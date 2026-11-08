//! Checked, clock-bound budgets. These are SDK values, not kernel handles.
const std = @import("std");
const abi = @import("r4os_contract").abi;

pub const Error = error{ UnknownFrequency, InvalidTimeout, BudgetOverflow, ClockUnavailable, ClockChanged, ClockRegressed, InvalidBudget };
pub const Kind = enum(u32) { poll = 0, finite = 1, forever = 2 };
pub const Value = extern struct {
    kind: u32 = @intFromEnum(Kind.poll),
    reserved: u32 = 0,
    value: u64 = 0,
};
pub const ClockIdentity = extern struct {
    source: u32 = 0,
    generation: u32 = 0,
    event_backend: u32 = 0,
    tick_hz: u32 = 0,
};
pub const ClockSample = extern struct {
    identity: ClockIdentity = .{},
    instant_ns: u64 = 0,

    /// Logical ticks use requested_hz. The rounded physical event frequency
    /// and the source's hardware frequency are different units.
    pub fn fromInfo(info: abi.MonotonicClockInfo) Error!ClockSample {
        if (info.version != 1 or info.size < @sizeOf(abi.MonotonicClockInfo) or
            info.flags & abi.monotonic_clock_flag_valid == 0 or
            info.source == abi.monotonic_clock_source_unavailable or info.generation == 0 or
            info.frequency_hz != abi.monotonic_clock_frequency_hz or info.resolution_ns == 0)
            return error.ClockUnavailable;
        return .{ .identity = .{ .source = info.source, .generation = info.generation, .event_backend = info.event_backend, .tick_hz = info.event_requested_hz }, .instant_ns = info.instant_ns };
    }
    pub fn validate(self: ClockSample) Error!void {
        if (self.identity.source == 0 or self.identity.generation == 0) return error.ClockUnavailable;
    }
};

/// Shared u128 arithmetic for the old saturating and new checked surfaces.
/// Quotient/remainder rounding cannot overflow the u128 intermediate.
pub fn scaleCeil(value: u64, numerator: u64, denominator: u64) Error!u64 {
    if (denominator == 0) return error.UnknownFrequency;
    const product = @as(u128, value) * numerator;
    const result = product / denominator + @intFromBool(product % denominator != 0);
    if (result > std.math.maxInt(u64)) return error.BudgetOverflow;
    return @intCast(result);
}
pub fn millisecondsToTicks(milliseconds: u64, hz: u32) Error!u64 {
    if (hz == 0) return error.UnknownFrequency;
    return scaleCeil(milliseconds, hz, 1000);
}
pub fn durationToTicks(duration: abi.R4Duration, hz: u32) Error!u64 {
    if (hz == 0) return error.UnknownFrequency;
    return scaleCeil(duration.nanoseconds, hz, abi.nanoseconds_per_second);
}
pub fn fromTimeout(timeout: abi.R4Timeout) Error!Value {
    for (timeout.reserved) |byte| if (byte != 0) return error.InvalidTimeout;
    switch (timeout.kind) {
        abi.timeout_kind_poll, abi.timeout_kind_forever => {
            if (timeout.nanoseconds != 0) return error.InvalidTimeout;
            return .{ .kind = if (timeout.kind == abi.timeout_kind_poll) 0 else 2 };
        },
        abi.timeout_kind_finite => return .{ .kind = if (timeout.nanoseconds == 0) 0 else 1, .value = timeout.nanoseconds },
        else => return error.InvalidTimeout,
    }
}
pub fn timeoutTicks(timeout: abi.R4Timeout, hz: u32) Error!Value {
    var result = try fromTimeout(timeout);
    if (result.kind == 1) result.value = try durationToTicks(.{ .nanoseconds = result.value }, hz);
    return result;
}

