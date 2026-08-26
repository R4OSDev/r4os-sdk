# R4OS SDK

The host-neutral R4OS SDK provides Zig and C startup code, platform facades,
module build support, templates, build profiles, and generic Runtime-R4L
helpers. The platform API and ABI remain canonical in the separate Contract
repository.

Subsystem R4X hosts can compose the allocation-free `subsystem_host` video
and input layer with `subsystem_runtime` for bounded guest slices, monotonic
guest time, lifecycle control, paced frames, and buffered S16LE audio through
the regular app audio facade. Audio streams are materialized on the first
non-silent quantum; silence, pause, mute, and reset submit no full zero PCM
payload and close an active sink once without affecting guest time or video.
Runnable slices with completed operations yield cooperatively; a progress
result with zero operations and no deadline waits one bounded host tick so an
idle guest cannot turn into an active scheduler scan loop.

## Service loops

`r4os.ServiceLoop` is the shared main-loop mechanism for R4X services. It
combines endpoint waits, the earliest service-owned absolute deadline, a
bounded stop-safety check, and queue draining limited to the endpoint depth.
Filled queues are processed without a forced tick between requests and yield
cooperatively after the batch budget. `ServiceLoopMetrics` and `report()`
provide passive numeric wait, wake, drain, and fairness counters without an
API or ABI extension.

The append-only R4DEV tail includes a PCI inventory performance snapshot.
Zig and C facades expose its source, capacity, configuration-access, ECAM
mapping, lookup, materialization, and enumeration timing counters while
remaining optional for older kernels.

DriverApi v20 exposes bounded audio-refill work with an absolute tick
deadline, a stable device key, and a maximum four-tick callback budget. It is
separate from the existing normal Driver Work submission facade.

DriverApi v21 additionally lets XHCI.R4D activate the sole kernel-resident
USB-host owner. UsbHostController v2 exposes productive port, control, bulk,
interrupt, recovery and poll callbacks plus capability and activity status;
it does not authorize a second PCI/MMIO/DMA implementation in the module.

DriverApi v22 appends owner-bound registration of exactly one synchronous
display-blit backend. The callback borrows a validated XRGB32 source, target
and at most eight regions for one call; the kernel retains target ownership,
fence completion and the complete CPU fallback.

DriverApi v23 exposes `DriverContext.netScheduleRx` as the IRQ-safe publication
point for adapter RX work. `netReceiveFrame` remains task-only and copies into
Netcore's bounded ownership queue; a busy result requires the driver to retain
the current device buffer and schedule a retry.

DriverApi v24 adds `netBackendQuery` and `netReceivePacket`. A v2 backend reads
its immutable offered/accepted/rejected selection after registration. Packet
metadata never removes the mandatory canonical flat bytes; return value 1
means those bytes were accepted through software fallback. The current BSP
selection is one queue and validated RX TCP/UDP checksum metadata only.

JavaScript programs publish a non-zero bytecode generation after validation.
Normal, generator, and async calls check that generation in constant time;
the full fingerprint remains available as an explicit integrity diagnostic.
The browser WebRuntime allocates its large JavaScript realm only when the
first script or module needs it and releases the complete realm on document
abort, replacement, or deinitialization.

## Dependency mapping

`Settings.R4S` maps the local Contract and workspace paths. Relative and
absolute mappings are supported. Use the repository build starters so those
mappings are applied before Zig resolves packages.

## Build and validation

On Windows:

    Build.bat test

On Linux or macOS:

    ./Build.sh test

Detailed German migration notes are preserved in
`DOCUMENTATION.de.txt`.

## License

Original R4OS material is licensed under Apache License 2.0. See `LICENSE`,
`NOTICE`, and `THIRD_PARTY_NOTICES.md`.
