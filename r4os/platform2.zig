//! Explicit generation-2 provider/probe access. Existing App remains on its
//! selected contract; no process-global binding or implicit generation fallback.
const std = @import("std");
pub const abi = @import("r4os_contract2");
pub const Error = error{ InvalidContext, InvalidImports, MixedGeneration, DuplicateGroup, MissingSystem, InvalidTable };

pub const Context = struct {
    raw: *const abi.R4XStartContext2,
    tables: [6]u64 = @splat(0),

    pub fn init(raw: *const abi.R4XStartContext2) Error!Context {
        if (raw.magic != abi.start_magic or raw.abi_major != 2 or raw.size < @sizeOf(abi.R4XStartContext2)) return error.InvalidContext;
        if (raw.import_count > 32 or (raw.import_count != 0 and (raw.imports == 0 or raw.imports % @alignOf(abi.R4XStartImport) != 0))) return error.InvalidImports;
        var result: Context = .{ .raw = raw };
        var seen: u8 = 0;
        if (raw.import_count != 0) {
            const imports: [*]const abi.R4XStartImport = @ptrFromInt(raw.imports);
            for (imports[0..raw.import_count]) |item| {
                if (item.group_id == 0) continue; // independent R4L interfaces
                if (item.group_id > 6) return error.InvalidImports;
                // Query2 export revision is separate from the table revision.
                if (item.resolved_version != abi.query_version) return error.MixedGeneration;
                const index: usize = @intCast(item.group_id - 1);
                const bit: u8 = @as(u8, 1) << @as(u3, @intCast(index));
                if (seen & bit != 0) return error.DuplicateGroup;
                seen |= bit;
                result.tables[index] = item.table;
            }
        }
        if (result.tables[0] == 0) return error.MissingSystem;
        if (result.system() == null) return error.InvalidTable;
        return result;
    }

    pub fn group(self: *const Context, comptime Table: type, id: u32) ?*const Table {
        if (id == 0 or id > 6) return null;
        const raw = self.tables[id - 1];
        if (raw == 0 or raw % @alignOf(Table) != 0) return null;
        const t: *const Table = @ptrFromInt(raw);
        const expected: Table = .{};
        if (t.magic != expected.magic or t.abi_version < 1 or t.size < 16) return null;
        return t;
    }
    pub fn system(self: *const Context) ?*const abi.R4XStartR4Sys2 {
        return self.group(abi.R4XStartR4Sys2, 1);
    }
    pub fn desktop(self: *const Context) ?*const abi.R4XStartR4Desk2 {
        return self.group(abi.R4XStartR4Desk2, 2);
    }
    pub fn drawing(self: *const Context) ?*const abi.R4XStartR4Draw2 {
        return self.group(abi.R4XStartR4Draw2, 3);
    }
    pub fn network(self: *const Context) ?*const abi.R4XStartR4Net2 {
        return self.group(abi.R4XStartR4Net2, 4);
    }
    pub fn audio(self: *const Context) ?*const abi.R4XStartR4Audio2 {
        return self.group(abi.R4XStartR4Audio2, 5);
    }
    pub fn devices(self: *const Context) ?*const abi.R4XStartR4Dev2 {
        return self.group(abi.R4XStartR4Dev2, 6);
    }
};

test "platform2 admits only the explicitly selected generation and retains canonical tables" {
    var sys: abi.R4XStartR4Sys2 = .{};
    var rows = [_]abi.R4XStartImport{.{ .group_id = 1, .resolved_version = 2, .table = @intFromPtr(&sys) }};
    var raw: abi.R4XStartContext2 = .{ .imports = @intFromPtr(&rows), .import_count = 1 };
    const value = try Context.init(&raw);
    try std.testing.expect(value.system().? == &sys);
    rows[0].resolved_version = 1;
    try std.testing.expectError(error.MixedGeneration, Context.init(&raw));
    rows[0].resolved_version = 2;
    sys.magic = (abi.shared.R4XStartR4Sys{}).magic;
    try std.testing.expectError(error.InvalidTable, Context.init(&raw));
    sys = .{};
    raw.abi_major = 1;
    try std.testing.expectError(error.InvalidContext, Context.init(&raw));
    raw.abi_major = 2;
    raw.size = 119;
    try std.testing.expectError(error.InvalidContext, Context.init(&raw));
    raw.size = 120;
    raw.import_count = 33;
    try std.testing.expectError(error.InvalidImports, Context.init(&raw));
    raw.import_count = 1;
    raw.imports += 1;
    try std.testing.expectError(error.InvalidImports, Context.init(&raw));
    raw.imports -= 1;
    rows[0].group_id = 7;
    try std.testing.expectError(error.InvalidImports, Context.init(&raw));
    rows[0].group_id = 2;
    try std.testing.expectError(error.MissingSystem, Context.init(&raw));
    rows[0].group_id = 1;
    sys.size = 15;
    try std.testing.expectError(error.InvalidTable, Context.init(&raw));
    sys.size = 16;
    try std.testing.expect((try Context.init(&raw)).system() != null);
    sys.abi_version = 0;
    try std.testing.expectError(error.InvalidTable, Context.init(&raw));
    sys = .{};
    var duplicate = [_]abi.R4XStartImport{ rows[0], rows[0] };
    duplicate[0].table = 0;
    raw.imports = @intFromPtr(&duplicate);
    raw.import_count = 2;
    try std.testing.expectError(error.DuplicateGroup, Context.init(&raw));
}
