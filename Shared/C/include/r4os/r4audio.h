#ifndef R4OS_R4AUDIO_H
#define R4OS_R4AUDIO_H

#include "r4l.h"
#include "r4sys.h"

#ifdef __cplusplus
extern "C" {
#endif

/* R4AUDIO is a built-in platform API provided by the kernel. It is resolved
 * as a group_interface import and has no R4L file. The table layout is
 * declared in <r4os/r4xstart.h> (R4XStartR4Audio). */

typedef struct R4Audio {
    const R4XStartR4Audio *table;
} R4Audio;

static inline int32_t r4audio_init(const R4XStartContext *ctx, R4Audio *out) {
    if (out == 0) return R4OS_ERROR_INVALID;
    out->table = 0;
    const R4XStartImport *item = r4xstart_find_import(ctx, R4L_GROUP_R4AUDIO);
    if (item == 0 || item->table == 0) return R4OS_ERROR_NOT_FOUND;
    if ((item->flags & R4XSTART_IMPORT_FLAG_GROUP_INTERFACE) == 0) return R4OS_ERROR_NOT_FOUND;
    const R4XStartR4Audio *table = (const R4XStartR4Audio *)(uintptr_t)item->table;
    if (table->magic != R4XSTART_R4AUDIO_MAGIC) return R4OS_ERROR_INVALID;
    if (table->abi_version < R4XSTART_R4AUDIO_VERSION) return R4OS_ERROR_INVALID;
    if (table->size < R4XSTART_R4AUDIO_SIZE) return R4OS_ERROR_INVALID;
    if (table->audio_open_stream == 0) return R4OS_ERROR_INVALID;
    out->table = table;
    return R4OS_OK;
}

static inline int r4audio_available(const R4Audio *g) {
    return g != 0 && g->table != 0;
}

/* outputs is scratch until result1; initialize receipt.version=1,size=sizeof.
 * The complete capture needs256 rows. Existing scalar enumeration is intact. */
static inline int32_t r4audio_output_catalog(const R4Audio *g,
    R4AudioOutputInfo *outputs, uint32_t capacity, R4AudioOutputCatalog *receipt) {
    if (!r4audio_available(g)) return R4OS_ERR_NO_GROUP;
    if (g->table->size < offsetof(R4XStartR4Audio, audio_output_catalog) + sizeof(uintptr_t)
        || g->table->audio_output_catalog == 0) return R4OS_ERR_NO_FN;
    R4AudioAudioOutputCatalogFn callback = (R4AudioAudioOutputCatalogFn)(uintptr_t)g->table->audio_output_catalog;
    return callback(outputs, capacity, receipt);
}

#ifdef __cplusplus
}
#endif

#endif
