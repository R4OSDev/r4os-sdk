const std = @import("std");
const r4os = @import("r4os");

fn gfxMapProbe(ref: *const r4os.abi.GfxBufferHandle, access: u32, offset: u64, bytes: u64, out: *r4os.abi.GfxBufferMap) callconv(.c) i32 {
    std.debug.assert(ref.generation == 99 and access == 1 and offset == 0x100000003 and bytes == 0x200000000);
    std.debug.assert(out.version == 1 and out.size == @sizeOf(r4os.abi.GfxBufferMap));
    out.byte_length = bytes;
    return 1;
}
fn gfxWaitProbe(fence: *const r4os.abi.GfxFence, ticks: u64, wait_for: u32, out: *r4os.abi.GfxFenceStatus) callconv(.c) i32 {
    std.debug.assert(fence.point == 0x100000007 and fence.reset_generation == 0x200000001 and ticks == 0x300000003 and wait_for == 1);
    std.debug.assert(out.version == 1 and out.size == 80);
    out.fence = fence.*;
    return 1;
}
fn gfxCompleteProbe(fence: *const r4os.abi.GfxFence, result: u32, quiesced: u32) callconv(.c) i32 {
    std.debug.assert(fence.point == 0x100000007 and result == 6 and quiesced == 0);
    return -4;
}
fn gfxRetainProbe(fence: *const r4os.abi.GfxFence, which: u32, out: *r4os.abi.GfxBufferReference) callconv(.c) i32 {
    std.debug.assert(fence.point == 0x100000007 and fence.reset_generation == 0x200000001 and which == 1);
    std.debug.assert(out.version == 1 and out.size == 48);
    out.reference.generation = 0x400000009;
    out.flags = r4os.abi.gfx_buffer_reference_mapping_only;
    return 1;
}
fn gfxQueuePrefixProbe(out: *r4os.abi.GfxDriverQueueApi) callconv(.c) i32 {
    out.* = .{ .size = 56, .complete = @intFromPtr(&gfxCompleteProbe) };
    return 1;
}
fn ownedReserveProbe(_: *const r4os.abi.GfxBufferDescriptor, cookie: u64, out: *r4os.abi.GfxOwnedBufferReservation) callconv(.c) i32 {
    std.debug.assert(cookie == 0x100000003 and out.size == 88);
    out.cookie = cookie; out.driver_generation = 0x200000005; return 1;
}
fn ownedCommitProbe(in: *const r4os.abi.GfxOwnedBufferReservation, out: *r4os.abi.GfxBufferReference) callconv(.c) i32 {
    std.debug.assert(in.cookie == 0x100000003 and in.driver_generation == 0x200000005 and out.size == 48); return 1;
}
fn ownedAbortProbe(in: *const r4os.abi.GfxOwnedBufferReservation, quiesced: u32) callconv(.c) i32 {
    std.debug.assert(in.cookie == 0x100000003 and quiesced == 0); return -4;
}
fn ownedTakeProbe(adapter: u32, generation: u64, out: *r4os.abi.GfxOwnedBufferRelease) callconv(.c) i32 {
    std.debug.assert(adapter == 17 and generation == 0x300000007 and out.size == 80);
    out.cookie = 0x100000003; out.attempt = 0x400000009; return 1;
}
fn ownedFinishProbe(in: *const r4os.abi.GfxOwnedBufferRelease, quiesced: u32) callconv(.c) i32 {
    std.debug.assert(in.cookie == 0x100000003 and in.attempt == 0x400000009 and quiesced == 1); return 1;
}
fn memoryPrefixProbe(out: *r4os.abi.GfxDriverMemoryApi) callconv(.c) i32 {
    const value: r4os.abi.GfxDriverMemoryApi = .{ .size = 112, .buffer_map = @intFromPtr(&gfxMapProbe) };
    @memcpy(@as([*]u8, @ptrCast(out))[0..112], std.mem.asBytes(&value)[0..112]); return 1;
}
fn ownedFacadeProbe() !void {
    const a = r4os.abi;
    var native = r4os.driver_memory.Context{ .table = .{ .buffer_reserve = @intFromPtr(&ownedReserveProbe), .buffer_commit = @intFromPtr(&ownedCommitProbe),
        .buffer_abort = @intFromPtr(&ownedAbortProbe), .buffer_take_release = @intFromPtr(&ownedTakeProbe), .buffer_finish_release = @intFromPtr(&ownedFinishProbe) } };
    var reservation: a.GfxOwnedBufferReservation = .{}; var reference: a.GfxBufferReference = .{}; var release: a.GfxOwnedBufferRelease = .{};
    for (112..120) |size| { native.table.size = @intCast(size); try std.testing.expectEqual(a.err_no_fn, native.bufferReserve(&.{}, 0x100000003, &reservation)); }
    try std.testing.expect(reservation.cookie == 0);
    native.table.size = 120; try std.testing.expectEqual(@as(i32, 1), native.bufferReserve(&.{}, 0x100000003, &reservation));
    for (120..128) |size| { native.table.size = @intCast(size); try std.testing.expectEqual(a.err_no_fn, native.bufferCommit(&reservation, &reference)); }
    native.table.size = 128; try std.testing.expectEqual(@as(i32, 1), native.bufferCommit(&reservation, &reference));
    for (128..136) |size| { native.table.size = @intCast(size); try std.testing.expectEqual(a.err_no_fn, native.bufferAbort(&reservation, 0)); }
    native.table.size = 136; try std.testing.expectEqual(@as(i32, -4), native.bufferAbort(&reservation, 0));
    for (136..144) |size| { native.table.size = @intCast(size); try std.testing.expectEqual(a.err_no_fn, native.bufferTakeRelease(17, 0x300000007, &release)); }
    native.table.size = 144; try std.testing.expectEqual(@as(i32, 1), native.bufferTakeRelease(17, 0x300000007, &release));
    for (144..152) |size| { native.table.size = @intCast(size); try std.testing.expectEqual(a.err_no_fn, native.bufferFinishRelease(&release, 1)); }
    native.table.size = 152; try std.testing.expectEqual(@as(i32, 1), native.bufferFinishRelease(&release, 1));
    var api: a.DriverApi = undefined; api.magic = a.driver_magic; api.version = 25; api.size = 568; api.gfx_memory_query = &memoryPrefixProbe;
    const ctx = r4os.r4dev.DriverContext.init(&api); const old = ctx.memory().?;
    try std.testing.expect(old.table.size == 112 and old.table.buffer_reserve == 0);
    try std.testing.expectEqual(a.err_no_fn, old.bufferReserve(&.{}, 0, &reservation));
}
test "graphics buffer optional tails preserve 64-bit offsets in Zig and R4D calls" {
    try ownedFacadeProbe();
    var tables = makeTables(true);
    tables[2].abi_version = 10; // A new facade must accept an older prefix.
    tables[2].gfx_buffer_map = @intFromPtr(&gfxMapProbe);
    tables[2].size = @offsetOf(r4os.abi.R4XStartR4Draw, "gfx_buffer_map");
    var imports: [3]r4os.abi.R4XStartImport = undefined;
    var context: r4os.abi.R4XStartContext = undefined;
    var app = try makeApp(&tables, &imports, &context);
    const draw = app.drawing().?;
    const buffers = draw.buffers();
    const ref: r4os.abi.GfxBufferHandle = .{ .id = 7, .generation = 99 };
    var output: r4os.abi.GfxBufferMap = .{ .byte_length = 37 };
    try std.testing.expectEqual(r4os.abi.err_no_fn, buffers.map(&ref, 1, 0x100000003, 0x200000000, &output));
    try std.testing.expectEqual(@as(u64, 37), output.byte_length);
    tables[2].size = @sizeOf(r4os.abi.R4XStartR4Draw);
    try std.testing.expectEqual(@as(i32, 1), buffers.map(&ref, 1, 0x100000003, 0x200000000, &output));
    var old_driver: r4os.abi.DriverApi = undefined;
    old_driver.magic = r4os.abi.driver_magic;
    old_driver.version = 24;
    old_driver.size = @offsetOf(r4os.abi.DriverApi, "gfx_memory_query");
    const old_context = r4os.r4dev.DriverContext.init(&old_driver);
    try std.testing.expect(old_context.apiCompatible());
    try std.testing.expect(old_context.memory() == null);
    try std.testing.expect(old_context.graphicsQueue() == null);
    const memory = @import("r4os").driver_memory.Context{ .table = .{ .buffer_map = @intFromPtr(&gfxMapProbe) } };
    try std.testing.expectEqual(@as(i32, 1), memory.bufferMap(&ref, 1, 0x100000003, 0x200000000, &output));
    const queues = draw.queues();
    const fence: r4os.abi.GfxFence = .{ .slot = 7, .timeline = 23, .point = 0x100000007, .reset_generation = 0x200000001 };
    var result: r4os.abi.GfxFenceStatus = .{ .deadline_ns = 123 };
    tables[2].gfx_fence_wait = @intFromPtr(&gfxWaitProbe);
    tables[2].size = @offsetOf(r4os.abi.R4XStartR4Draw, "gfx_fence_wait");
    try std.testing.expectEqual(r4os.abi.err_no_fn, queues.wait(&fence, 0x300000003, 1, &result));
    try std.testing.expectEqual(@as(u64, 123), result.deadline_ns);
    tables[2].size += 8;
    try std.testing.expectEqual(@as(i32, 1), queues.wait(&fence, 0x300000003, 1, &result));
    var native = r4os.driver_queue.Context{ .table = .{ .complete = @intFromPtr(&gfxCompleteProbe) } };
    try std.testing.expectEqual(@as(i32, -4), native.complete(&fence, 6, 0));
    native.table.size = @offsetOf(r4os.abi.GfxDriverQueueApi, "complete");
    try std.testing.expectEqual(r4os.abi.err_no_fn, native.complete(&fence, 6, 0));
    var retained: r4os.abi.GfxBufferReference = .{ .flags = 79 };
    native.table.retain_resource = @intFromPtr(&gfxRetainProbe);
    for (56..64) |size| {
        native.table.size = @intCast(size);
        try std.testing.expectEqual(r4os.abi.err_no_fn, native.retainResource(&fence, 1, &retained));
        try std.testing.expectEqual(@as(u32, 79), retained.flags);
    }
    native.table.size = 64;
    try std.testing.expectEqual(@as(i32, 1), native.retainResource(&fence, 1, &retained));
    try std.testing.expectEqual(@as(u64, 0x400000009), retained.reference.generation);
    try std.testing.expectEqual(r4os.abi.gfx_buffer_reference_mapping_only, retained.flags);
    old_driver.version = 26;
    old_driver.size = 576;
    old_driver.gfx_queue_query = &gfxQueuePrefixProbe;
    const prefix = old_context.graphicsQueue().?;
    try std.testing.expectEqual(@as(i32, -4), prefix.complete(&fence, 6, 0));
    try std.testing.expectEqual(r4os.abi.err_no_fn, prefix.retainResource(&fence, 1, &retained));
    try std.testing.expectEqual(@as(usize, 560), @offsetOf(r4os.abi.DriverApi, "gfx_memory_query"));
    try std.testing.expectEqual(@as(usize, 568), @offsetOf(r4os.abi.DriverApi, "gfx_queue_query"));
    try std.testing.expectEqual(@as(usize, 576), @offsetOf(r4os.abi.DriverApi, "gfx_output_query"));
    try std.testing.expectEqual(@as(usize, 584), @offsetOf(r4os.abi.DriverApi, "gfx_display_query"));
    try std.testing.expectEqual(@as(usize, 592), @offsetOf(r4os.abi.DriverApi, "resource_query"));
    // v29's resource query is still the end of that historical 600-byte
    // prefix; newer optional DriverApi services may follow it.
    try std.testing.expectEqual(@as(usize, 600), @offsetOf(r4os.abi.DriverApi, "resource_query") + @sizeOf(usize));
}

