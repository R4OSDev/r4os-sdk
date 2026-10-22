//! Explicit C callback ABI for the original Zig web hooks. The table and its
//! user storage stay at stable addresses through every retained native loan.
//! Callback inputs are borrowed only for this invocation; GC hooks retain
//! their original no-allocation/no-JavaScript/no-recursive-collection rules.
const std = @import("std");
const codec = @import("native_value_bridge.zig");
pub const Slot = codec.Slot;
pub const Kind = enum(u6) {
    glyph_support,
    font_resolve,
    font_measure,
    image_resolve,
    image_resolve_role,
    catalog_revision,
    catalog_count,
    catalog_info,
    js_host_function,
    js_host_get,
    js_host_set,
    js_cancel,
    js_clock,
    js_offset,
    promise_rejection,
    root_mark,
    root_mark_weak,
    root_sweep,
    program_create,
    program_destroy,
    program_allocate,
    program_free,
    canvas_allocate,
    canvas_free,
    resource_complete,
    font_local,
    font_cached,
    resource_report,
    frame_lookup,
    script_report,
    monotonic_clock,
    network_progress,
    cookie_provider,
    cookie_sink,
    target_authorize,
    download_progress,
    download_write,
    runtime_lookup,
};
pub const Table = extern struct {
    user: ?*anyopaque = null,
    mask: u64 = 0,
    invoke: ?*const fn (?*anyopaque, u32, [*]const Slot, u32, ?*anyopaque) callconv(.c) Slot = null,
    pub fn has(self: *const Table, kind: Kind) bool {
        return self.invoke != null and self.mask & (@as(u64, 1) << @intFromEnum(kind)) != 0;
    }
};
fn base(comptime T: type) type {
    return switch (@typeInfo(T)) {
        .error_union => |e| base(e.payload),
        .optional => |o| base(o.child),
        else => T,
    };
}
fn arg(comptime T: type, value: *const T) Slot {
    return switch (@typeInfo(T)) {
        .@"struct", .@"union", .array, .float => .{ .ptr = @ptrCast(@constCast(value)), .flags = codec.present },
        .optional => |o| if (value.* != null) arg(o.child, &value.*.?) else .{},
        else => codec.store(T, value.*, null) catch @panic("invalid native callback argument"),
    };
}
fn returned(comptime T: type, response: Slot, output: ?*anyopaque) T {
    if (response.status != 0) @panic("web callback transport failure");
    if (comptime @typeInfo(T) == .error_union) {
        const e = @typeInfo(T).error_union;
        if (response.flags & codec.native_error != 0) return (codec.decode(e.error_set, response) catch @panic("invalid callback error name")).value;
        return returned(e.payload, response, output);
    }
    if (response.flags & codec.native_error != 0) @panic("unexpected callback error");
    if (comptime T == void) return {};
    if (comptime @typeInfo(T) == .optional) {
        if (response.flags & codec.present == 0) return null;
        return @as(T, returned(@typeInfo(T).optional.child, response, output));
    }
    if (response.flags & codec.present == 0) @panic("missing callback result");
    if (comptime @typeInfo(T) == .@"struct" or @typeInfo(T) == .@"union" or @typeInfo(T) == .array or @typeInfo(T) == .float) {
        if (response.ptr != output or output == null) @panic("callback must initialize supplied native output");
    }
    return (codec.decode(T, response) catch @panic("invalid callback result")).value;
}
fn dispatch(comptime F: type, comptime context_index: usize, comptime kind: Kind, values: std.meta.ArgsTuple(F)) @typeInfo(F).@"fn".return_type.? {
    const meta = @typeInfo(F).@"fn";
    const R = meta.return_type.?;
    const C = @TypeOf(values[context_index]);
    const address = if (comptime @typeInfo(C) == .optional) values[context_index] orelse @panic("missing callback table") else values[context_index];
    const table: *const Table = @ptrCast(@alignCast(address));
    if (!table.has(kind)) @panic("unavailable callback kind");
    var arguments: [meta.params.len]Slot = undefined;
    inline for (meta.params, 0..) |p, i| arguments[i] = arg(p.type.?, &values[i]);
    // The callback sees the actual caller user pointer, never the SDK table.
    arguments[context_index] = .{ .ptr = table.user, .flags = if (table.user != null) codec.present else 0 };
    var storage: base(R) = undefined;
    const output: ?*anyopaque = if (comptime base(R) == void) null else @ptrCast(&storage);
    const response = table.invoke.?(table.user, @intFromEnum(kind), &arguments, arguments.len, output);
    return returned(R, response, output);
}

/// Return an exact original Zig function pointer. Only the inner invocation
/// crosses C, through scalar Slots and pointers (including floating data).
pub fn Adapter(comptime Pointer: type, comptime context_index: usize, comptime kind: Kind) type {
    const F = @typeInfo(Pointer).pointer.child;
    const info = @typeInfo(F).@"fn";
    const R = info.return_type.?;
    const P = struct {
        fn at(comptime n: usize) type {
            return info.params[n].type.?;
        }
    };
    return switch (info.params.len) {
        1 => struct {
            pub fn call(a: P.at(0)) callconv(info.calling_convention) R {
                return dispatch(F, context_index, kind, .{a});
            }
        },
        2 => struct {
            pub fn call(a: P.at(0), b: P.at(1)) callconv(info.calling_convention) R {
                return dispatch(F, context_index, kind, .{ a, b });
            }
        },
        3 => struct {
            pub fn call(a: P.at(0), b: P.at(1), c: P.at(2)) callconv(info.calling_convention) R {
                return dispatch(F, context_index, kind, .{ a, b, c });
            }
        },
        4 => struct {
            pub fn call(a: P.at(0), b: P.at(1), c: P.at(2), d: P.at(3)) callconv(info.calling_convention) R {
                return dispatch(F, context_index, kind, .{ a, b, c, d });
            }
        },
        5 => struct {
            pub fn call(a: P.at(0), b: P.at(1), c: P.at(2), d: P.at(3), e: P.at(4)) callconv(info.calling_convention) R {
                return dispatch(F, context_index, kind, .{ a, b, c, d, e });
            }
        },
        6 => struct {
            pub fn call(a: P.at(0), b: P.at(1), c: P.at(2), d: P.at(3), e: P.at(4), f: P.at(5)) callconv(info.calling_convention) R {
                return dispatch(F, context_index, kind, .{ a, b, c, d, e, f });
            }
        },
        else => @compileError("web callback arity needs an explicit adapter"),
    };
}
pub fn pointer(comptime T: type, comptime context_index: usize, comptime kind: Kind) T {
    return &Adapter(T, context_index, kind).call;
}
