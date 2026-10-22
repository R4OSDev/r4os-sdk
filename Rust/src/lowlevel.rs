//! Explicit raw R4X entry. Original context/ABI and caller-owned resources;
//! no normal App main invocation or implicit entropy/heap initialization.
pub use crate::abi as contract;
use crate::{App, StartupInfo, abi};
use core::{ffi::CStr, sync::atomic::Ordering};
pub type Context<'a> = App<'a>;
/// # Safety
/// Called only from the exact current loader entry. All admitted context and
/// table bytes stay immutable/resident until every instance task has retired.
#[doc(hidden)]
pub unsafe fn invoke(
    raw: *const abi::R4XStartContext,
    expected: &StartupInfo<'_>,
    name: &'static CStr,
    entry: unsafe extern "C" fn(*const abi::R4XStartContext) -> i32,
) -> i32 {
    let _view = match unsafe { App::from_raw(raw, expected, name) } {
        Ok(v) => v,
        Err(e) => return e,
    };
    crate::PANIC_CONTEXT.store(raw.cast_mut(), Ordering::Release);
    let code = unsafe { entry(raw) };
    crate::PANIC_CONTEXT.store(core::ptr::null_mut(), Ordering::Release);
    code
}
/// Explicit initialization for users choosing SDK entropy/global allocation.
/// The same original instance owner retains heap/task cleanup on process exit.
pub fn initialize_runtime(view: &Context<'_>) -> Result<(), i32> {
    let status = unsafe { crate::c_facades::R4SdkBindProgramEntropy(view.start_context()) };
    if status < 0 {
        return Err(status);
    }
    #[cfg(all(feature = "alloc", target_os = "none"))]
    crate::heap::install(view).map_err(|_| -17)?;
    Ok(())
}
/// Emits the real R4XStart symbol. The callback receives the raw loader context;
/// admission/panic scope are shared infrastructure, no App-main adapter runs.
#[macro_export]
macro_rules! lowlevel_entry {
    ($entry:path) => {
        const _: unsafe extern "C" fn(*const $crate::abi::R4XStartContext) -> i32 = $entry;
        #[unsafe(no_mangle)]
        #[unsafe(link_section = ".text.r4xstart_entry")]
        pub unsafe extern "C" fn R4XStart(raw: *const $crate::abi::R4XStartContext) -> i32 {
            use $crate as __r4os_startup;
            let expected = include!(env!("R4OS_STARTUP_INFO_FILE"));
            unsafe {
                $crate::lowlevel::invoke(
                    raw,
                    &expected,
                    core::ffi::CStr::from_bytes_with_nul_unchecked(
                        concat!(env!("R4OS_MODULE_NAME"), "\0").as_bytes(),
                    ),
                    $entry,
                )
            }
        }
    };
}
/// A checked view for explicitly chosen helpers; it does not initialize a heap,
/// bind entropy, create a window or call an application main function.
#[macro_export]
macro_rules! lowlevel_context {
    ($raw:expr) => {{
        use $crate as __r4os_startup;
        let expected = include!(env!("R4OS_STARTUP_INFO_FILE"));
        $crate::App::from_raw(
            $raw,
            &expected,
            core::ffi::CStr::from_bytes_with_nul_unchecked(
                concat!(env!("R4OS_MODULE_NAME"), "\0").as_bytes(),
            ),
        )
    }};
}
