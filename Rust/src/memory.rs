//! Close the freestanding compiler memory helpers inside the same R4X.
//! Volatile byte operations prevent LLVM from rewriting their bodies into
//! recursive libc calls. The caller supplies valid ranges; no allocator exists.

use core::{ffi::c_void, ptr};

#[unsafe(no_mangle)]
pub unsafe extern "C" fn memcpy(dst: *mut c_void, src: *const c_void, len: usize) -> *mut c_void {
    let dst = dst.cast::<u8>();
    let src = src.cast::<u8>();
    for index in 0..len {
        unsafe { ptr::write_volatile(dst.add(index), ptr::read_volatile(src.add(index))) };
    }
    dst.cast()
}

#[unsafe(no_mangle)]
pub unsafe extern "C" fn memmove(dst: *mut c_void, src: *const c_void, len: usize) -> *mut c_void {
    let dst = dst.cast::<u8>();
    let src = src.cast::<u8>();
    if (dst as usize).wrapping_sub(src as usize) < len {
        for index in (0..len).rev() {
            unsafe { ptr::write_volatile(dst.add(index), ptr::read_volatile(src.add(index))) };
        }
    } else {
        for index in 0..len {
            unsafe { ptr::write_volatile(dst.add(index), ptr::read_volatile(src.add(index))) };
        }
    }
    dst.cast()
}

#[unsafe(no_mangle)]
pub unsafe extern "C" fn memset(dst: *mut c_void, value: i32, len: usize) -> *mut c_void {
    let dst = dst.cast::<u8>();
    for index in 0..len {
        unsafe { ptr::write_volatile(dst.add(index), value as u8) };
    }
    dst.cast()
}

#[unsafe(no_mangle)]
pub unsafe extern "C" fn memcmp(left: *const c_void, right: *const c_void, len: usize) -> i32 {
    let left = left.cast::<u8>();
    let right = right.cast::<u8>();
    for index in 0..len {
        let a = unsafe { ptr::read_volatile(left.add(index)) };
        let b = unsafe { ptr::read_volatile(right.add(index)) };
        if a != b {
            return i32::from(a) - i32::from(b);
        }
    }
    0
}

#[unsafe(no_mangle)]
pub unsafe extern "C" fn bcmp(left: *const c_void, right: *const c_void, len: usize) -> i32 {
    unsafe { memcmp(left, right, len) }
}
