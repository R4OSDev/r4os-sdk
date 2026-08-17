const std = @import("std");
const abi = @import("r4os_contract").abi;
const r4desk = @import("r4desk.zig");
const r4draw = @import("r4draw.zig");
const raster = @import("raster.zig");

pub const tile_max_width: u32 = raster.max_width;
pub const tile_max_height: u32 = raster.max_height;
pub const tile_max_pixels: usize = raster.max_pixels;
pub const palette_entries: usize = 256;
pub const letterbox_rgb: u32 = 0x000000;
pub const integer_preference_percent: u32 = 85;
pub const max_damage_chain: u32 = 32;

pub const Error = error{
    InvalidSize,
    BufferTooSmall,
    PaletteTooSmall,
    ScratchTooSmall,
    Overflow,
    UnsupportedDrawContract,
    WindowUnavailable,
};

pub const PixelFormat = enum {
    indexed8,
    xrgb32,
};

pub const Indexed8 = struct {
    pixels: []u8,
    palette: []u32,
};

pub const PixelStorage = union(PixelFormat) {
    indexed8: Indexed8,
    xrgb32: []u32,
};

pub const Surface = struct {
    width: u32,
    height: u32,
    storage: PixelStorage,

    pub fn initIndexed8(pixels: []u8, palette_values: []u32, width: u32, height: u32) Error!Surface {
        const count = try requiredPixels(width, height);
        if (pixels.len < count) return Error.BufferTooSmall;
        if (palette_values.len < palette_entries) return Error.PaletteTooSmall;
        return .{
            .width = width,
            .height = height,
            .storage = .{ .indexed8 = .{
                .pixels = pixels[0..count],
                .palette = palette_values[0..palette_entries],
            } },
        };
    }

    pub fn initXrgb32(pixels: []u32, width: u32, height: u32) Error!Surface {
        const count = try requiredPixels(width, height);
        if (pixels.len < count) return Error.BufferTooSmall;
        return .{
            .width = width,
            .height = height,
            .storage = .{ .xrgb32 = pixels[0..count] },
        };
    }

    pub fn format(self: Surface) PixelFormat {
        return std.meta.activeTag(self.storage);
    }

    pub fn pixelCount(self: Surface) usize {
        return @as(usize, self.width) * @as(usize, self.height);
    }

    pub fn indexedPixels(self: *Surface) ?[]u8 {
        return switch (self.storage) {
            .indexed8 => |value| value.pixels,
            .xrgb32 => null,
        };
    }

    pub fn xrgb32Pixels(self: *Surface) ?[]u32 {
        return switch (self.storage) {
            .indexed8 => null,
            .xrgb32 => |value| value,
        };
    }

    pub fn palette(self: *Surface) ?[]u32 {
        return switch (self.storage) {
            .indexed8 => |value| value.palette,
            .xrgb32 => null,
        };
    }

    fn colorAt(self: Surface, x: u32, y: u32) u32 {
        const index = @as(usize, y) * @as(usize, self.width) + @as(usize, x);
        return switch (self.storage) {
            .indexed8 => |value| value.palette[value.pixels[index]] & 0x00FF_FFFF,
            .xrgb32 => |value| value[index] & 0x00FF_FFFF,
        };
    }
};

pub const Rect = struct {
    x: u32,
    y: u32,
    w: u32,
    h: u32,

    pub fn full(width: u32, height: u32) Rect {
        return .{ .x = 0, .y = 0, .w = width, .h = height };
    }

    pub fn isEmpty(self: Rect) bool {
        return self.w == 0 or self.h == 0;
    }
};

pub const Point = struct {
    x: u32,
    y: u32,
};

pub const Size = struct {
    w: u32,
    h: u32,
};

pub const Viewport = struct {
    x: i32,
    y: i32,
    w: u32,
    h: u32,
    guest_w: u32,
    guest_h: u32,
    integer_scale: u32,

    pub fn isInteger(self: Viewport) bool {
        return self.integer_scale != 0;
    }

    pub fn mapClientPoint(self: Viewport, client_x: i32, client_y: i32) ?Point {
        if (client_x < self.x or client_y < self.y) return null;
        const local_x: u64 = @intCast(client_x - self.x);
        const local_y: u64 = @intCast(client_y - self.y);
        if (local_x >= self.w or local_y >= self.h) return null;
        return .{
            .x = @intCast((local_x * self.guest_w) / self.w),
            .y = @intCast((local_y * self.guest_h) / self.h),
        };
    }
};

