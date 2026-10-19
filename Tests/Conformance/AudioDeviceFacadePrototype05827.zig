const std = @import("std");
const r4os = @import("r4os");

var sys_table: r4os.abi.R4XStartR4Sys = .{};
var audio_table: r4os.abi.R4XStartR4Audio = .{};
var dev_table: r4os.abi.R4XStartR4Dev = .{};
var context: r4os.abi.R4XStartContext = .{};
var timeout_next = false;
var stream_open = false;
var open_connections: u32 = 0;

fn fakeCpuLifecycle(op: u32, cpu: u32, epoch: u64, out: *r4os.abi.CpuLifecycleInfo) callconv(.c) i32 {
    std.debug.assert(op == 2 and cpu == 63 and epoch == 0x1234_5678_85ab_cdef);
    out.epoch = epoch + 1;
    return -63;
}
fn fakeCpuLifecycleCheck(out: *r4os.abi.ProgramKernelCpuLifecycleCheck) callconv(.c) i32 {
    out.new_epoch = 0x1234_5678_85ab_cdf0;
    return 1;
}
test "CPU lifecycle facades negotiate both optional slots and forward full epochs without truncation" {
    const a = r4os.abi;
    const t = std.testing;
    const facade = initFacades().devices.raw;
    var info: a.CpuLifecycleInfo = .{ .epoch = 71 };
    var report: a.ProgramKernelCpuLifecycleCheck = .{ .new_epoch = 72 };
    dev_table.cpu_lifecycle = @intFromPtr(&fakeCpuLifecycle);
    dev_table.kernel_cpu_lifecycle_check = @intFromPtr(&fakeCpuLifecycleCheck);
    for ([_]u32{ 552, 553, 559 }) |size| {
        dev_table.size = size;
        try t.expectEqual(a.err_no_fn, facade.cpuLifecycle(2, 63, 0x1234_5678_85ab_cdef, &info));
        try t.expectEqual(@as(u64, 71), info.epoch);
    }
    dev_table.size = 560;
    try t.expectEqual(@as(i32, -63), facade.cpuLifecycle(2, 63, 0x1234_5678_85ab_cdef, &info));
    try t.expectEqual(@as(u64, 0x1234_5678_85ab_cdf0), info.epoch);
    try t.expectEqual(a.err_no_fn, facade.kernelCpuLifecycleCheck(&report));
    try t.expectEqual(@as(u64, 72), report.new_epoch);
    dev_table.size = 568;
    try t.expectEqual(@as(i32, 1), facade.kernelCpuLifecycleCheck(&report));
    dev_table.cpu_lifecycle = 0; dev_table.kernel_cpu_lifecycle_check = 0;
    try t.expectEqual(a.err_no_fn, facade.cpuLifecycle(2, 63, 0x1234_5678_85ab_cdef, &info));
    try t.expectEqual(a.err_no_fn, facade.kernelCpuLifecycleCheck(&report));
}

fn fakeInstrumentation(out: *r4os.abi.ProgramInstrumentationInfo) callconv(.c) i32 {
    if (out.version != 1 or out.size != @sizeOf(r4os.abi.ProgramInstrumentationInfo)) return -1;
    out.* = .{ .mode = 0, .lock_count = 11, .stack_group_count = 13 };
    return 1;
}

fn fakeLock(index: u32, out: *r4os.abi.ProgramLockPerformanceInfo) callconv(.c) i32 {
    if (out.version != 1 or out.size != @sizeOf(r4os.abi.ProgramLockPerformanceInfo)) return -1;
    if (index >= 11) return 0;
    out.* = .{ .index = index, .acquisitions = 17 };
    return 1;
}

fn fakeStack(index: u32, out: *r4os.abi.ProgramStackPerformanceInfo) callconv(.c) i32 {
    if (out.version != 1 or out.size != @sizeOf(r4os.abi.ProgramStackPerformanceInfo)) return -1;
    if (index >= 13) return 0;
    out.* = .{ .index = index, .created = 9 };
    return 1;
}

