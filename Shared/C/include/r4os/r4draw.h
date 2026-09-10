#ifndef R4OS_R4DRAW_H
#define R4OS_R4DRAW_H

#include "r4l.h"
#include "r4sys.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct R4Draw {
    const R4XStartR4Draw *table;
} R4Draw;

static inline int r4draw_supports_display_blit_stride(const R4Draw *draw) {
    return draw != 0 && draw->table != 0 &&
        draw->table->size >= offsetof(R4XStartR4Draw, display_blit_xrgb32_stride) + sizeof(uintptr_t) &&
        draw->table->display_blit_xrgb32_stride != 0;
}

static inline int32_t r4draw_display_blit_xrgb32_stride(R4Draw *draw,
                                                         int32_t x, int32_t y,
                                                         uint32_t width, uint32_t height,
                                                         uint32_t source_stride_pixels,
                                                         const uint32_t *pixels,
                                                         uint32_t pixel_count) {
    if (!r4draw_supports_display_blit_stride(draw)) return R4OS_ERR_NO_FN;
    if (pixels == 0 || pixel_count == 0u) return R4OS_ERROR_INVALID;
    R4DrawDisplayBlitXrgb32StrideFn fn = (R4DrawDisplayBlitXrgb32StrideFn)(uintptr_t)draw->table->display_blit_xrgb32_stride;
    return fn(x, y, width, height, pixels, pixel_count, source_stride_pixels);
}

static inline int r4draw_supports_display_present_regions(const R4Draw *draw) {
    return draw != 0 && draw->table != 0 &&
        draw->table->size >= offsetof(R4XStartR4Draw, display_present_completion) + sizeof(uintptr_t) &&
        draw->table->display_present_regions != 0 &&
        draw->table->display_present_capabilities != 0 &&
        draw->table->display_present_completion != 0;
}

static inline int32_t r4draw_display_present_regions(R4Draw *draw,
                                                      const R4DisplayPresentRequest *request,
                                                      const uint32_t *pixels,
                                                      uint32_t pixel_count,
                                                      const R4DisplayDamageRect *regions,
                                                      uint32_t region_count,
                                                      R4DisplayPresentResult *out_result) {
    if (!r4draw_supports_display_present_regions(draw)) return R4OS_ERR_NO_FN;
    if (request == 0 || pixels == 0 || pixel_count == 0u || regions == 0 ||
        region_count == 0u || region_count > R4OS_DISPLAY_DAMAGE_MAX_REGIONS || out_result == 0) {
        return R4OS_DISPLAY_PRESENT_ERROR_INVALID;
    }
    R4DrawDisplayPresentRegionsFn fn =
        (R4DrawDisplayPresentRegionsFn)(uintptr_t)draw->table->display_present_regions;
    return fn(request, pixels, pixel_count, regions, region_count, out_result);
}

static inline int32_t r4draw_display_present_capabilities(R4Draw *draw,
                                                           R4DisplayPresentCapabilities *out_capabilities) {
    if (!r4draw_supports_display_present_regions(draw)) return R4OS_ERR_NO_FN;
    if (out_capabilities == 0) return R4OS_DISPLAY_PRESENT_ERROR_INVALID;
    out_capabilities->version = R4OS_DISPLAY_PRESENT_VERSION;
    out_capabilities->size = (uint16_t)sizeof(*out_capabilities);
    R4DrawDisplayPresentCapabilitiesFn fn =
        (R4DrawDisplayPresentCapabilitiesFn)(uintptr_t)draw->table->display_present_capabilities;
    return fn(out_capabilities);
}

static inline int32_t r4draw_display_present_completion(R4Draw *draw,
                                                         uint64_t fence,
                                                         R4DisplayPresentCompletion *out_completion) {
    if (!r4draw_supports_display_present_regions(draw)) return R4OS_ERR_NO_FN;
    if (fence == 0u || out_completion == 0) return R4OS_DISPLAY_PRESENT_ERROR_INVALID;
    out_completion->version = R4OS_DISPLAY_PRESENT_VERSION;
    out_completion->size = (uint16_t)sizeof(*out_completion);
    R4DrawDisplayPresentCompletionFn fn =
        (R4DrawDisplayPresentCompletionFn)(uintptr_t)draw->table->display_present_completion;
    return fn(fence, out_completion);
}

