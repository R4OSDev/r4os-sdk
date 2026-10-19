#ifndef R4OS_DRIVER_CPU_POWER_H
#define R4OS_DRIVER_CPU_POWER_H
#include "r4dev.h"

#define R4_CPU_POWER_HAS(t, field) ((t) && (t)->version == 1 && (t)->size >= offsetof(R4DriverCpuPowerApi, field) + sizeof(uint64_t) && (t)->field)
static inline int32_t r4driver_cpu_power_register(const R4DriverCpuPowerApi *t, const R4CpuPowerBackend *backend, uint64_t *cookie) {
    if (!R4_CPU_POWER_HAS(t, register_backend)) return R4OS_ERR_NO_FN;
    typedef int32_t (*Fn)(const R4CpuPowerBackend *, uint64_t *);
    return ((Fn)(uintptr_t)t->register_backend)(backend, cookie);
}
static inline int32_t r4driver_cpu_power_unregister(const R4DriverCpuPowerApi *t, uint64_t cookie) {
    if (!R4_CPU_POWER_HAS(t, unregister_backend)) return R4OS_ERR_NO_FN;
    typedef int32_t (*Fn)(uint64_t);
    return ((Fn)(uintptr_t)t->unregister_backend)(cookie);
}
static inline uint32_t r4driver_cpu_power_current(const R4DriverCpuPowerApi *t) {
    if (!R4_CPU_POWER_HAS(t, current_cpu)) return R4OS_CPU_POWER_CPU_NONE;
    typedef uint32_t (*Fn)(void);
    return ((Fn)(uintptr_t)t->current_cpu)();
}
static inline int32_t r4driver_cpu_power_capabilities(const R4DriverCpuPowerApi *t, uint32_t cpu, R4CpuCapabilitiesInfo *out) {
    if (!R4_CPU_POWER_HAS(t, capabilities)) return R4OS_ERR_NO_FN;
    typedef int32_t (*Fn)(uint32_t, R4CpuCapabilitiesInfo *);
    return ((Fn)(uintptr_t)t->capabilities)(cpu, out);
}
static inline int32_t r4driver_cpu_power_topology(const R4DriverCpuPowerApi *t, uint32_t cpu, R4CpuTopologyInfo *out) {
    if (!R4_CPU_POWER_HAS(t, topology)) return R4OS_ERR_NO_FN;
    typedef int32_t (*Fn)(uint32_t, R4CpuTopologyInfo *);
    return ((Fn)(uintptr_t)t->topology)(cpu, out);
}
static inline int32_t r4driver_cpu_power_read(const R4DriverCpuPowerApi *t, uint32_t cpu, uint64_t epoch, uint32_t id, R4CpuRegisterInfo *out) {
    if (!R4_CPU_POWER_HAS(t, register_read)) return R4OS_ERR_NO_FN;
    typedef int32_t (*Fn)(uint32_t, uint64_t, uint32_t, R4CpuRegisterInfo *);
    return ((Fn)(uintptr_t)t->register_read)(cpu, epoch, id, out);
}
static inline int32_t r4driver_cpu_power_clock(const R4DriverCpuPowerApi *t, R4MonotonicClockInfo *out) {
    if (!R4_CPU_POWER_HAS(t, clock)) return R4OS_ERR_NO_FN;
    typedef int32_t (*Fn)(R4MonotonicClockInfo *);
    return ((Fn)(uintptr_t)t->clock)(out);
}
static inline int32_t r4driver_cpu_power_counters(const R4DriverCpuPowerApi *t, uint32_t cpu, uint64_t epoch, R4CpuPowerCounters *out) {
    if (!R4_CPU_POWER_HAS(t, counters_read)) return R4OS_ERR_NO_FN;
    typedef int32_t (*Fn)(uint32_t, uint64_t, R4CpuPowerCounters *);
    return ((Fn)(uintptr_t)t->counters_read)(cpu, epoch, out);
}
#undef R4_CPU_POWER_HAS
#endif
