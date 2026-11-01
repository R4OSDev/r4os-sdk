const std = @import("std");
const r4sys = @import("r4sys.zig");
const server_profile = @import("server_profile.zig");

pub const Kind = enum {
    registration,
    benchmark_bearer,
};

pub const Error = error{
    CredentialsMissing,
    CredentialsInvalid,
    SecretMissing,
    SecretInvalid,
};

pub const Secret = struct {
    data: [256]u8 = .{0} ** 256,
    len: u16 = 0,

    pub fn bytes(self: *const Secret) []const u8 {
        return self.data[0..self.len];
    }

    pub fn clear(self: *Secret) void {
        std.crypto.secureZero(u8, &self.data);
        self.len = 0;
    }
};

/// Credentials are loaded only from a local file absent from the default
/// image. Callers must clear the returned buffer after use.
pub fn load(ctx: *const r4sys.Context, kind: Kind) Error!Secret {
    var document: [1024]u8 = undefined;
    defer std.crypto.secureZero(u8, &document);
    const count = ctx.fileRead(server_profile.credentials_path, &document);
    if (count == -3) return error.CredentialsMissing;
    if (count <= 0 or count >= document.len) return error.CredentialsInvalid;
    return parse(document[0..@intCast(count)], kind);
}

pub fn parse(document: []const u8, kind: Kind) Error!Secret {
    var data = document;
    if (std.mem.startsWith(u8, data, "\xef\xbb\xbf")) data = data[3..];
    const wanted = switch (kind) {
        .registration => "REGISTRATION_SECRET",
        .benchmark_bearer => "BENCHMARK_BEARER",
    };
    var schema_seen = false;
    var selected: ?[]const u8 = null;
    var lines = std.mem.splitScalar(u8, data, '\n');
    while (lines.next()) |raw| {
        const line = std.mem.trimEnd(u8, raw, "\r");
        if (line.len == 0 or line[0] == '#') continue;
        const separator = std.mem.indexOfScalar(u8, line, '=') orelse return error.CredentialsInvalid;
        const key = line[0..separator];
        const value = line[separator + 1 ..];
        if (std.mem.eql(u8, key, "SCHEMA")) {
            if (schema_seen or !std.mem.eql(u8, value, "R4OS_SERVER_CREDENTIALS")) return error.CredentialsInvalid;
            schema_seen = true;
        } else if (std.mem.eql(u8, key, wanted)) {
            if (selected != null) return error.CredentialsInvalid;
            selected = value;
        }
    }
    if (!schema_seen) return error.CredentialsInvalid;
    const value = selected orelse return error.SecretMissing;
    if (value.len == 0 or value.len > 256) return error.SecretInvalid;
    for (value) |byte| {
        if (byte < 0x21 or byte > 0x7e) return error.SecretInvalid;
    }
    var secret: Secret = .{};
    @memcpy(secret.data[0..value.len], value);
    secret.len = @intCast(value.len);
    return secret;
}

test "server credentials are local, explicit and bounded" {
    var secret = try parse("SCHEMA=R4OS_SERVER_CREDENTIALS\nREGISTRATION_SECRET=sample-secret\n", .registration);
    defer secret.clear();
    try std.testing.expectEqualStrings("sample-secret", secret.bytes());
    try std.testing.expectError(error.SecretMissing, parse("SCHEMA=R4OS_SERVER_CREDENTIALS\n", .benchmark_bearer));
    try std.testing.expectError(error.SecretInvalid, parse("SCHEMA=R4OS_SERVER_CREDENTIALS\nBENCHMARK_BEARER=bad token\n", .benchmark_bearer));
}