fn outputTestProbe(state: *const r4os.abi.GfxAtomicState, out: *r4os.abi.GfxAtomicResult) callconv(.c) i32 {
    std.debug.assert(state.topology_revision == 0x100000007 and state.assignments[7].output.connection_generation == 0x200000009);
    std.debug.assert(out.version == 1 and out.size == @sizeOf(r4os.abi.GfxAtomicResult));
    out.topology_revision = state.topology_revision;
    return 1;
}
fn modeEnableProbe(input: *const r4os.abi.GfxBackendBinding) callconv(.c) i32 {
    std.debug.assert(input.device_generation == 0x100000079);
    return 1;
}
fn modeTakeProbe(input: *const r4os.abi.GfxBackendBinding, output: *r4os.abi.GfxDriverModeJob) callconv(.c) i32 {
    std.debug.assert(input.device_generation == 0x100000079);
    output.* = .{ .ticket = 0x200000079, .sequence = 3, .operation = 1, .backend = input.* };
    return 1;
}
fn modeCompleteProbe(input: *const r4os.abi.GfxDriverModeCompletion) callconv(.c) i32 {
    std.debug.assert(input.ticket == 0x200000079 and input.sequence == 3 and input.quiesced == 1);
    return -3;
}
fn modeSubmitProbe(input: *const r4os.abi.GfxAtomicState, milliseconds: u32, output: *r4os.abi.GfxModeStatus) callconv(.c) i32 {
    std.debug.assert(input.topology_revision == 0x100000007 and milliseconds == 15000 and output.size == 88);
    output.* = .{ .ticket = 0x200000079, .phase = 1, .retained = 3 };
    return 1;
}
fn modeStatusProbe(ticket: u64, output: *r4os.abi.GfxModeStatus) callconv(.c) i32 {
    std.debug.assert(ticket == 0x200000079 and output.size == 88);
    output.phase = 3;
    return 1;
}
fn modeResolveProbe(ticket: u64, action: u32, output: *r4os.abi.GfxModeStatus) callconv(.c) i32 {
    std.debug.assert(ticket == 0x200000079 and action == 2 and output.size == 88);
    output.phase = 5;
    return 1;
}
fn outputPublishProbe(publication: *const r4os.abi.GfxOutputPublication, out: *r4os.abi.GfxOutputId) callconv(.c) i32 {
    std.debug.assert(publication.info.edid_bytes == 128 and publication.edid[127] == 0x79);
    out.* = .{ .adapter_id = 3, .connector_id = 17, .device_generation = 0x30000000b, .connection_generation = 0x40000000d };
    return 1;
}
fn receiverRegisterProbe(adapter: u32, out: *r4os.abi.GfxReceiverSource) callconv(.c) i32 {
    std.debug.assert(adapter == 17);
    out.* = .{ .adapter_id = adapter, .generation = 0x100000079 };
    return 1;
}
fn receiverReplaceProbe(input: *const r4os.abi.GfxReceiverUpdate) callconv(.c) i32 {
    std.debug.assert(input.source.generation == 0x100000079 and input.sequence == 0x200000001 and input.count == 0 and input.receivers == 0);
    return -4;
}
fn receiverCloseProbe(input: *const r4os.abi.GfxReceiverSource) callconv(.c) i32 {
    std.debug.assert(input.generation == 0x100000079);
    return 1;
}
fn displayTransitionProbe(generation: u64, operation: u32, output: *r4os.abi.GfxNativeState) callconv(.c) i32 {
    std.debug.assert(generation == 0x100000007 and operation == 2);
    output.generation = generation + 1; output.outcome = 3; output.retained = 1;
    return 1;
}
fn displayScheduleProbe(binding: *const r4os.abi.GfxBackendBinding) callconv(.c) i32 {
    std.debug.assert(binding.reset_generation == 0x30000000b);
    return -4;
}
fn presentationReadProbe(head: u32, output: *r4os.abi.DisplayPresentationStats) callconv(.c) i32 {
    std.debug.assert(head == 3 and output.version == 1 and output.size == 208);
    output.visible_sequence = 0x100000079; output.source_point = 0x200000079;
    return r4os.abi.gfx_output_ok;
}
fn presentationPublishProbe(input: *const r4os.abi.DisplayPresentationStats) callconv(.c) i32 {
    std.debug.assert(input.version == 1 and input.size == 208 and input.visible_sequence == 0x100000079 and input.source_point == 0x200000079);
    return r4os.abi.gfx_output_error_stale;
}
test "old display and driver prefixes hide output tails while C/Zig preserve receiver generations" {
    const a = r4os.abi;
    var tables = makeTables(true);
    tables[2].abi_version = 11; tables[2].size = 536;
    tables[2].gfx_atomic_test = @intFromPtr(&outputTestProbe);
    var imports: [3]a.R4XStartImport = undefined;
    var context: a.R4XStartContext = undefined;
    var app = try makeApp(&tables, &imports, &context);
    const outputs = app.drawing().?.outputs();
    const draw = app.drawing().?;
    var statistics: a.DisplayPresentationStats = .{ .visible_sequence = 79 };
    tables[2].display_presentation_stats = @intFromPtr(&presentationReadProbe);
    for (608..616) |bytes| {
        tables[2].size = @intCast(bytes);
        try std.testing.expect(!draw.supportsDisplayPresentationStats());
        try std.testing.expectEqual(a.err_no_fn, draw.displayPresentationStats(3, &statistics));
        try std.testing.expectEqual(@as(u64, 79), statistics.visible_sequence);
    }
    tables[2].size = 616;
    try std.testing.expect(draw.supportsDisplayPresentationStats());
    try std.testing.expectEqual(a.gfx_output_ok, draw.displayPresentationStats(3, &statistics));
    var statistics_driver: r4os.driver_display.Context = .{ .table = .{ .presentation_stats = @intFromPtr(&presentationPublishProbe) } };
    for (64..72) |bytes| {
        statistics_driver.table.size = @intCast(bytes);
        try std.testing.expect(!statistics_driver.supportsPresentationStats());
        try std.testing.expectEqual(a.err_no_fn, statistics_driver.presentationStats(&statistics));
    }
    statistics_driver.table.size = 72;
    try std.testing.expectEqual(a.gfx_output_error_stale, statistics_driver.presentationStats(&statistics));
    tables[2].size = 536;
    var state = a.GfxAtomicState{ .topology_revision = 0x100000007 };
    state.assignments[7].output.connection_generation = 0x200000009;
    var result = a.GfxAtomicResult{ .commit_sequence = 77 };
    const before = result;
    try std.testing.expectEqual(a.err_no_fn, outputs.testState(&state, &result));
    try std.testing.expectEqualDeep(before, result);
    tables[2].size = @sizeOf(a.R4XStartR4Draw);
    try std.testing.expectEqual(@as(i32, 1), outputs.testState(&state, &result));
    try std.testing.expectEqual(state.topology_revision, result.topology_revision);
    tables[2].gfx_atomic_submit = @intFromPtr(&modeSubmitProbe);
    tables[2].gfx_atomic_status = @intFromPtr(&modeStatusProbe);
    tables[2].gfx_atomic_resolve = @intFromPtr(&modeResolveProbe);
    var mode_status: a.GfxModeStatus = .{};
    tables[2].size = 584;
    try std.testing.expectEqual(a.err_no_fn, outputs.submit(&state, 15000, &mode_status));
    try std.testing.expectEqual(@as(u64, 0), mode_status.ticket);
    tables[2].size = @sizeOf(a.R4XStartR4Draw);
    try std.testing.expectEqual(a.gfx_output_ok, outputs.submit(&state, 15000, &mode_status));
    try std.testing.expectEqual(a.gfx_output_ok, outputs.status(mode_status.ticket, &mode_status));
    try std.testing.expectEqual(a.gfx_output_ok, outputs.resolve(mode_status.ticket, 2, &mode_status));
    try std.testing.expect(mode_status.ticket == 0x200000079 and mode_status.phase == 5 and mode_status.retained == 3);
    var mode_driver: r4os.driver_outputs.Context = .{ .table = .{ .mode_enable = @intFromPtr(&modeEnableProbe),
        .mode_take = @intFromPtr(&modeTakeProbe), .mode_complete = @intFromPtr(&modeCompleteProbe) } };
    const mode_binding: a.GfxBackendBinding = .{ .device_generation = 0x100000079 };
    var mode_job: a.GfxDriverModeJob = .{};
    for ([_]u32{ 24, 48, 56, 64, 71 }) |bytes| {
        mode_driver.table.size = bytes;
        try std.testing.expect(!mode_driver.supportsModes());
        try std.testing.expectEqual(a.err_no_fn, mode_driver.takeMode(&mode_binding, &mode_job));
    }
    mode_driver.table.size = 72;
    try std.testing.expectEqual(a.gfx_output_ok, mode_driver.enableModes(&mode_binding));
    try std.testing.expectEqual(a.gfx_output_ok, mode_driver.takeMode(&mode_binding, &mode_job));
    try std.testing.expectEqual(a.gfx_output_error_stale, mode_driver.completeMode(&.{ .ticket = mode_job.ticket, .sequence = mode_job.sequence, .quiesced = 1 }));
    var old_driver: a.DriverApi = undefined;
    old_driver.magic = a.driver_magic; old_driver.version = 26; old_driver.size = 576;
    try std.testing.expect(r4os.r4dev.DriverContext.init(&old_driver).graphicsOutputs() == null);
    var native = r4os.driver_outputs.Context{ .table = .{ .publish = @intFromPtr(&outputPublishProbe) } };
    var publication = a.GfxOutputPublication{}; publication.info.edid_bytes = 128; publication.edid[127] = 0x79;
    var identity: a.GfxOutputId = .{};
    try std.testing.expectEqual(@as(i32, 1), native.publish(&publication, &identity));
    try std.testing.expectEqual(@as(u64, 0x40000000d), identity.connection_generation);
    native.table = .{ .register_source = @intFromPtr(&receiverRegisterProbe), .replace_receivers = @intFromPtr(&receiverReplaceProbe), .close_source = @intFromPtr(&receiverCloseProbe) };
    var source: a.GfxReceiverSource = .{};
    try std.testing.expect(native.supportsReceivers());
    try std.testing.expectEqual(@as(i32, 1), native.registerSource(17, &source));
    const update: a.GfxReceiverUpdate = .{ .source = source, .sequence = 0x200000001 };
    try std.testing.expectEqual(@as(i32, -4), native.replaceReceivers(&update));
    try std.testing.expectEqual(@as(i32, 1), native.closeSource(&source));
    for ([_]u32{ 24, 32, 40, 47 }) |prefix| {
        native.table.size = prefix;
        try std.testing.expect(!native.supportsReceivers());
        try std.testing.expectEqual(a.err_no_fn, native.registerSource(17, &source));
        try std.testing.expectEqual(a.err_no_fn, native.replaceReceivers(&update));
        try std.testing.expectEqual(a.err_no_fn, native.closeSource(&source));
        try std.testing.expectEqual(@as(u64, 0x100000079), source.generation);
    }
    native.table.size = @offsetOf(a.GfxDriverOutputApi, "publish");
    try std.testing.expectEqual(a.err_no_fn, native.publish(&publication, &identity));
    try std.testing.expectEqual(@as(u64, 0x40000000d), identity.connection_generation);
    old_driver.version = 27; old_driver.size = 584;
    try std.testing.expect(r4os.r4dev.DriverContext.init(&old_driver).graphicsDisplay() == null);
    var display = r4os.driver_display.Context{ .table = .{ .transition = @intFromPtr(&displayTransitionProbe), .schedule = @intFromPtr(&displayScheduleProbe) } };
    var outcome = a.GfxNativeState{};
    try std.testing.expectEqual(@as(i32, 1), display.transition(0x100000007, 2, &outcome));
    try std.testing.expect(outcome.generation == 0x100000008 and outcome.outcome == 3 and outcome.retained == 1);
    const binding = a.GfxBackendBinding{ .reset_generation = 0x30000000b };
    try std.testing.expectEqual(@as(i32, -4), display.schedule(&binding));
    display.table.size = @offsetOf(a.GfxDriverDisplayApi, "schedule");
    try std.testing.expectEqual(a.err_no_fn, display.schedule(&binding));
    display.table.size = @offsetOf(a.GfxDriverDisplayApi, "transition");
    try std.testing.expectEqual(a.err_no_fn, display.transition(0, 0, &outcome));
    try std.testing.expect(outcome.generation == 0x100000008 and outcome.retained == 1);
}