fn fakeStackFault(index: u32, out: *r4os.abi.ProgramStackFaultInfo) callconv(.c) i32 {
    if (out.version != 1 or out.size < @sizeOf(r4os.abi.ProgramStackFaultInfo)) return -1;
    if (index >= 4) return 0;
    out.* = .{ .cpu_index = index, .sequence = 2,
        .flags = r4os.abi.stack_fault_flag_task, .task_id = 71, .task_generation = 93 };
    return 1;
}

test "stack fault view preserves output for old tables, end and invalid headers" {
    const facades = initFacades();
    const performance = facades.devices.performance();
    var out: r4os.abi.ProgramStackFaultInfo = .{ .task_id = 123 };
    try std.testing.expectEqual(r4os.abi.err_no_fn, performance.stackFault(0, &out));
    try std.testing.expectEqual(@as(u32, 123), out.task_id);
    dev_table.stack_fault = @intFromPtr(&fakeStackFault);
    try std.testing.expectEqual(@as(i32, 1), performance.stackFault(3, &out));
    try std.testing.expectEqual(@as(u32, 71), out.task_id);
    try std.testing.expectEqual(@as(u64, 93), out.task_generation);
    try std.testing.expectEqual(@as(i32, 0), performance.stackFault(4, &out));
    try std.testing.expectEqual(@as(u32, 71), out.task_id);
    out.version = 0;
    try std.testing.expectEqual(@as(i32, -1), performance.stackFault(0, &out));
    try std.testing.expectEqual(@as(u32, 71), out.task_id);
    dev_table.size = @offsetOf(r4os.abi.R4XStartR4Dev, "stack_fault");
    try std.testing.expectEqual(r4os.abi.err_no_fn, performance.stackFault(0, &out));
    try std.testing.expectEqual(@as(u32, 71), out.task_id);
}

test "instrumentation views distinguish missing slots, end of list and disabled details" {
    const facades = initFacades();
    const performance = facades.devices.performance();
    try std.testing.expect(performance.instrumentation() == null);
    dev_table.performance_instrumentation = @intFromPtr(&fakeInstrumentation);
    dev_table.performance_lock = @intFromPtr(&fakeLock);
    dev_table.performance_stack = @intFromPtr(&fakeStack);
    try std.testing.expectEqual(@as(u32, 0), performance.instrumentation().?.mode);
    try std.testing.expectEqual(@as(u64, 17), performance.lock(10).?.acquisitions);
    try std.testing.expectEqual(@as(u64, 9), performance.stack(12).?.created);
    try std.testing.expect(performance.lock(11) == null);
    try std.testing.expect(performance.stack(13) == null);
    dev_table.size = @offsetOf(r4os.abi.R4XStartR4Dev, "performance_instrumentation");
    try std.testing.expect(performance.instrumentation() == null);
    try std.testing.expect(performance.lock(0) == null);
    try std.testing.expect(performance.stack(0) == null);
}

fn fakeServiceOpen(_: [*:0]const u8, out: *r4os.abi.ServiceInfo) callconv(.c) i32 {
    out.* = .{ .handle = 77 };
    open_connections += 1;
    return r4os.abi.service_api_result_ok;
}

fn fakeServiceClose(handle: u32) callconv(.c) i32 {
    if (handle != 77 or open_connections == 0) return r4os.abi.service_api_result_bad_handle;
    open_connections -= 1;
    return r4os.abi.service_api_result_ok;
}

fn copyResponse(response: [*]u8, capacity: u32, value: *const r4os.abi.AudioServiceStreamResult) i32 {
    if (capacity < @sizeOf(r4os.abi.AudioServiceStreamResult)) return r4os.abi.service_api_result_buffer_too_small;
    @memcpy(response[0..@sizeOf(r4os.abi.AudioServiceStreamResult)], std.mem.asBytes(value));
    return @sizeOf(r4os.abi.AudioServiceStreamResult);
}