pub fn calculateViewport(client_w: i32, client_h: i32, guest_w: u32, guest_h: u32) Error!Viewport {
    if (client_w <= 0 or client_h <= 0 or guest_w == 0 or guest_h == 0) return Error.InvalidSize;
    const cw: u32 = @intCast(client_w);
    const ch: u32 = @intCast(client_h);
    const cw64: u64 = cw;
    const ch64: u64 = ch;
    const gw64: u64 = guest_w;
    const gh64: u64 = guest_h;

    var fit_w: u32 = undefined;
    var fit_h: u32 = undefined;
    if (cw64 * gh64 <= ch64 * gw64) {
        fit_w = cw;
        fit_h = @intCast(@max(@as(u64, 1), (gh64 * cw64) / gw64));
    } else {
        fit_h = ch;
        fit_w = @intCast(@max(@as(u64, 1), (gw64 * ch64) / gh64));
    }

    const integer_scale = @min(cw / guest_w, ch / guest_h);
    var view_w = fit_w;
    var view_h = fit_h;
    var selected_integer: u32 = 0;
    if (integer_scale != 0) {
        const integer_w: u64 = gw64 * integer_scale;
        const integer_h: u64 = gh64 * integer_scale;
        const preferred = integer_w * 100 >= @as(u64, fit_w) * integer_preference_percent and
            integer_h * 100 >= @as(u64, fit_h) * integer_preference_percent;
        if (preferred) {
            view_w = @intCast(integer_w);
            view_h = @intCast(integer_h);
            selected_integer = integer_scale;
        }
    }

    return .{
        .x = @intCast((cw - view_w) / 2),
        .y = @intCast((ch - view_h) / 2),
        .w = view_w,
        .h = view_h,
        .guest_w = guest_w,
        .guest_h = guest_h,
        .integer_scale = selected_integer,
    };
}

const DamageKind = enum {
    none,
    full,
    rect,
};

const Damage = struct {
    kind: DamageKind = .full,
    rect: Rect = .{ .x = 0, .y = 0, .w = 0, .h = 0 },

    fn markFull(self: *Damage) void {
        self.kind = .full;
    }

    fn clear(self: *Damage) void {
        self.* = .{ .kind = .none };
    }

    fn mark(self: *Damage, requested: Rect, width: u32, height: u32) void {
        const value = clipRect(requested, width, height) orelse return;
        switch (self.kind) {
            .full => return,
            .none => {
                self.kind = .rect;
                self.rect = value;
            },
            .rect => self.rect = mergeRect(self.rect, value),
        }
        if (rectIsFull(self.rect, width, height)) self.kind = .full;
    }
};

pub const PresentMode = enum {
    full,
    damage,
};

pub const PresentInfo = struct {
    mode: PresentMode,
    viewport: Viewport,
    raster_blocks: u32,
    sampled_pixels: u64,
};

pub const PresentResult = union(enum) {
    unchanged,
    hidden,
    presented: PresentInfo,
    failure: i32,
};

pub const PresentStats = struct {
    published_frames: u64 = 0,
    skipped_frames: u64 = 0,
    full_frames: u64 = 0,
    damage_frames: u64 = 0,
    compacted_frames: u64 = 0,
    raster_blocks: u64 = 0,
    sampled_pixels: u64 = 0,
};

pub const Backend = struct {
    context: *anyopaque,
    begin_full_fn: *const fn (*anyopaque) i32,
    begin_damage_fn: *const fn (*anyopaque) i32,
    clear_fn: *const fn (*anyopaque, u32) i32,
    raster_fn: *const fn (*anyopaque, i32, i32, u32, u32, u32, []const u32) i32,
    commit_full_fn: *const fn (*anyopaque) i32,
    commit_damage_fn: *const fn (*anyopaque) i32,
    cancel_fn: *const fn (*anyopaque) i32,

    pub fn fromDraw(draw: *const r4draw.Context) Backend {
        return .{
            .context = @ptrCast(@constCast(draw)),
            .begin_full_fn = drawBeginFull,
            .begin_damage_fn = drawBeginDamage,
            .clear_fn = drawClear,
            .raster_fn = drawRaster,
            .commit_full_fn = drawCommitFull,
            .commit_damage_fn = drawCommitDamage,
            .cancel_fn = drawCancel,
        };
    }

    fn begin(self: Backend, mode: PresentMode) i32 {
        return switch (mode) {
            .full => self.begin_full_fn(self.context),
            .damage => self.begin_damage_fn(self.context),
        };
    }

    fn clear(self: Backend, rgb: u32) i32 {
        return self.clear_fn(self.context, rgb);
    }

    fn raster(self: Backend, x: i32, y: i32, w: u32, h: u32, scale: u32, pixels: []const u32) i32 {
        return self.raster_fn(self.context, x, y, w, h, scale, pixels);
    }

    fn commit(self: Backend, mode: PresentMode) i32 {
        return switch (mode) {
            .full => self.commit_full_fn(self.context),
            .damage => self.commit_damage_fn(self.context),
        };
    }

    fn cancel(self: Backend) void {
        _ = self.cancel_fn(self.context);
    }
};

