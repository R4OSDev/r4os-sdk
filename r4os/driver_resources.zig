const std = @import("std");
const abi = @import("r4os_contract").abi;

/// Non-owning references to the authenticated driver's loaded container.
/// No close is needed. Read failure can leave partial bytes in output.
pub const Context = struct {
    table: abi.DriverResourceApi,
    pub fn stat(self: *const Context, name: []const u8, output: *abi.DriverResourceInfo) i32 {
        if (!self.has("stat")) return abi.err_no_fn;
        if (name.len == 0 or name.len > 63) return abi.driver_resource_error_invalid;
        const callback: *const fn ([*]const u8, u32, *abi.DriverResourceInfo) callconv(.c) i32 = @ptrFromInt(self.table.stat);
        return callback(name.ptr, @intCast(name.len), output);
    }
    pub fn readAt(self: *const Context, handle: u64, offset: u64, output: []u8, deadline_ns: u64) i32 {
        if (!self.has("read_at")) return abi.err_no_fn;
        if (output.len == 0 or output.len > abi.driver_resource_max_read_bytes) return abi.driver_resource_error_invalid;
        const callback: *const fn (u64, u64, [*]u8, u32, u64) callconv(.c) i32 = @ptrFromInt(self.table.read_at);
        return callback(handle, offset, output.ptr, @intCast(output.len), deadline_ns);
    }
    pub fn nowNs(self: *const Context) u64 {
        if (!self.has("now_ns")) return std.math.maxInt(u64);
        const callback: *const fn () callconv(.c) u64 = @ptrFromInt(self.table.now_ns);
        return callback();
    }
    fn has(self: *const Context, comptime field: []const u8) bool {
        return self.table.version == 1 and self.table.size >= @offsetOf(abi.DriverResourceApi, field) + 8 and @field(self.table, field) != 0;
    }
};