fn fakeServiceCall(_: u32, op: u16, request: [*]const u8, request_len: u32, header: *r4os.abi.ServiceMessageHeader, response: [*]u8, capacity: u32, _: u64) callconv(.c) i32 {
    header.* = .{ .op = op, .status = r4os.abi.service_api_result_ok };
    if (timeout_next) {
        timeout_next = false;
        return r4os.abi.service_api_result_timeout;
    }
    var result = r4os.abi.AudioServiceStreamResult{ .action = op, .result = 0, .stream_id = 91 };
    switch (op) {
        r4os.abi.audio_service_op_open_stream => stream_open = true,
        r4os.abi.audio_service_op_write_stream => {
            if (!stream_open or request_len < @sizeOf(r4os.abi.AudioServiceStreamWriteRequest)) result.result = -1 else {
                var wire: r4os.abi.AudioServiceStreamWriteRequest = .{};
                @memcpy(std.mem.asBytes(&wire), request[0..@sizeOf(r4os.abi.AudioServiceStreamWriteRequest)]);
                result.bytes = wire.byte_count;
                result.result = @intCast(wire.byte_count);
            }
        },
        r4os.abi.audio_service_op_set_stream_volume => if (!stream_open) {
            result.result = -1;
        },
        r4os.abi.audio_service_op_close_stream => if (stream_open) {
            stream_open = false;
        } else {
            result.result = -1;
        },
        else => result.result = r4os.abi.service_api_result_bad_op,
    }
    return copyResponse(response, capacity, &result);
}

fn fakeAudioOpen(_: u32, _: u16, _: u16) callconv(.c) i32 {
    return 1;
}
fn fakeSidAcquire() callconv(.c) i32 {
    return 11;
}
fn fakeSidWrite(_: u32, _: u8, _: u8) callconv(.c) i32 {
    return 0;
}
fn fakeSidRelease(_: u32) callconv(.c) i32 {
    return 0;
}
fn fakeMidiOpen(_: [*:0]const u8) callconv(.c) i32 {
    return 12;
}
fn fakeMidiSend(_: u32, _: u8, _: u8, _: u8, _: u8) callconv(.c) i32 {
    return 0;
}
fn fakeMidiClose(_: u32) callconv(.c) i32 {
    return 0;
}
fn fakeOplWrite(_: u8, _: u8, _: u8) callconv(.c) i32 {
    return 0;
}
fn fakeOplSimple() callconv(.c) i32 {
    return 0;
}

fn fakeInventorySummary(out: *r4os.abi.DeviceInventorySummary) callconv(.c) i32 {
    out.* = .{ .total = 2, .with_driver = 1, .without_driver = 1 };
    return 1;
}
fn fakeInventoryRecord(index: u32, out: *r4os.abi.DeviceInventoryRecord) callconv(.c) i32 {
    out.* = .{ .bus = @intCast(index + 1) };
    return 1;
}
fn fakeMemorySummary(out: *r4os.abi.ProgramMemorySummary) callconv(.c) i32 {
    out.* = .{ .physical_bytes = 64 * 1024 * 1024 };
    return 0;
}
fn fakeMemoryCount() callconv(.c) u32 {
    return 3;
}
fn fakeMemoryBlock(index: u32, out: *r4os.abi.ProgramMemoryBlockInfo) callconv(.c) i32 {
    out.* = .{ .id = index };
    return 1;
}
fn fakePressure(out: *r4os.abi.ProgramMemoryPressureSnapshot) callconv(.c) i32 {
    out.* = .{ .pressure_level = r4os.abi.memory_pressure_level_normal };
    return 1;
}
fn fakePerformance(out: *r4os.abi.ProgramPerformanceSummary) callconv(.c) i32 {
    out.* = .{ .audio_stream_writes = 9 };
    return 1;
}
fn fakeProgramInstanceStorageLegacy(out: *r4os.abi.ProgramInstanceStorageSummary) callconv(.c) i32 {
    @memset(@as([*]u8, @ptrCast(out))[0..256], 0);
    out.version = 1;
    out.size = 256;
    out.active_instances = 4;
    out.active_service_instances = 2;
    out.current_payload_bytes = 4096;
    out.payload_allocations = 11;
    out.payload_releases = 7;
    return 1;
}
fn fakeProgramInstanceStorageV2(out: *r4os.abi.ProgramInstanceStorageSummary) callconv(.c) i32 {
    if (out.version < 2 or out.size < @sizeOf(r4os.abi.ProgramInstanceStorageSummary)) return -1;
    out.* = .{ .active_instances = 4, .active_service_instances = 2, .current_payload_bytes = 4096, .payload_allocations = 11, .payload_releases = 7, .current_gui_frame_bytes = 8192 };
    return 1;
}
fn fakeProgramInstanceStorageSelfTest(out: *r4os.abi.ProgramInstanceStorageSelfTestResult) callconv(.c) i32 {
    out.* = .{ .cases = 27, .passed_cases = 27, .flags = 0xF, .allocation_failures_before = 2, .allocation_failures_after = 4 };
    return 1;
}
fn fakeExecutionInventory(out: *r4os.abi.ProgramInventorySummary) callconv(.c) i32 {
    out.* = .{
        .version = r4os.abi.program_inventory_version,
        .size = @sizeOf(r4os.abi.ProgramInventorySummary),
        .program_total = 17,
        .task_total = 29,
        .thread_total = 23,
        .program_peak = 41,
    };
    return r4os.abi.program_handle_ok;
}
fn fakePerformanceTask(index: u32, out: *r4os.abi.ProgramTaskPerformanceInfo) callconv(.c) i32 {
    out.* = .{ .id = index };
    return 1;
}
fn fakePerformanceStorage(index: u32, out: *r4os.abi.ProgramStoragePerformanceInfo) callconv(.c) i32 {
    out.* = .{ .index = index };
    return 1;
}
fn fakePerformanceBoot(_: u32, out: *r4os.abi.ProgramBootPhasePerformanceInfo) callconv(.c) i32 {
    out.* = .{};
    return 1;
}
fn fakeHardware(out: *r4os.abi.HardwareSummary) callconv(.c) i32 {
    out.* = .{ .cpu_logical_processors = 4 };
    return 1;
}