pub const Presenter = struct {
    surface: Surface,
    scratch: []u32,
    damage: Damage = .{},
    last_viewport: ?Viewport = null,
    has_frame: bool = false,
    damage_chain: u32 = 0,
    stats: PresentStats = .{},

    pub fn init(surface: Surface, scratch: []u32) Error!Presenter {
        _ = try requiredPixels(surface.width, surface.height);
        if (scratch.len < tile_max_pixels) return Error.ScratchTooSmall;
        return .{ .surface = surface, .scratch = scratch[0..tile_max_pixels] };
    }

    pub fn setSurface(self: *Presenter, surface: Surface) Error!void {
        _ = try requiredPixels(surface.width, surface.height);
        self.surface = surface;
        self.damage.markFull();
        self.last_viewport = null;
        self.damage_chain = 0;
    }

    pub fn invalidateAll(self: *Presenter) void {
        self.damage.markFull();
    }

    pub fn invalidate(self: *Presenter, rect: Rect) void {
        self.damage.mark(rect, self.surface.width, self.surface.height);
    }

    pub fn setPaletteEntry(self: *Presenter, index: u8, rgb: u32) bool {
        switch (self.surface.storage) {
            .indexed8 => |value| {
                value.palette[index] = rgb & 0x00FF_FFFF;
                self.damage.markFull();
                return true;
            },
            .xrgb32 => return false,
        }
    }

    pub fn currentViewport(self: *const Presenter) ?Viewport {
        return self.last_viewport;
    }

    pub fn presentTo(self: *Presenter, backend: Backend, client_w: i32, client_h: i32) PresentResult {
        const viewport = calculateViewport(client_w, client_h, self.surface.width, self.surface.height) catch {
            self.stats.skipped_frames +%= 1;
            return .hidden;
        };
        const geometry_changed = if (self.last_viewport) |last| !viewportEqual(last, viewport) else true;
        if (self.damage.kind == .none and !geometry_changed and self.has_frame) {
            self.stats.skipped_frames +%= 1;
            return .unchanged;
        }

        var compacted = false;
        var mode: PresentMode = if (!self.has_frame or geometry_changed or self.damage.kind == .full) .full else .damage;
        if (mode == .damage and self.damage_chain >= max_damage_chain) {
            mode = .full;
            compacted = true;
        }
        const source_damage = switch (mode) {
            .full => Rect.full(self.surface.width, self.surface.height),
            .damage => self.damage.rect,
        };

        const begun = backend.begin(mode);
        if (begun < 0) return .{ .failure = begun };
        if (mode == .full) {
            const cleared = backend.clear(letterbox_rgb);
            if (cleared < 0) {
                backend.cancel();
                return .{ .failure = cleared };
            }
        }

        const rendered = if (viewport.isInteger())
            renderInteger(self.surface, viewport, source_damage, self.scratch, backend)
        else
            renderFractional(self.surface, viewport, source_damage, self.scratch, backend);
        if (rendered.failure != 0) {
            backend.cancel();
            return .{ .failure = rendered.failure };
        }
        const committed = backend.commit(mode);
        if (committed < 0) {
            backend.cancel();
            return .{ .failure = committed };
        }

        self.has_frame = true;
        self.last_viewport = viewport;
        self.damage.clear();
        self.stats.published_frames +%= 1;
        self.stats.raster_blocks +%= rendered.blocks;
        self.stats.sampled_pixels +%= rendered.sampled_pixels;
        switch (mode) {
            .full => {
                self.stats.full_frames +%= 1;
                self.damage_chain = 0;
                if (compacted) self.stats.compacted_frames +%= 1;
            },
            .damage => {
                self.stats.damage_frames +%= 1;
                self.damage_chain +|= 1;
            },
        }
        return .{ .presented = .{
            .mode = mode,
            .viewport = viewport,
            .raster_blocks = rendered.blocks,
            .sampled_pixels = rendered.sampled_pixels,
        } };
    }
};

pub const MouseAction = enum {
    down,
    up,
    move,
};

pub const KeyEvent = struct {
    code: u32,
    modifiers: u32,
    tick: u64,
};

pub const TextEvent = struct {
    codepoint: u32,
    modifiers: u32,
    tick: u64,
};

pub const MouseEvent = struct {
    action: MouseAction,
    client_x: i32,
    client_y: i32,
    guest: ?Point,
    buttons: u32,
    modifiers: u32,
    tick: u64,
};

pub const ResizeEvent = struct {
    client: Size,
    viewport: Viewport,
    tick: u64,
};

pub const FocusEvent = struct {
    focused: bool,
    tick: u64,
};

