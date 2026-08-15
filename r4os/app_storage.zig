const abi = @import("r4os_contract").abi;
const path_contract = @import("path.zig");
const file_stream = @import("file_stream.zig");
const r4sys = @import("r4sys.zig");

pub const FilePath = path_contract.FilePath;
pub const AbsoluteFilePath = path_contract.AbsoluteFilePath;
pub const RelativeFilePath = path_contract.RelativeFilePath;
pub const RegistryPath = path_contract.RegistryPath;
pub const PathZ = path_contract.PathZ;

pub const Console = struct {
    sys: r4sys.Context,

    pub fn write(self: *const Console, bytes: []const u8) void {
        self.sys.write(bytes);
    }

    pub fn line(self: *const Console, bytes: []const u8) void {
        self.sys.println(bytes);
    }

    pub fn put(self: *const Console, byte: u8) void {
        self.sys.putc(byte);
    }
};

pub const Transfer = union(enum) {
    bytes: u32,
    end,
    failure: i32,
};

pub const Operation = union(enum) {
    ok,
    missing,
    failure: i32,
};

pub const AtomicReplaceOptions = struct {
    consume_stage: bool = true,
    require_target_absent: bool = false,
    require_owned_stage: bool = false,

    pub fn valid(self: AtomicReplaceOptions) bool {
        if (!self.consume_stage and (self.require_target_absent or self.require_owned_stage)) return false;
        if (self.require_owned_stage and !self.require_target_absent) return false;
        return true;
    }
};

pub const AtomicReplaceResult = union(enum) {
    ok,
    conflict,
    missing,
    unsupported,
    bad_path,
    failure: i32,
};

pub const FileInfoResult = union(enum) {
    value: abi.FileInfo,
    missing,
    failure: i32,
};

pub const DirectoryKind = enum(u8) { file, directory };

pub const DirectoryEntry = struct {
    kind: DirectoryKind,
    path: []const u8,
};

pub const DirectoryNext = union(enum) {
    entry: DirectoryEntry,
    end,
    failure: i32,
};

pub const Files = struct {
    sys: r4sys.Context,

    pub fn available(self: *const Files) bool {
        return self.sys.hasFn("file_read") and self.sys.hasFn("file_write") and
            self.sys.hasFn("file_read_at") and self.sys.hasFn("file_append");
    }

    pub fn read(self: *const Files, file_path: PathZ, out: []u8) Transfer {
        const raw = self.sys.fileRead(file_path.ptr, out);
        if (raw < 0) return .{ .failure = raw };
        if (raw == 0) return .end;
        return .{ .bytes = @intCast(raw) };
    }

    pub fn readAt(self: *const Files, file_path: PathZ, offset: u32, out: []u8) Transfer {
        const raw = self.sys.fileReadAt(file_path.ptr, offset, out);
        if (raw < 0) return .{ .failure = raw };
        if (raw == 0) return .end;
        return .{ .bytes = @intCast(raw) };
    }

    pub fn write(self: *const Files, file_path: PathZ, bytes: []const u8) Transfer {
        const raw = self.sys.fileWrite(file_path.ptr, bytes);
        if (raw < 0) return .{ .failure = raw };
        return .{ .bytes = @intCast(raw) };
    }

    pub fn append(self: *const Files, file_path: PathZ, bytes: []const u8) Transfer {
        const raw = self.sys.fileAppend(file_path.ptr, bytes);
        if (raw < 0) return .{ .failure = raw };
        return .{ .bytes = @intCast(raw) };
    }

    pub fn info(self: *const Files, file_path: PathZ) FileInfoResult {
        var value: abi.FileInfo = .{};
        const raw = self.sys.fileInfoRaw(file_path.ptr, &value);
        if (raw < 0) return .{ .failure = raw };
        if (raw == 0 or value.exists == 0) return .missing;
        return .{ .value = value };
    }

    pub fn delete(self: *const Files, file_path: PathZ) Operation {
        return classifyPresenceOperation(self.sys.fileDelete(file_path.ptr));
    }

    pub fn rename(self: *const Files, source: PathZ, target: PathZ) Operation {
        return classifyPresenceOperation(self.sys.fileRename(source.ptr, target.ptr));
    }

    pub fn createDirectory(self: *const Files, directory: PathZ) Operation {
        return classifyPresenceOperation(self.sys.dirCreate(directory.ptr));
    }

    pub fn deleteDirectory(self: *const Files, directory: PathZ) Operation {
        return classifyPresenceOperation(self.sys.dirDelete(directory.ptr));
    }

    pub fn iterate(self: Files, directory: PathZ) DirectoryIterator {
        return .{ .files = self, .directory = directory };
    }

    pub fn streamReader(self: Files, file_path: PathZ) StreamReader {
        return .{ .files = self, .path = file_path };
    }

    pub fn streamWriter(self: Files, file_path: PathZ, flags: u32) StreamWriterOpen {
        var writer = StreamWriter{ .files = self, .state = undefined };
        if (!file_stream.begin(&writer.files.sys, &writer.state, file_path.ptr, flags)) {
            return .{ .failure = writer.state.error_code };
        }
        return .{ .writer = writer };
    }

    /// Creates a private, create-only stream stage and retains its exact
    /// ownership after the final flush.  The returned writer can only be
    /// consumed by `replaceAtomic` with both create-only options enabled.
    pub fn ownedCreateWriter(self: Files, file_path: PathZ) OwnedStageWriterOpen {
        const owned_path = AbsoluteFilePath.parse(file_path.bytes()) catch
            return .{ .failure = abi.file_stream_error_invalid };
        var writer = OwnedStageWriter{ .files = self, .path = owned_path, .state = undefined };
        const flags = abi.file_stream_open_create | r4sys.file_stream_open_lease;
        if (!file_stream.begin(&writer.files.sys, &writer.state, writer.path.asZ().ptr, flags)) {
            return .{ .failure = writer.state.error_code };
        }
        return .{ .writer = writer };
    }

    /// Same-directory, no-fallback atomic replacement through the existing
    /// R4SYS slot.  Paths remain typed by the storage facade; callers never
    /// need to reach through `Files.sys`.
    pub fn replaceAtomic(
        self: *const Files,
        target: PathZ,
        staged: PathZ,
        backup: PathZ,
        options: AtomicReplaceOptions,
    ) AtomicReplaceResult {
        if (!options.valid()) return .{ .failure = r4sys.file_replace_atomic_error_invalid };
        const raw = self.sys.fileReplaceAtomic(target.ptr, staged.ptr, backup.ptr, atomicReplaceFlags(options));
        return classifyAtomicReplace(raw);
    }

    pub fn copy(self: *const Files, source: PathZ, target: PathZ, scratch: []u8) file_stream.CopyResult {
        return file_stream.copy(&self.sys, source.ptr, target.ptr, scratch);
    }
};

