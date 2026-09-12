#include <assert.h>
#include <stdint.h>

#include <r4os/r4os.h>
#include <r4os/driver_memory.h>
#include <r4os/driver_queue.h>
#include <r4os/driver_outputs.h>
#include <r4os/driver_display.h>

_Static_assert(sizeof(R4GfxReceiverSource) == 16, "receiver source layout");
_Static_assert(sizeof(R4GfxReceiverInfo) == 8224 && offsetof(R4GfxReceiverInfo, modes) == 32 && offsetof(R4GfxReceiverInfo, edid) == 4128, "receiver record layout");
_Static_assert(sizeof(R4GfxReceiverUpdate) == 48 && offsetof(R4GfxReceiverUpdate, receivers) == 40, "receiver update layout");
_Static_assert(sizeof(R4GfxDriverOutputApi) == 48 && offsetof(R4GfxDriverOutputApi, register_source) == 24, "legacy output prefix");

static int32_t display_transition_probe(uint64_t generation, uint32_t operation, R4GfxNativeState *output) {
    assert(generation == UINT64_C(0x100000007) && operation == 2);
    output->generation = generation + 1; output->outcome = 3; output->retained = 1; return 1;
}
static int32_t display_schedule_probe(const R4GfxBackendBinding *binding) {
    assert(binding->reset_generation == UINT64_C(0x30000000b)); return -4;
}

static int32_t output_test_probe(const R4GfxAtomicState *state, R4GfxAtomicResult *out) {
    assert(state->topology_revision == UINT64_C(0x100000007) && state->assignments[7].output.connection_generation == UINT64_C(0x200000009));
    assert(out->version == 1 && out->size == sizeof(*out)); out->topology_revision = state->topology_revision; return 1;
}
static int32_t output_publish_probe(const R4GfxOutputPublication *publication, R4GfxOutputId *out) {
    assert(publication->info.edid_bytes == 128 && publication->edid[127] == 0x79);
    out->connection_generation = UINT64_C(0x40000000d); return 1;
}
static int32_t receiver_register_probe(uint32_t adapter, R4GfxReceiverSource *out) {
    assert(adapter == 17); out->adapter_id = adapter; out->generation = UINT64_C(0x100000079); return 1;
}
static int32_t receiver_replace_probe(const R4GfxReceiverUpdate *input) {
    assert(input->source.generation == UINT64_C(0x100000079) && input->sequence == UINT64_C(0x200000001) && input->count == 0 && input->receivers == 0); return -4;
}
static int32_t receiver_close_probe(const R4GfxReceiverSource *input) {
    assert(input->generation == UINT64_C(0x100000079)); return 1;
}

static int32_t gfx_wait_probe(const R4GfxFence *fence, uint64_t ticks, uint32_t wait_for, R4GfxFenceStatus *out) {
    assert(fence->point == UINT64_C(0x100000007) && fence->reset_generation == UINT64_C(0x200000001));
    assert(ticks == UINT64_C(0x300000003) && wait_for == 1 && out->version == 1 && out->size == 80);
    out->fence = *fence;
    return 1;
}
static int32_t gfx_complete_probe(const R4GfxFence *fence, uint32_t result, uint32_t quiesced) {
    assert(fence->point == UINT64_C(0x100000007) && result == 6 && quiesced == 0);
    return -4;
}
static int32_t gfx_retain_probe(const R4GfxFence *fence, uint32_t which, R4GfxBufferReference *out) {
    assert(fence->point == UINT64_C(0x100000007) && fence->reset_generation == UINT64_C(0x200000001) && which == 1);
    assert(out->version == 1 && out->size == 48);
    out->reference.generation = UINT64_C(0x400000009);
    out->flags = R4OS_GFX_BUFFER_REFERENCE_MAPPING_ONLY;
    return 1;
}

