const abi = @import("r4os_contract").abi;

pub const Context = struct {
    table: abi.GfxDriverQueueApi,

    pub fn register(self: *const Context, input: *const abi.GfxBackendRegistration, output: *abi.GfxBackendBinding) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverQueueApi, "register_backend") + 8 or self.table.register_backend == 0) return abi.err_no_fn;
        output.version = 1;
        output.size = @sizeOf(abi.GfxBackendBinding);
        const callback: *const fn (*const abi.GfxBackendRegistration, *abi.GfxBackendBinding) callconv(.c) i32 = @ptrFromInt(self.table.register_backend);
        return callback(input, output);
    }

    pub fn unregister(self: *const Context, input: *const abi.GfxBackendBinding, quiesced: u32) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverQueueApi, "unregister_backend") + 8 or self.table.unregister_backend == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBackendBinding, u32) callconv(.c) i32 = @ptrFromInt(self.table.unregister_backend);
        return callback(input, quiesced);
    }

    pub fn take(self: *const Context, input: *const abi.GfxBackendBinding, output: *abi.GfxDriverJob) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverQueueApi, "take") + 8 or self.table.take == 0) return abi.err_no_fn;
        output.version = 1;
        output.size = @sizeOf(abi.GfxDriverJob);
        const callback: *const fn (*const abi.GfxBackendBinding, *abi.GfxDriverJob) callconv(.c) i32 = @ptrFromInt(self.table.take);
        return callback(input, output);
    }

    pub fn complete(self: *const Context, input: *const abi.GfxFence, result: u32, quiesced: u32) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverQueueApi, "complete") + 8 or self.table.complete == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxFence, u32, u32) callconv(.c) i32 = @ptrFromInt(self.table.complete);
        return callback(input, result, quiesced);
    }

    pub fn reset(self: *const Context, input: *const abi.GfxBackendBinding, quiesced: u32, output: *abi.GfxBackendBinding) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverQueueApi, "reset") + 8 or self.table.reset == 0) return abi.err_no_fn;
        output.version = 1;
        output.size = @sizeOf(abi.GfxBackendBinding);
        const callback: *const fn (*const abi.GfxBackendBinding, u32, *abi.GfxBackendBinding) callconv(.c) i32 = @ptrFromInt(self.table.reset);
        return callback(input, quiesced, output);
    }

    pub fn segment(self: *const Context, input: *const abi.GfxFence, which: u32, offset: u64, mask: u64, output: *abi.GfxDmaSegment) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverQueueApi, "segment") + 8 or self.table.segment == 0) return abi.err_no_fn;
        output.version = 1;
        output.size = @sizeOf(abi.GfxDmaSegment);
        const callback: *const fn (*const abi.GfxFence, u32, u64, u64, *abi.GfxDmaSegment) callconv(.c) i32 = @ptrFromInt(self.table.segment);
        return callback(input, which, offset, mask, output);
    }
};
