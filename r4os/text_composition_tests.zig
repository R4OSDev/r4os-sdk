const std = @import("std");
const o = @import("text_composition.zig");
const a = @import("r4os_contract").abi;
const t = std.testing;
fn h(id: u32) a.ProgramProcessHandle {
    return .{ .instance_id = id, .generation = 100 + id };
}
fn focus() o.Focus {
    return .{ .window = .{ .service = h(1), .desktop = h(2), .owner = h(3), .serial = 8 }, .view_generation = 9, .focus_generation = 10, .input_revision = 11, .observed_tick = 12, .focused = 1 };
}
fn provider() o.Provider {
    return .{ .process = h(4), .generation = 15, .features = 1 };
}
fn event(id: o.Id, seq: u64, kind: u32, revision: u64, range: o.Range, text: []const u8) o.Event {
    return .{ .id = id, .sequence = seq, .kind = kind, .text_revision = revision, .replacement = range, .selection = .{ .end = text.len }, .text_bytes = @intCast(text.len) };
}
fn begin(state: *o.Owner, revision: u64, doc: []const u8, range: o.Range) !o.Id {
    var id: o.Id = undefined;
    try t.expectEqual(@as(i32, 0), o.Owner.init(99, state));
    try t.expectEqual(@as(i32, 0), state.begin(focus(), provider(), revision, doc, range, .{}, &id));
    return id;
}
test "composition owner preedit leaves document exact until original valid commit" {
    var doc: [64]u8 = @splat(0xa5);
    @memcpy(doc[0..4], "abcd");
    var len: usize = 4;
    var rev: u64 = 7;
    var state: o.Owner = undefined;
    const id = try begin(&state, rev, doc[0..len], .{ .start = 1, .end = 3 });
    const before = doc;
    try t.expectEqual(@as(i32, 0), state.apply(focus(), provider(), event(id, 1, 1, rev, .{ .start = 1, .end = 3 }, "e\u{301}"), "e\u{301}", &doc, &len, &rev));
    try t.expectEqualDeep(before, doc);
    try t.expectEqualStrings("e\u{301}", state.preedit().?);
    try t.expectEqual(@as(u64, 7), rev);
    try t.expectEqual(@as(i32, 0), state.apply(focus(), provider(), event(id, 2, 2, rev, .{ .start = 1, .end = 3 }, "\u{1f469}\u{200d}\u{1f4bb}"), "\u{1f469}\u{200d}\u{1f4bb}", &doc, &len, &rev));
    try t.expectEqualStrings("a\u{1f469}\u{200d}\u{1f4bb}d", doc[0..len]);
    try t.expectEqual(@as(u64, 8), rev);
    try t.expect(state.preedit() == null);
}
test "composition owner rejects scalar-interior grapheme ranges invalid UTF8 NUL and whole capacity" {
    var doc: [16]u8 = @splat(0xa5);
    @memcpy(doc[0..4], "e\u{301}x");
    var len: usize = 4;
    var rev: u64 = 1;
    var state: o.Owner = undefined;
    const id = try begin(&state, rev, doc[0..len], .{});
    const before = doc;
    var e = event(id, 1, 1, rev, .{ .start = 1, .end = 3 }, "ok");
    try t.expectEqual(a.composition_error_range, state.apply(focus(), provider(), e, "ok", &doc, &len, &rev));
    e = event(id, 1, 1, rev, .{}, "e\u{301}");
    e.selection.end = 1;
    try t.expectEqual(a.composition_error_range, state.apply(focus(), provider(), e, "e\u{301}", &doc, &len, &rev));
    const bad = [_]u8{ 0xc0, 0xaf };
    try t.expectEqual(a.composition_error_encoding, state.apply(focus(), provider(), event(id, 1, 1, rev, .{}, &bad), &bad, &doc, &len, &rev));
    try t.expectEqual(a.composition_error_encoding, state.apply(focus(), provider(), event(id, 1, 1, rev, .{}, "a\x00"), "a\x00", &doc, &len, &rev));
    const large = [_]u8{'x'} ** 1025;
    try t.expectEqual(a.composition_error_capacity, state.apply(focus(), provider(), event(id, 1, 1, rev, .{}, &large), &large, &doc, &len, &rev));
    try t.expectEqualDeep(before, doc);
    try t.expectEqual(@as(usize, 4), len);
    try t.expectEqual(@as(u64, 1), rev);
    const full = [_]u8{'x'} ** 16;
    try t.expectEqual(a.composition_error_capacity, state.apply(focus(), provider(), event(id, 1, 2, rev, .{}, &full), &full, &doc, &len, &rev));
    try t.expectEqualDeep(before, doc);
}
test "composition owner focus view provider and text changes cancel only matching old session" {
    var state: o.Owner = undefined;
    var doc = [_]u8{'a'} ** 16;
    var len: usize = 1;
    var rev: u64 = 1;
    var id = try begin(&state, rev, doc[0..len], .{});
    const before = doc;
    var view = focus();
    view.focused = 0;
    try t.expectEqual(a.composition_error_no_focus, state.apply(view, provider(), event(id, 1, 2, rev, .{}, "b"), "b", &doc, &len, &rev));
    try t.expect(state.preedit() == null);
    try t.expectEqualDeep(before, doc);
    try t.expectEqual(@as(i32, 0), state.begin(focus(), provider(), rev, doc[0..len], .{}, .{}, &id));
    view = focus();
    view.window.owner.generation += 1;
    try t.expectEqual(a.composition_error_stale_view, state.refresh(view, provider(), rev));
    try t.expectEqual(@as(i32, 0), state.begin(focus(), provider(), rev, doc[0..len], .{}, .{}, &id));
    view = focus();
    view.focus_generation += 1;
    try t.expectEqual(a.composition_error_stale_view, state.refresh(view, provider(), rev));
    try t.expectEqual(@as(i32, 0), state.begin(focus(), provider(), rev, doc[0..len], .{}, .{}, &id));
    var method = provider();
    method.generation += 1;
    try t.expectEqual(a.composition_error_provider_changed, state.refresh(focus(), method, rev));
    try t.expectEqual(@as(i32, 0), state.begin(focus(), provider(), rev, doc[0..len], .{}, .{}, &id));
    try t.expectEqual(a.composition_error_stale_text, state.refresh(focus(), provider(), 2));
    try t.expectEqualDeep(before, doc);
}
test "composition owner stale cancel replay and superseded events cannot affect newer session" {
    var state: o.Owner = undefined;
    var doc = [_]u8{'a'} ** 16;
    var len: usize = 1;
    var rev: u64 = 1;
    const old = try begin(&state, rev, doc[0..len], .{});
    try t.expectEqual(@as(i32, 0), state.cancel(old));
    var id: o.Id = undefined;
    try t.expectEqual(@as(i32, 0), state.begin(focus(), provider(), rev, doc[0..len], .{}, .{}, &id));
    try t.expect(id.session_generation > old.session_generation);
    try t.expectEqual(a.composition_error_stale_session, state.cancel(old));
    var lost = focus();
    lost.focused = 0;
    try t.expectEqual(a.composition_error_stale_session, state.apply(lost, provider(), event(old, 2, 2, rev, .{}, "b"), "b", &doc, &len, &rev));
    try t.expect(state.preedit() != null);
    const e = event(id, 1, 1, rev, .{}, "b");
    try t.expectEqual(@as(i32, 0), state.apply(focus(), provider(), e, "b", &doc, &len, &rev));
    try t.expectEqual(a.composition_error_stale_session, state.apply(focus(), provider(), e, "b", &doc, &len, &rev));
    try t.expectEqualStrings("b", state.preedit().?);
    try t.expectEqual(@as(i32, 0), state.apply(focus(), provider(), event(id, 2, 3, rev, .{}, ""), "", &doc, &len, &rev));
    try t.expect(state.preedit() == null);
    try t.expectEqual(@as(u8, 'a'), doc[0]);
}
test "composition owner bounded surrounding caret scope NoProvider and nonwrapping identities" {
    var state: o.Owner = undefined;
    const text = "Ae\u{301}B";
    _ = try begin(&state, 1, text, .{});
    var bytes: [16]u8 = @splat(0xa5);
    var count: usize = 99;
    try t.expectEqual(a.composition_error_range, state.surrounding(focus(), provider(), 1, text, .{ .start = 2, .end = 4 }, &bytes, &count));
    try t.expectEqual(@as(usize, 99), count);
    try t.expectEqual(@as(i32, 0), state.surrounding(focus(), provider(), 1, text, .{ .start = 1, .end = 4 }, &bytes, &count));
    try t.expectEqualStrings("e\u{301}", bytes[0..count]);
    var caret: o.Caret = undefined;
    try t.expectEqual(@as(i32, 0), state.setCaret(focus(), provider(), 1, .{ .x = 3, .y = 4, .height = 12, .scale_numerator = 3, .scale_denominator = 2 }));
    try t.expectEqual(@as(i32, 0), state.queryCaret(focus(), provider(), 1, &caret));
    try t.expectEqual(@as(i32, 3), caret.x);
    try t.expectEqual(@as(u32, 2), caret.scale_denominator);
    _ = state.cancel(state.id);
    var id: o.Id = undefined;
    try t.expectEqual(a.composition_error_no_provider, state.begin(focus(), .{}, 1, text, .{}, .{}, &id));
    state.next_generation = std.math.maxInt(u64);
    try t.expectEqual(a.composition_error_exhausted, state.begin(focus(), provider(), 1, text, .{}, .{}, &id));
}