static int32_t gfx_map_probe(const R4GfxBufferHandle *ref, uint32_t access, uint64_t offset, uint64_t bytes, R4GfxBufferMap *out) {
    assert(ref->generation == 99 && access == 1 && offset == UINT64_C(0x100000003) && bytes == UINT64_C(0x200000000));
    assert(out->version == 1 && out->size == sizeof(*out));
    out->byte_length = bytes;
    return 1;
}
_Static_assert(sizeof(R4GfxOwnedBufferReservation)==88 && sizeof(R4GfxOwnedBufferRelease)==80 && offsetof(R4GfxDriverMemoryApi,buffer_reserve)==112 && sizeof(R4GfxDriverMemoryApi)==152, "owned BO ABI");
static int32_t owned_reserve(const R4GfxBufferDescriptor *d, uint64_t c, R4GfxOwnedBufferReservation *o){assert(d && c==UINT64_C(0x100000003) && o->size==88);o->cookie=c;return 1;}
static int32_t owned_commit(const R4GfxOwnedBufferReservation *r,R4GfxBufferReference *o){assert(r->cookie==UINT64_C(0x100000003) && o->size==48);return 1;}
static int32_t owned_abort(const R4GfxOwnedBufferReservation *r,uint32_t q){assert(r->cookie==UINT64_C(0x100000003) && q==0);return -4;}
static int32_t owned_take(uint32_t a,uint64_t g,R4GfxOwnedBufferRelease *o){assert(a==17 && g==UINT64_C(0x300000007) && o->size==80);o->attempt=UINT64_C(0x400000009);return 1;}
static int32_t owned_finish(const R4GfxOwnedBufferRelease *r,uint32_t q){assert(r->attempt==UINT64_C(0x400000009) && q==1);return 1;}
static void owned_facade_probe(void){
    R4GfxDriverMemoryApi m={.version=1,.size=152,.buffer_reserve=(uintptr_t)owned_reserve,.buffer_commit=(uintptr_t)owned_commit,.buffer_abort=(uintptr_t)owned_abort,.buffer_take_release=(uintptr_t)owned_take,.buffer_finish_release=(uintptr_t)owned_finish};
    R4GfxBufferDescriptor d={0};R4GfxOwnedBufferReservation r={0};R4GfxBufferReference ref={0};R4GfxOwnedBufferRelease rel={0};
    for(unsigned i=112;i<120;++i){m.size=i;assert(r4driver_memory_buffer_reserve(&m,&d,UINT64_C(0x100000003),&r)==R4OS_ERR_NO_FN && r.cookie==0);}
    m.size=120;assert(r4driver_memory_buffer_reserve(&m,&d,UINT64_C(0x100000003),&r)==1);
    for(unsigned i=120;i<128;++i){m.size=i;assert(r4driver_memory_buffer_commit(&m,&r,&ref)==R4OS_ERR_NO_FN);}
    m.size=128;assert(r4driver_memory_buffer_commit(&m,&r,&ref)==1);
    for(unsigned i=128;i<136;++i){m.size=i;assert(r4driver_memory_buffer_abort(&m,&r,0)==R4OS_ERR_NO_FN);}
    m.size=136;assert(r4driver_memory_buffer_abort(&m,&r,0)==-4);
    for(unsigned i=136;i<144;++i){m.size=i;assert(r4driver_memory_buffer_take_release(&m,17,UINT64_C(0x300000007),&rel)==R4OS_ERR_NO_FN);}
    m.size=144;assert(r4driver_memory_buffer_take_release(&m,17,UINT64_C(0x300000007),&rel)==1);
    for(unsigned i=144;i<152;++i){m.size=i;assert(r4driver_memory_buffer_finish_release(&m,&rel,1)==R4OS_ERR_NO_FN);}
    m.size=152;assert(r4driver_memory_buffer_finish_release(&m,&rel,1)==1);
}
static void gfx_facade_probe(void) {
    owned_facade_probe();
    R4XStartR4Draw table = {0};
    table.size = offsetof(R4XStartR4Draw, gfx_buffer_map);
    table.gfx_buffer_map = (uintptr_t)gfx_map_probe;
    const R4Draw draw = { &table };
    R4GfxBufferHandle ref = { .id = 7, .generation = 99 };
    R4GfxBufferMap output = { .byte_length = 37 };
    assert(r4draw_gfx_buffer_map(&draw, &ref, 1, UINT64_C(0x100000003), UINT64_C(0x200000000), &output) == R4OS_ERR_NO_FN);
    assert(output.byte_length == 37);
    table.size = sizeof(table);
    assert(r4draw_gfx_buffer_map(&draw, &ref, 1, UINT64_C(0x100000003), UINT64_C(0x200000000), &output) == 1);
    R4GfxDriverMemoryApi memory = { .version = 1, .size = sizeof(memory), .buffer_map = (uintptr_t)gfx_map_probe };
    assert(r4driver_memory_buffer_map(&memory, &ref, 1, UINT64_C(0x100000003), UINT64_C(0x200000000), &output) == 1);
    memory.size = offsetof(R4GfxDriverMemoryApi, buffer_map);
    assert(r4driver_memory_buffer_map(&memory, &ref, 1, 0, 0, &output) == R4OS_ERR_NO_FN);
    R4GfxFence fence = {.slot = 7, .timeline = 23, .point = UINT64_C(0x100000007), .reset_generation = UINT64_C(0x200000001)};
    R4GfxFenceStatus result = {.deadline_ns = 123};
    table.gfx_fence_wait = (uintptr_t)gfx_wait_probe;
    table.size = offsetof(R4XStartR4Draw, gfx_fence_wait);
    assert(r4draw_gfx_fence_wait(&draw, &fence, UINT64_C(0x300000003), 1, &result) == R4OS_ERR_NO_FN);
    assert(result.deadline_ns == 123);
    table.size += sizeof(uintptr_t);
    assert(r4draw_gfx_fence_wait(&draw, &fence, UINT64_C(0x300000003), 1, &result) == 1);
    R4GfxDriverQueueApi native = {.version = 1, .size = sizeof(native), .complete = (uintptr_t)gfx_complete_probe};
    assert(r4driver_queue_complete(&native, &fence, 6, 0) == -4);
    native.size = offsetof(R4GfxDriverQueueApi, complete);
    assert(r4driver_queue_complete(&native, &fence, 6, 0) == R4OS_ERR_NO_FN);
    R4GfxBufferReference retained = {.flags = 79};
    native.retain_resource = (uintptr_t)gfx_retain_probe;
    for (unsigned size = 56; size < 64; ++size) {
        native.size = size;
        assert(r4driver_queue_retain_resource(&native, &fence, 1, &retained) == R4OS_ERR_NO_FN && retained.flags == 79);
    }
    native.size = 64;
    assert(r4driver_queue_retain_resource(&native, &fence, 1, &retained) == 1);
    assert(retained.reference.generation == UINT64_C(0x400000009) && retained.flags == R4OS_GFX_BUFFER_REFERENCE_MAPPING_ONLY);
    R4GfxAtomicState state = {.topology_revision = UINT64_C(0x100000007)};
    state.assignments[7].output.connection_generation = UINT64_C(0x200000009);
    R4GfxAtomicResult atomic_result = {.commit_sequence = 77};
    table.abi_version = 11; table.size = 536; table.gfx_atomic_test = (uintptr_t)output_test_probe;
    assert(r4draw_gfx_atomic_test(&draw, &state, &atomic_result) == R4OS_ERR_NO_FN && atomic_result.commit_sequence == 77);
    table.size = sizeof(table);
    assert(r4draw_gfx_atomic_test(&draw, &state, &atomic_result) == 1 && atomic_result.topology_revision == state.topology_revision);
    R4GfxDriverOutputApi output_driver = {.version = 1, .size = sizeof(output_driver), .publish = (uintptr_t)output_publish_probe};
    R4GfxOutputPublication publication = {0}; publication.info.edid_bytes = 128; publication.edid[127] = 0x79;
    R4GfxOutputId identity = {0};
    assert(r4driver_output_publish(&output_driver, &publication, &identity) == 1 && identity.connection_generation == UINT64_C(0x40000000d));
    output_driver.register_source = (uintptr_t)receiver_register_probe;
    output_driver.replace_receivers = (uintptr_t)receiver_replace_probe;
    output_driver.close_source = (uintptr_t)receiver_close_probe;
    R4GfxReceiverSource receiver_source = {0};
    assert(r4driver_output_supports_receivers(&output_driver));
    assert(r4driver_output_register_source(&output_driver, 17, &receiver_source) == 1);
    R4GfxReceiverUpdate update = {.version = 1, .size = sizeof(update), .source = receiver_source, .sequence = UINT64_C(0x200000001)};
    assert(r4driver_output_replace_receivers(&output_driver, &update) == -4);
    assert(r4driver_output_close_source(&output_driver, &receiver_source) == 1);
    for (unsigned size = 24; size < 48; ++size) {
        output_driver.size = size;
        assert(!r4driver_output_supports_receivers(&output_driver));
        assert(r4driver_output_register_source(&output_driver, 17, &receiver_source) == R4OS_ERR_NO_FN);
        assert(r4driver_output_replace_receivers(&output_driver, &update) == R4OS_ERR_NO_FN);
        assert(r4driver_output_close_source(&output_driver, &receiver_source) == R4OS_ERR_NO_FN);
        assert(receiver_source.generation == UINT64_C(0x100000079));
    }
    output_driver.size = offsetof(R4GfxDriverOutputApi, publish);
    assert(r4driver_output_publish(&output_driver, &publication, &identity) == R4OS_ERR_NO_FN && identity.connection_generation == UINT64_C(0x40000000d));
    R4GfxDriverDisplayApi display = {.version = 1, .size = sizeof(display), .transition = (uintptr_t)display_transition_probe, .schedule = (uintptr_t)display_schedule_probe};
    R4GfxNativeState outcome = {0};
    assert(r4driver_display_transition(&display, UINT64_C(0x100000007), 2, &outcome) == 1);
    assert(outcome.generation == UINT64_C(0x100000008) && outcome.outcome == 3 && outcome.retained == 1);
    R4GfxBackendBinding binding = {.reset_generation = UINT64_C(0x30000000b)};
    assert(r4driver_display_schedule(&display, &binding) == -4);
    display.size = offsetof(R4GfxDriverDisplayApi, schedule);
    assert(r4driver_display_schedule(&display, &binding) == R4OS_ERR_NO_FN);
    display.size = offsetof(R4GfxDriverDisplayApi, transition);
    assert(r4driver_display_transition(&display, 0, 0, &outcome) == R4OS_ERR_NO_FN);
    assert(outcome.generation == UINT64_C(0x100000008) && outcome.retained == 1);
}

