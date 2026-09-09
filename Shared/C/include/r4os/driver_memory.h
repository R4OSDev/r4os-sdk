#ifndef R4OS_DRIVER_MEMORY_H
#define R4OS_DRIVER_MEMORY_H
#include "r4draw.h"

/* Obtained by the R4D v25 gfx_memory_query tail. Calls require the current
 * driver callback context. No global CPU pointer is a DMA or GPU address. */

static inline int32_t r4driver_memory_buffer_create(const R4GfxDriverMemoryApi *table, const R4GfxBufferDescriptor * input, R4GfxBufferReference * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, buffer_create) + sizeof(uint64_t) || table->buffer_create == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxBufferDescriptor *, R4GfxBufferReference *);
    return ((Callback)(uintptr_t)table->buffer_create)(input, output);
}

static inline int32_t r4driver_memory_buffer_describe(const R4GfxDriverMemoryApi *table, const R4GfxBufferHandle * input, R4GfxBufferDescriptor * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, buffer_describe) + sizeof(uint64_t) || table->buffer_describe == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxBufferHandle *, R4GfxBufferDescriptor *);
    return ((Callback)(uintptr_t)table->buffer_describe)(input, output);
}

static inline int32_t r4driver_memory_buffer_import(const R4GfxDriverMemoryApi *table, const R4GfxBufferHandle * input, R4GfxBufferReference * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, buffer_import) + sizeof(uint64_t) || table->buffer_import == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxBufferHandle *, R4GfxBufferReference *);
    return ((Callback)(uintptr_t)table->buffer_import)(input, output);
}

static inline int32_t r4driver_memory_buffer_release(const R4GfxDriverMemoryApi *table, const R4GfxBufferHandle * input) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, buffer_release) + sizeof(uint64_t) || table->buffer_release == 0) return R4OS_ERR_NO_FN;
    typedef int32_t (*Callback)(const R4GfxBufferHandle *);
    return ((Callback)(uintptr_t)table->buffer_release)(input);
}

static inline int32_t r4driver_memory_buffer_map(const R4GfxDriverMemoryApi *table, const R4GfxBufferHandle * input, uint32_t access, uint64_t offset, uint64_t bytes, R4GfxBufferMap * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, buffer_map) + sizeof(uint64_t) || table->buffer_map == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxBufferHandle *, uint32_t, uint64_t, uint64_t, R4GfxBufferMap *);
    return ((Callback)(uintptr_t)table->buffer_map)(input, access, offset, bytes, output);
}

static inline int32_t r4driver_memory_buffer_unmap(const R4GfxDriverMemoryApi *table, const R4GfxBufferHandle * input) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, buffer_unmap) + sizeof(uint64_t) || table->buffer_unmap == 0) return R4OS_ERR_NO_FN;
    typedef int32_t (*Callback)(const R4GfxBufferHandle *);
    return ((Callback)(uintptr_t)table->buffer_unmap)(input);
}

static inline int32_t r4driver_memory_device_acquire(const R4GfxDriverMemoryApi *table, const R4GfxBufferHandle * reference, const R4GfxDeviceRequest * request, R4GfxDeviceLease * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, device_acquire) + sizeof(uint64_t) || table->device_acquire == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxBufferHandle *, const R4GfxDeviceRequest *, R4GfxDeviceLease *);
    return ((Callback)(uintptr_t)table->device_acquire)(reference, request, output);
}

static inline int32_t r4driver_memory_device_segment(const R4GfxDriverMemoryApi *table, const R4GfxDeviceLease * lease, uint64_t offset, R4GfxDmaSegment * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, device_segment) + sizeof(uint64_t) || table->device_segment == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxDeviceLease *, uint64_t, R4GfxDmaSegment *);
    return ((Callback)(uintptr_t)table->device_segment)(lease, offset, output);
}

static inline int32_t r4driver_memory_device_release(const R4GfxDriverMemoryApi *table, const R4GfxDeviceLease * lease, uint32_t quiesced) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, device_release) + sizeof(uint64_t) || table->device_release == 0) return R4OS_ERR_NO_FN;
    typedef int32_t (*Callback)(const R4GfxDeviceLease *, uint32_t);
    return ((Callback)(uintptr_t)table->device_release)(lease, quiesced);
}

static inline int32_t r4driver_memory_mmio_map(const R4GfxDriverMemoryApi *table, const R4GfxMmioRequest * request, R4GfxMmioWindow * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, mmio_map) + sizeof(uint64_t) || table->mmio_map == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxMmioRequest *, R4GfxMmioWindow *);
    return ((Callback)(uintptr_t)table->mmio_map)(request, output);
}

static inline int32_t r4driver_memory_mmio_unmap(const R4GfxDriverMemoryApi *table, const R4GfxBufferHandle * window, uint32_t quiesced) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, mmio_unmap) + sizeof(uint64_t) || table->mmio_unmap == 0) return R4OS_ERR_NO_FN;
    typedef int32_t (*Callback)(const R4GfxBufferHandle *, uint32_t);
    return ((Callback)(uintptr_t)table->mmio_unmap)(window, quiesced);
}

static inline int32_t r4driver_memory_collect(const R4GfxDriverMemoryApi *table) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, collect) + sizeof(uint64_t) || table->collect == 0) return R4OS_ERR_NO_FN;
    typedef int32_t (*Callback)(void);
    return ((Callback)(uintptr_t)table->collect)();
}

static inline int32_t r4driver_memory_buffer_stats(const R4GfxDriverMemoryApi *table, R4GfxBufferStats * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverMemoryApi, buffer_stats) + sizeof(uint64_t) || table->buffer_stats == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(R4GfxBufferStats *);
    return ((Callback)(uintptr_t)table->buffer_stats)(output);
}

#endif

