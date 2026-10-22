param(
    [Parameter(Mandatory)][string]$ProjectRoot,
    [Parameter(Mandatory)][string]$ContractRoot,
    [Parameter(Mandatory)][string]$ToolsRoot,
    [string]$SdkRoot='', [string]$InstallRoot='', [string]$CacheRoot='',
    [string]$OutputRoot='', [switch]$Technical
)
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
$SdkRoot=if($SdkRoot){[IO.Path]::GetFullPath($SdkRoot)}else{[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))}
$ProjectRoot=[IO.Path]::GetFullPath($ProjectRoot);$ContractRoot=[IO.Path]::GetFullPath($ContractRoot);$ToolsRoot=[IO.Path]::GetFullPath($ToolsRoot)
if(!$InstallRoot){$InstallRoot=$ToolsRoot};$InstallRoot=[IO.Path]::GetFullPath($InstallRoot)
if(!$CacheRoot){$CacheRoot=Join-Path $InstallRoot '.Cache/Rust'};$CacheRoot=[IO.Path]::GetFullPath($CacheRoot)
if(!$OutputRoot){$OutputRoot=Join-Path $ProjectRoot 'build'};$OutputRoot=[IO.Path]::GetFullPath($OutputRoot)
$utf8=[Text.UTF8Encoding]::new($false);$phase='output';$guard=$null;$work='';$artifact='';$elf='';$receipt='';$startupFile='';$success=$false
function Hash([string]$Path){(Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash.ToLowerInvariant()}
function Write-Json([string]$Path,$Value){[IO.File]::WriteAllText($Path,($Value|ConvertTo-Json -Depth 40)+"`n",$utf8)}
function Below([string]$Path,[string]$Root){
    $comparison=if($IsWindows){[StringComparison]::OrdinalIgnoreCase}else{[StringComparison]::Ordinal}
    return $Path.StartsWith($Root.TrimEnd([IO.Path]::DirectorySeparatorChar)+[IO.Path]::DirectorySeparatorChar,$comparison)
}
function SamePath([string]$Left,[string]$Right){
    $comparison=if($IsWindows){[StringComparison]::OrdinalIgnoreCase}else{[StringComparison]::Ordinal}
    return [IO.Path]::TrimEndingDirectorySeparator([IO.Path]::GetFullPath($Left)).Equals([IO.Path]::TrimEndingDirectorySeparator([IO.Path]::GetFullPath($Right)),$comparison)
}
function Canonical([string]$Root,[string]$Relative){
    if([IO.Path]::IsPathRooted($Relative) -or $Relative.Contains('\') -or $Relative.Split('/') -contains '..'){throw 'Noncanonical input path.'}
    $path=[IO.Path]::GetFullPath($Relative,$Root)
    if(!(Below $path $Root)){throw 'Input escapes selected root.'}
    return $path
}
function Assert-NoCargoConfig([string]$Directory){
    $cursor=[IO.DirectoryInfo]::new($Directory)
    while($null -ne $cursor){
        foreach($relative in @('.cargo/config','.cargo/config.toml')){if(Test-Path -LiteralPath (Join-Path $cursor.FullName $relative)){throw 'RustCargoAncestorConfigForbidden'}}
        $cursor=$cursor.Parent
    }
}
function Invoke-Tool([string]$Program,[string[]]$Arguments,[string]$WorkingDirectory,[hashtable]$Environment=@{},[string]$Log='',[switch]$Diagnostics){
    $info=[Diagnostics.ProcessStartInfo]::new();$info.FileName=$Program;$info.WorkingDirectory=$WorkingDirectory
    $info.UseShellExecute=$false;$info.RedirectStandardOutput=$true;$info.RedirectStandardError=$true
    foreach($arg in $Arguments){$info.ArgumentList.Add($arg)}
    foreach($key in $Environment.Keys){if($null -eq $Environment[$key]){$info.Environment.Remove($key)|Out-Null}else{$info.Environment[$key]=[string]$Environment[$key]}}
    $process=[Diagnostics.Process]::new();$process.StartInfo=$info
    try{
        if(!$process.Start()){throw 'Cannot start tool.'}
        $stdout=$process.StandardOutput.ReadToEndAsync();$stderr=$process.StandardError.ReadToEndAsync();$process.WaitForExit()
        $out=$stdout.GetAwaiter().GetResult();$err=$stderr.GetAwaiter().GetResult();$code=$process.ExitCode
        if($Log){[IO.File]::WriteAllText($Log+'.stdout',$out,$utf8);[IO.File]::WriteAllText($Log+'.stderr',$err,$utf8)}
        if($code -ne 0){throw "Tool failed ($code): $([IO.Path]::GetFileName($Program))`n$err`n$out"}
        if($Diagnostics){return $out+$err};return $out
    }finally{$process.Dispose()}
}
function Check-Inputs([string]$Root,$Inputs){
    foreach($inputFile in $Inputs){$path=Canonical $Root $inputFile.path;if(!(Test-Path -LiteralPath $path -PathType Leaf) -or (Hash $path) -cne $inputFile.sha256){throw ('Matched source input differs: '+$inputFile.path)}}
}
function Input([string]$Path,[string]$Root,[string]$Label){
    # The v1 input tree has no implicit directory/file symlink dependencies.
    $cursor=$Root
    foreach($part in ([IO.Path]::GetRelativePath($Root,$Path).Split([IO.Path]::DirectorySeparatorChar))){
        $cursor=Join-Path $cursor $part
        if((Get-Item -LiteralPath $cursor -Force).LinkType){throw 'RustSourceLinkUnsupported'}
    }
    $item=Get-Item -LiteralPath $Path -Force
    return [ordered]@{owner=$Label;path=[IO.Path]::GetRelativePath($Root,$Path).Replace('\','/');sha256=Hash $Path;bytes=$item.Length}
}
try{
    if($OutputRoot -eq $ProjectRoot -or (Below $ProjectRoot $OutputRoot)){throw 'Output must not contain the project root.'}
    [IO.Directory]::CreateDirectory($OutputRoot)|Out-Null
    $guard=[IO.File]::Open((Join-Path $OutputRoot '.build-lock'),[IO.FileMode]::OpenOrCreate,[IO.FileAccess]::ReadWrite,[IO.FileShare]::None)
    $ownerFile=Join-Path $OutputRoot '.r4os-rust-build.json'
    if(Test-Path -LiteralPath $ownerFile){
        $previous=Get-Content -Raw -LiteralPath $ownerFile|ConvertFrom-Json -AsHashtable
        if($previous.schema -ne 1 -or !(SamePath $previous.project $ProjectRoot)){throw 'Output belongs to another project.'}
        foreach($field in @('artifact','elf')){
            if($previous.ContainsKey($field) -and $previous[$field]){
                if($previous[$field] -cnotmatch '^[A-Za-z0-9_-]{1,31}\.(R4X|elf)$'){throw 'Invalid previous output identity.'}
                $path=Join-Path $OutputRoot $previous[$field];if(Test-Path -LiteralPath $path){[IO.File]::Delete($path)}
            }
        }
    }else{
        if(@(Get-ChildItem -LiteralPath $OutputRoot -Force|Where-Object Name -cne '.build-lock').Count){throw 'New Rust output directory must be empty.'}
    }
    Write-Json $ownerFile @{schema=1;project=$ProjectRoot;status='building'}
    $startupFile=Join-Path $OutputRoot 'startup-info.rs'
    if(Test-Path -LiteralPath $startupFile){[IO.File]::Delete($startupFile)}
    $receipt=Join-Path $OutputRoot 'build.json';if(Test-Path -LiteralPath $receipt){[IO.File]::Delete($receipt)}
    $phase='profile'
    $rustToolProfilePath=Join-Path $ToolsRoot 'RustToolsProfile.json'
    $rustToolProfile=Get-Content -Raw -LiteralPath $rustToolProfilePath|ConvertFrom-Json -AsHashtable
    if($rustToolProfile.schema -ne 1 -or $rustToolProfile.id -cne 'r4os-rust-tools-v1' -or ($rustToolProfile.technical -and !$Technical)){throw 'RustToolProfileUnsupportedOrTechnical'}
    Check-Inputs $SdkRoot $rustToolProfile.sdk.inputs;Check-Inputs $ContractRoot $rustToolProfile.contract.inputs
    $runner=Join-Path $ToolsRoot 'Setup/Rust.ps1'
    $pwsh=(Get-Process -Id $PID).Path
    $toolArgs=@('-NoLogo','-NoProfile','-File',$runner,'--root',$InstallRoot,'--cache-root',$CacheRoot)
    $description=(Invoke-Tool $pwsh ($toolArgs+@('check')) $OutputRoot)|ConvertFrom-Json -AsHashtable
    if(!$description.installed -or !$description.complete_toolset){throw 'RustToolsetIncomplete'}
    $hostName=if($IsWindows){'Windows'}elseif($IsLinux){'Linux'}else{throw 'Unsupported Rust host'}
    $catalog=Canonical $ToolsRoot $rustToolProfile.hosts[$hostName].catalog
    $packager=Canonical $ToolsRoot $rustToolProfile.hosts[$hostName].packager
    $heapRuntime=Canonical $ToolsRoot $rustToolProfile.runtime.heap.path
    if((Hash $heapRuntime) -cne $rustToolProfile.runtime.heap.sha256){throw 'MatchedHeapRuntimeMismatch'}
    if($IsLinux){& chmod 755 $catalog $packager;if($LASTEXITCODE -ne 0){throw 'Cannot prepare executable host tools'}}
    $phase='manifest'
    $manifest=Join-Path $ProjectRoot 'module.R4MF'
    $plan=(Invoke-Tool $catalog @('plan','--manifest',$manifest) $OutputRoot)|ConvertFrom-Json -AsHashtable
    if($plan.plan.language -cne 'Rust' -or $plan.plan.kind -cne 'R4X'){throw 'RustR4XManifestRequired'}
    $facts=$plan.plan;$rust=$facts.rust_project
    # Stable, owned compiler input generated by the canonical manifest owner.
    # The Rust runtime consumes typed records, not another import grammar.
    Invoke-Tool $catalog @('startup-info','--manifest',$manifest,'--output',$startupFile) $OutputRoot|Out-Null
    if(!$rust.host_build_qualified -and !$Technical){throw 'RustHostBuilderNotYetQualified'}
    $codegenPath=Join-Path $SdkRoot 'r4os/rust_module_profile.json'
    $codegen=Get-Content -Raw -LiteralPath $codegenPath|ConvertFrom-Json -AsHashtable
    if($codegen.schema -ne 1 -or $codegen.id -cne $rust.profile -or $codegen.target -cne $description.kernel_target){throw 'RustModuleProfileMismatch'}
    foreach($name in @('RUSTFLAGS','CARGO_ENCODED_RUSTFLAGS','RUSTC','RUSTC_WRAPPER','RUSTC_WORKSPACE_WRAPPER','RUSTDOC','RUSTC_BOOTSTRAP')){
        if([Environment]::GetEnvironmentVariable($name)){throw "RustEnvironmentOverrideForbidden: $name"}
    }
    foreach($pair in [Environment]::GetEnvironmentVariables().GetEnumerator()){
        if([string]$pair.Key -match '^CARGO_(PROFILE_|TARGET_|BUILD_)' -and $pair.Value){throw ('RustEnvironmentOverrideForbidden: '+$pair.Key)}
    }
    Assert-NoCargoConfig $ProjectRoot;Assert-NoCargoConfig $OutputRoot
    $artifact=Join-Path $OutputRoot ($facts.name+'.R4X');$elf=Join-Path $OutputRoot ($facts.name+'.elf')
    Write-Json $ownerFile @{schema=1;project=$ProjectRoot;status='building';artifact=[IO.Path]::GetFileName($artifact);elf=[IO.Path]::GetFileName($elf)}
    $work=Join-Path $OutputRoot ('.work-'+[guid]::NewGuid().ToString('N'));[IO.Directory]::CreateDirectory($work)|Out-Null
    $cargoBuildHome=Join-Path $work 'cargo-home';[IO.Directory]::CreateDirectory($cargoBuildHome)|Out-Null
    $compiler=Join-Path $description.toolchain ('bin/rustc'+$(if($IsWindows){'.exe'}else{''}))
    $cargo=Join-Path $description.toolchain ('bin/cargo'+$(if($IsWindows){'.exe'}else{''}))
    $targetDir=Join-Path $CacheRoot ('Projects/'+[Convert]::ToHexString([Security.Cryptography.SHA256]::HashData([Text.Encoding]::UTF8.GetBytes($ProjectRoot+'|'+$description.toolset_manifest_sha256))).ToLowerInvariant())
    $cpuPath=Join-Path $ContractRoot 'Module/CpuBaseline.json';$cpu=Get-Content -Raw -LiteralPath $cpuPath|ConvertFrom-Json -AsHashtable
    if((Hash $cpuPath) -cne $rustToolProfile.runtime.heap.cpu_baseline_sha256){throw 'HeapRuntimeCpuContractMismatch'}
    if($cpu.format -ne 1 -or $cpu.xcr0_mask -ne 7){throw 'Unsupported CPU baseline'}
    $mapping=@{'-msse2'='sse2';'-mavx2'='avx2';'-maes'='aes';'-mpclmul'='pclmulqdq'}
    $features=@(foreach($requirement in $cpu.requirements){if($requirement.ContainsKey('c_flag')){if(!$mapping.ContainsKey($requirement.c_flag)){throw 'Unmapped canonical CPU requirement'};'+'+$mapping[$requirement.c_flag]}})
    $flags=@('-C',('code-model='+$codegen.code_model),'-C',('relocation-model='+$codegen.relocation_model),'-C','no-redzone=yes','-C',('target-cpu='+$cpu.cpu_model.Replace('_','-')),'-C',('target-feature='+($features -join ',')),'-C',('lto='+$codegen.lto),'-C','embed-bitcode=yes','-C',('codegen-units='+$codegen.codegen_units),'-C',('panic='+$codegen.panic))
    foreach($entry in @(@($ProjectRoot,'/r4os/project'),@($SdkRoot,'/r4os/sdk'),@($ContractRoot,'/r4os/contract'),@($CacheRoot,'/r4os/cache'),@($InstallRoot,'/r4os/tools'),@($OutputRoot,'/r4os/output'))){$flags+=('--remap-path-prefix='+$entry[0]+'='+$entry[1])}
    $envForCargo=@{CARGO_HOME=$cargoBuildHome;RUSTUP_HOME=$description.rustup_home;RUSTUP_TOOLCHAIN=([IO.Path]::GetFileName($description.toolchain));RUSTUP_AUTO_INSTALL='0';RUSTC=$compiler;CARGO_TARGET_DIR=$targetDir;CARGO_ENCODED_RUSTFLAGS=($flags -join [char]31);RUSTFLAGS=$null;R4OS_STARTUP_INFO_FILE=$startupFile;R4OS_MODULE_NAME=$facts.name;CARGO_INCREMENTAL='0';CARGO_PROFILE_RELEASE_OPT_LEVEL=$codegen.optimization[$facts.optimization];CARGO_PROFILE_RELEASE_PANIC='abort';CARGO_PROFILE_RELEASE_OVERFLOW_CHECKS='true';CARGO_PROFILE_RELEASE_DEBUG_ASSERTIONS='false';CARGO_PROFILE_RELEASE_DEBUG='0';CARGO_PROFILE_RELEASE_STRIP='none';CARGO_TERM_COLOR='never'}
    # Selected path crates satisfy these exact patched registry identities.
    # No registry/git download, ambient cargo config or custom build step.
    $patches=@('--config',('patch.crates-io.r4os-contract.path='+('"'+(Join-Path $ContractRoot 'Generated/SDK/Rust').Replace('\','/')+'"')),'--config',('patch.crates-io.r4os-sdk.path='+('"'+(Join-Path $SdkRoot 'Rust').Replace('\','/')+'"')))
    $phase='cargo-metadata'
    $metadata=(Invoke-Tool $cargo (@('metadata','--format-version','1','--offline','--locked','--manifest-path',(Join-Path $ProjectRoot 'Cargo.toml'))+$patches) $work $envForCargo)|ConvertFrom-Json -AsHashtable
    if(!(SamePath $metadata.workspace_root $ProjectRoot) -or $metadata.workspace_members.Count -ne 1){throw 'RustCargoAmbiguousWorkspace'}
    $package=@($metadata.packages|Where-Object id -CEQ $metadata.workspace_members[0]);if($package.Count -ne 1){throw 'RustCargoAmbiguousPackage'};$package=$package[0]
    $source=Canonical $ProjectRoot $rust.source
    if($package.name -cne $rust.cargo_package -or $package.version -cne $rust.cargo_version -or $package.targets.Count -ne 1){throw 'RustCargoSelectionMismatch'}
    $target=$package.targets[0]
    if($target.kind.Count -ne 1 -or $target.kind[0] -cne 'staticlib' -or $target.crate_types.Count -ne 1 -or $target.crate_types[0] -cne 'staticlib' -or !(SamePath $target.src_path $source) -or $target.edition -cne '2024'){throw 'RustCargoTargetMismatch'}
    $allowed=@{$ProjectRoot=$package.name;(Join-Path $SdkRoot 'Rust')='r4os-sdk';(Join-Path $ContractRoot 'Generated/SDK/Rust')='r4os-contract'}
    $sdkFeatureNames=@()
    foreach($dep in $metadata.packages){
        $directory=[IO.Path]::GetDirectoryName([IO.Path]::GetFullPath($dep.manifest_path))
        if(!$allowed.ContainsKey($directory) -or $allowed[$directory] -cne $dep.name -or $null -ne $dep.source){throw 'RustCargoDependencyOutsideSelectedRoots'}
        if($directory -cne $ProjectRoot -and $dep.version -cne '0.1.0'){throw 'RustCargoBindingVersionMismatch'}
        foreach($t in $dep.targets){if($t.kind -contains 'custom-build' -or $t.kind -contains 'proc-macro'){throw 'RustCargoHostBuildStepForbidden'}}
        foreach($d in $dep.dependencies){
            $sdkFeatures=$d.name -ceq 'r4os-sdk' -and @($d.features|Where-Object {$_ -cne 'alloc'}).Count -eq 0
            if($null -ne $d.kind -or $d.rename -or (!$sdkFeatures -and $d.features.Count -ne 0) -or $d.optional){throw 'RustCargoDependencyExtensionUnsupported'}
        }
        foreach($node in $metadata.resolve.nodes){
            if($node.id -ceq $dep.id -and $node.features.Count){
                if($dep.name -cne 'r4os-sdk' -or @($node.features|Where-Object {$_ -cnotin @('default','alloc')}).Count){throw 'RustCargoFeatureUnsupported'}
                $sdkFeatureNames=@($node.features)
            }
        }
    }
    $phase='compile'
    $messages=Invoke-Tool $cargo (@('build','--release','--lib','--locked','--offline','--target',$codegen.target,'--manifest-path',(Join-Path $ProjectRoot 'Cargo.toml'),'--message-format=json-render-diagnostics')+$patches) $work $envForCargo (Join-Path $work 'cargo')
    $archive=''
    foreach($line in $messages.Split("`n")){
        if(!$line.Trim()){continue};$message=$line|ConvertFrom-Json -AsHashtable
        if($message.reason -ceq 'compiler-artifact' -and $message.package_id -ceq $package.id){foreach($file in $message.filenames){if($file.EndsWith('.a')){if($archive){throw 'Ambiguous Rust archive'};$archive=$file}}}
    }
    if(!$archive -or !(Test-Path -LiteralPath $archive -PathType Leaf)){throw 'RustArchiveMissing'}
    $phase='link'
    $linked=Join-Path $work 'module.elf';$script=Canonical $SdkRoot $codegen.linker_script
    Invoke-Tool $description.linker @('-flavor','gnu','--emit-relocs','--gc-sections','--no-undefined','--strip-debug','--entry','R4XStart','-T',$script,'-o',$linked,$archive,$heapRuntime) $work|Out-Null
    $phase='package'
    $candidate=Join-Path $work 'module.R4X'
    $packArgs=@('--r4m','--kind','r4x','--elf',$linked,'--output',$candidate,'--module-name',$facts.name,'--app-class',$facts.app_class,'--export','R4XStart:@R4XStart:1')
    foreach($import in $facts.imports){$packArgs+=@('--import',$import)}
    foreach($meta in $facts.metadata){$packArgs+=@('--meta',$meta)}
    $declared=@(Input $manifest $ProjectRoot 'project';Input (Join-Path $ProjectRoot 'Cargo.toml') $ProjectRoot 'project';Input (Join-Path $ProjectRoot 'Cargo.lock') $ProjectRoot 'project')
    foreach($icon in $rust.icons){$path=Canonical $ProjectRoot $icon;$packArgs+=@('--icon',$path);$declared+=Input $path $ProjectRoot 'project'}
    if($rust.help){$path=Canonical $ProjectRoot $rust.help;$packArgs+=@('--help-file',$path);$declared+=Input $path $ProjectRoot 'project'}
    foreach($resource in $rust.resources){$path=Canonical $ProjectRoot $resource.path;$packArgs+=@('--resource',$resource.name,$path);$declared+=Input $path $ProjectRoot 'project'}
    $packing=Invoke-Tool $packager $packArgs $work -Diagnostics
    $inspection=Invoke-Tool $packager @('--inspect',$candidate) $work -Diagnostics
    $phase='dep-info'
    $depInfo=[IO.Path]::ChangeExtension($archive,'.d')
    $depText=[IO.File]::ReadAllText($depInfo)
    $line=@($depText.Split("`n")|Where-Object {$_ -match ': '})[0]
    $rhs=$line.Substring($line.IndexOf(': ')+2);$paths=[Collections.Generic.List[string]]::new();$token=[Text.StringBuilder]::new();$escaped=$false
    foreach($c in $rhs.ToCharArray()){
        if($escaped){[void]$token.Append($c);$escaped=$false;continue}
        if($c -eq '\'){$escaped=$true;continue}
        if([char]::IsWhiteSpace($c)){if($token.Length){$paths.Add($token.ToString());[void]$token.Clear()}}else{[void]$token.Append($c)}
    }
    if($token.Length){$paths.Add($token.ToString())}
    $observed=@(foreach($pathText in ($paths|Sort-Object -Unique)){
        $path=[IO.Path]::GetFullPath($pathText)
        if(SamePath $path $startupFile){Input $path $OutputRoot 'generated'}elseif(Below $path $ProjectRoot){Input $path $ProjectRoot 'project'}elseif(Below $path $SdkRoot){Input $path $SdkRoot 'sdk'}elseif(Below $path $ContractRoot){Input $path $ContractRoot 'contract'}else{throw 'RustCompilerDependencyOutsideSelectedRoots'}
    })
    if(!@($observed|Where-Object {$_.owner -ceq 'project' -and $_.path -ceq $rust.source}).Count){throw 'RustCompilerSourceNotObserved'}
    if(!@($observed|Where-Object owner -CEQ 'generated').Count){throw 'RustCompilerStartupInfoNotObserved'}
    $result=[ordered]@{schema=1;profile=$rust.profile;status='success';technical=[bool]$Technical;module=@{name=$facts.name;version=$rust.module_version;kind='R4X';app_class=$facts.app_class;target=$facts.target;imports=$facts.imports};cargo=@{name=$package.name;version=$package.version;source=$rust.source;target=$codegen.target;lock_sha256=Hash (Join-Path $ProjectRoot 'Cargo.lock')};sdk=$rustToolProfile.sdk;contract=$rustToolProfile.contract;tools=@{profile_sha256=Hash $rustToolProfilePath;pin_sha256=$description.pin_sha256;rust=$description.rust_version;cargo=$description.cargo_version;linker_sha256=$description.linker_sha256;packager_sha256=Hash $packager;catalog_sha256=Hash $catalog};cpu=@{id=$cpu.name;sha256=Hash $cpuPath;features=$features};codegen=@{profile_sha256=Hash $codegenPath;code_model=$codegen.code_model;relocation_model=$codegen.relocation_model;lto=$codegen.lto;red_zone=$false;panic='abort';stack_probes=$codegen.stack_probes};declared_inputs=$declared;compiler_inputs=$observed;elf=@{file=[IO.Path]::GetFileName($elf);sha256=Hash $linked};artifact=@{file=[IO.Path]::GetFileName($artifact);sha256=Hash $candidate;bytes=([IO.FileInfo]$candidate).Length};container_inspection=$inspection.Trim()}
    $result['memory']=@{sdk_features=$sdkFeatureNames;heap_runtime=@{path=$rustToolProfile.runtime.heap.path;sha256=Hash $heapRuntime;owner='SDK/r4os/vm_allocator.zig';instance_checked=$true};alloc_sysroot_component='rust-std/'+$codegen.target;root_return_releases_heap=$false}
    Copy-Item -LiteralPath $linked -Destination $elf;Copy-Item -LiteralPath $candidate -Destination $artifact
    Write-Json $receipt $result;Write-Json $ownerFile @{schema=1;project=$ProjectRoot;status='success';artifact=[IO.Path]::GetFileName($artifact);elf=[IO.Path]::GetFileName($elf)}
    $failedLink=Join-Path $OutputRoot 'failed-link.elf'
    if(Test-Path -LiteralPath $failedLink){[IO.File]::Delete($failedLink)}
    $success=$true;Write-Host "Rust R4X built: $artifact";Write-Output ($result|ConvertTo-Json -Depth 40)
}catch{
    if($Technical -and $work -and (Test-Path -LiteralPath (Join-Path $work 'module.elf'))){Copy-Item -LiteralPath (Join-Path $work 'module.elf') -Destination (Join-Path $OutputRoot 'failed-link.elf') -Force}
    if($artifact -and (Test-Path -LiteralPath $artifact)){[IO.File]::Delete($artifact)}
    if($elf -and (Test-Path -LiteralPath $elf)){[IO.File]::Delete($elf)}
    if($receipt -and (Test-Path -LiteralPath $receipt)){[IO.File]::Delete($receipt)}
    if($startupFile -and (Test-Path -LiteralPath $startupFile)){[IO.File]::Delete($startupFile)}
    Write-Error "Rust build failed at ${phase}: $_" -ErrorAction Continue
}finally{
    if($work -and (Test-Path -LiteralPath $work)){Remove-Item -LiteralPath $work -Recurse -Force}
    if($guard){$guard.Dispose()}
}
if(!$success){exit 1}
