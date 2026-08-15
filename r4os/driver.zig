const abi = @import("r4os_contract").abi;

pub const r4d_shutdown_entry_offset: u32 = 5;

pub fn entriesAsm(comptime init_target: []const u8, comptime shutdown_target: []const u8) []const u8 {
    return ".section .text.r4d_entries,\"ax\"\n" ++
        ".global r4d_init_entry\n" ++
        "r4d_init_entry:\n" ++
        "    jmp " ++ init_target ++ "\n" ++
        ".global r4d_shutdown_entry\n" ++
        "r4d_shutdown_entry:\n" ++
        "    jmp " ++ shutdown_target ++ "\n";
}

pub const Context = struct {
    api: *const abi.DriverApi,

    pub fn init(api: *const abi.DriverApi) Context {
        return .{ .api = api };
    }

    pub fn apiMagic(self: *const Context) u32 {
        return self.api.magic;
    }

    pub fn apiVersion(self: *const Context) u32 {
        return self.api.version;
    }

    pub fn apiSize(self: *const Context) u32 {
        return self.api.size;
    }

    pub fn apiHeaderValid(self: *const Context) bool {
        return self.api.magic == abi.driver_magic and self.api.size >= 16;
    }

    pub fn supportsDriverApi(self: *const Context, min_version: u32, min_size: u32) bool {
        return self.apiHeaderValid() and self.api.version >= min_version and self.api.size >= min_size;
    }

    pub fn apiCompatible(self: *const Context) bool {
        return self.supportsDriverApi(abi.driver_api_version, @intCast(@sizeOf(abi.DriverApi)));
    }

    pub fn logInfo(self: *const Context, text: [*:0]const u8) void {
        self.api.log_info(text);
    }

    pub fn logWarn(self: *const Context, text: [*:0]const u8) void {
        self.api.log_warn(text);
    }

    pub fn logError(self: *const Context, text: [*:0]const u8) void {
        self.api.log_error(text);
    }

    pub fn portInb(self: *const Context, port: u16) u8 {
        return self.api.port_inb(port);
    }

    pub fn portOutb(self: *const Context, port: u16, value: u8) void {
        self.api.port_outb(port, value);
    }

    pub fn portInw(self: *const Context, port: u16) u16 {
        return self.api.port_inw(port);
    }

    pub fn portOutw(self: *const Context, port: u16, value: u16) void {
        self.api.port_outw(port, value);
    }

    pub fn portInl(self: *const Context, port: u16) u32 {
        return self.api.port_inl(port);
    }

    pub fn portOutl(self: *const Context, port: u16, value: u32) void {
        self.api.port_outl(port, value);
    }

    pub fn getOption(self: *const Context, driver_name: [*:0]const u8, key: [*:0]const u8) [*:0]const u8 {
        return self.api.get_option(driver_name, key);
    }

    pub fn registerSynthEngine(self: *const Context, name: [*:0]const u8, engine: *const anyopaque) i32 {
        return self.api.register_synth_engine(name, engine);
    }

    pub fn registerSynthEngineEx(self: *const Context, name: [*:0]const u8, engine: *const abi.SynthEngine) i32 {
        return self.api.register_synth_engine_v2(name, engine);
    }

    pub fn registerAudioOutputBackend(self: *const Context, name: [*:0]const u8, backend: *const abi.AudioBackend) i32 {
        return self.api.register_audio_output_backend(name, backend);
    }

    pub fn unregisterAudioBackend(self: *const Context, name: [*:0]const u8) i32 {
        return self.api.unregister_audio_backend(name);
    }

    pub fn registerNetBackend(self: *const Context, name: [*:0]const u8, backend: *const abi.NetBackend) i32 {
        return self.api.register_net_backend(name, backend);
    }

    pub fn registerStorageBackend(self: *const Context, name: [*:0]const u8, backend: *const abi.StorageBackend) i32 {
        return self.api.register_storage_backend(name, backend);
    }

    pub fn unregisterStorageBackend(self: *const Context, name: [*:0]const u8) i32 {
        return self.api.unregister_storage_backend(name);
    }

    pub fn storageBackendRecoveryBegin(self: *const Context, name: [*:0]const u8) i32 {
        return self.api.storage_backend_recovery_begin(name);
    }

    pub fn storageBackendRecoveryFinish(self: *const Context, name: [*:0]const u8, ok: bool) i32 {
        return self.api.storage_backend_recovery_finish(name, if (ok) 1 else 0);
    }

    pub fn registerUsbHostController(self: *const Context, name: [*:0]const u8, backend: *const abi.UsbHostController) i32 {
        return self.api.register_usb_host_controller(name, backend);
    }

    pub fn unregisterUsbHostController(self: *const Context, name: [*:0]const u8) i32 {
        return self.api.unregister_usb_host_controller(name);
    }

    pub fn netReceiveFrame(self: *const Context, adapter_index: i32, frame: []const u8) i32 {
        return self.api.net_receive_frame(adapter_index, frame.ptr, @intCast(frame.len));
    }

    pub fn allocDmaRegion(self: *const Context, bytes: u32, alignment: u32, out: *abi.DmaBuffer) i32 {
        return self.api.alloc_dma_region(bytes, alignment, out);
    }

    pub fn freeDmaRegion(self: *const Context, buffer: *abi.DmaBuffer) void {
        self.api.free_dma_region(buffer);
    }

    pub fn pciDeviceCount(self: *const Context) u32 {
        return self.api.pci_device_count();
    }

    pub fn pciDeviceAt(self: *const Context, index: u32, out: *abi.PciDeviceInfo) i32 {
        return self.api.pci_device_at(index, out);
    }

    pub fn pciFindByClass(self: *const Context, class_code: u8, subclass: u8, start_index: u32, out: *abi.PciDeviceInfo) i32 {
        return self.api.pci_find_by_class(class_code, subclass, start_index, out);
    }

    pub fn pciReadConfig32(self: *const Context, info: abi.PciDeviceInfo, offset: u16) u32 {
        return self.api.pci_read_config32(info.bus_kind, info.bus, info.device, info.function, offset);
    }

    pub fn pciWriteConfig32(self: *const Context, info: abi.PciDeviceInfo, offset: u16, value: u32) i32 {
        return self.api.pci_write_config32(info.bus_kind, info.bus, info.device, info.function, offset, value);
    }

    pub fn pciReadBar(self: *const Context, info: abi.PciDeviceInfo, index: u8) u32 {
        return self.api.pci_read_bar(info.bus_kind, info.bus, info.device, info.function, index);
    }

    pub fn pciEnableBusMaster(self: *const Context, info: abi.PciDeviceInfo, flags: u32) i32 {
        return self.api.pci_enable_bus_master(info.bus_kind, info.bus, info.device, info.function, flags);
    }

    pub fn pciMapBar(self: *const Context, info: abi.PciDeviceInfo, index: u8, bytes: u32, flags: u32, out: *abi.MmioRegion) i32 {
        return self.api.pci_map_bar(info.bus_kind, info.bus, info.device, info.function, index, bytes, flags, out);
    }

    pub fn irqRegister(self: *const Context, irq: u8, handler: abi.IrqHandler, context: usize, flags: u32) i32 {
        return self.api.irq_register(irq, handler, context, flags);
    }

    pub fn pciEnableMsi(self: *const Context, info: abi.PciDeviceInfo) i32 {
        return self.api.pci_enable_msi(info.bus_kind, info.bus, info.device, info.function);
    }

    pub fn irqUnregister(self: *const Context, irq: u8, handler: abi.IrqHandler, context: usize) i32 {
        return self.api.irq_unregister(irq, handler, context);
    }

    pub fn irqStats(self: *const Context, irq: u8, out: *abi.IrqStats) i32 {
        return self.api.irq_stats(irq, out);
    }

    pub fn workSubmit(self: *const Context, handler: abi.DriverWorkHandler, context: usize, flags: u32, out_handle: *u32) i32 {
        return self.api.driver_work_submit(handler, context, flags, out_handle);
    }

    pub fn workCancel(self: *const Context, handle: u32) i32 {
        return self.api.driver_work_cancel(handle);
    }

    pub fn completionWait(self: *const Context, handle: u32, timeout_ticks: u64, out_result: *i32) i32 {
        return self.api.driver_completion_wait(handle, timeout_ticks, out_result);
    }

    pub fn completionStatus(self: *const Context, handle: u32, out: *abi.DriverCompletionStatus) i32 {
        return self.api.driver_completion_status(handle, out);
    }

    pub fn completionRelease(self: *const Context, handle: u32) i32 {
        return self.api.driver_completion_release(handle);
    }

    pub fn workSummary(self: *const Context, out: *abi.DriverWorkSummary) i32 {
        return self.api.driver_work_summary(out);
    }

    pub fn tickCount(self: *const Context) u64 {
        return self.api.tick_count();
    }

    pub fn timerFrequency(self: *const Context) u32 {
        return self.api.timer_frequency();
    }

    pub fn waitTicks(self: *const Context, ticks: u64) void {
        self.api.wait_ticks(ticks);
    }
};
