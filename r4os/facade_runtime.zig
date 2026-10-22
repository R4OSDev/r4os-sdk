//! The single SDK helper object shared by C and Rust consumers.
comptime {
    _ = @import("storage_runtime.zig");
    _ = @import("services_runtime.zig");
    _ = @import("generated/net_facade.zig");
    _ = @import("net_request_runtime.zig");
    _ = @import("gui_value_bridge.zig");
    _ = @import("graphics_runtime.zig");
}