pub const InputEvent = union(enum) {
    close: u64,
    resize: ResizeEvent,
    focus: FocusEvent,
    key_down: KeyEvent,
    text: TextEvent,
    mouse: MouseEvent,
};

pub const InputTranslator = struct {
    focused: bool = false,
    pending_text: ?TextEvent = null,

    pub fn takePending(self: *InputTranslator) ?InputEvent {
        if (self.pending_text) |value| {
            self.pending_text = null;
            return .{ .text = value };
        }
        return null;
    }

    pub fn translate(self: *InputTranslator, raw: abi.GuiEvent, viewport: ?Viewport, resize_size: ?Size) ?InputEvent {
        const kind = raw.kind;
        if (kind == @intFromEnum(abi.GuiEventKind.close)) return .{ .close = raw.tick };
        if (kind == @intFromEnum(abi.GuiEventKind.resize)) {
            const size = resize_size orelse return null;
            const view = viewport orelse return null;
            return .{ .resize = .{ .client = size, .viewport = view, .tick = raw.tick } };
        }
        if (kind == @intFromEnum(abi.GuiEventKind.focus_gained)) {
            if (self.focused) return null;
            self.focused = true;
            return .{ .focus = .{ .focused = true, .tick = raw.tick } };
        }
        if (kind == @intFromEnum(abi.GuiEventKind.focus_lost)) {
            if (!self.focused) return null;
            self.focused = false;
            return .{ .focus = .{ .focused = false, .tick = raw.tick } };
        }
        if (kind == @intFromEnum(abi.GuiEventKind.key_down)) {
            if (isTextCodepoint(raw.key)) self.pending_text = .{
                .codepoint = raw.key,
                .modifiers = raw.modifiers,
                .tick = raw.tick,
            };
            return .{ .key_down = .{
                .code = raw.key,
                .modifiers = raw.modifiers,
                .tick = raw.tick,
            } };
        }
        const action: MouseAction = if (kind == @intFromEnum(abi.GuiEventKind.mouse_down))
            .down
        else if (kind == @intFromEnum(abi.GuiEventKind.mouse_up))
            .up
        else if (kind == @intFromEnum(abi.GuiEventKind.mouse_move))
            .move
        else
            return null;
        return .{ .mouse = .{
            .action = action,
            .client_x = raw.x,
            .client_y = raw.y,
            .guest = if (viewport) |value| value.mapClientPoint(raw.x, raw.y) else null,
            .buttons = raw.buttons,
            .modifiers = raw.modifiers,
            .tick = raw.tick,
        } };
    }
};

pub const Host = struct {
    desk: r4desk.Context,
    draw: r4draw.Context,
    video: Presenter,
    input: InputTranslator = .{},
    input_viewport: ?Viewport = null,

    pub fn init(desk: r4desk.Context, draw: r4draw.Context, surface: Surface, scratch: []u32) Error!Host {
        if (!draw.supportsGuiFrameContract() or !draw.hasFn("gui_blit") or
            !draw.hasFn("gui_clear") or !draw.hasFn("gui_present")) return Error.UnsupportedDrawContract;
        if (desk.programWindowId() < 0) return Error.WindowUnavailable;
        return .{
            .desk = desk,
            .draw = draw,
            .video = try Presenter.init(surface, scratch),
        };
    }

    pub fn setTitle(self: *Host, title: [*:0]const u8) i32 {
        return self.desk.guiSetTitle(title);
    }

    pub fn setMinimumSize(self: *Host, width: i32, height: i32) i32 {
        return self.desk.guiSetMinSize(width, height);
    }

    pub fn present(self: *Host) PresentResult {
        var info: abi.GuiWindowInfo = .{};
        const window_result = self.desk.guiWindowInfo(&info);
        if (window_result < 0) return .{ .failure = window_result };
        if ((info.flags & abi.GuiWindowFlag.visible) == 0 or (info.flags & abi.GuiWindowFlag.minimized) != 0) return .hidden;
        const result = self.video.presentTo(Backend.fromDraw(&self.draw), info.client_w, info.client_h);
        switch (result) {
            .presented => |presented| self.input_viewport = presented.viewport,
            .unchanged => self.input_viewport = self.video.currentViewport(),
            else => {},
        }
        return result;
    }

    pub fn pollInput(self: *Host) ?InputEvent {
        if (self.input.takePending()) |event| return event;
        var raw: abi.GuiEvent = .{};
        if (self.desk.guiPollEvent(&raw) <= 0) return null;

        var viewport = self.input_viewport orelse self.video.currentViewport();
        var resize_size: ?Size = null;
        const guest_mode_changed = if (viewport) |value|
            value.guest_w != self.video.surface.width or value.guest_h != self.video.surface.height
        else
            true;
        if (raw.kind == @intFromEnum(abi.GuiEventKind.resize) or guest_mode_changed) {
            var info: abi.GuiWindowInfo = .{};
            if (self.desk.guiWindowInfo(&info) >= 0 and info.client_w > 0 and info.client_h > 0) {
                const size = Size{ .w = @intCast(info.client_w), .h = @intCast(info.client_h) };
                resize_size = size;
                viewport = calculateViewport(info.client_w, info.client_h, self.video.surface.width, self.video.surface.height) catch null;
                self.input_viewport = viewport;
            }
        }
        return self.input.translate(raw, viewport, resize_size);
    }
};

