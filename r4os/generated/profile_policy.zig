// Generated from Profiles/Build.json by Tools/Sync-ProfilePolicy.ps1. DO NOT EDIT.
pub const source_sha256 = "e95e5fd511255341e1b0e13414d97552479fe8e8804d4b421ef729147895d96c";
pub const Profile = struct { id: []const u8, language: []const u8, role: []const u8, generation: u8, explicit_platform: bool };
pub const profiles = [_]Profile{
    .{ .id = "r4os-c-generation2", .language = "C", .role = "module", .generation = 2, .explicit_platform = true },
    .{ .id = "r4os-c-module-v1", .language = "C", .role = "module", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-host-tools-v1", .language = "Zig", .role = "host", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-kernel-rust-v1", .language = "Rust", .role = "kernel", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-native-graphics-v1", .language = "C++", .role = "native", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-recovery-zig-v1", .language = "Zig", .role = "recovery", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-rust-generation2", .language = "Rust", .role = "module", .generation = 2, .explicit_platform = true },
    .{ .id = "r4os-rust-r4d-v1", .language = "Rust", .role = "module", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-rust-r4l-v1", .language = "Rust", .role = "module", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-rust-r4p-v1", .language = "Rust", .role = "module", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-rust-r4x-lowlevel-v1", .language = "Rust", .role = "module", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-rust-r4x-v2", .language = "Rust", .role = "module", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-zig-generation2", .language = "Zig", .role = "module", .generation = 2, .explicit_platform = true },
    .{ .id = "r4os-zig-module-v1", .language = "Zig", .role = "module", .generation = 1, .explicit_platform = false },
};
