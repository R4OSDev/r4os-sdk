#![no_std]
//! Minimal normal R4X runtime. Layouts, callbacks and constants come from the
//! matched generated Contract crate. There is no allocator or unwind runtime.

use core::sync::atomic::{AtomicPtr, Ordering};
use core::{ffi::CStr, marker::PhantomData, mem, ptr};
pub use r4os_contract as abi;
mod memory;

static PANIC_CONTEXT: AtomicPtr<abi::R4XStartContext> = AtomicPtr::new(ptr::null_mut());

pub struct App<'a> {
    context: &'a abi::R4XStartContext,
    name: &'static CStr,
    // These helpers belong to this executing instance, not to another thread.
    _local: PhantomData<*mut ()>,
}

impl<'a> App<'a> {
    /// # Safety
    /// `raw` and the loader-owned imports/tables must remain resident for the
    /// exact R4X call. The public entry macro supplies manifest-derived facts.
    pub unsafe fn from_raw(
        raw: *const abi::R4XStartContext,
        class: &str,
        imports: &str,
        name: &'static CStr,
    ) -> Result<Self, i32> {
        if raw.is_null() {
            return Err(-10);
        }
        let c = unsafe { &*raw };
        let expected = match class {
            "console" => abi::R4XStartAppClass::console,
            "gui" => abi::R4XStartAppClass::gui,
            "service" => abi::R4XStartAppClass::service,
            _ => return Err(-11),
        };
        if c.magic != abi::r4xstart_magic
            || c.abi_major != abi::r4xstart_abi_major
            || c.size < abi::r4xstart_context_size
            || c.app_class != expected.0
            || c.imports == 0
            || c.flags & abi::r4xstart_flag_imports_valid == 0
        {
            return Err(-12);
        }
        if imports.split(';').count() != c.import_count as usize || c.import_count > 16 {
            return Err(-13);
        }
        let entries = unsafe {
            core::slice::from_raw_parts(
                c.imports as *const abi::R4XStartImport,
                c.import_count as usize,
            )
        };
        for (entry, spec) in entries.iter().zip(imports.split(';')) {
            let mut parts = spec.split(':');
            let provider = parts.next().ok_or(-14)?;
            let symbol = parts.next().ok_or(-14)?;
            let version = parts.next().ok_or(-14)?.parse::<u32>().map_err(|_| -14)?;
            if parts.next().is_some()
                || entry.min_version != version
                || entry.resolved_version < version
                || entry.table == 0
                || !unsafe { name_equals(entry.module_name, provider.as_bytes()) }
                || !unsafe { name_equals(entry.symbol_name, symbol.as_bytes()) }
            {
                return Err(-14);
            }
        }
        let app = Self {
            context: c,
            name,
            _local: PhantomData,
        };
        // Access only fields included by the actual append-only table size.
        if app
            .sys_slot(mem::offset_of!(abi::R4XStartR4Sys, write))
            .is_none()
            || app
                .sys_slot(mem::offset_of!(abi::R4XStartR4Sys, sleep_ticks))
                .is_none()
        {
            return Err(-15);
        }
        if expected == abi::R4XStartAppClass::gui
            && (app
                .desk_slot(mem::offset_of!(abi::R4XStartR4Desk, gui_window_info))
                .is_none()
                || app
                    .draw_slot(mem::offset_of!(abi::R4XStartR4Draw, gui_clear))
                    .is_none()
                || app
                    .draw_slot(mem::offset_of!(abi::R4XStartR4Draw, gui_present))
                    .is_none())
        {
            return Err(-16);
        }
        Ok(app)
    }

