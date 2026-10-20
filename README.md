# R4OS SDK

The host-neutral R4OS SDK provides Zig and C startup code, platform facades,
module build support, templates, build profiles, and generic Runtime-R4L
helpers. The platform API and ABI remain canonical in the separate Contract
repository.

The optional `cpuIdleInfo` facade reads the separate R4DEV v29 idle receipt.
Driver CPU mechanisms negotiate `idlePublish` and `idlePolicy` individually
after the preserved168-byte prefix. Old tables return `err_no_fn` without
changing output. ACPI declarations and software attempts do not represent
measured hardware residency, wake latency or energy.

The shared update engine and recovery core accept only `R4U_JOURNAL=5`.
Formats 2–4 are unsupported; no compatibility conversion authorizes file
changes. V5 checksums, exact identities, copy selection, restart batches and
rollback remain supported, including new targets with `old_known=false`.

The shared update engine exposes SYSUPD's explicit `ARCHIVE-BOOT-BACKUP`
maintenance command. Its `system_update_backup` helper orders reference
checks, durable copy, complete comparison and conditional removal. Both
journal slots, boot configuration and sibling FAT identities must exclude
the candidate. Active stages, targets and retained journal backups stay
bound; no general cleanup or raw filesystem write is exposed.

Mixed Zig/C drivers use one Zig root followed by ordered C `SOURCE` entries
in their canonical `module.R4MF`, with `C_INCLUDE`, `C_DEFINE` and `C_FLAG`
for their C inputs. The SDK builds those companions into the same R4D ELF
and container, preserving the driver's entry and dependency contracts. The
existing mixed R4L path remains available; Zig R4X/R4P still have one source.
`R4DModuleOptions` and `R4DOptions` also expose the four corresponding C
options for direct build callers. Consumers that need the canonical parser
in a host build can use `build_api.module_manifest` instead of parsing a
second manifest format. After changing SDK manifest semantics, rebuild the
SDK host tools before running an image plan with an installed ModuleCatalog.

Subsystem R4X hosts can compose the allocation-free `subsystem_host` video
and input layer with `subsystem_runtime` for bounded guest slices, monotonic
guest time, lifecycle control, paced frames, and buffered S16LE audio through
the regular app audio facade. Audio streams are materialized on the first
non-silent quantum; silence, pause, mute, and reset submit no full zero PCM
payload and close an active sink once without affecting guest time or video.
Silent blocks retain their position in the bounded PCM queue and are suppressed
only at their audio deadline. Waiting guests refill only after a guest step or
a due quantum; repeated host polls cannot consume future silence. A temporary
empty producer buffer keeps the stream open and schedules a bounded retry.
Pause, mute, reset and shutdown still release it, and resume/unmute schedule
a fresh refill even if the guest remains waiting. Pending video is published
before audio work, and each host cycle performs at
most one open, write, or close service operation. Optional source-frame
feedback distinguishes accepted, suppressed, and discarded PCM while leaving
hardware playback explicitly unknown.
Runnable slices with completed operations yield cooperatively; a progress
result with zero operations and no deadline waits one bounded host tick so an
idle guest cannot turn into an active scheduler scan loop.
Input policies can preserve the default physical-key-plus-text/pointer model
or select one printable text event with pointer filtering before mapping.
Stable raw-event sequences and ticks, filter counters, and an ignored-without-
wakeup runtime result keep delivery and loss observable without event logs.
Manually constructed video backends may omit optional replacement, native
XRGB32 and shared-raster callbacks; unavailable hooks default to `err_no_fn`
with their capability flags disabled, preserving the copied full/damage path.

Draw-heavy Zig apps can attach a caller-owned `FrameCanvas` command/resource
buffer with `PaintContext.bufferedCanvas`. Existing Canvas widgets then share
bounded `gui_frame_append` chunks, while old R4DRAW tables retain the direct
draw path. Flush failures cancel the whole private frame, oversized individual
resources keep their ordering through a direct chunk or established draw
fallback, and per-frame statistics expose commands, bytes, flushes and actual
draw transitions without another ABI.

