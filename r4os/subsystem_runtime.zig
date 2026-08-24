const std = @import("std");
const abi = @import("r4os_contract").abi;
const app_audio = @import("app_audio.zig");
const r4sys = @import("r4sys.zig");
const time_contract = @import("time_contract.zig");

pub const default_slice_budget: u32 = 4096;
pub const default_max_input_events: u16 = 64;
pub const default_max_wait_ticks: u64 = 1;
pub const default_sample_rate: u32 = 48_000;
pub const default_channels: u16 = 2;
pub const default_quantum_frames: u32 = 480;
pub const default_target_quanta: u16 = 2;
pub const default_max_catchup_quanta: u16 = 2;
const audio_open_retry_limit: u16 = 3;
const audio_open_retry_nanoseconds: u64 = 50 * std.time.ns_per_ms;
pub const audio_error_timeout: i32 = -9601;
pub const audio_error_unavailable: i32 = -9602;
pub const runtime_error_guest_audio: i32 = -9610;
pub const runtime_error_guest_reset: i32 = -9611;
pub const runtime_error_host_poll: i32 = -9612;
pub const runtime_error_host_present: i32 = -9613;

pub const Error = error{
    UnknownFrequency,
    InvalidConfiguration,
    InvalidAudioConfiguration,
    AudioQueueTooSmall,
    AudioScratchTooSmall,
    Overflow,
};

pub const LifecycleState = enum {
    ready,
    running,
    paused,
    completed,
    failed,
    closed,
};

pub const LifecycleCommand = enum {
    none,
    pause,
    resume_running,
    toggle_pause,
    reset,
    mute,
    unmute,
    toggle_mute,
    close,
};

pub const StepStatus = enum {
    progress,
    waiting,
    completed,
    failed,
};

pub const StepResult = struct {
    status: StepStatus = .progress,
    frame_ready: bool = false,
    wake_guest_ns: u64 = 0,
    exit_code: i32 = 0,

    pub fn progress(frame_ready: bool) StepResult {
        return .{ .frame_ready = frame_ready };
    }

    pub fn waitUntil(wake_guest_ns: u64, frame_ready: bool) StepResult {
        return .{ .status = .waiting, .frame_ready = frame_ready, .wake_guest_ns = wake_guest_ns };
    }

    pub fn complete(exit_code: i32, frame_ready: bool) StepResult {
        return .{ .status = .completed, .frame_ready = frame_ready, .exit_code = exit_code };
    }

    pub fn fail(exit_code: i32) StepResult {
        return .{ .status = .failed, .exit_code = exit_code };
    }
};

pub const HostPollResult = union(enum) {
    idle,
    handled,
    present,
    command: LifecycleCommand,
    failure: i32,
};

pub const GuestDriver = struct {
    context: *anyopaque,
    step_fn: *const fn (*anyopaque, u32, u64) StepResult,
    reset_fn: *const fn (*anyopaque) i32,
    render_audio_fn: *const fn (*anyopaque, []u8) i32,

    pub fn step(self: GuestDriver, budget: u32, guest_now_ns: u64) StepResult {
        return self.step_fn(self.context, budget, guest_now_ns);
    }

    pub fn reset(self: GuestDriver) i32 {
        return self.reset_fn(self.context);
    }

    pub fn renderAudio(self: GuestDriver, out: []u8) i32 {
        return self.render_audio_fn(self.context, out);
    }
};

pub const HostDriver = struct {
    context: *anyopaque,
    poll_fn: *const fn (*anyopaque) HostPollResult,
    present_fn: *const fn (*anyopaque) i32,

    pub fn poll(self: HostDriver) HostPollResult {
        return self.poll_fn(self.context);
    }

    pub fn present(self: HostDriver) i32 {
        return self.present_fn(self.context);
    }
};

pub const GuestClock = struct {
    monotonic_hz: u32,
    last_host_tick: u64 = 0,
    guest_ns: u64 = 0,
    remainder: u64 = 0,
    paused: bool = false,

    pub fn init(monotonic_hz: u32, host_tick: u64) Error!GuestClock {
        if (monotonic_hz == 0) return Error.UnknownFrequency;
        return .{ .monotonic_hz = monotonic_hz, .last_host_tick = host_tick };
    }

    pub fn sync(self: *GuestClock, host_tick: u64) u64 {
        const delta = host_tick -| self.last_host_tick;
        self.last_host_tick = host_tick;
        if (self.paused or delta == 0) return self.guest_ns;

        const product = @as(u128, delta) * time_contract.nanoseconds_per_second + self.remainder;
        const advanced = product / self.monotonic_hz;
        self.remainder = @intCast(product % self.monotonic_hz);
        self.guest_ns +|= if (advanced > std.math.maxInt(u64)) std.math.maxInt(u64) else @intCast(advanced);
        return self.guest_ns;
    }

    pub fn pause(self: *GuestClock, host_tick: u64) void {
        _ = self.sync(host_tick);
        self.paused = true;
    }

    pub fn resumeAt(self: *GuestClock, host_tick: u64) void {
        self.last_host_tick = host_tick;
        self.paused = false;
    }

    pub fn reset(self: *GuestClock, host_tick: u64) void {
        self.last_host_tick = host_tick;
        self.guest_ns = 0;
        self.remainder = 0;
        self.paused = false;
    }

    pub fn ticksUntil(self: *const GuestClock, guest_deadline_ns: u64) u64 {
        if (guest_deadline_ns <= self.guest_ns) return 0;
        const delta = guest_deadline_ns - self.guest_ns;
        const product = @as(u128, delta) * self.monotonic_hz;
        const ticks = (product + time_contract.nanoseconds_per_second - 1) / time_contract.nanoseconds_per_second;
        return if (ticks > std.math.maxInt(u64)) std.math.maxInt(u64) else @intCast(ticks);
    }
};

pub const Pacer = struct {
    interval_ns: u64,
    next_ns: u64 = 0,

    pub fn initHz(rate_hz: u32) Error!Pacer {
        if (rate_hz == 0) return Error.InvalidConfiguration;
        return .{ .interval_ns = ceilDiv(time_contract.nanoseconds_per_second, rate_hz) };
    }

    pub fn reset(self: *Pacer, guest_now_ns: u64) void {
        self.next_ns = guest_now_ns;
    }

    pub fn take(self: *Pacer, guest_now_ns: u64) bool {
        if (guest_now_ns < self.next_ns) return false;
        if (self.next_ns == 0) self.next_ns = guest_now_ns;
        const elapsed = guest_now_ns -| self.next_ns;
        const periods = elapsed / self.interval_ns + 1;
        self.next_ns +|= periods *| self.interval_ns;
        return true;
    }

    pub fn deadline(self: *const Pacer) u64 {
        return self.next_ns;
    }
};

