#ifndef R4OS_WAIT_SET_PLATFORM2_H
#define R4OS_WAIT_SET_PLATFORM2_H
#include "platform2.h"
#include "poll_budget.h"
/* Task-owned bounded wait-any over actual kernel owners. Context/table/code
 * live through every call and Close. Same-process peers may close a handle;
 * configuration/wait belong to its exact creating task generation. Do not
 * duplicate ownership. Readiness/timeout/Cancel never releases source buffers,
 * work or DMA. Failed Close retains its exact closed backing for retry. */
typedef struct R4SdkWaitSetProvider {
 R4SysWaitsetCreateFn create; R4SysWaitsetEnrollFn enroll;
 R4SysWaitsetRearmFn rearm; R4SysWaitsetRemoveFn remove;
 R4SysWaitsetWaitFn wait; R4SysWaitsetCloseFn close;
} R4SdkWaitSetProvider;
static inline int32_t R4SdkWaitSetProvider2(const R4OS2Context *context,R4SdkWaitSetProvider *out){
 if(!out)return R4OS_WAITSET_ERROR_INVALID;
 const uint32_t offsets[6]={offsetof(R4XStartR4Sys2,waitset_create),offsetof(R4XStartR4Sys2,waitset_enroll),offsetof(R4XStartR4Sys2,waitset_rearm),offsetof(R4XStartR4Sys2,waitset_remove),offsetof(R4XStartR4Sys2,waitset_wait),offsetof(R4XStartR4Sys2,waitset_close)};
 uint64_t addresses[6]={0};
 for(uint32_t i=0;i<6;++i){int32_t rc=R4OS2ContextFunction(context,1,offsets[i],&addresses[i]);if(rc)return rc;}
 *out=(R4SdkWaitSetProvider){(R4SysWaitsetCreateFn)(uintptr_t)addresses[0],(R4SysWaitsetEnrollFn)(uintptr_t)addresses[1],(R4SysWaitsetRearmFn)(uintptr_t)addresses[2],(R4SysWaitsetRemoveFn)(uintptr_t)addresses[3],(R4SysWaitsetWaitFn)(uintptr_t)addresses[4],(R4SysWaitsetCloseFn)(uintptr_t)addresses[5]};return 0;
}
static inline R4WaitSource R4SdkWaitSetNotification(uint64_t handle,uint64_t observed,uint64_t tag,uint32_t stop){
 return (R4WaitSource){.version=1,.size=sizeof(R4WaitSource),.kind=R4OS_WAITSET_SOURCE_NOTIFICATION,.flags=stop?R4OS_WAITSET_SOURCE_FLAG_STOP:0,.object=handle,.observed_revision=observed,.user_tag=tag};
}
static inline int32_t R4SdkWaitSetTimer(R4SdkClockSample sample,uint64_t absolute_ns,uint64_t tag,R4WaitSource *out){
 if(!out)return R4OS_WAITSET_ERROR_INVALID;
 R4SdkClockIdentity k=sample.identity;
 if(!k.source||!k.generation||!k.tick_hz)return R4OS_WAITSET_ERROR_CLOCK_UNAVAILABLE;
 *out=(R4WaitSource){.version=1,.size=sizeof(R4WaitSource),.kind=R4OS_WAITSET_SOURCE_TIMER,.user_tag=tag,.deadline_ns=absolute_ns,.clock_source=k.source,.clock_generation=k.generation,.event_backend=k.event_backend,.tick_hz=k.tick_hz};return 0;
}
static inline int32_t R4SdkWaitSetDeadlineFromBudget(const R4SdkDeadlineBudget *budget,R4WaitSetDeadline *out){
 if(!budget||!out||budget->kind>2||budget->reserved)return R4OS_WAITSET_ERROR_INVALID;
 R4WaitSetDeadline result={.version=1,.size=sizeof(R4WaitSetDeadline),.kind=budget->kind};
 if(budget->kind==1){R4SdkClockIdentity k=budget->identity;
  if(!k.source||!k.generation||!k.tick_hz)return R4OS_WAITSET_ERROR_CLOCK_UNAVAILABLE;
  result.absolute_ns=budget->deadline_ns;result.last_ns=budget->last_ns;result.clock_source=k.source;result.clock_generation=k.generation;result.event_backend=k.event_backend;result.tick_hz=k.tick_hz;
 }
 *out=result;return 0;
}
_Static_assert(sizeof(R4WaitSource)==80u,"wait source");
_Static_assert(sizeof(R4WaitSetDeadline)==48u,"wait deadline");
_Static_assert(sizeof(R4WaitSetEvent)==48u,"wait event");
_Static_assert(sizeof(R4WaitSetBatch)==40u,"wait batch");
#endif