pub const DirectoryIterator = struct {
    files: Files,
    directory: PathZ,
    index: u32 = 2,
    ended: bool = false,

    pub fn next(self: *DirectoryIterator, out_path: []u8) DirectoryNext {
        if (self.ended) return .end;
        if (out_path.len == 0) return .{ .failure = abi.file_stream_error_invalid };
        @memset(out_path, 0);
        const raw = self.files.sys.dirEntry(self.directory.ptr, self.index, out_path);
        if (raw == r4sys.dir_entry_result_end) {
            self.ended = true;
            return .end;
        }
        if (raw < 0) return .{ .failure = raw };
        self.index += 1;
        return .{ .entry = .{
            .kind = if (raw == 1) .directory else .file,
            .path = spanZ(out_path),
        } };
    }

    /// R4SYS directory indices address the Nth currently live entry.  After
    /// removing the entry just returned by `next`, its successor shifts into
    /// that same logical index and must be visited before advancing again.
    pub fn revisitAfterRemoval(self: *DirectoryIterator) void {
        if (self.index > 2) self.index -= 1;
        self.ended = false;
    }
};

pub const StreamReader = struct {
    files: Files,
    path: PathZ,
    offset: u64 = 0,
    ended: bool = false,

    pub fn read(self: *StreamReader, out: []u8) Transfer {
        if (self.ended) return .end;
        if (self.offset > 0xFFFF_FFFF) return .{ .failure = abi.file_stream_error_too_large };
        const result = self.files.readAt(self.path, @intCast(self.offset), out);
        switch (result) {
            .bytes => |count| self.offset += count,
            .end => self.ended = true,
            .failure => {},
        }
        return result;
    }
};

pub const StreamWriterOpen = union(enum) {
    writer: StreamWriter,
    failure: i32,
};

pub const StreamWriter = struct {
    files: Files,
    state: file_stream.WriterState,

    pub fn write(self: *StreamWriter, bytes: []const u8) Operation {
        if (file_stream.write(&self.files.sys, &self.state, bytes)) return .ok;
        return .{ .failure = self.state.error_code };
    }

    pub fn finish(self: *StreamWriter) Operation {
        if (file_stream.finish(&self.files.sys, &self.state)) return .ok;
        return .{ .failure = self.state.error_code };
    }

    pub fn abort(self: *StreamWriter) Operation {
        const raw = file_stream.abort(&self.files.sys, &self.state);
        if (raw == abi.file_stream_result_ok) return .ok;
        return .{ .failure = raw };
    }
};

