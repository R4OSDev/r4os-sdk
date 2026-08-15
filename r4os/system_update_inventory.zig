const std = @import("std");
const contract = @import("r4u_manifest.zig");

pub const max_entries: usize = 192;
pub const max_bytes: usize = 64 * 1024;

pub const Profile = enum {
    slim,
    full,
    test_image,

    pub fn text(self: Profile) []const u8 {
        return switch (self) {
            .slim => "slim",
            .full => "full",
            .test_image => "test",
        };
    }

    fn parse(value: []const u8) ?Profile {
        if (std.mem.eql(u8, value, "slim")) return .slim;
        if (std.mem.eql(u8, value, "full")) return .full;
        if (std.mem.eql(u8, value, "test")) return .test_image;
        return null;
    }
};

pub const Entry = struct {
    name: []const u8,
    kind: contract.ComponentKind,
    version: []const u8,
    target: []const u8,
};

pub const Inventory = struct {
    profile: Profile = .full,
    entries: [max_entries]Entry = undefined,
    count: usize = 0,

    pub fn parse(bytes: []const u8, out: *Inventory) bool {
        out.* = .{};
        var scanner = Scanner{ .bytes = stripBom(bytes) };
        if (!scanner.take('{') or
            !scanner.key("schema") or scanner.number() != 2 or
            !scanner.comma() or !scanner.key("profile")) return false;
        const profile_text = scanner.string() orelse return false;
        out.profile = Profile.parse(profile_text) orelse return false;
        if (!scanner.comma() or !scanner.key("count")) return false;
        const declared_count = scanner.number() orelse return false;
        if (declared_count > max_entries or !scanner.comma() or
            !scanner.key("entries") or !scanner.take('[')) return false;

        while (!scanner.peek(']')) {
            if (out.count >= max_entries or !parseEntry(&scanner, &out.entries[out.count])) return false;
            out.count += 1;
            if (scanner.peek(']')) break;
            if (!scanner.comma()) return false;
        }
        if (!scanner.take(']') or !scanner.take('}') or !scanner.done()) return false;
        if (declared_count != out.count) return false;
        return out.validate();
    }

    pub fn upsert(self: *Inventory, replacement: Entry) bool {
        if (!validEntry(replacement)) return false;
        var target_match: ?usize = null;
        var identity_match: ?usize = null;
        for (self.entries[0..self.count], 0..) |entry, index| {
            if (contract.targetEquals(entry.target, replacement.target)) target_match = index;
            if (entry.kind == replacement.kind and std.ascii.eqlIgnoreCase(entry.name, replacement.name)) identity_match = index;
        }
        if (target_match) |index| {
            if (identity_match != null and identity_match.? != index) return false;
            const old = self.entries[index];
            if (old.kind != replacement.kind or !std.ascii.eqlIgnoreCase(old.name, replacement.name)) return false;
            self.entries[index] = replacement;
            return true;
        }
        if (identity_match != null or self.count >= max_entries) return false;
        self.entries[self.count] = replacement;
        self.count += 1;
        return true;
    }

    pub fn render(self: *const Inventory, out: []u8) ?[]const u8 {
        if (!self.validate()) return null;
        var writer = Writer{ .out = out };
        if (!writer.text("{\n  \"schema\": 2,\n  \"profile\": ") or
            !writer.string(self.profile.text()) or
            !writer.text(",\n  \"count\": ") or
            !writer.unsigned(self.count) or
            !writer.text(",\n  \"entries\": [\n")) return null;
        for (self.entries[0..self.count], 0..) |entry, index| {
            if (!writer.text("    {\n      \"name\": ") or !writer.string(entry.name) or
                !writer.text(",\n      \"kind\": ") or !writer.string(entry.kind.text()) or
                !writer.text(",\n      \"version\": ") or !writer.string(entry.version) or
                !writer.text(",\n      \"target\": ") or !writer.string(entry.target) or
                !writer.text("\n    }") or
                !writer.text(if (index + 1 == self.count) "\n" else ",\n")) return null;
        }
        if (!writer.text("  ]\n}\n")) return null;
        return out[0..writer.len];
    }

    fn validate(self: *const Inventory) bool {
        if (self.count == 0 or self.count > max_entries) return false;
        for (self.entries[0..self.count], 0..) |entry, index| {
            if (!validEntry(entry)) return false;
            for (self.entries[0..index]) |prior| {
                if (contract.targetEquals(entry.target, prior.target) or
                    (entry.kind == prior.kind and std.ascii.eqlIgnoreCase(entry.name, prior.name))) return false;
            }
        }
        return true;
    }
};

