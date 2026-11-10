//! Explicit typed DriverApi2 convenience facade. No legacy table is
//! synthesized and no method grants another execution scope a driver owner.
const abi = @import("r4os_contract").abi;
const technical = @import("technical2.zig");
const driver = @import("driver.zig");
pub const Api = technical.abi.DriverApi2;
fn Callback(comptime field: []const u8) type {
    const T = @FieldType(Api, field);
    return if (@typeInfo(T) == .optional) @typeInfo(T).optional.child else T;
}
pub const Context = struct {
    api: *const Api,
    pub fn init(api: *const Api) Context {
        return .{ .api = api };
    }
    pub fn apiCompatible(self: *const Context) bool {
        return technical.Driver.init(self.api) != null;
    }
    pub fn function(self: *const Context, comptime field: []const u8) ?Callback(field) {
        return (technical.Driver.init(self.api) orelse return null).function(field);
    }
    /// Validate this driver's actual capability set before allocating or
    /// publishing anything. The supplied boot table stays immutable/live
    /// through every callback and its terminal Shutdown acknowledgement.
    pub fn requires(self: *const Context, comptime fields: anytype) bool {
        if (!self.apiCompatible()) return false;
        inline for (fields) |field| if (self.function(field) == null) return false;
        return true;
    }
    fn required(self: *const Context, comptime field: []const u8) Callback(field) {
        return self.function(field) orelse @trap();
    }
    pub fn monotonicClock(self: *const Context, out: *abi.MonotonicClockInfo) i32 {
        const callback = self.function("monotonic_clock") orelse return abi.err_no_fn;
        return callback(out);
    }
    // These records have their own revision and owner. Query them through
    // DriverApi2 without constructing a legacy platform table or wrapper.
    pub fn heap(self: *const Context) ?@import("driver_heap.zig").Context {
        const query = self.function("heap_query") orelse return null;
        var table: abi.DriverHeapApi = .{};
        if (query(&table) != abi.driver_heap_ok or table.version != 1 or table.size < @sizeOf(abi.DriverHeapApi)) return null;
        return .{ .table = table };
    }
    pub fn resources(self: *const Context) ?@import("driver_resources.zig").Context {
        const query = self.function("resource_query") orelse return null;
        var table: abi.DriverResourceApi = .{};
        if (query(&table) != abi.driver_resource_ok or table.version != 1 or table.size < 32) return null;
        return .{ .table = table };
    }
    pub fn threads(self: *const Context) ?@import("driver_threads.zig").Context {
        const query = self.function("thread_query") orelse return null;
        var table: abi.DriverThreadApi = .{};
        if (query(&table) != 0 or table.version != 1 or table.size < abi.driver_thread_api_min_bytes) return null;
        return .{ .table = table };
    }
    pub fn semaphores(self: *const Context) ?@import("driver_semaphores.zig").Context {
        const query = self.function("semaphore_query") orelse return null;
        var table: abi.DriverSemaphoreApi = .{};
        if (query(&table) != 0 or table.version != 1 or table.size < @sizeOf(abi.DriverSemaphoreApi)) return null;
        return .{ .table = table };
    }
    pub fn activateUsbHostController(self: *const Context, name: [*:0]const u8, source: u32) i32 {
        return self.required("activate_usb_host_controller")(name, source);
    }
    pub fn unregisterUsbHostController(self: *const Context, name: [*:0]const u8) i32 {
        return self.required("unregister_usb_host_controller")(name);
    }
    pub fn createSharedDmaBuffer(self: *const Context, bytes: u32, max_phys: u64) ?*driver.SharedDmaBuffer {
        return driver.createSharedDmaBuffer(self, bytes, max_phys);
    }
    pub fn releaseSharedDmaBuffer(self: *const Context, buffer: *driver.SharedDmaBuffer) void {
        driver.releaseSharedDmaBuffer(buffer, self);
    }
    pub fn allocDmaRegion(self: *const Context, bytes: u32, alignment: u32, out: *abi.DmaBuffer) i32 {
        return self.required("alloc_dma_region")(bytes, alignment, out);
    }

    pub fn allocDmaRegionConstrained(self: *const Context, bytes: u32, alignment: u32, max_phys_addr: u64, out: *abi.DmaBuffer) i32 {
        return self.required("alloc_dma_region_constrained")(bytes, alignment, max_phys_addr, out);
    }

    pub fn completionRelease(self: *const Context, handle: u32) i32 {
        return self.required("driver_completion_release")(handle);
    }

    pub fn completionStatus(self: *const Context, handle: u32, out: *abi.DriverCompletionStatus) i32 {
        return self.required("driver_completion_status")(handle, out);
    }

    pub fn completionWait(self: *const Context, handle: u32, timeout_ticks: u64, out_result: *i32) i32 {
        return self.required("driver_completion_wait")(handle, timeout_ticks, out_result);
    }

    pub fn freeDmaRegion(self: *const Context, buffer: *abi.DmaBuffer) void {
        self.required("free_dma_region")(buffer);
    }

    pub fn irqRegister(self: *const Context, irq: u8, handler: abi.IrqHandler, context: usize, flags: u32) i32 {
        return self.required("irq_register")(irq, handler, context, flags);
    }

    pub fn irqUnregister(self: *const Context, irq: u8, handler: abi.IrqHandler, context: usize) i32 {
        return self.required("irq_unregister")(irq, handler, context);
    }

    pub fn logError(self: *const Context, text: [*:0]const u8) void {
        if (self.function("log_error")) |callback| callback(text);
    }

    pub fn logInfo(self: *const Context, text: [*:0]const u8) void {
        if (self.function("log_info")) |callback| callback(text);
    }

    pub fn logWarn(self: *const Context, text: [*:0]const u8) void {
        if (self.function("log_warn")) |callback| callback(text);
    }

    pub fn mapDmaPinned(self: *const Context, pin: *const abi.DmaPinnedBuffer, constraints: *const abi.DmaConstraints, direction: u32, out: *abi.DmaMapping) i32 {
        return self.required("dma_map_pinned")(pin, constraints, direction, out);
    }

    pub fn pciDisableMsi(self: *const Context, info: abi.PciDeviceInfo) i32 {
        return self.required("pci_disable_msi")(info.bus_kind, info.bus, info.device, info.function);
    }

    pub fn pciEnableBusMaster(self: *const Context, info: abi.PciDeviceInfo, flags: u32) i32 {
        return self.required("pci_enable_bus_master")(info.bus_kind, info.bus, info.device, info.function, flags);
    }

    pub fn pciEnableMsi(self: *const Context, info: abi.PciDeviceInfo) i32 {
        return self.required("pci_enable_msi")(info.bus_kind, info.bus, info.device, info.function);
    }

    pub fn pciFindByClass(self: *const Context, class_code: u8, subclass: u8, start_index: u32, out: *abi.PciDeviceInfo) i32 {
        return self.required("pci_find_by_class")(class_code, subclass, start_index, out);
    }

    pub fn pciMapBar(self: *const Context, info: abi.PciDeviceInfo, index: u8, bytes: u32, flags: u32, out: *abi.MmioRegion) i32 {
        return self.required("pci_map_bar")(info.bus_kind, info.bus, info.device, info.function, index, bytes, flags, out);
    }

    pub fn pciReadConfig32(self: *const Context, info: abi.PciDeviceInfo, offset: u16) u32 {
        return self.required("pci_read_config32")(info.bus_kind, info.bus, info.device, info.function, offset);
    }

    pub fn pciWriteConfig32(self: *const Context, info: abi.PciDeviceInfo, offset: u16, value: u32) i32 {
        return self.required("pci_write_config32")(info.bus_kind, info.bus, info.device, info.function, offset, value);
    }

    pub fn pinDmaBuffer(self: *const Context, buffer: []u8, out: *abi.DmaPinnedBuffer) i32 {
        if (buffer.len == 0 or buffer.len > abi.dma_mapping_max_bytes) return -2;
        return self.required("dma_pin_buffer")(@intFromPtr(buffer.ptr), @intCast(buffer.len), 0, out);
    }

    pub fn pinDmaConstBuffer(self: *const Context, buffer: []const u8, out: *abi.DmaPinnedBuffer) i32 {
        if (buffer.len == 0 or buffer.len > abi.dma_mapping_max_bytes) return -2;
        return self.required("dma_pin_buffer")(@intFromPtr(buffer.ptr), @intCast(buffer.len), 0, out);
    }

    pub fn portInb(self: *const Context, port: u16) u8 {
        return self.required("port_inb")(port);
    }

    pub fn portInw(self: *const Context, port: u16) u16 {
        return self.required("port_inw")(port);
    }
    pub fn portInl(self: *const Context, port: u16) u32 {
        return self.required("port_inl")(port);
    }

    pub fn portOutb(self: *const Context, port: u16, value: u8) void {
        self.required("port_outb")(port, value);
    }

    pub fn portOutw(self: *const Context, port: u16, value: u16) void {
        self.required("port_outw")(port, value);
    }
    pub fn portOutl(self: *const Context, port: u16, value: u32) void {
        self.required("port_outl")(port, value);
    }

    pub fn registerStorageBackend(self: *const Context, name: [*:0]const u8, backend: *const abi.StorageBackend) i32 {
        return self.required("register_storage_backend")(name, backend);
    }

    pub fn storageBackendRecoveryBegin(self: *const Context, name: [*:0]const u8) i32 {
        return self.required("storage_backend_recovery_begin")(name);
    }

    pub fn storageBackendRecoveryFinish(self: *const Context, name: [*:0]const u8, ok: bool) i32 {
        return self.required("storage_backend_recovery_finish")(name, if (ok) 1 else 0);
    }

    pub fn tickCount(self: *const Context) u64 {
        return self.required("tick_count")();
    }

    pub fn timerFrequency(self: *const Context) u32 {
        return self.required("timer_frequency")();
    }

    pub fn unmapDma(self: *const Context, mapping: *abi.DmaMapping) i32 {
        return self.required("dma_unmap")(mapping);
    }

    pub fn unpinDmaBuffer(self: *const Context, pin: *abi.DmaPinnedBuffer) i32 {
        return self.required("dma_unpin_buffer")(pin);
    }

    pub fn waitTicks(self: *const Context, ticks: u64) void {
        self.required("wait_ticks")(ticks);
    }

    pub fn workCancel(self: *const Context, handle: u32) i32 {
        return self.required("driver_work_cancel")(handle);
    }

    pub fn workSubmit(self: *const Context, handler: abi.DriverWorkHandler, context: usize, flags: u32, out_handle: *u32) i32 {
        return self.required("driver_work_submit")(handler, context, flags, out_handle);
    }
};