`r4os.subsystem_persistence` is the source-level companion for cartridge
subsystems. Consumers supply only their canonical save directories, exact RTC
record size and validator; the helper supplies one digest lease, exact reads,
immutable coalesced snapshots, a serial joinable worker, same-directory atomic
stage/target/last-good publication, bounded retry/recovery and drain-before-
release. Cartridge battery policy, memory sizing, codecs and guest clocks stay
with the subsystem. The helper is compiled into each consumer and creates no
R4L or platform ABI.

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

`r4dev.Context.kernelHeapCheck` explicitly runs the bounded kernel-heap
diagnostic through optional R4DEV v15. The fixed result separates its own
allocations and VM reservations from concurrent global observations.
Missing groups/functions preserve the caller output and return the existing
availability errors. A normal app has no reason to start this diagnostic;
Spectra owns `CHECK MEMORY /KERNELHEAP`, JSON presentation and export.

DriverApi v20 exposes bounded audio-refill work with an absolute tick
deadline, a stable device key, and a maximum four-tick callback budget. It is
separate from the existing normal Driver Work submission facade.

DriverApi v21 additionally lets XHCI.R4D activate the sole kernel-resident
USB-host owner. UsbHostController v2 exposes productive port, control, bulk,
interrupt, recovery and poll callbacks plus capability and activity status;
it does not authorize a second PCI/MMIO/DMA implementation in the module.

The optional `driver_queue.retainResource` tail (table 1/64) retains source
or target backing of an active native job, including after producer exit.
The 56-byte prefix remains supported. Mapping-only references (flag 2) allow
describe, DMA/GPU residency and release; execution stays with the validated
queue extent. CPU maps, sharing and new execution are rejected. Actual
Work/start ownership is checked on every call. Mapping and fence lifetimes
remain independent. See Contract/ABI/R4DDriver.txt.

The optional `driver_outputs` receiver-source tail registers immutable
receiver generations independently of execution queues. The original 24-byte
output table prefix stays valid; all three receiver callbacks require the
complete 48-byte tail. Receiver-only catalog entries carry zero source/routing
limits and cannot participate in an atomic scanout commit. Registration and
publication require the actual Init/Work owner; closed/stale sources cannot
publish. Caller records must stay resident and exclusively borrowed through
the call. Close revokes metadata without claiming GPU quiescence.

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
Since Kernel0.1.304 registration requires version2 and the complete120-byte
NetBackend. V1/short descriptors are rejected before registration or callbacks.
Flat callbacks, absent transmit_packet and existing poll paths remain valid;
optional features are not required. The v2 layout and DriverApi slots stay fixed.

JavaScript programs publish a non-zero bytecode generation after validation.
Normal, generator, and async calls check that generation in constant time;
the full fingerprint remains available as an explicit integrity diagnostic.
The browser WebRuntime allocates its large JavaScript realm only when the
first script or module needs it and releases the complete realm on document
abort, replacement, or deinitialization.

Typed file and registry paths initialize only their canonical bytes and the
required trailing zero. File normalization keeps its 160 rollback positions
as 16-bit offsets, for a fixed 640-byte temporary instead of two native-word
arrays; all public length, UTF-8, device-name, and normalization semantics are
unchanged in the Zig and C facades.

## Dependency mapping

The VM allocator keeps its existing bins, boundary tags, direct cache and
retention policy. Reserve, commit, decommit and release run with private
operation identity outside the shared metadata lock. Other threads can use
existing free blocks while that work waits; completion rebinds current block
metadata. Failed releases and decommits retain their exact retry identity.
The default allocator and explicit `vm_allocator.Heap` objects use the same
path. Keep an explicit heap at a stable address until all concurrent calls
and allocations have retired, including their notification cleanup.

Long contention uses the existing optional R4SYS notifications, observing a
revision before rechecking the predicate. Notifications close after their last
waiter; a failed close keeps the handle for retry. Older or partial tables
fall back to `sleep_ticks` where available, then the existing yield support.
No new kernel allocator API is required. Focused host validation of these
existing cases is available through `./Build.sh vm-allocator-test` (Windows:
`Build.bat vm-allocator-test`).

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

## File transfer counts

Kernel 0.1.291 bounds each R4SYS read/write/append/stream-write request,
including its read-buffer capacity, to `2147483647` bytes because byte results
are signed 32-bit values. Oversized requests return `io_error_too_large`
(`-10`) before queue admission or file mutation; an async request ID remains
zero. Existing 64-bit file sizes, modern range offsets, finish sizes and
lock ranges retain their previous types and limits. Split larger transfers
into suitable chunks. See `Docs/API/FileTransferLimits.txt` in the workspace.