var now_ticks: u64 = 100;
var activity_waits: u32 = 0;
var clipboard_revision: u32 = 7;
var present_count: u32 = 0;
var draw_count: u32 = 0;
var alpha8_count: u32 = 0;
var alpha8_x: i32 = 0;
var alpha8_y: i32 = 0;
var alpha8_width: u32 = 0;
var alpha8_height: u32 = 0;
var alpha8_stride: u32 = 0;
var alpha8_first: u8 = 0;
var frame_begin_count: u32 = 0;
var frame_append_count: u32 = 0;
var frame_commit_count: u32 = 0;
var frame_cancel_count: u32 = 0;
var frame_append_fail_at: u32 = 0;
var captured_command_count: usize = 0;
var captured_resource_len: usize = 0;
var captured_commands = [_]r4os.abi.GuiFrameCommand{.{}} ** 128;
var captured_resources: [8192]u8 = .{0} ** 8192;
var raster_count: u32 = 0;
var event_index: usize = 0;

const raw_events = [_]r4os.abi.GuiEvent{
    .{ .kind = @intFromEnum(r4os.abi.GuiEventKind.resize), .window_id = 4, .tick = 10 },
    .{ .kind = @intFromEnum(r4os.abi.GuiEventKind.key_down), .window_id = 4, .key = 'A', .modifiers = 2, .tick = 11 },
    .{ .kind = @intFromEnum(r4os.abi.GuiEventKind.mouse_down), .window_id = 4, .x = 8, .y = 9, .buttons = 1, .tick = 12 },
    .{ .kind = @intFromEnum(r4os.abi.GuiEventKind.mouse_up), .window_id = 4, .x = 10, .y = 11, .tick = 13 },
    .{ .kind = @intFromEnum(r4os.abi.GuiEventKind.mouse_move), .window_id = 4, .x = 12, .y = 13, .tick = 14 },
    .{ .kind = @intFromEnum(r4os.abi.GuiEventKind.close), .window_id = 4, .tick = 15 },
};

