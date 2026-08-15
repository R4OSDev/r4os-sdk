const std = @import("std");
const generated = @import("platform_group");

const query_code = [_]u8{ 0x31, 0xc0, 0x66, 0xb8, 0x14, 0x02, 0xc3 };

pub fn main(init: std.process.Init) !void {
    const args = try init.minimal.args.toSlice(init.arena.allocator());
    if (args.len != 3) return error.BadArgs;

    var data = [_]u8{0} ** generated.r4l_query_struct_len;
    putU32(&data, 0, generated.query.magic);
    putU32(&data, 4, generated.query.abi_version);
    putU32(&data, 8, generated.query.size);
    putU32(&data, 12, generated.query.group);
    putU64(&data, 16, generated.query.kernel_bridge);
    putU64(&data, 24, generated.query.reserved);

    const cwd = std.Io.Dir.cwd();
    try cwd.writeFile(init.io, .{ .sub_path = args[1], .data = &query_code });
    try cwd.writeFile(init.io, .{ .sub_path = args[2], .data = &data });
}

fn putU32(out: []u8, offset: usize, value: u32) void {
    std.mem.writeInt(u32, out[offset..][0..4], value, .little);
}

fn putU64(out: []u8, offset: usize, value: u64) void {
    std.mem.writeInt(u64, out[offset..][0..8], value, .little);
}