fn initFacades() struct { audio: r4os.Audio, devices: r4os.Devices } {
    sys_table = .{};
    sys_table.service_open = @intFromPtr(&fakeServiceOpen);
    sys_table.service_close = @intFromPtr(&fakeServiceClose);
    sys_table.service_call = @intFromPtr(&fakeServiceCall);
    audio_table = .{};
    audio_table.audio_open_stream = @intFromPtr(&fakeAudioOpen);
    audio_table.sid_acquire = @intFromPtr(&fakeSidAcquire);
    audio_table.sid_write_register = @intFromPtr(&fakeSidWrite);
    audio_table.sid_release = @intFromPtr(&fakeSidRelease);
    audio_table.midi_open_synth = @intFromPtr(&fakeMidiOpen);
    audio_table.midi_send = @intFromPtr(&fakeMidiSend);
    audio_table.midi_close = @intFromPtr(&fakeMidiClose);
    audio_table.opl3_write_register = @intFromPtr(&fakeOplWrite);
    audio_table.opl3_reset = @intFromPtr(&fakeOplSimple);
    audio_table.opl3_render_block = @intFromPtr(&fakeOplSimple);
    audio_table.opl3_stop = @intFromPtr(&fakeOplSimple);
    dev_table = .{};
    dev_table.device_inventory_summary = @intFromPtr(&fakeInventorySummary);
    dev_table.device_inventory_record = @intFromPtr(&fakeInventoryRecord);
    dev_table.memory_summary = @intFromPtr(&fakeMemorySummary);
    dev_table.memory_block_count = @intFromPtr(&fakeMemoryCount);
    dev_table.memory_block = @intFromPtr(&fakeMemoryBlock);
    dev_table.memory_pressure_snapshot = @intFromPtr(&fakePressure);
    dev_table.performance_summary = @intFromPtr(&fakePerformance);
    dev_table.program_instance_storage_summary = @intFromPtr(&fakeProgramInstanceStorageLegacy);
    dev_table.program_instance_storage_summary_v2 = @intFromPtr(&fakeProgramInstanceStorageV2);
    dev_table.program_instance_storage_self_test = @intFromPtr(&fakeProgramInstanceStorageSelfTest);
    dev_table.execution_inventory_summary = @intFromPtr(&fakeExecutionInventory);
    dev_table.performance_task = @intFromPtr(&fakePerformanceTask);
    dev_table.performance_storage = @intFromPtr(&fakePerformanceStorage);
    dev_table.performance_boot_phase = @intFromPtr(&fakePerformanceBoot);
    dev_table.hardware_summary = @intFromPtr(&fakeHardware);
    dev_table.display_state = @intFromPtr(&fakeDisplayState);
    const bundle = r4os.program.Bundle{ .raw = &context, .sys = &sys_table, .audio = &audio_table, .dev = &dev_table };
    const sys = r4os.r4sys.Context.init(&bundle);
    return .{
        .audio = .{ .sys = sys, .raw = r4os.r4audio.Context.init(&bundle) },
        .devices = .{ .raw = r4os.r4dev.Context.init(&bundle) },
    };
}