const RenderResult = struct {
    blocks: u32 = 0,
    sampled_pixels: u64 = 0,
    failure: i32 = 0,
};

fn renderInteger(surface: Surface, viewport: Viewport, damage: Rect, scratch: []u32, backend: Backend) RenderResult {
    const source = clipRect(damage, surface.width, surface.height) orelse return .{};
    var result = RenderResult{};
    var tile_y = source.y;
    const source_bottom = source.y + source.h;
    const source_right = source.x + source.w;
    while (tile_y < source_bottom) {
        const tile_h = @min(tile_max_height, source_bottom - tile_y);
        var tile_x = source.x;
        while (tile_x < source_right) {
            const tile_w = @min(tile_max_width, source_right - tile_x);
            const count = @as(usize, tile_w) * @as(usize, tile_h);
            fillGuestTile(surface, tile_x, tile_y, tile_w, tile_h, scratch[0..count]);
            const raw = backend.raster(
                viewport.x + @as(i32, @intCast(tile_x * viewport.integer_scale)),
                viewport.y + @as(i32, @intCast(tile_y * viewport.integer_scale)),
                tile_w,
                tile_h,
                viewport.integer_scale,
                scratch[0..count],
            );
            if (raw < 0) {
                result.failure = raw;
                return result;
            }
            result.blocks +|= 1;
            result.sampled_pixels +|= count;
            tile_x += tile_w;
        }
        tile_y += tile_h;
    }
    return result;
}

fn renderFractional(surface: Surface, viewport: Viewport, damage: Rect, scratch: []u32, backend: Backend) RenderResult {
    const destination = mapDamageToViewport(damage, surface.width, surface.height, viewport.w, viewport.h) orelse return .{};
    var result = RenderResult{};
    var tile_y = destination.y;
    const destination_bottom = destination.y + destination.h;
    const destination_right = destination.x + destination.w;
    while (tile_y < destination_bottom) {
        const tile_h = @min(tile_max_height, destination_bottom - tile_y);
        var tile_x = destination.x;
        while (tile_x < destination_right) {
            const tile_w = @min(tile_max_width, destination_right - tile_x);
            const count = @as(usize, tile_w) * @as(usize, tile_h);
            fillScaledTile(surface, viewport, tile_x, tile_y, tile_w, tile_h, scratch[0..count]);
            const raw = backend.raster(
                viewport.x + @as(i32, @intCast(tile_x)),
                viewport.y + @as(i32, @intCast(tile_y)),
                tile_w,
                tile_h,
                1,
                scratch[0..count],
            );
            if (raw < 0) {
                result.failure = raw;
                return result;
            }
            result.blocks +|= 1;
            result.sampled_pixels +|= count;
            tile_x += tile_w;
        }
        tile_y += tile_h;
    }
    return result;
}

fn fillGuestTile(surface: Surface, start_x: u32, start_y: u32, width: u32, height: u32, out: []u32) void {
    var y: u32 = 0;
    while (y < height) : (y += 1) {
        var x: u32 = 0;
        while (x < width) : (x += 1) {
            out[@as(usize, y) * @as(usize, width) + @as(usize, x)] = surface.colorAt(start_x + x, start_y + y);
        }
    }
}

fn fillScaledTile(surface: Surface, viewport: Viewport, start_x: u32, start_y: u32, width: u32, height: u32, out: []u32) void {
    var y: u32 = 0;
    while (y < height) : (y += 1) {
        const source_y: u32 = @intCast((@as(u64, start_y + y) * surface.height) / viewport.h);
        var x: u32 = 0;
        while (x < width) : (x += 1) {
            const source_x: u32 = @intCast((@as(u64, start_x + x) * surface.width) / viewport.w);
            out[@as(usize, y) * @as(usize, width) + @as(usize, x)] = surface.colorAt(source_x, source_y);
        }
    }
}

fn requiredPixels(width: u32, height: u32) Error!usize {
    if (width == 0 or height == 0) return Error.InvalidSize;
    const total = std.math.mul(u64, width, height) catch return Error.Overflow;
    if (total > std.math.maxInt(usize)) return Error.Overflow;
    return @intCast(total);
}

