const std = @import("std");
const storage = @import("app_storage.zig");

/// Bounded dialog pages own paths and kinds. Labels are presentation only;
/// activating a row never enumerates its old filesystem index again.
pub fn DialogPage(comptime capacity: usize, comptime path_bytes: usize, comptime label_bytes: usize) type {
    if (capacity < 4) @compileError("A page needs parent, previous, next and file rows");
    return struct {
        const Self = @This();
        pub const page_size = capacity - 3;
        pub const Kind = enum { file, directory, previous, next };
        pub const Row = struct {
            kind: Kind = .file,
            path: [path_bytes]u8 = .{0} ** path_bytes,
            label: [label_bytes]u8 = .{0} ** label_bytes,
        };
        directory: [path_bytes]u8 = .{0} ** path_bytes,
        rows: [capacity]Row = .{Row{}} ** capacity,
        count: usize = 0,
        number: u32 = 0,

        /// Builds privately through the real end, including entries beyond
        /// the visible page, so an I/O error cannot publish a partial view.
        pub fn load(self: *Self, files: storage.Files, directory: storage.PathZ, number: u32, extension: []const u8) bool {
            if (directory.len >= path_bytes) return false;
            var next = Self{ .number = number };
            copyZ(&next.directory, directory.bytes());
            var iterator = files.iterate(directory);
            iterator.index = 1; // Parent row; omit the redundant current-directory row.
            var path: [path_bytes]u8 = undefined;
            const parent = switch (iterator.next(&path)) {
                .entry => |entry| entry,
                else => return false,
            };
            next.add(.directory, parent.path, "[DIR] ..");
            if (number != 0) next.add(.previous, "", "<< Previous page");
            const first = @as(u64, number) * page_size;
            var seen: u64 = 0;
            while (true) {
                const entry = switch (iterator.next(&path)) {
                    .entry => |entry| entry,
                    .end => break,
                    .failure => return false,
                };
                if (entry.kind == .file and extension.len != 0 and !std.ascii.endsWithIgnoreCase(entry.path, extension)) continue;
                if (seen >= first and seen - first < page_size) {
                    const name = tail(entry.path);
                    var label: [label_bytes]u8 = .{0} ** label_bytes;
                    const prefix = if (entry.kind == .directory) "[DIR] " else "";
                    copyZ(&label, prefix);
                    copyZ(label[prefix.len..], name);
                    next.add(if (entry.kind == .directory) .directory else .file, entry.path, std.mem.sliceTo(&label, 0));
                }
                seen += 1;
            }
            if (seen > first + page_size) next.add(.next, "", "Next page >>");
            self.* = next;
            return true;
        }

        fn add(self: *Self, kind: Kind, path: []const u8, label: []const u8) void {
            const row = &self.rows[self.count];
            row.kind = kind;
            copyZ(&row.path, path);
            copyZ(&row.label, label);
            self.count += 1;
        }
    };
}

/// A caller-owned, ordered best-N set. Scanning all entries with this set
/// gives a globally sorted page without retaining the entire directory.
pub fn OrderedPage(comptime T: type, comptime capacity: usize) type {
    return struct {
        entries: [capacity]T = undefined,
        count: usize = 0,

        pub fn offer(self: *@This(), value: T, context: anytype, comptime less: fn (@TypeOf(context), T, T) bool) void {
            if (self.count == capacity and !less(context, value, self.entries[capacity - 1])) return;
            var at = @min(self.count, capacity - 1);
            while (at > 0 and less(context, value, self.entries[at - 1])) : (at -= 1) {
                self.entries[at] = self.entries[at - 1];
            }
            self.entries[at] = value;
            self.count = @min(self.count + 1, capacity);
        }
    };
}

fn copyZ(out: []u8, value: []const u8) void {
    @memset(out, 0);
    const count = @min(value.len, out.len - 1);
    @memcpy(out[0..count], value[0..count]);
}

fn tail(path: []const u8) []const u8 {
    var start: usize = 0;
    for (path, 0..) |ch, index| if (ch == '\\' or ch == '/') {
        start = index + 1;
    };
    return path[start..];
}