static uint64_t now_ticks = 100u;
static uint32_t activity_waits;
static uint32_t clipboard_revision = 7u;
static uint32_t event_index;
static uint32_t draw_count;
static uint32_t present_count;
static uint32_t alpha8_count;
static int32_t alpha8_x;
static int32_t alpha8_y;
static uint32_t alpha8_width;
static uint32_t alpha8_height;
static uint32_t alpha8_stride;
static uint8_t alpha8_first;
static uint32_t frame_begin_count;
static uint32_t frame_append_count;
static uint32_t frame_commit_count;
static uint32_t frame_cancel_count;

static const R4GuiEvent events[] = {
    {.kind = R4_GUI_RAW_EVENT_RESIZE, .window_id = 4, .tick = 10u},
    {.kind = R4_GUI_RAW_EVENT_KEY_DOWN, .window_id = 4, .key = 'A', .modifiers = 2u, .tick = 11u},
    {.kind = R4_GUI_RAW_EVENT_MOUSE_DOWN, .window_id = 4, .x = 8, .y = 9, .buttons = 1u, .tick = 12u},
    {.kind = R4_GUI_RAW_EVENT_MOUSE_UP, .window_id = 4, .x = 10, .y = 11, .tick = 13u},
    {.kind = R4_GUI_RAW_EVENT_MOUSE_MOVE, .window_id = 4, .x = 12, .y = 13, .tick = 14u},
    {.kind = R4_GUI_RAW_EVENT_CLOSE, .window_id = 4, .tick = 15u},
};

