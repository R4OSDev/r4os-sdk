use super::{boolean, c, slot};
use crate::storage::{Error, Result};
use core::{marker::PhantomData, mem::MaybeUninit, ptr::NonNull};

/// Native text state retains an exclusive buffer loan; it owns no independent
/// Unicode editor. Moving this Rust wrapper does not move its borrowed data.
pub struct TextField<'b> {
    native: MaybeUninit<c::R4SdkGuiTextField>,
    buffer: NonNull<u8>,
    capacity: usize,
    _loan: PhantomData<&'b mut [u8]>,
}
impl<'b> TextField<'b> {
    pub fn new(buffer: &'b mut [u8]) -> Result<Self> {
        if buffer.is_empty() {
            return Err(Error::Length);
        }
        let capacity = buffer.len();
        let buffer = NonNull::new(buffer.as_mut_ptr()).ok_or(Error::Length)?;
        let mut native = MaybeUninit::uninit();
        let out = slot(unsafe {
            c::R4SdkGui_borrowedTextField(0, buffer.as_ptr(), capacity as _, native.as_mut_ptr())
        })?;
        if out.flags & 1 == 0 {
            return Err(Error::Length);
        }
        Ok(Self {
            native,
            buffer,
            capacity,
            _loan: PhantomData,
        })
    }
    pub fn set_exact(&mut self, text: &[u8]) -> Result<bool> {
        boolean(unsafe {
            c::R4SdkGuiTextField_setExact(
                0,
                self.native.as_mut_ptr(),
                text.as_ptr(),
                text.len() as _,
            )
        })
    }
    pub fn paste(&mut self, text: &[u8]) -> Result<bool> {
        boolean(unsafe {
            c::R4SdkGuiTextField_pasteSlice(
                0,
                self.native.as_mut_ptr(),
                text.as_ptr(),
                text.len() as _,
            )
        })
    }
    pub fn handle_codepoint(&mut self, value: u32) -> Result<bool> {
        boolean(unsafe {
            c::R4SdkGuiTextField_handleCodepointChecked(0, self.native.as_mut_ptr(), value)
        })
    }
    pub fn set_selection(&mut self, start: usize, end: usize) -> Result<()> {
        slot(unsafe {
            c::R4SdkGuiTextField_setSelection(0, self.native.as_mut_ptr(), start as _, end as _)
        })?;
        Ok(())
    }
    pub fn value(&self) -> Result<&[u8]> {
        let value = slot(unsafe { c::R4SdkGuiTextField_value(0, self.native.as_ptr()) })?;
        if value.length as usize >= self.capacity {
            return Err(Error::InvalidProvider);
        }
        Ok(unsafe { core::slice::from_raw_parts(self.buffer.as_ptr(), value.length as usize) })
    }
    /// # Safety
    /// Do not change the buffer identity/length or violate native selection,
    /// cursor or UTF-8 invariants. This loan ends before the next safe call.
    pub unsafe fn native(&mut self) -> *mut c::R4SdkGuiTextField {
        self.native.as_mut_ptr()
    }
}
pub struct TextArea<'b> {
    native: MaybeUninit<c::R4SdkGuiTextArea>,
    view: MaybeUninit<c::R4SdkGuiTextAreaView>,
    buffer: NonNull<u8>,
    capacity: usize,
    _loan: PhantomData<&'b mut [u8]>,
}
impl<'b> TextArea<'b> {
    pub fn new(buffer: &'b mut [u8], columns: usize, rows: usize) -> Result<Self> {
        if buffer.len() < 2 {
            return Err(Error::Length);
        }
        let capacity = buffer.len();
        let buffer = NonNull::new(buffer.as_mut_ptr()).ok_or(Error::Length)?;
        let mut native = MaybeUninit::uninit();
        let out = slot(unsafe {
            c::R4SdkGui_borrowedTextArea(0, buffer.as_ptr(), capacity as _, native.as_mut_ptr())
        })?;
        if out.flags & 1 == 0 {
            return Err(Error::Length);
        }
        let mut view = MaybeUninit::uninit();
        slot(unsafe {
            c::R4SdkGuiTextAreaView_init(0, columns as _, rows as _, view.as_mut_ptr())
        })?;
        Ok(Self {
            native,
            view,
            buffer,
            capacity,
            _loan: PhantomData,
        })
    }
    /// Uses the native area's existing bounded preload semantics.
    pub fn set(&mut self, text: &[u8]) -> Result<()> {
        slot(unsafe {
            c::R4SdkGuiTextArea_set(0, self.native.as_mut_ptr(), text.as_ptr(), text.len() as _)
        })?;
        Ok(())
    }
    pub fn paste(&mut self, text: &[u8]) -> Result<bool> {
        boolean(unsafe {
            c::R4SdkGuiTextArea_pasteSlice(
                0,
                self.native.as_mut_ptr(),
                text.as_ptr(),
                text.len() as _,
                self.view.as_ptr(),
            )
        })
    }
    pub fn delete_backward(&mut self) -> Result<bool> {
        boolean(unsafe {
            c::R4SdkGuiTextArea_deleteBackward(0, self.native.as_mut_ptr(), self.view.as_ptr())
        })
    }
    pub fn value(&self) -> Result<&[u8]> {
        let v = slot(unsafe { c::R4SdkGuiTextArea_value(0, self.native.as_ptr()) })?;
        if v.length as usize >= self.capacity {
            return Err(Error::InvalidProvider);
        }
        Ok(unsafe { core::slice::from_raw_parts(self.buffer.as_ptr(), v.length as usize) })
    }
    /// # Safety
    /// Preserve the native buffer, cursor, selection and text invariants.
    pub unsafe fn native(&mut self) -> *mut c::R4SdkGuiTextArea {
        self.native.as_mut_ptr()
    }
}
