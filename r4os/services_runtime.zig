//! Scalar SDK boundary; loop, fairness and deadline policies stay in their owners.
const std = @import("std");
const bridge = @import("net_bridge_support.zig");
const abi = bridge.abi;
const services = @import("app_services.zig");
const sys = @import("r4sys.zig");
const time = @import("time_contract.zig");
const deadline = @import("service_deadline.zig");

const Metrics = bridge.flatRecord(services.ServiceLoopMetrics);
const Loop = extern struct { endpoint_handle: u32, started_tick: u64, stop_check_ticks: u64, drain_limit: u32, metrics: Metrics };
const Batch = extern struct { announced: u32, processed: u32, done: u32 };
const Step = extern struct { kind: u32, value: i32 };
const DeadlineView = extern struct { length: usize, deadline_tick: u64, has_deadline: u32 };

fn restore(state: *const Loop, bundle: *const bridge.program.Bundle) services.ServiceLoop {
    var metrics: services.ServiceLoopMetrics = .{};
    inline for (@typeInfo(Metrics).@"struct".fields) |field| @field(metrics, field.name) = @field(state.metrics, field.name);
    return .{ .sys = sys.Context.init(bundle), .endpoint_handle = state.endpoint_handle, .started_tick = state.started_tick, .stop_check_ticks = state.stop_check_ticks, .drain_limit = state.drain_limit, .metrics = metrics };
}
fn store(state: *Loop, value: services.ServiceLoop) void {
    state.* = .{ .endpoint_handle = value.endpoint_handle, .started_tick = value.started_tick, .stop_check_ticks = value.stop_check_ticks, .drain_limit = value.drain_limit, .metrics = bridge.flatten(Metrics, value.metrics) };
}
pub export fn R4SdkServiceLoopInit(context: *const abi.R4XStartContext, endpoint: u32, stop_ms: u64, drain_limit: u32, out: *Loop) callconv(.c) i32 {
    const bundle = bridge.bundle(context) orelse return abi.err_no_group;
    if (endpoint == 0) return abi.service_api_result_bad_handle;
    store(out, services.ServiceLoop.init(sys.Context.init(&bundle), endpoint, .{ .stop_check_ms = stop_ms, .drain_limit = drain_limit }));
    return 0;
}
pub export fn R4SdkServiceLoopWait(context: *const abi.R4XStartContext, state: *Loop, has_deadline: u32, tick: u64) callconv(.c) Step {
    const bundle = bridge.bundle(context) orelse return .{ .kind = 4, .value = abi.err_no_group };
    var owner = restore(state, &bundle);
    const result = owner.wait(if (has_deadline != 0) tick else null);
    store(state, owner);
    return switch (result) { .requests => |n| .{ .kind = 0, .value = @intCast(n) }, .deadline => .{ .kind = 1, .value = 0 }, .idle => .{ .kind = 2, .value = 0 }, .stop => .{ .kind = 3, .value = 0 }, .failure => |raw| .{ .kind = 4, .value = raw } };
}
pub export fn R4SdkServiceLoopBatch(context: *const abi.R4XStartContext, state: *Loop, announced: u32, out: *Batch) callconv(.c) i32 {
    const bundle = bridge.bundle(context) orelse return abi.err_no_group;
    var owner = restore(state, &bundle);
    const batch = owner.beginBatch(announced);
    store(state, owner);
    out.* = .{ .announced = batch.announced, .processed = batch.processed, .done = @intFromBool(batch.done) };
    return 0;
}
pub export fn R4SdkServiceBatchNext(context: *const abi.R4XStartContext, state: *Loop, batch: *Batch) callconv(.c) Step {
    const bundle = bridge.bundle(context) orelse return .{ .kind = 3, .value = abi.err_no_group };
    var owner = restore(state, &bundle);
    var active = services.ServiceRequestBatch{ .loop = &owner, .announced = batch.announced, .processed = batch.processed, .done = batch.done != 0 };
    const result = active.next();
    store(state, owner);
    batch.* = .{ .announced = active.announced, .processed = active.processed, .done = @intFromBool(active.done) };
    return switch (result) { .request => .{ .kind = 0, .value = 0 }, .complete => .{ .kind = 1, .value = 0 }, .yielded => .{ .kind = 2, .value = 0 }, .failure => |raw| .{ .kind = 3, .value = raw } };
}
const Handler = *const fn (?*anyopaque) callconv(.c) i32;
fn invoke(handler: Handler, data: ?*anyopaque) i32 { return handler(data); }
pub export fn R4SdkServiceLoopDrain(context: *const abi.R4XStartContext, state: *Loop, announced: u32, handler: Handler, data: ?*anyopaque) callconv(.c) i32 {
    const bundle = bridge.bundle(context) orelse return abi.err_no_group;
    var owner = restore(state, &bundle);
    const result = owner.drain(announced, invoke, .{ handler, data });
    store(state, owner);
    return result;
}
pub export fn R4SdkServiceLoopReport(context: *const abi.R4XStartContext, state: *const Loop, name: [*]const u8, len: u32, out: [*]u8, capacity: u32) callconv(.c) i32 {
    const bundle = bridge.bundle(context) orelse return abi.err_no_group;
    const owner = restore(state, &bundle);
    const result = owner.formatReport(name[0..len], out[0..capacity]) orelse return abi.service_api_result_buffer_too_small;
    return @intCast(result.len);
}
pub export fn R4SdkServiceDetails(context: *const abi.R4XStartContext, out: [*]abi.ServiceDetail, capacity: u32) callconv(.c) i32 {
    const bundle = bridge.bundle(context) orelse return abi.err_no_group;
    const owner = sys.Context.init(&bundle);
    return switch (services.readCompleteDetails(&owner, out[0..capacity])) { .complete => |n| @intCast(n), .failure => |raw| raw };
}
pub export fn R4SdkServiceControl(context: *const abi.R4XStartContext, operation: u32, name: [*:0]const u8, path: ?[*:0]const u8, args: ?[*:0]const u8, mode: u32, description: ?[*:0]const u8, timeout_ticks: u64, out: *abi.ServiceInfo) callconv(.c) i32 {
    const bundle = bridge.bundle(context) orelse return abi.err_no_group;
    const owner = sys.Context.init(&bundle);
    return switch (operation) {
        0 => owner.serviceStatus(name, out),
        1 => owner.serviceStart(name, out),
        2 => owner.serviceStop(name, out, timeout_ticks),
        3 => owner.serviceRestart(name, out),
        4 => owner.serviceInstall(name, path orelse return abi.service_api_result_invalid, args orelse "", mode, description orelse "", out),
        5 => owner.serviceRemove(name),
        6 => owner.serviceSetStartMode(name, mode, out),
        else => abi.service_api_result_invalid,
    };
}
pub export fn R4SdkServiceInfo(context: *const abi.R4XStartContext, index: u32, out: *abi.ServiceInfo) callconv(.c) i32 {
    const bundle = bridge.bundle(context) orelse return abi.err_no_group;
    return sys.Context.init(&bundle).serviceInfo(index, out);
}
pub export fn R4SdkServiceDetail(context: *const abi.R4XStartContext, name: [*:0]const u8, out: *abi.ServiceDetail) callconv(.c) i32 {
    const bundle = bridge.bundle(context) orelse return abi.err_no_group;
    return sys.Context.init(&bundle).serviceDetailByName(name, out);
}
pub export fn R4SdkCompletedReply(raw: i32) callconv(.c) i32 { return services.completedReplyResult(raw); }
pub export fn R4SdkDeadlineAppend(out: [*]u8, capacity: u32, payload: [*]const u8, len: u32, tick: u64) callconv(.c) i32 {
    const result = deadline.append(out[0..capacity], payload[0..len], tick) orelse return abi.service_api_result_buffer_too_small;
    return @intCast(result.len);
}
pub export fn R4SdkDeadlineSplit(payload: [*]const u8, len: u32) callconv(.c) DeadlineView {
    const result = deadline.split(payload[0..len]);
    return .{ .length = result.payload.len, .deadline_tick = result.deadline_tick orelse 0, .has_deadline = @intFromBool(result.deadline_tick != null) };
}
pub export fn R4SdkDeadlineFromTimeout(timeout: abi.R4Timeout, now: u64, hz: u32, out: *u64) callconv(.c) i32 {
    out.* = deadline.deadlineFromTimeout(timeout, now, hz) catch return abi.service_api_result_invalid;
    return 0;
}
pub export fn R4SdkDeadlineRemaining(tick: u64, now: u64, hz: u32) callconv(.c) abi.R4Timeout { return deadline.remainingTimeout(tick, now, hz); }
pub export fn R4SdkDurationFromTicks(ticks: u64, hz: u32, out: *abi.R4Duration) callconv(.c) i32 {
    out.* = time.durationFromTicks(ticks, hz) catch return abi.service_api_result_invalid;
    return 0;
}
