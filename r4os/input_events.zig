//! Wire-only console transport. UTF-8 decoding remains with the text library.
const abi = @import("r4os_contract").abi;

pub fn text(value: u32) ?abi.ConsoleInputEvent {
    if (value > 0x10ffff or (value >= 0xd800 and value <= 0xdfff)) return null;
    return .{ .kind = abi.console_input_event_text, .value = value };
}
pub fn key(value: u8) abi.ConsoleInputEvent {
    return .{ .kind = abi.console_input_event_key, .value = value };
}
pub fn utf8Byte(value: u8) abi.ConsoleInputEvent {
    return .{ .kind = abi.console_input_event_utf8_byte, .value = value };
}
pub fn valid(event: abi.ConsoleInputEvent) bool {
    if (event.version != 1 or event.flags != 0) return false;
    return switch (event.kind) {
        abi.console_input_event_text => text(event.value) != null,
        abi.console_input_event_key, abi.console_input_event_utf8_byte => event.value <= 255,
        else => false,
    };
}

/// Caller-owned pending events. Failed admission leaves the old queue intact;
/// only an explicitly acknowledged prefix may be consumed. Bind the enclosing
/// producer to its exact process handle and clear it when that binding closes.
pub fn Queue(comptime capacity: usize) type {
    return struct {
        const Self = @This();
        data: [capacity]abi.ConsoleInputEvent = undefined,
        head: usize = 0,
        len: usize = 0,

        pub fn append(self: *Self, events: []const abi.ConsoleInputEvent) bool {
            if (events.len > capacity - self.len) return false;
            for (events) |event| if (!valid(event)) return false;
            for (events) |event| {
                self.data[(self.head + self.len) % capacity] = event;
                self.len += 1;
            }
            return true;
        }
        pub fn peek(self: *const Self) []const abi.ConsoleInputEvent {
            return self.data[self.head..][0..@min(self.len, capacity - self.head)];
        }
        pub fn consume(self: *Self, count: usize) bool {
            if (count > self.len) return false;
            self.head = (self.head + count) % capacity;
            self.len -= count;
            return true;
        }
        pub fn clear(self: *Self) void { self.head = 0; self.len = 0; }
    };
}

test "console event validation and retained full/partial/wrapped producer queue" {
    const std = @import("std");
    var queue: Queue(3) = .{};
    const initial = [_]abi.ConsoleInputEvent{ text(0x401).?, key(0x80), utf8Byte(0x81) };
    try std.testing.expect(queue.append(&initial));
    try std.testing.expect(!queue.append(&.{text(0x1f600).?}));
    try std.testing.expectEqual(@as(usize, 3), queue.len);
    try std.testing.expect(queue.consume(1));
    try std.testing.expect(queue.append(&.{text(0x1f600).?}));
    try std.testing.expectEqual(abi.console_input_event_key, queue.peek()[0].kind);
    try std.testing.expectEqual(@as(u32, 0x81), queue.peek()[1].value);
    try std.testing.expect(queue.consume(2));
    try std.testing.expectEqual(@as(u32, 0x1f600), queue.peek()[0].value);
    try std.testing.expect(!queue.consume(2));
    try std.testing.expect(!queue.append(&.{.{ .kind = 1, .value = 0xd800 }}));
    try std.testing.expectEqual(@as(usize, 1), queue.len);
    try std.testing.expect(text(0) != null);
    try std.testing.expect(text(0x110000) == null);
}
