param(
    [Parameter(Mandatory)][string]$ContractRoot,
    [Parameter(Mandatory)][string]$Zig,
    [Parameter(Mandatory)][string]$RustLauncher,
    [Parameter(Mandatory)][string]$WorkRoot
)
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
$sdk=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$ContractRoot=[IO.Path]::GetFullPath($ContractRoot);$Zig=[IO.Path]::GetFullPath($Zig)
$RustLauncher=[IO.Path]::GetFullPath($RustLauncher);$WorkRoot=[IO.Path]::GetFullPath($WorkRoot)
if(Test-Path -LiteralPath $WorkRoot){throw 'Use a new empty test directory.'}
[IO.Directory]::CreateDirectory($WorkRoot)|Out-Null
$success=$false;$previousFlags=$env:CARGO_ENCODED_RUSTFLAGS
try {
    Push-Location $sdk
    try {
        & $Zig build ('--fork='+$ContractRoot) -Dheap-host-test-only=true --prefix (Join-Path $WorkRoot 'native') -j2
        if($LASTEXITCODE -ne 0){throw 'Native shared heap build failed.'}
    }finally{Pop-Location}
    $source=(Join-Path $sdk 'Tests/Simulation/RustHeap.rs').Replace('\','/')
    $dependency=(Join-Path $sdk 'Rust').Replace('\','/')
    $manifest=@"
[package]
name="r4os-sdk-heap-interop"
version="0.1.0"
edition="2024"
[lib]
path="$source"
[dependencies]
r4os-sdk={path="$dependency",features=["alloc"]}
[workspace]
"@
    # TOML is file data, never interpolated into a shell command.
    [IO.File]::WriteAllText((Join-Path $WorkRoot 'Cargo.toml'),$manifest,[Text.UTF8Encoding]::new($false))
    $object=Join-Path $WorkRoot 'native/lib/r4sdk_heap_host.o'
    $env:CARGO_ENCODED_RUSTFLAGS=('-D'+[char]31+'warnings'+[char]31+'-C'+[char]31+'link-arg='+$object)
    $patch='patch.crates-io.r4os-contract.path="'+(Join-Path $ContractRoot 'Generated/SDK/Rust').Replace('\','/')+'"'
    $pwsh=(Get-Process -Id $PID).Path
    & $pwsh -NoLogo -NoProfile -File $RustLauncher cargo test --offline --manifest-path (Join-Path $WorkRoot 'Cargo.toml') --target-dir (Join-Path $WorkRoot 'target') --config $patch
    if($LASTEXITCODE -ne 0){throw 'Rust/shared heap interop failed.'}
    $success=$true
    Write-Host 'SDK shared heap Rust/C ABI, owner/generation, layout/failure and release ACKs PASS.'
}finally{
    $env:CARGO_ENCODED_RUSTFLAGS=$previousFlags
    if($success){Remove-Item -LiteralPath $WorkRoot -Recurse -Force}
}
