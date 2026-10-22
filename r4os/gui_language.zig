//! Concrete spelling of the public structural selection parameter. The
//! rendering implementation and all clipping/Unicode work remain in gui.zig.
const g = @import("gui.zig");
pub fn drawTextFieldEx(canvas: g.Canvas, rect: g.Rect, scratch: []u8, value: []const u8, cursor: usize, selection: g.TextRange, focused: bool, disabled: bool, palette: g.Palette) i32 {
    return g.drawTextFieldEx(canvas, rect, scratch, value, cursor, selection, focused, disabled, palette);
}