static uint64_t fake_ticks(void) { return now_ticks; }
static uint32_t fake_should_close(void) { return 0u; }
static void fake_time_state(R4TimeState *out) {
    *out = (R4TimeState){0};
    out->monotonic_ticks = now_ticks;
    out->monotonic_hz = 1000u;
    out->valid = 1u;
}
static int32_t fake_window_id(void) { return 4; }
static int32_t fake_window_info(R4GuiWindowInfo *out) {
    *out = (R4GuiWindowInfo){0};
    out->window_id = 4;
    out->client_w = 320;
    out->client_h = 200;
    return 0;
}
static int32_t fake_poll_event(R4GuiEvent *out) {
    if (event_index >= sizeof(events) / sizeof(events[0])) return 0;
    *out = events[event_index++];
    return 1;
}
static int32_t fake_set_title(const uint8_t *title) { return title != 0 ? 0 : -1; }
static int32_t fake_set_minimum_size(int32_t width, int32_t height) { return width == 100 && height == 80 ? 0 : -1; }
static uint32_t fake_clipboard_revision(void) { return clipboard_revision; }
static int32_t fake_activity_wait(uint64_t sequence, uint64_t timeout, uint64_t *out_sequence) {
    ++activity_waits;
    now_ticks = UINT64_MAX - now_ticks < timeout ? UINT64_MAX : now_ticks + timeout;
    *out_sequence = sequence;
    return 0;
}
static int32_t fake_clear(uint32_t rgb) { (void)rgb; ++draw_count; return 0; }
static int32_t fake_rect(int32_t x, int32_t y, uint32_t width, uint32_t height, uint32_t rgb) {
    (void)x; (void)y; (void)width; (void)height; (void)rgb; ++draw_count; return 0;
}
static int32_t fake_text(int32_t x, int32_t y, const uint8_t *text, uint32_t fg, uint32_t bg) {
    (void)x; (void)y; (void)text; (void)fg; (void)bg; ++draw_count; return 0;
}
static int32_t fake_alpha8(int32_t x, int32_t y, uint32_t width, uint32_t height,
                           uint32_t stride, uint32_t rgb, const uint8_t *alpha,
                           uint32_t alpha_len) {
    (void)rgb;
    assert(alpha != 0 && alpha_len >= width);
    ++alpha8_count;
    alpha8_x = x;
    alpha8_y = y;
    alpha8_width = width;
    alpha8_height = height;
    alpha8_stride = stride;
    alpha8_first = alpha[0];
    return 0;
}
static int32_t fake_present(void) { ++present_count; return 0; }
static int32_t fake_frame_begin(void) { ++frame_begin_count; return R4OS_GUI_FRAME_RESULT_OK; }
static int32_t fake_frame_append(const R4GuiFrameCommand *commands, uint64_t command_count,
                                 const uint8_t *resources, uint64_t resource_len) {
    ++frame_append_count;
    return (commands == 0 && command_count != 0u) || (resources == 0 && resource_len != 0u)
        ? R4OS_GUI_FRAME_ERROR_INVALID : R4OS_GUI_FRAME_RESULT_OK;
}
static int32_t fake_frame_commit(void) { ++frame_commit_count; return R4OS_GUI_FRAME_RESULT_OK; }
static int32_t fake_frame_cancel(void) { ++frame_cancel_count; return R4OS_GUI_FRAME_RESULT_OK; }
static int32_t fake_frame_info(const R4ProgramProcessHandle *handle, R4GuiFrameInfo *out) {
    if (out->version < R4OS_GUI_FRAME_INFO_VERSION || out->size < R4OS_GUI_FRAME_INFO_SIZE) return R4OS_GUI_FRAME_ERROR_INVALID;
    *out = (R4GuiFrameInfo){0};
    out->version = R4OS_GUI_FRAME_INFO_VERSION;
    out->size = R4OS_GUI_FRAME_INFO_SIZE;
    if (handle != 0) out->owner = *handle;
    out->committed_generation = 7u;
    out->committed_command_count = 1u;
    out->committed_resource_bytes = 4u;
    return R4OS_GUI_FRAME_RESULT_OK;
}
static int32_t fake_frame_read(const R4ProgramProcessHandle *handle, uint64_t expected_generation,
                               R4GuiFrameCommand *commands, uint64_t command_capacity,
                               uint8_t *resources, uint64_t resource_capacity,
                               R4GuiFrameInfo *out) {
    (void)handle;
    if (out->version < R4OS_GUI_FRAME_INFO_VERSION || out->size < R4OS_GUI_FRAME_INFO_SIZE) return R4OS_GUI_FRAME_ERROR_INVALID;
    *out = (R4GuiFrameInfo){0};
    out->version = R4OS_GUI_FRAME_INFO_VERSION;
    out->size = R4OS_GUI_FRAME_INFO_SIZE;
    out->committed_generation = 7u;
    out->committed_command_count = 1u;
    out->committed_resource_bytes = 4u;
    if ((commands == 0 && command_capacity != 0u) ||
        (resources == 0 && resource_capacity != 0u)) return R4OS_GUI_FRAME_ERROR_INVALID;
    if (expected_generation != 7u) return R4OS_GUI_FRAME_ERROR_STALE;
    if (command_capacity < 1u || resource_capacity < 4u) return R4OS_GUI_FRAME_ERROR_BUFFER_TOO_SMALL;
    commands[0] = (R4GuiFrameCommand){0}; commands[0].kind = R4OS_GUI_FRAME_COMMAND_KIND_TEXT; commands[0].resource_bytes = 4u;
    resources[0] = 'R'; resources[1] = '4'; resources[2] = 'O'; resources[3] = 'S';
    return R4OS_GUI_FRAME_RESULT_OK;
}