pub const AudioConfig = struct {
    sample_rate: u32 = default_sample_rate,
    channels: u16 = default_channels,
    volume: u32 = app_audio.default_volume,
    quantum_frames: u32 = default_quantum_frames,
    target_quanta: u16 = default_target_quanta,
    max_catchup_quanta: u16 = default_max_catchup_quanta,

    pub fn frameBytes(self: AudioConfig) Error!usize {
        if (self.sample_rate == 0 or self.channels == 0) return Error.InvalidAudioConfiguration;
        return std.math.mul(usize, @as(usize, self.channels), @sizeOf(i16)) catch Error.Overflow;
    }

    pub fn quantumBytes(self: AudioConfig) Error!usize {
        if (self.quantum_frames == 0) return Error.InvalidAudioConfiguration;
        return std.math.mul(usize, try self.frameBytes(), @as(usize, self.quantum_frames)) catch Error.Overflow;
    }

    pub fn targetBytes(self: AudioConfig) Error!usize {
        if (self.target_quanta == 0) return Error.InvalidAudioConfiguration;
        return std.math.mul(usize, try self.quantumBytes(), @as(usize, self.target_quanta)) catch Error.Overflow;
    }
};

pub const AudioSink = struct {
    context: *anyopaque,
    open_fn: *const fn (*anyopaque, AudioConfig) i32,
    write_fn: *const fn (*anyopaque, []const u8) i32,
    volume_fn: *const fn (*anyopaque, u32) i32,
    close_fn: *const fn (*anyopaque) i32,

    fn open(self: AudioSink, config: AudioConfig) i32 {
        return self.open_fn(self.context, config);
    }

    fn write(self: AudioSink, data: []const u8) i32 {
        return self.write_fn(self.context, data);
    }

    fn setVolume(self: AudioSink, volume: u32) i32 {
        return self.volume_fn(self.context, volume);
    }

    fn close(self: AudioSink) i32 {
        return self.close_fn(self.context);
    }
};

pub const R4AudioSink = struct {
    audio: app_audio.Audio,
    stream: ?app_audio.AudioStream = null,
    timeout: time_contract.Timeout = time_contract.timeoutFinite(.{ .nanoseconds = 100 * std.time.ns_per_ms }),

    pub fn init(audio: app_audio.Audio) R4AudioSink {
        return .{ .audio = audio };
    }

    pub fn sink(self: *R4AudioSink) AudioSink {
        return .{
            .context = self,
            .open_fn = r4AudioOpen,
            .write_fn = r4AudioWrite,
            .volume_fn = r4AudioVolume,
            .close_fn = r4AudioClose,
        };
    }
};

pub const AudioState = enum {
    disabled,
    ready,
    active,
    degraded,
    closed,
};

pub const AudioStats = struct {
    generated_bytes: u64 = 0,
    submitted_bytes: u64 = 0,
    discarded_bytes: u64 = 0,
    silence_bytes: u64 = 0,
    muted_bytes: u64 = 0,
    underflows: u64 = 0,
    open_retries: u64 = 0,
    writes: u64 = 0,
    busy_writes: u64 = 0,
    write_failures: u64 = 0,
    late_resyncs: u64 = 0,
};

pub const PcmQueue = struct {
    storage: []u8,
    frame_bytes: usize = 1,
    read_pos: usize = 0,
    len: usize = 0,

    pub fn init(storage: []u8, frame_bytes: usize) Error!PcmQueue {
        if (frame_bytes == 0 or storage.len < frame_bytes or storage.len % frame_bytes != 0) return Error.AudioQueueTooSmall;
        return .{ .storage = storage, .frame_bytes = frame_bytes };
    }

    pub fn available(self: *const PcmQueue) usize {
        return self.len;
    }

    pub fn free(self: *const PcmQueue) usize {
        return self.storage.len - self.len;
    }

    pub fn clear(self: *PcmQueue) void {
        self.read_pos = 0;
        self.len = 0;
    }

    pub fn write(self: *PcmQueue, data: []const u8) usize {
        const requested = @min(data.len, self.free());
        const count = requested - requested % self.frame_bytes;
        const write_pos = (self.read_pos + self.len) % self.storage.len;
        const first = @min(count, self.storage.len - write_pos);
        @memcpy(self.storage[write_pos..][0..first], data[0..first]);
        if (first < count) @memcpy(self.storage[0 .. count - first], data[first..count]);
        self.len += count;
        return count;
    }

    pub fn peek(self: *const PcmQueue, out: []u8) usize {
        const requested = @min(out.len, self.len);
        const count = requested - requested % self.frame_bytes;
        const first = @min(count, self.storage.len - self.read_pos);
        @memcpy(out[0..first], self.storage[self.read_pos..][0..first]);
        if (first < count) @memcpy(out[first..count], self.storage[0 .. count - first]);
        return count;
    }

    pub fn discard(self: *PcmQueue, byte_count: usize) usize {
        const requested = @min(byte_count, self.len);
        const count = requested - requested % self.frame_bytes;
        self.read_pos = (self.read_pos + count) % self.storage.len;
        self.len -= count;
        if (self.len == 0) self.read_pos = 0;
        return count;
    }

    pub fn read(self: *PcmQueue, out: []u8) usize {
        const count = self.peek(out);
        _ = self.discard(count);
        return count;
    }
};

pub const AudioOptions = struct {
    config: AudioConfig = .{},
    queue_storage: []u8,
    scratch: []u8,
    sink: ?AudioSink = null,
};

const empty_audio_storage = [_]u8{};

const SubmitResult = enum {
    submitted,
    busy,
    failed,
};

