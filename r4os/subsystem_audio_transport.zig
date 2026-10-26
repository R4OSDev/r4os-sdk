//! One owned native Async Service request per stream. The interactive caller
//! only submits/polls; no worker or additional PCM backlog is introduced.
const std = @import("std");
const abi = @import("r4os_contract").abi;
const audio = @import("app_audio.zig");
const services = @import("app_services.zig");
const r4sys = @import("r4sys.zig");
const time = @import("time_contract.zig");

pub const pending: i32 = -9603;
pub const Operation = enum { open, write, volume, close, fence };
pub const Completion = struct { operation: Operation, request_id: u32, generation: u64, result: i32 };
pub const Finish = struct { completion: ?Completion = null, error_code: i32 = 0, control_requests: u32 = 0 };

pub const Transport = struct {
    sys: r4sys.Context,
    timeout: time.Timeout,
    close_timeout: time.Timeout,
    connection: ?services.ServiceConnection = null,
    stream_id: u32 = 0,
    frame_bytes: usize = 0,
    generation: u64 = 0,
    request_id: u32 = 0,
    operation: Operation = .open,
    request_generation: u64 = 0,
    payload: [abi.service_api_max_payload]u8 = undefined,
    header: abi.ServiceMessageHeader = .{},
    response: abi.AudioServiceStreamResult = .{},
    status: abi.AudioServiceStatus = .{},
    copied_bytes: usize = 0,
    // A timed-out Open has no usable stream ID. AUDSVC abandons that lazy
    // session when its reply fails; a same-endpoint status reply fences it.
    uncertain_open: bool = false,

    pub fn create(sys: r4sys.Context, timeout: time.Timeout, close_timeout: time.Timeout) ?*Transport {
        const p = sys.allocator().create(Transport) catch return null;
        p.* = .{ .sys = sys, .timeout = timeout, .close_timeout = close_timeout };
        return p;
    }

    pub fn open(self: *Transport, rate: u32, channels: u16, fixed: u32) i32 {
        if (self.request_id != 0 or self.stream_id != 0 or self.uncertain_open) return abi.service_api_result_busy;
        if (self.generation == std.math.maxInt(u64)) return abi.service_api_result_invalid;
        if (rate == 0 or rate > 192000 or channels == 0 or channels > 2) return abi.service_api_result_invalid;
        if (self.connection == null) {
            const facade = services.Services{ .sys = self.sys };
            self.connection = switch (facade.open("AUDSVC")) {
                .connection => |c| c,
                .failure => |code| return code,
            };
        }
        self.generation += 1;
        self.frame_bytes = @as(usize, channels) * 2;
        const request = abi.AudioServiceStreamOpenRequest{ .rate = rate, .channels = channels, .format = @intFromEnum(audio.PcmFormat.s16le), .fixed_volume = fixed };
        @memcpy(self.payload[0..@sizeOf(@TypeOf(request))], std.mem.asBytes(&request));
        const rc = self.submit(.open, @sizeOf(@TypeOf(request)), self.timeout);
        if (rc == pending) self.uncertain_open = true;
        return rc;
    }

    pub fn write(self: *Transport, bytes: []const u8) i32 {
        if (self.request_id != 0) return abi.service_api_result_busy;
        if (self.stream_id == 0) return abi.err_closed;
        if (self.frame_bytes == 0 or bytes.len == 0 or bytes.len % self.frame_bytes != 0) return abi.service_api_result_invalid;
        const limit = @min(bytes.len, audio.max_write_payload);
        self.copied_bytes = limit - limit % self.frame_bytes;
        const request = abi.AudioServiceStreamWriteRequest{ .stream_id = self.stream_id, .byte_count = @intCast(self.copied_bytes) };
        const header_bytes = @sizeOf(@TypeOf(request));
        @memcpy(self.payload[0..header_bytes], std.mem.asBytes(&request));
        @memcpy(self.payload[header_bytes..][0..self.copied_bytes], bytes[0..self.copied_bytes]);
        return self.submit(.write, header_bytes + self.copied_bytes, self.timeout);
    }

    pub fn volume(self: *Transport, fixed: u32) i32 {
        if (self.request_id != 0) return abi.service_api_result_busy;
        if (self.stream_id == 0) return abi.err_closed;
        const request = abi.AudioServiceStreamControlRequest{ .stream_id = self.stream_id, .fixed_volume = fixed };
        @memcpy(self.payload[0..@sizeOf(@TypeOf(request))], std.mem.asBytes(&request));
        return self.submit(.volume, @sizeOf(@TypeOf(request)), self.timeout);
    }

    pub fn close(self: *Transport) i32 {
        return self.closeWithTimeout(self.close_timeout);
    }

    fn closeWithTimeout(self: *Transport, budget: time.Timeout) i32 {
        if (self.request_id != 0) return abi.service_api_result_busy;
        if (self.stream_id == 0) {
            if (self.uncertain_open) return self.submit(.fence, 0, budget);
            return 0;
        }
        const request = abi.AudioServiceStreamControlRequest{ .stream_id = self.stream_id };
        @memcpy(self.payload[0..@sizeOf(@TypeOf(request))], std.mem.asBytes(&request));
        return self.submit(.close, @sizeOf(@TypeOf(request)), budget);
    }

    fn submit(self: *Transport, operation: Operation, len: usize, timeout: time.Timeout) i32 {
        if (self.request_id != 0) return abi.service_api_result_busy;
        const connection = &(self.connection orelse return abi.err_closed);
        const budget = time.timeoutToTicks(timeout, self.sys.monotonicHz()) catch return abi.service_api_result_invalid;
        self.operation = operation;
        self.request_generation = self.generation;
        self.header = .{};
        self.response = .{};
        self.status = .{};
        const response = if (operation == .fence) std.mem.asBytes(&self.status) else std.mem.asBytes(&self.response);
        const rc = self.sys.ioServiceCall(connection.raw, wireOp(operation), self.payload[0..len], &self.header, response, budget, 0, &self.request_id);
        if (rc != abi.io_ok) {
            self.request_id = 0;
            return rc;
        }
        return pending;
    }

    /// A caller timeout is not permission to recycle this exact storage. Even
    /// terminal publication is followed by actual ioClose/retirement success.
    pub fn poll(self: *Transport) ?Completion {
        if (self.request_id == 0) return null;
        var info: abi.ProgramIoInfo = .{};
        const rc = self.sys.ioStatus(self.request_id, &info);
        // Transient status contention is not a zero-byte write receipt. Do
        // not retire a concurrently completed request without reading it.
        if (rc != abi.io_ok and rc != abi.io_error_not_found) return null;
        if (rc == abi.io_ok and info.state != abi.io_state_completed and info.state != abi.io_state_failed) return null;
        const closed = self.sys.ioClose(self.request_id);
        if (closed != abi.io_ok and closed != abi.io_error_not_found) return null;
        const id = self.request_id;
        self.request_id = 0;
        const result = if (rc != abi.io_ok) rc else if (info.request_id != id or info.kind != abi.io_kind_service_call or self.request_generation != self.generation)
            abi.service_api_result_invalid
        else if (info.state != abi.io_state_completed and info.result >= 0) abi.service_api_result_invalid else if (info.result < 0) info.result else self.decode(info.result);
        return .{ .operation = if (self.operation == .fence) .close else self.operation, .request_id = id, .generation = self.request_generation, .result = result };
    }

    fn decode(self: *Transport, bytes: i32) i32 {
        if (self.header.magic != abi.service_api_magic or self.header.version != abi.service_api_version or self.header.op != wireOp(self.operation) or self.header.request_id == 0) return abi.service_api_result_invalid;
        if (self.header.status != abi.service_api_result_ok) return if (self.header.status < 0) self.header.status else abi.service_api_result_invalid;
        if (self.operation == .fence) {
            if (bytes != @sizeOf(abi.AudioServiceStatus) or self.status.magic != abi.audio_service_status_magic or self.status.version != abi.audio_service_status_version) return abi.service_api_result_invalid;
            self.uncertain_open = false;
            return 0;
        }
        if (bytes != @sizeOf(abi.AudioServiceStreamResult) or self.response.magic != abi.audio_service_result_magic or self.response.version != abi.audio_service_result_version or self.response.action != wireOp(self.operation)) return abi.service_api_result_invalid;
        if (self.response.result < 0) return self.response.result;
        if (self.operation == .open) {
            if (self.response.stream_id == 0) return abi.service_api_result_invalid;
            self.stream_id = self.response.stream_id;
            self.uncertain_open = false;
            return 0;
        }
        if (self.response.stream_id != self.stream_id or self.stream_id == 0) return abi.service_api_result_invalid;
        if (self.operation == .write) {
            const accepted = self.response.bytes;
            if (accepted == 0 or accepted > self.copied_bytes or accepted % self.frame_bytes != 0 or self.response.result != accepted) return abi.service_api_result_invalid;
            return @intCast(accepted);
        }
        if (self.response.result != 0) return abi.service_api_result_invalid;
        if (self.operation == .close) self.stream_id = 0;
        return 0;
    }

    fn drain(self: *Transport) Completion {
        while (true) {
            if (self.poll()) |value| return value;
            var info: abi.ProgramIoInfo = .{};
            _ = self.sys.ioWait(self.request_id, abi.io_wait_forever, &info);
            if (self.request_id != 0) self.sys.sleepTicks(1);
        }
    }

    /// Terminal shutdown only. The original finite RPC budget and an unlimited
    /// wait for actual buffer release are separate. Close retries consume one
    /// absolute drain budget; a failed remote close is returned, never success.
    pub fn finish(self: *Transport) Finish {
        var result = Finish{};
        if (self.request_id != 0) result.completion = self.drain();
        const started = self.sys.ticks();
        const ticks = time.timeoutToTicks(self.close_timeout, self.sys.monotonicHz()) catch 0;
        while (self.stream_id != 0 or self.uncertain_open) {
            const elapsed = self.sys.ticks() -| started;
            const remaining = if (ticks == abi.io_wait_forever) ticks else ticks -| elapsed;
            if (remaining == 0) {
                result.error_code = abi.service_api_result_timeout;
                break;
            }
            const duration = time.durationFromTicks(remaining, self.sys.monotonicHz()) catch time.Duration{};
            const budget = if (remaining == abi.io_wait_forever) time.timeoutForever() else time.timeoutFinite(duration);
            const submitted = self.closeWithTimeout(budget);
            if (submitted == pending) result.control_requests += 1;
            const code = if (submitted == pending) self.drain().result else submitted;
            if (code == 0) break;
            if (code != abi.service_api_result_busy and code != abi.service_api_result_timeout) {
                result.error_code = code;
                break;
            }
            self.sys.sleepTicks(1);
        }
        std.debug.assert(self.request_id == 0);
        if (self.connection) |*c| {
            const closed = c.close();
            if (closed != 0 and closed != abi.err_closed and result.error_code == 0) result.error_code = if (closed < 0) closed else abi.service_api_result_invalid;
        }
        const allocator = self.sys.allocator();
        allocator.destroy(self);
        return result;
    }
};

