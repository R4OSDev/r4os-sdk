const abi = @import("r4os_contract").abi;
pub const Context = struct {
    table: abi.GfxDriverDisplayApi,
    pub fn bootHold(self: *const Context, input: *const abi.GfxBootHoldRequest, output: *abi.GfxNativeState) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverDisplayApi, "boot_hold") + 8 or self.table.boot_hold == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBootHoldRequest, *abi.GfxNativeState) callconv(.c) i32 = @ptrFromInt(self.table.boot_hold);
        return callback(input, output);
    }
    pub fn bootFinish(self: *const Context, generation: u64, operation: u32, output: *abi.GfxNativeState) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverDisplayApi, "boot_finish") + 8 or self.table.boot_finish == 0) return abi.err_no_fn;
        const callback: *const fn (u64, u32, *abi.GfxNativeState) callconv(.c) i32 = @ptrFromInt(self.table.boot_finish);
        return callback(generation, operation, output);
    }
    pub fn schedule(self: *const Context, input: *const abi.GfxBackendBinding) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverDisplayApi, "schedule") + 8 or self.table.schedule == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBackendBinding) callconv(.c) i32 = @ptrFromInt(self.table.schedule);
        return callback(input);
    }
    pub fn bootInfo(self: *const Context, output: *abi.GfxNativeBootInfo) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverDisplayApi, "boot_info") + 8 or self.table.boot_info == 0) return abi.err_no_fn;
        const callback: *const fn (*abi.GfxNativeBootInfo) callconv(.c) i32 = @ptrFromInt(self.table.boot_info);
        return callback(output);
    }
    pub fn prepare(self: *const Context, input: *const abi.GfxNativeRegistration, output: *abi.GfxNativeState) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverDisplayApi, "prepare") + 8 or self.table.prepare == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxNativeRegistration, *abi.GfxNativeState) callconv(.c) i32 = @ptrFromInt(self.table.prepare);
        return callback(input, output);
    }
    pub fn transition(self: *const Context, generation: u64, operation: u32, output: *abi.GfxNativeState) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverDisplayApi, "transition") + 8 or self.table.transition == 0) return abi.err_no_fn;
        const callback: *const fn (u64, u32, *abi.GfxNativeState) callconv(.c) i32 = @ptrFromInt(self.table.transition);
        return callback(generation, operation, output);
    }
};