pub const AudioPump = struct {
    config: AudioConfig = .{},
    queue: PcmQueue = .{ .storage = @constCast(empty_audio_storage[0..]) },
    scratch: []u8 = @constCast(empty_audio_storage[0..]),
    sink: ?AudioSink = null,
    state: AudioState = .disabled,
    last_error: i32 = 0,
    muted: bool = false,
    next_deadline_tick: u64 = 0,
    quantum_ticks: u64 = 1,
    open_retry_ticks: u64 = 1,
    open_retry_attempts: u16 = 0,
    resync_prefill_quanta: u16 = 0,
    stats: AudioStats = .{},

    fn init(options: AudioOptions, monotonic_hz: u32) Error!AudioPump {
        const frame_bytes = try options.config.frameBytes();
        const quantum_bytes = try options.config.quantumBytes();
        const target_bytes = try options.config.targetBytes();
        if (options.config.max_catchup_quanta == 0) return Error.InvalidAudioConfiguration;
        if (options.queue_storage.len < target_bytes) return Error.AudioQueueTooSmall;
        if (options.scratch.len < quantum_bytes) return Error.AudioScratchTooSmall;
        const quantum_ns_product = @as(u128, options.config.quantum_frames) * time_contract.nanoseconds_per_second;
        const quantum_ns: u64 = @intCast((quantum_ns_product + options.config.sample_rate - 1) / options.config.sample_rate);
        const quantum_ticks = time_contract.durationToTicks(.{ .nanoseconds = quantum_ns }, monotonic_hz) catch return Error.UnknownFrequency;
        const open_retry_ticks = time_contract.durationToTicks(.{ .nanoseconds = audio_open_retry_nanoseconds }, monotonic_hz) catch return Error.UnknownFrequency;
        return .{
            .config = options.config,
            .queue = try PcmQueue.init(options.queue_storage, frame_bytes),
            .scratch = options.scratch[0..quantum_bytes],
            .sink = options.sink,
            .state = .ready,
            .quantum_ticks = @max(@as(u64, 1), quantum_ticks),
            .open_retry_ticks = @max(@as(u64, 1), open_retry_ticks),
        };
    }

    fn start(self: *AudioPump, now: u64) void {
        if (self.state == .disabled or self.state == .active or self.state == .degraded) return;
        self.queue.clear();
        self.next_deadline_tick = now +| self.quantum_ticks;
        _ = self.tryOpen(now);
    }

    fn tryOpen(self: *AudioPump, now: u64) bool {
        const sink = self.sink orelse {
            self.degrade(audio_error_unavailable);
            return false;
        };
        const rc = sink.open(self.config);
        if (rc < 0) {
            self.last_error = rc;
            if (retryableOpenError(rc) and self.open_retry_attempts < audio_open_retry_limit) {
                self.open_retry_attempts += 1;
                self.stats.open_retries +%= 1;
                self.next_deadline_tick = now +| self.open_retry_ticks;
                return false;
            }
            self.degrade(rc);
            return false;
        }
        self.state = .active;
        self.last_error = 0;
        self.open_retry_attempts = 0;
        self.resync_prefill_quanta = self.config.target_quanta;
        self.next_deadline_tick = now +| self.quantum_ticks;
        return true;
    }

    fn reset(self: *AudioPump, now: u64) void {
        if (self.state == .disabled or self.state == .degraded or self.state == .closed) return;
        self.queue.clear();
        self.next_deadline_tick = now +| self.quantum_ticks;
    }

    fn setMuted(self: *AudioPump, muted: bool, now: u64) void {
        if (self.muted == muted) return;
        self.muted = muted;
        if (self.state == .degraded) return;
        self.queue.clear();
        self.next_deadline_tick = now +| self.quantum_ticks;
        if (self.state == .active) {
            const sink = self.sink orelse return;
            const rc = sink.setVolume(if (muted) 0 else self.config.volume);
            if (rc < 0) self.degrade(rc);
        }
    }

    fn fill(self: *AudioPump, guest: GuestDriver) i32 {
        if (self.state != .ready and self.state != .active) return 0;
        const target = self.config.targetBytes() catch return runtime_error_guest_audio;
        const frame_bytes = self.config.frameBytes() catch return runtime_error_guest_audio;
        while (self.queue.available() < target) {
            const wanted_raw = @min(self.scratch.len, @min(target - self.queue.available(), self.queue.free()));
            const wanted = wanted_raw - wanted_raw % frame_bytes;
            if (wanted == 0) break;
            const rendered = guest.renderAudio(self.scratch[0..wanted]);
            if (rendered < 0) return rendered;
            const count: usize = @intCast(rendered);
            if (count == 0) break;
            if (count > wanted or count % frame_bytes != 0) return runtime_error_guest_audio;
            if (self.queue.write(self.scratch[0..count]) != count) return runtime_error_guest_audio;
            self.stats.generated_bytes +%= count;
        }
        return 0;
    }

    fn resyncLate(self: *AudioPump, now: u64) void {
        if ((self.state != .ready and self.state != .active) or now < self.next_deadline_tick) return;
        const catchup_ticks = @as(u64, self.config.max_catchup_quanta) *| self.quantum_ticks;
        if (now - self.next_deadline_tick < catchup_ticks) return;
        const discarded = self.queue.available();
        self.queue.clear();
        self.stats.discarded_bytes +%= discarded;
        self.next_deadline_tick = now;
        self.resync_prefill_quanta = self.config.target_quanta;
        self.stats.late_resyncs +%= 1;
    }

    fn pump(self: *AudioPump, now: u64, running: bool) void {
        if (self.state != .ready and self.state != .active) return;
        if (self.state == .ready) {
            if (now < self.next_deadline_tick or !self.tryOpen(now)) return;
        }
        if (self.resync_prefill_quanta != 0) {
            const quanta = self.resync_prefill_quanta;
            self.resync_prefill_quanta = 0;
            var submitted: u16 = 0;
            while (submitted < quanta) {
                switch (self.submitQuantum(running)) {
                    .submitted => submitted += 1,
                    .busy, .failed => break,
                }
            }
            self.next_deadline_tick = now +| self.quantum_ticks;
            return;
        }
        var sink_busy = false;
        var pumped: u16 = 0;
        while (now >= self.next_deadline_tick and pumped < self.config.max_catchup_quanta) : (pumped += 1) {
            switch (self.submitQuantum(running)) {
                .submitted => {},
                .busy => {
                    sink_busy = true;
                    self.next_deadline_tick = now +| self.quantum_ticks;
                    break;
                },
                .failed => break,
            }
            self.next_deadline_tick +|= self.quantum_ticks;
        }
        if (!sink_busy and now >= self.next_deadline_tick) self.resyncLate(now);
    }

    fn submitQuantum(self: *AudioPump, running: bool) SubmitResult {
        var copied: usize = 0;
        if (running) copied = self.queue.peek(self.scratch);
        if (copied < self.scratch.len) {
            @memset(self.scratch[copied..], 0);
        }
        if (self.muted) {
            @memset(self.scratch, 0);
        }

        if (self.state != .active) {
            return .failed;
        }
        const sink = self.sink orelse {
            self.degrade(audio_error_unavailable);
            return .failed;
        };
        const written = sink.write(self.scratch);
        if (written == abi.service_api_result_busy) {
            self.stats.busy_writes +%= 1;
            return .busy;
        }
        if (written != @as(i32, @intCast(self.scratch.len))) {
            self.stats.write_failures +%= 1;
            if (written > 0) {
                const submitted: usize = @min(@as(usize, @intCast(written)), self.scratch.len);
                _ = self.queue.discard(@min(submitted, copied));
                self.stats.submitted_bytes +%= submitted;
            }
            self.degrade(if (written < 0) written else audio_error_unavailable);
            return .failed;
        }
        _ = self.queue.discard(copied);
        if (copied < self.scratch.len) {
            self.stats.silence_bytes +%= self.scratch.len - copied;
            if (running and !self.muted) self.stats.underflows +%= 1;
        }
        if (self.muted) self.stats.muted_bytes +%= self.scratch.len;
        self.stats.writes +%= 1;
        self.stats.submitted_bytes +%= self.scratch.len;
        return .submitted;
    }

    fn degrade(self: *AudioPump, error_code: i32) void {
        if (self.state == .active) {
            if (self.sink) |sink| _ = sink.close();
        }
        const discarded = self.queue.available();
        self.queue.clear();
        self.stats.discarded_bytes +%= discarded;
        self.resync_prefill_quanta = 0;
        self.next_deadline_tick = 0;
        self.open_retry_attempts = 0;
        self.state = .degraded;
        self.last_error = if (error_code < 0) error_code else audio_error_unavailable;
    }

    fn close(self: *AudioPump) void {
        if (self.state == .closed or self.state == .disabled) return;
        if (self.state == .active) {
            if (self.sink) |sink| {
                const rc = sink.close();
                if (rc < 0) self.last_error = rc;
            }
        }
        self.queue.clear();
        self.state = .closed;
    }
};

