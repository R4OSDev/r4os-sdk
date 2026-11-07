#ifndef R4OS_PLATFORM2_H
#define R4OS_PLATFORM2_H
/* Explicit generation-2 view. Include both Contract include directories.
 * The caller retains the start record and every declared table prefix. */
#include <r4os/generation2.h>

typedef enum {
    R4OS2_CONTEXT_OK = 0,
    R4OS2_CONTEXT_INVALID = 1,
    R4OS2_CONTEXT_IMPORTS = 2,
    R4OS2_CONTEXT_MIXED = 3,
    R4OS2_CONTEXT_DUPLICATE = 4,
    R4OS2_CONTEXT_NO_SYSTEM = 5,
    R4OS2_CONTEXT_TABLE = 6
} R4OS2ContextResult;
typedef struct {
    const R4XStartContext2 *raw;
    uint64_t tables[6];
} R4OS2Context;
static inline const void *R4OS2ContextGroup(const R4OS2Context *context, uint32_t group) {
    static const uint32_t magic[6] = {R4OS2_R4SYS_MAGIC, R4OS2_R4DESK_MAGIC,
        R4OS2_R4DRAW_MAGIC, R4OS2_R4NET_MAGIC, R4OS2_R4AUDIO_MAGIC, R4OS2_R4DEV_MAGIC};
    if (!context || !group || group > 6) return NULL;
    uint64_t address = context->tables[group - 1];
    if (!address || address % 8) return NULL;
    const uint32_t *header = (const uint32_t *)(uintptr_t)address;
    if (header[0] != magic[group - 1] || header[1] < 1 || header[2] < 16) return NULL;
    return header;
}
static inline R4OS2ContextResult R4OS2ContextInit(const R4XStartContext2 *raw, R4OS2Context *out) {
    if (!out || !raw || raw->magic != R4OS2_START_MAGIC || raw->abi_major != 2 || raw->size < sizeof(*raw)) return R4OS2_CONTEXT_INVALID;
    if (raw->import_count > 32 || (raw->import_count && (!raw->imports || raw->imports % _Alignof(R4XStartImport)))) return R4OS2_CONTEXT_IMPORTS;
    R4OS2Context result = {.raw = raw, .tables = {0}};
    uint32_t seen = 0;
    const R4XStartImport *imports = (const R4XStartImport *)(uintptr_t)raw->imports;
    for (uint32_t i = 0; i < raw->import_count; ++i) {
        const R4XStartImport *item = &imports[i];
        if (!item->group_id) continue;
        if (item->group_id > 6) return R4OS2_CONTEXT_IMPORTS;
        if (item->resolved_version != 2) return R4OS2_CONTEXT_MIXED;
        uint32_t bit = UINT32_C(1) << (item->group_id - 1);
        if (seen & bit) return R4OS2_CONTEXT_DUPLICATE;
        seen |= bit;
        result.tables[item->group_id - 1] = item->table;
    }
    if (!result.tables[0]) return R4OS2_CONTEXT_NO_SYSTEM;
    if (!R4OS2ContextGroup(&result, 1)) return R4OS2_CONTEXT_TABLE;
    *out = result;
    return R4OS2_CONTEXT_OK;
}
/* On failure the address is unchanged. The Contract supplies offset/type. */
static inline int32_t R4OS2ContextFunction(const R4OS2Context *context, uint32_t group, uint32_t offset, uint64_t *out) {
    const uint32_t *table = R4OS2ContextGroup(context, group);
    if (!table) return R4OS_ERR_NO_GROUP;
    if (!out || offset < 16 || offset % 8 || (uint64_t)offset + 8 > table[2]) return R4OS_ERR_NO_FN;
    uintptr_t address = (uintptr_t)table;
    if (address > UINTPTR_MAX - offset) return R4OS_ERR_NO_FN;
    uint64_t slot = *(const uint64_t *)(address + offset);
    if (!slot) return R4OS_ERR_NO_FN;
    *out = slot;
    return 0;
}
#endif
