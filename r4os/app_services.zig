const std = @import("std");
const abi = @import("r4os_contract").abi;
const r4sys = @import("r4sys.zig");
const time_contract = @import("time_contract.zig");

pub const Timeout = time_contract.Timeout;

pub const Services = struct {
    sys: r4sys.Context,

    pub fn available(self: *const Services) bool {
        return self.sys.hasFn("service_open") and self.sys.hasFn("service_close") and
            self.sys.hasFn("service_call") and self.sys.hasFn("service_endpoint_register") and
            self.sys.hasFn("service_endpoint_unregister") and self.sys.hasFn("service_endpoint_wait") and
            self.sys.hasFn("service_endpoint_recv") and self.sys.hasFn("service_endpoint_reply");
    }

    pub fn open(self: *const Services, name: [*:0]const u8) ServiceOpen {
        var info: abi.ServiceInfo = .{};
        const raw = self.sys.serviceOpen(name, &info);
        if (raw != abi.service_api_result_ok or info.handle == 0) {
            return .{ .failure = if (raw == abi.service_api_result_ok) abi.service_api_result_no_endpoint else raw };
        }
        return .{ .connection = .{ .sys = self.sys, .raw = info.handle, .owned = true, .info = info } };
    }

    pub fn register(self: *const Services, name: [*:0]const u8, flags: u32) EndpointOpen {
        var info: abi.ServiceInfo = .{};
        const raw = self.sys.serviceEndpointRegister(name, flags, &info);
        if (raw != abi.service_api_result_ok or info.handle == 0) {
            return .{ .failure = if (raw == abi.service_api_result_ok) abi.service_api_result_no_endpoint else raw };
        }
        return .{ .endpoint = .{ .sys = self.sys, .raw = info.handle, .owned = true, .info = info } };
    }
};

pub const ServiceOpen = union(enum) {
    connection: ServiceConnection,
    failure: i32,
};

pub const EndpointOpen = union(enum) {
    endpoint: ServiceEndpoint,
    failure: i32,
};

pub const ServiceResponse = struct {
    header: abi.ServiceMessageHeader,
    bytes: usize,
};

pub const ServiceCall = union(enum) {
    response: ServiceResponse,
    timed_out,
    remote_failure: i32,
    failure: i32,
};

pub fn TypedServiceCall(comptime T: type) type {
    return union(enum) {
        value: T,
        timed_out,
        remote_failure: i32,
        failure: i32,
    };
}

pub const ServiceConnection = struct {
    sys: r4sys.Context,
    raw: u32 = 0,
    owned: bool = false,
    info: abi.ServiceInfo = .{},

    pub fn valid(self: *const ServiceConnection) bool {
        return self.raw != 0;
    }

    pub fn call(self: *ServiceConnection, op: u16, request: []const u8, response: []u8, timeout: Timeout) ServiceCall {
        if (!self.valid()) return .{ .failure = abi.err_closed };
        var header: abi.ServiceMessageHeader = .{};
        const raw = self.sys.serviceCallTimeout(self.raw, op, request, &header, response, timeout);
        if (raw == abi.service_api_result_timeout) return .timed_out;
        if (raw == abi.service_api_result_bad_handle or raw == abi.service_api_result_not_running) {
            self.raw = 0;
            return .{ .failure = raw };
        }
        if (raw < 0) return .{ .failure = raw };
        if (header.status == abi.service_api_result_timeout) return .timed_out;
        if (header.status != abi.service_api_result_ok) return .{ .remote_failure = header.status };
        return .{ .response = .{ .header = header, .bytes = @intCast(raw) } };
    }

    pub fn callTyped(self: *ServiceConnection, comptime Request: type, comptime Response: type, op: u16, request: *const Request, timeout: Timeout) TypedServiceCall(Response) {
        var response: Response = undefined;
        const response_bytes = std.mem.asBytes(&response);
        return switch (self.call(op, std.mem.asBytes(request), response_bytes, timeout)) {
            .response => |result| if (result.bytes == @sizeOf(Response)) .{ .value = response } else .{ .failure = abi.service_api_result_buffer_too_small },
            .timed_out => .timed_out,
            .remote_failure => |raw| .{ .remote_failure = raw },
            .failure => |raw| .{ .failure = raw },
        };
    }

    pub fn close(self: *ServiceConnection) i32 {
        if (!self.valid()) return abi.err_closed;
        if (!self.owned) return abi.err_not_owned;
        const raw = self.sys.serviceClose(self.raw);
        if (raw == abi.service_api_result_ok or raw == abi.service_api_result_bad_handle) {
            self.raw = 0;
            self.info = .{};
            return if (raw == abi.service_api_result_ok) raw else abi.err_closed;
        }
        return raw;
    }
};