test "DriverApi2 queries preserve independent record revision and reject missing prefix or malformed results" {
    const std = @import("std");
    const F = struct {
        var mode: u32 = 0;
        var calls: usize = 0;
        fn result(comptime T: type, out: *T) i32 {
            calls += 1;
            out.* = .{};
            out.version = if (mode == 1) 2 else 1;
            out.size = if (mode == 2) 8 else @sizeOf(T);
            return if (mode == 3) -1 else 0;
        }
        fn heap(out: *abi.DriverHeapApi) callconv(.c) i32 {
            return result(abi.DriverHeapApi, out);
        }
        fn resources(out: *abi.DriverResourceApi) callconv(.c) i32 {
            return result(abi.DriverResourceApi, out);
        }
        fn threads(out: *abi.DriverThreadApi) callconv(.c) i32 {
            return result(abi.DriverThreadApi, out);
        }
        fn semaphores(out: *abi.DriverSemaphoreApi) callconv(.c) i32 {
            return result(abi.DriverSemaphoreApi, out);
        }
    };
    var api: Api = undefined;
    @memset(std.mem.asBytes(&api), 0);
    api.magic = technical.abi.driver_magic;
    api.version = technical.abi.driver_version;
    api.size = @sizeOf(Api);
    const ctx = Context.init(&api);
    try std.testing.expect(ctx.heap() == null and ctx.resources() == null and ctx.threads() == null and ctx.semaphores() == null);
    api.heap_query = F.heap;
    api.resource_query = F.resources;
    api.thread_query = F.threads;
    api.semaphore_query = F.semaphores;
    const heap = ctx.heap().?;
    try std.testing.expect(ctx.resources() != null and ctx.threads() != null and ctx.semaphores() != null);
    try std.testing.expectEqual(@as(u32, 1), heap.table.version);
    for (1..4) |mode| {
        F.mode = @intCast(mode);
        try std.testing.expect(ctx.heap() == null and ctx.resources() == null and ctx.threads() == null and ctx.semaphores() == null);
    }
    try std.testing.expectEqual(@as(u32, 1), heap.table.version);
    const calls = F.calls;
    api.size = @offsetOf(Api, "resource_query");
    try std.testing.expect(ctx.heap() == null and ctx.resources() == null and ctx.threads() == null and ctx.semaphores() == null);
    try std.testing.expectEqual(calls, F.calls);
}