fn wireOp(operation: Operation) u16 {
    return switch (operation) {
        .open => abi.audio_service_op_open_stream,
        .write => abi.audio_service_op_write_stream,
        .volume => abi.audio_service_op_set_stream_volume,
        .close => abi.audio_service_op_close_stream,
        .fence => abi.audio_service_op_status,
    };
}

// Explicitly modeled native tables exercise the actual request owner. No host
// test here claims native endpoint scheduling, cancellation or hardware work.
const Probe = struct {
    var table: abi.R4XStartR4Sys = .{};
    var raw: abi.R4XStartContext = .{};
    var bundle: @import("program.zig").Bundle = undefined;
    var next_id: u32 = 400;
    var state: u32 = abi.io_state_running;
    var result: i32 = @sizeOf(abi.AudioServiceStreamResult);
    var close_busy: bool = false;
    var status_busy: bool = false;
    var closes: usize = 0;
    var header: *abi.ServiceMessageHeader = undefined;
    var response: [*]u8 = undefined;
    var operation: u16 = 0;
    fn context() r4sys.Context {
        table = .{};
        raw = .{};
        next_id = 400;
        state = abi.io_state_running;
        result = @sizeOf(abi.AudioServiceStreamResult);
        close_busy = false;
        status_busy = false;
        closes = 0;
        table.monotonic_clock = @intFromPtr(&clock);
        table.io_service_call = @intFromPtr(&submit);
        table.io_status = @intFromPtr(&status);
        table.io_close = @intFromPtr(&close);
        bundle = .{ .raw = &raw, .sys = &table };
        return r4sys.Context.init(&bundle);
    }
    fn clock(out: *abi.MonotonicClockInfo) callconv(.c) i32 {
        out.* = .{ .event_effective_hz = 1000 };
        return 1;
    }
    fn submit(handle: u32, op: u16, _: [*]const u8, _: u32, h: *abi.ServiceMessageHeader, bytes: [*]u8, _: u32, _: u64, _: u32, id: *u32) callconv(.c) i32 {
        std.debug.assert(handle == 11);
        next_id += 1;
        id.* = next_id;
        header = h;
        response = bytes;
        operation = op;
        return 0;
    }
    fn status(id: u32, out: *abi.ProgramIoInfo) callconv(.c) i32 {
        if (status_busy) return abi.io_error_busy;
        out.* = .{ .request_id = id, .kind = abi.io_kind_service_call, .state = state, .result = result };
        return 0;
    }
    fn close(_: u32) callconv(.c) i32 {
        closes += 1;
        return if (close_busy) abi.io_error_busy else 0;
    }
    fn reply(stream_id: u32, accepted: u32) void {
        header.* = .{ .op = operation, .request_id = 91 };
        const value = abi.AudioServiceStreamResult{ .action = operation, .stream_id = stream_id, .result = @intCast(accepted), .bytes = accepted };
        @memcpy(response[0..@sizeOf(@TypeOf(value))], std.mem.asBytes(&value));
        state = abi.io_state_completed;
    }
    fn stream() Transport {
        const sys = context();
        return .{ .sys = sys, .timeout = time.timeoutFinite(.{ .nanoseconds = 200000000 }), .close_timeout = time.timeoutFinite(.{ .nanoseconds = 500000000 }), .connection = .{ .sys = sys, .raw = 11, .owned = true }, .stream_id = 77, .frame_bytes = 4, .generation = 9 };
    }
};

