//! Exclusive synchronous Query2 client for the existing DNS/TCP/UDP services.
//! Copied bounded records only. No automatic retry after uncertain mutations.
const std = @import("std");
pub const common = @import("network_common.zig");
pub const abi = common.abi;
pub const deadline = common.deadline;
pub const fromBudget = common.fromBudget;
const platform = @import("platform2.zig");
pub const Service = enum { dns, tcp, udp };
pub const Client = struct {
    call: abi.R4SysFns.service_call,
    close_call: abi.R4SysFns.service_close,
    handle: u32,
    service: Service,
    timeout_ticks: u64 = 500,
    pub fn connect(context: *const platform.Context, service: Service, out: *Client) i32 {
        const table = context.system();
        const open = platform.abi.function(platform.abi.R4SysFns2, table, "service_open") orelse return abi.err_no_fn;
        const call = platform.abi.function(platform.abi.R4SysFns2, table, "service_call") orelse return abi.err_no_fn;
        const close_call = platform.abi.function(platform.abi.R4SysFns2, table, "service_close") orelse return abi.err_no_fn;
        const name: [*:0]const u8 = switch (service) {
            .dns => "DNSSVC",
            .tcp => "TCPSVC",
            .udp => "UDPSVC",
        };
        var endpoint: abi.ServiceInfo = .{};
        const rc = open(name, &endpoint);
        if (rc != 0) return rc;
        if (endpoint.handle == 0) return abi.service_api_result_no_endpoint;
        out.* = .{ .call = call, .close_call = close_call, .handle = endpoint.handle, .service = service };
        return 0;
    }
    pub fn close(self: *Client) i32 {
        if (self.handle == 0) return abi.network_error_bad_socket;
        const rc = self.close_call(self.handle);
        if (rc >= 0) self.handle = 0;
        return rc;
    }
    fn rpc(self: *const Client, op: u16, request: []const u8, response: []u8) i32 {
        if (self.handle == 0) return abi.network_error_bad_socket;
        var header: abi.ServiceMessageHeader = .{};
        const rc = self.call(self.handle, op, request.ptr, @intCast(request.len), &header, response.ptr, @intCast(response.len), self.timeout_ticks);
        if (rc < 0) return rc;
        if (header.status == abi.service_api_result_bad_op) return abi.err_no_fn;
        if (header.status != 0) return if (header.status < 0) header.status else abi.network_error_invalid;
        return rc;
    }
    pub fn info(self: *const Client, out: *abi.NetworkProviderInfo) i32 {
        var bytes: [@sizeOf(abi.NetworkProviderInfo)]u8 = undefined;
        const rc = self.rpc(abi.network_op_info, "", &bytes);
        if (rc < 0) return rc;
        const value = common.record(abi.NetworkProviderInfo, bytes[0..@intCast(@min(rc, bytes.len))]) catch return abi.network_error_invalid;
        if (rc != bytes.len or value.provider == 0 or value.reserved != 0 or value.capabilities & ~@as(u64, 4095) != 0 or value.max_send > 3968 or value.max_recv > 4008 or value.max_answers > 32 or value.page_capacity > 16) return abi.network_error_invalid;
        out.* = value;
        return 0;
    }
    /// Read/Recv return payload in data_out. Write/Send return an accepted byte
    /// prefix in result.bytes and no payload. Result/output stay untouched on
    /// malformed/negative replies. Caller retains every unaccepted suffix.
    pub fn socket(self: *const Client, op: u16, request: abi.NetworkSocketRequest, data_in: []const u8, data_out: []u8, out: *abi.NetworkSocketResult) i32 {
        if (self.service == .dns or op < abi.network_op_connect or op > abi.network_op_accept or op == abi.network_op_resolve or request.version != 1 or request.size != @sizeOf(@TypeOf(request)) or request.provider == 0 or data_in.len > 3968 or data_out.len > 4008) return abi.network_error_invalid;
        const sending = op == abi.network_op_write or op == abi.network_op_send;
        const receiving = op == abi.network_op_read or op == abi.network_op_recv;
        if (data_in.len != (if (sending) request.bytes else @as(u32, 0)) or receiving and request.bytes > data_out.len) return abi.network_error_invalid;
        var payload: [4096]u8 = undefined;
        @memcpy(payload[0..@sizeOf(@TypeOf(request))], std.mem.asBytes(&request));
        @memcpy(payload[@sizeOf(@TypeOf(request))..][0..data_in.len], data_in);
        var response: [4096]u8 = undefined;
        const rc = self.rpc(op, payload[0 .. @sizeOf(@TypeOf(request)) + data_in.len], &response);
        if (rc < 0) return rc;
        if (rc < @sizeOf(abi.NetworkSocketResult) or rc > response.len) return abi.network_error_invalid;
        const value = common.record(abi.NetworkSocketResult, response[0..@sizeOf(abi.NetworkSocketResult)]) catch return abi.network_error_invalid;
        if (value.provider != request.provider or value.socket == 0 or value.generation == 0 or request.socket != 0 and (value.socket != request.socket or value.generation != request.generation) or !common.endpointValid(value.endpoint) or value.state < 1 or value.state > 6 or value.flags & ~@as(u32, abi.network_flag_truncated) != 0) return abi.network_error_invalid;
        if (value.bytes > request.bytes or value.original_bytes < value.bytes or rc != @sizeOf(abi.NetworkSocketResult) + (if (receiving) value.bytes else @as(u32, 0))) return abi.network_error_invalid;
        if (op != abi.network_op_recv and (value.flags != 0 or value.original_bytes != value.bytes) or op == abi.network_op_recv and ((value.flags & abi.network_flag_truncated != 0) != (value.original_bytes > value.bytes))) return abi.network_error_invalid;
        if (receiving) @memcpy(data_out[0..value.bytes], response[@sizeOf(abi.NetworkSocketResult)..][0..value.bytes]);
        out.* = value;
        return 0;
    }
    pub fn resolve(self: *const Client, request: abi.NetworkResolveRequest, answers: []abi.NetworkResolveAnswer, out: *abi.NetworkResolvePage) i32 {
        if (self.service != .dns or request.capacity == 0 or request.capacity > 16 or request.capacity > answers.len) return abi.network_error_invalid;
        var response: [4096]u8 = undefined;
        const rc = self.rpc(abi.network_op_resolve, std.mem.asBytes(&request), &response);
        if (rc < 0) return rc;
        if (rc < @sizeOf(abi.NetworkResolvePage) or rc > response.len) return abi.network_error_invalid;
        const page = common.record(abi.NetworkResolvePage, response[0..@sizeOf(abi.NetworkResolvePage)]) catch return abi.network_error_invalid;
        if (page.provider != request.provider or page.provider == 0 or page.query == 0 or request.query != 0 and page.query != request.query or page.expires_ns == 0 or page.total == 0 or page.total > 32 or page.count == 0 or page.count > request.capacity or request.cursor > page.total or page.count > page.total - request.cursor or page.next != request.cursor + page.count or page.flags != (if (page.next < page.total) @as(u32, abi.network_flag_more) else 0) or rc != @sizeOf(abi.NetworkResolvePage) + page.count * @sizeOf(abi.NetworkResolveAnswer)) return abi.network_error_invalid;
        for (0..page.count) |i| {
            var answer: abi.NetworkResolveAnswer = undefined;
            @memcpy(std.mem.asBytes(&answer), response[@sizeOf(abi.NetworkResolvePage) + i * @sizeOf(abi.NetworkResolveAnswer) ..][0..@sizeOf(abi.NetworkResolveAnswer)]);
            if (!common.addressValid(answer.address) or answer.reserved != 0 or request.query == 0 and answer.address.family != request.family) return abi.network_error_invalid;
        }
        @memcpy(std.mem.sliceAsBytes(answers[0..page.count]), response[@sizeOf(abi.NetworkResolvePage)..][0 .. page.count * @sizeOf(abi.NetworkResolveAnswer)]);
        out.* = page;
        return 0;
    }
    pub fn release(self: *const Client, provider: u64, query: u64) i32 {
        const request: abi.NetworkResolveRequest = .{ .provider = provider, .query = query, .family = 0, .capacity = 0 };
        var bytes: [1]u8 = undefined;
        const rc = self.rpc(abi.network_op_release, std.mem.asBytes(&request), &bytes);
        return if (rc <= 0) rc else abi.network_error_invalid;
    }
};