static inline int r4draw_import_valid(const R4XStartImport *item) {
    return item != 0 &&
        item->group_id == R4L_GROUP_R4DRAW &&
        (item->flags & R4XSTART_IMPORT_FLAG_GROUP_INTERFACE) != 0 &&
        item->table != 0;
}

static inline int32_t r4draw_init(const R4XStartContext *ctx, R4Draw *out_draw) {
    if (out_draw == 0) return R4OS_ERROR_INVALID;
    out_draw->table = 0;
    const R4XStartImport *item = r4xstart_find_import(ctx, R4L_GROUP_R4DRAW);
    if (item == 0) return R4OS_ERROR_NOT_FOUND;
    if (!r4draw_import_valid(item)) return R4OS_ERROR_NOT_FOUND;
    const R4XStartR4Draw *table = (const R4XStartR4Draw *)(uintptr_t)item->table;
    if (table->magic != R4XSTART_R4DRAW_MAGIC) return R4OS_ERROR_INVALID;
    /* Optional append-only tails are checked by their individual facades. */
    if (table->abi_version < 1) return R4OS_ERROR_INVALID;
    if (table->size < offsetof(R4XStartR4Draw, gui_present) + sizeof(uintptr_t)) return R4OS_ERROR_INVALID;
    if (table->gui_clear == 0 || table->gui_rect == 0 || table->gui_present == 0) return R4OS_ERROR_INVALID;
    out_draw->table = table;
    return R4OS_OK;
}

static inline int32_t r4draw_gui_clear(R4Draw *draw, uint32_t rgb) {
    if (draw == 0 || draw->table == 0 || draw->table->gui_clear == 0) return R4OS_ERROR_INVALID;
    R4DrawGuiClearFn fn = (R4DrawGuiClearFn)(uintptr_t)draw->table->gui_clear;
    return fn(rgb);
}

static inline int32_t r4draw_gui_rect(R4Draw *draw, int32_t x, int32_t y, uint32_t w, uint32_t h, uint32_t rgb) {
    if (draw == 0 || draw->table == 0 || draw->table->gui_rect == 0) return R4OS_ERROR_INVALID;
    R4DrawGuiRectFn fn = (R4DrawGuiRectFn)(uintptr_t)draw->table->gui_rect;
    return fn(x, y, w, h, rgb);
}

static inline int32_t r4draw_gui_draw_text(R4Draw *draw, int32_t x, int32_t y, const char *text, uint32_t fg, uint32_t bg) {
    if (draw == 0 || draw->table == 0 || draw->table->gui_draw_text == 0) return R4OS_ERROR_INVALID;
    R4DrawGuiDrawTextFn fn = (R4DrawGuiDrawTextFn)(uintptr_t)draw->table->gui_draw_text;
    return fn(x, y, (const uint8_t *)(const void *)text, fg, bg);
}

static inline int32_t r4draw_gui_blend_alpha8(R4Draw *draw, int32_t x, int32_t y,
                                               uint32_t width, uint32_t height,
                                               uint32_t stride, uint32_t rgb,
                                               const uint8_t *alpha, size_t alpha_len) {
    if (draw == 0 || draw->table == 0 ||
        draw->table->size < offsetof(R4XStartR4Draw, gui_blend_alpha8) + sizeof(uintptr_t) ||
        draw->table->gui_blend_alpha8 == 0) return R4OS_ERR_NO_FN;
    if (alpha == 0 || alpha_len == 0u || alpha_len > UINT32_MAX) return R4OS_ERROR_INVALID;
    R4DrawGuiBlendAlpha8Fn fn = (R4DrawGuiBlendAlpha8Fn)(uintptr_t)draw->table->gui_blend_alpha8;
    return fn(x, y, width, height, stride, rgb, alpha, (uint32_t)alpha_len);
}

