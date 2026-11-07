param([string]$SdkRoot='', [switch]$Check)
$ErrorActionPreference='Stop'
Set-StrictMode -Version Latest
if(!$SdkRoot){$SdkRoot=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))}
$source=Join-Path $SdkRoot 'Profiles/Build.json'
$text=[IO.File]::ReadAllText($source).Replace("`r`n","`n")
$data=$text|ConvertFrom-Json -AsHashtable -Depth 100
if($data.schema -ne 1){throw 'SdkProfileSchemaMismatch: Build'}
$hash=[Convert]::ToHexString([Security.Cryptography.SHA256]::HashData([Text.Encoding]::UTF8.GetBytes($text))).ToLowerInvariant()
$lines=[Collections.Generic.List[string]]::new()
$lines.Add('// Generated from Profiles/Build.json by Tools/Sync-ProfilePolicy.ps1. DO NOT EDIT.')
$lines.Add('pub const source_sha256 = "'+$hash+'";')
$lines.Add('pub const Profile = struct { id: []const u8, language: []const u8, role: []const u8, generation: u8, explicit_platform: bool };')
$lines.Add('pub const profiles = [_]Profile{')
$ids=[string[]]@($data.profiles.Keys)
[Array]::Sort($ids,[StringComparer]::Ordinal)
foreach($id in $ids){
    $profile=$data.profiles[$id]
    $explicit=$profile.ContainsKey('platform')
    $platform=if($explicit){$profile.platform}else{'platform1'}
    foreach($value in @($id,$profile.language,$profile.role)){
        if($value -cnotmatch '^[A-Za-z0-9_+.-]+$'){throw 'SdkProfileProjectionStringInvalid'}
    }
    $generation=$data.platforms[$platform].generation
    if($generation -notin @(1,2)){throw 'SdkProfileProjectionGenerationInvalid'}
    $lines.Add('    .{ .id = "'+$id+'", .language = "'+$profile.language+'", .role = "'+$profile.role+'", .generation = '+$generation+', .explicit_platform = '+$explicit.ToString().ToLowerInvariant()+' },')
}
$lines.Add('};')
$generated=($lines -join "`n")+"`n"
$path=Join-Path $SdkRoot 'r4os/generated/profile_policy.zig'
if($Check){
    if(!(Test-Path -LiteralPath $path) -or [IO.File]::ReadAllText($path).Replace("`r`n","`n") -cne $generated){throw 'SdkProfilePolicyProjectionDrift'}
    Write-Output 'SDK profile policy projection verified.'
}else{
    [IO.Directory]::CreateDirectory((Split-Path $path -Parent))|Out-Null
    [IO.File]::WriteAllText($path,$generated,[Text.UTF8Encoding]::new($false))
}
