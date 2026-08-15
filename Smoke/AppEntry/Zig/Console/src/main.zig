const r4os = @import("r4os");

pub fn r4_app_main(app: *r4os.App) i32 {
    if (app.profile != .console or !app.hasGroup(.r4sys) or app.desktop() != null) return 71;
    const files = app.files() orelse return 72;
    var missing_path = r4os.FilePath.parse("C:\\__R4OS_05835_PARITY_MISSING__.BIN") catch return 73;
    var payload_path = r4os.FilePath.parse("C:\\R4OS\\CONFIG\\VERSION.R4S") catch return 74;
    var missing_buffer: [8]u8 = .{0xA5} ** 8;
    const missing_raw: i32 = switch (files.read(missing_path.asZ(), missing_buffer[0..])) {
        .failure => |raw| raw,
        .end => 0,
        .bytes => |count| @intCast(count),
    };

    var buffer: [128]u8 = .{0xA5} ** 128;
    const count: u32 = switch (files.read(payload_path.asZ(), buffer[0..64])) {
        .bytes => |value| value,
        .end => 0,
        .failure => return 75,
    };
    var payload: u64 = 14695981039346656037;
    for (buffer[0..count]) |byte| {
        payload ^= byte;
        payload *%= 1099511628211;
    }

    var region = switch (app.resources().reserveVm(4096, 4096, r4os.abi.vm_region_flags_default)) {
        .region => |value| value,
        .failure => return 76,
    };
    const handle_before: u64 = @intFromBool(region.valid());
    const close_raw = region.release();
    const handle_after: u64 = @intFromBool(region.valid());

    const sys = app.system();
    sys.write("APPPARITY lang=zig domain=");
    sys.printU64(@intFromEnum(r4os.app_contract.ErrorDomain.filesystem));
    sys.write(" raw=");
    sys.printI32(missing_raw);
    sys.write(" payload=");
    sys.printU64(payload);
    sys.write(" bytes=");
    sys.printU64(count);
    sys.write(" mutated=");
    sys.printU64(@intFromBool(count != 0 and buffer[0] != 0xA5));
    sys.write(" tail=");
    sys.printU64(@intFromBool(buffer[64] == 0xA5));
    sys.write(" handle_before=");
    sys.printU64(handle_before);
    sys.write(" close=");
    sys.printI32(close_raw);
    sys.write(" handle_after=");
    sys.printU64(handle_after);
    sys.write("\r\n");
    if (count == 0 or buffer[64] != 0xA5 or handle_before != 1 or close_raw != 0 or handle_after != 0) return 77;
    sys.println("APPZCON app entry: OK");
    return 0;
}