static inline int r4draw_supports_gui_frame_contract(const R4Draw *draw) {
    if (draw == 0 || draw->table == 0) return 0;
    const R4XStartR4Draw *table = draw->table;
    return table->size >= offsetof(R4XStartR4Draw, gui_frame_read) + sizeof(uintptr_t) &&
        table->gui_frame_begin != 0 && table->gui_frame_append != 0 &&
        table->gui_frame_commit != 0 && table->gui_frame_cancel != 0 &&
        table->gui_frame_info != 0 && table->gui_frame_read != 0;
}

static inline int r4draw_supports_gui_frame_damage_contract(const R4Draw *draw) {
    if (!r4draw_supports_gui_frame_contract(draw)) return 0;
    const R4XStartR4Draw *table = draw->table;
    return table->size >= offsetof(R4XStartR4Draw, gui_frame_generation_read) + sizeof(uintptr_t) &&
        table->gui_frame_begin_damage != 0 && table->gui_frame_generation_info != 0 &&
        table->gui_frame_generation_read != 0;
}

static inline int r4draw_supports_gui_frame_streaming_contract(const R4Draw *draw) {
    if (!r4draw_supports_gui_frame_damage_contract(draw)) return 0;
    const R4XStartR4Draw *table = draw->table;
    return table->size >= offsetof(R4XStartR4Draw, gui_frame_stream_info) + sizeof(uintptr_t) &&
        table->gui_frame_begin_replace != 0 && table->gui_frame_stream_info != 0;
}

static inline int32_t r4draw_gui_frame_begin(R4Draw *draw) {
    if (draw == 0 || !r4draw_supports_gui_frame_contract(draw)) return R4OS_ERR_NO_FN;
    R4DrawGuiFrameBeginFn fn = (R4DrawGuiFrameBeginFn)(uintptr_t)draw->table->gui_frame_begin;
    return fn();
}

static inline int32_t r4draw_gui_frame_begin_damage(R4Draw *draw,
                                                     const R4DisplayDamageRect *regions,
                                                     uint32_t region_count) {
    if (draw == 0 || !r4draw_supports_gui_frame_damage_contract(draw)) return R4OS_ERR_NO_FN;
    if (regions == 0 || region_count == 0u || region_count > R4OS_GUI_FRAME_MAX_DAMAGE_REGIONS) {
        return R4OS_GUI_FRAME_ERROR_INVALID;
    }
    R4DrawGuiFrameBeginDamageFn fn = (R4DrawGuiFrameBeginDamageFn)(uintptr_t)draw->table->gui_frame_begin_damage;
    return fn(regions, region_count);
}

static inline int32_t r4draw_gui_frame_begin_replace(R4Draw *draw,
                                                      const R4DisplayDamageRect *regions,
                                                      uint32_t region_count) {
    if (draw == 0 || !r4draw_supports_gui_frame_streaming_contract(draw)) return R4OS_ERR_NO_FN;
    if (regions == 0 || region_count == 0u || region_count > R4OS_GUI_FRAME_MAX_DAMAGE_REGIONS) {
        return R4OS_GUI_FRAME_ERROR_INVALID;
    }
    R4DrawGuiFrameBeginReplaceFn fn = (R4DrawGuiFrameBeginReplaceFn)(uintptr_t)draw->table->gui_frame_begin_replace;
    return fn(regions, region_count);
}

static inline int32_t r4draw_gui_frame_append(R4Draw *draw,
                                               const R4GuiFrameCommand *commands, uint64_t command_count,
                                               const uint8_t *resources, uint64_t resource_len) {
    if (draw == 0 || !r4draw_supports_gui_frame_contract(draw)) return R4OS_ERR_NO_FN;
    R4DrawGuiFrameAppendFn fn = (R4DrawGuiFrameAppendFn)(uintptr_t)draw->table->gui_frame_append;
    return fn(commands, command_count, resources, resource_len);
}

static inline int32_t r4draw_gui_frame_commit(R4Draw *draw) {
    if (draw == 0 || !r4draw_supports_gui_frame_contract(draw)) return R4OS_ERR_NO_FN;
    R4DrawGuiFrameCommitFn fn = (R4DrawGuiFrameCommitFn)(uintptr_t)draw->table->gui_frame_commit;
    return fn();
}

