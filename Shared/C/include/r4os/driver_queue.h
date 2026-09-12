#ifndef R4OS_DRIVER_QUEUE_H
#define R4OS_DRIVER_QUEUE_H
#include "r4draw.h"

/* Native callbacks require the actual bound R4D work/IRQ owner. */

static inline int32_t r4driver_queue_register_backend(const R4GfxDriverQueueApi *table, const R4GfxBackendRegistration * input, R4GfxBackendBinding * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, register_backend) + sizeof(uint64_t) || table->register_backend == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxBackendRegistration *, R4GfxBackendBinding *);
    return ((Callback)(uintptr_t)table->register_backend)(input, output);
}

static inline int32_t r4driver_queue_unregister_backend(const R4GfxDriverQueueApi *table, const R4GfxBackendBinding * input, uint32_t quiesced) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, unregister_backend) + sizeof(uint64_t) || table->unregister_backend == 0) return R4OS_ERR_NO_FN;
    typedef int32_t (*Callback)(const R4GfxBackendBinding *, uint32_t);
    return ((Callback)(uintptr_t)table->unregister_backend)(input, quiesced);
}

static inline int32_t r4driver_queue_take(const R4GfxDriverQueueApi *table, const R4GfxBackendBinding * input, R4GfxDriverJob * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, take) + sizeof(uint64_t) || table->take == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxBackendBinding *, R4GfxDriverJob *);
    return ((Callback)(uintptr_t)table->take)(input, output);
}

static inline int32_t r4driver_queue_complete(const R4GfxDriverQueueApi *table, const R4GfxFence * input, uint32_t result, uint32_t quiesced) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, complete) + sizeof(uint64_t) || table->complete == 0) return R4OS_ERR_NO_FN;
    typedef int32_t (*Callback)(const R4GfxFence *, uint32_t, uint32_t);
    return ((Callback)(uintptr_t)table->complete)(input, result, quiesced);
}

static inline int32_t r4driver_queue_reset(const R4GfxDriverQueueApi *table, const R4GfxBackendBinding * input, uint32_t quiesced, R4GfxBackendBinding * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, reset) + sizeof(uint64_t) || table->reset == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxBackendBinding *, uint32_t, R4GfxBackendBinding *);
    return ((Callback)(uintptr_t)table->reset)(input, quiesced, output);
}

static inline int32_t r4driver_queue_segment(const R4GfxDriverQueueApi *table, const R4GfxFence * input, uint32_t which, uint64_t offset, uint64_t mask, R4GfxDmaSegment * output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, segment) + sizeof(uint64_t) || table->segment == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxFence *, uint32_t, uint64_t, uint64_t, R4GfxDmaSegment *);
    return ((Callback)(uintptr_t)table->segment)(input, which, offset, mask, output);
}

/* Mapping-only reference for source=0 or target=1 of an active native job.
 * Release with driver_memory_buffer_release after confirmed device unmaps.
 * Queue execution ownership and job extents are unchanged. */
static inline int32_t r4driver_queue_retain_resource(const R4GfxDriverQueueApi *table, const R4GfxFence *input, uint32_t which, R4GfxBufferReference *output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, retain_resource) + sizeof(uint64_t) || table->retain_resource == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxFence *, uint32_t, R4GfxBufferReference *);
    return ((Callback)(uintptr_t)table->retain_resource)(input, which, output);
}

#endif