fn fakeWrite(bytes: [*]const u8, length: u32) callconv(.c) i32 {
    _ = bytes;
    return @intCast(length);
}

fn fakePutc(byte: u8) callconv(.c) void {
    _ = byte;
}

fn fakeTicks() callconv(.c) u64 {
    return now_ticks;
}

fn fakeTimeState(out: *r4os.abi.TimeState) callconv(.c) void {
    out.* = .{ .monotonic_ticks = now_ticks, .monotonic_hz = 1000, .valid = 1 };
}

fn fakeShouldClose(context: *const r4os.abi.R4XStartContext) callconv(.c) u32 {
    _ = context;
    return 0;
}

fn fakeWindowId() callconv(.c) i32 {
    return 4;
}

fn fakeWindowInfo(out: *r4os.abi.GuiWindowInfo) callconv(.c) i32 {
    out.* = .{ .window_id = 4, .client_w = 320, .client_h = 200 };
    return 0;
}

fn fakePollEvent(out: *r4os.abi.GuiEvent) callconv(.c) i32 {
    if (event_index >= raw_events.len) return 0;
    out.* = raw_events[event_index];
    event_index += 1;
    return 1;
}

fn fakeSetTitle(title: [*:0]const u8) callconv(.c) i32 {
    return if (std.mem.eql(u8, std.mem.span(title), "Test")) 0 else -1;
}

fn fakeSetMinSize(width: i32, height: i32) callconv(.c) i32 {
    return if (width == 100 and height == 80) 0 else -1;
}

fn fakeClipboardRevision() callconv(.c) u32 {
    return clipboard_revision;
}

fn fakeActivityWait(last_sequence: u64, timeout_ticks: u64, out_sequence: *u64) callconv(.c) i32 {
    activity_waits += 1;
    now_ticks +|= timeout_ticks;
    out_sequence.* = last_sequence;
    return 0;
}

fn fakeClear(rgb: u32) callconv(.c) i32 {
    _ = rgb;
    draw_count += 1;
    return 0;
}

fn fakeRect(x: i32, y: i32, width: u32, height: u32, rgb: u32) callconv(.c) i32 {
    _ = x;
    _ = y;
    _ = width;
    _ = height;
    _ = rgb;
    draw_count += 1;
    return 0;
}

fn fakeText(x: i32, y: i32, text: [*:0]const u8, fg: u32, bg: u32) callconv(.c) i32 {
    _ = x;
    _ = y;
    _ = text;
    _ = fg;
    _ = bg;
    draw_count += 1;
    return 0;
}

fn fakeTextEx(x: i32, y: i32, text: [*:0]const u8, fg: u32, bg: u32, font_id: u32, flags: u32) callconv(.c) i32 {
    _ = font_id;
    _ = flags;
    return fakeText(x, y, text, fg, bg);
}

fn fakeBlit(x: i32, y: i32, width: u32, height: u32, scale: u32, pixels: [*]const u32, pixel_count: u32) callconv(.c) i32 {
    _ = x;
    _ = y;
    _ = scale;
    _ = pixels;
    if (@as(u64, width) * @as(u64, height) > pixel_count) return -3;
    raster_count += 1;
    draw_count += 1;
    return 0;
}