static inline int32_t r4draw_gui_frame_cancel(R4Draw *draw) {
    if (draw == 0 || !r4draw_supports_gui_frame_contract(draw)) return R4OS_ERR_NO_FN;
    R4DrawGuiFrameCancelFn fn = (R4DrawGuiFrameCancelFn)(uintptr_t)draw->table->gui_frame_cancel;
    return fn();
}

static inline int32_t r4draw_gui_frame_info(R4Draw *draw, const R4ProgramProcessHandle *handle, R4GuiFrameInfo *out_info) {
    if (draw == 0 || !r4draw_supports_gui_frame_contract(draw)) return R4OS_ERR_NO_FN;
    if (out_info == 0) return R4OS_GUI_FRAME_ERROR_INVALID;
    R4DrawGuiFrameInfoFn fn = (R4DrawGuiFrameInfoFn)(uintptr_t)draw->table->gui_frame_info;
    out_info->version = R4OS_GUI_FRAME_INFO_VERSION;
    out_info->size = R4OS_GUI_FRAME_INFO_SIZE;
    return fn(handle, out_info);
}

static inline int32_t r4draw_gui_frame_read(R4Draw *draw, const R4ProgramProcessHandle *handle,
                                             uint64_t expected_generation,
                                             R4GuiFrameCommand *commands, uint64_t command_capacity,
                                             uint8_t *resources, uint64_t resource_capacity,
                                             R4GuiFrameInfo *out_info) {
    if (draw == 0 || !r4draw_supports_gui_frame_contract(draw)) return R4OS_ERR_NO_FN;
    if (out_info == 0) return R4OS_GUI_FRAME_ERROR_INVALID;
    out_info->version = R4OS_GUI_FRAME_INFO_VERSION;
    out_info->size = R4OS_GUI_FRAME_INFO_SIZE;
    if (handle == 0) return R4OS_GUI_FRAME_ERROR_INVALID;
    R4DrawGuiFrameReadFn fn = (R4DrawGuiFrameReadFn)(uintptr_t)draw->table->gui_frame_read;
    return fn(handle, expected_generation, commands, command_capacity, resources, resource_capacity, out_info);
}

static inline int32_t r4draw_gui_frame_generation_info(R4Draw *draw,
                                                        const R4ProgramProcessHandle *handle,
                                                        uint64_t generation,
                                                        R4GuiFrameGenerationInfo *out_info) {
    if (draw == 0 || !r4draw_supports_gui_frame_damage_contract(draw)) return R4OS_ERR_NO_FN;
    if (handle == 0 || generation == 0u || out_info == 0) return R4OS_GUI_FRAME_ERROR_INVALID;
    out_info->version = R4OS_GUI_FRAME_GENERATION_INFO_VERSION;
    out_info->size = R4OS_GUI_FRAME_GENERATION_INFO_SIZE;
    R4DrawGuiFrameGenerationInfoFn fn = (R4DrawGuiFrameGenerationInfoFn)(uintptr_t)draw->table->gui_frame_generation_info;
    return fn(handle, generation, out_info);
}

static inline int32_t r4draw_gui_frame_generation_read(R4Draw *draw,
                                                        const R4ProgramProcessHandle *handle,
                                                        uint64_t generation,
                                                        R4GuiFrameCommand *commands,
                                                        uint64_t command_capacity,
                                                        uint8_t *resources,
                                                        uint64_t resource_capacity,
                                                        R4DisplayDamageRect *regions,
                                                        uint32_t region_capacity,
                                                        R4GuiFrameGenerationInfo *out_info) {
    if (draw == 0 || !r4draw_supports_gui_frame_damage_contract(draw)) return R4OS_ERR_NO_FN;
    if (handle == 0 || generation == 0u || out_info == 0 ||
        (commands == 0 && command_capacity != 0u) || (resources == 0 && resource_capacity != 0u) ||
        (regions == 0 && region_capacity != 0u)) return R4OS_GUI_FRAME_ERROR_INVALID;
    out_info->version = R4OS_GUI_FRAME_GENERATION_INFO_VERSION;
    out_info->size = R4OS_GUI_FRAME_GENERATION_INFO_SIZE;
    R4DrawGuiFrameGenerationReadFn fn = (R4DrawGuiFrameGenerationReadFn)(uintptr_t)draw->table->gui_frame_generation_read;
    return fn(handle, generation, commands, command_capacity, resources, resource_capacity, regions, region_capacity, out_info);
}

