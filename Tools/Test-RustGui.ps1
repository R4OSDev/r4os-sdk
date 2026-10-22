param(
    [Parameter(Mandatory)][string]$ContractRoot,
    [Parameter(Mandatory)][string]$Zig,
    [Parameter(Mandatory)][string]$RustLauncher,
    [Parameter(Mandatory)][string]$FacadeGenerator,
    [Parameter(Mandatory)][string]$GuiBridgeGenerator,
    [Parameter(Mandatory)][string]$WorkRoot,
    [switch]$Graphics
)
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
$sdk=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$ContractRoot=[IO.Path]::GetFullPath($ContractRoot);$Zig=[IO.Path]::GetFullPath($Zig)
$RustLauncher=[IO.Path]::GetFullPath($RustLauncher);$WorkRoot=[IO.Path]::GetFullPath($WorkRoot)
if(Test-Path -LiteralPath $WorkRoot){throw 'Use a new empty test directory.'}
[IO.Directory]::CreateDirectory($WorkRoot)|Out-Null
$success=$false;$previous=$env:CARGO_ENCODED_RUSTFLAGS
try {
    & $GuiBridgeGenerator check (Join-Path $sdk 'Shared/C/include/r4os/gui_bridge.h') (Join-Path $sdk 'r4os/generated/gui_fingerprint.zig')
    if($LASTEXITCODE -ne 0){throw 'Compiler-typed GUI boundary drift.'}
    & $FacadeGenerator check (Join-Path $sdk 'Rust/src/c_facades.rs')
    if($LASTEXITCODE -ne 0){throw 'C/Rust facade projection drift.'}
    Push-Location $sdk
    try {
        $steps=@(if($Graphics){'graphics-parity-test'}else{'gui-parity-test';'dialog-text-test';'input-events-test'})
        & $Zig build ('--fork='+$ContractRoot) @steps -j1
        if($LASTEXITCODE -ne 0){throw 'Existing GUI pixels/frame/text/input owner cases failed.'}
        & $Zig build ('--fork='+$ContractRoot) -Dfacade-runtime-only=true -Dfacade-host-test=true --prefix (Join-Path $WorkRoot 'native') -j1
        if($LASTEXITCODE -ne 0){throw 'Native shared SDK GUI objects failed.'}
        & $Zig build ('--fork='+$ContractRoot) -Dgui-oracle-only=true --prefix (Join-Path $WorkRoot 'oracle') -j1
        if($LASTEXITCODE -ne 0){throw 'Original GUI oracle object failed.'}
    }finally{Pop-Location}
    $callbacks=Join-Path $WorkRoot 'callbacks.o'
    & $Zig cc -O1 -UNDEBUG -Werror -fPIC -ffunction-sections -fdata-sections -I (Join-Path $sdk 'Shared/C/include') -I (Join-Path $ContractRoot 'Generated/SDK/C/include') -c (Join-Path $sdk 'Tests/Simulation/GuiParity.c') -o $callbacks
    if($LASTEXITCODE -ne 0){throw 'C compatibility and typed native GUI fixture failed.'}
    $source=(Join-Path $sdk $(if($Graphics){'Tests/Simulation/RustGraphics.rs'}else{'Tests/Simulation/RustGui.rs'})).Replace('\','/')
    $dependency=(Join-Path $sdk 'Rust').Replace('\','/')
    $manifest=@"
[package]
name="r4os-sdk-gui-interop"
version="0.1.0"
edition="2024"
[lib]
path="$source"
[dependencies]
r4os-sdk={path="$dependency"}
[workspace]
"@
    [IO.File]::WriteAllText((Join-Path $WorkRoot 'Cargo.toml'),$manifest,[Text.UTF8Encoding]::new($false))
    $flags=@('-D','warnings')
    foreach($object in @((Join-Path $WorkRoot 'native/lib/r4sdk_facades.o'),(Join-Path $WorkRoot 'native/lib/r4sdk_storage.o'),(Join-Path $WorkRoot 'oracle/lib/r4sdk_gui_oracle.o'),$callbacks)){$flags+=@('-C',('link-arg='+$object))}
    $env:CARGO_ENCODED_RUSTFLAGS=$flags -join [char]31
    $patch='patch.crates-io.r4os-contract.path="'+(Join-Path $ContractRoot 'Generated/SDK/Rust').Replace('\','/')+'"'
    $pwsh=(Get-Process -Id $PID).Path
    & $pwsh -NoLogo -NoProfile -File $RustLauncher cargo test --release --offline --manifest-path (Join-Path $WorkRoot 'Cargo.toml') --target-dir (Join-Path $WorkRoot 'target') --config $patch --config 'profile.release.opt-level="z"' --config 'profile.release.overflow-checks=true' --config 'profile.release.lto="fat"' -- --test-threads=1
    if($LASTEXITCODE -ne 0){throw 'Rust/C shared GUI pixel/lifetime interop failed.'}
    $negative=Join-Path $WorkRoot 'negative.rs';$manifest=$manifest.Replace($source,$negative.Replace('\','/'))
    [IO.File]::WriteAllText((Join-Path $WorkRoot 'Cargo.toml'),$manifest,[Text.UTF8Encoding]::new($false))
    $cases=@(
        @('E0133','pub fn bad(){let _=r4os_sdk::gui::raw::R4SdkGuiCanvas_clear(0,core::ptr::null(),0);}'),
        @('E0277','fn send<T:Send>(){} pub fn bad(){send::<r4os_sdk::gui::Session<''static,''static>>();}'),
        @('E0499','pub fn bad(s:&mut r4os_sdk::gui::Session<''_,''_>,c:&mut[r4os_sdk::abi::GuiFrameCommand],r:&mut[u8]){let p=s.begin(c,r).unwrap();let _=s.begin(c,r);drop(p);}')
    )
    if($Graphics){$cases=@(
        @('E0133','pub fn bad(q:&r4os_sdk::graphics::Queues<''_>,h:&r4os_sdk::abi::GfxQueueHandle,s:&r4os_sdk::abi::GfxSubmission){let _=q.submit(h,s);}'),
        @('E0277','fn send<T:Send>(){} pub fn bad(){send::<r4os_sdk::graphics::Graphics<''static,''static>>();}'),
        @('E0277','fn unpin<T:Unpin>(){} pub fn bad(){unpin::<r4os_sdk::graphics::GraphicsStorage>();}'),
        @('E0499','pub fn bad(mut s:core::pin::Pin<&mut r4os_sdk::graphics::GraphicsStorage>,a:&r4os_sdk::App<''_>){let first=r4os_sdk::graphics::Graphics::open(s.as_mut(),a).unwrap();let _second=r4os_sdk::graphics::Graphics::open(s.as_mut(),a);drop(first);}')
    )}
    foreach($case in $cases){
        [IO.File]::WriteAllText($negative,$case[1],[Text.UTF8Encoding]::new($false));$failure=Join-Path $WorkRoot 'negative.log'
        & $pwsh -NoLogo -NoProfile -File $RustLauncher cargo check --offline --manifest-path (Join-Path $WorkRoot 'Cargo.toml') --target-dir (Join-Path $WorkRoot 'target') --config $patch > $failure 2>&1
        if($LASTEXITCODE -eq 0 -or !([IO.File]::ReadAllText($failure).Contains($case[0]))){throw ('Actual negative GUI consumer failed for wrong reason: '+$case[0])}
    }
    $success=$true
    if($Graphics){
        Write-Host 'Rust/C original graphics descriptors, generations, pending/retire/cursor/telemetry and shared GUI regression PASS; unsafe/Send/Unpin/context-loan misuse rejected.'
    }else{
        Write-Host 'Rust/C original GUI pixels, immutable frames, Unicode/input, float-data pointers and exact host sessions PASS; unsafe/Send/frame-loan misuse rejected.'
    }
}finally{
    $env:CARGO_ENCODED_RUSTFLAGS=$previous
    if($success){Remove-Item -LiteralPath $WorkRoot -Recurse -Force}
}
