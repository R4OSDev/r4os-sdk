const abi = @import("r4os_contract").abi;
const program = @import("program.zig");

pub const name = "R4DRAW";
pub const import_query = "R4DRAW:Query:1";
pub const group = abi.R4LGroup.r4draw;
pub const abi_version = abi.r4l_abi_version;
pub const contract = "Repositories/Contract/API/Groups.txt";
pub const provider_repository = "Repositories/Kernel";
pub const c_header = "Repositories/SDK/Shared/C/include/r4os/r4draw.h";
pub const query_contract = "Repositories/Contract/ABI/R4LQuery.txt";

pub const Context = struct {
    base: program.Context,

    pub fn init(bundle: *const program.Bundle) Context {
        return .{ .base = program.Context.initBundle(bundle) };
    }

    pub fn fromProgram(ctx: program.Context) Context {
        return .{ .base = ctx };
    }

    // 0.57.2: ehrliche Vertragspruefung (ersetzt supports*-Versionsgates).
    pub fn hasFn(self: *const Context, comptime field: []const u8) bool {
        return self.base.hasDrawFn(field);
    }

    pub fn screenWidth(self: *const Context) u32 {
        return self.base.screenWidth();
    }

    pub fn screenHeight(self: *const Context) u32 {
        return self.base.screenHeight();
    }

    pub fn clear(self: *const Context, rgb: u32) void {
        self.base.clear(rgb);
    }

    pub fn rect(self: *const Context, x: i32, y: i32, w: u32, h: u32, rgb: u32) void {
        self.base.rect(x, y, w, h, rgb);
    }

    pub fn text(self: *const Context, x: i32, y: i32, value: [*:0]const u8, fg: u32, bg: u32) void {
        self.base.text(x, y, value, fg, bg);
    }

    pub fn displayRevision(self: *const Context) u32 {
        return self.base.displayRevision();
    }

    pub fn displayBeginFrame(self: *const Context) i32 {
        return self.base.displayBeginFrame();
    }

    pub fn displayBeginFrameRect(self: *const Context, x: i32, y: i32, w: u32, h: u32) i32 {
        return self.base.displayBeginFrameRect(x, y, w, h);
    }

    pub fn displayPresent(self: *const Context) i32 {
        return self.base.displayPresent();
    }

    pub fn displayBlitXrgb32(self: *const Context, x: i32, y: i32, w: u32, h: u32, pixels: []const u32) i32 {
        return self.base.displayXrgb32Blit(x, y, w, h, pixels);
    }

    pub fn guiClear(self: *const Context, rgb: u32) i32 {
        return self.base.guiClear(rgb);
    }

    pub fn guiRect(self: *const Context, x: i32, y: i32, w: u32, h: u32, rgb: u32) i32 {
        return self.base.guiRect(x, y, w, h, rgb);
    }

    pub fn guiDrawText(self: *const Context, x: i32, y: i32, value: [*:0]const u8, fg: u32, bg: u32) i32 {
        return self.base.guiDrawText(x, y, value, fg, bg);
    }

    pub fn guiDrawTextEx(self: *const Context, x: i32, y: i32, value: [*:0]const u8, fg: u32, bg: u32, font_id: u32, flags: u32) i32 {
        return self.base.guiDrawTextEx(x, y, value, fg, bg, font_id, flags);
    }

    pub fn guiBlit(self: *const Context, x: i32, y: i32, w: u32, h: u32, scale: u32, pixels: []const u32) i32 {
        return self.base.guiBlit(x, y, w, h, scale, pixels);
    }

    pub fn guiBlendAlpha8(self: *const Context, x: i32, y: i32, w: u32, h: u32, stride: u32, rgb: u32, alpha: []const u8) i32 {
        return self.base.guiBlendAlpha8(x, y, w, h, stride, rgb, alpha);
    }

    pub fn guiRasterRead(self: *const Context, instance_id: u32, offset: u32, out: []u32) i32 {
        return self.base.guiRasterRead(instance_id, offset, out);
    }

    pub fn supportsGuiFrameContract(self: *const Context) bool {
        return self.base.supportsGuiFrameContract();
    }

    pub fn guiFrameBegin(self: *const Context) i32 {
        return self.base.guiFrameBegin();
    }

    pub fn guiFrameAppend(self: *const Context, commands: []const abi.GuiFrameCommand, resources: []const u8) i32 {
        return self.base.guiFrameAppend(commands, resources);
    }

    pub fn guiFrameCommit(self: *const Context) i32 {
        return self.base.guiFrameCommit();
    }

    pub fn guiFrameCancel(self: *const Context) i32 {
        return self.base.guiFrameCancel();
    }

    pub fn guiFrameInfo(self: *const Context, handle: ?*const abi.ProgramProcessHandle, out: *abi.GuiFrameInfo) i32 {
        return self.base.guiFrameInfo(handle, out);
    }

    pub fn guiFrameRead(self: *const Context, handle: *const abi.ProgramProcessHandle, expected_generation: u64, commands: []abi.GuiFrameCommand, resources: []u8, out: *abi.GuiFrameInfo) i32 {
        return self.base.guiFrameRead(handle, expected_generation, commands, resources, out);
    }

    pub fn guiPresent(self: *const Context) i32 {
        return self.base.guiPresent();
    }

    pub fn fontCount(self: *const Context) u32 {
        return self.base.fontCount();
    }

    pub fn fontInfo(self: *const Context, font_id: u32, out: *abi.GuiFontInfo) i32 {
        return self.base.fontInfo(font_id, out);
    }

    pub fn fontMeasure(self: *const Context, font_id: u32, value: [*:0]const u8, out: *abi.GuiTextMetrics) i32 {
        return self.base.fontMeasure(font_id, value, out);
    }

    pub fn fontGlyphRow(self: *const Context, font_id: u32, codepoint: u32, row: u32) u64 {
        return self.base.fontGlyphRow(font_id, codepoint, row);
    }

    pub fn fontReload(self: *const Context) i32 {
        return self.base.fontReload();
    }

    pub fn guiSetFont(self: *const Context, font_id: u32) i32 {
        return self.base.guiSetFont(font_id);
    }

    pub fn guiFont(self: *const Context, instance_id: u32, out: *abi.GuiFontInfo) i32 {
        return self.base.guiFont(instance_id, out);
    }

    pub fn textFont(self: *const Context, font_id: u32, x: i32, y: i32, value: [*:0]const u8, fg: u32, bg: u32) void {
        self.base.textFont(font_id, x, y, value, fg, bg);
    }
};

test "r4draw exposes project and present ABI metadata" {
    const std = @import("std");
    try std.testing.expectEqualStrings("R4DRAW", name);
    try std.testing.expectEqualStrings("R4DRAW:Query:1", import_query);
    try std.testing.expectEqual(@as(u32, 3), @intFromEnum(group));
    try std.testing.expectEqual(abi.r4l_abi_version, abi_version);
    try std.testing.expectEqual(abi.r4xstart_r4draw_version, (abi.R4XStartR4Draw{}).abi_version);
    try std.testing.expectEqual(abi.remote_frame_format_xrgb32, (abi.RemoteFrameInfo{}).format);
    try std.testing.expectEqualStrings("Repositories/Kernel", provider_repository);
    try std.testing.expectEqualStrings("Repositories/SDK/Shared/C/include/r4os/r4draw.h", c_header);
}
