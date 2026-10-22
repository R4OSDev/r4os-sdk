//! Exact UTF8 buffers and presentation-only grapheme truncation from R4STD.
use crate::c_facades as c;
pub fn valid(bytes: &[u8]) -> bool {
    unsafe { c::R4SdkTextValid(bytes.as_ptr(), bytes.len() as u64) != 0 }
}
pub fn assign_z(out: &mut [u8], bytes: &[u8]) -> bool {
    unsafe {
        c::R4SdkTextAssign(
            out.as_mut_ptr(),
            out.len() as u64,
            bytes.as_ptr(),
            bytes.len() as u64,
        ) != 0
    }
}
pub fn label_z(out: &mut [u8], bytes: &[u8]) -> bool {
    unsafe {
        c::R4SdkTextLabel(
            out.as_mut_ptr(),
            out.len() as u64,
            bytes.as_ptr(),
            bytes.len() as u64,
        ) != 0
    }
}
pub fn load_prefix(bytes: &[u8], capacity: usize, truncated: bool) -> Option<usize> {
    let mut n = 0;
    if unsafe {
        c::R4SdkTextPrefix(
            bytes.as_ptr(),
            bytes.len() as u64,
            capacity as u64,
            i32::from(truncated),
            &mut n,
        )
    } != 0
    {
        Some(n as usize)
    } else {
        None
    }
}
