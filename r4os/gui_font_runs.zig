//! Optional UTF-8 text with application-owned R4FONT faces. Layout and drawing
//! share one prepared run. A run is borrowed until the next prepare/deinit.
const std = @import("std");
const gui = @import("gui.zig");
const abi = @import("r4os_contract").abi;

pub const Run = struct {
    advance: i32,
    truncated: bool = false,
    width: u32,
    height: u32,
    top: i32,
    mask: []u8,

    /// The caller supplies the typographic baseline and the horizontal cell.
    pub fn draw(self: Run, canvas: gui.Canvas, x: i32, baseline: i32, cell_width: i32, alignment: gui.Align, color: u32) void {
        _ = self.drawChecked(canvas, x, baseline, cell_width, alignment, color);
    }

    pub fn drawChecked(self: Run, canvas: gui.Canvas, x: i32, baseline: i32, cell_width: i32, alignment: gui.Align, color: u32) i32 {
        const left = x + switch (alignment) {
            .left => @as(i32, 0),
            .center => @divFloor(cell_width - self.advance, 2),
            .right => cell_width - self.advance,
        };
        const visible_w: u32 = @intCast(@min(@as(i64, self.width), @max(0, @as(i64, x) + cell_width - left)));
        var column: u32 = 0;
        while (column < visible_w and self.height > 0) {
            const width = @min(abi.gui_alpha8_max_width, visible_w - column);
            // The wire limit applies to each packed command. Canvas snapshots
            // rows using the source stride, including for a cropped run.
            const rows = @min(abi.gui_alpha8_max_height, abi.gui_alpha8_max_pixels / width);
            var y: u32 = 0;
            while (y < self.height) {
                const height = @min(rows, self.height - y);
                const offset = @as(usize, y) * self.width + column;
                const result = canvas.blendAlpha8(left + @as(i32, @intCast(column)), baseline + self.top + @as(i32, @intCast(y)), width, height, self.width, color, self.mask[offset..]);
                if (result < 0) return result;
                y += height;
            }
            column += width;
        }
        return 0;
    }
};

/// No R4FONT import or allocation is introduced for users of resident fonts.
pub fn FontRuns(comptime fonts: type) type {
    return struct {
        const Self = @This();
        const Face = fonts.FaceHandle;
        const Entry = struct { face: Face, size: u32, limit: i32, text: []u8, run: Run };
        const Glyph = struct { index: u32, origin: i32, end: i32 };
        const slots = 128;
        const byte_budget = 512 * 1024;
        allocator: std.mem.Allocator,
        entries: [slots]?Entry = @splat(null),
        cursor: usize = 0,
        bytes: usize = 0,
        positions: std.ArrayList(Glyph) = .empty,

        pub fn deinit(self: *Self) void {
            for (&self.entries) |*slot| self.release(slot);
            self.positions.deinit(self.allocator);
        }
        fn release(self: *Self, slot: *?Entry) void {
            const entry = slot.* orelse return;
            self.bytes -= entry.text.len + entry.run.mask.len;
            self.allocator.free(entry.text);
            self.allocator.free(entry.run.mask);
            slot.* = null;
        }

        pub fn prepare(self: *Self, store: *fonts.FaceStore, face: Face, size: u32, limit: i32, text: []const u8) !Run {
            if (limit < 0 or text.len > 4096) return error.TooLarge;
            for (&self.entries) |*slot| if (slot.*) |entry| {
                if (entry.size == size and (entry.limit == limit or (!entry.run.truncated and entry.run.advance <= limit)) and std.meta.eql(entry.face, face) and std.mem.eql(u8, entry.text, text)) return entry.run;
            };
            const run = try self.make(store, face, size, limit, text);
            errdefer self.allocator.free(run.mask);
            const cost = run.mask.len + text.len;
            if (cost > byte_budget) return error.TooLarge;
            const key = try self.allocator.dupe(u8, text);
            while (true) {
                self.release(&self.entries[self.cursor]);
                if (self.bytes + cost <= byte_budget) break;
                self.cursor = (self.cursor + 1) % slots;
            }
            self.entries[self.cursor] = .{ .face = face, .size = size, .limit = limit, .text = key, .run = run };
            self.cursor = (self.cursor + 1) % slots;
            self.bytes += cost;
            return run;
        }

        fn pixels(v: i32) i32 {
            return @divFloor(v + 32, 64);
        }
        fn add(self: *Self, store: *fonts.FaceStore, face: Face, size: u32, index: u32, limit: i32) !bool {
            const last = self.positions.getLastOrNull();
            const origin = if (last) |prev| prev.end + (try store.kerningAt(face, prev.index, index, size))[0] else 0;
            const g = try store.rasterizeCached(face, index, size);
            const end = origin + g.advance_x_26_6;
            if (pixels(end) > limit) return false;
            try self.positions.append(self.allocator, .{ .index = index, .origin = pixels(origin), .end = end });
            return true;
        }
        fn make(self: *Self, store: *fonts.FaceStore, face: Face, size: u32, limit: i32, text: []const u8) !Run {
            self.positions.clearRetainingCapacity();
            var truncated = false;
            var iter = (try std.unicode.Utf8View.init(text)).iterator();
            while (iter.nextCodepoint()) |cp| {
                const index = (try store.glyphIndex(face, cp)) orelse return error.MissingGlyph;
                if (try self.add(store, face, size, index, limit)) continue;
                truncated = true;
                const ellipsis = (try store.glyphIndex(face, '…')) orelse return error.MissingGlyph;
                while (!try self.add(store, face, size, ellipsis, limit)) {
                    if (self.positions.pop() == null) break;
                }
                break;
            }
            var top: i32 = 0;
            var bottom: i32 = 0;
            var right: i32 = 0;
            for (self.positions.items) |p| {
                const g = try store.rasterizeCached(face, p.index, size);
                top = @min(top, -g.top);
                bottom = @max(bottom, @as(i32, @intCast(g.height)) - g.top);
                right = @max(right, p.origin + g.left + @as(i32, @intCast(g.width)));
            }
            const width: u32 = @intCast(@min(limit, right));
            const height: u32 = @intCast(bottom - top);
            const length = @as(usize, width) * height;
            if (length + text.len > byte_budget) return error.TooLarge;
            const mask = try self.allocator.alloc(u8, length);
            errdefer self.allocator.free(mask);
            @memset(mask, 0);
            for (self.positions.items) |p| {
                const g = try store.rasterizeCached(face, p.index, size);
                const x = p.origin + g.left;
                const begin: usize = @intCast(@max(0, -x));
                const end: usize = @intCast(@max(0, @min(@as(i32, @intCast(g.width)), @as(i32, @intCast(width)) - x)));
                if (begin >= end) continue;
                const dest_x: usize = @intCast(x + @as(i32, @intCast(begin)));
                for (0..g.height) |y| {
                    const row = (y + @as(usize, @intCast(-g.top - top))) * width + dest_x;
                    const source = y * g.width + begin;
                    for (mask[row..][0 .. end - begin], g.alpha[source..][0 .. end - begin]) |*dst, a| dst.* = @max(dst.*, a);
                }
            }
            return .{ .truncated = truncated or right > limit, .advance = if (self.positions.getLastOrNull()) |last| pixels(last.end) else 0, .width = width, .height = height, .top = top, .mask = mask };
        }
    };
}
