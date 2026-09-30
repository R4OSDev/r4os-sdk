//! The actual update engine with finite, competing journal replacement through R4SYS.
const std = @import("std");
const r4os = @import("r4os");
const engine = @import("update_engine");
const recovery = r4os.system_update_recovery;
const batch = r4os.system_update_batch;
const expect = std.testing.expect;

const paths = [_][]const u8{
    "C:\\R4OS\\UPDATE\\STAGED\\SYSUPD0.JRN",
    "C:\\R4OS\\UPDATE\\STAGED\\SYSUPD1.JRN",
    "C:\\R4OS\\UPDATE\\STAGED\\SYSBCH0.JRN",
    "C:\\R4OS\\UPDATE\\STAGED\\SYSBCH1.JRN",
};
const File = struct { bytes: [8192]u8 = undefined, len: usize = 0, stats: usize = 0 };
var files: [4]File = undefined;
var race_slot: ?usize = null;
var race_seen = false;
var permanent = false;
var remove_batch = false;
var output: [8192]u8 = undefined;
var output_len: usize = 0;
var sleeps: usize = 0;

fn index(path: [*:0]const u8) ?usize {
    for (paths, 0..) |name, i| if (std.mem.eql(u8, name, std.mem.span(path))) return i;
    return null;
}
fn info(path: [*:0]const u8, out: *r4os.abi.FileInfo) callconv(.c) i32 {
    out.* = .{};
    const i = index(path) orelse {
        out.exists = 1;
        out.is_dir = 1;
        return 1;
    };
    const f = &files[i];
    f.stats += 1;
    if (f.len == 0) return 0;
    out.exists = 1;
    out.size = @intCast(f.len);
    // Simulate atomic replacement with a shorter, valid journal after stat.
    if (race_slot == i and (!race_seen or permanent)) {
        out.size += 31;
        race_seen = true;
        if (remove_batch) {
            files[2].len = 0;
            files[3].len = 0;
        }
    }
    return 1;
}
fn read(path: [*:0]const u8, offset: u32, bytes: [*]u8, capacity: u32) callconv(.c) i32 {
    const i = index(path) orelse return -8;
    const f = &files[i];
    if (offset >= f.len) return 0;
    const n = @min(f.len - offset, capacity);
    @memcpy(bytes[0..n], f.bytes[offset..][0..n]);
    return @intCast(n);
}
fn write(bytes: [*]const u8, len: u32) callconv(.c) i32 {
    const n = @min(len, output.len - output_len);
    @memcpy(output[output_len..][0..n], bytes[0..n]);
    output_len += n;
    return @intCast(len);
}
fn putc(ch: u8) callconv(.c) void {
    _ = write(@ptrCast(&ch), 1);
}
fn sleep(_: u64) callconv(.c) void {
    sleeps += 1;
}
fn mkdir(_: [*:0]const u8) callconv(.c) i32 {
    return 0;
}