test "actual DriverApi2 callback admission and shared DMA references retain the original owner" {
    const std = @import("std");
    const Fake = struct {
        var backing: [8192]u8 align(4096) = undefined;
        var logs: usize = 0;
        var frees: usize = 0;
        var independent_descriptor = false;
        fn log(_: [*:0]const u8) callconv(.c) void {
            logs += 1;
        }
        fn allocate(bytes: u32, alignment: u32, limit: u64, output: *abi.DmaBuffer) callconv(.c) i32 {
            if (bytes != backing.len or alignment != 4096 or limit != 0xffff_ffff) return -1;
            output.* = .{};
            output.virt_addr = @intFromPtr(&backing);
            output.bytes = bytes;
            return 0;
        }
        fn free(descriptor: *abi.DmaBuffer) callconv(.c) void {
            independent_descriptor = @intFromPtr(descriptor) < @intFromPtr(&backing) or
                @intFromPtr(descriptor) >= @intFromPtr(&backing) + backing.len;
            frees += 1;
            @memset(&backing, 0xdd);
        }
    };
    var api: Api = undefined;
    @memset(std.mem.asBytes(&api), 0);
    api.magic = technical.abi.driver_magic;
    api.version = technical.abi.driver_version;
    api.size = @sizeOf(Api);
    const ctx = Context.init(&api);
    try std.testing.expect(ctx.apiCompatible());
    try std.testing.expect(!ctx.requires(.{"log_info"}));
    ctx.logInfo("unavailable");
    try std.testing.expectEqual(@as(usize, 0), Fake.logs);
    api.log_info = Fake.log;
    try std.testing.expect(ctx.requires(.{"log_info"}));
    ctx.logInfo("available");
    try std.testing.expectEqual(@as(usize, 1), Fake.logs);
    api.alloc_dma_region_constrained = Fake.allocate;
    api.free_dma_region = Fake.free;
    try std.testing.expect(ctx.requires(.{ "alloc_dma_region_constrained", "free_dma_region" }));
    const buffer = ctx.createSharedDmaBuffer(4096, 0xffff_ffff) orelse return error.AllocationFailed;
    try std.testing.expectEqual(@intFromPtr(&Fake.backing) + 4096, @intFromPtr(buffer.data().ptr));
    try std.testing.expectEqual(@as(usize, 4096), buffer.data().len);
    buffer.retain();
    ctx.releaseSharedDmaBuffer(buffer);
    try std.testing.expectEqual(@as(usize, 0), Fake.frees);
    ctx.releaseSharedDmaBuffer(buffer);
    try std.testing.expectEqual(@as(usize, 1), Fake.frees);
    try std.testing.expect(Fake.independent_descriptor);
    api.magic = abi.driver_magic;
    try std.testing.expect(!ctx.apiCompatible());
    try std.testing.expect(!ctx.requires(.{"log_info"}));
    ctx.logInfo("wrong generation");
    try std.testing.expectEqual(@as(usize, 1), Fake.logs);
}
