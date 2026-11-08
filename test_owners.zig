//! Package-root test entry: imports must remain in this module, not a separate
//! SDK dependency whose tests Zig deliberately omits from this test artifact.
test "wire owner pure helpers" {
    _ = @import("r4os/binary_cursor.zig");
    _ = @import("r4os/native_protocol_view.zig");
    _ = @import("r4os/internet_checksum.zig");
    _ = @import("r4os/block_transfer.zig");
}
test "cli owner shared helpers" {
    _ = @import("r4os/diagnostic_sinks.zig");
    _ = @import("r4os/arg_cursor.zig");
    _ = @import("r4os/diagnostic_buffer.zig");
}
test {
    _ = @import("Tests/Simulation/DataOwners.zig");
    _ = @import("Tests/Simulation/WebOwners.zig");
    _ = @import("Tests/Simulation/TransportOwners.zig");
}
