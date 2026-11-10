//! Shared control policy over the original clipboard and composition owners.
//! Caller keeps channel/stage/snapshot identities through explicit Commit,
//! Status/Abort and Release/Close acknowledgement. No automatic retry/fallback.
const std = @import("std");
const a = @import("r4os_contract").abi;
const offers = @import("clipboard_offer.zig");

/// Stages UTF8 item0 only. It never commits, cuts, replaces or loses the token.
pub fn stageText(client: *const offers.Client, stage: *const offers.Lease, text: []const u8) i32 {
    if (stage.state != a.clipboard_offer_state_writing or stage.provider == 0 or stage.id == 0) return a.clipboard_offer_error_invalid;
    if (!std.unicode.utf8ValidateSlice(text) or std.mem.indexOfScalar(u8, text, 0) != null) return a.clipboard_offer_error_invalid_encoding;
    if (text.len > a.clipboard_offer_max_offer_bytes) return a.clipboard_offer_error_too_large;
    var rc = client.declare(stage.*, 0, a.clipboard_offer_format_text_utf8, text.len);
    if (rc != 0) return rc;
    var offset: usize = 0;
    while (offset < text.len) {
        const end = offset + @min(text.len - offset, a.clipboard_offer_put_chunk);
        rc = client.put(stage.*, 0, a.clipboard_offer_format_text_utf8, offset, text.len, text[offset..end]);
        if (rc != 0) return rc;
        offset = end;
    }
    return 0;
}

/// Reads one exact advertised UTF8 representation completely into scratch.
/// Any failure leaves the control untouched and the snapshot with its caller.
pub fn readText(client: *const offers.Client, snapshot: *const offers.Lease, format: *const offers.Format, scratch: []u8) i32 {
    if (snapshot.state != a.clipboard_offer_state_snapshot or snapshot.provider == 0 or snapshot.id == 0 or
        format.item >= a.clipboard_offer_max_items or format.format != a.clipboard_offer_format_text_utf8 or format.flags != 0 or format.reserved != 0) return a.clipboard_offer_error_invalid;
    if (format.total_bytes > a.clipboard_offer_max_offer_bytes or format.total_bytes > scratch.len) return a.clipboard_offer_error_too_large;
    var offset: usize = 0;
    const total: usize = @intCast(format.total_bytes);
    // Even empty formats must validate the exact live snapshot at its owner.
    // A zero-byte read still acknowledges provider/id/revision and EOF.
    var first = true;
    while (first or offset < total) {
        first = false;
        const end = offset + @min(total - offset, a.clipboard_offer_read_chunk);
        var chunk: offers.Chunk = undefined;
        const rc = client.read(snapshot.*, format.item, format.format, offset, scratch[offset..end], &chunk);
        if (rc != 0) return rc;
        if (chunk.total_bytes != total or (total != 0 and chunk.bytes == 0) or chunk.bytes > end - offset) return a.clipboard_offer_error_invalid;
        offset += chunk.bytes;
    }
    const text = scratch[0..total];
    if (!std.unicode.utf8ValidateSlice(text) or std.mem.indexOfScalar(u8, text, 0) != null) return a.clipboard_offer_error_invalid_encoding;
    return @intCast(total);
}