fn clipRect(value: Rect, width: u32, height: u32) ?Rect {
    if (value.isEmpty() or value.x >= width or value.y >= height) return null;
    const right = @min(@as(u64, width), @as(u64, value.x) + value.w);
    const bottom = @min(@as(u64, height), @as(u64, value.y) + value.h);
    if (right <= value.x or bottom <= value.y) return null;
    return .{
        .x = value.x,
        .y = value.y,
        .w = @intCast(right - value.x),
        .h = @intCast(bottom - value.y),
    };
}

fn mergeRect(a: Rect, b: Rect) Rect {
    const x = @min(a.x, b.x);
    const y = @min(a.y, b.y);
    const right = @max(@as(u64, a.x) + a.w, @as(u64, b.x) + b.w);
    const bottom = @max(@as(u64, a.y) + a.h, @as(u64, b.y) + b.h);
    return .{ .x = x, .y = y, .w = @intCast(right - x), .h = @intCast(bottom - y) };
}

fn rectIsFull(value: Rect, width: u32, height: u32) bool {
    return value.x == 0 and value.y == 0 and value.w == width and value.h == height;
}

fn mapDamageToViewport(value: Rect, guest_w: u32, guest_h: u32, view_w: u32, view_h: u32) ?Rect {
    const clipped = clipRect(value, guest_w, guest_h) orelse return null;
    const left: u64 = (@as(u64, clipped.x) * view_w) / guest_w;
    const top: u64 = (@as(u64, clipped.y) * view_h) / guest_h;
    const source_right = @as(u64, clipped.x) + clipped.w;
    const source_bottom = @as(u64, clipped.y) + clipped.h;
    const right = divideCeil(source_right * view_w, guest_w);
    const bottom = divideCeil(source_bottom * view_h, guest_h);
    if (right <= left or bottom <= top) return null;
    return .{
        .x = @intCast(left),
        .y = @intCast(top),
        .w = @intCast(@min(@as(u64, view_w), right) - left),
        .h = @intCast(@min(@as(u64, view_h), bottom) - top),
    };
}

fn divideCeil(numerator: u64, denominator: u64) u64 {
    return numerator / denominator + @intFromBool(numerator % denominator != 0);
}

fn viewportEqual(a: Viewport, b: Viewport) bool {
    return a.x == b.x and a.y == b.y and a.w == b.w and a.h == b.h and
        a.guest_w == b.guest_w and a.guest_h == b.guest_h and a.integer_scale == b.integer_scale;
}

fn isTextCodepoint(value: u32) bool {
    if (value >= 0x20 and value <= 0x7E) return true;
    if (value < 0xA0 or value > 0x10FFFF) return false;
    return value < 0xD800 or value > 0xDFFF;
}

fn drawContext(context: *anyopaque) *const r4draw.Context {
    return @ptrCast(@alignCast(context));
}

fn drawBeginFull(context: *anyopaque) i32 {
    return drawContext(context).guiFrameBegin();
}

fn drawBeginDamage(_: *anyopaque) i32 {
    return 0;
}

fn drawClear(context: *anyopaque, rgb: u32) i32 {
    return drawContext(context).guiClear(rgb);
}

fn drawRaster(context: *anyopaque, x: i32, y: i32, width: u32, height: u32, scale: u32, pixels: []const u32) i32 {
    return drawContext(context).guiBlit(x, y, width, height, scale, pixels);
}

fn drawCommitFull(context: *anyopaque) i32 {
    return drawContext(context).guiFrameCommit();
}

fn drawCommitDamage(context: *anyopaque) i32 {
    return drawContext(context).guiPresent();
}

fn drawCancel(context: *anyopaque) i32 {
    return drawContext(context).guiFrameCancel();
}

const FakeBackend = struct {
    full_begins: u32 = 0,
    damage_begins: u32 = 0,
    clears: u32 = 0,
    commits: u32 = 0,
    cancels: u32 = 0,
    rasters: u32 = 0,
    max_w: u32 = 0,
    max_h: u32 = 0,
    last_scale: u32 = 0,
    invalid_raster: bool = false,
    captured: [16]u32 = .{0} ** 16,
    captured_len: usize = 0,

    fn backend(self: *FakeBackend) Backend {
        return .{
            .context = self,
            .begin_full_fn = fakeBeginFull,
            .begin_damage_fn = fakeBeginDamage,
            .clear_fn = fakeClear,
            .raster_fn = fakeRaster,
            .commit_full_fn = fakeCommit,
            .commit_damage_fn = fakeCommit,
            .cancel_fn = fakeCancel,
        };
    }
};

fn fakeState(context: *anyopaque) *FakeBackend {
    return @ptrCast(@alignCast(context));
}

fn fakeBeginFull(context: *anyopaque) i32 {
    fakeState(context).full_begins += 1;
    return 0;
}