static inline int32_t r4draw_gui_frame_stream_info(R4Draw *draw,
                                                    const R4ProgramProcessHandle *handle,
                                                    R4GuiFrameStreamInfo *out_info) {
    if (draw == 0 || !r4draw_supports_gui_frame_streaming_contract(draw)) return R4OS_ERR_NO_FN;
    if (handle == 0 || out_info == 0) return R4OS_GUI_FRAME_ERROR_INVALID;
    out_info->version = R4OS_GUI_FRAME_STREAM_INFO_VERSION;
    out_info->size = R4OS_GUI_FRAME_STREAM_INFO_SIZE;
    R4DrawGuiFrameStreamInfoFn fn = (R4DrawGuiFrameStreamInfoFn)(uintptr_t)draw->table->gui_frame_stream_info;
    return fn(handle, out_info);
}

static inline int32_t r4draw_gui_present(R4Draw *draw) {
    if (draw == 0 || draw->table == 0 || draw->table->gui_present == 0) return R4OS_ERROR_INVALID;
    R4DrawGuiPresentFn fn = (R4DrawGuiPresentFn)(uintptr_t)draw->table->gui_present;
    return fn();
}


/* Generation-bound graphics buffers. Check each optional tail independently. */
static inline int32_t r4draw_gfx_buffer_create(const R4Draw *draw, const R4GfxBufferDescriptor * descriptor, R4GfxBufferReference * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_buffer_create) + sizeof(uintptr_t) || draw->table->gfx_buffer_create == 0) return R4OS_ERR_NO_FN;
    if (descriptor == 0 || output == 0) return R4OS_GFX_BUFFER_ERROR_INVALID;
    output->version = 1; output->size = sizeof(R4GfxBufferReference);
    return ((R4DrawGfxBufferCreateFn)(uintptr_t)draw->table->gfx_buffer_create)(descriptor, output);
}

static inline int32_t r4draw_gfx_buffer_describe(const R4Draw *draw, const R4GfxBufferHandle * reference, R4GfxBufferDescriptor * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_buffer_describe) + sizeof(uintptr_t) || draw->table->gfx_buffer_describe == 0) return R4OS_ERR_NO_FN;
    if (reference == 0 || output == 0) return R4OS_GFX_BUFFER_ERROR_INVALID;
    output->version = 1; output->size = sizeof(R4GfxBufferDescriptor);
    return ((R4DrawGfxBufferDescribeFn)(uintptr_t)draw->table->gfx_buffer_describe)(reference, output);
}

static inline int32_t r4draw_gfx_buffer_import(const R4Draw *draw, const R4GfxBufferHandle * source_reference, R4GfxBufferReference * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_buffer_import) + sizeof(uintptr_t) || draw->table->gfx_buffer_import == 0) return R4OS_ERR_NO_FN;
    if (source_reference == 0 || output == 0) return R4OS_GFX_BUFFER_ERROR_INVALID;
    output->version = 1; output->size = sizeof(R4GfxBufferReference);
    return ((R4DrawGfxBufferImportFn)(uintptr_t)draw->table->gfx_buffer_import)(source_reference, output);
}

static inline int32_t r4draw_gfx_buffer_release(const R4Draw *draw, const R4GfxBufferHandle * reference) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_buffer_release) + sizeof(uintptr_t) || draw->table->gfx_buffer_release == 0) return R4OS_ERR_NO_FN;
    if (reference == 0) return R4OS_GFX_BUFFER_ERROR_INVALID;
    return ((R4DrawGfxBufferReleaseFn)(uintptr_t)draw->table->gfx_buffer_release)(reference);
}