fn fakeDisplayState(out: *r4os.abi.DisplayStateInfo) callconv(.c) i32 {
    if (out.version != 1 or out.size < @sizeOf(r4os.abi.DisplayStateInfo)) return -1;
    out.* = .{ .state = r4os.abi.display_state_bootfb, .device_generation = 7, .policy = r4os.abi.display_policy_software_once };
    return 1;
}

test "PCM lifecycle validates format timeout progress and double close" {
    stream_open = false;
    open_connections = 0;
    timeout_next = false;
    var facades = initFacades();
    try std.testing.expect(facades.audio.available());
    const invalid_format: r4os.PcmFormat = @enumFromInt(2);
    try std.testing.expect(switch (facades.audio.openStream(48_000, 2, invalid_format, r4os.app_audio.default_volume, r4os.time_contract.timeoutPoll())) {
        .failure => |raw| raw == r4os.abi.service_api_result_invalid,
        else => false,
    });
    timeout_next = true;
    try std.testing.expect(switch (facades.audio.openStream(48_000, 2, .s16le, r4os.app_audio.default_volume, r4os.time_contract.timeoutPoll())) {
        .timed_out => true,
        else => false,
    });
    var stream = switch (facades.audio.openStream(48_000, 2, .s16le, r4os.app_audio.default_volume, r4os.time_contract.timeoutForever())) {
        .stream => |value| value,
        else => return error.Open,
    };
    var pcm: [2048]u8 = .{1} ** 2048;
    try std.testing.expectEqual(pcm.len, switch (stream.write(pcm[0..], r4os.time_contract.timeoutForever())) {
        .written => |bytes| bytes,
        else => 0,
    });
    try std.testing.expect(switch (stream.setVolume(0x8000, r4os.time_contract.timeoutForever())) {
        .ok => true,
        else => false,
    });
    try std.testing.expect(switch (stream.close(r4os.time_contract.timeoutForever())) {
        .ok => true,
        else => false,
    });
    try std.testing.expect(switch (stream.close(r4os.time_contract.timeoutForever())) {
        .failure => |raw| raw == r4os.abi.err_closed,
        else => false,
    });
    try std.testing.expectEqual(@as(u32, 0), open_connections);
}

