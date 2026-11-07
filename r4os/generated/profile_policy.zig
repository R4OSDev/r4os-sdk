// Generated from Profiles/Build.json by Tools/Sync-ProfilePolicy.ps1. DO NOT EDIT.
pub const source_sha256 = "dd9e61f4b93d74ddc5c5a0fd96b65b8b56a6693dff526d0c92ce2d026b25559f";
pub const Profile = struct { id: []const u8, language: []const u8, role: []const u8, kind: []const u8, generation: u8, explicit_platform: bool };
pub const profiles = [_]Profile{
    .{ .id = "r4os-c-generation2", .language = "C", .role = "module", .kind = "R4X", .generation = 2, .explicit_platform = true },
    .{ .id = "r4os-c-module-v1", .language = "C", .role = "module", .kind = "", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-c-r4d-generation2", .language = "C", .role = "module", .kind = "R4D", .generation = 2, .explicit_platform = true },
    .{ .id = "r4os-c-r4p-generation2", .language = "C", .role = "module", .kind = "R4P", .generation = 2, .explicit_platform = true },
    .{ .id = "r4os-host-tools-v1", .language = "Zig", .role = "host", .kind = "", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-kernel-rust-v1", .language = "Rust", .role = "kernel", .kind = "", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-native-graphics-v1", .language = "C++", .role = "native", .kind = "", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-recovery-zig-v1", .language = "Zig", .role = "recovery", .kind = "", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-rust-generation2", .language = "Rust", .role = "module", .kind = "R4X", .generation = 2, .explicit_platform = true },
    .{ .id = "r4os-rust-r4d-generation2", .language = "Rust", .role = "module", .kind = "R4D", .generation = 2, .explicit_platform = true },
    .{ .id = "r4os-rust-r4d-v1", .language = "Rust", .role = "module", .kind = "R4D", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-rust-r4l-v1", .language = "Rust", .role = "module", .kind = "R4L", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-rust-r4p-generation2", .language = "Rust", .role = "module", .kind = "R4P", .generation = 2, .explicit_platform = true },
    .{ .id = "r4os-rust-r4p-v1", .language = "Rust", .role = "module", .kind = "R4P", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-rust-r4x-lowlevel-v1", .language = "Rust", .role = "module", .kind = "R4X", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-rust-r4x-v2", .language = "Rust", .role = "module", .kind = "R4X", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-zig-generation2", .language = "Zig", .role = "module", .kind = "R4X", .generation = 2, .explicit_platform = true },
    .{ .id = "r4os-zig-module-v1", .language = "Zig", .role = "module", .kind = "", .generation = 1, .explicit_platform = false },
    .{ .id = "r4os-zig-r4d-generation2", .language = "Zig", .role = "module", .kind = "R4D", .generation = 2, .explicit_platform = true },
    .{ .id = "r4os-zig-r4p-generation2", .language = "Zig", .role = "module", .kind = "R4P", .generation = 2, .explicit_platform = true },
};
