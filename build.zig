const std = @import("std");
const r4os_build = @import("r4os/build.zig");

pub const build_api = r4os_build;
pub const Sdk = r4os_build.Sdk;
pub const SdkOptions = r4os_build.SdkOptions;
pub const HostProfile = r4os_build.HostProfile;
pub const R4XAppOptions = r4os_build.R4XAppOptions;
pub const R4XCAppOptions = r4os_build.R4XCAppOptions;
pub const R4AppOptions = r4os_build.R4AppOptions;
pub const R4CAppOptions = r4os_build.R4CAppOptions;
pub const AppProfile = r4os_build.AppProfile;
pub const R4DModuleOptions = r4os_build.R4DModuleOptions;
pub const R4PModuleOptions = r4os_build.R4PModuleOptions;
pub const R4LModuleOptions = r4os_build.R4LModuleOptions;
pub const R4MFBuildOptions = r4os_build.R4MFBuildOptions;

pub fn sdk(b: *std.Build, dependency: *std.Build.Dependency, opts: SdkOptions) Sdk {
    return Sdk.fromDependency(b, dependency, opts);
}

pub fn build(b: *std.Build) void {
    b.addNamedLazyPath("system_update_engine", b.path("r4os/system_update_engine.zig"));
    b.addNamedLazyPath("update_service_contract", b.path("r4os/update_service_contract.zig"));

    const contract_dependency = b.dependency("r4os_contract", .{});
    if (b.option(bool, "packager-only", "Build only the selected host R4M0 packager") orelse false) {
        b.installArtifact(r4os_build.addR4XBuilder(b, b.path("Tools/R4XBuilder/src/main.zig")));
        return;
    }
    if (b.option(bool, "catalog-only", "Build only the selected host ModuleCatalog") orelse false) {
        const target = b.standardTargetOptions(.{});
        const bundle = b.createModule(.{ .root_source_file = b.path("r4os/r4cp_convert.zig"), .target = target, .optimize = .ReleaseSafe });
        bundle.addImport("r4os_contract", contract_dependency.module("r4os_contract"));
        const root = b.createModule(.{ .root_source_file = b.path("Tools/ModuleCatalog/src/main.zig"), .target = target, .optimize = .ReleaseSafe });
        root.addImport("contract_bundle", bundle);
        b.installArtifact(b.addExecutable(.{ .name = "module-catalog", .root_module = root }));
        return;
    }
    const sdk_profile = Sdk.init(b, .{ .contract_dependency = contract_dependency });
    if (b.option(bool, "gui-oracle-only", "Build existing GUI callbacks/pixel oracle for language interop") orelse false) {
        const oracle = b.createModule(.{ .root_source_file = b.path("Tests/Conformance/GuiFacadePrototype05824.zig"), .target = b.graph.host, .optimize = .Debug, .pic = true });
        oracle.addImport("r4os", sdk_profile.createR4osModule(b.graph.host, .Debug));
        b.getInstallStep().dependOn(&b.addInstallFile(b.addObject(.{ .name = "r4sdk_gui_oracle", .root_module = oracle }).getEmittedBin(), "lib/r4sdk_gui_oracle.o").step);
        const platform_oracle = b.createModule(.{ .root_source_file = b.path("Tests/Conformance/AudioDeviceFacadePrototype05827.zig"), .target = b.graph.host, .optimize = .Debug, .pic = true });
        platform_oracle.addImport("r4os", sdk_profile.createR4osModule(b.graph.host, .Debug));
        b.getInstallStep().dependOn(&b.addInstallFile(b.addObject(.{ .name = "r4sdk_platform_oracle", .root_module = platform_oracle }).getEmittedBin(), "lib/r4sdk_platform_oracle.o").step);
        return;
    }
    if (b.option(bool, "gui-bridge-runtime-only", "Build only the shared GUI owner boundary") orelse false) {
        const native = b.option(bool, "gui-bridge-host-test", "Use native ABI for GUI bridge interop") orelse false;
        const object = r4os_build.addStorageRuntimeObject(b, b.path("r4os/gui_value_bridge.zig"), sdk_profile.profile.contract_module, sdk_profile.profile.grapheme_source.?, sdk_profile.builder, native);
        b.getInstallStep().dependOn(&b.addInstallFile(object, "lib/r4sdk_gui.o").step);
        return;
    }
    if (b.option(bool, "gui-bridge-generator-only", "Build the compiler-typed GUI bridge generator") orelse false) {
        const root = b.createModule(.{ .root_source_file = b.path("Tools/GuiBridgeGen/src/main.zig"), .target = b.graph.host, .optimize = .Debug });
        const schema = b.createModule(.{ .root_source_file = b.path("r4os/gui_bridge_schema.zig"), .target = b.graph.host, .optimize = .Debug });
        schema.addImport("r4os_contract", contract_dependency.module("r4os_contract"));
        schema.addImport("r4std_grapheme", b.createModule(.{ .root_source_file = sdk_profile.profile.grapheme_source.?, .target = b.graph.host, .optimize = .ReleaseSafe }));
        root.addImport("schema", schema);
        b.installArtifact(b.addExecutable(.{ .name = "gui-bridge-gen", .root_module = root }));
        return;
    }
    if (b.option(bool, "net-bridge-generator-only", "Build the compiler-typed SDK network bridge generator") orelse false) {
        const root = b.createModule(.{ .root_source_file = b.path("Tools/NetBridgeGen/src/main.zig"), .target = b.graph.host, .optimize = .ReleaseSafe });
        const bridge = b.createModule(.{ .root_source_file = b.path("r4os/net_bridge_support.zig"), .target = b.graph.host, .optimize = .ReleaseSafe });
        bridge.addImport("r4os_contract", contract_dependency.module("r4os_contract"));
        bridge.addImport("r4std_grapheme", b.createModule(.{ .root_source_file = sdk_profile.profile.grapheme_source.?, .target = b.graph.host, .optimize = .ReleaseSafe }));
        root.addImport("bridge", bridge);
        b.installArtifact(b.addExecutable(.{ .name = "net-bridge-gen", .root_module = root }));
        return;
    }
    if (b.option(bool, "facade-generator-only", "Build the compiler-typed SDK C/Rust facade projector") orelse false) {
        const root = b.createModule(.{ .root_source_file = b.path("Tools/CFacadeGen/src/main.zig"), .target = b.graph.host, .optimize = .ReleaseSafe, .link_libc = true });
        root.addImport("r4os_contract", contract_dependency.module("r4os_contract"));
        root.addIncludePath(sdk_profile.profile.c_include_root);
        root.addIncludePath(sdk_profile.profile.contract_c_include_root);
        b.installArtifact(b.addExecutable(.{ .name = "c-facade-gen", .root_module = root }));
        return;
    }
    if (b.option(bool, "facade-runtime-only", "Build the SDK C facade object for Rust consumers") orelse false) {
        const native = b.option(bool, "facade-host-test", "Use native ABI for facade interop only") orelse false;
        const object = r4os_build.addFacadeRuntime(b, b.path("Shared/C/src/facades.c"), sdk_profile.profile.c_include_root, sdk_profile.profile.contract_c_include_root, native);
        b.getInstallStep().dependOn(&b.addInstallFile(object, "lib/r4sdk_facades.o").step);
        const storage_runtime = r4os_build.addStorageRuntimeObject(b, b.path("r4os/facade_runtime.zig"), sdk_profile.profile.contract_module, sdk_profile.profile.grapheme_source.?, sdk_profile.builder, native);
        b.getInstallStep().dependOn(&b.addInstallFile(storage_runtime, "lib/r4sdk_storage.o").step);
        return;
    }
    const r4l_generator_tests = b.addRunArtifact(b.addTest(.{ .root_module = sdk_profile.r4l_contract_generator.?.root_module }));
    b.step("r4l-contract-test", "Run the existing library contract generator cases").dependOn(&r4l_generator_tests.step);
    if (b.option(bool, "r4l-contract-generator-only", "Build only the host library contract generator") orelse false) {
        b.installArtifact(sdk_profile.r4l_contract_generator.?);
        return;
    }
    if (b.option(bool, "heap-host-test-only", "Build the native SDK heap object for its host interop test") orelse false) {
        const root = b.createModule(.{ .root_source_file = b.path("r4os/heap_runtime.zig"), .target = b.graph.host, .optimize = .ReleaseSafe, .pic = true, .single_threaded = false, .stack_check = false });
        root.addImport("r4os_contract", contract_dependency.module("r4os_contract"));
        const object = b.addObject(.{ .name = "r4sdk_heap_host", .root_module = root });
        b.getInstallStep().dependOn(&b.addInstallFile(object.getEmittedBin(), "lib/r4sdk_heap_host.o").step);
        return;
    }
    const heap_runtime = sdk_profile.addHeapRuntime();
    b.getInstallStep().dependOn(&b.addInstallFile(heap_runtime, "lib/r4sdk_heap.o").step);
    if (b.option(bool, "heap-runtime-only", "Build only the module CPU-profile shared C/Rust heap object") orelse false) return;
    const facade_runtime = r4os_build.addFacadeRuntime(b, b.path("Shared/C/src/facades.c"), sdk_profile.profile.c_include_root, sdk_profile.profile.contract_c_include_root, false);
    b.getInstallStep().dependOn(&b.addInstallFile(facade_runtime, "lib/r4sdk_facades.o").step);
    b.getInstallStep().dependOn(&b.addInstallFile(sdk_profile.addStorageRuntime(), "lib/r4sdk_storage.o").step);
    b.installArtifact(sdk_profile.builder);
    if (sdk_profile.r4l_contract_generator) |generator| b.installArtifact(generator);

    const module_filter = b.option([]const u8, "module-filter", "Build only matching SDK smoke R4X names") orelse "";
    _ = sdk_profile.addR4MFCatalog(&.{b.path("Smoke")}, module_filter);
    _ = sdk_profile.addR4MFWithOptions(b.path("Tests/Build/R4MFMapping/module.R4MF"), .{
        .zig_module_roots = &.{ b.path("Tests/Build/R4MFMapping/Bindings/external.zig"), b.path("Tests/Build/R4MFMapping/Bindings/shared.zig") },
    });
    _ = sdk_profile.addR4MF(b.path("Tests/Build/SubsystemManifest/module.R4MF"));
    _ = sdk_profile.addR4D(.{
        .name = "SDKSMOKE",
        .driver_name = "SDKSMOKE",
        .driver_type = "misc",
        .root_source_file = b.path("Smoke/R4D/src/main.zig"),
    });
    _ = sdk_profile.addR4P(.{
        .name = "SDKSMOKE",
        .protocol_name = "SDKSMOKE",
        .role = "misc.sdk_smoke",
        .category = "misc",
        .root_source_file = b.path("Smoke/R4P/src/main.zig"),
    });

    const host_r4os = sdk_profile.createR4osModule(b.graph.host, .Debug);
    const gui_cases = b.createModule(.{ .root_source_file = b.path("Tests/Conformance/GuiFacadePrototype05824.zig"), .target = b.graph.host, .optimize = .Debug });
    gui_cases.addImport("r4os", host_r4os);
    const gui_parity = b.addRunArtifact(b.addTest(.{ .root_module = gui_cases, .filters = &.{ "raw GUI events", "command clipboard timer", "transactional paint", "buffered Canvas" } }));
    b.step("gui-parity-test", "Existing GUI events, frame/immutable generation, pixel and failure oracles").dependOn(&gui_parity.step);
    const graphics_parity = b.addRunArtifact(b.addTest(.{ .root_module = gui_cases, .filters = &.{ "graphics buffer optional tails", "old display and driver prefixes" } }));
    b.step("graphics-parity-test", "Existing graphics descriptors, generations, retire, cursor and telemetry cases").dependOn(&graphics_parity.step);
    const storage_cases = b.createModule(.{ .root_source_file = b.path("Tests/Conformance/StorageFacadePrototype05823.zig"), .target = b.graph.host, .optimize = .Debug });
    storage_cases.addImport("r4os", host_r4os);
    const storage_parity = b.addRunArtifact(b.addTest(.{ .root_module = storage_cases }));
    b.step("storage-parity-test", "Existing file/registry/physical storage cases and imported codec/path owners").dependOn(&storage_parity.step);
    const resource_cases = b.createModule(.{ .root_source_file = b.path("Tests/Conformance/ResourceFacadePrototype05825.zig"), .target = b.graph.host, .optimize = .Debug });
    resource_cases.addImport("r4os", host_r4os);
    const resource_parity = b.addRunArtifact(b.addTest(.{ .root_module = resource_cases, .filters = &.{ "process thread VM and I/O resources", "program handles reject stale copies", "sequential stress reuses" } }));
    b.step("resource-parity-test", "Existing process/thread/VM/I/O resource lifecycle cases only").dependOn(&resource_parity.step);
    const service_cases = b.createModule(.{ .root_source_file = b.path("Tests/Conformance/ServiceNetworkFacadePrototype05826.zig"), .target = b.graph.host, .optimize = .Debug });
    service_cases.addImport("r4os", host_r4os);
    const service_parity = b.addRunArtifact(b.addTest(.{ .root_module = service_cases, .filters = &.{ "service connection and endpoint", "resolver TCP and UDP", "service loop", "service deadline suffix", "net socket drain", "duration conversion", "duration and deadline", "tagged timeout", "deadline budget" } }));
    b.step("service-parity-test", "Existing service/network, bounded drain and absolute deadline owner cases").dependOn(&service_parity.step);
    const platform_cases = b.createModule(.{ .root_source_file = b.path("Tests/Conformance/AudioDeviceFacadePrototype05827.zig"), .target = b.graph.host, .optimize = .Debug });
    platform_cases.addImport("r4os", host_r4os);
    const platform_step = b.step("platform-parity-test", "Existing Audio/Device/PCM/Power owner cases");
    platform_step.dependOn(&b.addRunArtifact(b.addTest(.{ .root_module = platform_cases })).step);
    const pcm_cases = b.createModule(.{ .root_source_file = b.path("r4os/audio_pcm.zig"), .target = b.graph.host, .optimize = .Debug });
    platform_step.dependOn(&b.addRunArtifact(b.addTest(.{ .root_module = pcm_cases })).step);
    platform_step.dependOn(&b.addRunArtifact(b.addTest(.{ .root_module = service_cases, .filters = &.{ "power profile client", "power perCPU client" } })).step);
    const sdk_unit_tests = b.addTest(.{ .root_module = host_r4os });
    const run_sdk_unit_tests = b.addRunArtifact(sdk_unit_tests);
    const dialog_root = b.createModule(.{
        .root_source_file = b.path("r4os/gui.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    dialog_root.addImport("r4os_contract", sdk_profile.profile.contract_module);
    dialog_root.addImport("r4std_grapheme", b.createModule(.{ .root_source_file = sdk_profile.profile.grapheme_source.?, .target = b.graph.host, .optimize = .Debug }));
    const dialog_tests = b.addTest(.{ .root_module = dialog_root, .filters = &.{
        "bounded text", "text field",  "text fields",
        "text area",    "ellipsizing", "grapheme",
    } });
    b.step("dialog-text-test", "Actual bounded Unicode dialog and existing scalar widget cases").dependOn(&b.addRunArtifact(dialog_tests).step);

    const cpu_tests_root = b.createModule(.{
        .root_source_file = b.path("r4os/cpu_acceleration_tests.zig"),
        // Independent software SHA oracle; never select the host's optional
        // SHA backend while testing a synthetic executor and its rollback.
        .target = b.resolveTargetQuery(.{ .cpu_arch = .x86_64, .os_tag = b.graph.host.result.os.tag, .abi = b.graph.host.result.abi, .cpu_model = .baseline }),
        .optimize = .ReleaseSafe,
    });
    cpu_tests_root.addImport("r4os_contract", sdk_profile.profile.contract_module);
    const cpu_tests = b.addRunArtifact(b.addTest(.{ .root_module = cpu_tests_root }));
    b.step("cpu-acceleration-test", "Exact dispatch, SHA fallback/rollback, memory alignment/overlap/guard pages").dependOn(&cpu_tests.step);
    const entropy_tests_root = b.createModule(.{
        .root_source_file = b.path("r4os/secure_random.zig"),
        .target = b.resolveTargetQuery(.{ .cpu_arch = .x86_64, .os_tag = b.graph.host.result.os.tag, .abi = b.graph.host.result.abi, .cpu_model = .baseline }),
        .optimize = .ReleaseSafe,
    });
    entropy_tests_root.addImport("r4os_contract", sdk_profile.profile.contract_module);
    const entropy_tests = b.addRunArtifact(b.addTest(.{ .root_module = entropy_tests_root }));
    b.step("entropy-test", "Shared entropy CF bound, source fallback and whole-output failure").dependOn(&entropy_tests.step);

    const update_engine = b.createModule(.{
        .root_source_file = b.path("r4os/system_update_engine.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    update_engine.addImport("r4os", host_r4os);
    const update_status = b.createModule(.{
        .root_source_file = b.path("Tests/Simulation/CheckSystemUpdateStatus.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    update_status.addImport("r4os", host_r4os);
    update_status.addImport("update_engine", update_engine);
    const update_status_tests = b.addTest(.{
        .root_module = update_status,
        .filters = &.{"status resnapshots"},
    });
    const run_update_status_tests = b.addRunArtifact(update_status_tests);

    const vm_allocator_module = b.createModule(.{
        .root_source_file = b.path("r4os/vm_allocator.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    vm_allocator_module.addImport("r4os_contract", sdk_profile.profile.contract_module);
    const vm_allocator_tests = b.addTest(.{ .root_module = vm_allocator_module });
    const run_vm_allocator_tests = b.addRunArtifact(vm_allocator_tests);
    b.step("vm-allocator-test", "Run the existing VM allocator ownership and concurrency tests").dependOn(&run_vm_allocator_tests.step);

    const subsystem_runtime_module = b.createModule(.{
        .root_source_file = b.path("r4os/subsystem_runtime.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    subsystem_runtime_module.addImport("r4os_contract", sdk_profile.profile.contract_module);
    const subsystem_runtime_tests = b.addTest(.{ .root_module = subsystem_runtime_module });
    const run_subsystem_runtime_tests = b.addRunArtifact(subsystem_runtime_tests);

    const ntfs_format = b.createModule(.{
        .root_source_file = b.path("r4os/ntfs_format.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    const ntfs_volume = b.createModule(.{
        .root_source_file = b.path("r4os/ntfs_volume.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    ntfs_volume.addImport("ntfs_format", ntfs_format);
    const ntfs_volume_tests = b.addTest(.{ .root_module = ntfs_volume });
    const run_ntfs_volume_tests = b.addRunArtifact(ntfs_volume_tests);

    const r4x_builder_tests = b.addTest(.{
        .root_module = b.createModule(.{
            .root_source_file = b.path("Tools/R4XBuilder/src/main.zig"),
            .target = b.graph.host,
            .optimize = .Debug,
        }),
    });
    const run_r4x_builder_tests = b.addRunArtifact(r4x_builder_tests);
    b.step("packager-test", "Run existing R4M0/ELF packager ownership and relocation cases").dependOn(&run_r4x_builder_tests.step);

    const r4l_contract_tests = b.addTest(.{
        .root_module = b.createModule(.{
            .root_source_file = b.path("Tools/R4LContractGen/src/main.zig"),
            .target = b.graph.host,
            .optimize = .Debug,
        }),
    });
    const run_r4l_contract_tests = b.addRunArtifact(r4l_contract_tests);

    const catalog_bundle = b.createModule(.{
        .root_source_file = b.path("r4os/r4cp_convert.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    catalog_bundle.addImport("r4os_contract", sdk_profile.profile.contract_module);
    const catalog_root = b.createModule(.{
        .root_source_file = b.path("Tools/ModuleCatalog/src/main.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    catalog_root.addImport("contract_bundle", catalog_bundle);
    const catalog = b.addExecutable(.{ .name = "module-catalog", .root_module = catalog_root });
    b.installArtifact(catalog);
    const catalog_tests = b.addTest(.{ .root_module = catalog_bundle });
    const run_catalog_tests = b.addRunArtifact(catalog_tests);
    const catalog_tool_test_root = b.createModule(.{
        .root_source_file = b.path("Tools/ModuleCatalog/src/main.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    catalog_tool_test_root.addImport("contract_bundle", catalog_bundle);
    const catalog_tool_tests = b.addTest(.{ .root_module = catalog_tool_test_root });
    const run_catalog_tool_tests = b.addRunArtifact(catalog_tool_tests);
    const module_test_step = b.step("module-test", "Run the existing manifest and module catalog tests");
    module_test_step.dependOn(&run_catalog_tests.step);
    module_test_step.dependOn(&run_catalog_tool_tests.step);

    const test_step = b.step("test", "Run SDK, build-tool and smoke tests");
    const input_events_root = b.createModule(.{
        .root_source_file = b.path("r4os/input_events_tests.zig"),
        .target = b.graph.host,
        .optimize = .ReleaseSafe,
    });
    input_events_root.addImport("r4os_contract", sdk_profile.profile.contract_module);
    const input_events_tests = b.addRunArtifact(b.addTest(.{ .root_module = input_events_root }));
    b.step("input-events-test", "Typed console events, retained producer queue and inaccessible legacy table tail").dependOn(&input_events_tests.step);
    test_step.dependOn(&input_events_tests.step);
    test_step.dependOn(&cpu_tests.step);
    const storage_tools = b.createModule(.{
        .root_source_file = b.path("r4os/storage_tools.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    const storage_fixture = b.createModule(.{
        .root_source_file = b.path("Tests/Simulation/CheckStorageTools0769.zig"),
        .target = b.graph.host,
        .optimize = .Debug,
    });
    storage_fixture.addImport("storage_tools", storage_tools);
    const storage_tests = b.addRunArtifact(b.addTest(.{ .root_module = storage_fixture }));
    b.step("storage-tools-test", "Shared partition/format component fixtures and fault cases").dependOn(&storage_tests.step);
    test_step.dependOn(&storage_tests.step);
    test_step.dependOn(b.getInstallStep());
    test_step.dependOn(&run_sdk_unit_tests.step);
    test_step.dependOn(&run_update_status_tests.step);
    test_step.dependOn(&run_vm_allocator_tests.step);
    test_step.dependOn(&run_subsystem_runtime_tests.step);
    test_step.dependOn(&run_ntfs_volume_tests.step);
    test_step.dependOn(&run_r4x_builder_tests.step);
    test_step.dependOn(&run_r4l_contract_tests.step);
    test_step.dependOn(&run_catalog_tests.step);
    test_step.dependOn(&run_catalog_tool_tests.step);
}
