use super::{Rect, c, code, exact, slot};
use crate::{
    App, abi,
    resources::Timeout,
    storage::{Error, Result},
};
use core::{
    ffi::CStr,
    marker::{PhantomData, PhantomPinned},
    mem::MaybeUninit,
    pin::Pin,
    ptr::NonNull,
};

pub type Event = c::R4SdkGuiEvent;
pub type TimerStorage = MaybeUninit<c::R4SdkGuiTimer>;
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Role {
    Window,
    DesktopHost,
}
/// Pin this storage before opening. Native contexts refer to their own stable
/// bundle; neither Rust nor C may move that bundle while a session is live.
pub struct SessionStorage {
    native: MaybeUninit<c::R4SdkGuiSession>,
    _pin: PhantomPinned,
}
impl SessionStorage {
    pub const fn new() -> Self {
        Self {
            native: MaybeUninit::uninit(),
            _pin: PhantomPinned,
        }
    }
}
impl Default for SessionStorage {
    fn default() -> Self {
        Self::new()
    }
}
pub struct Session<'app, 'storage> {
    native: NonNull<c::R4SdkGuiSession>,
    _storage: PhantomData<Pin<&'storage mut SessionStorage>>,
    _timers: PhantomData<&'storage mut [TimerStorage]>,
    _app: PhantomData<&'app ()>,
    _local: PhantomData<*mut ()>,
}
impl<'app, 'storage> Session<'app, 'storage> {
    pub fn open(
        storage: Pin<&'storage mut SessionStorage>,
        app: &'app App<'_>,
        role: Role,
        timers: &'storage mut [TimerStorage],
    ) -> Result<Self> {
        // Only native code writes opaque storage, including its uninitialized
        // padding. We never form a reference to the native record.
        let native = unsafe { storage.get_unchecked_mut() }.native.as_mut_ptr();
        let timer_count = timers.len();
        let timers = timers.as_mut_ptr();
        exact(unsafe {
            c::R4SdkGuiSessionOpen(
                native,
                app.start_context(),
                match role {
                    Role::Window => 0,
                    Role::DesktopHost => 1,
                },
                timers.cast(),
                timer_count as _,
            )
        })?;
        Ok(Self {
            native: NonNull::new(native).ok_or(Error::InvalidProvider)?,
            _storage: PhantomData,
            _timers: PhantomData,
            _app: PhantomData,
            _local: PhantomData,
        })
    }
    fn pointer(&mut self) -> *mut c::R4SdkGuiSession {
        // Native contexts retain interior pointers into this allocation.
        // Never recreate an exclusive Rust reference after native admission.
        self.native.as_ptr()
    }
    pub fn set_title(&mut self, title: &CStr) -> Result<i32> {
        let w = unsafe { c::R4SdkGuiSessionWindow(self.pointer()) };
        if w.is_null() {
            return Err(Error::Unavailable);
        }
        code(unsafe { c::R4SdkGuiWindow_setTitle(0, w, title.as_ptr().cast()) })
    }
    pub fn set_minimum_size(&mut self, width: i32, height: i32) -> Result<i32> {
        if width <= 0 || height <= 0 {
            return Err(Error::Length);
        }
        let w = unsafe { c::R4SdkGuiSessionWindow(self.pointer()) };
        if w.is_null() {
            return Err(Error::Unavailable);
        }
        code(unsafe { c::R4SdkGuiWindow_setMinimumSize(0, w, width, height) })
    }
    /// Exact native state; a null token queries the current own window.
    pub fn pointer_info(
        &mut self,
        token: Option<&abi::GuiPointerCaptureHandle>,
    ) -> Result<abi::GuiPointerCaptureInfo> {
        let mut out = abi::GuiPointerCaptureInfo::default();
        code(unsafe {
            c::R4SdkGuiDesktopContext_guiPointerCaptureInfo(
                0,
                self.native_desktop(),
                c::R4SdkGuiSlot {
                    ptr: token.map_or(core::ptr::null_mut(), |value| {
                        core::ptr::from_ref(value).cast_mut().cast()
                    }),
                    length: 0,
                    bits: 0,
                    status: 0,
                    flags: u32::from(token.is_some()), // R4SDK_GUI_PRESENT, optional pointer only.
                },
                &mut out,
            )
        })?;
        Ok(out)
    }
    pub fn pointer_identity(&mut self) -> Result<abi::GuiPointerWindowIdentity> {
        let info = self.pointer_info(None)?;
        if info.capture.window.epoch == 0 || info.capture.window.window_id < 0 {
            return Err(Error::Raw(abi::gui_pointer_error_unavailable));
        }
        Ok(info.capture.window)
    }
    /// Success is PENDING. The native capture_changed event grants ACTIVE;
    /// physical relative events never derive from clamped cursor positions.
    pub fn pointer_capture(
        &mut self,
        window: &abi::GuiPointerWindowIdentity,
        mode: u32,
    ) -> Result<abi::GuiPointerCaptureHandle> {
        let mut out = abi::GuiPointerCaptureHandle::default();
        code(unsafe {
            c::R4SdkGuiDesktopContext_guiPointerCaptureAcquire(
                0,
                self.native_desktop(),
                window,
                mode,
                &mut out,
            )
        })?;
        Ok(out)
    }
    pub fn pointer_release(&mut self, capture: &abi::GuiPointerCaptureHandle) -> Result<i32> {
        code(unsafe {
            c::R4SdkGuiDesktopContext_guiPointerCaptureRelease(0, self.native_desktop(), capture)
        })
    }

