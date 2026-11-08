#ifndef R4OS_TECHNICAL2_H
#define R4OS_TECHNICAL2_H
#include <r4os/generation2.h>
#include <r4os/poll_budget.h>

/* Borrows of the exact immutable loader tables. Caller scope and actual
 * callback/DMA quiescence remain with the original R4D or R4P owner. */
typedef struct { const R4DriverApi2 *api; } R4OS2Driver;
typedef struct { const R4ProtocolApi2 *api; } R4OS2Protocol;
static inline int32_t R4OS2DriverInit(const R4DriverApi2 *api, R4OS2Driver *out) {
    if (!api || !out || ((uintptr_t)api & 7u) || api->magic != R4OS_DRIVER_API2_MAGIC || api->version < R4OS_DRIVER_API2_VERSION || api->size < sizeof(*api) || api->reserved) return -1;
    *out = (R4OS2Driver){api}; return 0;
}
static inline int32_t R4OS2ProtocolInit(const R4ProtocolApi2 *api, R4OS2Protocol *out) {
    if (!api || !out || ((uintptr_t)api & 7u) || api->magic != R4OS_PROTOCOL_API2_MAGIC || api->version < R4OS_PROTOCOL_API2_VERSION || api->size < sizeof(*api) || api->reserved) return -1;
    *out = (R4OS2Protocol){api}; return 0;
}
/* Descriptor/callback backing stays resident even after partial registration
 * failure, until genuine unregister/terminal cleanup acknowledges retirement. */
static inline int32_t R4OS2DriverRegisterAudio(const R4OS2Driver *driver, const uint8_t *name, const R4AudioBackend2 *backend) {
    return driver && driver->api ? driver->api->register_audio_output_backend(name, backend) : -1;
}
static inline int32_t R4OS2DriverClockSample(const R4OS2Driver *driver, R4SdkClockSample *out) {
    if (!driver || !driver->api || !driver->api->monotonic_clock) return R4_BUDGET_CLOCK_UNAVAILABLE;
    R4MonotonicClockInfo info = {0};
    if (driver->api->monotonic_clock(&info) <= 0) return R4_BUDGET_CLOCK_UNAVAILABLE;
    return R4SdkClockSampleRead(&info,out);
}
#define R4OS_DRIVER_ENTRY2(init, shutdown) \
    __attribute__((section(".text.r4d_entries"),used)) int32_t DriverInit2(const R4DriverApi2 *api) { return (init)(api); } \
    __attribute__((section(".text.r4d_entries"),used)) int32_t DriverShutdown(void) { return (shutdown)(); }
#define R4OS_PROTOCOL_ENTRY2(init, shutdown, query, dispatch) \
    __attribute__((section(".text.r4p_entries"),used)) int32_t ProtocolInit2(const R4ProtocolApi2 *api) { return (init)(api); } \
    __attribute__((section(".text.r4p_entries"),used)) int32_t ProtocolShutdown(void) { return (shutdown)(); } \
    __attribute__((section(".text.r4p_entries"),used)) int32_t ProtocolQuery(R4ProtocolStatus *out) { return (query)(out); } \
    __attribute__((section(".text.r4p_entries"),used)) int32_t ProtocolDispatch(uint32_t op, const R4ProtocolBuffer *input, R4ProtocolBuffer *out) { return (dispatch)(op, input, out); }
#endif
