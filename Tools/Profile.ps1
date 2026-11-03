param(
    [ValidateSet('Validate', 'Describe')][string]$Action = 'Validate',
    [string]$SdkRoot = '',
    [string]$Profile = 'r4os-zig-module-v1'
)
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
if (!$SdkRoot) { $SdkRoot = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..')) }
. (Join-Path $PSScriptRoot 'ProfileData.ps1')
if ($Action -ceq 'Describe') {
    Get-R4SdkBuildProfile $SdkRoot $Profile | ConvertTo-Json -Depth 100
} else {
    $data = Read-R4SdkProfiles $SdkRoot
    [ordered]@{schema=1; valid=$true; sdk_version=$data.sdk_version; hashes=$data.hashes;
        profiles=@($data.Build.profiles.Keys); system_libraries=@($data.Components.libraries.Keys)} | ConvertTo-Json -Depth 10
}