static inline int32_t r4draw_gfx_buffer_map(const R4Draw *draw, const R4GfxBufferHandle * reference, uint32_t access, uint64_t offset, uint64_t byte_length, R4GfxBufferMap * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_buffer_map) + sizeof(uintptr_t) || draw->table->gfx_buffer_map == 0) return R4OS_ERR_NO_FN;
    if (reference == 0 || output == 0) return R4OS_GFX_BUFFER_ERROR_INVALID;
    output->version = 1; output->size = sizeof(R4GfxBufferMap);
    return ((R4DrawGfxBufferMapFn)(uintptr_t)draw->table->gfx_buffer_map)(reference, access, offset, byte_length, output);
}

static inline int32_t r4draw_gfx_buffer_unmap(const R4Draw *draw, const R4GfxBufferHandle * lease) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_buffer_unmap) + sizeof(uintptr_t) || draw->table->gfx_buffer_unmap == 0) return R4OS_ERR_NO_FN;
    if (lease == 0) return R4OS_GFX_BUFFER_ERROR_INVALID;
    return ((R4DrawGfxBufferUnmapFn)(uintptr_t)draw->table->gfx_buffer_unmap)(lease);
}

static inline int32_t r4draw_gfx_buffer_export_raster(const R4Draw *draw, const R4GuiSharedRasterLease * lease, R4GfxBufferReference * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_buffer_export_raster) + sizeof(uintptr_t) || draw->table->gfx_buffer_export_raster == 0) return R4OS_ERR_NO_FN;
    if (lease == 0 || output == 0) return R4OS_GFX_BUFFER_ERROR_INVALID;
    output->version = 1; output->size = sizeof(R4GfxBufferReference);
    return ((R4DrawGfxBufferExportRasterFn)(uintptr_t)draw->table->gfx_buffer_export_raster)(lease, output);
}

static inline int32_t r4draw_gfx_buffer_stats(const R4Draw *draw, R4GfxBufferStats * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_buffer_stats) + sizeof(uintptr_t) || draw->table->gfx_buffer_stats == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_BUFFER_ERROR_INVALID;
    output->version = 1; output->size = sizeof(R4GfxBufferStats);
    return ((R4DrawGfxBufferStatsFn)(uintptr_t)draw->table->gfx_buffer_stats)(output);
}


/* Asynchronous graphics queues and exact fences. Check each optional tail independently. */
static inline int32_t r4draw_gfx_output_revision(const R4Draw *draw, R4GfxDisplayRevision * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_output_revision) + sizeof(uintptr_t) || draw->table->gfx_output_revision == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    return ((R4DrawGfxOutputRevisionFn)(uintptr_t)draw->table->gfx_output_revision)(output);
}
static inline int32_t r4draw_gfx_output_info(const R4Draw *draw, uint32_t index, R4GfxOutputInfo * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_output_info) + sizeof(uintptr_t) || draw->table->gfx_output_info == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    return ((R4DrawGfxOutputInfoFn)(uintptr_t)draw->table->gfx_output_info)(index, output);
}
static inline int32_t r4draw_gfx_output_mode(const R4Draw *draw, const R4GfxOutputId * identity, uint32_t index, R4GfxOutputMode * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_output_mode) + sizeof(uintptr_t) || draw->table->gfx_output_mode == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    return ((R4DrawGfxOutputModeFn)(uintptr_t)draw->table->gfx_output_mode)(identity, index, output);
}
static inline int32_t r4draw_gfx_output_edid(const R4Draw *draw, const R4GfxOutputId * identity, uint32_t index, R4GfxEdidBlock * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_output_edid) + sizeof(uintptr_t) || draw->table->gfx_output_edid == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    return ((R4DrawGfxOutputEdidFn)(uintptr_t)draw->table->gfx_output_edid)(identity, index, output);
}
static inline int32_t r4draw_gfx_atomic_test(const R4Draw *draw, const R4GfxAtomicState * state, R4GfxAtomicResult * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_atomic_test) + sizeof(uintptr_t) || draw->table->gfx_atomic_test == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    return ((R4DrawGfxAtomicTestFn)(uintptr_t)draw->table->gfx_atomic_test)(state, output);
}
static inline int32_t r4draw_gfx_atomic_commit(const R4Draw *draw, const R4GfxAtomicState * state, R4GfxAtomicResult * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_atomic_commit) + sizeof(uintptr_t) || draw->table->gfx_atomic_commit == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_OUTPUT_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    return ((R4DrawGfxAtomicCommitFn)(uintptr_t)draw->table->gfx_atomic_commit)(state, output);
}