## File copies

`Files.copy` / `file_stream.copy` and C `r4_files_copy` submit one optional
`file_copy_buffered` request with caller-owned scratch space. It checks
backend file identity before replacement and keeps the paired filesystem
request throughout copying. Results preserve exact completed byte/chunk
counts; old providers return unavailable without an unsafe truncate/read
fallback. Failure cleanup can fail and progress is not a retry offset.


Registry-Selbsttests ab 0.78.64
-----------------------------
REG WRITESELFTEST/APITEST/MIGRATESELFTEST und RegEdit /SELFTEST sind nur fuer
ein ausdruecklich privates Testimage vorgesehen. Die Test-Injection liefert
TEMP/REGTEST.R4S mit R4OS_REGISTRY_SELFTEST=PRIVATE_IMAGE; Slim/Full enthalten
diese Testdeklaration nicht. Das ist eine Diagnosekonvention und kein Rechte-
modell. Ohne Deklaration brechen die schreibenden Tests vor Mutationen ab.
REG SELFTEST bleibt ein reiner Speichertest.

Der gemeinsame SDK-Helfer registry_selftest laesst keine bereits vorhandenen
TMP/BAK-, Original-, Restore- oder Displaced-Dateien als eigenen Bestand zu.
Lesefehler werden nicht als Abwesenheit behandelt. Die Originalsicherung wird
vollstaendig mit dem zuvor gelesenen Inhalt verglichen. Zum Rueckbau entsteht
aus ihr eine gepruefte zweite Stagedatei; nur diese wird durch R4SYS atomar
uebernommen. Erst nach erfolgreichem Ersatz, Bytevergleich und Bereinigung
werden REGSYS.SAV beziehungsweise SYSTEM.REB entfernt und OK ausgegeben.
Fehler behalten die Originalkopie; ein erneuter Test ueberschreibt sie nicht.
REGs temporaere Exportdatei wird ebenfalls nur bei vorheriger Abwesenheit
verwendet. Die acht schon zuvor auf16Byte ausgerichteten Scratch-Slices
bleiben bis zur Freigabe ausgerichtet und werden jetzt rueckwaerts freigegeben.

Begleitkorrektur in Kernel0.1.128: Externer atomarer Dateiersatz invalidiert
betroffene Registry-Cacheansichten auch nach einem moeglicherweise partiellen
I/O-Fehler. Der interne Registry-Commit benutzt denselben Dateipfad mit
explizit internem Abschluss, damit sein eigener Kandidat erhalten bleibt.
So stimmen nach einem Restore Dateibytes und gelesene Cachegeneration wieder
ueberein. Kein neuer ABI-Slot und keine neue Kernel-Diagnoseschnittstelle.

Nachweis: vier gebuendelte Hostfaelle fuer fehlgeschlagene Kopie/Publikation,
bestehende Sicherungen, fehlend/leere Hive, beide App-Abschluesse und alle
acht teilweisen Scratchallokationen. Ein lokaler SMP4-Gast verwendet eine
frisch erzeugte private246-Byte-Hive, prueft beide vorhandenen Selbsttests,
Originalbytes, Cachegeneration1 und Bereinigung. Keine regulaere Installation
wird als Testbestand verwendet. Belege unter Temp/roadmap-078-execution/07864.


`r4os.document_save.Saver` is a caller-owned synchronous policy for small
editable documents. It stages 64 KB chunks in create-only 8.3 siblings,
confirms stream completion and uses `Files.replaceAtomic` without an
overwrite fallback. Its result distinguishes a confirmed save (including a
retained backup) from an unconfirmed save with retained copies. Callers
publish their path, Dirty flag and history only for a committed result.
The helper preserves relative-path semantics and adds no kernel ABI.


HTTP and URL boundaries (0.78.70)
---------------------------------
HTTP URL parsing and request serialization both reject literal control
bytes, whitespace, fragments and incomplete percent escapes in a request
target. The serializer preserves valid percent escapes and percent-encodes
UTF-8 and other non-URI bytes. It also validates directly constructed URL
hosts and custom header names before emitting those fields. Existing
header-value checks remain in place.

