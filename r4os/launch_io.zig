//! Optional copied Start2 bindings; no automatic pipe inheritance or app routing.
//! Stdio snapshots borrow exact child references; copies are never Dup. Close
//! explicitly and retain failed Close identities. Context/code outlive all calls.
const std = @import("std");
const a = @import("r4os_contract").abi;
const platform = @import("platform2.zig");
const pipe = @import("byte_pipe.zig");
pub const Request = a.LaunchIo;
pub const Binding = a.LaunchIoBinding;
pub fn pipeBinding(end: a.BytePipeEnd) Binding {
    return .{ .kind = a.launch_io_pipe, .end = end };
}
pub fn launch(context: *const platform.Context, path: [*:0]const u8, args: [*:0]const u8, request: Request, out: *a.ProgramProcessHandle) i32 {
    var address: u64 = 0;
    const rc = context.lookup(1, @offsetOf(platform.abi.R4XStartR4Sys2, "program_launch_io"), &address);
    if (rc != 0) return rc;
    const call: a.R4SysFns.program_launch_io = @ptrFromInt(address);
    return call(path, args, &request, out);
}
fn consolePoll(limit: pipe.Deadline) i32 {
    if (limit.version != 1 or limit.size != @sizeOf(pipe.Deadline) or limit.reserved0 != 0) return a.byte_pipe_error_invalid;
    if (limit.kind != 0) return a.byte_pipe_error_unsupported;
    if (!std.meta.eql(limit, pipe.Deadline{})) return a.byte_pipe_error_invalid;
    return 0;
}
/// Pipe operations have full native deadlines. Default Console preserves its
/// existing byte/count/routing behavior: Poll only, no EOF/atomic-write claim.
/// Returned console write count means legacy-call handoff, not pipe queueing
/// or delivery. Original console wait/event APIs remain separate.
pub const Stdio = struct {
    context: *const platform.Context,
    snapshot: Request,
    pipes: ?pipe.Provider,
    pub fn init(context: *const platform.Context, out: *Stdio) i32 {
        var address: u64 = 0;
        const code = context.lookup(1, @offsetOf(platform.abi.R4XStartR4Sys2, "program_stdio"), &address);
        if (code != 0) return code;
        const call: a.R4SysFns.program_stdio = @ptrFromInt(address);
        var snapshot: Request = .{};
        const rc = call(&snapshot);
        if (rc != 0) return rc;
        if (snapshot.version != 1 or snapshot.size != @sizeOf(Request)) return a.launch_io_error_invalid;
        var any = false;
        for ([_]Binding{ snapshot.stdin_binding, snapshot.stdout_binding, snapshot.stderr_binding }) |b| {
            if (b.reserved != 0 or b.kind > a.launch_io_pipe) return a.launch_io_error_invalid;
            any = any or b.kind == a.launch_io_pipe;
        }
        var provider: ?pipe.Provider = null;
        if (any) {
            var value: pipe.Provider = undefined;
            const resolved = pipe.Provider.fromContext(context, &value);
            if (resolved != 0) return resolved;
            provider = value;
        }
        out.* = .{ .context = context, .snapshot = snapshot, .pipes = provider };
        return 0;
    }
    fn selected(self: *Stdio, stream: u32) ?*Binding {
        return switch (stream) {
            0 => &self.snapshot.stdin_binding,
            1 => &self.snapshot.stdout_binding,
            2 => &self.snapshot.stderr_binding,
            else => null,
        };
    }
    /// Borrowed value only; query/byte copy never retains another end.
    pub fn binding(self: *const Stdio, stream: u32) ?Binding {
        return switch (stream) {
            0 => self.snapshot.stdin_binding,
            1 => self.snapshot.stdout_binding,
            2 => self.snapshot.stderr_binding,
            else => null,
        };
    }
    pub fn read(self: *const Stdio, storage: []u8, limit: pipe.Deadline, out: *pipe.Progress) i32 {
        if (storage.len == 0) return a.byte_pipe_error_invalid;
        const b = self.snapshot.stdin_binding;
        if (b.kind == a.launch_io_pipe) {
            const provider = self.pipes orelse return a.byte_pipe_error_unsupported;
            return provider.read(b.end, storage.ptr, storage.len, &limit, out);
        }
        const valid = consolePoll(limit);
        if (valid != 0) return valid;
        var address: u64 = 0;
        const code = self.context.lookup(2, @offsetOf(platform.abi.R4XStartR4Desk2, "console_read"), &address);
        if (code != 0) return code;
        const call: a.R4DeskFns.console_read = @ptrFromInt(address);
        var staged: [a.byte_pipe_max_step]u8 = undefined;
        const count: usize = @min(storage.len, staged.len);
        const rc = call(&staged, @intCast(count));
        if (rc < 0) return rc;
        const n: usize = @intCast(rc);
        if (n > count) return a.byte_pipe_error_invalid;
        @memcpy(storage[0..n], staged[0..n]);
        out.* = .{ .bytes = n, .state = if (n != 0) a.byte_pipe_ready else a.byte_pipe_would_block };
        return 0;
    }
    pub fn write(self: *const Stdio, stream: u32, bytes: []const u8, limit: pipe.Deadline, out: *pipe.Progress) i32 {
        const b = self.binding(stream) orelse return a.byte_pipe_error_invalid;
        if (stream == 0 or bytes.len == 0) return a.byte_pipe_error_invalid;
        if (b.kind == a.launch_io_pipe) {
            const provider = self.pipes orelse return a.byte_pipe_error_unsupported;
            return provider.write(b.end, bytes.ptr, bytes.len, &limit, out);
        }
        const valid = consolePoll(limit);
        if (valid != 0) return valid;
        var address: u64 = 0;
        const code = self.context.lookup(2, @offsetOf(platform.abi.R4XStartR4Desk2, "console_write"), &address);
        if (code != 0) return code;
        const call: a.R4DeskFns.console_write = @ptrFromInt(address);
        const count: usize = @min(bytes.len, @as(usize, @intCast(a.byte_pipe_max_step)));
        const rc = call(stream, bytes.ptr, @intCast(count));
        if (rc < 0) return rc;
        const n: usize = @intCast(rc);
        if (n > count) return a.byte_pipe_error_invalid;
        out.* = .{ .bytes = n, .state = if (n != 0) a.byte_pipe_ready else a.byte_pipe_would_block };
        return 0;
    }
    pub fn cancel(self: *Stdio, stream: u32) i32 {
        const b = self.selected(stream) orelse return a.byte_pipe_error_invalid;
        if (b.kind != a.launch_io_pipe) return a.byte_pipe_error_unsupported;
        const provider = self.pipes orelse return a.byte_pipe_error_unsupported;
        return provider.cancel(b.end);
    }
    pub fn close(self: *Stdio, stream: u32) i32 {
        const b = self.selected(stream) orelse return a.byte_pipe_error_invalid;
        if (b.kind != a.launch_io_pipe) return a.byte_pipe_error_unsupported;
        if (b.end.handle == 0) return 0;
        const provider = self.pipes orelse return a.byte_pipe_error_unsupported;
        const code = provider.close(b.end);
        if (code == 0) b.end = .{};
        return code;
    }
};
