const abi = @import("r4os_contract").abi;

// Copyable table view; returned objects/maps retain independent kernel owners.
pub const Context = struct {
    table: abi.GfxDriverMemoryApi,

    pub fn bufferCreate(self: *const Context, input: *const abi.GfxBufferDescriptor, output: *abi.GfxBufferReference) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_create") + 8 or self.table.buffer_create == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBufferDescriptor, *abi.GfxBufferReference) callconv(.c) i32 = @ptrFromInt(self.table.buffer_create);
        return callback(input, output);
    }

    pub fn bufferDescribe(self: *const Context, input: *const abi.GfxBufferHandle, output: *abi.GfxBufferDescriptor) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_describe") + 8 or self.table.buffer_describe == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBufferHandle, *abi.GfxBufferDescriptor) callconv(.c) i32 = @ptrFromInt(self.table.buffer_describe);
        return callback(input, output);
    }

    pub fn bufferImport(self: *const Context, input: *const abi.GfxBufferHandle, output: *abi.GfxBufferReference) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_import") + 8 or self.table.buffer_import == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBufferHandle, *abi.GfxBufferReference) callconv(.c) i32 = @ptrFromInt(self.table.buffer_import);
        return callback(input, output);
    }

    pub fn bufferRelease(self: *const Context, input: *const abi.GfxBufferHandle) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_release") + 8 or self.table.buffer_release == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBufferHandle) callconv(.c) i32 = @ptrFromInt(self.table.buffer_release);
        return callback(input);
    }

    pub fn bufferMap(self: *const Context, input: *const abi.GfxBufferHandle, access: u32, offset: u64, bytes: u64, output: *abi.GfxBufferMap) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_map") + 8 or self.table.buffer_map == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBufferHandle, u32, u64, u64, *abi.GfxBufferMap) callconv(.c) i32 = @ptrFromInt(self.table.buffer_map);
        return callback(input, access, offset, bytes, output);
    }

    pub fn bufferUnmap(self: *const Context, input: *const abi.GfxBufferHandle) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_unmap") + 8 or self.table.buffer_unmap == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBufferHandle) callconv(.c) i32 = @ptrFromInt(self.table.buffer_unmap);
        return callback(input);
    }

    pub fn deviceAcquire(self: *const Context, reference: *const abi.GfxBufferHandle, request: *const abi.GfxDeviceRequest, output: *abi.GfxDeviceLease) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "device_acquire") + 8 or self.table.device_acquire == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBufferHandle, *const abi.GfxDeviceRequest, *abi.GfxDeviceLease) callconv(.c) i32 = @ptrFromInt(self.table.device_acquire);
        return callback(reference, request, output);
    }

    pub fn deviceSegment(self: *const Context, lease: *const abi.GfxDeviceLease, offset: u64, output: *abi.GfxDmaSegment) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "device_segment") + 8 or self.table.device_segment == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxDeviceLease, u64, *abi.GfxDmaSegment) callconv(.c) i32 = @ptrFromInt(self.table.device_segment);
        return callback(lease, offset, output);
    }

    pub fn deviceRelease(self: *const Context, lease: *const abi.GfxDeviceLease, quiesced: u32) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "device_release") + 8 or self.table.device_release == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxDeviceLease, u32) callconv(.c) i32 = @ptrFromInt(self.table.device_release);
        return callback(lease, quiesced);
    }

    pub fn mmioMap(self: *const Context, request: *const abi.GfxMmioRequest, output: *abi.GfxMmioWindow) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "mmio_map") + 8 or self.table.mmio_map == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxMmioRequest, *abi.GfxMmioWindow) callconv(.c) i32 = @ptrFromInt(self.table.mmio_map);
        return callback(request, output);
    }

    pub fn mmioUnmap(self: *const Context, window: *const abi.GfxBufferHandle, quiesced: u32) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "mmio_unmap") + 8 or self.table.mmio_unmap == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBufferHandle, u32) callconv(.c) i32 = @ptrFromInt(self.table.mmio_unmap);
        return callback(window, quiesced);
    }

    pub fn collect(self: *const Context) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "collect") + 8 or self.table.collect == 0) return abi.err_no_fn;
        const callback: *const fn () callconv(.c) i32 = @ptrFromInt(self.table.collect);
        return callback();
    }

    pub fn bufferStats(self: *const Context, output: *abi.GfxBufferStats) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_stats") + 8 or self.table.buffer_stats == 0) return abi.err_no_fn;
        const callback: *const fn (*abi.GfxBufferStats) callconv(.c) i32 = @ptrFromInt(self.table.buffer_stats);
        return callback(output);
    }

    pub fn bufferReserve(self: *const Context, input: *const abi.GfxBufferDescriptor, cookie: u64, output: *abi.GfxOwnedBufferReservation) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_reserve") + 8 or self.table.buffer_reserve == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxBufferDescriptor, u64, *abi.GfxOwnedBufferReservation) callconv(.c) i32 = @ptrFromInt(self.table.buffer_reserve);
        return callback(input, cookie, output);
    }

    pub fn bufferCommit(self: *const Context, input: *const abi.GfxOwnedBufferReservation, output: *abi.GfxBufferReference) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_commit") + 8 or self.table.buffer_commit == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxOwnedBufferReservation, *abi.GfxBufferReference) callconv(.c) i32 = @ptrFromInt(self.table.buffer_commit);
        return callback(input, output);
    }

    pub fn bufferAbort(self: *const Context, input: *const abi.GfxOwnedBufferReservation, quiesced: u32) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_abort") + 8 or self.table.buffer_abort == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxOwnedBufferReservation, u32) callconv(.c) i32 = @ptrFromInt(self.table.buffer_abort);
        return callback(input, quiesced);
    }

    pub fn bufferTakeRelease(self: *const Context, adapter: u32, generation: u64, output: *abi.GfxOwnedBufferRelease) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_take_release") + 8 or self.table.buffer_take_release == 0) return abi.err_no_fn;
        const callback: *const fn (u32, u64, *abi.GfxOwnedBufferRelease) callconv(.c) i32 = @ptrFromInt(self.table.buffer_take_release);
        return callback(adapter, generation, output);
    }

    pub fn bufferFinishRelease(self: *const Context, input: *const abi.GfxOwnedBufferRelease, quiesced: u32) i32 {
        if (self.table.version != 1 or self.table.size < @offsetOf(abi.GfxDriverMemoryApi, "buffer_finish_release") + 8 or self.table.buffer_finish_release == 0) return abi.err_no_fn;
        const callback: *const fn (*const abi.GfxOwnedBufferRelease, u32) callconv(.c) i32 = @ptrFromInt(self.table.buffer_finish_release);
        return callback(input, quiesced);
    }
};