pub const EndpointWait = union(enum) {
    ready: u32,
    timed_out,
    failure: i32,
};

pub const EndpointMessage = struct {
    header: abi.ServiceMessageHeader,
    bytes: usize,
};

pub const EndpointReceive = union(enum) {
    message: EndpointMessage,
    would_block,
    failure: i32,
};

pub fn TypedEndpointReceive(comptime T: type) type {
    return union(enum) {
        message: struct { header: abi.ServiceMessageHeader, payload: T },
        would_block,
        failure: i32,
    };
}

pub const ServiceEndpoint = struct {
    sys: r4sys.Context,
    raw: u32 = 0,
    owned: bool = false,
    info: abi.ServiceInfo = .{},

    pub fn valid(self: *const ServiceEndpoint) bool {
        return self.raw != 0;
    }

    pub fn wait(self: *ServiceEndpoint, timeout: Timeout) EndpointWait {
        if (!self.valid()) return .{ .failure = abi.err_closed };
        const raw = self.sys.serviceEndpointWaitTimeout(self.raw, timeout);
        if (raw == 0) return .timed_out;
        if (raw == abi.service_api_result_bad_handle or raw == abi.service_api_result_not_running) {
            self.raw = 0;
            return .{ .failure = raw };
        }
        if (raw < 0) return .{ .failure = raw };
        return .{ .ready = @intCast(raw) };
    }

    pub fn recv(self: *ServiceEndpoint, out: []u8) EndpointReceive {
        if (!self.valid()) return .{ .failure = abi.err_closed };
        var header: abi.ServiceMessageHeader = .{};
        const raw = self.sys.serviceEndpointRecv(self.raw, &header, out);
        if (raw == 0 and header.magic != abi.service_api_magic) return .would_block;
        if (raw == abi.service_api_result_bad_handle or raw == abi.service_api_result_not_running) {
            self.raw = 0;
            return .{ .failure = raw };
        }
        if (raw < 0) return .{ .failure = raw };
        return .{ .message = .{ .header = header, .bytes = @intCast(raw) } };
    }

    pub fn recvTyped(self: *ServiceEndpoint, comptime T: type) TypedEndpointReceive(T) {
        var payload: T = undefined;
        return switch (self.recv(std.mem.asBytes(&payload))) {
            .message => |message| if (message.bytes == @sizeOf(T)) .{ .message = .{ .header = message.header, .payload = payload } } else .{ .failure = abi.service_api_result_buffer_too_small },
            .would_block => .would_block,
            .failure => |raw| .{ .failure = raw },
        };
    }

    pub fn reply(self: *ServiceEndpoint, request_id: u32, status: i32, payload: []const u8) i32 {
        if (!self.valid()) return abi.err_closed;
        const raw = self.sys.serviceEndpointReply(self.raw, request_id, status, payload);
        if (raw == abi.service_api_result_bad_handle or raw == abi.service_api_result_not_running) self.raw = 0;
        return raw;
    }

    pub fn replyTyped(self: *ServiceEndpoint, comptime T: type, request_id: u32, status: i32, payload: *const T) i32 {
        return self.reply(request_id, status, std.mem.asBytes(payload));
    }

    pub fn unregister(self: *ServiceEndpoint) i32 {
        if (!self.valid()) return abi.err_closed;
        if (!self.owned) return abi.err_not_owned;
        const raw = self.sys.serviceEndpointUnregister(self.raw);
        if (raw == abi.service_api_result_ok or raw == abi.service_api_result_bad_handle) {
            self.raw = 0;
            self.info = .{};
            return if (raw == abi.service_api_result_ok) raw else abi.err_closed;
        }
        return raw;
    }
};
