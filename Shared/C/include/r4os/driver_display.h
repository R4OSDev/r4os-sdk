#ifndef R4OS_DRIVER_DISPLAY_H
#define R4OS_DRIVER_DISPLAY_H
#include "r4draw.h"

static inline int32_t r4driver_display_boot_info(const R4GfxDriverDisplayApi *table, R4GfxNativeBootInfo *output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverDisplayApi, boot_info) + sizeof(uint64_t) || table->boot_info == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    typedef int32_t (*Callback)(R4GfxNativeBootInfo *);
    return ((Callback)(uintptr_t)table->boot_info)(output);
}
static inline int32_t r4driver_display_prepare(const R4GfxDriverDisplayApi *table, const R4GfxNativeRegistration *input, R4GfxNativeState *output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverDisplayApi, prepare) + sizeof(uint64_t) || table->prepare == 0) return R4OS_ERR_NO_FN;
    if (input == 0 || output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    typedef int32_t (*Callback)(const R4GfxNativeRegistration *, R4GfxNativeState *);
    return ((Callback)(uintptr_t)table->prepare)(input, output);
}
static inline int32_t r4driver_display_transition(const R4GfxDriverDisplayApi *table, uint64_t generation, uint32_t operation, R4GfxNativeState *output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverDisplayApi, transition) + sizeof(uint64_t) || table->transition == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    typedef int32_t (*Callback)(uint64_t, uint32_t, R4GfxNativeState *);
    return ((Callback)(uintptr_t)table->transition)(generation, operation, output);
}
static inline int32_t r4driver_display_schedule(const R4GfxDriverDisplayApi *table, const R4GfxBackendBinding *input) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverDisplayApi, schedule) + sizeof(uint64_t) || table->schedule == 0) return R4OS_ERR_NO_FN;
    if (input == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    typedef int32_t (*Callback)(const R4GfxBackendBinding *);
    return ((Callback)(uintptr_t)table->schedule)(input);
}
#endif