fn fakeAlpha8(x: i32, y: i32, width: u32, height: u32, stride: u32, rgb: u32, alpha: [*]const u8, alpha_len: u32) callconv(.c) i32 {
    _ = rgb;
    if (alpha_len < width) return -1;
    alpha8_count += 1;
    alpha8_x = x;
    alpha8_y = y;
    alpha8_width = width;
    alpha8_height = height;
    alpha8_stride = stride;
    alpha8_first = alpha[0];
    return 0;
}

fn fakePresent() callconv(.c) i32 {
    present_count += 1;
    return 0;
}

fn fakeFrameBegin() callconv(.c) i32 {
    frame_begin_count += 1;
    return r4os.abi.gui_frame_result_ok;
}

fn fakeFrameAppend(commands: ?[*]const r4os.abi.GuiFrameCommand, command_count: u64, resources: ?[*]const u8, resource_len: u64) callconv(.c) i32 {
    if ((commands == null and command_count != 0) or (resources == null and resource_len != 0)) return r4os.abi.gui_frame_error_invalid;
    frame_append_count += 1;
    if (frame_append_fail_at != 0 and frame_append_count == frame_append_fail_at) return r4os.abi.gui_frame_error_oom;
    const command_len = std.math.cast(usize, command_count) orelse return r4os.abi.gui_frame_error_overflow;
    const resource_bytes = std.math.cast(usize, resource_len) orelse return r4os.abi.gui_frame_error_overflow;
    if (command_len > captured_commands.len - captured_command_count or resource_bytes > captured_resources.len - captured_resource_len) return r4os.abi.gui_frame_error_overflow;
    const source_resources: []const u8 = if (resource_bytes == 0) &.{} else resources.?[0..resource_bytes];
    for (if (command_len == 0) (&[_]r4os.abi.GuiFrameCommand{})[0..] else commands.?[0..command_len]) |source| {
        if (source.resource_bytes == 0 and source.resource_offset != 0) return r4os.abi.gui_frame_error_invalid;
        if (source.resource_bytes != 0) {
            const end = std.math.add(u64, source.resource_offset, source.resource_bytes) catch return r4os.abi.gui_frame_error_overflow;
            if (end > resource_len) return r4os.abi.gui_frame_error_invalid;
        }
        var command = source;
        if (command.resource_bytes != 0) command.resource_offset += captured_resource_len;
        captured_commands[captured_command_count] = command;
        captured_command_count += 1;
    }
    @memcpy(captured_resources[captured_resource_len .. captured_resource_len + resource_bytes], source_resources);
    captured_resource_len += resource_bytes;
    return r4os.abi.gui_frame_result_ok;
}

fn fakeFrameCommit() callconv(.c) i32 {
    frame_commit_count += 1;
    return r4os.abi.gui_frame_result_ok;
}

fn fakeFrameCancel() callconv(.c) i32 {
    frame_cancel_count += 1;
    return r4os.abi.gui_frame_result_ok;
}

fn resetFrameCapture() void {
    frame_append_count = 0;
    frame_append_fail_at = 0;
    captured_command_count = 0;
    captured_resource_len = 0;
    @memset(captured_commands[0..], .{});
    @memset(captured_resources[0..], 0);
}

fn fakeFrameInfo(handle: ?*const r4os.abi.ProgramProcessHandle, out: *r4os.abi.GuiFrameInfo) callconv(.c) i32 {
    if (out.version < r4os.abi.gui_frame_info_version or out.size < r4os.abi.gui_frame_info_size) return r4os.abi.gui_frame_error_invalid;
    out.* = .{ .owner = if (handle) |value| value.* else .{}, .committed_generation = 7, .committed_command_count = 1, .committed_resource_bytes = 4 };
    return r4os.abi.gui_frame_result_ok;
}

fn fakeFrameRead(handle: *const r4os.abi.ProgramProcessHandle, expected_generation: u64, commands: ?[*]r4os.abi.GuiFrameCommand, command_capacity: u64, resources: ?[*]u8, resource_capacity: u64, out: *r4os.abi.GuiFrameInfo) callconv(.c) i32 {
    _ = handle;
    if (out.version < r4os.abi.gui_frame_info_version or out.size < r4os.abi.gui_frame_info_size) return r4os.abi.gui_frame_error_invalid;
    out.* = .{ .committed_generation = 7, .committed_command_count = 1, .committed_resource_bytes = 4 };
    if (expected_generation != 7) return r4os.abi.gui_frame_error_stale;
    if (command_capacity < 1 or resource_capacity < 4) return r4os.abi.gui_frame_error_buffer_too_small;
    commands.?[0] = .{ .kind = r4os.abi.gui_frame_command_kind_text, .resource_bytes = 4 };
    @memcpy(resources.?[0..4], "R4OS");
    return r4os.abi.gui_frame_result_ok;
}

fn makeTables(draw_available: bool) struct { r4os.abi.R4XStartR4Sys, r4os.abi.R4XStartR4Desk, r4os.abi.R4XStartR4Draw } {
    var sys: r4os.abi.R4XStartR4Sys = .{};
    sys.write = @intFromPtr(&fakeWrite);
    sys.putc = @intFromPtr(&fakePutc);
    sys.ticks = @intFromPtr(&fakeTicks);
    sys.time_state = @intFromPtr(&fakeTimeState);
    var desk: r4os.abi.R4XStartR4Desk = .{};
    desk.program_window_id = @intFromPtr(&fakeWindowId);
    desk.gui_window_info = @intFromPtr(&fakeWindowInfo);
    desk.gui_poll_event = @intFromPtr(&fakePollEvent);
    desk.gui_set_title = @intFromPtr(&fakeSetTitle);
    desk.gui_set_min_size = @intFromPtr(&fakeSetMinSize);
    desk.clipboard_revision = @intFromPtr(&fakeClipboardRevision);
    desk.desktop_activity_wait = @intFromPtr(&fakeActivityWait);
    var draw: r4os.abi.R4XStartR4Draw = .{};
    draw.gui_clear = @intFromPtr(&fakeClear);
    draw.gui_rect = @intFromPtr(&fakeRect);
    draw.gui_draw_text = @intFromPtr(&fakeText);
    draw.gui_draw_text_ex = @intFromPtr(&fakeTextEx);
    draw.gui_blit = @intFromPtr(&fakeBlit);
    draw.gui_blend_alpha8 = @intFromPtr(&fakeAlpha8);
    if (draw_available) draw.gui_present = @intFromPtr(&fakePresent);
    return .{ sys, desk, draw };
}

fn enableFrameContract(draw: *r4os.abi.R4XStartR4Draw) void {
    draw.gui_frame_begin = @intFromPtr(&fakeFrameBegin);
    draw.gui_frame_append = @intFromPtr(&fakeFrameAppend);
    draw.gui_frame_commit = @intFromPtr(&fakeFrameCommit);
    draw.gui_frame_cancel = @intFromPtr(&fakeFrameCancel);
    draw.gui_frame_info = @intFromPtr(&fakeFrameInfo);
    draw.gui_frame_read = @intFromPtr(&fakeFrameRead);
}

fn readCapturedXrgb(command: r4os.abi.GuiFrameCommand, pixel_index: usize) u32 {
    const start: usize = @intCast(command.resource_offset + pixel_index * 4);
    return @as(u32, captured_resources[start]) |
        (@as(u32, captured_resources[start + 1]) << 8) |
        (@as(u32, captured_resources[start + 2]) << 16);
}

