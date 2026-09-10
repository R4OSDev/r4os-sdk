#ifndef R4OS_DRIVER_RESOURCES_H
#define R4OS_DRIVER_RESOURCES_H
#include "r4dev.h"

static inline int32_t r4driver_resource_stat(const R4DriverResourceApi *table, const uint8_t *name, uint32_t length, R4DriverResourceInfo *output) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4DriverResourceApi, stat) + sizeof(uint64_t) || table->stat == 0) return R4OS_ERR_NO_FN;
    if (name == 0 || length == 0 || length > 63 || output == 0) return R4OS_DRIVER_RESOURCE_ERROR_INVALID;
    typedef int32_t (*Callback)(const uint8_t *, uint32_t, R4DriverResourceInfo *);
    return ((Callback)(uintptr_t)table->stat)(name, length, output);
}
static inline int32_t r4driver_resource_read_at(const R4DriverResourceApi *table, uint64_t handle, uint64_t offset, uint8_t *output, uint32_t length, uint64_t deadline_ns) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4DriverResourceApi, read_at) + sizeof(uint64_t) || table->read_at == 0) return R4OS_ERR_NO_FN;
    if (output == 0 || length == 0 || length > R4OS_DRIVER_RESOURCE_MAX_READ_BYTES) return R4OS_DRIVER_RESOURCE_ERROR_INVALID;
    typedef int32_t (*Callback)(uint64_t, uint64_t, uint8_t *, uint32_t, uint64_t);
    return ((Callback)(uintptr_t)table->read_at)(handle, offset, output, length, deadline_ns);
}
static inline uint64_t r4driver_resource_now_ns(const R4DriverResourceApi *table) {
    if (table == 0 || table->version != 1 || table->size < offsetof(R4DriverResourceApi, now_ns) + sizeof(uint64_t) || table->now_ns == 0) return UINT64_MAX;
    typedef uint64_t (*Callback)(void);
    return ((Callback)(uintptr_t)table->now_ns)();
}
#endif
