const a = @import("r4os_contract").abi;
/// Authenticated optional CPU mechanism, obtained during driver init. Explicit
/// controls retain exact hardware membership until the owner proves return.
/// No arbitrary MSR address or cross-CPU dispatch.
pub const Context = struct {
    table: a.DriverCpuPowerApi,
    pub fn has(self: *const Context, comptime field: []const u8) bool {
        return self.table.version == 1 and self.table.size >= @offsetOf(a.DriverCpuPowerApi, field) + 8 and @field(self.table, field) != 0;
    }
    pub fn feature(self: *const Context, cpu: u32, epoch: u64, ordinal: u32, out: *a.CpuFeatureInfo) i32 {
        if (!self.has("feature")) return a.err_no_fn;
        const call: *const fn (u32, u64, u32, *a.CpuFeatureInfo) callconv(.c) i32 = @ptrFromInt(self.table.feature);
        return call(cpu, epoch, ordinal, out);
    }
    pub fn registerPerformance(self: *const Context, cookie: u64, backend: *const a.CpuPerformanceBackend) i32 {
        if (!self.has("register_performance")) return a.err_no_fn;
        const call: *const fn (u64, *const a.CpuPerformanceBackend) callconv(.c) i32 = @ptrFromInt(self.table.register_performance);
        return call(cookie, backend);
    }
    pub fn controlAcquire(self: *const Context, cpu: u32, epoch: u64, token: *u64) i32 {
        if (!self.has("control_acquire")) return a.err_no_fn;
        const call: *const fn (u32, u64, *u64) callconv(.c) i32 = @ptrFromInt(self.table.control_acquire);
        return call(cpu, epoch, token);
    }
    pub fn controlRelease(self: *const Context, cpu: u32, epoch: u64, token: u64) i32 {
        if (!self.has("control_release")) return a.err_no_fn;
        const call: *const fn (u32, u64, u64) callconv(.c) i32 = @ptrFromInt(self.table.control_release);
        return call(cpu, epoch, token);
    }
    pub fn registerCompareWrite(self: *const Context, cpu: u32, epoch: u64, token: u64, id: u32, expected: u64, requested: u64, out: *a.CpuRegisterWriteInfo) i32 {
        if (!self.has("register_compare_write")) return a.err_no_fn;
        const call: *const fn (u32, u64, u64, u32, u64, u64, *a.CpuRegisterWriteInfo) callconv(.c) i32 = @ptrFromInt(self.table.register_compare_write);
        return call(cpu, epoch, token, id, expected, requested, out);
    }

    pub fn registerCppc(self: *const Context, cookie: u64, backend: *const a.CpuCppcBackend) i32 {
        if (!self.has("register_cppc")) return a.err_no_fn;
        const call: *const fn (u64, *const a.CpuCppcBackend) callconv(.c) i32 = @ptrFromInt(self.table.register_cppc);
        return call(cookie, backend);
    }
    pub fn rankPublish(self: *const Context, input: *const a.CpuPerformanceHint, sequence: *u64) i32 {
        if (!self.has("rank_publish")) return a.err_no_fn;
        const call: *const fn (*const a.CpuPerformanceHint, *u64) callconv(.c) i32 = @ptrFromInt(self.table.rank_publish);
        return call(input, sequence);
    }

    pub fn register(self: *const Context, backend: *const a.CpuPowerBackend, cookie: *u64) i32 {
        if (!self.has("register_backend")) return a.err_no_fn;
        const call: *const fn (*const a.CpuPowerBackend, *u64) callconv(.c) i32 = @ptrFromInt(self.table.register_backend);
        return call(backend, cookie);
    }
    pub fn unregister(self: *const Context, cookie: u64) i32 {
        if (!self.has("unregister_backend")) return a.err_no_fn;
        const call: *const fn (u64) callconv(.c) i32 = @ptrFromInt(self.table.unregister_backend);
        return call(cookie);
    }
    pub fn currentCpu(self: *const Context) u32 {
        if (!self.has("current_cpu")) return a.cpu_power_cpu_none;
        const call: *const fn () callconv(.c) u32 = @ptrFromInt(self.table.current_cpu);
        return call();
    }
    pub fn capabilities(self: *const Context, cpu: u32, out: *a.CpuCapabilitiesInfo) i32 {
        if (!self.has("capabilities")) return a.err_no_fn;
        const call: *const fn (u32, *a.CpuCapabilitiesInfo) callconv(.c) i32 = @ptrFromInt(self.table.capabilities);
        return call(cpu, out);
    }
    pub fn topology(self: *const Context, cpu: u32, out: *a.CpuTopologyInfo) i32 {
        if (!self.has("topology")) return a.err_no_fn;
        const call: *const fn (u32, *a.CpuTopologyInfo) callconv(.c) i32 = @ptrFromInt(self.table.topology);
        return call(cpu, out);
    }
    pub fn registerRead(self: *const Context, cpu: u32, epoch: u64, id: u32, out: *a.CpuRegisterInfo) i32 {
        if (!self.has("register_read")) return a.err_no_fn;
        const call: *const fn (u32, u64, u32, *a.CpuRegisterInfo) callconv(.c) i32 = @ptrFromInt(self.table.register_read);
        return call(cpu, epoch, id, out);
    }
    pub fn clock(self: *const Context, out: *a.MonotonicClockInfo) i32 {
        if (!self.has("clock")) return a.err_no_fn;
        const call: *const fn (*a.MonotonicClockInfo) callconv(.c) i32 = @ptrFromInt(self.table.clock);
        return call(out);
    }
    pub fn countersRead(self: *const Context, cpu: u32, epoch: u64, out: *a.CpuPowerCounters) i32 {
        if (!self.has("counters_read")) return a.err_no_fn;
        const call: *const fn (u32, u64, *a.CpuPowerCounters) callconv(.c) i32 = @ptrFromInt(self.table.counters_read);
        return call(cpu, epoch, out);
    }
};