    pub fn window_info(&mut self) -> Result<Option<abi::GuiWindowInfo>> {
        let w = unsafe { c::R4SdkGuiSessionWindow(self.pointer()) };
        if w.is_null() {
            return Ok(None);
        }
        let mut out = abi::GuiWindowInfo::default();
        let result = slot(unsafe { c::R4SdkGuiWindow_info(0, w, &mut out) })?;
        Ok(if result.flags & 1 != 0 {
            Some(out)
        } else {
            None
        })
    }
    pub fn next(&mut self, timeout: Timeout) -> Result<Option<Event>> {
        let mut out: Event = unsafe { core::mem::zeroed() };
        match unsafe { c::R4SdkGuiSessionNext(self.pointer(), &timeout.raw(), &mut out) } {
            1 => Ok(Some(out)),
            0 => Ok(None),
            rc => Err(Error::Raw(rc)),
        }
    }
    pub fn start_timer(
        &mut self,
        index: usize,
        id: u32,
        nanoseconds: u64,
        repeating: bool,
    ) -> Result<()> {
        exact(unsafe {
            c::R4SdkGuiSessionTimer(
                self.pointer(),
                index as _,
                id,
                &abi::R4Duration { nanoseconds },
                u32::from(repeating),
            )
        })
    }
    pub fn cancel_timer(&mut self, index: usize) -> Result<()> {
        exact(unsafe { c::R4SdkGuiSessionCancelTimer(self.pointer(), index as _) })
    }
    pub fn post_command(&mut self, id: u32) -> Result<()> {
        exact(unsafe { c::R4SdkGuiSessionCommand(self.pointer(), id) })
    }
    pub fn begin<'s>(
        &'s mut self,
        commands: &'s mut [abi::GuiFrameCommand],
        resources: &'s mut [u8],
    ) -> Result<Paint<'s, 'app, 'storage>> {
        exact(unsafe {
            c::R4SdkGuiSessionBegin(
                self.pointer(),
                commands.as_mut_ptr(),
                commands.len() as _,
                resources.as_mut_ptr(),
                resources.len() as _,
            )
        })?;
        let canvas = NonNull::new(unsafe { c::R4SdkGuiSessionCanvas(self.pointer()) })
            .ok_or(Error::InvalidProvider)?;
        Ok(Paint {
            owner: self,
            canvas,
            active: true,
            _buffers: PhantomData,
        })
    }
    pub fn poll_mode(&mut self) -> Result<abi::WindowModeReply> {
        self.mode(0, 0)
    }
    pub fn request_fullscreen(&mut self, fullscreen: bool) -> Result<abi::WindowModeReply> {
        self.mode(1, u32::from(fullscreen))
    }
    pub fn retry_mode(&mut self) -> Result<abi::WindowModeReply> {
        self.mode(2, 0)
    }
    fn mode(&mut self, action: u32, value: u32) -> Result<abi::WindowModeReply> {
        let mut out = abi::WindowModeReply::default();
        exact(unsafe { c::R4SdkGuiSessionMode(self.pointer(), action, value, &mut out) })?;
        Ok(out)
    }
    /// One technical claim, without application startup/retry policy. A live
    /// different host is rejected by WindowService. No app window is queried.
    pub fn claim_host(&mut self, timeout: Timeout) -> Result<abi::TrayDesktopExchange> {
        let mut out = abi::TrayDesktopExchange::default();
        exact(unsafe { c::R4SdkGuiSessionHostClaim(self.pointer(), &mut out, &timeout.raw()) })?;
        Ok(out)
    }
    pub fn host_exchange(
        &mut self,
        op: u16,
        request: &abi::TrayDesktopExchange,
        timeout: Timeout,
    ) -> Result<abi::TrayDesktopExchange> {
        let mut out = abi::TrayDesktopExchange::default();
        exact(unsafe {
            c::R4SdkGuiSessionHostExchange(self.pointer(), op, request, &mut out, &timeout.raw())
        })?;
        Ok(out)
    }
    /// Closes only the local endpoint. Exact live process binding remains at
    /// WindowService; a subsequent explicit claim revalidates that service.
    pub fn reset_host_connection(&mut self) {
        unsafe { c::R4SdkGuiSessionHostReset(self.pointer()) }
    }
    pub fn clipboard_write(&mut self, text: &[u8]) -> Result<i32> {
        let p = unsafe { c::R4SdkGuiSessionProgram(self.pointer()) };
        code(unsafe { c::R4SdkGuiClipboard_writeText(0, p, text.as_ptr(), text.len() as _) })
    }
    pub fn clipboard_clear(&mut self) -> Result<i32> {
        let p = unsafe { c::R4SdkGuiSessionProgram(self.pointer()) };
        code(unsafe { c::R4SdkGuiClipboard_clear(0, p) })
    }
    pub fn clipboard_info(&mut self) -> Result<abi::ClipboardInfo> {
        let p = unsafe { c::R4SdkGuiSessionProgram(self.pointer()) };
        let mut out = abi::ClipboardInfo::default();
        slot(unsafe { c::R4SdkGuiClipboard_query(0, p, &mut out) })?;
        Ok(out)
    }
    pub fn clipboard_read<'b>(&mut self, buffer: &'b mut [u8]) -> Result<&'b [u8]> {
        let p = unsafe { c::R4SdkGuiSessionProgram(self.pointer()) };
        let mut out = MaybeUninit::<c::R4SdkGuiClipboardReadResult>::uninit();
        slot(unsafe {
            c::R4SdkGuiClipboard_readText(
                0,
                p,
                buffer.as_mut_ptr(),
                buffer.len() as _,
                out.as_mut_ptr(),
            )
        })?;
        let rc = code(unsafe { c::R4SdkGuiClipboardReadResult_get_code(out.as_ptr()) })? as usize;
        if rc > buffer.len() {
            return Err(Error::InvalidProvider);
        }
        Ok(&buffer[..rc])
    }
    /// # Safety
    /// The pointer borrows this pinned session and its exact executing App.
    /// Do not move/copy contexts, escape this loan, mutate private fields or
    /// retain callbacks/buffers past their owner's acknowledgement.
    pub unsafe fn native_desktop(&mut self) -> *mut c::R4SdkGuiDesktopContext {
        unsafe { c::R4SdkGuiSessionDesktop(self.pointer()) }
    }
    /// # Safety
    /// Same context/owner/lifetime requirements as `native_desktop`.
    pub unsafe fn native_draw(&mut self) -> *mut c::R4SdkGuiDrawContext {
        unsafe { c::R4SdkGuiSessionDraw(self.pointer()) }
    }
    /// # Safety
    /// Same context/owner/lifetime requirements as `native_desktop`.
    pub unsafe fn native_program(&mut self) -> *mut c::R4SdkGuiProgramContext {
        unsafe { c::R4SdkGuiSessionProgram(self.pointer()) }
    }
}
impl Drop for Session<'_, '_> {
    fn drop(&mut self) {
        unsafe { c::R4SdkGuiSessionClose(self.pointer()) }
    }
}