test "advanced synth operations and R4DEV views stay explicit" {
    var facades = initFacades();
    const advanced = facades.audio.advanced();
    try std.testing.expectEqual(@as(i32, 11), advanced.sidAcquire());
    try std.testing.expectEqual(@as(i32, 0), advanced.sidWriteRegister(11, 0, 1));
    try std.testing.expectEqual(@as(i32, 12), advanced.midiOpenSynth("OPL3"));
    try std.testing.expectEqual(@as(i32, 0), advanced.midiSend(12, 0, 0x90, 60, 100));
    try std.testing.expectEqual(@as(i32, 0), advanced.opl3Reset());
    const inventory = facades.devices.inventory();
    const display_state = facades.devices.display().?;
    try std.testing.expectEqual(@as(u64, 7), display_state.device_generation);
    try std.testing.expectEqual(r4os.abi.display_policy_software_once, display_state.policy);
    const full_size = dev_table.size;
    dev_table.size = @offsetOf(r4os.abi.R4XStartR4Dev, "display_state");
    try std.testing.expectEqual(@as(?r4os.abi.DisplayStateInfo, null), facades.devices.display());
    dev_table.size = full_size;
    try std.testing.expectEqual(@as(u32, 2), inventory.summary().?.total);
    try std.testing.expectEqual(@as(u32, 4), inventory.hardware().?.cpu_logical_processors);
    const memory = facades.devices.memory();
    try std.testing.expectEqual(@as(u64, 64 * 1024 * 1024), memory.summary().?.physical_bytes);
    try std.testing.expectEqual(@as(u32, 3), memory.blockCount());
    const performance = facades.devices.performance();
    try std.testing.expectEqual(@as(u64, 9), performance.summary().?.audio_stream_writes);
    const storage = performance.programInstanceStorage().?;
    try std.testing.expectEqual(@as(u32, 2), storage.version);
    try std.testing.expectEqual(@as(u32, @sizeOf(r4os.abi.ProgramInstanceStorageSummary)), storage.size);
    try std.testing.expectEqual(@as(u32, 4), storage.active_instances);
    try std.testing.expectEqual(@as(u64, 4096), storage.current_payload_bytes);
    try std.testing.expectEqual(@as(u64, 8192), storage.current_gui_frame_bytes);
    var legacy_storage: r4os.abi.ProgramInstanceStorageSummary = undefined;
    @memset(std.mem.asBytes(&legacy_storage), 0xA5);
    try std.testing.expect(performance.raw.programInstanceStorageSummaryLegacy(&legacy_storage) > 0);
    try std.testing.expectEqual(@as(u32, 1), legacy_storage.version);
    try std.testing.expectEqual(@as(u32, 256), legacy_storage.size);
    try std.testing.expectEqual(@as(u8, 0xA5), std.mem.asBytes(&legacy_storage)[256]);
    legacy_storage.version = 3;
    legacy_storage.size = @sizeOf(r4os.abi.ProgramInstanceStorageSummary);
    try std.testing.expect(performance.raw.programInstanceStorageSummaryV2(&legacy_storage) > 0);
    try std.testing.expectEqual(@as(u32, 2), legacy_storage.version);
    @memset(std.mem.asBytes(&legacy_storage), 0xB6);
    legacy_storage.version = 0;
    legacy_storage.size = @sizeOf(r4os.abi.ProgramInstanceStorageSummary) - 1;
    try std.testing.expectEqual(@as(i32, -1), performance.raw.programInstanceStorageSummaryV2(&legacy_storage));
    try std.testing.expectEqual(@as(u32, 0), legacy_storage.version);
    try std.testing.expectEqual(@as(u32, @sizeOf(r4os.abi.ProgramInstanceStorageSummary) - 1), legacy_storage.size);
    try std.testing.expectEqual(@as(u8, 0xB6), std.mem.asBytes(&legacy_storage)[8]);
    dev_table.size = 288;
    const legacy_fallback = performance.programInstanceStorage().?;
    try std.testing.expectEqual(@as(u32, 1), legacy_fallback.version);
    try std.testing.expectEqual(@as(u32, 256), legacy_fallback.size);
    try std.testing.expectEqual(@as(u64, 0), legacy_fallback.current_gui_frame_bytes);
    var storage_test: r4os.abi.ProgramInstanceStorageSelfTestResult = .{};
    try std.testing.expect(performance.programInstanceStorageSelfTest(&storage_test) > 0);
    try std.testing.expectEqual(@as(u32, 27), storage_test.passed_cases);
    try std.testing.expectEqual(@as(u32, 0xF), storage_test.flags);
    const execution = performance.executionInventory().?;
    try std.testing.expectEqual(r4os.abi.program_inventory_version, execution.version);
    try std.testing.expectEqual(@as(u32, 17), execution.program_total);
    try std.testing.expectEqual(@as(u32, 29), execution.task_total);
    try std.testing.expectEqual(@as(u32, 23), execution.thread_total);
    var direct_execution: r4os.abi.ProgramInventorySummary = .{};
    try std.testing.expectEqual(r4os.abi.program_handle_ok, facades.devices.raw.executionInventorySummary(&direct_execution));
    try std.testing.expectEqual(@as(u32, 41), direct_execution.program_peak);
}