fn text(out: []u8, value: []const u8) usize {
    @memcpy(out[0..value.len], value);
    return value.len;
}
fn reset() void {
    files = @splat(.{});
    race_slot = null;
    race_seen = false;
    permanent = false;
    remove_batch = false;
    output_len = 0;
    sleeps = 0;
}
fn journal(slot: usize, generation: u64) !void {
    var value: recovery.TransactionJournal = .{
        .valid = true,
        .transaction_generation = 5,
        .journal_generation = generation,
        .package_payload_count = 1,
        .payload_count = 1,
        .package_length = 1000,
    };
    value.source_len = text(&value.source_path, "C:\\R4OS\\UPDATE\\INBOX\\PKG.R4U");
    value.source_version_len = text(&value.source_version, "0.82.0");
    value.target_version_len = text(&value.target_version, "0.82.0");
    value.package_version_len = text(&value.package_version, "1.0.0");
    const target = "C:\\R4OS\\SOFTWARE\\TERMINAL\\TERMINAL.R4X";
    const entry = &value.payloads[0];
    entry.target_len = text(&entry.target_path, target);
    entry.stage_len = recovery.buildInternal83Name(&entry.stage_path, target, 'S', 5, 0) orelse return error.Fixture;
    entry.backup_len = recovery.buildInternal83Name(&entry.backup_path, target, 'B', 5, 0) orelse return error.Fixture;
    files[slot].len = (recovery.serializeJournal(&value, &files[slot].bytes) orelse return error.Fixture).len;
    var parsed: recovery.TransactionJournal = .{};
    try expect(recovery.parseJournalInto(files[slot].bytes[0..files[slot].len], @intCast(slot), &parsed));
}
fn batchJournal(slot: usize, generation: u64) !void {
    var value: batch.BatchJournal = .{
        .valid = true,
        .batch_generation = 4,
        .journal_generation = generation,
        .phase = .installed,
        .package_count = 1,
        .current_package = 1,
    };
    value.source_release_len = text(&value.source_release, "0.82.0");
    value.target_release_len = text(&value.target_release, "0.82.0");
    const entry = &value.packages[0];
    entry.path_len = text(&entry.path, "C:\\R4OS\\UPDATE\\INBOX\\PKG.R4U");
    entry.package_len = text(&entry.package, "PKG");
    entry.package_version_len = text(&entry.package_version, "1.0.0");
    entry.release_len = text(&entry.release, "0.82.0");
    entry.package_length = 1000;
    entry.package_digest = 100;
    entry.manifest_checksum = 200;
    entry.component_digest = 300;
    files[slot].len = (batch.serializeJournal(&value, &files[slot].bytes) orelse return error.Fixture).len;
    var parsed: batch.BatchJournal = .{};
    try expect(batch.parseJournalInto(files[slot].bytes[0..files[slot].len], @intCast(slot - 2), &parsed));
}
fn status() engine.Result {
    const api: r4os.abi.R4XStartR4Sys = .{
        .write = @intFromPtr(&write),
        .putc = @intFromPtr(&putc),
        .sleep_ticks = @intFromPtr(&sleep),
        .file_info = @intFromPtr(&info),
        .file_read_at = @intFromPtr(&read),
        .dir_create = @intFromPtr(&mkdir),
    };
    const bundle: r4os.program.Bundle = .{ .raw = undefined, .sys = &api };
    var app: r4os.App = undefined;
    var owner: engine.Engine = .{ .app = &app, .ctx = r4os.r4sys.Context.init(&bundle) };
    return owner.status();
}

test "status resnapshots a replaced journal without stale partial results" {
    reset();
    try journal(0, 10);
    try journal(1, 11);
    try batchJournal(2, 7);
    race_slot = 1;
    const result = status();
    if (result.exit_code != 0) std.debug.print("status fixture output={s} stats={d},{d},{d},{d}\n", .{ output[0..output_len], files[0].stats, files[1].stats, files[2].stats, files[3].stats });
    try std.testing.expectEqual(@as(i32, 0), result.exit_code);
    try expect(files[1].stats >= 2 and files[1].stats <= 3);
    try expect(std.mem.indexOf(u8, output[0..output_len], "generation=11 ") != null);
    try expect(std.mem.indexOf(u8, output[0..output_len], "FAILED") == null);

    reset();
    try batchJournal(2, 7);
    try batchJournal(3, 8);
    race_slot = 3;
    try std.testing.expectEqual(@as(i32, 0), status().exit_code);
    try expect(files[3].stats >= 2 and files[3].stats <= 3);

    reset();
    try journal(1, 11);
    try batchJournal(2, 7);
    race_slot = 1;
    remove_batch = true;
    const changed = status();
    try std.testing.expectEqual(@as(i32, 0), changed.exit_code);
    try std.testing.expectEqual(@as(u64, 0), changed.batch_generation);
    try expect(std.mem.indexOf(u8, output[0..output_len], "batch-state=") == null);

    reset();
    try journal(0, 10);
    try journal(1, 11);
    try batchJournal(2, 7);
    race_slot = 1;
    permanent = true;
    const failed = status();
    try std.testing.expectEqual(@as(i32, 1), failed.exit_code);
    try std.testing.expectEqual(@as(u64, 0), failed.batch_generation);
    try std.testing.expectEqual(@as(u64, 0), failed.transaction_generation);
    try expect(files[1].stats <= 3 and sleeps <= 16);
    try expect(std.mem.indexOf(u8, output[0..output_len], "reason=journal-read") != null);
}
