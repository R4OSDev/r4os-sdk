//! Explicit generation-2 view, independent of the existing App binding.
pub use crate::abi::generation2 as abi;
use core::{ffi::c_void, marker::PhantomData, mem};

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
#[repr(i32)]
pub enum Error {
    InvalidContext = 1,
    InvalidImports = 2,
    MixedGeneration = 3,
    DuplicateGroup = 4,
    MissingSystem = 5,
    InvalidTable = 6,
}

pub struct Context<'a> {
    raw: &'a abi::R4XStartContext2,
    tables: [u64; 6],
    local: PhantomData<*mut ()>,
}
impl<'a> Context<'a> {
    /// # Safety
    /// Imports and each table's declared initialized prefix remain readable
    /// for this view's lifetime. They belong to the actual start generation.
    /// Table function calls retain their own caller and buffer contracts.
    pub unsafe fn new(raw: &'a abi::R4XStartContext2) -> Result<Self, Error> {
        if raw.magic != abi::START_MAGIC
            || raw.abi_major != 2
            || raw.size < mem::size_of_val(raw) as u32
        {
            return Err(Error::InvalidContext);
        }
        if raw.import_count > 32
            || (raw.import_count != 0
                && (raw.imports == 0
                    || !raw
                        .imports
                        .is_multiple_of(mem::align_of::<crate::abi::R4XStartImport>() as u64)))
        {
            return Err(Error::InvalidImports);
        }
        let mut result = Self {
            raw,
            tables: [0; 6],
            local: PhantomData,
        };
        let mut seen = 0u8;
        if raw.import_count != 0 {
            let imports = unsafe {
                core::slice::from_raw_parts(
                    raw.imports as *const crate::abi::R4XStartImport,
                    raw.import_count as usize,
                )
            };
            for item in imports {
                if item.group_id == 0 {
                    continue;
                }
                if item.group_id > 6 {
                    return Err(Error::InvalidImports);
                }
                if item.resolved_version != 2 {
                    return Err(Error::MixedGeneration);
                }
                let index = (item.group_id - 1) as usize;
                let bit = 1u8 << index;
                if seen & bit != 0 {
                    return Err(Error::DuplicateGroup);
                }
                seen |= bit;
                result.tables[index] = item.table;
            }
        }
        if result.tables[0] == 0 {
            return Err(Error::MissingSystem);
        }
        if result.group(1).is_none() {
            return Err(Error::InvalidTable);
        }
        Ok(result)
    }
    pub fn raw(&self) -> &'a abi::R4XStartContext2 {
        self.raw
    }
    /// The Contract supplies the slot offset and C function signature.
    /// Resolving an address neither invokes it nor changes its buffer loans.
    pub fn lookup(&self, group: u32, offset: u32) -> Result<u64, i32> {
        let table = self.group(group).ok_or(crate::abi::err_no_group)?;
        let size = unsafe { *(table.cast::<u32>()).add(2) };
        if offset < 16 || !offset.is_multiple_of(8) || u64::from(offset) + 8 > u64::from(size) {
            return Err(crate::abi::err_no_fn);
        }
        let address = (table as usize)
            .checked_add(offset as usize)
            .ok_or(crate::abi::err_no_fn)?;
        let slot = unsafe { *(address as *const u64) };
        if slot == 0 {
            Err(crate::abi::err_no_fn)
        } else {
            Ok(slot)
        }
    }
    pub fn group(&self, group: u32) -> Option<*const c_void> {
        const MAGIC: [u32; 6] = [
            abi::R4SYS_MAGIC,
            abi::R4DESK_MAGIC,
            abi::R4DRAW_MAGIC,
            abi::R4NET_MAGIC,
            abi::R4AUDIO_MAGIC,
            abi::R4DEV_MAGIC,
        ];
        if !(1..=6).contains(&group) {
            return None;
        }
        let address = self.tables[(group - 1) as usize];
        if address == 0 || !address.is_multiple_of(8) {
            return None;
        }
        // Read only the promised header, never form a full-table reference
        // for a shorter compatible prefix.
        let header = address as *const u32;
        if unsafe { *header } != MAGIC[(group - 1) as usize]
            || unsafe { *header.add(1) } < 1
            || unsafe { *header.add(2) } < 16
        {
            return None;
        }
        Some(address as *const c_void)
    }
}