URL parts search for a query only before the first fragment delimiter.
URL and Location getters/setters and Origin parsing already use this shared
splitter. Navigation and HTTP redirects now share reference resolution and
path normalization. Only complete dot segments are removed; query and
fragment data, encoded dots and repeated path slashes retain their meaning.
The HTTP resolver still uses caller capacity rather than the browser's
767-byte navigation limit.

A complete response head now returns a specific status/version/header/
length/transfer error. Both response decoders preserve a known header error
across later EOF. Missing terminators remain need_more until EOF; a valid
response with no fields is accepted. The existing incremental body decoder,
connection rules and cache policy are retained.

Six focused host cases cover request bytes, custom headers, redirects,
precise head errors, URL parts and navigation. HTTP checks include both
complete-buffer and streaming entry points. Product builds cover R4HTTP
0.1.4, R4JS 0.54.11, Klickifax 0.29.19, KlickifaxLive 0.2.20 and UpdateService
0.2.19. Recovery 0.1.54 / Menu 0.1.19 uses the same committed HTTP/URL sources
and the updated R4HTTP artifact. These are pure parser checks; no additional
QEMU, network or full browser profile is needed.

References: RFC 9112 sections 3.2, 4 and 5
(https://www.rfc-editor.org/rfc/rfc9112.html), RFC 3986 section 5.2
(https://www.rfc-editor.org/rfc/rfc3986.html), and the WHATWG URL fragment state
(https://url.spec.whatwg.org/#fragment-state).


Global bindings and primitive conversion (0.78.71)
-------------------------------------------------
The realm has one stable global object and a separate declarative lexical
environment. Script var and function declarations use global object
properties; reads and writes through names and globalThis see the same
values. let/const remain lexical. Standard intrinsics are non-enumerable,
writable and configurable, except undefined, NaN and Infinity, which are
immutable. Host defineGlobal keeps its explicit constant flag.

Script this is the stable realm object even after globalThis is reassigned.
Module this is undefined; arrows preserve their defining environment across
Script/module calls. A global identifier call does not implicitly bind an
object receiver. Strict writes to immutable globals fail; sloppy writes
leave their values unchanged. Function declarations are instantiated once
per statement list and can be redeclared in a later Script.

Array and function conversion observes Symbol.toPrimitive, then ordinary
valueOf/toString in hint order. Null and undefined mean an absent exotic
converter. Custom methods and thrown errors are observable. Function source
formatting belongs to Function.prototype.toString, avoiding recursive
conversion through that method. Values and converters remain rooted during
calls. This is a targeted language correction, not full ECMAScript support.


NTFS image boundaries (0.78.73)
-------------------------------
The shared R4OS path policy is 24 components, including a final file name.
The builder checks a child's depth before insertion. ImageCreator counts
the complete destination before creating parent nodes. NtfsVerify applies
the same boundary to both files and directories. The public volume reader
uses that shared constant; its existing runtime limit is unchanged.

The builder's index bitmap now covers all 4096 permitted index blocks.
Block construction checks the same limit before allocation; resident record
capacity remains checked by prepare, before any target is opened for writing.
A 3500-file fixture needs 587 blocks and an 80-byte bitmap, including the
previously out-of-range bit 512. Verification and the final long-name lookup
both succeed.

NtfsVerify collects consecutive nonresident extents, checks physical run
ranges and logical coverage, and requires initialized size <= data size.
Ordinary attributes require data size <= allocated size and complete run
coverage of that allocation, without holes. Sparse/compressed streams and
the special $BadClus:$Bad stream are distinguished; their logical coverage
is checked without applying ordinary physical-allocation equality. Raw
readRunsInto supports sparse zeroes but rejects compressed/encrypted data,
and never reports bytes beyond its actual run array as read successfully.
This does not claim to validate decompressed or decrypted file contents.

Reference: Microsoft ATTRIBUTE_RECORD_HEADER
https://learn.microsoft.com/en-us/windows/win32/devnotes/attribute-record-header
and the existing local NTFS layout references.

R4DRAW ABI12 appends generation-bound connector/mode/EDID queries and atomic
test/commit envelopes. C and Zig facades check optional table tails before
access; DriverApi27 appends an owner-bound output publication interface.
Native hardware commits require a separately negotiated backend; the
firmware fallback retains only its actual boot geometry and unknown refresh.
Zig R4D manifests may declare compiled ZIG_MODULE helpers as R4X already do;
this adds no runtime imports or application entry/class to drivers.
Thin owner launchers can share Tools/BuildModule.ps1 through their configured
SDK_ROOT; it resolves dependency forks and forwards an explicit argument array.

DriverApi28 retains the complete v27/584-byte prefix and appends the optional
`graphicsDisplay()` query at offset 584 (total 592 bytes). The Zig
`driver_display` helper and C `r4os/driver_display.h` negotiate a 40-byte table
for boot geometry, owner-bound prepare/commit/abort/restore, and an IRQ-safe
coalesced notification of the existing graphics worker. A handled transition
can report output-lost with retained ownership; callers must inspect outcome
and the resulting generation. Device access 4 is physical backing residency,
not GPU-VA or data-access permission. Display upload operation 2 belongs only
to the kernel's bound native source queue and never implies visible VBlank.

R4D callers can negotiate DriverApi32 through `DriverContext.threads()`.
`DriverThreadContext` and `r4os/driver_threads.h` expose start, cooperative stop,
finite join, release, status, current handle, tick sleep and owner statistics.
All slots are checked by version, size and availability. Handles, context and
timeout values keep their full 64-bit width. Timeout/cancellation retains the
target; completed callbacks still require successful task/stack release.
The ordinary resource-facade conformance fixture covers both Zig and C.

DriverApi33 is negotiated through `DriverContext.semaphores()`.
`DriverSemaphoreContext` and `r4os/driver_semaphores.h` provide typed create,
acquire, single release, destroy, snapshots and current execution flags.
Zero timeout tries once; UINT64_MAX requires a real permit. Close/stop never
substitutes for successful acquisition. The same resource facade fixture
checks full-width counters/handles/timeouts and optional table boundaries in
Zig and C; callers keep ownership on busy, timeout and failed destruction.

The version-1 DriverThreadApi has optional `abort_current` at offset 72
and `current_request` at offset 80, total 88 bytes. `DriverContext.threads()` continues to accept the
complete old 72-byte prefix. `canAbort()` checks the tail; an abortable start
is rejected before dispatch if it is absent. The C facade follows the same
size/slot checks. Flag 2 opts a dedicated Task into synchronous self-abort;
flag 4 is status-only and cannot be requested at creation.

`abortCurrent(negative_result)` returns only on refusal. An accepted call
bypasses module defers and returns to the kernel's enclosing Task boundary.
The owner must quiesce peers and explicitly recover retained resources.
Calls from Init/Work, non-abortable Tasks, IRQ or kernel critical sections
are not admitted; this does not provide remote termination or an exception
handler. DriverApi remains version 33, 632 bytes; existing service offsets
and module import names are unchanged.

`hasCurrentRequest()` / `currentRequest()` expose the immutable start request
of the actual running dedicated Task. They preserve the original full-width
handler/context and creation flags, never computed status flags. The kernel
resets a valid output before a missing context/owner result; an invalid fixed
32-byte request prefix remains untouched. The caller retains the referenced
context through Task retirement. No allocation, wait, CPU-local binding or
new unwind guard is involved. C uses `r4driver_thread_current_request`.

Thread query returns the largest complete prefix fitting the caller: 72 for
capacities 72..79, 80 for 80..87, and 88 from 88 upward. The sleeping flag 8
is status-only: the real backing Task is blocked in this service's sleep
queue. It does not describe semaphore or arbitrary application waits and
cannot be requested at creation. Original minimum size/version/imports and
DriverApi33/632 remain unchanged for this thread-service extension.

DriverApi34 separately appends `syncDmaRangeForDevice` and `syncDmaRangeForCpu`
through optional slots at 632/640 (total 648 bytes). The context checks the
provider version, size and callback before dispatch; old tables return
`err_no_fn`. Offsets and nonzero lengths are byte ranges of an existing mapping.
The kernel validates its actual retained bounds and preserves other bytes.
Callers still own publication order, per-field exclusion and device quiescence
before unmap. Dedicated threads and IRQ/storage callbacks are not admitted.
The existing resource facade test covers old prefixes, partial/null tails,
full-width arguments and provider errors.


Directory continuation (0.81.26)
-------------------------------
Zig and C storage iterators use the optional R4SYS directory_next tail with
caller-owned continuation and per-entry metadata. Restart is an explicit
failure requiring a fresh complete result generation. Old providers and
intentional live-index deletion retain their previous fallback semantics.
No cursor allocation, retained mount loan or explicit close is required.


Fragmented NTFS directory allocation (0.82.28)
---------------------------------------------
The INDEX_ALLOCATION owner checks AttrScratch.runs.len (256) when growing
an I30 index. MAX_DATA_RUNS (24) belongs to a different file payload buffer.
Record, bitmap, run coverage, reservation, flush and rollback checks remain
unchanged. Kernel Support uses the exact same source; no ABI or buffer grows.
The existing CheckNtfsTreeModel0607 adds 1200 resident files interleaved with
1200 separately allocated payloads:60fragmented index runs, exact contents
and cold remount pass. The original code rejects file498 with24runs despite
free clusters. The whole existing tree/churn/append/crash suite still passes.
On OssiPC, read-only metadata confirmed TEMP had24runs/25full index blocks;
CPU-only new writes failed with FileWrite=-4. Whole-hash-installed Kernel240
now writes36files plus progress/completion successfully, with exact full
readbacks and27actual index runs. Evidence: Temp/Ossi08228/FileIO28C and
Update28A-Installed.json. Host models, SMP4 and hardware are separate proofs.

Abgeschlossener Beleg0.82.28: ExFiles/Reports/OssiGPU/20261003-profile08228/Final08228/Result08228.json; urspruengliche Fehler und neue CPU-/Metadaten-/GPU-Belege getrennt erhalten.

Freestanding Zig modules emit optimized LLVM IR with stack checks enabled.
The existing builder changes only the probe strategy to LLVM inline probes
before machine code generation; this covers large realignment gaps as well
as ordinary and dynamic frames. Other IR/ABI/target attributes stay intact,
and the codegen stage does not rerun LLVM optimization passes. Native C/C++
uses `-Xclang -fstack-clash-protection` with the freestanding target.
Probes allocate or wait nowhere. The kernel retains stack VM/fault ownership;
callers must still prepare resident headroom before a no-sleep owner region.

`r4dev.Context.kernelSchedulerCheck` explicitly selects native synchronization,
roles/fairness/inheritance, real deadlines or IRQ/FPU work through optional
R4DEV v16. Reports prove exact own task generations and work releases;
unavailable hardware and isolated boot injections stay explicit. Missing
capabilities retain the existing error and leave caller output unchanged.

`r4dev.Context.kernelSmpCheck` explicitly runs owned functional CPU/clock,
remote-TLB, mapping and heap/mutex checks through optional R4DEV v17.
`smpTlbSnapshot` only reads current CPU/clock registration and real remote
invalidation counters. Fixed v1 records are224/184bytes. Missing capabilities
leave output unchanged; global timeout injection stays isolated boot-only.

R4DEV v18 adds optional `kernelBlockQueueCheck(out)`: explicit owned synthetic
blockqueue cases and exact task/device/completion receipts. It returns raw
status; missing slots preserve caller output. No physical disk is selected.

R4DEV v19 adds optional `kernelNvmeCheck(out)`: one explicit read-only NVMe
request with matching native ticket, driver CQE/IRQ-worker and DMA-release
receipts. Its fixed296-byte result distinguishes unavailable hardware or
capabilities, failure and retained resources. Passive counters are descriptive;
they cannot prove this request completed. Old storage requests retain their
56-byte layout; only capable backends receive the optional80-byte observed
request with its synchronous104-byte callback record. The callback data must
be copied before return; the resident cookie and buffer survive until actual
completion. Missing slots leave caller output unchanged.

R4DEV v20 adds optional `kernelUsbCheck(out)` for the existing bounded local
USB ring-cycle and event-router cases. Its fixed32-byte report contains case
masks; it needs no USB hardware and performs no live controller/queue work.
The call is reentrant and retains nothing. Missing slots preserve output.

Since Kernel0.1.305 the untyped DriverApi audio/synth registration slots are
reserved: always-1, no argument reads or side effects. The SDK retains
registerSynthEngineEx and the typed AudioBackend helpers. DriverApi36/656,
slot offsets96/120 and current descriptor/Idle/Stop/cleanup contracts stay fixed.

SerialLink retirement (0.84.34 / SDK0.64.35)
-----------------------------------------
The current R4NET and program Contexts no longer expose SerialLink methods.
Frozen ABI types and slots remain at Contract for binary compatibility; the
kernel stubs return err_no_fn without UART or buffer access. COM1 debugging
remains independent. General serial/COM access is a separate platform facility.
# Serial COM API (0.64.35)

`app.serial()` returns the optional typed COM context when the running R4DEV
table supports the complete serial tail (ABI 21). Enumerate with `count` and
`portAt`, then open the exact `port_id` and `generation`, or use `openNumber`.
Port count is dynamic; enumeration indices are not stable COM identities.
`read`, `write`, `drain`, `status`, `configure`, `cancel` and `close` use the
exclusive handle of the exact process instance. C equivalents are in
`r4os/serial.h`; driver backend wrappers are in `r4os/driver_serial.h`.

Use finite system tick budgets. Zero means poll. A read returns available
bytes; a write counts bytes accepted by the provider, and `drain` separately
waits for the physical sender. Always inspect both the return code and
`info.completed`: partial data remains meaningful after timeout or cancellation.
A failed close keeps the same handle and ownership for a later close attempt.
COM1 can remain busy while kernel debugging owns it. Backend registration is
restricted to lifecycle-owned driver initialization or owned Work; cached
notifications and shutdown operations retain their existing owner context.

## Compute workers

Since 0.85.18, an R4X may declare `META=runtime.workers=owned-v1` after
reviewing its worker entry points and reachable libraries/APIs. Zig
`sys.computeWorkerCreate` / `resources.createComputeWorker` and C
`r4sys_compute_worker_create` / `r4_resources_create_compute_worker` forward
the explicit creation flag through the existing generation-safe thread slot.
Older providers refuse that flag; callers may execute preparation serially.

This declaration does not move the foreground main thread. Compute descendants
retain their role even with zero creation flags. They do not produce console
or GUI output, consume stdin, launch a console descendant or claim a prompt.
Their buffers and context must remain valid until a real successful join or
terminal process retirement; a timeout never releases them. The existing
instance-generation, VM, FPU, placement and join/exit contracts still apply.
This is an ownership contract in the trusted single-user system.

CPU performance (0.64.43): `cpuPerformance` negotiates the optional R4DEV26
624-byte tail. It returns a receipt whose state and error must be checked; a
request readback is not achieved frequency. The optional112-byte
`DriverCpuPowerContext` tail retains exact hardware-control tokens until real
return. Existing64/72-byte observation tables remain supported. The provider
requires explicit local release before CPU offline or driver unload; uncertain
state keeps its resources. HWP package activation requires separate reset-only
consent. No governor or implicit policy runs in these facades.

Machine Check observations (0.64.48): `cpuMachineInfo` and `cpuMachineBank`
negotiate the independent optional R4DEV30 tail. They only copy retained
boot-passive or terminal raw evidence. Check origin, validity/fault/truncation
flags and the exact original epoch/sequence before interpreting a bank; no
snapshot is a current-health or generic repair promise. C uses the matching
`r4dev_cpu_machine_info` / `r4dev_cpu_machine_bank` facades. Older tables refuse
without touching output or caller tail.

Early microcode observations (0.64.49): `cpuMicrocodeInfo` negotiates the
optional R4DEV31 slot82 at672bytes, complete table680bytes. Its independent
144-byte record separates actual revision validity, virtual origin, exact
firmware binding, prerequisites, failed load/readback and common post-baseline
capture. A supplied package or virtual revision is not native update success.
This facade only copies resident evidence; no public reload or arbitrary
data/register endpoint exists. The C facade is `r4dev_cpu_microcode_info`.

PMU scopes (0.64.50): `cpuPmuInfo` and `cpuPmuResult` passively copy cached
interface facts and exact original CPU/epoch/generation receipts. Three
optional R4DEV32 slots follow the preserved680-byte prefix; complete704.
Separate128/256-byte records keep raw validity, restoration, IF and scope
independent. `cpuPmuMeasure` explicitly invokes1..4096 iterations of trusted
pure resident work: no allocation, fault, blocking, yield or API/placement
call inside the callback. Warm its code/data/stack first. The facade passes
a local typed callback slot; no optional-by-value wire ABI is introduced.
Native support needs the exact qualified architecture/model; virtual or
unsupported requests return unavailable before hardware/work. Intel overflow
never becomes valid absolute count; AMD legacy exposes modulo-only data.
Inspect result status/flags: return0 means a receipt, not valid measurements.
Failed copies preserve output/tails. No arbitrary event/MSR interface or
change to STANDARD workloads/reference/scoring. C facades use the same
`r4dev_cpu_pmu_info`, `_measure` and `_result` names.

Optional CPU leaves (0.64.51): `cpuAccelerationInfo` copies cached dispatch
hints, and `cpuAccelerationWork` grants one exact CPU/epoch/OS/task/IF window
for resident pure work, with a copied typed callback slot. R4DEV33/720 keeps
the complete old704-byte prefix; old and null providers preserve output.
Legacy `ProtocolApi` keeps its88-byte/version1 prefix and appends independently
size-checked nullable info/work functions at88/96. Inspect every work receipt:
return0 alone never accepts a result. Unlike native PMU, ordinary exposed ISA
may run on a virtual CPU after its real OS-state admission.

`cpu_memory.Policy` selects REP MOVSB only for larger forward copies with a
complete common ERMS hint. Short copies and backward overlap keep the normal
path, DF stays clear, and no cache flush or speculative page read is added.
`crypto_sha256.Sha256(provider)` keeps standard streaming, padding and fallback;
only8..64 full blocks are staged on the caller stack for the guarded SHA-NI
leaf. A rejected, incomplete or over-budget receipt never commits its state.
The provider returns a resident optional work-function pointer and may prefilter
missing SHA from cached info; this hint never replaces the mandatory grant.
No optional instruction is executed for warmup. XCR0=7/common AVX2 baseline
remains sufficient, without an additional XSTATE component. Explicit per-CPU
Spectra observations are separate from STANDARD and do not promise a speedup.

`secure_random` binds optional resident source functions before App workers or
protocol callbacks start. Hardware words use work kind RDRAND, an exact fresh
CPU grant, and at most ten carry-flag attempts per word. A registered driver is
the alternative; its declared maximum bounds every request. Every incomplete
operation clears the entire caller output, including earlier successful chunks.
No clock/ID substitute or entropy pool is introduced. WebCrypto keeps this same
shared implementation. Legacy ProtocolApi prefixes fail safely without reading
absent fields. Newly compiled consumers need the matching kernel facilities;
already compiled applications retain their embedded SDK implementation.

`driver_resources.Context.entropy()` caches the optional registration table
during driver init. Unregister closes admission; it never acknowledges physical
DMA stop. The driver must obtain its real reset and resource-release receipts.
`Build.sh entropy-test` (`Build.bat entropy-test` on Windows) checks bounded CF
failure, whole-output rollback, device limits, and optional-table boundaries.

Unicode dialog buffers (0.85.43): bounded_text.assignZ and TextField.setExact
reject invalid/overlong input without changing the previous value. Use
handleCodepointChecked to retain selected text on a capacity failure.
Byte offsets remain separate from Unicode scalars; FileDialog/InputDialog
accept the actual cursor and selection. DirectoryPage retains exact full
path identities; overlong presentation labels use whole scalars plus ... .
No normalization, glyph coverage, display width or grapheme claim.

0.64.57: Shared text widgets use the external R4STD Unicode17.0.0/UAX29rev47
default extended grapheme boundaries for editing and bounded clipping.
Rendering still measures scalar glyph advances; shaping, BiDi and grapheme
display width are separate capabilities. The SDK build injects a generated byte-exact snapshot of the pinned
Libraries23 text module. R4STD remains the sole implementation owner;
Tools/Sync-R4stdGrapheme.ps1 and SOURCE.json verify its upstream bytes.
This avoids a second Libraries build identity when older consumers use
local forks. Direct low-level build options can supply its
grapheme_source; normal Sdk profiles provide it automatically.
