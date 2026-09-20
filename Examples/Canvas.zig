//! A hosted, event-driven window using the ordinary transactional R4DRAW path.
const r = @import("r4os");

pub fn r4_app_main(app: *r.App) i32 {
    var timers: [0]r.Timer = .{};
    var window = r.Window.init(app.system(), app.desktop() orelse return -1,
        app.drawing() orelse return -1, &timers) orelse return -1;
    _ = window.setTitle("Canvas example");
    _ = window.setMinimumSize(240, 120);
    var dirty = true;
    while (true) {
        if (dirty) {
            var paint = switch (window.beginPaint()) {
                .paint => |value| value,
                .failure => return -1,
            };
            defer paint.discard();
            var commands: [8]r.abi.GuiFrameCommand = undefined;
            var resources: [256]u8 = undefined;
            var builder: r.app_gui.FrameCanvas = undefined;
            const canvas = paint.bufferedCanvas(&builder, &commands, &resources);
            var text: [64]u8 = undefined;
            // Width and height are the complete current client dimensions.
            if (canvas.clear(0x182030) < 0 or
                canvas.rect(.{ .x = 12, .y = 12, .w = canvas.w - 24, .h = canvas.h - 24 }, 0x284060) < 0 or
                canvas.label(.{ .rect = .{ .x = 20, .y = 24, .w = canvas.w - 40, .h = 20 },
                    .text = "Shared R4DRAW canvas", .fg = 0xffffff, .bg = 0x284060 }, &text) < 0 or
                paint.present() < 0) return -1;
            dirty = false;
        }
        switch (window.waitMessage(.{ .kind = r.abi.timeout_kind_forever })) {
            .message => |message| switch (message) {
                .close => return 0,
                .resize => dirty = true,
                else => {},
            },
            .timed_out => {},
            .failure => return -1,
        }
    }
}
