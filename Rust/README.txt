R4OS normal Rust R4X development
================================

SDK package0.64.70 supplies r4os-rust-r4x-v2. The Rust helper crate is
r4os-sdk0.1.0; r4os-contract0.1.0 remains a separate generated ABI crate.
Neither crate version is the SDK/Contract package or installed module version.
The platform contract and project rules live in Contract/Module/RustModuleV2.txt.

Profile and tools
-----------------
Use the matched SDK, Contract and r4os-rust-tools-v1 export. Rust/Cargo1.99.0,
rustup1.29.1, LLVM tools and x86_64-unknown-none are pinned by the shared DevKit
installer. No global Rust, complete workspace, Zig install, MSVC linker or
Rust sources are needed for pure Rust builds with the exported baretarget tools.
Explicit C companions additionally require the selected pinned Zig/Clang root.
The publisher builds both host packagers/catalogs with Zig. Windows uses the
same PS7 driver and prepared PE tools; Windows execution is not yet qualified.

Example with separately selected components (quote paths containing spaces):

  ./TOOLS/Setup/Rust.sh --root /install --cache-root /cache setup
  ./SDK/Tools/Build-RustModule.sh -ProjectRoot /project -ContractRoot /CONTRACT -ToolsRoot /TOOLS -InstallRoot /install -CacheRoot /cache

On Windows use Setup\Rust.bat and SDK\Tools\Build-RustModule.bat with identical
PS7 parameters. -SdkRoot can explicitly select another SDK directory; otherwise
it resolves from the driver. No Settings.R4S, sibling workspace or DevKit lookup.
The exporter binds source inputs, host binaries and package identities/hashes.
Describe/check output is JSON. A technical/dirty profile needs -Technical and
does not qualify a release. Install/runtime presence and semantic support are
different facts; the matched ModuleCatalog supplies build admission.

Official projects
-----------------
SDK0.64.61 adds complete Console, Desktop and Service projects under
Templates/R4OS/R4X_Rust_*. New-RustProject.sh/.bat uses their actual template.ini
file maps and module manifests. Select the exact stable TemplateId, a new
Directory and explicit ContractRoot/ToolsRoot; ProjectName is optional.
Shared Build.ps1 passes the explicitly selected component directories to the
SDK driver. Component version selection and project locks belong to the caller;
the SDK neither creates nor reads such a file. The driver still checks matched
SDK/Contract source hashes and the required toolchain inside its owned output
lifecycle, so a technical component mismatch invalidates previous success.
See Templates/R4OS/README.txt for commands and current qualification.

Project and outputs
-------------------
module.R4MF is the module truth: LANGUAGE=Rust, one canonical .rs SOURCE root,
ENTRY_MODE=app, APP_CLASS=console/gui/service, target/version/imports/resources.
Cargo owns its different crate name/version, edition2024 and one explicit
[lib] path=SOURCE, crate-type=["staticlib"]. Include Cargo.lock. Cargo parses
its own TOML and supplies resolved package identities/features. Additional
local/path or vendored crates are supported, including aliases and optional
dependencies; matched r4os-sdk/r4os-contract0.1.0 retain exact component paths.
Builds run offline/locked, with a private Cargo home and no registry/git fetch.
For crates outside project/SDK/Contract, pass an explicit -DependencyRoot.
Multiple roots can be passed as -DependencyRootsJson '["/first","/second"]'
from command-line launchers; PS callers may supply a DependencyRoot array.
Root -Features 'one,two' and -NoDefaultFeatures select Cargo features. This
is build selection, not SDK-owned component version/project-pin management.

Additional ordered SOURCE lines may declare C companions; C_INCLUDE,
C_DEFINE and C_FLAG use the existing manifest fields. Select -ZigRoot explicitly
for these sources. The matched Profile/ZigToolchain.json pin, freestanding
CPU/PIC/stack-probe options and actual compiler source/header dependencies are
recorded. C objects link into the same R4M0 artifact; no Cargo build.rs or new
runtime module. Native C compiler flags precede required SDK codegen options.

Use #![no_std], a function fn main(app: &mut r4os_sdk::App<'_>) -> i32 and
r4os_sdk::app!(main). The macro's R4XStart derives class/import order/name from
generated startup-info.rs input from the common ModuleCatalog manifest parser.
There is no Rust-specific import grammar or hard-coded import capacity.
It validates the exact ordered declarations, including absent optional named
providers, required groups, pointer alignment and the current Contract table
defaults (version and complete size). An unresolved optional import remains a
record with table/resolved_version/flags zero. Query revision1 is distinct from
the actual platform table version. No app-window operation runs at admission.
All six checked immutable API views, start_context and named import lookup are
instance-bound; App is neither Send nor Sync. A raw constructor caller must
pin the full context/imports/tables until that entry ends. Thread callbacks
keep the kernel's existing exact instance ownership; they must not reuse a
finished root App. Local R4L resolvers still validate their own table headers.
Callback signatures come from the generated Contract. No copied layouts or new R4L runtime. Direct float/vector C ABI remains
outside this profile. Rust module/include inputs come from rustc
dep-info; the receipt distinguishes those from declared manifest/Cargo/resources.
The generated startup input has owner=generated in compiler_inputs and its
exact hash in the same receipt. Input directory/file symlinks are outside the
current project tree.