static inline int32_t r4draw_gfx_queue_open(const R4Draw *draw, const R4GfxQueueConfig * config, R4GfxQueueHandle * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_queue_open) + sizeof(uintptr_t) || draw->table->gfx_queue_open == 0) return R4OS_ERR_NO_FN;
    if (config == 0 || output == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(R4GfxQueueHandle);
    return ((R4DrawGfxQueueOpenFn)(uintptr_t)draw->table->gfx_queue_open)(config, output);
}

static inline int32_t r4draw_gfx_queue_backend(const R4Draw *draw, uint32_t index, R4GfxBackendBinding *output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_queue_backend) + sizeof(uintptr_t) || draw->table->gfx_queue_backend == 0) return R4OS_ERR_NO_FN;
    if (output == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(*output);
    return ((R4DrawGfxQueueBackendFn)(uintptr_t)draw->table->gfx_queue_backend)(index, output);
}

static inline int32_t r4draw_gfx_queue_close(const R4Draw *draw, const R4GfxQueueHandle * queue) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_queue_close) + sizeof(uintptr_t) || draw->table->gfx_queue_close == 0) return R4OS_ERR_NO_FN;
    if (queue == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    return ((R4DrawGfxQueueCloseFn)(uintptr_t)draw->table->gfx_queue_close)(queue);
}

static inline int32_t r4draw_gfx_queue_submit(const R4Draw *draw, const R4GfxQueueHandle * queue, const R4GfxSubmission * submission, R4GfxFenceStatus * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_queue_submit) + sizeof(uintptr_t) || draw->table->gfx_queue_submit == 0) return R4OS_ERR_NO_FN;
    if (queue == 0 || submission == 0 || output == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(R4GfxFenceStatus);
    return ((R4DrawGfxQueueSubmitFn)(uintptr_t)draw->table->gfx_queue_submit)(queue, submission, output);
}

static inline int32_t r4draw_gfx_fence_query(const R4Draw *draw, const R4GfxFence * fence, R4GfxFenceStatus * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_fence_query) + sizeof(uintptr_t) || draw->table->gfx_fence_query == 0) return R4OS_ERR_NO_FN;
    if (fence == 0 || output == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(R4GfxFenceStatus);
    return ((R4DrawGfxFenceQueryFn)(uintptr_t)draw->table->gfx_fence_query)(fence, output);
}

static inline int32_t r4draw_gfx_fence_wait(const R4Draw *draw, const R4GfxFence * fence, uint64_t timeout_ticks, uint32_t wait_for, R4GfxFenceStatus * output) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_fence_wait) + sizeof(uintptr_t) || draw->table->gfx_fence_wait == 0) return R4OS_ERR_NO_FN;
    if (fence == 0 || output == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    output->version = 1; output->size = sizeof(R4GfxFenceStatus);
    return ((R4DrawGfxFenceWaitFn)(uintptr_t)draw->table->gfx_fence_wait)(fence, timeout_ticks, wait_for, output);
}

static inline int32_t r4draw_gfx_fence_cancel(const R4Draw *draw, const R4GfxFence * fence) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_fence_cancel) + sizeof(uintptr_t) || draw->table->gfx_fence_cancel == 0) return R4OS_ERR_NO_FN;
    if (fence == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    return ((R4DrawGfxFenceCancelFn)(uintptr_t)draw->table->gfx_fence_cancel)(fence);
}

static inline int32_t r4draw_gfx_fence_release(const R4Draw *draw, const R4GfxFence * fence) {
    if (draw == 0 || draw->table == 0 || draw->table->size < offsetof(R4XStartR4Draw, gfx_fence_release) + sizeof(uintptr_t) || draw->table->gfx_fence_release == 0) return R4OS_ERR_NO_FN;
    if (fence == 0) return R4OS_GFX_QUEUE_ERROR_INVALID;
    return ((R4DrawGfxFenceReleaseFn)(uintptr_t)draw->table->gfx_fence_release)(fence);
}

#ifdef __cplusplus
}
#endif

#endif
