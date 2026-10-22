//! Instance-bound views of the SDK's shared pooled VM heap. The same core
//! serves Zig, C and Rust; the kernel still owns VM and task retirement.
use crate::{App, abi};
use core::{
    alloc::Layout,
    ffi::{CStr, c_void},
    marker::PhantomData,
    ptr::NonNull,
};

unsafe extern "C" {
    fn R4SdkHeapBind(api: *const abi::R4XStartR4Sys, instance: u64) -> i32;
    fn R4SdkHeapAlloc(
        api: *const abi::R4XStartR4Sys,
        instance: u64,
        size: usize,
        alignment: usize,
    ) -> *mut c_void;
    fn R4SdkHeapRealloc(
        api: *const abi::R4XStartR4Sys,
        instance: u64,
        pointer: *mut c_void,
        size: usize,
        alignment: usize,
    ) -> *mut c_void;
    fn R4SdkHeapFree(api: *const abi::R4XStartR4Sys, instance: u64, pointer: *mut c_void) -> i32;
    fn R4SdkHeapStats(
        api: *const abi::R4XStartR4Sys,
        instance: u64,
        values: *mut u64,
        capacity: u32,
    ) -> i32;
    fn R4SdkHeapStatName(index: u32) -> *const core::ffi::c_char;
    fn R4SdkHeapFinish(api: *const abi::R4XStartR4Sys, instance: u64) -> i32;
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Error {
    InvalidLayout,
    OutOfMemory,
    Runtime(i32),
}

pub struct Heap<'a> {
    api: &'a abi::R4XStartR4Sys,
    instance: u64,
    _local: PhantomData<*mut ()>,
}
impl<'a> Heap<'a> {
    pub(crate) fn new(app: &'a App<'_>) -> Result<Self, Error> {
        let api = app.system_api().ok_or(Error::Runtime(-1))?;
        let instance = app.instance_id();
        let rc = unsafe { R4SdkHeapBind(api, instance) };
        if rc != 0 {
            return Err(Error::Runtime(rc));
        }
        Ok(Self {
            api,
            instance,
            _local: PhantomData,
        })
    }
    pub fn allocate(&self, size: usize, alignment: usize) -> Result<Buffer<'_, 'a>, Error> {
        let layout = Layout::from_size_align(size, alignment).map_err(|_| Error::InvalidLayout)?;
        let pointer = if size == 0 {
            NonNull::new(alignment as *mut u8).unwrap()
        } else {
            NonNull::new(unsafe { R4SdkHeapAlloc(self.api, self.instance, size, alignment) }.cast())
                .ok_or(Error::OutOfMemory)?
        };
        // Safe slice views require initialized bytes. GlobalAlloc remains
        // uninitialized, as required by its separate raw allocation contract.
        unsafe { core::ptr::write_bytes(pointer.as_ptr(), 0, size) };
        Ok(Buffer {
            heap: self,
            pointer,
            layout,
        })
    }
    pub fn stats(&self) -> Result<Stats, Error> {
        let mut stats = Stats {
            values: [0; 64],
            count: 0,
        };
        let count =
            unsafe { R4SdkHeapStats(self.api, self.instance, stats.values.as_mut_ptr(), 64) };
        if count < 0 {
            return Err(Error::Runtime(count));
        }
        if count as usize > stats.values.len() {
            return Err(Error::Runtime(-1));
        }
        stats.count = count as usize;
        Ok(stats)
    }
    /// Close allocation admission for this entire R4X heap. Existing buffers
    /// may be freed before retry. Success includes actual VM/notification ACKs.
    /// # Safety
    /// All allocator users, including any worker threads, must be joined or
    /// otherwise quiescent. No allocation may follow this irreversible call.
    pub unsafe fn finish_instance(&self) -> Result<(), Error> {
        let rc = unsafe { R4SdkHeapFinish(self.api, self.instance) };
        if rc == 0 {
            Ok(())
        } else {
            Err(Error::Runtime(rc))
        }
    }
}