    pub fn name(&self) -> &'static CStr {
        self.name
    }
    pub fn instance_id(&self) -> u64 {
        self.context.instance_id
    }
    pub fn args(&self) -> &[u8] {
        if self.context.args == 0 || self.context.args_len == 0 || self.context.args_len > 4096 {
            return &[];
        }
        unsafe {
            core::slice::from_raw_parts(
                self.context.args as *const u8,
                self.context.args_len as usize,
            )
        }
    }
    pub fn write(&self, text: &str) -> i32 {
        if text.len() > u32::MAX as usize {
            return -1;
        }
        let Some(address) = self.sys_slot(mem::offset_of!(abi::R4XStartR4Sys, write)) else {
            return -2;
        };
        let f: abi::R4SysFns::write = unsafe { mem::transmute(address) };
        unsafe { f(text.as_ptr(), text.len() as u32) }
    }
    pub fn sleep(&self, ticks: u64) {
        if let Some(address) = self.sys_slot(mem::offset_of!(abi::R4XStartR4Sys, sleep_ticks)) {
            let f: abi::R4SysFns::sleep_ticks = unsafe { mem::transmute(address) };
            unsafe { f(ticks) };
        }
    }
    pub fn should_close(&self) -> bool {
        if self.context.flags & abi::r4xstart_flag_close_supported != 0
            && self.context.should_close != 0
        {
            let f: abi::R4XStartShouldCloseFn =
                unsafe { mem::transmute(self.context.should_close as usize) };
            return unsafe { f(self.context) != 0 };
        }
        if let Some(address) =
            self.sys_slot(mem::offset_of!(abi::R4XStartR4Sys, program_should_close))
        {
            let f: abi::R4SysFns::program_should_close = unsafe { mem::transmute(address) };
            return unsafe { f() != 0 };
        }
        false
    }
    fn table_slot(
        &self,
        group: abi::R4LGroup,
        magic: u32,
        minimum: u32,
        offset: usize,
    ) -> Option<usize> {
        let entries = unsafe {
            core::slice::from_raw_parts(
                self.context.imports as *const abi::R4XStartImport,
                self.context.import_count as usize,
            )
        };
        let entry = entries.iter().find(|e| e.group_id == group.0)?;
        if entry.flags & abi::r4xstart_import_flag_group_interface == 0 || entry.table == 0 {
            return None;
        }
        let base = entry.table as *const u8;
        // Header offsets are the canonical common prefix, asserted below.
        let actual_magic = unsafe {
            ptr::read_unaligned(
                base.add(mem::offset_of!(abi::R4XStartR4Sys, magic))
                    .cast::<u32>(),
            )
        };
        let version = unsafe {
            ptr::read_unaligned(
                base.add(mem::offset_of!(abi::R4XStartR4Sys, abi_version))
                    .cast::<u32>(),
            )
        };
        let size = unsafe {
            ptr::read_unaligned(
                base.add(mem::offset_of!(abi::R4XStartR4Sys, size))
                    .cast::<u32>(),
            )
        };
        if actual_magic != magic
            || version < minimum
            || (size as usize) < offset.checked_add(mem::size_of::<usize>())?
        {
            return None;
        }
        let value = unsafe { ptr::read_unaligned(base.add(offset).cast::<usize>()) };
        if value == 0 { None } else { Some(value) }
    }
    fn sys_slot(&self, offset: usize) -> Option<usize> {
        self.table_slot(
            abi::R4LGroup::r4sys,
            abi::r4xstart_r4sys_magic,
            abi::r4xstart_r4sys_version,
            offset,
        )
    }
    fn desk_slot(&self, offset: usize) -> Option<usize> {
        self.table_slot(
            abi::R4LGroup::r4desk,
            abi::r4xstart_r4desk_magic,
            abi::r4xstart_r4desk_version,
            offset,
        )
    }
    fn draw_slot(&self, offset: usize) -> Option<usize> {
        self.table_slot(
            abi::R4LGroup::r4draw,
            abi::r4xstart_r4draw_magic,
            abi::r4xstart_r4draw_version,
            offset,
        )
    }

    /// The regular R4OS host creates/binds the GUI window before R4XStart.
    pub fn window_info(&self) -> Result<abi::GuiWindowInfo, i32> {
        let f: abi::R4DeskFns::gui_window_info = unsafe {
            mem::transmute(
                self.desk_slot(mem::offset_of!(abi::R4XStartR4Desk, gui_window_info))
                    .ok_or(-2)?,
            )
        };
        let mut info = abi::GuiWindowInfo::default();
        let rc = unsafe { f(&mut info) };
        if rc < 0 || info.window_id < 0 {
            Err(if rc < 0 { rc } else { -3 })
        } else {
            Ok(info)
        }
    }
    pub fn set_title(&self, title: &CStr) -> Result<(), i32> {
        let f: abi::R4DeskFns::gui_set_title = unsafe {
            mem::transmute(
                self.desk_slot(mem::offset_of!(abi::R4XStartR4Desk, gui_set_title))
                    .ok_or(-2)?,
            )
        };
        check(unsafe { f(title.as_ptr().cast()) })
    }
    pub fn clear(&self, color: u32) -> Result<(), i32> {
        let f: abi::R4DrawFns::gui_clear = unsafe {
            mem::transmute(
                self.draw_slot(mem::offset_of!(abi::R4XStartR4Draw, gui_clear))
                    .ok_or(-2)?,
            )
        };
        check(unsafe { f(color) })
    }
    pub fn text(
        &self,
        x: i32,
        y: i32,
        text: &CStr,
        color: u32,
        background: u32,
    ) -> Result<(), i32> {
        let f: abi::R4DrawFns::gui_draw_text = unsafe {
            mem::transmute(
                self.draw_slot(mem::offset_of!(abi::R4XStartR4Draw, gui_draw_text))
                    .ok_or(-2)?,
            )
        };
        check(unsafe { f(x, y, text.as_ptr().cast(), color, background) })
    }
    pub fn present(&self) -> Result<(), i32> {
        let f: abi::R4DrawFns::gui_present = unsafe {
            mem::transmute(
                self.draw_slot(mem::offset_of!(abi::R4XStartR4Draw, gui_present))
                    .ok_or(-2)?,
            )
        };
        check(unsafe { f() })
    }
    pub fn poll_event(&self) -> Result<Option<abi::GuiEvent>, i32> {
        let f: abi::R4DeskFns::gui_poll_event = unsafe {
            mem::transmute(
                self.desk_slot(mem::offset_of!(abi::R4XStartR4Desk, gui_poll_event))
                    .ok_or(-2)?,
            )
        };
        let mut event = abi::GuiEvent::default();
        let rc = unsafe { f(&mut event) };
        if rc < 0 {
            Err(rc)
        } else if rc == 0 {
            Ok(None)
        } else {
            Ok(Some(event))
        }
    }
    /// A bounded event wait leaves the scheduler ready list while idle.
    pub fn wait_event(&self, ticks: u64) -> Result<Option<abi::GuiEvent>, i32> {
        if let Some(event) = self.poll_event()? {
            return Ok(Some(event));
        }
        self.sleep(ticks.max(1));
        self.poll_event()
    }
    pub fn register_service(&self) -> Result<Service<'_, 'a>, i32> {
        if self.context.app_class != abi::R4XStartAppClass::service.0 {
            return Err(-1);
        }
        let f: abi::R4SysFns::service_endpoint_register = unsafe {
            mem::transmute(
                self.sys_slot(mem::offset_of!(
                    abi::R4XStartR4Sys,
                    service_endpoint_register
                ))
                .ok_or(-2)?,
            )
        };
        let mut info = abi::ServiceInfo::default();
        let rc = unsafe { f(self.name.as_ptr().cast(), 0, &mut info) };
        if rc < 0 || info.handle == 0 {
            return Err(if rc < 0 { rc } else { -3 });
        }
        Ok(Service {
            app: self,
            handle: info.handle,
        })
    }
}

