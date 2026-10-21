const std = @import("std");

pub const Cargo = struct { name: []const u8, version: []const u8, source: []const u8 };
pub const forbidden_inputs = [_][]const u8{ "build.rs", ".cargo/config", ".cargo/config.toml", "rust-toolchain", "rust-toolchain.toml", "src/main.rs", "src/bin", "examples", "tests", "benches" };

// Deliberately bounded TOML subset for the first reproducible SDK profile.
// Cargo metadata subsequently verifies Cargo's own package/target selection.
// Unsupported TOML is rejected, never guessed or compiled by another path.
pub fn parseCargo(source: []const u8, text: []const u8) !Cargo {
    var table: []const u8 = "";
    var tables: [8][]const u8 = undefined;
    var table_count: usize = 0;
    var keys: [48][]const u8 = undefined;
    var key_count: usize = 0;
    var name: ?[]const u8 = null;
    var version: ?[]const u8 = null;
    var edition = false;
    var path: ?[]const u8 = null;
    var staticlib = false;
    var lines = std.mem.splitScalar(u8, text, '\n');
    while (lines.next()) |raw| {
        const line = try stripComment(raw);
        if (line.len == 0) continue;
        if (line[0] == '[') {
            if (line.len < 3 or line[line.len - 1] != ']' or line[1] == '[') return error.RustCargoUnsupportedTable;
            table = line[1 .. line.len - 1];
            if (!oneOf(table, &.{ "package", "lib", "workspace", "dependencies" })) return error.RustCargoUnsupportedTable;
            for (tables[0..table_count]) |prior| if (std.mem.eql(u8, prior, table)) return error.RustCargoDuplicateTable;
            tables[table_count] = table;
            table_count += 1;
            key_count = 0;
            continue;
        }
        const eq = std.mem.indexOfScalar(u8, line, '=') orelse return error.RustCargoUnsupportedSyntax;
        const key = std.mem.trim(u8, line[0..eq], " \t");
        const value = std.mem.trim(u8, line[eq + 1 ..], " \t");
        if (key.len == 0 or value.len == 0 or key_count == keys.len) return error.RustCargoUnsupportedSyntax;
        for (keys[0..key_count]) |prior| if (std.mem.eql(u8, prior, key)) return error.RustCargoDuplicateKey;
        keys[key_count] = key;
        key_count += 1;
        if (std.mem.eql(u8, table, "package")) {
            if (std.mem.eql(u8, key, "name")) {
                name = try string(value);
                if (name.?.len == 0) return error.RustCargoInvalidPackage;
                for (name.?) |c| if (!std.ascii.isAlphanumeric(c) and c != '-' and c != '_') return error.RustCargoInvalidPackage;
            } else if (std.mem.eql(u8, key, "version")) {
                version = try string(value);
                var parts = std.mem.splitScalar(u8, version.?, '.');
                for (0..3) |_| _ = std.fmt.parseInt(u16, parts.next() orelse return error.RustCargoInvalidVersion, 10) catch return error.RustCargoInvalidVersion;
                if (parts.next() != null) return error.RustCargoInvalidVersion;
            } else if (std.mem.eql(u8, key, "edition")) {
                if (!std.mem.eql(u8, try string(value), "2024")) return error.RustCargoEditionRequired;
                edition = true;
            } else if (oneOf(key, &.{ "build", "publish", "autobins", "autoexamples", "autotests", "autobenches" })) {
                if (!std.mem.eql(u8, value, "false")) return error.RustCargoOverrideForbidden;
            } else if (oneOf(key, &.{ "description", "license", "rust-version" })) {
                _ = try string(value);
            } else return error.RustCargoUnsupportedPackageField;
        } else if (std.mem.eql(u8, table, "lib")) {
            if (std.mem.eql(u8, key, "path")) {
                path = try string(value);
                if (!std.mem.eql(u8, path.?, source)) return error.RustCargoSourceMismatch;
            } else if (std.mem.eql(u8, key, "crate-type")) {
                var compact: [64]u8 = undefined;
                var n: usize = 0;
                for (value) |c| if (c != ' ' and c != '\t') {
                    if (n == compact.len) return error.RustCargoStaticlibRequired;
                    compact[n] = c;
                    n += 1;
                };
                if (!std.mem.eql(u8, compact[0..n], "[\"staticlib\"]")) return error.RustCargoStaticlibRequired;
                staticlib = true;
            } else return error.RustCargoUnsupportedTargetField;
        } else if (std.mem.eql(u8, table, "dependencies")) {
            if (!oneOf(key, &.{ "r4os-contract", "r4os-sdk" })) return error.RustCargoDependencyUnsupported;
            // Only explicit inline dependency tables. The host driver checks
            // exact resolved paths, versions, features and package identities.
            if (value[0] != '{' or value[value.len - 1] != '}') return error.RustCargoDependencyUnsupported;
        } else return error.RustCargoWorkspaceOrRootOverride;
    }
    if (!edition or path == null or !staticlib) return error.RustCargoExplicitTargetRequired;
    return .{ .name = name orelse return error.RustCargoMissingPackage, .version = version orelse return error.RustCargoMissingPackage, .source = path.? };
}

fn oneOf(value: []const u8, choices: []const []const u8) bool {
    for (choices) |choice| if (std.mem.eql(u8, value, choice)) return true;
    return false;
}

fn string(value: []const u8) ![]const u8 {
    if (value.len < 2 or value[0] != '"' or value[value.len - 1] != '"') return error.RustCargoUnsupportedString;
    const body = value[1 .. value.len - 1];
    for (body) |c| if (c == '"' or c == '\\' or c < 32) return error.RustCargoUnsupportedString;
    return body;
}

fn stripComment(raw: []const u8) ![]const u8 {
    var quoted = false;
    for (raw, 0..) |c, index| {
        if (c == '\\' or c == '\'') return error.RustCargoUnsupportedSyntax;
        if (c == '"') quoted = !quoted;
        if (c == '#' and !quoted) return std.mem.trim(u8, raw[0..index], " \t\r");
    }
    if (quoted) return error.RustCargoUnsupportedString;
    return std.mem.trim(u8, raw, " \t\r");
}

test "Rust Cargo binds the one staticlib source and rejects overrides" {
    const text = "[package]\nname=\"different-crate\"\nversion=\"1.2.3\"\nedition=\"2024\"\n[lib]\npath=\"src/main.rs\"\ncrate-type=[\"staticlib\"]\n[workspace]\n";
    const cargo = try parseCargo("src/main.rs", text);
    try std.testing.expectEqualStrings("different-crate", cargo.name);
    try std.testing.expectError(error.RustCargoSourceMismatch, parseCargo("src/other.rs", text));
    try std.testing.expectError(error.RustCargoUnsupportedTable, parseCargo("src/main.rs", text ++ "[profile.release]\npanic=\"unwind\"\n"));
    try std.testing.expectError(error.RustCargoWorkspaceOrRootOverride, parseCargo("src/main.rs", text ++ "members=[]\n"));
    try std.testing.expectError(error.RustCargoUnsupportedTargetField, parseCargo("src/main.rs", "[lib]\nproc-macro=true\n"));
}
