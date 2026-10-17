//! Private allocator wait channels. No allocator call, caller-stack node or
//! new platform API is needed. A notification lives until its last waiter has
//! left; failed close retains the exact handle for a later close attempt.
const std = @import("std");
const abi = @import("r4os_contract").abi;

pub const Channel = struct {
    lock: u32 = 0,
    active: u32 = 0,
    handle: u64 = 0,
    references: u32 = 0,
    changing: bool = false,

    fn enter(self: *Channel) void {
        while (@cmpxchgWeak(u32, &self.lock, 0, 1, .acquire, .monotonic) != null) std.atomic.spinLoopHint();
    }
    fn leave(self: *Channel) void {
        @atomicStore(u32, &self.lock, 0, .release);
    }

    pub fn enroll(self: *Channel, api: *const abi.R4XStartR4Sys) ?Ticket {
        if (!supports(api)) return null;
        self.enter();
        if (self.changing or self.references == std.math.maxInt(u32)) {
            self.leave();
            return null;
        }
        if (self.handle == 0) {
            self.changing = true;
            @atomicStore(u32, &self.active, 1, .release);
            self.leave();
            var handle: u64 = 0;
            const rc = call(api, "notification_create")(&handle);
            self.enter();
            std.debug.assert(self.changing and self.handle == 0 and self.references == 0);
            self.changing = false;
            if (rc != abi.notification_ok or handle == 0) {
                @atomicStore(u32, &self.active, 0, .release);
                self.leave();
                return null;
            }
            self.handle = handle;
        }
        self.references += 1;
        const handle = self.handle;
        self.leave();
        var ticket: Ticket = .{ .channel = self, .api = api, .handle = handle };
        if (!ticket.observe()) {
            ticket.deinit();
            return null;
        }
        return ticket;
    }

    /// Notify while the handle is borrowed. This callback only advances the
    /// kernel revision and wakes enrolled tasks; it never waits for a task.
    pub fn notify(self: *Channel, api: *const abi.R4XStartR4Sys) void {
        if (@atomicLoad(u32, &self.active, .acquire) == 0) return;
        self.enter();
        defer self.leave();
        if (self.handle != 0 and !self.changing and self.references != 0) {
            _ = call(api, "notification_notify")(self.handle, std.math.maxInt(u32));
        }
    }

    /// Call only with the allocator metadata lock released. Closing can enter
    /// the kernel allocator; a new enrollment cannot borrow a closing handle.
    pub fn prune(self: *Channel, api: *const abi.R4XStartR4Sys) void {
        if (@atomicLoad(u32, &self.active, .acquire) == 0) return;
        self.enter();
        if (self.handle == 0 or self.changing or self.references != 0) {
            self.leave();
            return;
        }
        self.changing = true;
        const handle = self.handle;
        self.leave();
        const rc = call(api, "notification_close")(handle);
        self.enter();
        std.debug.assert(self.changing and self.handle == handle and self.references == 0);
        if (rc == abi.notification_ok or rc == abi.notification_error_stale) {
            self.handle = 0;
            @atomicStore(u32, &self.active, 0, .release);
        }
        self.changing = false;
        self.leave();
    }
};

pub const Ticket = struct {
    channel: *Channel,
    api: *const abi.R4XStartR4Sys,
    handle: u64,
    sequence: u64 = 0,

    pub fn observe(self: *Ticket) bool {
        return call(self.api, "notification_query")(self.handle, &self.sequence) == abi.notification_ok;
    }
    pub fn wait(self: Ticket) void {
        // The caller rechecks its predicate after observe and before parking.
        // Kernel enrollment compares this same revision atomically with wake.
        if (call(self.api, "notification_wait")(self.handle, self.sequence, abi.thread_wait_forever) < 0) pause(self.api);
    }
    pub fn deinit(self: Ticket) void {
        self.channel.enter();
        defer self.channel.leave();
        std.debug.assert(!self.channel.changing and self.channel.handle == self.handle and self.channel.references != 0);
        self.channel.references -= 1;
    }
};

fn supports(api: *const abi.R4XStartR4Sys) bool {
    return api.magic == abi.r4xstart_r4sys_magic and
        api.size >= @offsetOf(abi.R4XStartR4Sys, "notification_close") + @sizeOf(usize) and
        api.notification_create != 0 and api.notification_query != 0 and api.notification_notify != 0 and
        api.notification_wait != 0 and api.notification_close != 0;
}

fn call(api: *const abi.R4XStartR4Sys, comptime field: []const u8) @field(abi.R4SysFns, field) {
    return @ptrFromInt(@field(api.*, field));
}

pub fn pause(api: ?*const abi.R4XStartR4Sys) void {
    if (api) |table| {
        if (table.magic != abi.r4xstart_r4sys_magic) return;
        if (table.size >= @offsetOf(abi.R4XStartR4Sys, "sleep_ticks") + @sizeOf(usize) and table.sleep_ticks != 0) {
            call(table, "sleep_ticks")(1);
        } else if (table.size >= @offsetOf(abi.R4XStartR4Sys, "task_yield") + @sizeOf(usize) and table.task_yield != 0) {
            call(table, "task_yield")();
        }
    }
    std.atomic.spinLoopHint();
}
