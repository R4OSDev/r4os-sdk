#ifndef R4OS_APP2_H
#define R4OS_APP2_H
#include <r4os/platform2.h>

/* SDK-private callback input to the existing module heap. This is not a
 * platform table or another allocator. Bind2 copies it into module storage. */
typedef struct {
    uint32_t version, size, generation, flags;
    uint64_t identity;
    uint64_t vm_reserve, vm_commit, vm_decommit, vm_release;
    uint64_t notification_create, notification_query, notification_notify;
    uint64_t notification_wait, notification_close;
    uint64_t sleep_ticks, task_yield, thread_current_handle, program_exit;
} R4App2Memory;
typedef struct {
    const char *module_name, *symbol_name;
    uint32_t minimum, optional, group_id, reserved;
} R4App2Import;
typedef struct {
    uint32_t profile, app_class, required_groups, import_count;
    const R4App2Import *imports;
} R4App2StartupInfo;
typedef struct {
    R4OS2Context context;
    R4App2Memory memory;
    uint32_t profile;
} R4App2;
_Static_assert(sizeof(R4App2Memory) == 128, "SDK heap input2");
_Static_assert(sizeof(R4App2Import) == 32 && sizeof(R4App2StartupInfo) == 24, "SDK startup2 facts");

int32_t R4SdkApp2Init(const R4XStartContext2 *, const R4App2StartupInfo *, R4App2Memory *);
int32_t R4SdkHeapBind2(const R4App2Memory *, uint64_t);
void *R4SdkHeapAlloc2(const R4App2Memory *, uint64_t, size_t, size_t);
void *R4SdkHeapRealloc2(const R4App2Memory *, uint64_t, void *, size_t, size_t);
int32_t R4SdkHeapFree2(const R4App2Memory *, uint64_t, void *);
int32_t R4SdkHeapStats2(const R4App2Memory *, uint64_t, uint64_t *, uint32_t);
int32_t R4SdkHeapFinish2(const R4App2Memory *, uint64_t);

static inline int32_t r4_app2_init(const R4XStartContext2 *raw, const R4App2StartupInfo *info, R4App2 *out) {
    if (!out) return -12;
    R4App2 candidate;
    int32_t rc = R4SdkApp2Init(raw, info, &candidate.memory);
    if (rc < 0) return rc;
    if (R4OS2ContextInit(raw, &candidate.context) != R4OS2_CONTEXT_OK) return -12;
    candidate.profile = info->profile;
    *out = candidate;
    return 0;
}
static inline int32_t r4_app2_function(const R4App2 *app, uint32_t group, uint32_t offset, uint64_t *out) {
    if (!app) return R4OS_ERR_NO_GROUP;
    return R4OS2ContextFunction(&app->context, group, offset, out);
}
static inline int32_t r4_app2_write(const R4App2 *app, const uint8_t *data, uint32_t length) {
    uint64_t address;
    int32_t rc = r4_app2_function(app, 1, offsetof(R4XStartR4Sys2, write), &address);
    return rc < 0 ? rc : ((int32_t (*)(const uint8_t *, uint32_t))(uintptr_t)address)(data, length);
}
static inline const uint8_t *r4_app2_args(const R4App2 *app, uint64_t *length) {
    return app ? R4OS2ContextArgs(&app->context, length) : NULL;
}
static inline uint32_t r4_app2_should_close(const R4App2 *app) {
    return app ? R4OS2ContextShouldClose(&app->context) : 1;
}
static inline uint32_t r4_app2_yield(const R4App2 *app) {
    return app ? R4OS2ContextYield(&app->context) : 0;
}
static inline int32_t r4_app2_heap_bind(const R4App2 *app) {
    return app ? R4SdkHeapBind2(&app->memory, app->context.raw->instance_id) : -1;
}
/* All heap users and callbacks must be quiescent before Finish2. Busy/pending
 * retain the exact ownership and must not be translated into success. */
static inline void *r4_app2_alloc(const R4App2 *app, size_t size, size_t alignment) {
    if (r4_app2_heap_bind(app) != 0) return NULL;
    return R4SdkHeapAlloc2(&app->memory, app->context.raw->instance_id, size, alignment);
}
static inline int32_t r4_app2_free(const R4App2 *app, void *pointer) {
    return app ? R4SdkHeapFree2(&app->memory, app->context.raw->instance_id, pointer) : -1;
}
#endif
