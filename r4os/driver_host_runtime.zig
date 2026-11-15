//! The original production driver bridge for the existing C/Rust host oracle.
pub const panic = @import("runtime_fault.zig").panic;
comptime {
    if (@import("builtin").os.tag == .freestanding) @compileError("Native driver oracle only");
    _ = @import("driver_value_bridge.zig");
}