fn validEntry(entry: Entry) bool {
    if (!contract.validToken(entry.name, contract.component_name_max_bytes) or
        !contract.validSemanticVersion(entry.version)) return false;
    var canonical_buffer: [1024]u8 = undefined;
    const canonical = contract.canonicalInventoryTarget(canonical_buffer[0..], entry.target) orelse return false;
    if (!contract.targetEquals(canonical, entry.target)) return false;
    return switch (entry.kind) {
        .kernel => contract.targetEquals(entry.target, "/boot/r4os.elf") and std.ascii.eqlIgnoreCase(entry.name, "KERNEL"),
        .r4x => std.ascii.endsWithIgnoreCase(entry.target, ".R4X"),
        .r4l => std.ascii.endsWithIgnoreCase(entry.target, ".R4L"),
        .r4d => std.ascii.endsWithIgnoreCase(entry.target, ".R4D"),
        .r4p => std.ascii.endsWithIgnoreCase(entry.target, ".R4P"),
    };
}

fn parseEntry(scanner: *Scanner, entry: *Entry) bool {
    if (!scanner.take('{') or !scanner.key("name")) return false;
    const name = scanner.string() orelse return false;
    if (!scanner.comma() or !scanner.key("kind")) return false;
    const kind = contract.ComponentKind.parse(scanner.string() orelse return false) orelse return false;
    if (!scanner.comma() or !scanner.key("version")) return false;
    const version = scanner.string() orelse return false;
    if (!scanner.comma() or !scanner.key("target")) return false;
    const target = scanner.string() orelse return false;
    if (!scanner.take('}')) return false;
    entry.* = .{ .name = name, .kind = kind, .version = version, .target = target };
    return true;
}

const Scanner = struct {
    bytes: []const u8,
    pos: usize = 0,

    fn skip(self: *Scanner) void {
        while (self.pos < self.bytes.len and std.ascii.isWhitespace(self.bytes[self.pos])) self.pos += 1;
    }

    fn take(self: *Scanner, expected: u8) bool {
        self.skip();
        if (self.pos >= self.bytes.len or self.bytes[self.pos] != expected) return false;
        self.pos += 1;
        return true;
    }

    fn peek(self: *Scanner, expected: u8) bool {
        self.skip();
        return self.pos < self.bytes.len and self.bytes[self.pos] == expected;
    }

    fn comma(self: *Scanner) bool {
        return self.take(',');
    }

    fn key(self: *Scanner, expected: []const u8) bool {
        const got = self.string() orelse return false;
        return std.mem.eql(u8, got, expected) and self.take(':');
    }

    fn string(self: *Scanner) ?[]const u8 {
        self.skip();
        if (self.pos >= self.bytes.len or self.bytes[self.pos] != '"') return null;
        self.pos += 1;
        const start = self.pos;
        while (self.pos < self.bytes.len and self.bytes[self.pos] != '"') : (self.pos += 1) {
            const byte = self.bytes[self.pos];
            if (byte == '\\' or byte < 0x20) return null;
        }
        if (self.pos >= self.bytes.len or !std.unicode.utf8ValidateSlice(self.bytes[start..self.pos])) return null;
        const value = self.bytes[start..self.pos];
        self.pos += 1;
        return value;
    }

    fn number(self: *Scanner) ?usize {
        self.skip();
        const start = self.pos;
        var value: usize = 0;
        while (self.pos < self.bytes.len and std.ascii.isDigit(self.bytes[self.pos])) : (self.pos += 1) {
            value = std.math.mul(usize, value, 10) catch return null;
            value = std.math.add(usize, value, self.bytes[self.pos] - '0') catch return null;
        }
        if (self.pos == start) return null;
        return value;
    }

    fn done(self: *Scanner) bool {
        self.skip();
        return self.pos == self.bytes.len;
    }
};

