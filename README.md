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

Typed file and registry paths initialize only their canonical bytes and the
required trailing zero. File normalization keeps its 160 rollback positions
as 16-bit offsets, for a fixed 640-byte temporary instead of two native-word
arrays; all public length, UTF-8, device-name, and normalization semantics are
unchanged in the Zig and C facades.

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
