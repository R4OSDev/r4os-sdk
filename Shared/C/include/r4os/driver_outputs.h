#ifndef R4OS_DRIVER_OUTPUTS_H
#define R4OS_DRIVER_OUTPUTS_H
#include "r4draw.h"

static inline int r4driver_output_supports_modes(const R4GfxDriverOutputApi *table) {
    return table != 0 && table->version == 1 && table->size >= offsetof(R4GfxDriverOutputApi, mode_complete) + sizeof(uint64_t) &&
        table->mode_enable != 0 && table->mode_take != 0 && table->mode_complete != 0;
}
static inline int32_t r4driver_output_enable_modes(const R4GfxDriverOutputApi *table, const R4GfxBackendBinding *backend) {
    if (!r4driver_output_supports_modes(table)) return R4OS_ERR_NO_FN;
    if (backend == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    typedef int32_t (*Callback)(const R4GfxBackendBinding *);
    return ((Callback)(uintptr_t)table->mode_enable)(backend);
}
static inline int32_t r4driver_output_take_mode(const R4GfxDriverOutputApi *table, const R4GfxBackendBinding *backend, R4GfxDriverModeJob *output) {
    if (!r4driver_output_supports_modes(table)) return R4OS_ERR_NO_FN;
    if (backend == 0 || output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    typedef int32_t (*Callback)(const R4GfxBackendBinding *, R4GfxDriverModeJob *);
    return ((Callback)(uintptr_t)table->mode_take)(backend, output);
}
static inline int32_t r4driver_output_complete_mode(const R4GfxDriverOutputApi *table, const R4GfxDriverModeCompletion *input) {
    if (!r4driver_output_supports_modes(table)) return R4OS_ERR_NO_FN;
    if (input == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    typedef int32_t (*Callback)(const R4GfxDriverModeCompletion *);
    return ((Callback)(uintptr_t)table->mode_complete)(input);
}

static inline int r4driver_output_supports_receivers(const R4GfxDriverOutputApi *table) {
    return table != 0 && table->version == 1 && table->size >= offsetof(R4GfxDriverOutputApi, close_source) + sizeof(uint64_t) &&
        table->register_source != 0 && table->replace_receivers != 0 && table->close_source != 0;
}
static inline int32_t r4driver_output_register_source(const R4GfxDriverOutputApi *table, uint32_t adapter, R4GfxReceiverSource *output) {
    if (!r4driver_output_supports_receivers(table)) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    typedef int32_t (*Callback)(uint32_t, R4GfxReceiverSource *);
    return ((Callback)(uintptr_t)table->register_source)(adapter, output);
}
static inline int32_t r4driver_output_replace_receivers(const R4GfxDriverOutputApi *table, const R4GfxReceiverUpdate *input) {
    if (!r4driver_output_supports_receivers(table)) return R4OS_ERR_NO_FN;
    if (input == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    typedef int32_t (*Callback)(const R4GfxReceiverUpdate *);
    return ((Callback)(uintptr_t)table->replace_receivers)(input);
}
static inline int32_t r4driver_output_close_source(const R4GfxDriverOutputApi *table, const R4GfxReceiverSource *input) {
    if (!r4driver_output_supports_receivers(table)) return R4OS_ERR_NO_FN;
    if (input == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    typedef int32_t (*Callback)(const R4GfxReceiverSource *);
    return ((Callback)(uintptr_t)table->close_source)(input);
}

static inline int32_t r4driver_output_publish(const R4GfxDriverOutputApi *table, const R4GfxOutputPublication *input, R4GfxOutputId *output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverOutputApi, publish) + sizeof(uint64_t) || table->publish == 0) return R4OS_ERR_NO_FN;
    if (input == 0 || output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    typedef int32_t (*Callback)(const R4GfxOutputPublication *, R4GfxOutputId *);
    return ((Callback)(uintptr_t)table->publish)(input, output);
}
static inline int32_t r4driver_output_withdraw(const R4GfxDriverOutputApi *table, const R4GfxOutputId *input) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4GfxDriverOutputApi, withdraw) + sizeof(uint64_t) || table->withdraw == 0) return R4OS_ERR_NO_FN;
    if (input == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    typedef int32_t (*Callback)(const R4GfxOutputId *);
    return ((Callback)(uintptr_t)table->withdraw)(input);
}
#endif
