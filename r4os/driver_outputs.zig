const abi = @import("r4os_contract").abi;
pub const Context = struct {
    table: abi.GfxDriverOutputApi,
    pub fn supportsModes(self: *const Context) bool {
        return self.table.version == 1 and self.table.size >= @offsetOf(abi.GfxDriverOutputApi, "mode_complete") + 8 and
            self.table.mode_enable != 0 and self.table.mode_take != 0 and self.table.mode_complete != 0;
    }
    pub fn enableModes(self: *const Context, backend: *const abi.GfxBackendBinding) i32 {
        if (!self.supportsModes()) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBackendBinding) callconv(.c) i32 = @ptrFromInt(self.table.mode_enable);
        return callback(backend);
    }
    pub fn takeMode(self: *const Context, backend: *const abi.GfxBackendBinding, output: *abi.GfxDriverModeJob) i32 {
        if (!self.supportsModes()) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBackendBinding, *abi.GfxDriverModeJob) callconv(.c) i32 = @ptrFromInt(self.table.mode_take);
        return callback(backend, output);
    }
    pub fn completeMode(self: *const Context, input: *const abi.GfxDriverModeCompletion) i32 {
        if (!self.supportsModes()) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxDriverModeCompletion) callconv(.c) i32 = @ptrFromInt(self.table.mode_complete);
        return callback(input);
    }
    pub fn supportsReceivers(self: *const Context) bool {
        return self.table.version == 1 and self.table.size >= @offsetOf(abi.GfxDriverOutputApi, "close_source") + 8 and
            self.table.register_source != 0 and self.table.replace_receivers != 0 and self.table.close_source != 0;
    }
    pub fn registerSource(self: *const Context, adapter: u32, output: *abi.GfxReceiverSource) i32 {
        if (!self.supportsReceivers()) return abi.err_no_fn;
        const callback: *const fn (u32, *abi.GfxReceiverSource) callconv(.c) i32 = @ptrFromInt(self.table.register_source);
        return callback(adapter, output);
    }
    pub fn replaceReceivers(self: *const Context, input: *const abi.GfxReceiverUpdate) i32 {
        if (!self.supportsReceivers()) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxReceiverUpdate) callconv(.c) i32 = @ptrFromInt(self.table.replace_receivers);
        return callback(input);
    }
    pub fn closeSource(self: *const Context, input: *const abi.GfxReceiverSource) i32 {
        if (!self.supportsReceivers()) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxReceiverSource) callconv(.c) i32 = @ptrFromInt(self.table.close_source);
        return callback(input);
    }
    pub fn publish(self: *const Context, input: *const abi.GfxOutputPublication, output: *abi.GfxOutputId) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverOutputApi, "publish") + 8 or self.table.publish == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxOutputPublication, *abi.GfxOutputId) callconv(.c) i32 = @ptrFromInt(self.table.publish);
        return callback(input, output);
    }
    pub fn withdraw(self: *const Context, input: *const abi.GfxOutputId) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverOutputApi, "withdraw") + 8 or self.table.withdraw == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxOutputId) callconv(.c) i32 = @ptrFromInt(self.table.withdraw);
        return callback(input);
    }
};
