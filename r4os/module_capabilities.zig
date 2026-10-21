const std = @import("std");

pub const rust_profile = "r4os-rust-r4x-v1";
pub const rust_tools = "r4os-rust-tools-v1";
pub const rust_build_plan_schema: u32 = 1;
// Admission and availability are different facts. The host driver changes
// this only after source -> ELF -> R4M0 and real R4XStart qualification.
pub const rust_host_builder = false;

pub const Execution = enum { host, native_r4os };
pub const Decision = struct {
    supported: bool,
    code: []const u8,
    reason: []const u8,
    failure: ?anyerror = null,
};

pub fn rust(kind: []const u8, entry: []const u8, role: ?[]const u8, execution: Execution) Decision {
    if (std.mem.eql(u8, kind, "R4L")) return .{ .supported = false, .code = "rust-r4l-contract-unqualified", .reason = "Rust R4L implementation/binding/conformance and Query export build are not qualified.", .failure = error.RustR4LUnsupported };
    if (std.mem.eql(u8, kind, "R4D")) return .{ .supported = false, .code = "rust-driver-lifecycle-unqualified", .reason = "Rust driver entry, metadata, callbacks and teardown are not qualified.", .failure = error.RustR4DUnsupported };
    if (std.mem.eql(u8, kind, "R4P")) return .{ .supported = false, .code = "rust-protocol-lifecycle-unqualified", .reason = "Rust protocol registration, callbacks and teardown are not qualified.", .failure = error.RustR4PUnsupported };
    if (role != null) return .{ .supported = false, .code = "rust-subsystem-host-unqualified", .reason = "Rust subsystem host/resolver/media and cleanup helpers are not qualified.", .failure = error.RustSubsystemUnsupported };
    if (!std.ascii.eqlIgnoreCase(entry, "app")) return .{ .supported = false, .code = "rust-lowlevel-entry-unqualified", .reason = "Only the normal R4XStart app entry is admitted for Rust.", .failure = error.RustLowlevelUnsupported };
    if (execution == .native_r4os) return .{ .supported = false, .code = "rust-native-compiler-unavailable", .reason = "Rust compilation requires the pinned Windows/Linux host tools; R4OS has no native Rust compiler.", .failure = error.RustNativeCompilerUnavailable };
    return .{ .supported = true, .code = "supported", .reason = "Rust R4X app console/gui/service semantic profile; compiler installation is a separate check." };
}

pub fn requireRustHost(kind: []const u8, entry: []const u8, role: ?[]const u8) !void {
    const decision = rust(kind, entry, role, .host);
    if (decision.failure) |err| return err;
    if (!rust_host_builder) return error.RustHostBuilderNotYetQualified;
}
