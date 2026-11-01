//! Own-launch WM delegation, exact retained receipt and separate frame view.
//! A transport failure or Unknown never means that WM did not apply the action.
use super::{Call, Services};
use crate::{
    abi as a,
    resources::Timeout,
    storage::{Error, Result},
};
use core::{ffi::CStr, mem};
pub type ActionToken = a::DesktopActionToken;
pub type ActionRequest = a::DesktopActionRequest;
pub type ActionReply = a::DesktopActionReply;
fn same(x: a::ProgramProcessHandle, y: a::ProgramProcessHandle) -> bool {
    x.instance_id == y.instance_id && x.generation == y.generation && x.reserved == y.reserved
}
fn valid(h: a::ProgramProcessHandle) -> bool {
    h.instance_id != 0 && h.generation != 0 && h.reserved == 0
}
pub fn prepare_actions(
    scope: ActionToken,
    request: a::ProgramProcessHandle,
    controller: a::ProgramProcessHandle,
    rights: u32,
) -> Result<ActionToken> {
    if scope.version != 1
        || scope.size as usize != mem::size_of::<ActionToken>()
        || !valid(scope.window.service)
        || scope.epoch == [0; 3]
        || !valid(request)
        || !valid(controller)
        || rights == 0
        || rights & !7 != 0
    {
        return Err(Error::Raw(a::desktop_action_result_invalid));
    }
    Ok(ActionToken {
        window: a::WindowModeIdentity {
            service: scope.window.service,
            ..Default::default()
        },
        request,
        controller,
        rights,
        epoch: scope.epoch,
        ..Default::default()
    })
}
pub fn action_frame_ready(reply: &ActionReply) -> bool {
    reply.phase == a::desktop_action_phase_applied
        && reply.result == 0
        && reply.applied.view_revision != 0
        && reply.current.view_revision == reply.applied.view_revision
        && same(reply.current.window.service, reply.applied.window.service)
        && same(reply.current.window.desktop, reply.applied.window.desktop)
        && same(reply.current.window.owner, reply.applied.window.owner)
        && reply.current.window.serial == reply.applied.window.serial
        && reply.current.window.window_id == reply.applied.window.window_id
        && reply.current.proof_flags & a::desktop_action_proof_composed != 0
        && reply.current.composition_serial != 0
        && (reply.current.proof_flags & a::desktop_action_proof_invisible != 0
            || reply.current.proof_flags & a::desktop_action_proof_app_fresh != 0)
}
impl Services<'_> {
    fn action_call(&self, op: u16, request: ActionRequest, nanos: u64) -> Result<ActionReply> {
        let name = CStr::from_bytes_with_nul(b"WINSVC\0").map_err(|_| Error::InvalidProvider)?;
        let mut connection = self.open(name)?;
        let mut bytes = [0u8; mem::size_of::<ActionReply>()];
        let body = unsafe {
            core::slice::from_raw_parts(
                core::ptr::from_ref(&request).cast(),
                mem::size_of_val(&request),
            )
        };
        let count = match connection.call(op, body, &mut bytes, Timeout::AfterNanos(nanos))? {
            Call::Response { bytes, .. } => bytes,
            Call::TimedOut => return Err(Error::Raw(a::service_api_result_timeout)),
            Call::RemoteFailure(code) => return Err(Error::Raw(code)),
        };
        if count != bytes.len() {
            return Err(Error::InvalidProvider);
        }
        let reply = unsafe { core::ptr::read_unaligned(bytes.as_ptr().cast::<ActionReply>()) };
        let token = reply.request.token;
        if token.version != 1
            || token.size as usize != mem::size_of::<ActionToken>()
            || reply.result > 0
            || reply.result < a::desktop_action_result_released
            || reply.phase > a::desktop_action_phase_unknown
            || reply.applied.version != 1
            || reply.applied.size as usize != mem::size_of::<a::DesktopActionState>()
            || reply.current.version != 1
            || reply.current.size as usize != mem::size_of::<a::DesktopActionState>()
        {
            return Err(Error::InvalidProvider);
        }
        if op != a::desktop_action_op_scope
            && op != a::desktop_action_op_app_view
            && (!same(token.window.service, request.token.window.service)
                || !same(token.request, request.token.request)
                || !same(token.controller, request.token.controller)
                || token.epoch != request.token.epoch
                || token.rights != request.token.rights
                || (request.token.grant != 0 && token.grant != request.token.grant)
                || (request.token.window.serial != 0
                    && (!same(token.window.owner, request.token.window.owner)
                        || !same(token.window.desktop, request.token.window.desktop)
                        || token.window.serial != request.token.window.serial
                        || token.window.window_id != request.token.window.window_id)))
        {
            return Err(Error::InvalidProvider);
        }
        if op == a::desktop_action_op_app_view
            && reply.result == 0
            && token.window.window_id != request.token.window.window_id
        {
            return Err(Error::InvalidProvider);
        }
        Ok(reply)
    }
    pub fn action_scope(&self) -> Result<ActionReply> {
        self.action_call(a::desktop_action_op_scope, Default::default(), 500_000_000)
    }
    pub fn action_grant(&self, token: ActionToken) -> Result<ActionReply> {
        self.action_call(
            a::desktop_action_op_grant,
            ActionRequest {
                token,
                ..Default::default()
            },
            500_000_000,
        )
    }
    pub fn action_command(&self, request: ActionRequest) -> Result<ActionReply> {
        self.action_call(a::desktop_action_op_command, request, 500_000_000)
    }
    pub fn action_status(&self, token: ActionToken, operation: u64) -> Result<ActionReply> {
        self.action_call(
            a::desktop_action_op_status,
            ActionRequest {
                token,
                operation,
                ..Default::default()
            },
            500_000_000,
        )
    }
    pub fn action_release(&self, token: ActionToken) -> Result<ActionReply> {
        self.action_call(
            a::desktop_action_op_release,
            ActionRequest {
                token,
                ..Default::default()
            },
            500_000_000,
        )
    }
    pub fn action_app_view(&self, window_id: u32) -> Result<ActionReply> {
        self.action_call(
            a::desktop_action_op_app_view,
            ActionRequest {
                token: ActionToken {
                    window: a::WindowModeIdentity {
                        window_id,
                        ..Default::default()
                    },
                    ..Default::default()
                },
                ..Default::default()
            },
            20_000_000,
        )
    }
    pub fn action_app_frame(
        &self,
        view: &ActionReply,
        frame_generation: u64,
        width: i32,
        height: i32,
    ) -> Result<ActionReply> {
        self.action_call(
            a::desktop_action_op_app_frame,
            ActionRequest {
                token: view.request.token,
                operation: view.current.view_revision,
                frame_generation,
                width,
                height,
                ..Default::default()
            },
            20_000_000,
        )
    }
}
