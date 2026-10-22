//! The single SDK helper object shared by C and Rust consumers.
comptime {
    _ = @import("runtime_bootstrap.zig");
    _ = @import("storage_runtime.zig");
    _ = @import("services_runtime.zig");
    _ = @import("generated/net_facade.zig");
    _ = @import("net_request_runtime.zig");
    _ = @import("gui_value_bridge.zig");
    _ = @import("graphics_runtime.zig");
    _ = @import("platform_runtime.zig");
    _ = @import("data_value_bridge.zig");
    _ = @import("web_value_bridge.zig");
    _ = @import("transport_value_bridge.zig");
}

comptime {
    _ = @import("update_value_bridge.zig");
}
