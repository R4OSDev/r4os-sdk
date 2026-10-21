const std = @import("std");

pub const rust_profile = "r4os-rust-r4x-v1";
pub const rust_tools = "r4os-rust-tools-v1";
pub const rust_build_plan_schema: u32 = 1;
// Admission and availability are different facts. The host driver changes
// this only after source -> ELF -> R4M0 and real R4XStart qualification.
pub const rust_host_builder = true;

pub const Execution = enum { host, native_r4os };
pub const Decision = struct {
    supported: bool,
    code: []const u8,
    reason: []const u8,
    failure: ?anyerror = null,
    owner_contract: []const u8 = "",
    missing_steps: []const []const u8 = &.{},
};

pub fn rust(kind: []const u8, entry: []const u8, role: ?[]const u8, execution: Execution) Decision {
    if (std.mem.eql(u8, kind, "R4L")) return .{ .supported = false, .code = "rust-r4l-contract-unqualified", .reason = "Rust R4L implementation/binding/conformance and Query export build are not qualified.", .failure = error.RustR4LUnsupported, .owner_contract = "Contract/Module/R4MFv2.txt", .missing_steps = &.{ "Rust implementation and local contract/binding/conformance generator", "Regular Query/table exports and library-owned baseline validation", "Qualified Rust R4L build and consumer lifecycle" } };
    if (std.mem.eql(u8, kind, "R4D")) return .{ .supported = false, .code = "rust-driver-lifecycle-unqualified", .reason = "Rust driver entry, metadata, callbacks and teardown are not qualified.", .failure = error.RustR4DUnsupported, .owner_contract = "Contract/ABI/R4DDriver.txt", .missing_steps = &.{ "Rust DriverInit/DriverShutdown entry and metadata packaging", "R4DEV callback admission and exact per-device IRQ/DMA/resource teardown" } };
    if (std.mem.eql(u8, kind, "R4P")) return .{ .supported = false, .code = "rust-protocol-lifecycle-unqualified", .reason = "Rust protocol registration, callbacks and teardown are not qualified.", .failure = error.RustR4PUnsupported, .owner_contract = "SDK/r4os/build.zig:addR4MFProtocol", .missing_steps = &.{ "Rust protocol-specific entry/registration/export and metadata builder", "Qualified callback ownership, hot removal and shutdown lifecycle" } };
    if (role != null) return .{ .supported = false, .code = "rust-subsystem-host-unqualified", .reason = "Rust subsystem host/resolver/media and cleanup helpers are not qualified.", .failure = error.RustSubsystemUnsupported, .owner_contract = "SDK/r4os/subsystem_launch.zig", .missing_steps = &.{ "Rust host/resolver and subsystem ID/format/catalog integration", "Video/input/audio/persistence and exact host cleanup helpers" } };
    if (!std.ascii.eqlIgnoreCase(entry, "app")) return .{ .supported = false, .code = "rust-lowlevel-entry-unqualified", .reason = "Only the normal R4XStart app entry is admitted for Rust.", .failure = error.RustLowlevelUnsupported, .owner_contract = "Contract/ABI/R4XStart.txt", .missing_steps = &.{"Independent raw-entry Rust ABI/startup/stack/panic qualification"} };
    if (execution == .native_r4os) return .{ .supported = false, .code = "rust-native-compiler-unavailable", .reason = "Rust compilation requires the pinned Windows/Linux host tools; R4OS has no native Rust compiler.", .failure = error.RustNativeCompilerUnavailable, .owner_contract = "SDK/Rust/README.txt", .missing_steps = &.{"Independent native R4OS Rust compiler/toolchain port and qualification"} };
    return .{ .supported = true, .code = "supported", .reason = "Rust R4X app console/gui/service semantic profile; compiler installation is a separate check." };
}

pub fn requireRustHost(kind: []const u8, entry: []const u8, role: ?[]const u8) !void {
    const decision = rust(kind, entry, role, .host);
    if (decision.failure) |err| return err;
    if (!rust_host_builder) return error.RustHostBuilderNotYetQualified;
}