pub const OwnedStageWriterOpen = union(enum) {
    writer: OwnedStageWriter,
    failure: i32,
};

pub const OwnedStageWriter = struct {
    files: Files,
    /// `WriterState.path` is a borrowed pointer.  The writer therefore owns
    /// the typed path and rebinds that pointer after every possible struct
    /// move before it enters R4SYS.
    path: AbsoluteFilePath,
    state: file_stream.WriterState,
    owned: bool = false,

    pub fn write(self: *OwnedStageWriter, bytes: []const u8) Operation {
        self.rebindPath();
        if (file_stream.write(&self.files.sys, &self.state, bytes)) return .ok;
        return .{ .failure = self.state.error_code };
    }

    pub fn finishKeepOwnership(self: *OwnedStageWriter) Operation {
        if (!self.state.active) return .{ .failure = abi.file_stream_error_invalid };
        self.rebindPath();
        const raw = self.files.sys.fileStreamFinish(
            self.state.path,
            self.state.offset,
            r4sys.file_stream_finish_keep_ownership,
        );
        self.state.error_code = raw;
        self.state.active = false;
        self.owned = raw == abi.file_stream_result_ok;
        if (self.owned) return .ok;
        return .{ .failure = raw };
    }

    /// Releases a live or retained stream slot.  After an ambiguous publish
    /// failure R4SYS deliberately keeps any path whose ownership is no longer
    /// provable; this method surfaces that failure instead of deleting blind.
    pub fn abort(self: *OwnedStageWriter) Operation {
        self.rebindPath();
        const raw = self.files.sys.fileStreamAbort(self.state.path);
        self.state.error_code = raw;
        self.state.active = false;
        self.owned = false;
        if (raw == abi.file_stream_result_ok) return .ok;
        return .{ .failure = raw };
    }

    fn rebindPath(self: *OwnedStageWriter) void {
        self.state.path = self.path.asZ().ptr;
    }
};

pub const RegistryValue = struct {
    info: abi.RegistryValueInfo,
    bytes: []const u8,

    pub fn asU32(self: RegistryValue) ?u32 {
        if (self.info.value_type != abi.registry_value_type_u32 or self.bytes.len != 4) return null;
        return readLe(u32, self.bytes);
    }

    pub fn asU64(self: RegistryValue) ?u64 {
        if (self.info.value_type != abi.registry_value_type_u64 or self.bytes.len != 8) return null;
        return readLe(u64, self.bytes);
    }

    pub fn asBool(self: RegistryValue) ?bool {
        if (self.info.value_type != abi.registry_value_type_bool or self.bytes.len != 1 or self.bytes[0] > 1) return null;
        return self.bytes[0] != 0;
    }

    pub fn asString(self: RegistryValue) ?[]const u8 {
        if (self.info.value_type != abi.registry_value_type_string) return null;
        return self.bytes;
    }
};

pub const RegistryRead = union(enum) {
    value: RegistryValue,
    missing,
    failure: i32,
};

pub const Registry = struct {
    sys: r4sys.Context,

    pub fn available(self: *const Registry) bool {
        return self.sys.hasFn("registry_get_value") and self.sys.hasFn("registry_set_value");
    }

    pub fn get(self: *const Registry, key: *const RegistryPath, name: [*:0]const u8, out: []u8) RegistryRead {
        var info: abi.RegistryValueInfo = .{};
        const raw = self.sys.registryGetValue(key.asZ().ptr, name, &info, out);
        if (raw == abi.registry_api_result_value_not_found or raw == abi.registry_api_result_key_not_found) return .missing;
        if (raw < 0) return .{ .failure = raw };
        if (@as(usize, @intCast(raw)) > out.len) return .{ .failure = abi.registry_api_result_buffer_too_small };
        return .{ .value = .{ .info = info, .bytes = out[0..@as(usize, @intCast(raw))] } };
    }

    pub fn setString(self: *const Registry, key: *const RegistryPath, name: [*:0]const u8, value: []const u8) Operation {
        return classifyRegistryOperation(self.sys.registrySetString(key.asZ().ptr, name, value));
    }

    pub fn setU32(self: *const Registry, key: *const RegistryPath, name: [*:0]const u8, value: u32) Operation {
        return classifyRegistryOperation(self.sys.registrySetU32(key.asZ().ptr, name, value));
    }

    pub fn setU64(self: *const Registry, key: *const RegistryPath, name: [*:0]const u8, value: u64) Operation {
        return classifyRegistryOperation(self.sys.registrySetU64(key.asZ().ptr, name, value));
    }

    pub fn setBool(self: *const Registry, key: *const RegistryPath, name: [*:0]const u8, value: bool) Operation {
        return classifyRegistryOperation(self.sys.registrySetBool(key.asZ().ptr, name, value));
    }

    pub fn setBinary(self: *const Registry, key: *const RegistryPath, name: [*:0]const u8, value: []const u8) Operation {
        return classifyRegistryOperation(self.sys.registrySetBinary(key.asZ().ptr, name, value));
    }

    pub fn delete(self: *const Registry, key: *const RegistryPath, name: [*:0]const u8) Operation {
        const raw = self.sys.registryDeleteValue(key.asZ().ptr, name);
        if (raw == abi.registry_api_result_value_not_found or raw == abi.registry_api_result_key_not_found) return .missing;
        return classifyRegistryOperation(raw);
    }
};