fn fakeBeginDamage(context: *anyopaque) i32 {
    fakeState(context).damage_begins += 1;
    return 0;
}

fn fakeClear(context: *anyopaque, _: u32) i32 {
    fakeState(context).clears += 1;
    return 0;
}

fn fakeRaster(context: *anyopaque, _: i32, _: i32, width: u32, height: u32, scale: u32, pixels: []const u32) i32 {
    const self = fakeState(context);
    self.rasters += 1;
    self.max_w = @max(self.max_w, width);
    self.max_h = @max(self.max_h, height);
    self.last_scale = scale;
    const needed = @as(usize, width) * @as(usize, height);
    if (width == 0 or height == 0 or width > tile_max_width or height > tile_max_height or pixels.len != needed) self.invalid_raster = true;
    if (self.captured_len == 0) {
        self.captured_len = @min(self.captured.len, pixels.len);
        @memcpy(self.captured[0..self.captured_len], pixels[0..self.captured_len]);
    }
    return 0;
}

fn fakeCommit(context: *anyopaque) i32 {
    fakeState(context).commits += 1;
    return 0;
}

fn fakeCancel(context: *anyopaque) i32 {
    fakeState(context).cancels += 1;
    return 0;
}

test "viewport preserves aspect ratio maps letterbox and prefers useful integer scales" {
    const gorillas = try calculateViewport(1280, 680, 640, 350);
    try std.testing.expectEqual(@as(u32, 1243), gorillas.w);
    try std.testing.expectEqual(@as(u32, 680), gorillas.h);
    try std.testing.expectEqual(@as(u32, 0), gorillas.integer_scale);
    try std.testing.expect(gorillas.mapClientPoint(gorillas.x - 1, gorillas.y) == null);
    try std.testing.expectEqual(Point{ .x = 0, .y = 0 }, gorillas.mapClientPoint(gorillas.x, gorillas.y).?);
    try std.testing.expectEqual(Point{ .x = 639, .y = 349 }, gorillas.mapClientPoint(gorillas.x + @as(i32, @intCast(gorillas.w)) - 1, gorillas.y + @as(i32, @intCast(gorillas.h)) - 1).?);

    const integer = try calculateViewport(1000, 700, 320, 200);
    try std.testing.expectEqual(@as(u32, 3), integer.integer_scale);
    try std.testing.expectEqual(@as(u32, 960), integer.w);
    try std.testing.expectEqual(@as(u32, 600), integer.h);

    const down = try calculateViewport(200, 200, 256, 224);
    try std.testing.expectEqual(@as(u32, 200), down.w);
    try std.testing.expectEqual(@as(u32, 175), down.h);
    try std.testing.expectEqual(@as(i32, 12), down.y);
}

test "640x350 full frame is split into fifteen bounded raster blocks and unchanged frames are skipped" {
    const pixels = try std.testing.allocator.alloc(u32, 640 * 350);
    defer std.testing.allocator.free(pixels);
    @memset(pixels, 0x00112233);
    const scratch = try std.testing.allocator.alloc(u32, tile_max_pixels);
    defer std.testing.allocator.free(scratch);
    var presenter = try Presenter.init(try Surface.initXrgb32(pixels, 640, 350), scratch);
    var fake = FakeBackend{};

    const first = presenter.presentTo(fake.backend(), 640, 350);
    switch (first) {
        .presented => |info| {
            try std.testing.expectEqual(PresentMode.full, info.mode);
            try std.testing.expectEqual(@as(u32, 15), info.raster_blocks);
        },
        else => return error.TestUnexpectedResult,
    }
    try std.testing.expectEqual(@as(u32, 15), fake.rasters);
    try std.testing.expect(!fake.invalid_raster);
    try std.testing.expectEqual(tile_max_width, fake.max_w);
    try std.testing.expectEqual(tile_max_height, fake.max_h);

    try std.testing.expect(presenter.presentTo(fake.backend(), 640, 350) == .unchanged);
    try std.testing.expectEqual(@as(u32, 15), fake.rasters);

    presenter.invalidate(.{ .x = 7, .y = 9, .w = 12, .h = 10 });
    const partial = presenter.presentTo(fake.backend(), 640, 350);
    switch (partial) {
        .presented => |info| {
            try std.testing.expectEqual(PresentMode.damage, info.mode);
            try std.testing.expectEqual(@as(u32, 1), info.raster_blocks);
        },
        else => return error.TestUnexpectedResult,
    }
    try std.testing.expectEqual(@as(u32, 1), fake.damage_begins);
    try std.testing.expectEqual(@as(u32, 16), fake.rasters);
}

