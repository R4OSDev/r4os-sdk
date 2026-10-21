param(
    [Parameter(Mandatory)][string]$TemplateId,
    [Parameter(Mandatory)][string]$Directory,
    [Parameter(Mandatory)][string]$ContractRoot,
    [Parameter(Mandatory)][string]$ToolsRoot,
    [string]$ProjectName='', [string]$SdkRoot='', [switch]$Technical
)
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
if(!$SdkRoot){$SdkRoot=Join-Path $PSScriptRoot '..'}
$SdkRoot=[IO.Path]::GetFullPath($SdkRoot);$ContractRoot=[IO.Path]::GetFullPath($ContractRoot);$ToolsRoot=[IO.Path]::GetFullPath($ToolsRoot);$Directory=[IO.Path]::GetFullPath($Directory)
$templateRoot=Join-Path $SdkRoot 'Templates/R4OS';$selected=$null;$stage=''
function Hash([string]$Path){(Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash.ToLowerInvariant()}
function Relative([string]$Root,[string]$Path){
    $full=[IO.Path]::GetFullPath($Path,$Root)
    if(!$full.StartsWith($Root.TrimEnd([IO.Path]::DirectorySeparatorChar)+[IO.Path]::DirectorySeparatorChar,$(if($IsWindows){[StringComparison]::OrdinalIgnoreCase}else{[StringComparison]::Ordinal}))){throw 'Template file escapes its owner.'}
    return $full
}
function Crate-Version([string]$Path){
    $text=[IO.File]::ReadAllText($Path)
    $package=[regex]::Match($text,'(?ms)^\[package\]\s*(.*?)(?=^\[|\z)').Groups[1].Value
    $version=[regex]::Match($package,'(?m)^version\s*=\s*"(\d+\.\d+\.\d+)"').Groups[1].Value
    if(!$version){throw 'Matched binding crate version missing.'};return $version
}
try{
    if(Test-Path -LiteralPath $Directory){throw 'Project destination already exists.'}
    foreach($entry in Get-ChildItem -LiteralPath $templateRoot -Filter template.ini -Recurse -File){
        $meta=@{};$files=[Collections.Generic.List[string]]::new()
        foreach($line in [IO.File]::ReadLines($entry.FullName)){
            if(!$line.Trim() -or $line.StartsWith('#') -or $line -ceq '[Template]'){continue}
            $separator=$line.IndexOf('=');if($separator -lt 1){throw 'Invalid template metadata.'}
            $key=$line.Substring(0,$separator);$value=$line.Substring($separator+1)
            if($key -ceq 'File'){$files.Add($value)}else{if($meta.ContainsKey($key)){throw 'Duplicate template metadata.'};$meta[$key]=$value}
        }
        if($meta.Id -ceq $TemplateId){if($selected){throw 'Ambiguous template ID.'};$selected=@{root=$entry.DirectoryName;meta=$meta;files=$files.ToArray()}}
    }
    if(!$selected -or !$selected.files.Count){throw 'Rust template/file map not found.'}
    if(!$ProjectName){$ProjectName=$selected.meta.DefaultProjectName}
    if($ProjectName -cnotmatch '^[A-Za-z0-9_-]{1,31}$' -or $ProjectName[0] -notmatch '[A-Za-z]'){throw 'Invalid project name.'}
    $toolManifest=Join-Path $ToolsRoot 'RustToolsProfile.json';$toolProfile=Get-Content -Raw -LiteralPath $toolManifest|ConvertFrom-Json -AsHashtable
    if($toolProfile.schema -ne 1 -or ($toolProfile.technical -and !$Technical)){throw 'Unsupported/technical tool profile.'}
    foreach($owner in @(@($SdkRoot,$toolProfile.sdk.inputs),@($ContractRoot,$toolProfile.contract.inputs))){
        foreach($inputFile in $owner[1]){if((Hash (Relative $owner[0] $inputFile.path)) -cne $inputFile.sha256){throw ('Selected component differs: '+$inputFile.path)}}
    }
    $tokens=@{ProjectName=$ProjectName;CrateName=$ProjectName.ToLowerInvariant().Replace('_','-');SdkCrateVersion=Crate-Version (Join-Path $SdkRoot 'Rust/Cargo.toml');ContractCrateVersion=Crate-Version (Join-Path $ContractRoot 'Generated/SDK/Rust/Cargo.toml');DisplayName=$selected.meta.DisplayName;TemplateId=$TemplateId}
    $stage=$Directory+'.new-'+[guid]::NewGuid().ToString('N');[IO.Directory]::CreateDirectory($stage)|Out-Null
    $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
    foreach($mapping in $selected.files){
        $parts=$mapping.Split('|');if($parts.Count -ne 2 -or !$seen.Add($parts[1])){throw 'Invalid/duplicate template file map.'}
        $source=Relative $templateRoot ([IO.Path]::GetRelativePath($templateRoot,[IO.Path]::GetFullPath($parts[0],$selected.root)))
        if($parts[1].Contains('\') -or $parts[1].Split('/') -contains '..'){throw 'Invalid project file map target.'}
        $target=Relative $stage $parts[1];$text=[IO.File]::ReadAllText($source)
        foreach($key in $tokens.Keys){$text=$text.Replace('{'+$key+'}',$tokens[$key])}
        [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target))|Out-Null
        $bom=[IO.Path]::GetExtension($target) -in @('.txt','.md')
        [IO.File]::WriteAllText($target,$text,[Text.UTF8Encoding]::new($bom))
    }
    $hostName=if($IsWindows){'Windows'}else{'Linux'}
    $catalog=Relative $ToolsRoot $toolProfile.hosts[$hostName].catalog
    if($IsLinux){& chmod 755 $catalog (Join-Path $stage 'Build.sh');if($LASTEXITCODE -ne 0){throw 'Cannot prepare template executables.'}}
    $json=@(& $catalog plan --manifest (Join-Path $stage 'module.R4MF') 2>&1);if($LASTEXITCODE -ne 0){throw ($json -join "`n")};$plan=($json -join "`n")|ConvertFrom-Json -AsHashtable
    if($plan.plan.language -cne 'Rust' -or !$plan.plan.rust_project.host_build_qualified){throw 'Template lacks qualified Rust host build admission.'}
    $pin=[ordered]@{schema=1;template=$TemplateId;sdk=$toolProfile.sdk;contract=$toolProfile.contract;tools_profile_sha256=Hash $toolManifest;technical=[bool]$Technical}
    [IO.File]::WriteAllText((Join-Path $stage 'r4os-project.json'),($pin|ConvertTo-Json -Depth 20)+"`n",[Text.UTF8Encoding]::new($false))
    [IO.Directory]::Move($stage,$Directory);$stage=''
    Write-Host "Rust project created: $Directory ($TemplateId)"
}finally{if($stage -and (Test-Path -LiteralPath $stage)){Remove-Item -LiteralPath $stage -Recurse -Force}}