fn classifyPresenceOperation(raw: i32) Operation {
    if (raw < 0) return .{ .failure = raw };
    if (raw == 0) return .missing;
    return .ok;
}

fn atomicReplaceFlags(options: AtomicReplaceOptions) u32 {
    var flags: u32 = 0;
    if (options.consume_stage) flags |= r4sys.file_replace_atomic_flag_consume_stage;
    if (options.require_target_absent) flags |= r4sys.file_replace_atomic_flag_require_target_absent;
    if (options.require_owned_stage) flags |= r4sys.file_replace_atomic_flag_require_owned_stage;
    return flags;
}

fn classifyAtomicReplace(raw: i32) AtomicReplaceResult {
    return switch (raw) {
        r4sys.file_replace_atomic_result_ok => .ok,
        r4sys.file_replace_atomic_error_conflict, r4sys.file_replace_atomic_error_alias => .conflict,
        r4sys.file_replace_atomic_error_not_found => .missing,
        r4sys.file_replace_atomic_error_unsupported, r4sys.file_replace_atomic_error_not_atomic => .unsupported,
        r4sys.file_replace_atomic_error_bad_path => .bad_path,
        else => .{ .failure = raw },
    };
}

fn classifyRegistryOperation(raw: i32) Operation {
    if (raw < 0) return .{ .failure = raw };
    return .ok;
}

fn spanZ(bytes: []const u8) []const u8 {
    var len: usize = 0;
    while (len < bytes.len and bytes[len] != 0) : (len += 1) {}
    return bytes[0..len];
}

fn readLe(comptime T: type, bytes: []const u8) T {
    var value: T = 0;
    for (bytes, 0..) |byte, index| value |= @as(T, byte) << @intCast(index * 8);
    return value;
}

test "storage facade preserves owned create-only atomic publish options" {
    const create_only = AtomicReplaceOptions{
        .consume_stage = true,
        .require_target_absent = true,
        .require_owned_stage = true,
    };
    try @import("std").testing.expect(create_only.valid());
    try @import("std").testing.expectEqual(
        r4sys.file_replace_atomic_flag_consume_stage |
            r4sys.file_replace_atomic_flag_require_target_absent |
            r4sys.file_replace_atomic_flag_require_owned_stage,
        atomicReplaceFlags(create_only),
    );
    try @import("std").testing.expect(!(AtomicReplaceOptions{ .require_owned_stage = true }).valid());
    try @import("std").testing.expectEqual(AtomicReplaceResult.ok, classifyAtomicReplace(r4sys.file_replace_atomic_result_ok));
    try @import("std").testing.expectEqual(AtomicReplaceResult.conflict, classifyAtomicReplace(r4sys.file_replace_atomic_error_conflict));
    try @import("std").testing.expectEqual(AtomicReplaceResult.unsupported, classifyAtomicReplace(r4sys.file_replace_atomic_error_not_atomic));
}

test "owned stage writer rebinds its path after a struct move" {
    const original = try AbsoluteFilePath.parse("C:\\R4OS\\TEMP\\OWNED.TMP");
    const source = OwnedStageWriter{
        .files = undefined,
        .path = original,
        .state = .{ .path = original.asZ().ptr },
    };
    var moved = source;
    moved.rebindPath();

    const rebound = moved.path.asZ();
    try @import("std").testing.expectEqual(@intFromPtr(rebound.ptr), @intFromPtr(moved.state.path));
    try @import("std").testing.expectEqualStrings("C:\\R4OS\\TEMP\\OWNED.TMP", moved.state.path[0..rebound.len]);
}

test "directory iterator revisits the shifted live entry after removal" {
    var iterator = DirectoryIterator{
        .files = undefined,
        .directory = undefined,
        .index = 5,
        .ended = true,
    };
    iterator.revisitAfterRemoval();
    try @import("std").testing.expectEqual(@as(u32, 4), iterator.index);
    try @import("std").testing.expect(!iterator.ended);
    iterator.index = 2;
    iterator.revisitAfterRemoval();
    try @import("std").testing.expectEqual(@as(u32, 2), iterator.index);
}
