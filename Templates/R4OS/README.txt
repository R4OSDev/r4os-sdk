R4OS SDK Templates
==================

These are installable project templates for R4CODE and R4BUILD under
C:/R4OS/SDK/Templates. Templates belong to the SDK, not to an application's
private directory.

The native C templates are:

  R4X C Terminal Hello  -> R4X_C_Console
  R4X C Desktop OK      -> R4X_C_Desktop_OK

R4CODE creates module.R4MF and source files from these templates. R4BUILD
validates, plans, and builds that manifest through R4PACK and R4CC.

The C console and desktop template directories own their module.R4MF and
source templates. Host-created projects use the same R4MF v2 contract and
thin build.zig/build.zig.zon entry points that delegate to the SDK. Zig
console templates are host-only because the native R4CC path implements the
current C subset.

Do not create a second template source of truth. template.ini describes only
catalog entries and filenames; language, module kind, application class,
imports, and targets remain in module.R4MF.template.

Rust host templates (SDK0.64.61)
-------------------------------
R4OS.R4X_Rust_Console, R4OS.R4X_Rust_Desktop and R4OS.R4X_Rust_Service use the
same template.ini convention. Repeated File=source|destination entries own
the complete file map; shared Cargo/lock/build/readme sources live in
RustShared. Language/class/target/import/resource facts remain solely in each
module.R4MF.template. These are SDK sources, not extra productive modules.

Create an independent project with the matched standalone components:

  ./Tools/New-RustProject.sh -TemplateId R4OS.R4X_Rust_Console -Directory /project -ProjectName HELLO -ContractRoot /CONTRACT -ToolsRoot /TOOLS

The script derives SDK from its own location, accepts -SdkRoot explicitly,
and needs no compiler to create/validate the project. It refuses an existing
destination. Build.sh/Build.bat call one Build.ps1 and the SDK driver with
explicit SDK/Contract/tool directories. The caller owns version selection and
any project lock. Technical component/profile checks remain in the driver;
component mismatches, missing tools or compiler errors invalidate previous
owned success outputs. No project pin file is created or consumed.

Migration from SDK0.64.61-.65: remove -ProjectPin and its value from an existing
project's Build.ps1, or invoke the SDK driver directly with component roots.
Any existing project metadata remains under its external owner's control;
the SDK does not read, migrate or delete it. Cargo.lock remains required for
the actual Rust dependencies.

All three templates were really compiled from individually staged SDK,
Contract and tools in /tmp, outside the complete checkout. Console output,
hosted window and bounded service registration/wait/stop are actual Rust code.
The common startup/panic evidence is reused. SDK0.64.64 binds final independent
package builds, path reproducibility and visible GUI/service/console runtime
qualification in that release's metadata. SDK0.64.66 publishes the general
component/package/evidence manifest as SDK-Release.json. Launch GUI through the regular
desktop host, for example its Run dialog; an SSH console is not a visible GUI
host. The service answers STATUS/op1 and rejects unknown requests in bounded
batches. Stop also accepts an endpoint already retired by its owner.
Windows remains prepared, not run.

Capability interface1
---------------------
module-catalog capabilities --json reads these same definitions and the host
Zig/C/R4L template.ini file maps. Execution selects host versus native R4OS;
language/class/imports/targets still come from the manifest. Host C reuses this
canonical console source instead of an absent second file. Host build.zig.zon
accepts exact SDK URL/hash inputs; no fixed neighboring SDK path. The R4L file
map includes its real local contract/generator preparation. See
Tools/ModuleCatalog/Capabilities.txt for sample expansion, tokens and limits.