fn retryableOpenError(raw: i32) bool {
    return raw == audio_error_timeout or
        raw == abi.service_api_result_timeout or
        raw == abi.service_api_result_busy or
        raw == abi.service_api_result_full or
        raw == abi.service_api_result_no_endpoint or
        raw == abi.service_api_result_not_running;
}

pub const Config = struct {
    slice_budget: u32 = default_slice_budget,
    max_input_events: u16 = default_max_input_events,
    max_wait_ticks: u64 = default_max_wait_ticks,
};

pub const RuntimeStats = struct {
    cycles: u64 = 0,
    slices: u64 = 0,
    budgeted_operations: u64 = 0,
    input_events: u64 = 0,
    presents: u64 = 0,
    pauses: u64 = 0,
    resumes: u64 = 0,
    resets: u64 = 0,
    yields: u64 = 0,
    sleeps: u64 = 0,
};

pub const CycleResult = union(enum) {
    wait: u64,
    finished: struct {
        state: LifecycleState,
        exit_code: i32,
    },
};

pub const Runtime = struct {
    config: Config,
    clock: GuestClock,
    audio: AudioPump = .{},
    state: LifecycleState = .ready,
    exit_code: i32 = 0,
    guest_wake_ns: u64 = 0,
    present_pending: bool = false,
    started: bool = false,
    resources_closed: bool = false,
    stats: RuntimeStats = .{},

    pub fn init(config: Config, monotonic_hz: u32, host_tick: u64, audio: ?AudioOptions) Error!Runtime {
        if (config.slice_budget == 0 or config.max_input_events == 0 or config.max_wait_ticks == 0) return Error.InvalidConfiguration;
        return .{
            .config = config,
            .clock = try GuestClock.init(monotonic_hz, host_tick),
            .audio = if (audio) |options| try AudioPump.init(options, monotonic_hz) else .{},
        };
    }

    pub fn start(self: *Runtime, host_tick: u64) void {
        if (self.started) return;
        self.clock.reset(host_tick);
        self.audio.start(host_tick);
        self.state = .running;
        self.started = true;
        self.resources_closed = false;
    }

    pub fn request(self: *Runtime, command: LifecycleCommand, host_tick: u64, guest: GuestDriver) void {
        if (isTerminal(self.state)) return;
        switch (command) {
            .none => {},
            .pause => if (self.state == .running) {
                self.clock.pause(host_tick);
                self.audio.reset(host_tick);
                self.state = .paused;
                self.stats.pauses +%= 1;
            },
            .resume_running => if (self.state == .paused) {
                self.clock.resumeAt(host_tick);
                self.audio.reset(host_tick);
                self.state = .running;
                self.stats.resumes +%= 1;
            },
            .toggle_pause => self.request(if (self.state == .paused) .resume_running else .pause, host_tick, guest),
            .reset => {
                const rc = guest.reset();
                if (rc < 0) {
                    self.fail(rc);
                    return;
                }
                self.clock.reset(host_tick);
                self.audio.reset(host_tick);
                self.guest_wake_ns = 0;
                self.present_pending = true;
                self.state = .running;
                self.stats.resets +%= 1;
            },
            .mute => self.audio.setMuted(true, host_tick),
            .unmute => self.audio.setMuted(false, host_tick),
            .toggle_mute => self.audio.setMuted(!self.audio.muted, host_tick),
            .close => {
                self.state = .closed;
                self.exit_code = 0;
            },
        }
    }

    pub fn cycle(self: *Runtime, host_tick: u64, guest: GuestDriver, host: HostDriver) CycleResult {
        if (!self.started) self.start(host_tick);
        self.stats.cycles +%= 1;
        var guest_now_ns = self.clock.sync(host_tick);

        var polled: u16 = 0;
        while (polled < self.config.max_input_events) : (polled += 1) {
            switch (host.poll()) {
                .idle => break,
                .handled => self.stats.input_events +%= 1,
                .present => {
                    self.stats.input_events +%= 1;
                    self.present_pending = true;
                },
                .command => |command| {
                    self.stats.input_events +%= 1;
                    self.request(command, host_tick, guest);
                    if (isTerminal(self.state)) break;
                },
                .failure => |raw| {
                    self.fail(if (raw < 0) raw else runtime_error_host_poll);
                    break;
                },
            }
        }

        if (isTerminal(self.state)) return self.finish();
        guest_now_ns = self.clock.sync(host_tick);

        // Drop source PCM which missed the complete bounded catch-up window
        // before the guest observes the new time. A guest audio renderer can
        // then advance its own timeline and refill from the current point;
        // stale samples are never submitted first and replayed late.
        if (self.state == .running) self.audio.resyncLate(host_tick);

        if (self.state == .running and (self.guest_wake_ns == 0 or guest_now_ns >= self.guest_wake_ns)) {
            self.guest_wake_ns = 0;
            const step = guest.step(self.config.slice_budget, guest_now_ns);
            self.stats.slices +%= 1;
            self.stats.budgeted_operations +%= self.config.slice_budget;
            self.present_pending = self.present_pending or step.frame_ready;
            switch (step.status) {
                .progress => self.guest_wake_ns = step.wake_guest_ns,
                .waiting => self.guest_wake_ns = step.wake_guest_ns,
                .completed => {
                    self.state = .completed;
                    self.exit_code = step.exit_code;
                },
                .failed => self.fail(step.exit_code),
            }
        }

        if (self.state == .running) {
            const audio_fill = self.audio.fill(guest);
            if (audio_fill < 0) self.fail(audio_fill);
        }
        self.audio.pump(host_tick, self.state == .running);

        if (self.present_pending and self.state != .failed and self.state != .closed) {
            const presented = host.present();
            if (presented < 0) {
                self.fail(presented);
            } else {
                self.stats.presents +%= 1;
                self.present_pending = false;
            }
        }

        if (isTerminal(self.state)) return self.finish();
        return .{ .wait = self.nextWait(host_tick) };
    }

    pub fn run(self: *Runtime, sys: *const r4sys.Context, guest: GuestDriver, host: HostDriver) i32 {
        self.start(sys.ticks());
        defer self.shutdown();
        while (true) {
            switch (self.cycle(sys.ticks(), guest, host)) {
                .finished => |finished| return finished.exit_code,
                .wait => |ticks| {
                    if (ticks == 0) {
                        self.stats.yields +%= 1;
                        sys.taskYield();
                    } else {
                        self.stats.sleeps +%= 1;
                        sys.sleepTicks(ticks);
                    }
                },
            }
        }
    }

    pub fn shutdown(self: *Runtime) void {
        if (self.resources_closed) return;
        self.audio.close();
        self.resources_closed = true;
    }

    fn fail(self: *Runtime, raw: i32) void {
        self.state = .failed;
        self.exit_code = if (raw == 0) -1 else raw;
    }

    fn finish(self: *Runtime) CycleResult {
        self.shutdown();
        return .{ .finished = .{ .state = self.state, .exit_code = self.exit_code } };
    }

    fn nextWait(self: *const Runtime, host_tick: u64) u64 {
        var wait = self.config.max_wait_ticks;
        if (self.state == .running) {
            if (self.guest_wake_ns == 0) return 0;
            wait = @min(wait, self.clock.ticksUntil(self.guest_wake_ns));
        }
        if (self.audio.state == .ready or self.audio.state == .active) {
            const audio_wait = if (host_tick >= self.audio.next_deadline_tick) @as(u64, 0) else self.audio.next_deadline_tick - host_tick;
            wait = @min(wait, audio_wait);
        }
        return wait;
    }
};

