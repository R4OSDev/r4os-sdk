R4OS normal Rust R4X development
================================

SDK package0.64.60 introduces r4os-rust-r4x-v1. The Rust helper crate is
r4os-sdk0.1.0; r4os-contract0.1.0 remains a separate generated ABI crate.
Neither crate version is the SDK/Contract package or installed module version.
The platform contract and project rules live in Contract/Module/RustModuleV1.txt.

Profile and tools
-----------------
Use the matched SDK, Contract and r4os-rust-tools-v1 export. Rust/Cargo1.99.0,
rustup1.29.1, LLVM tools and x86_64-unknown-none are pinned by the shared DevKit
installer. No global Rust, complete workspace, Zig install, MSVC linker or
Rust sources are needed to consume the exported baretarget build tools.
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
module.R4MF is the module truth: LANGUAGE=Rust, one canonical .rs SOURCE,
ENTRY_MODE=app, APP_CLASS=console/gui/service, target/version/imports/resources.
Cargo owns its different crate name/version, edition2024 and one explicit
[lib] path=SOURCE, crate-type=["staticlib"]. Include Cargo.lock. The bounded
single-line TOML grammar is documented by the Contract. The initial dependencies
are matched r4os-sdk/r4os-contract0.1.0 only; exact path patches come from the
selected components. Builds run offline/locked, without a registry fetch.

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
Callback signatures come from the generated Contract. No copied layouts or new R4L runtime. Direct float/vector C ABI and
alloc are outside this profile. Rust module/include inputs come from rustc
dep-info; the receipt distinguishes those from declared manifest/Cargo/resources.
The generated startup input has owner=generated in compiler_inputs and its
exact hash in the same receipt. Input directory/file symlinks are outside the
v1 project tree.

Default output is project/build; -OutputRoot selects another owned directory.
Its marker binds it to exactly one project and an exclusive build lock. Invalid
sources, compile/link errors or missing tools remove previous successful R4X,
ELF, generated startup-info.rs and build.json outputs. An output directory containing unrelated files is
rejected. build.json schema1 records exact source/tool/profile/ELF/R4M0 hashes,
selected Cargo package/target, imports, version and resource inputs. Cargo's
reusable target cache lives below the explicitly selected cache root. Temporary
build homes/work files are removed. Technical failures may retain one clearly
named failed-link.elf while diagnosing a link profile; it is no success output.

Project/ancestor Cargo config, build.rs, proc macros, other dependency kinds,
features, profiles, rust-toolchain overrides and compiler/target/profile flags
from the environment are rejected. The child process gets private Cargo state
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

Other module roles (0.86.38)
---------------------------
The shared SDK module_capabilities.zig Decision supplies supported/code/reason,
owner_contract and missing_steps. Installation of a compiler does not change
these support decisions. Further Rust roles are deliberately separate work:

R4L: current R4MF requires library-owned contract/baseline, IMPLEMENTATION_ZIG,
Zig/C bindings/conformance and regular Query/table export generation. The R4L
contract generator emits Zig/C only. Rust needs its real implementation and
local contract/generator/build/consumer qualification; fake Zig SOURCE or
unused IMPLEMENTATION_ZIG entries are forbidden.

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
