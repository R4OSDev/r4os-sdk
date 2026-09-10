#ifndef R4OS_DRIVER_OUTPUTS_H
#define R4OS_DRIVER_OUTPUTS_H
#include "r4draw.h"

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