pub struct Paint<'s, 'app, 'storage> {
    owner: &'s mut Session<'app, 'storage>,
    canvas: NonNull<c::R4SdkGuiCanvas>,
    active: bool,
    _buffers: PhantomData<(&'s mut [abi::GuiFrameCommand], &'s mut [u8])>,
}
impl Paint<'_, '_, '_> {
    pub fn clear(&mut self, rgb: u32) -> Result<i32> {
        code(unsafe { c::R4SdkGuiCanvas_clear(0, self.canvas.as_ptr(), rgb) })
    }
    pub fn rect(&mut self, item: Rect, rgb: u32) -> Result<i32> {
        let r = item.native()?;
        code(unsafe { c::R4SdkGuiCanvas_rect(0, self.canvas.as_ptr(), r.as_ptr(), rgb) })
    }
    pub fn text(&mut self, x: i32, y: i32, value: &CStr, fg: u32, bg: u32) -> Result<i32> {
        code(unsafe {
            c::R4SdkGuiCanvas_text(0, self.canvas.as_ptr(), x, y, value.as_ptr().cast(), fg, bg)
        })
    }
    pub fn raster(
        &mut self,
        x: i32,
        y: i32,
        width: u32,
        height: u32,
        scale: u32,
        pixels: &[u32],
    ) -> Result<i32> {
        if scale == 0
            || (width as usize)
                .checked_mul(height as usize)
                .is_none_or(|n| n > pixels.len())
        {
            return Err(Error::Length);
        }
        code(unsafe {
            c::R4SdkGuiCanvas_raster(
                0,
                self.canvas.as_ptr(),
                x,
                y,
                width,
                height,
                scale,
                pixels.as_ptr(),
                pixels.len() as _,
            )
        })
    }
    #[allow(clippy::too_many_arguments)]
    pub fn blend_alpha8(
        &mut self,
        x: i32,
        y: i32,
        width: u32,
        height: u32,
        stride: u32,
        rgb: u32,
        alpha: &[u8],
    ) -> Result<i32> {
        if stride < width
            || (stride as usize)
                .checked_mul(height.saturating_sub(1) as usize)
                .and_then(|n| n.checked_add(width as usize))
                .is_none_or(|n| height != 0 && n > alpha.len())
        {
            return Err(Error::Length);
        }
        code(unsafe {
            c::R4SdkGuiCanvas_blendAlpha8(
                0,
                self.canvas.as_ptr(),
                x,
                y,
                width,
                height,
                stride,
                rgb,
                alpha.as_ptr(),
                alpha.len() as _,
            )
        })
    }
    pub fn present(mut self) -> Result<i32> {
        let rc = unsafe { c::R4SdkGuiSessionEnd(self.owner.pointer(), 1) };
        // Drop cancels an unsuccessful immediate paint as well. Successful
        // transactional commit is the original owner's real acknowledgement.
        if rc >= 0 {
            self.active = false;
            Ok(rc)
        } else {
            Err(Error::Raw(rc))
        }
    }
    pub fn discard(mut self) -> Result<()> {
        let rc = unsafe { c::R4SdkGuiSessionEnd(self.owner.pointer(), 0) };
        self.active = false;
        exact(rc)
    }
    /// # Safety
    /// Native widgets must preserve the original canvas/frame invariants and
    /// all resource loans. The pointer is invalid when this paint ends.
    pub unsafe fn native_canvas(&mut self) -> *mut c::R4SdkGuiCanvas {
        self.canvas.as_ptr()
    }
}
impl Drop for Paint<'_, '_, '_> {
    fn drop(&mut self) {
        if self.active {
            let _ = unsafe { c::R4SdkGuiSessionEnd(self.owner.pointer(), 0) };
        }
    }
}
