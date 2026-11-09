//! SDK-local C/Rust bootstrap. Records cross the native ABI only by pointer.
const abi = @import("platform2.zig").abi;
const startup = @import("app2.zig");
const Memory = @import("allocator_source.zig").Memory;

export fn R4SdkApp2Init(raw: ?*const abi.R4XStartContext2, expected: ?*const startup.StartupInfo, output: ?*Memory) callconv(.c) i32 {
    const context = raw orelse return -12;
    const info = expected orelse return -12;
    const memory = output orelse return -12;
    if (@intFromPtr(context) % @alignOf(abi.R4XStartContext2) != 0) return -12;
    var app = switch (startup.App.initDeclared(context, info)) {
        .value => |value| value,
        .failure => |failure| return failure.raw_code,
    };
    const low = app.lowLevel();
    @import("secure_random.zig").bindProgram(&low);
    @import("runtime_fault.zig").bind(@import("allocator_source.zig").Source.mapped(&app.memory).function("program_exit"));
    memory.* = app.memory;
    return 0;
}