static R4App make_app(R4XStartR4Sys *sys, R4XStartR4Desk *desk, R4XStartR4Draw *draw, int drawing_available) {
    *sys = (R4XStartR4Sys){0};
    sys->ticks = (uintptr_t)&fake_ticks;
    sys->time_state = (uintptr_t)&fake_time_state;
    sys->program_should_close = (uintptr_t)&fake_should_close;
    *desk = (R4XStartR4Desk){0};
    desk->program_window_id = (uintptr_t)&fake_window_id;
    desk->gui_window_info = (uintptr_t)&fake_window_info;
    desk->gui_poll_event = (uintptr_t)&fake_poll_event;
    desk->gui_set_title = (uintptr_t)&fake_set_title;
    desk->gui_set_min_size = (uintptr_t)&fake_set_minimum_size;
    desk->clipboard_revision = (uintptr_t)&fake_clipboard_revision;
    desk->desktop_activity_wait = (uintptr_t)&fake_activity_wait;
    *draw = (R4XStartR4Draw){0};
    draw->size = R4XSTART_R4DRAW_SIZE;
    draw->gui_clear = (uintptr_t)&fake_clear;
    draw->gui_rect = (uintptr_t)&fake_rect;
    draw->gui_draw_text = (uintptr_t)&fake_text;
    draw->gui_blend_alpha8 = (uintptr_t)&fake_alpha8;
    if (drawing_available) draw->gui_present = (uintptr_t)&fake_present;
    R4App app = {0};
    app.profile = R4_APP_PROFILE_DESKTOP;
    app.group_mask = (1u << R4L_GROUP_R4SYS) | (1u << R4L_GROUP_R4DESK) | (1u << R4L_GROUP_R4DRAW);
    app.system.table = sys;
    app.desktop.table = desk;
    app.drawing.table = draw;
    return app;
}