const Writer = struct {
    out: []u8,
    len: usize = 0,

    fn text(self: *Writer, value: []const u8) bool {
        if (value.len > self.out.len - self.len) return false;
        @memcpy(self.out[self.len .. self.len + value.len], value);
        self.len += value.len;
        return true;
    }

    fn string(self: *Writer, value: []const u8) bool {
        return self.text("\"") and self.text(value) and self.text("\"");
    }

    fn unsigned(self: *Writer, value: usize) bool {
        var buffer: [24]u8 = undefined;
        const rendered = std.fmt.bufPrint(buffer[0..], "{d}", .{value}) catch return false;
        return self.text(rendered);
    }
};

fn stripBom(bytes: []const u8) []const u8 {
    if (bytes.len >= 3 and bytes[0] == 0xEF and bytes[1] == 0xBB and bytes[2] == 0xBF) return bytes[3..];
    return bytes;
}

const fixture =
    \\{
    \\  "schema": 2,
    \\  "profile": "slim",
    \\  "count": 2,
    \\  "entries": [
    \\    {
    \\      "name": "KERNEL",
    \\      "kind": "KERNEL",
    \\      "version": "0.1.0",
    \\      "target": "/boot/r4os.elf"
    \\    },
    \\    {
    \\      "name": "TERMINAL",
    \\      "kind": "R4X",
    \\      "version": "0.1.3",
    \\      "target": "/R4OS/SOFTWARE/TERMINAL/TERMINAL.R4X"
    \\    }
    \\  ]
    \\}
;

test "inventory update preserves profile and takes exact artifact versions" {
    var inventory: Inventory = undefined;
    try std.testing.expect(Inventory.parse(fixture, &inventory));
    try std.testing.expectEqual(Profile.slim, inventory.profile);
    try std.testing.expect(inventory.upsert(.{
        .name = "TERMINAL",
        .kind = .r4x,
        .version = "0.0.1",
        .target = "/R4OS/SOFTWARE/TERMINAL/TERMINAL.R4X",
    }));
    try std.testing.expect(inventory.upsert(.{
        .name = "R4SYS",
        .kind = .r4l,
        .version = "0.1.1",
        .target = "/R4OS/LIBS/R4SYS.R4L",
    }));
    var rendered: [4096]u8 = undefined;
    const text = inventory.render(rendered[0..]).?;
    var reparsed: Inventory = undefined;
    try std.testing.expect(Inventory.parse(text, &reparsed));
    try std.testing.expectEqual(Profile.slim, reparsed.profile);
    try std.testing.expectEqual(@as(usize, 3), reparsed.count);
    try std.testing.expectEqualStrings("0.0.1", reparsed.entries[1].version);
}

test "inventory rejects drifted count and unknown profile" {
    var inventory: Inventory = undefined;
    const bad_count = try std.mem.replaceOwned(u8, std.testing.allocator, fixture, "\"count\": 2", "\"count\": 1");
    defer std.testing.allocator.free(bad_count);
    try std.testing.expect(!Inventory.parse(bad_count, &inventory));
    const bad_profile = try std.mem.replaceOwned(u8, std.testing.allocator, fixture, "\"slim\"", "\"other\"");
    defer std.testing.allocator.free(bad_profile);
    try std.testing.expect(!Inventory.parse(bad_profile, &inventory));
}
