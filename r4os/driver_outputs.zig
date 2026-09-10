const abi = @import("r4os_contract").abi;
pub const Context = struct {
    table: abi.GfxDriverOutputApi,
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
