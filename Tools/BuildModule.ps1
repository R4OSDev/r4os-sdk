# Shared PS7 owner build used by thin repository launchers on both hosts.
param([Parameter(Mandatory=$true)][string]$ModuleRoot, [string[]]$BuildArguments=@())
$ErrorActionPreference='Stop'
Set-StrictMode -Version Latest
$modulePath=[IO.Path]::GetFullPath($ModuleRoot)
$settings=@{}
foreach($line in Get-Content -LiteralPath (Join-Path $modulePath 'Settings.R4S')){
    if($line -match '^([A-Z_]+)=(.+)$'){$settings[$Matches[1]]=$Matches[2]}
}
function Resolve-ModuleSetting([string]$name,[string]$base){
    if(!$settings.ContainsKey($name)){throw "Missing $name in module Settings.R4S"}
    return [IO.Path]::GetFullPath($settings[$name].Replace('\',[IO.Path]::DirectorySeparatorChar),$base)
}
$sdkPath=Resolve-ModuleSetting SDK_ROOT $modulePath
$contractPath=Resolve-ModuleSetting CONTRACT_ROOT $modulePath
$devkitPath=Resolve-ModuleSetting DEVKIT_ROOT $modulePath
$artifactPath=Resolve-ModuleSetting ARTIFACTS_ROOT $modulePath
$zigPath=Join-Path (Resolve-ModuleSetting ZIG_ROOT $devkitPath) $(if($IsWindows){'zig.exe'}else{'zig'})
$forkPaths=@($sdkPath,$contractPath)
$manifestPath=Join-Path $modulePath 'build.zig.zon'
if($settings.ContainsKey('LIBRARIES_ROOT')){
    $forkPaths+=,(Resolve-ModuleSetting LIBRARIES_ROOT $modulePath)
} elseif([IO.File]::ReadAllText($manifestPath) -match '\.r4os_libraries\s*='){
    # Older local settings predate a module's new library dependency. The
    # canonical sibling follows the configured SDK path, never the host cwd.
    $forkPaths+=,[IO.Path]::GetFullPath((Join-Path $sdkPath '../Libraries'))
}
foreach($path in $forkPaths){if(!(Test-Path -LiteralPath (Join-Path $path 'build.zig.zon') -PathType Leaf)){throw "Repository not found: $path"}}
if(!(Test-Path -LiteralPath $zigPath -PathType Leaf)){throw "Zig not found: $zigPath"}
[IO.Directory]::CreateDirectory($artifactPath)|Out-Null
$forward=@($BuildArguments)
$forks=@($forkPaths|ForEach-Object {'--fork='+$_})
Push-Location $modulePath
try {
    & $zigPath build --prefix $artifactPath @forks @forward
    $buildCode=$LASTEXITCODE
} finally {Pop-Location}
exit $buildCode
