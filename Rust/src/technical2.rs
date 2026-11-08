//! Borrowed generation2 technical tables; the original driver/PPI execution
//! owner authenticates each call. No Drop implies device or DMA quiescence.
use crate::abi;
use core::{ffi::CStr, marker::PhantomData, mem};

pub struct Driver<'a> {
    table: &'a abi::DriverApi2,
    _local: PhantomData<*mut ()>,
}
impl<'a> Driver<'a> {
    /// # Safety
    /// The exact immutable loader table and every declared mandatory callback
    /// are readable/valid for 'a under this driver's admitted execution scope.
    pub unsafe fn from_raw(raw: *const abi::DriverApi2) -> Result<Self, i32> {
        if raw.is_null() || !(raw as usize).is_multiple_of(8) { return Err(-1); }
        let valid = unsafe { (*raw).magic == abi::driver_api2_magic && (*raw).version >= abi::driver_api2_version && (*raw).size as usize >= mem::size_of::<abi::DriverApi2>() && (*raw).reserved == 0 };
        if !valid { return Err(-1); }
        Ok(Self { table: unsafe { &*raw }, _local: PhantomData })
    }
    pub fn raw(&self) -> &'a abi::DriverApi2 { self.table }
    pub fn log(&self, text: &CStr) { unsafe { (self.table.log_info)(text.as_ptr().cast()) } }
    pub fn clock_sample(&self) -> Result<crate::time::checked::ClockSample, crate::time::checked::Error> {
        let callback = self.table.monotonic_clock.ok_or(crate::time::checked::Error::ClockUnavailable)?;
        let mut info = abi::MonotonicClockInfo::default();
        if unsafe { callback(&mut info) } <= 0 { return Err(crate::time::checked::Error::ClockUnavailable); }
        crate::time::checked::ClockSample::from_info(&info)
    }
    /// # Safety
    /// Descriptor and all callback/context backing stay immutable and resident
    /// through actual unregister/terminal retirement, even after partial error.
    pub unsafe fn register_audio(&self, name: &CStr, backend: *const abi::AudioBackend2) -> i32 {
        unsafe { (self.table.register_audio_output_backend)(name.as_ptr().cast(), backend) }
    }
}
pub struct Protocol<'a> {
    table: &'a abi::ProtocolApi2,
    _local: PhantomData<*mut ()>,
}
impl<'a> Protocol<'a> {
    /// # Safety
    /// Exact original immutable readable PPI2 table and mandatory callbacks
    /// retain their lifetime under this module's genuine execution scope.
    pub unsafe fn from_raw(raw: *const abi::ProtocolApi2) -> Result<Self, i32> {
        if raw.is_null() || !(raw as usize).is_multiple_of(8) { return Err(-1); }
        let valid = unsafe { (*raw).magic == abi::protocol_api2_magic && (*raw).version >= abi::protocol_api2_version && (*raw).size as usize >= mem::size_of::<abi::ProtocolApi2>() && (*raw).reserved == 0 };
        if !valid { return Err(-1); }
        Ok(Self { table: unsafe { &*raw }, _local: PhantomData })
    }
    pub fn raw(&self) -> &'a abi::ProtocolApi2 { self.table }
}
#[macro_export]
macro_rules! driver_entry2 {
    ($init:path,$shutdown:path)=>{
        core::arch::global_asm!(
            ".pushsection .text.r4d_entries,\"ax\",@progbits",
            ".global DriverInit2", "DriverInit2:", ".byte 0xe9", ".long {init} - . - 4",
            ".global DriverShutdown", "DriverShutdown:", ".byte 0xe9", ".long {shutdown} - . - 4", ".popsection",
            init=sym $init,shutdown=sym $shutdown);
        const _: unsafe extern "C" fn(*const $crate::abi::DriverApi2)->i32=$init;
        const _: unsafe extern "C" fn()->i32=$shutdown;
    };
}
#[macro_export]
macro_rules! protocol_entry2 {
    ($init:path,$shutdown:path,$query:path,$dispatch:path)=>{
        core::arch::global_asm!(
            ".pushsection .text.r4p_entries,\"ax\",@progbits",
            ".global ProtocolInit2", "ProtocolInit2:", ".byte 0xe9", ".long {init} - . - 4",
            ".global ProtocolShutdown", "ProtocolShutdown:", ".byte 0xe9", ".long {shutdown} - . - 4",
            ".global ProtocolQuery", "ProtocolQuery:", ".byte 0xe9", ".long {query} - . - 4",
            ".global ProtocolDispatch", "ProtocolDispatch:", ".byte 0xe9", ".long {dispatch} - . - 4", ".popsection",
            init=sym $init,shutdown=sym $shutdown,query=sym $query,dispatch=sym $dispatch);
        const _: unsafe extern "C" fn(*const $crate::abi::ProtocolApi2)->i32=$init;
        const _: unsafe extern "C" fn()->i32=$shutdown;
        const _: unsafe extern "C" fn(*mut $crate::abi::ProtocolStatus)->i32=$query;
        const _: unsafe extern "C" fn(u32,*const $crate::abi::ProtocolBuffer,*mut $crate::abi::ProtocolBuffer)->i32=$dispatch;
    };
}