int main(void) {
    gfx_facade_probe();
    R4XStartR4Sys sys;
    R4XStartR4Desk desk;
    R4XStartR4Draw draw;
    R4App app = make_app(&sys, &desk, &draw, 1);
    draw.magic = R4XSTART_R4DRAW_MAGIC;
    draw.abi_version = 10;
    draw.size = offsetof(R4XStartR4Draw, gfx_queue_open);
    const R4XStartImport draw_import = {.group_id = R4L_GROUP_R4DRAW, .flags = R4XSTART_IMPORT_FLAG_GROUP_INTERFACE, .table = (uintptr_t)&draw};
    const R4XStartContext old_start = {.magic = R4XSTART_MAGIC, .abi_major = R4XSTART_ABI_MAJOR, .size = sizeof(R4XStartContext), .flags = R4XSTART_FLAG_IMPORTS_VALID, .imports = (uintptr_t)&draw_import, .import_count = 1};
    R4Draw old_draw;
    assert(r4draw_init(&old_start, &old_draw) == R4OS_OK);
    R4GfxQueueConfig old_config = {0};
    R4GfxQueueHandle untouched = {.timeline = 77};
    assert(r4draw_gfx_queue_open(&old_draw, &old_config, &untouched) == R4OS_ERR_NO_FN && untouched.timeline == 77);
    draw.size = R4XSTART_R4DRAW_SIZE;
    R4Timer timers[1] = {{0}};
    R4Window window;
    assert(r4_window_open(&app, timers, 1u, &window));
    assert(r4_window_set_title(&window, "Test") == 0);
    assert(r4_window_set_minimum_size(&window, 100, 80) == 0);

    R4Message message;
    assert(r4_event_loop_poll(&window.events, &message) && message.kind == R4_MESSAGE_RESIZE && message.value.resize.width == 320);
    assert(r4_event_loop_poll(&window.events, &message) && message.kind == R4_MESSAGE_KEY && message.value.key.key == 'A' && message.value.key.codepoint == 'A');
    assert(r4_event_loop_poll(&window.events, &message) && message.kind == R4_MESSAGE_MOUSE && message.value.mouse.action == R4_MOUSE_DOWN);
    assert(r4_event_loop_poll(&window.events, &message) && message.kind == R4_MESSAGE_MOUSE && message.value.mouse.action == R4_MOUSE_UP);
    assert(r4_event_loop_poll(&window.events, &message) && message.kind == R4_MESSAGE_MOUSE && message.value.mouse.action == R4_MOUSE_MOVE);
    assert(r4_event_loop_poll(&window.events, &message) && message.kind == R4_MESSAGE_CLOSE && message.value.close_window_id == 4);

    R4PaintContext paint;
    assert(r4_window_begin_paint(&window, &paint));
    R4Canvas canvas = r4_paint_canvas(&paint);
    assert(r4_canvas_clear(canvas, 0u) == 0);
    assert(r4_canvas_rect(canvas, 1, 2, 3u, 4u, 0xFFFFFFu) == 0);
    const uint8_t alpha8[] = {10u, 20u, 30u, 99u, 40u, 50u, 60u};
    assert(r4_canvas_blend_alpha8(canvas, -1, -1, 3u, 2u, 4u, 0x336699u,
                                  alpha8, sizeof(alpha8)) == 0);
    assert(alpha8_count == 1u && alpha8_x == 0 && alpha8_y == 0);
    assert(alpha8_width == 2u && alpha8_height == 1u && alpha8_stride == 4u);
    assert(alpha8_first == 50u);
    assert(r4_paint_present(&paint) == 0);
    assert(r4_paint_present(&paint) == R4OS_ERR_NO_FN);
    assert(draw_count >= 2u && present_count == 1u);

    draw.gui_frame_begin = (uintptr_t)&fake_frame_begin;
    draw.gui_frame_append = (uintptr_t)&fake_frame_append;
    draw.gui_frame_commit = (uintptr_t)&fake_frame_commit;
    draw.gui_frame_cancel = (uintptr_t)&fake_frame_cancel;
    draw.gui_frame_info = (uintptr_t)&fake_frame_info;
    draw.gui_frame_read = (uintptr_t)&fake_frame_read;
    assert(r4draw_supports_gui_frame_contract(&app.drawing));
    assert(r4_window_begin_paint(&window, &paint));
    R4GuiFrameCommand command = {0}; command.version = R4OS_GUI_FRAME_COMMAND_VERSION; command.size = R4OS_GUI_FRAME_COMMAND_SIZE; command.kind = R4OS_GUI_FRAME_COMMAND_KIND_TEXT; command.resource_bytes = 4u;
    assert(r4draw_gui_frame_append(&app.drawing, &command, 1u, (const uint8_t *)"R4OS", 4u) == R4OS_GUI_FRAME_RESULT_OK);
    assert(r4draw_gui_frame_append(&app.drawing, 0, 1u, 0, 0u) == R4OS_GUI_FRAME_ERROR_INVALID);
    assert(frame_append_count == 2u);
    assert(r4_paint_present(&paint) == R4OS_GUI_FRAME_RESULT_OK);
    assert(frame_begin_count == 1u && frame_commit_count == 1u);
    R4ProgramProcessHandle handle = {0}; handle.instance_id = 4u; handle.generation = 9u;
    R4GuiFrameInfo frame_info = {0};
    assert(r4draw_gui_frame_info(&app.drawing, &handle, &frame_info) == R4OS_GUI_FRAME_RESULT_OK);
    assert(frame_info.version == R4OS_GUI_FRAME_INFO_VERSION && frame_info.size == R4OS_GUI_FRAME_INFO_SIZE);
    R4GuiFrameCommand snapshot_commands[1] = {{0}}; uint8_t snapshot_resources[4] = {0};
    frame_info.version = 0u; frame_info.size = 0u;
    assert(r4draw_gui_frame_read(&app.drawing, &handle, frame_info.committed_generation, snapshot_commands, 1u, snapshot_resources, 4u, &frame_info) == R4OS_GUI_FRAME_RESULT_OK);
    assert(snapshot_resources[0] == 'R' && snapshot_resources[3] == 'S');
    frame_info = (R4GuiFrameInfo){0};
    assert(r4draw_gui_frame_read(&app.drawing, &handle, 7u, 0, 1u, snapshot_resources, 4u, &frame_info) == R4OS_GUI_FRAME_ERROR_INVALID);
    assert(frame_info.version == R4OS_GUI_FRAME_INFO_VERSION && frame_info.size == R4OS_GUI_FRAME_INFO_SIZE && frame_info.committed_command_count == 1u);
    assert(r4_window_begin_paint(&window, &paint)); r4_paint_discard(&paint); assert(frame_cancel_count == 1u);

    assert(r4_event_loop_post_command(&window.events, (R4CommandId){42u}));
    assert(r4_event_loop_poll(&window.events, &message) && message.kind == R4_MESSAGE_COMMAND && message.value.command.value == 42u);
    clipboard_revision = 8u;
    assert(r4_event_loop_poll(&window.events, &message) && message.kind == R4_MESSAGE_CLIPBOARD && message.value.clipboard.revision == 8u);
    assert(r4_timer_start(&timers[0], &app, (R4TimerId){9u}, (R4Duration){2000000u}, 0));
    R4MessageNext next = r4_window_wait_message(&window, r4_timeout_finite((R4Duration){10000000u}));
    assert(next.state == R4_MESSAGE_NEXT_MESSAGE && next.message.kind == R4_MESSAGE_TIMER && next.message.value.timer.id.value == 9u);
    assert(activity_waits > 0u);
    assert(r4_window_wait_message(&window, r4_timeout_poll()).state == R4_MESSAGE_NEXT_TIMED_OUT);

    R4App missing_draw = make_app(&sys, &desk, &draw, 0);
    assert(!r4_window_open(&missing_draw, timers, 1u, &window));
    return 0;
}
