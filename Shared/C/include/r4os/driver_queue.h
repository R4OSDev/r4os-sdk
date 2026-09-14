#ifndef R4OS_DRIVER_QUEUE_H
#define R4OS_DRIVER_QUEUE_H
#include "r4draw.h"

/* Native callbacks require the actual bound R4D work/IRQ owner. */

static inline int r4driver_queue_supports_scanout(const R4GfxDriverQueueApi *table) {
    return table && table->version == 1 && table->size >= offsetof(R4GfxDriverQueueApi, scanout_retire_requested) + 8 &&
        table->retain_scanout && table->begin_scanout && table->scanout_retire_requested;
}
static inline int32_t r4driver_queue_retain_scanout(const R4GfxDriverQueueApi *table, const R4GfxFence *fence, R4GfxBufferReference *output) {
    if (!r4driver_queue_supports_scanout(table)) return R4OS_ERR_NO_FN;
    if (!fence || !output) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    return ((int32_t (*)(const R4GfxFence *, R4GfxBufferReference *))(uintptr_t)table->retain_scanout)(fence, output);
}
static inline int32_t r4driver_queue_begin_scanout(const R4GfxDriverQueueApi *table, const R4GfxFence *fence) {
    if (!r4driver_queue_supports_scanout(table)) return R4OS_ERR_NO_FN;
    if (!fence) return R4OS_GFX_QUEUE_ERROR_INVALID;
    return ((int32_t (*)(const R4GfxFence *))(uintptr_t)table->begin_scanout)(fence);
}
static inline int32_t r4driver_queue_scanout_retire_requested(const R4GfxDriverQueueApi *table, const R4GfxFence *fence) {
    if (!r4driver_queue_supports_scanout(table)) return R4OS_ERR_NO_FN;
    if (!fence) return R4OS_GFX_QUEUE_ERROR_INVALID;
    return ((int32_t (*)(const R4GfxFence *))(uintptr_t)table->scanout_retire_requested)(fence);
}

static inline int32_t r4driver_queue_read_render_list(const R4GfxDriverQueueApi *table, const R4GfxFence *fence, R4GfxRenderList *output) {
    if (!table || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, read_render_list) + sizeof(uint64_t) || !table->read_render_list) return R4OS_ERR_NO_FN;
    if (!fence || !output) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    return ((int32_t (*)(const R4GfxFence *, R4GfxRenderList *))(uintptr_t)table->read_render_list)(fence, output);
}
static inline int32_t r4driver_queue_read_render_grid_list(const R4GfxDriverQueueApi *table, const R4GfxFence *fence, R4GfxRenderGridList *output) {
    if (!table || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, read_render_grid_list) + sizeof(uint64_t) || !table->read_render_grid_list) return R4OS_ERR_NO_FN;
    if (!fence || !output) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    return ((int32_t (*)(const R4GfxFence *, R4GfxRenderGridList *))(uintptr_t)table->read_render_grid_list)(fence, output);
}
static inline int32_t r4driver_queue_read_render_color_list(const R4GfxDriverQueueApi *table, const R4GfxFence *fence, R4GfxRenderColorList *output) {
    if (!table || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, read_render_color_list) + sizeof(uint64_t) || !table->read_render_color_list) return R4OS_ERR_NO_FN;
    if (!fence || !output) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    return ((int32_t (*)(const R4GfxFence *, R4GfxRenderColorList *))(uintptr_t)table->read_render_color_list)(fence, output);
}

static inline int32_t r4driver_queue_update_operations(const R4GfxDriverQueueApi *table, const R4GfxBackendBinding *input, uint64_t operations) {
    if (!table || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, update_operations) + 8 || !table->update_operations) return R4OS_ERR_NO_FN;
    return ((int32_t (*)(const R4GfxBackendBinding *, uint64_t))(uintptr_t)table->update_operations)(input, operations);
}
static inline int32_t r4driver_queue_register_profile(const R4GfxDriverQueueApi *table, const R4GfxBackendRegistration *input, const R4GfxBackendProfile *profile, R4GfxBackendBinding *output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverQueueApi, register_profile) + sizeof(uint64_t) || table->register_profile == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    typedef int32_t (*Callback)(const R4GfxBackendRegistration *, const R4GfxBackendProfile *, R4GfxBackendBinding *);
    return ((Callback)(uintptr_t)table->register_profile)(input, profile, output);
}

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