pub struct Service<'a, 'context> {
    app: &'a App<'context>,
    handle: u32,
}
impl Service<'_, '_> {
    pub fn handle(&self) -> u32 {
        self.handle
    }
    pub fn wait(&self, ticks: u64) -> Result<(), i32> {
        let f: abi::R4SysFns::service_endpoint_wait = unsafe {
            mem::transmute(
                self.app
                    .sys_slot(mem::offset_of!(abi::R4XStartR4Sys, service_endpoint_wait))
                    .ok_or(-2)?,
            )
        };
        let rc = unsafe { f(self.handle, ticks.max(1)) };
        if rc == abi::service_api_result_timeout {
            Ok(())
        } else {
            check(rc)
        }
    }
    pub fn receive(&self, header: &mut abi::ServiceMessageHeader, data: &mut [u8]) -> i32 {
        let Some(address) = self
            .app
            .sys_slot(mem::offset_of!(abi::R4XStartR4Sys, service_endpoint_recv))
        else {
            return -2;
        };
        if data.len() > u32::MAX as usize {
            return -1;
        }
        let f: abi::R4SysFns::service_endpoint_recv = unsafe { mem::transmute(address) };
        unsafe { f(self.handle, header, data.as_mut_ptr(), data.len() as u32) }
    }
    pub fn reply(&self, request: u32, status: i32, data: &[u8]) -> i32 {
        let Some(address) = self
            .app
            .sys_slot(mem::offset_of!(abi::R4XStartR4Sys, service_endpoint_reply))
        else {
            return -2;
        };
        if data.len() > u32::MAX as usize {
            return -1;
        }
        let f: abi::R4SysFns::service_endpoint_reply = unsafe { mem::transmute(address) };
        unsafe {
            f(
                self.handle,
                request,
                status,
                data.as_ptr(),
                data.len() as u32,
            )
        }
    }
    /// Clear the handle only after its exact unregister acknowledgement.
    pub fn close(&mut self) -> Result<(), i32> {
        let rc = self.unregister();
        if rc >= 0 {
            self.handle = 0;
            Ok(())
        } else {
            Err(rc)
        }
    }
    fn unregister(&self) -> i32 {
        let Some(address) = self.app.sys_slot(mem::offset_of!(
            abi::R4XStartR4Sys,
            service_endpoint_unregister
        )) else {
            return -2;
        };
        let f: abi::R4SysFns::service_endpoint_unregister = unsafe { mem::transmute(address) };
        unsafe { f(self.handle) }
    }
}
impl Drop for Service<'_, '_> {
    fn drop(&mut self) {
        if self.handle != 0 {
            let _ = self.unregister();
        }
    }
}
fn check(rc: i32) -> Result<(), i32> {
    if rc < 0 { Err(rc) } else { Ok(()) }
}
unsafe fn name_equals(address: u64, expected: &[u8]) -> bool {
    if address == 0 || expected.len() > 63 {
        return false;
    }
    let p = address as *const u8;
    for (index, value) in expected.iter().enumerate() {
        if unsafe { *p.add(index) } != *value {
            return false;
        }
    }
    unsafe { *p.add(expected.len()) == 0 }
}

