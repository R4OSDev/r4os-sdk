//! Package-root test entry: imports must remain in this module, not a separate
//! SDK dependency whose tests Zig deliberately omits from this test artifact.
test {
    _ = @import("Tests/Simulation/DataOwners.zig");
    _ = @import("Tests/Simulation/WebOwners.zig");
    _ = @import("Tests/Simulation/TransportOwners.zig");
}