pub struct Buffer<'h, 'a> {
    heap: &'h Heap<'a>,
    pointer: NonNull<u8>,
    layout: Layout,
}
impl Buffer<'_, '_> {
    pub fn as_slice(&self) -> &[u8] {
        unsafe { core::slice::from_raw_parts(self.pointer.as_ptr(), self.layout.size()) }
    }
    pub fn as_mut_slice(&mut self) -> &mut [u8] {
        unsafe { core::slice::from_raw_parts_mut(self.pointer.as_ptr(), self.layout.size()) }
    }
    pub fn resize(&mut self, size: usize) -> Result<(), Error> {
        let next =
            Layout::from_size_align(size, self.layout.align()).map_err(|_| Error::InvalidLayout)?;
        let pointer = if size == 0 {
            if self.layout.size() != 0 {
                let rc = unsafe {
                    R4SdkHeapFree(
                        self.heap.api,
                        self.heap.instance,
                        self.pointer.as_ptr().cast(),
                    )
                };
                if rc != 0 {
                    return Err(Error::Runtime(rc));
                }
            }
            NonNull::new(next.align() as *mut u8).unwrap()
        } else {
            let old = if self.layout.size() == 0 {
                core::ptr::null_mut()
            } else {
                self.pointer.as_ptr().cast()
            };
            NonNull::new(
                unsafe {
                    R4SdkHeapRealloc(self.heap.api, self.heap.instance, old, size, next.align())
                }
                .cast(),
            )
            .ok_or(Error::OutOfMemory)?
        };
        if size > self.layout.size() {
            unsafe {
                core::ptr::write_bytes(
                    pointer.as_ptr().add(self.layout.size()),
                    0,
                    size - self.layout.size(),
                )
            };
        }
        self.pointer = pointer;
        self.layout = next;
        Ok(())
    }
}
impl Drop for Buffer<'_, '_> {
    fn drop(&mut self) {
        if self.layout.size() != 0 {
            let rc = unsafe {
                R4SdkHeapFree(
                    self.heap.api,
                    self.heap.instance,
                    self.pointer.as_ptr().cast(),
                )
            };
            assert_eq!(rc, 0, "SDK heap ownership lost");
        }
    }
}

/// A single locked snapshot of every metric of the canonical VM allocator.
/// Names are provided by that owner, not duplicated per language.
pub struct Stats {
    values: [u64; 64],
    count: usize,
}
impl Stats {
    pub fn iter(&self) -> impl Iterator<Item = (&CStr, u64)> {
        self.values[..self.count]
            .iter()
            .enumerate()
            .map(|(index, value)| {
                let name = unsafe { CStr::from_ptr(R4SdkHeapStatName(index as u32)) };
                (name, *value)
            })
    }
    pub fn get(&self, name: &CStr) -> Option<u64> {
        self.iter()
            .find_map(|(key, value)| if key == name { Some(value) } else { None })
    }
}

#[cfg(all(feature = "alloc", target_os = "none"))]
mod global {
    use super::*;
    use core::{
        alloc::GlobalAlloc,
        sync::atomic::{AtomicPtr, AtomicU64, Ordering},
    };
    // Only the immutable provider pointer/instance identity is retained.
    // No root App/Context loan survives into a worker. The kernel pins this
    // module image and VM ownership until all tasks have actually retired.
    pub(super) struct InstanceAllocator {
        api: AtomicPtr<abi::R4XStartR4Sys>,
        instance: AtomicU64,
    }
    #[global_allocator]
    static ALLOCATOR: InstanceAllocator = InstanceAllocator {
        api: AtomicPtr::new(core::ptr::null_mut()),
        instance: AtomicU64::new(0),
    };
    pub(crate) fn install(app: &App<'_>) -> Result<(), Error> {
        let heap = Heap::new(app)?;
        ALLOCATOR.instance.store(heap.instance, Ordering::Relaxed);
        ALLOCATOR
            .api
            .store(core::ptr::from_ref(heap.api).cast_mut(), Ordering::Release);
        Ok(())
    }
    unsafe impl GlobalAlloc for InstanceAllocator {
        unsafe fn alloc(&self, layout: Layout) -> *mut u8 {
            let api = self.api.load(Ordering::Acquire);
            if api.is_null() {
                return core::ptr::null_mut();
            }
            unsafe {
                R4SdkHeapAlloc(
                    api,
                    self.instance.load(Ordering::Relaxed),
                    layout.size(),
                    layout.align(),
                )
                .cast()
            }
        }
        unsafe fn dealloc(&self, pointer: *mut u8, _: Layout) {
            let api = self.api.load(Ordering::Acquire);
            assert!(!api.is_null(), "SDK allocator not initialized");
            let rc = unsafe {
                R4SdkHeapFree(api, self.instance.load(Ordering::Relaxed), pointer.cast())
            };
            assert_eq!(rc, 0, "SDK heap ownership lost");
        }
        unsafe fn realloc(&self, pointer: *mut u8, old: Layout, size: usize) -> *mut u8 {
            let api = self.api.load(Ordering::Acquire);
            if api.is_null() {
                return core::ptr::null_mut();
            }
            unsafe {
                R4SdkHeapRealloc(
                    api,
                    self.instance.load(Ordering::Relaxed),
                    pointer.cast(),
                    size,
                    old.align(),
                )
                .cast()
            }
        }
    }
}
#[cfg(all(feature = "alloc", target_os = "none"))]
pub(crate) use global::install;