Default output is project/build; -OutputRoot selects another owned directory.
Its marker binds it to exactly one project and an exclusive build lock. Invalid
sources, compile/link errors or missing tools remove previous successful R4X,
ELF, generated startup-info.rs and build.json outputs. An output directory containing unrelated files is
rejected. build.json schema2 records exact source/tool/profile/ELF/R4M0 hashes,
selected/resolved Cargo graph/features, every manifest, Rust/C/include inputs,
imports, module version and resources. Cargo's
reusable target cache lives below the explicitly selected cache root. Temporary
build homes/work files are removed. Technical failures may retain one clearly
named failed-link.elf while diagnosing a link profile; it is no success output.

Project/ancestor Cargo config, build.rs, proc macros, rust-toolchain overrides
and compiler/target/profile environment flags are rejected. Project release
settings are explicitly replaced by the SDK's profile; actual Cargo artifact
profiles must match optimization/check/assertion/test settings. The child
process gets private Cargo state
and exact tools; the calling shell is not changed. Empty [workspace] avoids
implicit parent selection. ModuleCatalog validation runs before Cargo metadata,
which independently confirms the one real package and target.

CPU, relocation and runtime
---------------------------
r4os/rust_module_profile.json owns the module codegen choice. CPU baseline and
required ISA flags come from the selected Contract/Module/CpuBaseline.json;
no target-cpu=native. The pinned precompiled core requires code-model=kernel.
For modules it is combined with PIE and whole-crate fat LTO, not the kernel's
static relocation profile. LTO closes precompiled core calls; the five minimal
memory builtins close compiler libc calls in the same module. Volatile byte
bodies prevent recursive libc lowering. Unknown runtime relocations remain
hard errors in the unchanged R4M0 packager. Only ABS64, PC32/PLT32 are admitted.

The existing linker script starts text at0 and keeps the R4X entry first.
No redzone; pinned target inline stack probes touch each4096-byte step.
OPTIMIZE=size -> opt-level=z, speed ->3; overflow checks remain on. No unwind
crosses C ABI. Normal main returns its actual i32 code. Panic reports failure
and uses the size-checked process-exit callback with code-101/reason failed.
A missing/rejected terminal callback becomes a real module fault (UD2), never
a success, HLT or spinning process. Kernel-owned stack/SIMD/exit resources keep
their existing lifecycle. No loader, platform ABI or normal kernel change.

Helpers
-------
App provides console write, arguments, bounded sleep and close state. GUI uses
the regular host-created R4DESK window and R4DRAW clear/text/present operations;
no private framebuffer. Poll/wait checks optional table slots; idle waits leave
the scheduler ready list. Service registers its exact named endpoint, waits
with bounded timeout, receives/replies optionally, and unregisters before the
handle is cleared. The normal process owner remains responsible for final exit.
The service owner can retire that exact endpoint while requesting Stop;
close treats its bad_handle acknowledgement as already retired and clears
the private handle. Other failures remain errors. The official service
template drains bounded request batches, answers STATUS/op1 and rejects
unknown operations; merely waiting on an unread request would stay ready.

Qualification is recorded separately as build, ELF/container and actual guest
results in Docs/API/RustContractBindings.txt. Host memory bounds/overlap cases
and source/error/tool cases are reusable SDK tests; no broad image/hardware
matrix or extra normal STANDARD follows from host/fixture-only work.

Pooled allocation (SDK0.64.69)
------------------------------
Select r4os-sdk = { version = "=0.1.0", features = ["alloc"] } in Cargo.toml.
Use extern crate alloc and alloc::boxed::Box, alloc::vec::Vec or
alloc::string::String normally. app! installs the instance allocator before
main. The pinned rust-std target already contains liballoc; no new compiler,
unstable allocator handler or Rust sources are needed. Allocation failure in
infallible collections follows the existing terminal panic path; fallible
collection APIs retain their ordinary failure semantics.

app.heap() supplies an explicit borrowed Heap. allocate(size,alignment) returns
an owned Buffer with initialized bytes and fallible resize; new bytes on growth
are zeroed before safe slice access. Its drop returns ownership to
the common allocator. Zero-length buffers require no VM region. Invalid
alignment/overflow fail before VM work, and failed growth preserves the old
buffer. Heap and Buffer do not grant Send/Sync to App; normal global allocations
can be used by threads of the same exact kernel instance/generation.