fn replayCaptured(width: usize, height: usize, output: []u32) void {
    std.debug.assert(output.len == width * height);
    for (captured_commands[0..captured_command_count]) |command| switch (command.kind) {
        r4os.abi.gui_frame_command_kind_clear => @memset(output, command.rgb & 0x00FF_FFFF),
        r4os.abi.gui_frame_command_kind_rect => {
            const left: usize = @intCast(@max(0, command.x));
            const top: usize = @intCast(@max(0, command.y));
            const right = @min(width, left + command.w);
            const bottom = @min(height, top + command.h);
            for (top..bottom) |row| @memset(output[row * width + left .. row * width + right], command.rgb & 0x00FF_FFFF);
        },
        r4os.abi.gui_frame_command_kind_raster => {
            if (command.parameter0 != 1) continue;
            for (0..@as(usize, @intCast(command.h))) |row| for (0..@as(usize, @intCast(command.w))) |column| {
                const target_x = command.x + @as(i32, @intCast(column));
                const target_y = command.y + @as(i32, @intCast(row));
                if (target_x < 0 or target_y < 0 or target_x >= width or target_y >= height) continue;
                output[@as(usize, @intCast(target_y)) * width + @as(usize, @intCast(target_x))] = readCapturedXrgb(command, row * command.w + column);
            };
        },
        r4os.abi.gui_frame_command_kind_alpha8 => {
            const start: usize = @intCast(command.resource_offset);
            for (0..@as(usize, @intCast(command.h))) |row| for (0..@as(usize, @intCast(command.w))) |column| {
                const target_x = command.x + @as(i32, @intCast(column));
                const target_y = command.y + @as(i32, @intCast(row));
                if (target_x < 0 or target_y < 0 or target_x >= width or target_y >= height) continue;
                const alpha = captured_resources[start + row * command.w + column];
                if (alpha == 255) output[@as(usize, @intCast(target_y)) * width + @as(usize, @intCast(target_x))] = command.rgb & 0x00FF_FFFF;
            };
        },
        else => {},
    };
}

fn makeApp(tables: anytype, imports: *[3]r4os.abi.R4XStartImport, context: *r4os.abi.R4XStartContext) !r4os.App {
    imports.* = .{
        .{ .group_id = @intFromEnum(r4os.abi.R4LGroup.r4sys), .flags = r4os.abi.r4xstart_import_flag_group_interface, .table = @intFromPtr(&tables[0]) },
        .{ .group_id = @intFromEnum(r4os.abi.R4LGroup.r4desk), .flags = r4os.abi.r4xstart_import_flag_group_interface, .table = @intFromPtr(&tables[1]) },
        .{ .group_id = @intFromEnum(r4os.abi.R4LGroup.r4draw), .flags = r4os.abi.r4xstart_import_flag_group_interface, .table = @intFromPtr(&tables[2]) },
    };
    context.* = .{
        .app_class = @intFromEnum(r4os.abi.R4XStartAppClass.gui),
        .flags = r4os.abi.r4xstart_flag_imports_valid,
        .imports = @intFromPtr(imports),
        .import_count = imports.len,
        .should_close = @intFromPtr(&fakeShouldClose),
    };
    return switch (r4os.App.init(context, .desktop)) {
        .value => |app| app,
        .failure => error.AppInit,
    };
}

test "raw GUI events become typed messages and paint presents once" {
    event_index = 0;
    draw_count = 0;
    alpha8_count = 0;
    present_count = 0;
    var tables = makeTables(true);
    var imports: [3]r4os.abi.R4XStartImport = undefined;
    var context: r4os.abi.R4XStartContext = undefined;
    var app = try makeApp(&tables, &imports, &context);
    var timers: [1]r4os.Timer = .{.{}};
    var window = app.window(timers[0..]) orelse return error.WindowMissing;
    try std.testing.expectEqual(@as(i32, 0), window.setTitle("Test"));
    try std.testing.expectEqual(@as(i32, 0), window.setMinimumSize(100, 80));

    switch (window.pollMessage().?) {
        .resize => |message| try std.testing.expect(message.width == 320 and message.height == 200),
        else => return error.Resize,
    }
    switch (window.pollMessage().?) {
        .key => |message| try std.testing.expect(message.key == 'A' and message.codepoint == 'A' and message.modifiers == 2),
        else => return error.Key,
    }
    switch (window.pollMessage().?) {
        .mouse => |message| try std.testing.expect(message.action == .down and message.x == 8),
        else => return error.Mouse,
    }
    switch (window.pollMessage().?) {
        .mouse => |message| try std.testing.expect(message.action == .up),
        else => return error.Mouse,
    }
    switch (window.pollMessage().?) {
        .mouse => |message| try std.testing.expect(message.action == .move),
        else => return error.Mouse,
    }
    switch (window.pollMessage().?) {
        .close => |id| try std.testing.expectEqual(@as(i32, 4), id),
        else => return error.Close,
    }

    var paint = switch (window.beginPaint()) {
        .paint => |value| value,
        .failure => return error.Paint,
    };
    _ = paint.canvas.clear(0);
    _ = paint.canvas.rect(.{ .x = 1, .y = 2, .w = 3, .h = 4 }, 0xFFFFFF);
    const alpha8 = [_]u8{ 10, 20, 30, 99, 40, 50, 60 };
    try std.testing.expectEqual(@as(i32, 0), paint.canvas.blendAlpha8(-1, -1, 3, 2, 4, 0x336699, alpha8[0..]));
    try std.testing.expectEqual(@as(u32, 1), alpha8_count);
    try std.testing.expectEqual(@as(i32, 0), alpha8_x);
    try std.testing.expectEqual(@as(i32, 0), alpha8_y);
    try std.testing.expectEqual(@as(u32, 2), alpha8_width);
    try std.testing.expectEqual(@as(u32, 1), alpha8_height);
    try std.testing.expectEqual(@as(u32, 4), alpha8_stride);
    try std.testing.expectEqual(@as(u8, 50), alpha8_first);
    try std.testing.expectEqual(@as(i32, 0), paint.present());
    try std.testing.expectEqual(@as(i32, r4os.abi.err_no_fn), paint.present());
    try std.testing.expect(draw_count >= 2 and present_count == 1);
}

test "command clipboard timer wait and missing draw capability stay explicit" {
    event_index = raw_events.len;
    now_ticks = 100;
    activity_waits = 0;
    clipboard_revision = 7;
    var tables = makeTables(true);
    var imports: [3]r4os.abi.R4XStartImport = undefined;
    var context: r4os.abi.R4XStartContext = undefined;
    var app = try makeApp(&tables, &imports, &context);
    var timers: [1]r4os.Timer = .{.{}};
    var window = app.window(timers[0..]) orelse return error.WindowMissing;

    try std.testing.expect(window.events.postCommand(.init(42)));
    switch (window.pollMessage().?) {
        .command => |id| try std.testing.expectEqual(@as(u32, 42), id.value),
        else => return error.Command,
    }
    clipboard_revision = 8;
    switch (window.pollMessage().?) {
        .clipboard => |message| try std.testing.expectEqual(@as(u32, 8), message.revision),
        else => return error.Clipboard,
    }
    try std.testing.expect(timers[0].start(&window.sys, .init(9), .{ .nanoseconds = 2_000_000 }, false));
    switch (window.waitMessage(r4os.time_contract.timeoutFinite(.{ .nanoseconds = 10_000_000 }))) {
        .message => |message| switch (message) {
            .timer => |timer| try std.testing.expectEqual(@as(u32, 9), timer.id.value),
            else => return error.Timer,
        },
        else => return error.TimerWait,
    }
    try std.testing.expect(activity_waits > 0);
    try std.testing.expect(window.waitMessage(r4os.time_contract.timeoutPoll()) == .timed_out);

    var missing_tables = makeTables(false);
    var missing_imports: [3]r4os.abi.R4XStartImport = undefined;
    var missing_context: r4os.abi.R4XStartContext = undefined;
    var missing_app = try makeApp(&missing_tables, &missing_imports, &missing_context);
    try std.testing.expect(missing_app.window(timers[0..]) == null);
}