/// # Safety
/// Called only by the SDK entry macro under the loader's R4XStart contract.
#[doc(hidden)]
pub unsafe fn start(
    raw: *const abi::R4XStartContext,
    class: &str,
    imports: &str,
    name: &'static CStr,
    main: fn(&mut App<'_>) -> i32,
) -> i32 {
    let mut app = match unsafe { App::from_raw(raw, class, imports, name) } {
        Ok(a) => a,
        Err(e) => return e,
    };
    PANIC_CONTEXT.store(raw.cast_mut(), Ordering::Release);
    let code = main(&mut app);
    PANIC_CONTEXT.store(ptr::null_mut(), Ordering::Release);
    code
}

#[cfg(target_os = "none")]
#[panic_handler]
fn panic(_info: &core::panic::PanicInfo<'_>) -> ! {
    let raw = PANIC_CONTEXT.load(Ordering::Acquire);
    if !raw.is_null() {
        // The normal validated context remains pinned by the loader until
        // actual program exit. No SDK lock/allocator is held here.
        let app = App {
            context: unsafe { &*raw },
            name: c"panic",
            _local: PhantomData,
        };
        let _ = app.write("[RUST] panic: failed process exit\n");
        if let Some(address) = app.sys_slot(mem::offset_of!(abi::R4XStartR4Sys, program_exit)) {
            let f: abi::R4SysFns::program_exit = unsafe { mem::transmute(address) };
            let _ = unsafe { f(-101, abi::program_exit_reason_failed as u32) };
        }
    }
    // A missing/rejected terminal API is a real module fault, not success or
    // an idle/spinning process. No unwinding crosses an extern-C boundary.
    unsafe { core::arch::asm!("ud2", options(noreturn)) }
}

#[macro_export]
macro_rules! app {
    ($main:path) => {
        #[unsafe(no_mangle)]
        #[unsafe(link_section = ".text.r4xstart_entry")]
        pub unsafe extern "C" fn R4XStart(raw: *const $crate::abi::R4XStartContext) -> i32 {
            unsafe {
                $crate::start(
                    raw,
                    env!("R4OS_APP_CLASS"),
                    env!("R4OS_IMPORTS"),
                    core::ffi::CStr::from_bytes_with_nul_unchecked(
                        concat!(env!("R4OS_MODULE_NAME"), "\0").as_bytes(),
                    ),
                    $main,
                )
            }
        }
    };
}

const _: () = {
    assert!(
        mem::offset_of!(abi::R4XStartR4Sys, magic) == mem::offset_of!(abi::R4XStartR4Desk, magic)
    );
    assert!(
        mem::offset_of!(abi::R4XStartR4Sys, abi_version)
            == mem::offset_of!(abi::R4XStartR4Draw, abi_version)
    );
    assert!(
        mem::offset_of!(abi::R4XStartR4Sys, size) == mem::offset_of!(abi::R4XStartR4Desk, size)
    );
    assert!(
        mem::offset_of!(abi::R4XStartR4Sys, size) == mem::offset_of!(abi::R4XStartR4Draw, size)
    );
};