test "one actual transport request copies PCM and retains all buffers through terminal close BUSY" {
    var owner = Probe.stream();
    var bytes = [_]u8{0x19} ** 1920;
    try std.testing.expectEqual(pending, owner.write(&bytes));
    @memset(&bytes, 0x72);
    try std.testing.expect(std.mem.allEqual(u8, owner.payload[@sizeOf(abi.AudioServiceStreamWriteRequest)..][0..1920], 0x19));
    try std.testing.expectEqual(abi.service_api_result_busy, owner.write(&bytes));
    Probe.status_busy = true;
    try std.testing.expect(owner.poll() == null and Probe.closes == 0);
    Probe.status_busy = false;
    try std.testing.expect(owner.poll() == null and Probe.closes == 0);
    Probe.reply(77, 960);
    Probe.close_busy = true;
    try std.testing.expect(owner.poll() == null and owner.request_id == 401);
    try std.testing.expectEqual(abi.service_api_result_busy, owner.close());
    Probe.close_busy = false;
    const receipt = owner.poll().?;
    try std.testing.expectEqual(@as(i32, 960), receipt.result);
    try std.testing.expectEqual(@as(u64, 9), receipt.generation);
    try std.testing.expectEqual(@as(u32, 401), receipt.request_id);
    try std.testing.expect(owner.request_id == 0 and owner.poll() == null);
}

