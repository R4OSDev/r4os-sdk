//! Caller-owned stable contexts; no window/host role or output policy.
const p = @import("program.zig");
pub const Context = struct {
    bundle: p.Bundle,
    draw: @import("r4draw.zig").Context,
    dev: @import("r4dev.zig").Context,
};