pub const DeadlineBudget = extern struct {
    identity: ClockIdentity = .{},
    deadline_ns: u64 = 0,
    last_ns: u64 = 0,
    kind: u32 = 0,
    reserved: u32 = 0,

    pub fn init(sample: ClockSample, timeout: abi.R4Timeout) Error!DeadlineBudget {
        try sample.validate();
        const budget = try fromTimeout(timeout);
        const end = if (budget.kind == 2) 0 else std.math.add(u64, sample.instant_ns, budget.value) catch return error.BudgetOverflow;
        return .{ .identity = sample.identity, .deadline_ns = end, .last_ns = sample.instant_ns, .kind = budget.kind };
    }
    /// A failed observation does not alter the budget or silently rebase it.
    pub fn remaining(self: *DeadlineBudget, sample: ClockSample) Error!Value {
        if (self.kind > 2 or self.reserved != 0) return error.InvalidBudget;
        try sample.validate();
        if (!std.meta.eql(self.identity, sample.identity)) return error.ClockChanged;
        if (sample.instant_ns < self.last_ns) return error.ClockRegressed;
        self.last_ns = sample.instant_ns;
        if (self.kind == 2) return .{ .kind = 2 };
        if (sample.instant_ns >= self.deadline_ns) return .{};
        return .{ .kind = 1, .value = self.deadline_ns - sample.instant_ns };
    }
};

test "checked budget conversion preserves poll finite forever and full arithmetic range" {
    for ([_]u32{ 100, 128, 333, 1000 }) |hz| {
        try std.testing.expectEqual(@as(u64, 0), try millisecondsToTicks(0, hz));
        try std.testing.expectEqual(@as(u64, 1), try millisecondsToTicks(1, hz));
        try std.testing.expectEqual(@as(u64, hz), try millisecondsToTicks(1000, hz));
        try std.testing.expectEqual(@as(u64, 1), try durationToTicks(.{ .nanoseconds = 1 }, hz));
    }
    try std.testing.expectEqual(std.math.maxInt(u64), try millisecondsToTicks(std.math.maxInt(u64), 1000));
    try std.testing.expectError(error.BudgetOverflow, millisecondsToTicks(std.math.maxInt(u64), 1001));
    try std.testing.expectEqual(std.math.maxInt(u64), try scaleCeil(std.math.maxInt(u64), std.math.maxInt(u64), std.math.maxInt(u64)));
    try std.testing.expectError(error.UnknownFrequency, millisecondsToTicks(0, 0));
    try std.testing.expectError(error.UnknownFrequency, durationToTicks(.{}, 0));
    try std.testing.expectEqual(@as(u32, 0), (try timeoutTicks(.{}, 0)).kind);
    try std.testing.expectEqual(@as(u32, 2), (try timeoutTicks(.{ .kind = abi.timeout_kind_forever }, 0)).kind);
    const max_finite = try timeoutTicks(.{ .kind = abi.timeout_kind_finite, .nanoseconds = std.math.maxInt(u64) }, 1_000_000_000);
    try std.testing.expectEqual(@as(u32, 1), max_finite.kind);
    try std.testing.expectEqual(std.math.maxInt(u64), max_finite.value);
    try std.testing.expectError(error.InvalidTimeout, fromTimeout(.{ .kind = abi.timeout_kind_forever, .nanoseconds = 1 }));
}

test "checked budget deadline binds one clock and never rebases on change or regression" {
    const sample = ClockSample{ .identity = .{ .source = 1, .generation = 9, .tick_hz = 333 }, .instant_ns = 100 };
    var deadline = try DeadlineBudget.init(sample, .{ .kind = abi.timeout_kind_finite, .nanoseconds = 10 });
    var next = sample;
    next.instant_ns = 109;
    try std.testing.expectEqual(@as(u64, 1), (try deadline.remaining(next)).value);
    next.identity.generation += 1;
    const before = deadline;
    try std.testing.expectError(error.ClockChanged, deadline.remaining(next));
    try std.testing.expectEqualDeep(before, deadline);
    next = sample;
    try std.testing.expectError(error.ClockRegressed, deadline.remaining(next));
    next.instant_ns = 110;
    try std.testing.expectEqual(@as(u32, 0), (try deadline.remaining(next)).kind);
    next.instant_ns = std.math.maxInt(u64);
    try std.testing.expectError(error.BudgetOverflow, DeadlineBudget.init(next, .{ .kind = abi.timeout_kind_finite, .nanoseconds = 1 }));
    var forever = try DeadlineBudget.init(next, .{ .kind = abi.timeout_kind_forever });
    try std.testing.expectEqual(@as(u32, 2), (try forever.remaining(next)).kind);
}
