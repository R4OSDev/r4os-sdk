/* Reuse the actual existing C protocol peers, without unrelated power cases. */
#define main sdk_service_unused_fixture
#include "../Conformance/ServiceNetworkFacadePrototype05826.c"
#undef main
#include <r4os/facades.h>
#include <assert.h>

static uint64_t clock_tick=100, last_wait;
static uint32_t forbidden_calls;
static int32_t forbidden_open(uint32_t id,R4ProgramProcessHandle *out){(void)id;(void)out;++forbidden_calls;return -99;}
static uint32_t queued, yielded, stopping, reply_cancelled, io_live, io_done;
static uint8_t *async_out;
static const uint8_t *async_in;
static R4ServiceMessageHeader *async_header;
static uint16_t async_op;
static uint32_t async_handle,async_length,async_capacity;
static int32_t async_result;
static uint32_t serial_live, serial_closing;
static uint64_t serial_id=UINT64_C(0x1122334455667788),serial_generation=UINT64_C(0x99aabbccddeeff00),serial_handle=UINT64_C(0xabcd0123456789ef);
int sdk_service_c_case(void){return service_network_checks();}
void sdk_service_mode(uint32_t value){reply_mode=(enum ReplyMode)value;}
void sdk_service_queue(uint32_t n){queued=n;}
void sdk_service_stop(uint32_t value){stopping=value;}
void sdk_service_cancel_reply(uint32_t value){reply_cancelled=value;}
uint32_t sdk_service_yielded(void){return yielded;}
uint64_t sdk_service_last_wait(void){return last_wait;}
uint32_t sdk_service_open_handles(void){return open_handles;}
static uint64_t ticks(void){return clock_tick;}
static void time_state(R4TimeState *out){memset(out,0,sizeof(*out));out->monotonic_hz=1000;}
static uint32_t should_close(void){return stopping;}
static void task_yield(void){++yielded;}
static int32_t endpoint_wait(uint32_t handle,uint64_t timeout){last_wait=timeout;return handle==201&&endpoint_registered?(int32_t)queued:R4OS_SERVICE_API_RESULT_BAD_HANDLE;}
static int32_t endpoint_poll(uint32_t handle){return endpoint_wait(handle,0);}
static int32_t endpoint_recv(uint32_t handle,R4ServiceMessageHeader *header,uint8_t *out,uint32_t capacity){endpoint_ready=queued!=0;int32_t rc=fake_recv(handle,header,out,capacity);if(rc>=0&&queued)--queued;return rc;}
static int32_t endpoint_reply(uint32_t handle,uint32_t id,int32_t status,const uint8_t *bytes,uint32_t n){if(reply_cancelled)return R4OS_SERVICE_API_RESULT_NOT_FOUND;return fake_reply(handle,id,status,bytes,n);}
static int32_t io_begin(uint32_t handle,uint16_t op,const uint8_t *in,uint32_t n,R4ServiceMessageHeader *header,uint8_t *out,uint32_t capacity,uint64_t timeout,uint32_t flags,uint32_t *id){
    assert((handle==102||handle==103)&&capacity>=sizeof(R4NetServiceTcpResult)+2&&flags==0&&!io_live);
    if(op==37)assert(n==4&&memcmp(in,"PING",4)==0&&timeout==17);
    async_in=in;async_out=out;async_header=header;async_op=op;async_handle=handle;async_length=n;async_capacity=capacity;io_live=1;io_done=0;*id=901;return 0;
}
static int32_t io_status(uint32_t id,R4ProgramIoInfo *out){
    if(id!=901||!io_live)return R4OS_IO_ERROR_NOT_FOUND;
    memset(out,0,sizeof(*out));out->state=io_done?R4OS_IO_STATE_COMPLETED:R4OS_IO_STATE_PENDING;
    out->result=io_done?async_result:0;return 0;
}
void sdk_service_complete(void){
    assert(io_live&&!io_done);
    if(async_op!=37){R4SdkDeadlineView view=R4SdkDeadlineSplit(async_in,async_length);async_result=fake_call(async_handle,async_op,async_in,(uint32_t)view.length,async_header,async_out,async_capacity,17);io_done=1;return;}
    assert(memcmp(async_in,"PING",4)==0);
    R4NetServiceTcpResult result={.magic=R4OS_NET_SERVICE_TCP_RESULT_MAGIC,.version=R4OS_NET_SERVICE_TCP_RESULT_VERSION,.flags=R4OS_NET_SERVICE_TCP_FLAG_DATA,.bytes=2,.pending_rx=2,.tx_window=9};
    memcpy(async_out,&result,sizeof(result));memcpy(async_out+sizeof(result),"OK",2);
    *async_header=(R4ServiceMessageHeader){.magic=R4OS_SERVICE_API_MAGIC,.version=R4OS_SERVICE_API_VERSION,.op=async_op};async_result=sizeof(result)+2;io_done=1;
}
static int32_t io_wait(uint32_t id,uint64_t timeout,R4ProgramIoInfo *out){if(id==901&&io_live&&!io_done&&async_op!=37)sdk_service_complete();int32_t rc=io_status(id,out);return rc!=0?rc:(!io_done&&timeout!=R4OS_IO_WAIT_FOREVER?R4OS_IO_ERROR_TIMEOUT:0);}
static int32_t io_close(uint32_t id){if(id!=901||!io_live)return R4OS_IO_ERROR_NOT_FOUND;if(!io_done)return R4OS_IO_ERROR_BUSY;io_live=0;return 0;}
void sdk_service_reap_pending(void){assert(io_live&&io_done);assert(io_close(901)==0);assert(fake_close(async_handle)==0);}
static uint32_t port_count(void){return 1;}
static int32_t port_at(uint32_t index,R4SerialPortInfo *out){if(index)return R4OS_SERIAL_ERROR_NOT_FOUND;memset(out,0,sizeof(*out));out->com_number=3;out->port_id=serial_id;out->generation=serial_generation;return 0;}
static int32_t port_open(uint64_t id,uint64_t generation,const R4SerialConfig *config,uint64_t *out){(void)config;if(id!=serial_id||generation!=serial_generation)return R4OS_SERIAL_ERROR_STALE;if(serial_live)return R4OS_SERIAL_ERROR_BUSY;serial_live=1;*out=serial_handle;return 0;}
static int32_t port_configure(uint64_t handle,const R4SerialConfig *config){(void)config;return handle==serial_handle?0:R4OS_SERIAL_ERROR_STALE;}
static int32_t port_read(uint64_t handle,uint8_t *out,uint32_t n,uint64_t ticks_value,R4SerialTransfer *info){assert(handle==serial_handle&&serial_live&&n>=2&&ticks_value==19);out[0]='R';out[1]='X';memset(info,0,sizeof(*info));info->completed=2;info->requested=n;return R4OS_SERIAL_ERROR_TIMEOUT;}
static int32_t port_write(uint64_t handle,const uint8_t *bytes,uint32_t n,uint64_t ticks_value,R4SerialTransfer *info){assert(handle==serial_handle&&serial_live&&n==4&&memcmp(bytes,"SEND",4)==0&&ticks_value==19);memset(info,0,sizeof(*info));info->completed=2;info->requested=n;return 0;}
static int32_t port_drain(uint64_t handle,uint64_t ticks_value){(void)ticks_value;return handle==serial_handle?0:R4OS_SERIAL_ERROR_STALE;}
static int32_t port_status(uint64_t handle,R4SerialStatus *out){if(handle!=serial_handle)return R4OS_SERIAL_ERROR_STALE;memset(out,0,sizeof(*out));return 0;}
static int32_t port_cancel(uint64_t handle){if(handle!=serial_handle)return R4OS_SERIAL_ERROR_STALE;serial_closing=0;return 0;}
static int32_t port_close(uint64_t handle,uint32_t flags,uint64_t timeout){(void)flags;(void)timeout;if(handle!=serial_handle)return R4OS_SERIAL_ERROR_STALE;if(serial_closing)return R4OS_SERIAL_ERROR_BUSY;serial_live=0;return 0;}
void sdk_serial_busy(uint32_t value){serial_closing=value;}
uint32_t sdk_serial_live(void){return serial_live;}
void sdk_service_tables(R4XStartR4Sys *sys,R4XStartR4Net *net,R4XStartR4Desk *desk,R4XStartR4Dev *dev){
    /* The caller supplies canonical current record defaults. C's public
     * R4XSTART_*_VERSION constants describe minimum query prefixes. */
    uint32_t sys_version=sys->abi_version,net_version=net->abi_version,desk_version=desk->abi_version,dev_version=dev->abi_version;
    R4App ignored;init_app(&ignored,sys,net);reply_mode=MODE_OK;open_handles=0;endpoint_registered=0;queued=yielded=stopping=reply_cancelled=io_live=serial_live=serial_closing=0;
    sys->abi_version=sys_version;net->abi_version=net_version;
    sys->ticks=(uintptr_t)&ticks;sys->time_state=(uintptr_t)&time_state;sys->program_should_close=(uintptr_t)&should_close;sys->task_yield=(uintptr_t)&task_yield;
    sys->service_endpoint_wait=(uintptr_t)&endpoint_wait;sys->service_endpoint_poll=(uintptr_t)&endpoint_poll;sys->service_endpoint_recv=(uintptr_t)&endpoint_recv;sys->service_endpoint_reply=(uintptr_t)&endpoint_reply;
    sys->io_service_call=(uintptr_t)&io_begin;sys->io_status=(uintptr_t)&io_status;sys->io_wait=(uintptr_t)&io_wait;sys->io_close=(uintptr_t)&io_close;
    *desk=(R4XStartR4Desk){.magic=R4XSTART_R4DESK_MAGIC,.abi_version=desk_version,.size=sizeof(*desk)};
    *dev=(R4XStartR4Dev){.magic=R4XSTART_R4DEV_MAGIC,.abi_version=dev_version,.size=sizeof(*dev),.serial_count=(uintptr_t)&port_count,.serial_port_at=(uintptr_t)&port_at,.serial_open=(uintptr_t)&port_open,.serial_configure=(uintptr_t)&port_configure,.serial_read=(uintptr_t)&port_read,.serial_write=(uintptr_t)&port_write,.serial_drain=(uintptr_t)&port_drain,.serial_status=(uintptr_t)&port_status,.serial_cancel=(uintptr_t)&port_cancel,.serial_close=(uintptr_t)&port_close};
}
int sdk_service_extra_c_case(void){
    R4NetServiceTcpResult tcp={.flags=R4OS_NET_SERVICE_STATUS_WOULD_BLOCK<<R4OS_NET_SERVICE_STATUS_SHIFT};
    if(r4_net_classify_tcp(&tcp,3).kind!=R4_NET_RESULT_WOULD_BLOCK)return 1;
    R4NetServiceUdpResult udp={.flags=R4OS_NET_SERVICE_STATUS_TIMEOUT<<R4OS_NET_SERVICE_STATUS_SHIFT};
    if(r4_net_classify_udp(&udp,3).kind!=R4_NET_RESULT_TIMED_OUT)return 2;
    uint64_t n=99;if(r4_remaining_ticks((R4Deadline){5},(R4MonotonicInstant){5},0,&n)!=0||n!=0)return 3;
    R4App app;R4XStartR4Sys sys;R4XStartR4Net net;init_app(&app,&sys,&net);
    R4Services services=r4_app_services(&app);sys.size=offsetof(R4XStartR4Sys,service_open);R4ServiceConnection connection;
    if(r4_services_available(&services)||r4_services_open(&services,"EXAMPLE",&connection)!=R4OS_ERR_NO_FN)return 4;
    R4XStartContext ctx={.instance_id=42};app.context=&ctx;sys.size=offsetof(R4XStartR4Sys,program_open_handle);sys.program_open_handle=(uintptr_t)&forbidden_open;
    R4Tray tray;forbidden_calls=0;if(r4_app_tray(&app,&tray)!=R4OS_ERR_NO_FN||forbidden_calls)return 5;
    return 0;
}