fn r4AudioOpen(context: *anyopaque, config: AudioConfig) i32 {
    const self: *R4AudioSink = @ptrCast(@alignCast(context));
    if (!self.audio.available()) return audio_error_unavailable;
    if (self.stream != null) return abi.service_api_result_busy;
    return switch (self.audio.openStream(config.sample_rate, config.channels, .s16le, config.volume, self.timeout)) {
        .stream => |stream| blk: {
            self.stream = stream;
            break :blk 0;
        },
        .timed_out => audio_error_timeout,
        .no_service => |raw| if (raw < 0) raw else audio_error_unavailable,
        .failure => |raw| if (raw < 0) raw else audio_error_unavailable,
    };
}

fn r4AudioWrite(context: *anyopaque, data: []const u8) i32 {
    const self: *R4AudioSink = @ptrCast(@alignCast(context));
    var stream = &(self.stream orelse return abi.err_closed);
    return switch (stream.write(data, self.timeout)) {
        .written => |bytes| @intCast(bytes),
        .busy => |bytes| if (bytes == 0) abi.service_api_result_busy else @intCast(bytes),
        .timed_out => |bytes| if (bytes == 0) audio_error_timeout else @intCast(bytes),
        .failure => |failure| if (failure.written != 0) @intCast(failure.written) else failure.raw,
    };
}

fn r4AudioVolume(context: *anyopaque, volume: u32) i32 {
    const self: *R4AudioSink = @ptrCast(@alignCast(context));
    var stream = &(self.stream orelse return abi.err_closed);
    return switch (stream.setVolume(volume, self.timeout)) {
        .ok => 0,
        .timed_out => audio_error_timeout,
        .failure => |raw| raw,
    };
}

fn r4AudioClose(context: *anyopaque) i32 {
    const self: *R4AudioSink = @ptrCast(@alignCast(context));
    var stream = &(self.stream orelse return 0);
    const result: i32 = switch (stream.close(self.timeout)) {
        .ok => 0,
        .timed_out => audio_error_timeout,
        .failure => |raw| raw,
    };
    if (result < 0) {
        _ = stream.connection.close();
        stream.stream_id = 0;
        stream.owned = false;
    }
    self.stream = null;
    return result;
}

fn isTerminal(state: LifecycleState) bool {
    return state == .completed or state == .failed or state == .closed;
}

fn ceilDiv(value: u64, divisor: u32) u64 {
    return value / divisor + @intFromBool(value % divisor != 0);
}

const FakeGuest = struct {
    steps: u32 = 0,
    resets: u32 = 0,
    audio_renders: u32 = 0,
    audio_byte: u8 = 1,
    audio_enabled: bool = true,
    complete_after: u32 = 0,
    fail_code: i32 = 0,
    reset_result: i32 = 0,
    last_budget: u32 = 0,
    last_guest_ns: u64 = 0,

    fn driver(self: *FakeGuest) GuestDriver {
        return .{ .context = self, .step_fn = fakeGuestStep, .reset_fn = fakeGuestReset, .render_audio_fn = fakeGuestAudio };
    }
};

const FakeHost = struct {
    commands: [8]LifecycleCommand = .{.none} ** 8,
    command_count: usize = 0,
    command_index: usize = 0,
    presents: u32 = 0,
    present_error: i32 = 0,

    fn driver(self: *FakeHost) HostDriver {
        return .{ .context = self, .poll_fn = fakeHostPoll, .present_fn = fakeHostPresent };
    }

    fn push(self: *FakeHost, command: LifecycleCommand) void {
        self.commands[self.command_count] = command;
        self.command_count += 1;
    }
};