test "actual transport rejects wrong stream partial frame and generation after exact release" {
    for (0..4) |variant| {
        var owner = Probe.stream();
        const bytes = [_]u8{0x22} ** 1920;
        try std.testing.expectEqual(pending, owner.write(&bytes));
        Probe.reply(if (variant == 0) 78 else 77, if (variant == 1) 959 else 960);
        if (variant == 2) owner.request_generation -= 1;
        if (variant == 3) Probe.state = abi.io_state_failed;
        try std.testing.expectEqual(abi.service_api_result_invalid, owner.poll().?.result);
        try std.testing.expect(owner.request_id == 0 and Probe.closes == 1);
    }
}

test "timed out actual Open is fenced on its original endpoint before reusing the stream" {
    var owner = Probe.stream();
    owner.stream_id = 0;
    try std.testing.expectEqual(pending, owner.open(48000, 2, audio.default_volume));
    Probe.state = abi.io_state_failed;
    Probe.result = abi.service_api_result_timeout;
    try std.testing.expectEqual(abi.service_api_result_timeout, owner.poll().?.result);
    try std.testing.expect(owner.uncertain_open);
    try std.testing.expectEqual(abi.service_api_result_busy, owner.open(48000, 2, audio.default_volume));
    try std.testing.expectEqual(pending, owner.close());
    try std.testing.expectEqual(abi.audio_service_op_status, Probe.operation);
    Probe.header.* = .{ .op = Probe.operation, .request_id = 92 };
    const status = abi.AudioServiceStatus{};
    @memcpy(Probe.response[0..@sizeOf(@TypeOf(status))], std.mem.asBytes(&status));
    Probe.state = abi.io_state_completed;
    Probe.result = @sizeOf(@TypeOf(status));
    const receipt = owner.poll().?;
    try std.testing.expectEqual(Operation.close, receipt.operation);
    try std.testing.expectEqual(@as(i32, 0), receipt.result);
    try std.testing.expect(!owner.uncertain_open and owner.stream_id == 0 and owner.request_id == 0);
}
