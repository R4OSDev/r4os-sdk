#ifndef R4OS_DESKTOP_ACTIONS_H
#define R4OS_DESKTOP_ACTIONS_H
#include "app_services.h"
/* Explicit own-launch delegation. A saved operation and exact arguments are
 * reconciled after Unknown; response loss never means that WM did not apply. */
static inline int r4_desktop_action_same_process(R4ProgramProcessHandle a,R4ProgramProcessHandle b){return a.instance_id==b.instance_id&&a.generation==b.generation&&a.reserved==b.reserved;}
static inline int r4_desktop_action_same_window(R4WindowModeIdentity a,R4WindowModeIdentity b){return r4_desktop_action_same_process(a.service,b.service)&&r4_desktop_action_same_process(a.desktop,b.desktop)&&r4_desktop_action_same_process(a.owner,b.owner)&&a.serial==b.serial&&a.window_id==b.window_id&&a.reserved==b.reserved;}
static inline int r4_desktop_action_valid_process(R4ProgramProcessHandle a){return a.instance_id&&a.generation&&!a.reserved;}
static inline R4DesktopActionRequest r4_desktop_action_request(const R4DesktopActionToken *token){R4DesktopActionRequest q={0};q.token.version=1;q.token.size=sizeof(q.token);if(token)q.token=*token;return q;}
static inline int32_t r4_desktop_action_prepare(const R4DesktopActionToken *scope,R4ProgramProcessHandle requester,R4ProgramProcessHandle controller,uint32_t rights,R4DesktopActionToken*out){
 if(!scope||!out||scope->version!=1||scope->size!=sizeof(*scope)||!r4_desktop_action_valid_process(scope->window.service)||!(scope->epoch[0]|scope->epoch[1]|scope->epoch[2])||!r4_desktop_action_valid_process(requester)||!r4_desktop_action_valid_process(controller)||!rights||(rights&~7u))return R4OS_DESKTOP_ACTION_RESULT_INVALID;
 *out=(R4DesktopActionToken){0};out->version=1;out->size=sizeof(*out);out->window.service=scope->window.service;out->request=requester;out->controller=controller;out->rights=rights;for(uint32_t i=0;i<3;++i)out->epoch[i]=scope->epoch[i];return 0;
}
static inline int32_t r4_desktop_action_call_ms(R4App*app,uint16_t op,const R4DesktopActionRequest*q,R4DesktopActionReply*out,uint32_t milliseconds){
 if(!app||!q||!out)return R4OS_DESKTOP_ACTION_RESULT_INVALID;
 R4Services services=r4_app_services(app);R4ServiceConnection connection={0};int32_t rc=r4_services_open(&services,R4OS_WINDOW_SERVICE_NAME,&connection);if(rc)return rc;
 R4DesktopActionReply reply;R4Duration duration={(uint64_t)milliseconds*1000000u};
 R4ServiceCallResult call=r4_service_connection_call(&connection,op,q,sizeof(*q),&reply,sizeof(reply),r4_timeout_finite(duration));(void)r4_service_connection_close(&connection);
 if(call.kind==R4_SERVICE_CALL_TIMED_OUT)return R4OS_SERVICE_API_RESULT_TIMEOUT;if(call.kind!=R4_SERVICE_CALL_RESPONSE)return call.raw_code;
 if(call.bytes!=sizeof(reply)||reply.request.token.version!=1||reply.request.token.size!=sizeof(R4DesktopActionToken)||reply.result>0||reply.result<R4OS_DESKTOP_ACTION_RESULT_RELEASED||reply.phase>R4OS_DESKTOP_ACTION_PHASE_UNKNOWN||reply.applied.version!=1||reply.applied.size!=sizeof(R4DesktopActionState)||reply.current.version!=1||reply.current.size!=sizeof(R4DesktopActionState))return R4OS_DESKTOP_ACTION_RESULT_INVALID;
 const R4DesktopActionToken*t=&reply.request.token;
 if(op!=R4OS_DESKTOP_ACTION_OP_SCOPE&&op!=R4OS_DESKTOP_ACTION_OP_APP_VIEW&&(!r4_desktop_action_same_process(t->window.service,q->token.window.service)||!r4_desktop_action_same_process(t->request,q->token.request)||!r4_desktop_action_same_process(t->controller,q->token.controller)||t->rights!=q->token.rights||t->epoch[0]!=q->token.epoch[0]||t->epoch[1]!=q->token.epoch[1]||t->epoch[2]!=q->token.epoch[2]||(q->token.grant&&t->grant!=q->token.grant)||(q->token.window.serial&&!r4_desktop_action_same_window(t->window,q->token.window))))return R4OS_DESKTOP_ACTION_RESULT_INVALID;
 if(op==R4OS_DESKTOP_ACTION_OP_APP_VIEW&&!reply.result&&t->window.window_id!=q->token.window.window_id)return R4OS_DESKTOP_ACTION_RESULT_INVALID;
 *out=reply;return 0;
}
static inline int32_t r4_desktop_action_scope(R4App*app,R4DesktopActionReply*out){R4DesktopActionRequest q=r4_desktop_action_request(0);return r4_desktop_action_call_ms(app,R4OS_DESKTOP_ACTION_OP_SCOPE,&q,out,500);}
static inline int32_t r4_desktop_action_grant(R4App*app,const R4DesktopActionToken*t,R4DesktopActionReply*out){R4DesktopActionRequest q=r4_desktop_action_request(t);return r4_desktop_action_call_ms(app,R4OS_DESKTOP_ACTION_OP_GRANT,&q,out,500);}
static inline int32_t r4_desktop_action_command(R4App*app,const R4DesktopActionRequest*q,R4DesktopActionReply*out){return r4_desktop_action_call_ms(app,R4OS_DESKTOP_ACTION_OP_COMMAND,q,out,500);}
static inline int32_t r4_desktop_action_status(R4App*app,const R4DesktopActionToken*t,uint64_t operation,R4DesktopActionReply*out){R4DesktopActionRequest q=r4_desktop_action_request(t);q.operation=operation;return r4_desktop_action_call_ms(app,R4OS_DESKTOP_ACTION_OP_STATUS,&q,out,500);}
static inline int32_t r4_desktop_action_release(R4App*app,const R4DesktopActionToken*t,R4DesktopActionReply*out){R4DesktopActionRequest q=r4_desktop_action_request(t);return r4_desktop_action_call_ms(app,R4OS_DESKTOP_ACTION_OP_RELEASE,&q,out,500);}
static inline int32_t r4_desktop_action_app_view(R4App*app,int32_t window_id,R4DesktopActionReply*out){if(window_id<0)return R4OS_DESKTOP_ACTION_RESULT_INVALID;R4DesktopActionRequest q=r4_desktop_action_request(0);q.token.window.window_id=(uint32_t)window_id;return r4_desktop_action_call_ms(app,R4OS_DESKTOP_ACTION_OP_APP_VIEW,&q,out,20);}
static inline int32_t r4_desktop_action_app_frame(R4App*app,const R4DesktopActionToken*t,uint64_t revision,uint64_t frame,int32_t width,int32_t height,R4DesktopActionReply*out){R4DesktopActionRequest q=r4_desktop_action_request(t);q.operation=revision;q.frame_generation=frame;q.width=width;q.height=height;return r4_desktop_action_call_ms(app,R4OS_DESKTOP_ACTION_OP_APP_FRAME,&q,out,20);}
static inline int r4_desktop_action_frame_ready(const R4DesktopActionReply*r){return r&&r->phase==R4OS_DESKTOP_ACTION_PHASE_APPLIED&&!r->result&&r->applied.view_revision&&r->applied.view_revision==r->current.view_revision&&r4_desktop_action_same_window(r->applied.window,r->current.window)&&(r->current.proof_flags&R4OS_DESKTOP_ACTION_PROOF_COMPOSED)&&r->current.composition_serial&&((r->current.proof_flags&R4OS_DESKTOP_ACTION_PROOF_INVISIBLE)||(r->current.proof_flags&R4OS_DESKTOP_ACTION_PROOF_APP_FRESH));}
#endif