const FakeSink = struct {
    open_result: i32 = 0,
    open_failure_result: i32 = 0,
    open_failures_remaining: u32 = 0,
    busy_after: u32 = std.math.maxInt(u32),
    write_error_after: u32 = std.math.maxInt(u32),
    opens: u32 = 0,
    writes: u32 = 0,
    closes: u32 = 0,
    volumes: u32 = 0,
    bytes: u64 = 0,
    all_zero: bool = true,

    fn sink(self: *FakeSink) AudioSink {
        return .{ .context = self, .open_fn = fakeSinkOpen, .write_fn = fakeSinkWrite, .volume_fn = fakeSinkVolume, .close_fn = fakeSinkClose };
    }
};

fn fakeGuestStep(context: *anyopaque, budget: u32, guest_now_ns: u64) StepResult {
    const self: *FakeGuest = @ptrCast(@alignCast(context));
    self.steps += 1;
    self.last_budget = budget;
    self.last_guest_ns = guest_now_ns;
    if (self.fail_code != 0) return StepResult.fail(self.fail_code);
    if (self.complete_after != 0 and self.steps >= self.complete_after) return StepResult.complete(0, true);
    return StepResult.waitUntil(guest_now_ns + 10 * std.time.ns_per_ms, true);
}

fn fakeGuestReset(context: *anyopaque) i32 {
    const self: *FakeGuest = @ptrCast(@alignCast(context));
    self.resets += 1;
    self.steps = 0;
    return self.reset_result;
}

fn fakeGuestAudio(context: *anyopaque, out: []u8) i32 {
    const self: *FakeGuest = @ptrCast(@alignCast(context));
    self.audio_renders += 1;
    if (!self.audio_enabled) return 0;
    @memset(out, self.audio_byte);
    return @intCast(out.len);
}

fn fakeHostPoll(context: *anyopaque) HostPollResult {
    const self: *FakeHost = @ptrCast(@alignCast(context));
    if (self.command_index >= self.command_count) return .idle;
    const command = self.commands[self.command_index];
    self.command_index += 1;
    return .{ .command = command };
}

fn fakeHostPresent(context: *anyopaque) i32 {
    const self: *FakeHost = @ptrCast(@alignCast(context));
    self.presents += 1;
    return self.present_error;
}

fn fakeSinkOpen(context: *anyopaque, _: AudioConfig) i32 {
    const self: *FakeSink = @ptrCast(@alignCast(context));
    self.opens += 1;
    if (self.open_failures_remaining != 0) {
        self.open_failures_remaining -= 1;
        return self.open_failure_result;
    }
    return self.open_result;
}

fn fakeSinkWrite(context: *anyopaque, data: []const u8) i32 {
    const self: *FakeSink = @ptrCast(@alignCast(context));
    if (self.writes >= self.busy_after) return abi.service_api_result_busy;
    if (self.writes >= self.write_error_after) return -77;
    self.writes += 1;
    self.bytes +%= data.len;
    for (data) |byte| self.all_zero = self.all_zero and byte == 0;
    return @intCast(data.len);
}

fn fakeSinkVolume(context: *anyopaque, _: u32) i32 {
    const self: *FakeSink = @ptrCast(@alignCast(context));
    self.volumes += 1;
    return 0;
}

fn fakeSinkClose(context: *anyopaque) i32 {
    const self: *FakeSink = @ptrCast(@alignCast(context));
    self.closes += 1;
    return 0;
}

test "guest clock excludes paused host time and pacer advances without drift catchup" {
    var clock = try GuestClock.init(100, 10);
    try std.testing.expectEqual(@as(u64, 20 * std.time.ns_per_ms), clock.sync(12));
    clock.pause(12);
    try std.testing.expectEqual(@as(u64, 20 * std.time.ns_per_ms), clock.sync(40));
    clock.resumeAt(40);
    try std.testing.expectEqual(@as(u64, 30 * std.time.ns_per_ms), clock.sync(41));
    try std.testing.expectEqual(@as(u64, 2), clock.ticksUntil(50 * std.time.ns_per_ms));
    clock.reset(50);
    try std.testing.expectEqual(@as(u64, 0), clock.guest_ns);

    var pacer = try Pacer.initHz(30);
    try std.testing.expect(pacer.take(0));
    try std.testing.expect(!pacer.take(10 * std.time.ns_per_ms));
    try std.testing.expect(pacer.take(100 * std.time.ns_per_ms));
    try std.testing.expect(pacer.deadline() > 100 * std.time.ns_per_ms);
}

test "pcm queue wraps caller storage without losing byte order" {
    var storage: [8]u8 = undefined;
    var queue = try PcmQueue.init(storage[0..], 2);
    try std.testing.expectEqual(@as(usize, 6), queue.write(&.{ 1, 2, 3, 4, 5, 6 }));
    var first: [4]u8 = undefined;
    try std.testing.expectEqual(@as(usize, 4), queue.read(first[0..]));
    try std.testing.expectEqualSlices(u8, &.{ 1, 2, 3, 4 }, first[0..]);
    try std.testing.expectEqual(@as(usize, 6), queue.write(&.{ 7, 8, 9, 10, 11, 12 }));
    var peeked: [4]u8 = undefined;
    try std.testing.expectEqual(@as(usize, 4), queue.peek(peeked[0..]));
    try std.testing.expectEqualSlices(u8, &.{ 5, 6, 7, 8 }, peeked[0..]);
    try std.testing.expectEqual(@as(usize, 4), queue.discard(peeked.len));
    var second: [4]u8 = undefined;
    try std.testing.expectEqual(@as(usize, 4), queue.read(second[0..]));
    try std.testing.expectEqualSlices(u8, &.{ 9, 10, 11, 12 }, second[0..]);
}

test "runtime bounds guest slices and applies pause resume reset and close between slices" {
    var queue_storage: [3840]u8 = undefined;
    var scratch: [1920]u8 = undefined;
    var sink = FakeSink{};
    var runtime = try Runtime.init(.{ .slice_budget = 123, .max_wait_ticks = 1 }, 100, 0, .{
        .queue_storage = queue_storage[0..],
        .scratch = scratch[0..],
        .sink = sink.sink(),
    });
    var guest = FakeGuest{};
    var host = FakeHost{};

    try std.testing.expect(runtime.cycle(0, guest.driver(), host.driver()) == .wait);
    try std.testing.expectEqual(@as(u32, 1), guest.steps);
    try std.testing.expectEqual(@as(u32, 123), guest.last_budget);

    host.push(.pause);
    _ = runtime.cycle(1, guest.driver(), host.driver());
    try std.testing.expectEqual(LifecycleState.paused, runtime.state);
    try std.testing.expectEqual(@as(u32, 1), guest.steps);

    host.push(.resume_running);
    _ = runtime.cycle(5, guest.driver(), host.driver());
    try std.testing.expectEqual(LifecycleState.running, runtime.state);
    try std.testing.expectEqual(@as(u32, 2), guest.steps);

    host.push(.reset);
    _ = runtime.cycle(6, guest.driver(), host.driver());
    try std.testing.expectEqual(@as(u32, 1), guest.resets);
    try std.testing.expectEqual(@as(u32, 1), guest.steps);
    try std.testing.expectEqual(@as(u64, 0), guest.last_guest_ns);

    host.push(.close);
    const closed = runtime.cycle(7, guest.driver(), host.driver());
    try std.testing.expectEqual(LifecycleState.closed, closed.finished.state);
    try std.testing.expectEqual(@as(u32, 1), sink.closes);
    try std.testing.expectEqual(@as(u64, 3), runtime.stats.slices);
}

