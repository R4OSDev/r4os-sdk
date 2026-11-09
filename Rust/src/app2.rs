//! Normal application entry on the actual generation2 contract.
use crate::{abi, heap, platform2};
use core::{ffi::CStr, marker::PhantomData, mem};

#[repr(C)]
#[derive(Clone, Copy)]
pub(crate) struct Memory {
    pub(crate) version: u32,
    pub(crate) size: u32,
    pub(crate) generation: u32,
    pub(crate) flags: u32,
    pub(crate) identity: u64,
    pub(crate) vm_reserve: u64,
    pub(crate) vm_commit: u64,
    pub(crate) vm_decommit: u64,
    pub(crate) vm_release: u64,
    pub(crate) notification_create: u64,
    pub(crate) notification_query: u64,
    pub(crate) notification_notify: u64,
    pub(crate) notification_wait: u64,
    pub(crate) notification_close: u64,
    pub(crate) sleep_ticks: u64,
    pub(crate) task_yield: u64,
    pub(crate) thread_current_handle: u64,
    pub(crate) program_exit: u64,
}
#[repr(C)]
pub struct ImportSpec {
    pub module_name: *const u8,
    pub symbol_name: *const u8,
    pub minimum: u32,
    pub optional: u32,
    pub group_id: u32,
    pub reserved: u32,
}
pub struct StartupInfo<'a> {
    pub profile: u32,
    pub app_class: u32,
    pub required_groups: u32,
    pub imports: &'a [ImportSpec],
}
#[repr(C)]
struct RawStartupInfo {
    profile: u32,
    app_class: u32,
    required_groups: u32,
    import_count: u32,
    imports: *const ImportSpec,
}
unsafe extern "C" {
    fn R4SdkApp2Init(
        raw: *const platform2::abi::R4XStartContext2,
        expected: *const RawStartupInfo,
        output: *mut Memory,
    ) -> i32;
}
pub struct App<'a> {
    context: platform2::Context<'a>,
    pub(crate) memory: Memory,
    name: &'static CStr,
    local: PhantomData<*mut ()>,
}
impl<'a> App<'a> {
    /// # Safety
    /// The actual generation2 start, imports, names and declared table prefixes
    /// stay resident through the exact entry. All caller and buffer loans must
    /// retire before it returns. This borrowed App is neither Send nor Sync.
    pub unsafe fn from_raw(
        raw: *const platform2::abi::R4XStartContext2,
        expected: &StartupInfo<'_>,
        name: &'static CStr,
    ) -> Result<Self, i32> {
        if raw.is_null()
            || !(raw as usize).is_multiple_of(mem::align_of::<platform2::abi::R4XStartContext2>())
        {
            return Err(-12);
        }
        let mut memory = unsafe { mem::zeroed() };
        let facts = RawStartupInfo {
            profile: expected.profile,
            app_class: expected.app_class,
            required_groups: expected.required_groups,
            import_count: u32::try_from(expected.imports.len()).map_err(|_| -13)?,
            imports: expected.imports.as_ptr(),
        };
        let rc = unsafe { R4SdkApp2Init(raw, &facts, &mut memory) };
        if rc < 0 {
            return Err(rc);
        }
        let context = unsafe { platform2::Context::new(&*raw) }.map_err(|_| -12)?;
        Ok(Self {
            context,
            memory,
            name,
            local: PhantomData,
        })
    }
    pub fn context(&self) -> &platform2::Context<'a> {
        &self.context
    }
    pub fn start_context(&self) -> &'a platform2::abi::R4XStartContext2 {
        self.context.raw()
    }
    pub fn name(&self) -> &'static CStr {
        self.name
    }
    pub fn instance_id(&self) -> u64 {
        self.start_context().instance_id
    }
    pub fn args(&self) -> &'a [u8] {
        self.context.args()
    }
    pub fn should_close(&self) -> bool {
        self.context.should_close()
    }
    pub fn yield_current(&self) {
        let _ = self.context.yield_current();
    }
    pub fn write(&self, text: &str) -> i32 {
        let length = match u32::try_from(text.len()) {
            Ok(n) => n,
            Err(_) => return abi::err_no_fn,
        };
        let address = match self.context.lookup(
            1,
            mem::offset_of!(platform2::abi::R4XStartR4Sys2, write) as u32,
        ) {
            Ok(a) => a,
            Err(e) => return e,
        };
        let function: abi::R4SysFns::write = unsafe { mem::transmute(address) };
        unsafe { function(text.as_ptr(), length) }
    }
    pub fn heap(&self) -> Result<heap::Heap<'_>, heap::Error> {
        heap::Heap::new2(self)
    }
}

/// # Safety
/// Only the SDK entry macro calls this with the complete generated facts and
/// a loader-pinned exact generation2 entry.
#[doc(hidden)]
pub unsafe fn start(
    raw: *const platform2::abi::R4XStartContext2,
    expected: &StartupInfo<'_>,
    name: &'static CStr,
    main: fn(&mut App<'_>) -> i32,
) -> i32 {
    let mut app = match unsafe { App::from_raw(raw, expected, name) } {
        Ok(a) => a,
        Err(e) => return e,
    };
    crate::bind_panic_callbacks(
        app.context()
            .lookup(
                1,
                mem::offset_of!(platform2::abi::R4XStartR4Sys2, write) as u32,
            )
            .unwrap_or(0),
        app.context()
            .lookup(
                1,
                mem::offset_of!(platform2::abi::R4XStartR4Sys2, program_exit) as u32,
            )
            .unwrap_or(0),
    );
    #[cfg(all(feature = "alloc", target_os = "none"))]
    if heap::install2(&app).is_err() {
        crate::clear_panic_callbacks();
        return -17;
    }
    let result = main(&mut app);
    crate::clear_panic_callbacks();
    result
}
#[macro_export]
macro_rules! app2 {
    ($main:path) => {
        #[unsafe(no_mangle)]
        #[unsafe(link_section = ".text.r4xstart_entry")]
        pub unsafe extern "C" fn R4XStart2(
            raw: *const $crate::platform2::abi::R4XStartContext2,
        ) -> i32 {
            use $crate as __r4os_startup;
            let startup = include!(env!("R4OS_STARTUP_INFO_FILE"));
            unsafe {
                $crate::app2::start(
                    raw,
                    &startup,
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
    assert!(mem::size_of::<Memory>() == 128);
    assert!(mem::size_of::<ImportSpec>() == 32);
    assert!(mem::size_of::<RawStartupInfo>() == 24);
};