test "transactional paint and immutable snapshot use the complete frame facade" {
    frame_begin_count = 0;
    frame_commit_count = 0;
    frame_cancel_count = 0;
    resetFrameCapture();
    var tables = makeTables(true);
    enableFrameContract(&tables[2]);
    var imports: [3]r4os.abi.R4XStartImport = undefined;
    var context: r4os.abi.R4XStartContext = undefined;
    var app = try makeApp(&tables, &imports, &context);
    var timers: [1]r4os.Timer = .{.{}};
    var window = app.window(timers[0..]) orelse return error.WindowMissing;
    try std.testing.expect(window.draw.supportsGuiFrameContract());

    var direct = switch (r4os.app_gui.beginPaintForSize(&window.draw, 333, 201)) {
        .paint => |value| value,
        .failure => return error.Paint,
    };
    try std.testing.expectEqual(@as(i32, 333), direct.canvas.w);
    try std.testing.expectEqual(@as(i32, 201), direct.canvas.h);
    direct.discard();
    try std.testing.expectEqual(@as(u32, 1), frame_begin_count);
    try std.testing.expectEqual(@as(u32, 1), frame_cancel_count);

    var full_hd = switch (r4os.app_gui.beginPaintForSize(&window.draw, 1920, 1080)) {
        .paint => |value| value,
        .failure => return error.Paint,
    };
    try std.testing.expectEqual(@as(i32, 1920), full_hd.canvas.w);
    try std.testing.expectEqual(@as(i32, 1080), full_hd.canvas.h);
    try std.testing.expectEqual(r4os.gui.Rect{ .w = 1920, .h = 1080 }, full_hd.canvas.bounds());
    full_hd.discard();
    try std.testing.expectEqual(@as(u32, 2), frame_begin_count);
    try std.testing.expectEqual(@as(u32, 2), frame_cancel_count);

    var paint = switch (window.beginPaint()) {
        .paint => |value| value,
        .failure => return error.Paint,
    };
    const command = [_]r4os.abi.GuiFrameCommand{.{ .kind = r4os.abi.gui_frame_command_kind_text, .resource_bytes = 4 }};
    try std.testing.expectEqual(@as(i32, 0), window.draw.guiFrameAppend(command[0..], "R4OS"));
    try std.testing.expectEqual(@as(i32, 0), paint.present());
    try std.testing.expectEqual(@as(u32, 3), frame_begin_count);
    try std.testing.expectEqual(@as(u32, 1), frame_commit_count);

    const handle = r4os.abi.ProgramProcessHandle{ .instance_id = 4, .generation = 9 };
    var info: r4os.abi.GuiFrameInfo = .{};
    info.version = 0;
    info.size = 0;
    try std.testing.expectEqual(@as(i32, 0), window.draw.guiFrameInfo(&handle, &info));
    try std.testing.expectEqual(r4os.abi.gui_frame_info_version, info.version);
    try std.testing.expectEqual(r4os.abi.gui_frame_info_size, info.size);
    var commands: [1]r4os.abi.GuiFrameCommand = .{.{}};
    var resources: [4]u8 = undefined;
    info.version = 0;
    info.size = 0;
    try std.testing.expectEqual(@as(i32, 0), window.draw.guiFrameRead(&handle, info.committed_generation, commands[0..], resources[0..], &info));
    try std.testing.expectEqualStrings("R4OS", resources[0..]);

    var cancelled = switch (window.beginPaint()) {
        .paint => |value| value,
        .failure => return error.Paint,
    };
    cancelled.discard();
    try std.testing.expectEqual(@as(u32, 3), frame_cancel_count);
}

test "buffered Canvas keeps pixels identical while collapsing draw transitions" {
    frame_begin_count = 0;
    frame_commit_count = 0;
    frame_cancel_count = 0;
    draw_count = 0;
    alpha8_count = 0;
    raster_count = 0;
    resetFrameCapture();
    var tables = makeTables(true);
    enableFrameContract(&tables[2]);
    var imports: [3]r4os.abi.R4XStartImport = undefined;
    var context: r4os.abi.R4XStartContext = undefined;
    var app = try makeApp(&tables, &imports, &context);
    var timers: [1]r4os.Timer = .{.{}};
    var window = app.window(timers[0..]) orelse return error.WindowMissing;
    var paint = switch (r4os.app_gui.beginPaintForSize(&window.draw, 4, 3)) {
        .paint => |value| value,
        .failure => return error.Paint,
    };
    defer paint.discard();

    var command_buffer: [8]r4os.abi.GuiFrameCommand = undefined;
    var resource_buffer: [64]u8 = undefined;
    var builder: r4os.FrameCanvas = undefined;
    const canvas = paint.bufferedCanvas(&builder, command_buffer[0..], resource_buffer[0..]);
    try std.testing.expectEqual(@as(i32, 0), canvas.clear(0));
    try std.testing.expectEqual(@as(i32, 0), canvas.rect(.{ .x = 2, .y = 1, .w = 2, .h = 1 }, 0xCC0000));
    const raster = [_]u32{ 0xAA112233, 0xFF445566 };
    try std.testing.expectEqual(@as(i32, 0), canvas.raster(0, 0, 2, 1, 1, raster[0..]));
    const alpha = [_]u8{ 0, 255, 77, 255, 0 };
    try std.testing.expectEqual(@as(i32, 0), canvas.blendAlpha8(0, 1, 2, 2, 3, 0xFFFFFF, alpha[0..]));
    // A resource-less command after resource-bearing commands must retain the
    // ABI-mandated zero resource offset instead of inheriting the cursor.
    try std.testing.expectEqual(@as(i32, 0), canvas.rect(.{ .x = 3, .y = 2, .w = 1, .h = 1 }, 0x010203));
    try std.testing.expectEqual(@as(i32, 0), paint.present());

    try std.testing.expectEqual(@as(u64, 5), builder.stats.logical_commands);
    try std.testing.expectEqual(@as(u64, 12), builder.stats.resource_bytes);
    try std.testing.expectEqual(@as(u64, 1), builder.stats.flushes);
    try std.testing.expectEqual(@as(u64, 1), builder.stats.append_calls);
    try std.testing.expectEqual(@as(u64, 0), builder.stats.direct_chunks);
    try std.testing.expectEqual(@as(u64, 0), builder.stats.legacy_calls);
    try std.testing.expectEqual(@as(u64, 1), builder.stats.drawTransitions());
    try std.testing.expectEqual(builder.stats.drawTransitions(), builder.stats.frameMutationEntries());
    try std.testing.expectEqual(@as(u32, 0), draw_count);
    try std.testing.expectEqual(@as(u32, 0), alpha8_count);
    try std.testing.expectEqual(@as(u32, 0), raster_count);
    try std.testing.expectEqual(@as(u32, 1), frame_commit_count);
    try std.testing.expectEqual(@as(usize, 5), captured_command_count);
    try std.testing.expectEqual(@as(usize, 12), captured_resource_len);
    try std.testing.expectEqual(@as(u64, 0), captured_commands[4].resource_offset);
    try std.testing.expectEqual(@as(u64, 0), captured_commands[4].resource_bytes);
    try std.testing.expectEqualSlices(u8, &.{ 0x33, 0x22, 0x11, 0, 0x66, 0x55, 0x44, 0 }, captured_resources[0..8]);
    try std.testing.expectEqualSlices(u8, &.{ 0, 255, 255, 0 }, captured_resources[8..12]);

    var pixels: [12]u32 = undefined;
    replayCaptured(4, 3, pixels[0..]);
    const expected = [_]u32{
        0x112233, 0x445566, 0,        0,
        0,        0xFFFFFF, 0xCC0000, 0xCC0000,
        0xFFFFFF, 0,        0,        0x010203,
    };
    try std.testing.expectEqualSlices(u32, expected[0..], pixels[0..]);
    try std.testing.expectEqual(
        std.hash.Wyhash.hash(0, std.mem.sliceAsBytes(expected[0..])),
        std.hash.Wyhash.hash(0, std.mem.sliceAsBytes(pixels[0..])),
    );
}