The same r4os/vm_allocator.zig pool is compiled by the SDK publisher into
Runtime/r4sdk_heap.o. The tools export and build receipt bind its hash and CPU
profile to the matched SDK/Contract. Rust consumers link this machine object
with the pinned linker, without running Zig. C's heap.h and normal C builder
use the same core. This is an R4X-image heap, not a shared R4L-global allocator;
library-owned caller heaps remain a separate role contract.

stats() captures every metric of that core under one lock. Metric names come
from the owner; active_bytes includes the small C/Rust allocation prefix.
Logical free may retain cached or pending VM regions. Unsafe finish_instance
irreversibly closes allocation admission; first join allocator users and drop
their buffers. Runtime(1) means busy/live and Runtime(2) means a physical release
is pending; exact identities stay retryable even after partial unmapping.
Success requires every region/notification release ACK. Root return never
automatically destroys an allocator still usable by workers: the kernel retains
the image/VM owner until actual task retirement. Let the kernel perform normal
instance cleanup, or explicitly finish only after quiescence.

Ordinary thread APIs accept reserve=0 for the kernel's memory-profile default.
The allocation fixture uses that default and the existing owned-v1 compute
worker contract. A hand-picked 64KB reserve was insufficient for its VM call
chain; a small reserve is not a guarantee that arbitrary kernel calls fit.

The ELF/R4M0 packager closes only proven local unrelaxed GOTPCREL slots: the
final linked slot must contain the exact module-owned symbol, with the supported
-4 addend. It emits ordinary relative patches and full-width slot definitions.
Every nonzero GOT slot must close; GOTPCRELX/ABS32 remain rejected. Module ABI,
loader and kernel are unchanged. Evidence: Docs/SDK/LanguageParity.txt.

Other module roles (0.86.38)
---------------------------
Library consumers (SDK0.64.71)
------------------------------
Each current library publishes a generated Bindings/Rust/src/lib.rs and a
local Cargo package such as r4os-r4std0.1.0. Its crate version belongs to Cargo;
the provider module version and interface revision remain distinct facts.
Select the path dependency and explicitly admit its Libraries root in the
module builder. No provider rewrite or global Zig installation is required.

For example, r4os_r4std::TextV1Client::init(app) validates the declared import,
ID/major/revision/size/flags and every required slot. The client borrows App
and cannot cross that loan or move to another thread. Its unsafe operation
methods preserve raw status values and the library's ownership/lifetime/
blocking/threading/reentrancy rules, documented from the same local contract.
::optional(app) explicitly permits absence; incompatible loaded tables fail.
The SDK r4l::query helper reads standalone Query metadata, separate from a
named table or platform API. Rust raw records/tables assert all local sizes,
alignments and field/slot offsets during compilation. Higher library helper
facades remain their own parity waves; these are complete contract consumers.

The shared SDK module_capabilities.zig Decision supplies supported/code/reason,
owner_contract and missing_steps. Installation of a compiler does not change
these support decisions. Further Rust roles are deliberately separate work:

R4L provider: current R4MF requires library-owned contract/baseline,
implementation/bindings/conformance and regular Query/table exports. The
generator supplies Zig/C/Rust consumers; a Rust provider still needs its real
implementation entry, export/build and lifecycle qualification. Fake Zig
SOURCE or unused IMPLEMENTATION_ZIG entries are forbidden.

R4D: the current driver builder owns r4d_init_entry, DriverInit/DriverShutdown,
R4DEV callbacks and metadata. Rust needs an actual driver startup/packager and
per-device IRQ/DMA/resource cleanup proof. R4XStart/app class is unrelated.

R4P: the protocol builder owns separate init/register/export stubs, role/category/
dependency metadata and teardown. Raw Rust callback layouts alone do not provide
that builder or qualified registration/hot removal/shutdown ownership.

Subsystem: a normal GUI R4X with MODULE_ROLE=subsystem additionally owns ID,
display name, guest formats/target/catalog and resolver/host/video/input/audio/
persistence/cleanup contracts. Existing subsystem_launch/host/runtime helpers
are Zig; the Rust window helper is not an equivalent subsystem host facade.

Rust lowlevel needs separate raw-entry stack/ABI/panic qualification. Native
R4OS Rust builds need a compiler/toolchain port; R4CC implements the native C
subset and is not a Rust compiler. Stable machine reason codes live in the
shared Decision, not in an IDE-maintained matrix. No new driver/protocol/library/
subsystem implementation or hardware claim is included in this SDK delivery.
