//! Compiler-owned GUI type and operation catalogue for scalar C/Rust bridges.
//! Native layouts remain opaque; no foreign language guesses Zig slice,
//! optional, tagged-union, private-state or enum storage layouts.
const std = @import("std");
pub const abi = @import("r4os_contract").abi;
pub const program = @import("program.zig");
pub const sys = @import("r4sys.zig");
pub const desk = @import("r4desk.zig");
pub const draw = @import("r4draw.zig");
pub const gui = @import("gui.zig");
pub const app_gui = @import("app_gui.zig");
pub const shapes = @import("gui_shapes.zig");
pub const chart = @import("chart.zig");
pub const clipboard = @import("clipboard.zig");
pub const input = @import("input_events.zig");
pub const mode = @import("window_mode.zig");
pub const session = @import("gui_session_support.zig");
pub const language = @import("gui_language.zig");
pub const modules = .{ gui, app_gui, shapes, chart, clipboard, input, mode, language };
pub const Function = struct { owner: type, name: []const u8 };

fn contains(comptime list: []const type, comptime T: type) bool {
    for (list) |Item| if (Item == T) return true;
    return false;
}
pub fn context(comptime T: type) bool {
    return T == program.Context or T == sys.Context or T == desk.Context or T == draw.Context or T == session.Session;
}
pub fn canonical(comptime T: type) bool {
    const full = @typeName(T);
    const start = (std.mem.lastIndexOfScalar(u8, full, '.') orelse return false) + 1;
    return @hasDecl(abi, full[start..]) and @field(abi, full[start..]) == T;
}
fn walk(comptime T: type, comptime list: *[]const type) void {
    switch (@typeInfo(T)) {
        .void, .noreturn, .bool, .int, .float, .error_set => return,
        .pointer => |p| {
            if (p.child == anyopaque or @typeInfo(p.child) == .@"fn") return;
        },
        .@"struct", .@"union", .@"enum", .array, .optional, .error_union => {},
        else => return,
    }
    if (contains(list.*, T)) return;
    list.* = list.* ++ &[_]type{T};
    if (context(T) or canonical(T)) return;
    switch (@typeInfo(T)) {
        .@"struct" => |s| for (s.fields) |f| walk(f.type, list),
        .@"union" => |u| {
            if (u.tag_type) |tag| walk(tag, list);
            for (u.fields) |f| walk(f.type, list);
        },
        .array => |a| walk(a.child, list),
        .pointer => |p| walk(p.child, list),
        .optional => |o| walk(o.child, list),
        .error_union => |e| walk(e.payload, list),
        else => {},
    }
}
fn walkFunction(comptime F: type, comptime list: *[]const type) void {
    const f = @typeInfo(F).@"fn";
    if (f.is_generic or f.is_var_args) return;
    for (f.params) |p| walk(p.type.?, list);
    if (f.return_type.? != type) walk(f.return_type.?, list);
}
fn exportedMethod(comptime T: type, comptime name: []const u8) bool {
    if (T == program.Context or T == sys.Context) return false;
    if (T == draw.Context) return std.mem.startsWith(u8, name, "gui") or std.mem.startsWith(u8, name, "supportsGui") or std.mem.startsWith(u8, name, "font");
    if (T == desk.Context) return !std.mem.eql(u8, name, "init") and !std.mem.eql(u8, name, "fromProgram") and !std.mem.eql(u8, name, "hasFn");
    return true;
}
pub const types = blk: {
    @setEvalBranchQuota(32_000_000);
    var result: []const type = &.{};
    for (modules) |M| for (@typeInfo(M).@"struct".decls) |decl| {
        const value = @field(M, decl.name);
        if (@TypeOf(value) == type) walk(value, &result) else if (@typeInfo(@TypeOf(value)) == .@"fn") walkFunction(@TypeOf(value), &result);
    };
    walk(gui.TextField([]u8), &result);
    walk(gui.TextArea([]u8), &result);
    walk(input.Queue([]abi.ConsoleInputEvent), &result);
    walk(desk.Context, &result);
    walk(draw.Context, &result);
    walk(session.Session, &result);
    var index: usize = 0;
    while (index < result.len) : (index += 1) {
        const T = result[index];
        if (@typeInfo(T) != .@"struct" and @typeInfo(T) != .@"union" and @typeInfo(T) != .@"enum") continue;
        if (canonical(T)) continue;
        const decls = switch (@typeInfo(T)) {
            .@"struct" => |s| s.decls,
            .@"union" => |u| u.decls,
            .@"enum" => |e| e.decls,
            else => unreachable,
        };
        for (decls) |decl| {
            if (!exportedMethod(T, decl.name)) continue;
            const F = @TypeOf(@field(T, decl.name));
            if (@typeInfo(F) == .@"fn") walkFunction(F, &result);
        }
    }
    break :blk result;
};
pub const functions = blk: {
    @setEvalBranchQuota(32_000_000);
    var result: []const Function = &.{};
    for (modules) |M| for (@typeInfo(M).@"struct".decls) |decl| {
        const F = @TypeOf(@field(M, decl.name));
        if (@typeInfo(F) == .@"fn" and !@typeInfo(F).@"fn".is_generic) result = result ++ &[_]Function{.{ .owner = M, .name = decl.name }};
    };
    for (types) |T| {
        const meta = @typeInfo(T);
        if (meta != .@"struct" and meta != .@"union" and meta != .@"enum") continue;
        if (canonical(T)) continue;
        const decls = switch (meta) {
            .@"struct" => |s| s.decls,
            .@"union" => |u| u.decls,
            .@"enum" => |e| e.decls,
            else => unreachable,
        };
        for (decls) |decl| {
            if (!exportedMethod(T, decl.name)) continue;
            const F = @TypeOf(@field(T, decl.name));
            if (@typeInfo(F) == .@"fn" and !@typeInfo(F).@"fn".is_generic) result = result ++ &[_]Function{.{ .owner = T, .name = decl.name }};
        }
    }
    break :blk result;
};
pub fn typeId(comptime T: type) u32 {
    for (types, 0..) |Item, i| if (Item == T) return @intCast(i);
    @compileError("Uncatalogued GUI value " ++ @typeName(T));
}
/// Binds opaque layouts, enum tags and dispatch signatures to the exact
/// generated boundary. This is SDK-local, never a new platform ABI version.
/// Zig's private anonymous-type counters depend on analysis order, not ABI.
/// Keep their enclosing declaration and structure, omitting only that counter.
pub fn stableName(comptime full: []const u8) []const u8 {
    return comptime blk: {
        var bytes: [full.len]u8 = undefined;
        var i: usize = 0;
        var n: usize = 0;
        while (i < full.len) {
            var anonymous = false;
            for (.{ "__struct_", "__union_", "__enum_" }) |prefix| {
                if (std.mem.startsWith(u8, full[i..], prefix)) {
                    @memcpy(bytes[n..][0..prefix.len], prefix);
                    n += prefix.len;
                    i += prefix.len;
                    while (i < full.len and std.ascii.isDigit(full[i])) : (i += 1) {}
                    anonymous = true;
                    break;
                }
            }
            if (anonymous) continue;
            bytes[n] = full[i];
            n += 1;
            i += 1;
        }
        const result = bytes;
        break :blk result[0..n];
    };
}
pub const fingerprint = blk: {
    @setEvalBranchQuota(32_000_000);
    var hash = std.hash.Wyhash.init(0);
    for (types) |T| {
        hash.update(std.fmt.comptimePrint("{s}:{d}:{d};", .{ stableName(@typeName(T)), @sizeOf(T), @alignOf(T) }));
        switch (@typeInfo(T)) {
            .@"struct" => |v| for (v.fields) |f| hash.update(std.fmt.comptimePrint("{s}:{s}:{d};", .{ f.name, stableName(@typeName(f.type)), @offsetOf(T, f.name) })),
            .@"union" => |v| for (v.fields) |f| hash.update(f.name ++ ":" ++ stableName(@typeName(f.type)) ++ ";"),
            .@"enum" => |v| for (v.fields) |f| hash.update(std.fmt.comptimePrint("{s}:{d};", .{ f.name, f.value })),
            else => {},
        }
    }
    for (functions) |f| hash.update(stableName(@typeName(f.owner)) ++ "." ++ f.name ++ ":" ++ stableName(@typeName(@TypeOf(@field(f.owner, f.name)))) ++ ";");
    hash.update(std.fmt.comptimePrint("session-event:{d}:{d};", .{ @sizeOf(session.Event), @alignOf(session.Event) }));
    for (@typeInfo(session.Event).@"struct".fields) |f| hash.update(std.fmt.comptimePrint("{s}:{s}:{d};", .{ f.name, stableName(@typeName(f.type)), @offsetOf(session.Event, f.name) }));
    for (@typeInfo(session.EventKind).@"enum".fields) |f| hash.update(std.fmt.comptimePrint("{s}:{d};", .{ f.name, f.value }));
    break :blk hash.final();
};