test "audio underflow is silence and degraded audio leaves guest time bounded without another deadline" {
    var queue_a: [3840]u8 = undefined;
    var scratch_a: [1920]u8 = undefined;
    var sink_a = FakeSink{};
    var runtime_a = try Runtime.init(.{}, 100, 0, .{ .queue_storage = queue_a[0..], .scratch = scratch_a[0..], .sink = sink_a.sink() });
    var guest_a = FakeGuest{ .audio_enabled = false };
    var host_a = FakeHost{};
    _ = runtime_a.cycle(0, guest_a.driver(), host_a.driver());
    _ = runtime_a.cycle(1, guest_a.driver(), host_a.driver());
    try std.testing.expectEqual(@as(u64, 3), runtime_a.audio.stats.underflows);
    try std.testing.expect(sink_a.all_zero);
    runtime_a.request(.mute, 1, guest_a.driver());
    try std.testing.expect(runtime_a.audio.muted);
    try std.testing.expectEqual(@as(u32, 1), sink_a.volumes);

    var queue_b: [3840]u8 = undefined;
    var scratch_b: [1920]u8 = undefined;
    var missing = FakeSink{ .open_result = -55 };
    var runtime_b = try Runtime.init(.{}, 100, 0, .{ .queue_storage = queue_b[0..], .scratch = scratch_b[0..], .sink = missing.sink() });
    var guest_b = FakeGuest{};
    var host_b = FakeHost{};
    const missing_first = runtime_b.cycle(0, guest_b.driver(), host_b.driver());
    const missing_second = runtime_b.cycle(1, guest_b.driver(), host_b.driver());
    try std.testing.expectEqual(AudioState.degraded, runtime_b.audio.state);
    try std.testing.expectEqual(@as(i32, -55), runtime_b.audio.last_error);
    try std.testing.expectEqual(LifecycleState.running, runtime_b.state);
    try std.testing.expect(missing_first.wait != 0);
    try std.testing.expect(missing_second.wait != 0);
    try std.testing.expectEqual(@as(u32, 0), guest_b.audio_renders);
    try std.testing.expectEqual(@as(u64, 0), runtime_b.audio.stats.generated_bytes);
    try std.testing.expectEqual(@as(u64, 0), runtime_b.audio.stats.discarded_bytes);
    const missing_late = runtime_b.cycle(50, guest_b.driver(), host_b.driver());
    try std.testing.expect(missing_late.wait != 0);
    try std.testing.expectEqual(@as(u32, 0), guest_b.audio_renders);

    var queue_c: [3840]u8 = undefined;
    var scratch_c: [1920]u8 = undefined;
    var sink_c = FakeSink{};
    var runtime_c = try Runtime.init(.{}, 100, 0, .{ .queue_storage = queue_c[0..], .scratch = scratch_c[0..], .sink = sink_c.sink() });
    var guest_c = FakeGuest{ .audio_byte = 0x33 };
    var host_c = FakeHost{};
    _ = runtime_c.cycle(0, guest_c.driver(), host_c.driver());
    try std.testing.expectEqual(@as(usize, 0), runtime_c.audio.queue.available());
    _ = runtime_c.cycle(1, guest_c.driver(), host_c.driver());
    try std.testing.expectEqual(@as(usize, 1920), runtime_c.audio.queue.available());
    _ = runtime_c.cycle(50, guest_c.driver(), host_c.driver());
    try std.testing.expectEqual(@as(u64, 1), runtime_c.audio.stats.late_resyncs);
    try std.testing.expectEqual(@as(u64, 1920), runtime_c.audio.stats.discarded_bytes);
    try std.testing.expectEqual(@as(u64, 9600), runtime_c.audio.stats.submitted_bytes);
    try std.testing.expectEqual(@as(usize, 0), runtime_c.audio.queue.available());
    try std.testing.expectEqual(@as(u32, 5), sink_c.writes);

    var queue_d: [3840]u8 = undefined;
    var scratch_d: [1920]u8 = undefined;
    var sink_d = FakeSink{ .busy_after = 1 };
    var runtime_d = try Runtime.init(.{}, 1000, 0, .{
        .queue_storage = queue_d[0..],
        .scratch = scratch_d[0..],
        .sink = sink_d.sink(),
    });
    var guest_d = FakeGuest{ .audio_byte = 0x44 };
    var host_d = FakeHost{};
    _ = runtime_d.cycle(0, guest_d.driver(), host_d.driver());
    try std.testing.expectEqual(@as(u32, 1), sink_d.writes);
    try std.testing.expectEqual(@as(u64, 1), runtime_d.audio.stats.busy_writes);
    _ = runtime_d.cycle(1, guest_d.driver(), host_d.driver());
    try std.testing.expectEqual(AudioState.active, runtime_d.audio.state);
    try std.testing.expectEqual(@as(usize, 3840), runtime_d.audio.queue.available());
    try std.testing.expectEqual(@as(u64, 1), runtime_d.audio.stats.busy_writes);
    sink_d.busy_after = 2;
    _ = runtime_d.cycle(10, guest_d.driver(), host_d.driver());
    try std.testing.expectEqual(@as(u32, 2), sink_d.writes);
    try std.testing.expectEqual(@as(usize, 1920), runtime_d.audio.queue.available());
    try std.testing.expectEqual(@as(u64, 1), runtime_d.audio.stats.busy_writes);

    var queue_e: [3840]u8 = undefined;
    var scratch_e: [1920]u8 = undefined;
    var sink_e = FakeSink{ .open_failure_result = audio_error_timeout, .open_failures_remaining = 1 };
    var runtime_e = try Runtime.init(.{}, 1000, 0, .{
        .queue_storage = queue_e[0..],
        .scratch = scratch_e[0..],
        .sink = sink_e.sink(),
    });
    var guest_e = FakeGuest{ .audio_byte = 0x55 };
    var host_e = FakeHost{};
    _ = runtime_e.cycle(0, guest_e.driver(), host_e.driver());
    try std.testing.expectEqual(AudioState.ready, runtime_e.audio.state);
    try std.testing.expectEqual(@as(u64, 1), runtime_e.audio.stats.open_retries);
    try std.testing.expectEqual(@as(u32, 1), sink_e.opens);
    _ = runtime_e.cycle(10, guest_e.driver(), host_e.driver());
    try std.testing.expectEqual(@as(u32, 1), sink_e.opens);
    _ = runtime_e.cycle(50, guest_e.driver(), host_e.driver());
    try std.testing.expectEqual(AudioState.active, runtime_e.audio.state);
    try std.testing.expectEqual(@as(u32, 2), sink_e.opens);
    try std.testing.expectEqual(@as(u32, 2), sink_e.writes);
}

