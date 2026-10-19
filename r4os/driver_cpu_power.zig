const a = @import("r4os_contract").abi;
/// Authenticated passive CPU mechanism, obtained during driver init. No
/// arbitrary MSR address, cross-CPU dispatch or power-control operation.
pub const Context = struct {
    table: a.DriverCpuPowerApi,
    pub fn has(self: *const Context, comptime field: []const u8) bool {
        return self.table.version == 1 and self.table.size >= @offsetOf(a.DriverCpuPowerApi, field) + 8 and @field(self.table, field) != 0;
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