test "bounded damage chains compact into a fresh full frame" {
    var pixels = [_]u32{0x00112233} ** (8 * 8);
    var scratch: [tile_max_pixels]u32 = undefined;
    var presenter = try Presenter.init(try Surface.initXrgb32(pixels[0..], 8, 8), scratch[0..]);
    var fake = FakeBackend{};

    try std.testing.expect(presenter.presentTo(fake.backend(), 8, 8) == .presented);
    var index: u32 = 0;
    while (index < max_damage_chain) : (index += 1) {
        presenter.invalidate(.{ .x = index % 8, .y = 0, .w = 1, .h = 1 });
        const result = presenter.presentTo(fake.backend(), 8, 8);
        try std.testing.expect(result.presented.mode == .damage);
    }

    presenter.invalidate(.{ .x = 0, .y = 1, .w = 1, .h = 1 });
    const compacted = presenter.presentTo(fake.backend(), 8, 8);
    try std.testing.expect(compacted.presented.mode == .full);
    try std.testing.expectEqual(@as(u64, 1), presenter.stats.compacted_frames);
    try std.testing.expectEqual(@as(u32, 2), fake.full_begins);
}

test "indexed palette and fractional nearest neighbour scaling produce xrgb tiles" {
    var indices = [_]u8{ 0, 1, 2, 3 };
    var palette_values = [_]u32{0} ** palette_entries;
    palette_values[0] = 0x00000000;
    palette_values[1] = 0x00FF0000;
    palette_values[2] = 0x0000FF00;
    palette_values[3] = 0x000000FF;
    var scratch: [tile_max_pixels]u32 = undefined;
    var presenter = try Presenter.init(try Surface.initIndexed8(indices[0..], palette_values[0..], 2, 2), scratch[0..]);
    var fake = FakeBackend{};
    const result = presenter.presentTo(fake.backend(), 3, 3);
    switch (result) {
        .presented => |info| {
            try std.testing.expectEqual(PresentMode.full, info.mode);
            try std.testing.expectEqual(@as(u32, 0), info.viewport.integer_scale);
        },
        else => return error.TestUnexpectedResult,
    }
    try std.testing.expectEqual(@as(usize, 9), fake.captured_len);
    try std.testing.expectEqualSlices(u32, &.{
        0x00000000, 0x00000000, 0x00FF0000,
        0x00000000, 0x00000000, 0x00FF0000,
        0x0000FF00, 0x0000FF00, 0x000000FF,
    }, fake.captured[0..9]);
    try std.testing.expect(presenter.setPaletteEntry(1, 0xAA123456));
    try std.testing.expectEqual(@as(u32, 0x00123456), palette_values[1]);
}

test "input translation separates text and rejects letterbox coordinates" {
    const viewport = try calculateViewport(200, 200, 256, 224);
    var translator = InputTranslator{};
    const gained = translator.translate(.{
        .kind = @intFromEnum(abi.GuiEventKind.focus_gained),
        .tick = 1,
    }, viewport, null).?;
    try std.testing.expect(gained.focus.focused);

    const key = translator.translate(.{
        .kind = @intFromEnum(abi.GuiEventKind.key_down),
        .key = 'A',
        .modifiers = 2,
        .tick = 2,
    }, viewport, null).?;
    try std.testing.expectEqual(@as(u32, 'A'), key.key_down.code);
    const text_event = translator.takePending().?;
    try std.testing.expectEqual(@as(u32, 'A'), text_event.text.codepoint);

    const outside = translator.translate(.{
        .kind = @intFromEnum(abi.GuiEventKind.mouse_move),
        .x = 10,
        .y = 1,
        .tick = 3,
    }, viewport, null).?;
    try std.testing.expect(outside.mouse.guest == null);
    const inside = translator.translate(.{
        .kind = @intFromEnum(abi.GuiEventKind.mouse_down),
        .x = viewport.x,
        .y = viewport.y,
        .buttons = 1,
        .tick = 4,
    }, viewport, null).?;
    try std.testing.expectEqual(Point{ .x = 0, .y = 0 }, inside.mouse.guest.?);

    const lost = translator.translate(.{
        .kind = @intFromEnum(abi.GuiEventKind.focus_lost),
        .tick = 5,
    }, viewport, null).?;
    try std.testing.expect(!lost.focus.focused);
}

test "resize event carries unchanged guest mode and recalculated viewport" {
    const viewport = try calculateViewport(800, 600, 320, 200);
    var translator = InputTranslator{};
    const event = translator.translate(.{
        .kind = @intFromEnum(abi.GuiEventKind.resize),
        .tick = 9,
    }, viewport, .{ .w = 800, .h = 600 }).?;
    try std.testing.expectEqual(@as(u32, 320), event.resize.viewport.guest_w);
    try std.testing.expectEqual(@as(u32, 200), event.resize.viewport.guest_h);
    try std.testing.expectEqual(@as(u32, 800), event.resize.client.w);
}