test "guest completion failure and reset failure converge on terminal cleanup" {
    var complete_queue: [3840]u8 = undefined;
    var complete_scratch: [1920]u8 = undefined;
    var complete_sink = FakeSink{};
    var complete_runtime = try Runtime.init(.{}, 100, 0, .{
        .queue_storage = complete_queue[0..],
        .scratch = complete_scratch[0..],
        .sink = complete_sink.sink(),
    });
    var complete_guest = FakeGuest{ .complete_after = 1 };
    var complete_host = FakeHost{};
    const completed = complete_runtime.cycle(0, complete_guest.driver(), complete_host.driver());
    try std.testing.expectEqual(LifecycleState.completed, completed.finished.state);
    try std.testing.expect(complete_runtime.resources_closed);
    try std.testing.expectEqual(@as(u32, 1), complete_sink.closes);

    var fail_queue: [3840]u8 = undefined;
    var fail_scratch: [1920]u8 = undefined;
    var fail_sink = FakeSink{};
    var fail_runtime = try Runtime.init(.{}, 100, 0, .{
        .queue_storage = fail_queue[0..],
        .scratch = fail_scratch[0..],
        .sink = fail_sink.sink(),
    });
    var fail_guest = FakeGuest{ .fail_code = -88 };
    var fail_host = FakeHost{};
    const failed = fail_runtime.cycle(0, fail_guest.driver(), fail_host.driver());
    try std.testing.expectEqual(LifecycleState.failed, failed.finished.state);
    try std.testing.expectEqual(@as(i32, -88), failed.finished.exit_code);
    try std.testing.expect(fail_runtime.resources_closed);
    try std.testing.expectEqual(@as(u32, 1), fail_sink.closes);

    var reset_runtime = try Runtime.init(.{}, 100, 0, null);
    var reset_guest = FakeGuest{ .reset_result = -66 };
    var reset_host = FakeHost{};
    reset_host.push(.reset);
    const reset_failed = reset_runtime.cycle(0, reset_guest.driver(), reset_host.driver());
    try std.testing.expectEqual(LifecycleState.failed, reset_failed.finished.state);
    try std.testing.expectEqual(@as(i32, -66), reset_failed.finished.exit_code);
    try std.testing.expect(reset_runtime.resources_closed);
}

test "two runtimes isolate clock queue host state and an audio failure" {
    var queue_a: [3840]u8 = undefined;
    var scratch_a: [1920]u8 = undefined;
    var sink_a = FakeSink{};
    var runtime_a = try Runtime.init(.{}, 100, 0, .{ .queue_storage = queue_a[0..], .scratch = scratch_a[0..], .sink = sink_a.sink() });
    var guest_a = FakeGuest{ .audio_byte = 0x11 };
    var host_a = FakeHost{};

    var queue_b: [3840]u8 = undefined;
    var scratch_b: [1920]u8 = undefined;
    var sink_b = FakeSink{ .write_error_after = 0 };
    var runtime_b = try Runtime.init(.{}, 100, 0, .{ .queue_storage = queue_b[0..], .scratch = scratch_b[0..], .sink = sink_b.sink() });
    var guest_b = FakeGuest{ .audio_byte = 0x22 };
    var host_b = FakeHost{};

    _ = runtime_a.cycle(0, guest_a.driver(), host_a.driver());
    _ = runtime_b.cycle(0, guest_b.driver(), host_b.driver());
    runtime_a.request(.pause, 0, guest_a.driver());
    _ = runtime_a.cycle(1, guest_a.driver(), host_a.driver());
    _ = runtime_b.cycle(1, guest_b.driver(), host_b.driver());

    try std.testing.expectEqual(LifecycleState.paused, runtime_a.state);
    try std.testing.expectEqual(LifecycleState.running, runtime_b.state);
    try std.testing.expectEqual(AudioState.active, runtime_a.audio.state);
    try std.testing.expectEqual(AudioState.degraded, runtime_b.audio.state);
    try std.testing.expectEqual(@as(i32, -77), runtime_b.audio.last_error);
    try std.testing.expect(runtime_a.clock.guest_ns < runtime_b.clock.guest_ns);
    try std.testing.expectEqual(@as(u32, 1), guest_a.steps);
    try std.testing.expectEqual(@as(u32, 2), guest_b.steps);
    try std.testing.expectEqual(@as(u64, 1920), runtime_a.audio.stats.submitted_bytes);
    try std.testing.expectEqual(@as(u64, 0), runtime_b.audio.stats.submitted_bytes);
    try std.testing.expectEqual(@as(u64, 3840), runtime_b.audio.stats.discarded_bytes);
    try std.testing.expectEqual(@as(u8, 0x11), runtime_a.audio.queue.storage[runtime_a.audio.queue.read_pos]);
    try std.testing.expectEqual(@as(usize, 0), runtime_b.audio.queue.available());
    const degraded_renders = guest_b.audio_renders;
    const degraded_cycle = runtime_b.cycle(100, guest_b.driver(), host_b.driver());
    try std.testing.expect(degraded_cycle.wait != 0);
    try std.testing.expectEqual(degraded_renders, guest_b.audio_renders);
    try std.testing.expectEqual(@as(u64, 3840), runtime_b.audio.stats.discarded_bytes);
    runtime_a.shutdown();
    runtime_b.shutdown();
    try std.testing.expectEqual(@as(u32, 1), sink_a.closes);
    try std.testing.expectEqual(@as(u32, 1), sink_b.closes);
}
