//! Shared tagged timeouts, saturating absolute deadlines and request footers.
use crate::{
    abi, c_facades as c,
    resources::Timeout,
    storage::{Error, Result, length},
};
pub use abi::{
    R4Deadline as Deadline, R4Duration as Duration, R4MonotonicInstant as Instant,
    R4UtcTime as UtcTime,
};
pub struct Clock<'a, 'context> {
    app: &'a crate::App<'context>,
}
impl<'a, 'context> Clock<'a, 'context> {
    pub fn new(app: &'a crate::App<'context>) -> Self {
        Self { app }
    }
    pub fn state(&self) -> Result<abi::TimeState> {
        let address = self
            .app
            .sys_slot(core::mem::offset_of!(abi::R4XStartR4Sys, time_state))
            .ok_or(Error::Raw(abi::err_no_fn))?;
        let f: abi::R4SysFns::time_state = unsafe { core::mem::transmute(address) };
        let mut state = abi::TimeState::default();
        unsafe { f(&mut state) };
        Ok(state)
    }
    pub fn ticks(&self) -> Result<u64> {
        let address = self
            .app
            .sys_slot(core::mem::offset_of!(abi::R4XStartR4Sys, ticks))
            .ok_or(Error::Raw(abi::err_no_fn))?;
        let f: abi::R4SysFns::ticks = unsafe { core::mem::transmute(address) };
        Ok(unsafe { f() })
    }
    pub fn instant(&self) -> Result<Instant> {
        let state = self.state()?;
        instant_from_ticks(state.monotonic_ticks, state.monotonic_hz)
    }
}
fn exact(rc: i32) -> Result<()> {
    if rc == 0 { Ok(()) } else { Err(Error::Raw(rc)) }
}
pub fn resolution(hz: u32) -> Result<u64> {
    if hz == 0 {
        return Err(Error::Raw(abi::service_api_result_invalid));
    }
    Ok(unsafe { c::r4_monotonic_resolution_ns(hz) })
}
pub fn duration_to_ticks(duration: Duration, hz: u32) -> Result<u64> {
    let mut ticks = 0;
    exact(unsafe { c::r4_duration_to_ticks(duration, hz, &mut ticks) })?;
    Ok(ticks)
}
pub fn duration_from_ticks(ticks: u64, hz: u32) -> Result<Duration> {
    let mut value = Duration::default();
    exact(unsafe { c::R4SdkDurationFromTicks(ticks, hz, &mut value) })?;
    Ok(value)
}
pub fn instant_from_ticks(ticks: u64, hz: u32) -> Result<Instant> {
    Ok(Instant {
        nanoseconds: duration_from_ticks(ticks, hz)?.nanoseconds,
    })
}
pub fn deadline_after(now: Instant, duration: Duration) -> Deadline {
    unsafe { c::r4_deadline_after(now, duration) }
}
pub fn timeout_ticks(timeout: Timeout, hz: u32) -> Result<u64> {
    let mut ticks = 0;
    exact(unsafe { c::r4_timeout_to_ticks(timeout.raw(), hz, &mut ticks) })?;
    Ok(ticks)
}
pub fn timeout_deadline(timeout: Timeout, now: Instant) -> Result<Option<Deadline>> {
    let mut value = Deadline::default();
    let mut forever = 0;
    exact(unsafe { c::r4_timeout_deadline(timeout.raw(), now, &mut value, &mut forever) })?;
    Ok(if forever != 0 { None } else { Some(value) })
}
pub fn remaining_ticks(deadline: Deadline, now: Instant, hz: u32) -> Result<u64> {
    let mut ticks = 0;
    exact(unsafe { c::r4_remaining_ticks(deadline, now, hz, &mut ticks) })?;
    Ok(ticks)
}
pub fn request_deadline(timeout: Timeout, now: u64, hz: u32) -> Result<u64> {
    let mut value = 0;
    exact(unsafe { c::R4SdkDeadlineFromTimeout(timeout.raw(), now, hz, &mut value) })?;
    Ok(value)
}
pub fn request_remaining(deadline: u64, now: u64, hz: u32) -> Timeout {
    let raw = unsafe { c::R4SdkDeadlineRemaining(deadline, now, hz) };
    match raw.kind {
        abi::timeout_kind_forever => Timeout::Forever,
        abi::timeout_kind_finite => Timeout::AfterNanos(raw.nanoseconds),
        _ => Timeout::Poll,
    }
}
pub fn append_deadline<'a>(out: &'a mut [u8], payload: &[u8], tick: u64) -> Result<&'a [u8]> {
    let n = unsafe {
        c::R4SdkDeadlineAppend(
            out.as_mut_ptr(),
            length(out.len())?,
            payload.as_ptr(),
            length(payload.len())?,
            tick,
        )
    };
    if n < 0 {
        return Err(Error::Raw(n));
    }
    out.get(..n as usize).ok_or(Error::InvalidProvider)
}
pub fn split_deadline(bytes: &[u8]) -> Result<(&[u8], Option<u64>)> {
    let v = unsafe { c::R4SdkDeadlineSplit(bytes.as_ptr(), length(bytes.len())?) };
    Ok((
        bytes
            .get(..usize::try_from(v.length).map_err(|_| Error::InvalidProvider)?)
            .ok_or(Error::InvalidProvider)?,
        if v.has_deadline != 0 {
            Some(v.deadline_tick)
        } else {
            None
        },
    ))
}