test "buffered Canvas covers widgets partial flush direct fallback and old tables" {
    frame_begin_count = 0;
    frame_commit_count = 0;
    frame_cancel_count = 0;
    draw_count = 0;
    present_count = 0;
    resetFrameCapture();
    var tables = makeTables(true);
    enableFrameContract(&tables[2]);
    var imports: [3]r4os.abi.R4XStartImport = undefined;
    var context: r4os.abi.R4XStartContext = undefined;
    var app = try makeApp(&tables, &imports, &context);
    var timers: [1]r4os.Timer = .{.{}};
    var window = app.window(timers[0..]) orelse return error.WindowMissing;

    var paint = switch (window.beginPaint()) {
        .paint => |value| value,
        .failure => return error.Paint,
    };
    defer paint.discard();
    var commands: [3]r4os.abi.GuiFrameCommand = undefined;
    var resources: [4]u8 = undefined;
    var builder: r4os.FrameCanvas = undefined;
    const canvas = paint.bufferedCanvas(&builder, commands[0..], resources[0..]);
    var scratch: [32]u8 = undefined;
    try std.testing.expect(canvas.button(.{ .rect = .{ .x = 4, .y = 4, .w = 60, .h = 20 }, .text = "OK", .focused = true }, scratch[0..]) >= 0);
    try std.testing.expectEqual(@as(i32, 0), canvas.text(4, 30, "oversized", 0, 0xFFFFFF));
    var shape_storage: [@sizeOf(r4os.abi.GuiShapeResource)]u8 = undefined;
    const shape_resource = try r4os.gui_shapes.roundedRect(shape_storage[0..], .{ .x = 1, .y = 1, .w = 12, .h = 8, .fill_argb = 0xFF336699 });
    const shape_command = try r4os.gui_shapes.command(r4os.abi.gui_frame_command_kind_rounded_rect, 0, 0, 16, 12, 0, shape_resource.len);
    try std.testing.expectEqual(@as(i32, 0), canvas.frameCommand(shape_command, shape_resource));
    try std.testing.expectEqual(@as(i32, 0), paint.present());
    try std.testing.expect(builder.stats.logical_commands > 4);
    try std.testing.expect(builder.stats.flushes >= 1);
    try std.testing.expectEqual(@as(u64, 2), builder.stats.direct_chunks);
    try std.testing.expect(builder.stats.drawTransitions() < builder.stats.logical_commands);

    // The same facade on an old table uses the established draw calls and
    // PRESENT.  No batch operation is attempted.
    resetFrameCapture();
    draw_count = 0;
    present_count = 0;
    var legacy_tables = makeTables(true);
    var legacy_imports: [3]r4os.abi.R4XStartImport = undefined;
    var legacy_context: r4os.abi.R4XStartContext = undefined;
    var legacy_app = try makeApp(&legacy_tables, &legacy_imports, &legacy_context);
    var legacy_window = legacy_app.window(timers[0..]) orelse return error.WindowMissing;
    var legacy_paint = switch (legacy_window.beginPaint()) {
        .paint => |value| value,
        .failure => return error.Paint,
    };
    defer legacy_paint.discard();
    var legacy_builder: r4os.FrameCanvas = undefined;
    const legacy_canvas = legacy_paint.bufferedCanvas(&legacy_builder, commands[0..], resources[0..]);
    try std.testing.expectEqual(@as(i32, 0), legacy_canvas.clear(0));
    try std.testing.expectEqual(@as(i32, 0), legacy_canvas.rect(.{ .x = 1, .y = 1, .w = 2, .h = 2 }, 1));
    try std.testing.expectEqual(@as(i32, 0), legacy_canvas.text(1, 1, "old", 1, 0));
    try std.testing.expectEqual(@as(i32, 0), legacy_paint.present());
    try std.testing.expectEqual(@as(u64, 3), legacy_builder.stats.legacy_calls);
    try std.testing.expectEqual(@as(u64, 3), legacy_builder.stats.drawTransitions());
    try std.testing.expectEqual(@as(u32, 3), draw_count);
    try std.testing.expectEqual(@as(u32, 1), present_count);
    try std.testing.expectEqual(@as(u32, 0), frame_append_count);
}

test "buffered Canvas cancels a transactional frame after a partial flush failure" {
    frame_begin_count = 0;
    frame_commit_count = 0;
    frame_cancel_count = 0;
    resetFrameCapture();
    frame_append_fail_at = 2;
    var tables = makeTables(true);
    enableFrameContract(&tables[2]);
    var imports: [3]r4os.abi.R4XStartImport = undefined;
    var context: r4os.abi.R4XStartContext = undefined;
    var app = try makeApp(&tables, &imports, &context);
    var timers: [1]r4os.Timer = .{.{}};
    var window = app.window(timers[0..]) orelse return error.WindowMissing;
    var paint = switch (window.beginPaint()) {
        .paint => |value| value,
        .failure => return error.Paint,
    };
    defer paint.discard();
    var commands: [1]r4os.abi.GuiFrameCommand = undefined;
    var resources: [1]u8 = undefined;
    var builder: r4os.FrameCanvas = undefined;
    const canvas = paint.bufferedCanvas(&builder, commands[0..], resources[0..]);
    try std.testing.expectEqual(@as(i32, 0), canvas.rect(.{ .x = 0, .y = 0, .w = 1, .h = 1 }, 1));
    try std.testing.expectEqual(@as(i32, 0), canvas.rect(.{ .x = 1, .y = 0, .w = 1, .h = 1 }, 2));
    try std.testing.expectEqual(@as(i32, r4os.abi.gui_frame_error_oom), canvas.rect(.{ .x = 2, .y = 0, .w = 1, .h = 1 }, 3));
    try std.testing.expectEqual(@as(i32, r4os.abi.gui_frame_error_oom), paint.present());
    try std.testing.expectEqual(@as(u32, 2), frame_append_count);
    try std.testing.expectEqual(@as(u32, 0), frame_commit_count);
    try std.testing.expectEqual(@as(u32, 1), frame_cancel_count);
    try std.testing.expectEqual(@as(u64, 1), builder.stats.failed_calls);
    try std.testing.expectEqual(@as(i32, r4os.abi.err_no_fn), paint.present());
}
