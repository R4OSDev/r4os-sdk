param(
    [Parameter(Mandatory)][string]$ProjectRoot,
    [Parameter(Mandatory)][string]$ContractRoot,
    [Parameter(Mandatory)][string]$ToolsRoot,
    [string]$SdkRoot='', [string]$InstallRoot='', [string]$CacheRoot='',
    [string]$OutputRoot='', [string[]]$DependencyRoot=@(), [string]$DependencyRootsJson='',
    [string]$Features='', [switch]$NoDefaultFeatures, [string]$ZigRoot='',
    [string]$LibraryHelpersRoot='',
    [switch]$Technical
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
. (Join-Path $PSScriptRoot 'RustBuildInputs.ps1')
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
    $facadeObjects=@(foreach($name in @('facades','storage')){
        $item=$rustToolProfile.runtime[$name]
        $path=Canonical $ToolsRoot $item.path
        if((Hash $path) -cne $item.sha256){throw ('MatchedSdkRuntimeMismatch: '+$name)}
        $path
    })
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
    if($rust.schema -ne 2 -or $codegen.schema -ne 2 -or $codegen.id -cne $rust.profile -or $codegen.target -cne $description.kernel_target){throw 'RustModuleProfileMismatch'}
    if($DependencyRootsJson){
        $decoded=ConvertFrom-Json -InputObject $DependencyRootsJson -NoEnumerate
        if($decoded -isnot [array] -or @($decoded|Where-Object {$_ -isnot [string]}).Count){throw 'RustDependencyRootsJsonInvalid'}
        $DependencyRoot+=@($decoded)
    }
    if($LibraryHelpersRoot){
        $LibraryHelpersRoot=[IO.Path]::GetFullPath($LibraryHelpersRoot)
        if(!@($DependencyRoot|Where-Object {SamePath $_ $LibraryHelpersRoot}).Count){$DependencyRoot+=@($LibraryHelpersRoot)}
    }
    $inputRoots=@(@{owner='project';path=$ProjectRoot},@{owner='sdk';path=$SdkRoot},@{owner='contract';path=$ContractRoot})
    foreach($dependency in $DependencyRoot){
        $path=[IO.Path]::GetFullPath($dependency)
        if(!(Test-Path -LiteralPath $path -PathType Container)){throw 'RustDependencyRootMissing'}
        if(@($inputRoots|Where-Object {SamePath $_.path $path}).Count){throw 'RustDuplicateDependencyRoot'}
        $inputRoots+=@{owner=('dependency'+($inputRoots.Count-3));path=$path}
    }
    $selection=@()
    if($Features){
        if($Features -cnotmatch '^[A-Za-z0-9_+./-]+(,[A-Za-z0-9_+./-]+)*$'){throw 'RustFeatureSelectionInvalid'}
        $selection+=@('--features',$Features)
    }
    if($NoDefaultFeatures){$selection+='--no-default-features'}
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
    foreach($name in @('facades','storage')){if((Hash $cpuPath) -cne $rustToolProfile.runtime[$name].cpu_baseline_sha256){throw ('SdkRuntimeCpuContractMismatch: '+$name)}}
    if($cpu.format -ne 1 -or $cpu.xcr0_mask -ne 7){throw 'Unsupported CPU baseline'}
    $mapping=@{'-msse2'='sse2';'-mavx2'='avx2';'-maes'='aes';'-mpclmul'='pclmulqdq'}
    $cpuFeatures=@(foreach($requirement in $cpu.requirements){if($requirement.ContainsKey('c_flag')){if(!$mapping.ContainsKey($requirement.c_flag)){throw 'Unmapped canonical CPU requirement'};'+'+$mapping[$requirement.c_flag]}})
    if(!$codegen.backend_features.reason -or $codegen.backend_features.selection -cne 'target-defaults'){throw 'RustBackendFeaturePolicyInvalid'}
    # Hardware admission and C/Zig objects retain the complete common floor.
    # Do not apply their SIMD switches to this softfloat Rust target: the
    # pinned backend miscompiles ordinary aggregate moves in that combination.
    $effectiveCpuFeatures=@()
    $flags=@('-C',('code-model='+$codegen.code_model),'-C',('relocation-model='+$codegen.relocation_model),'-C','no-redzone=yes','-C',('target-cpu='+$cpu.cpu_model.Replace('_','-')),'-C',('lto='+$codegen.lto),'-C','embed-bitcode=yes','-C',('codegen-units='+$codegen.codegen_units),'-C',('panic='+$codegen.panic))
    $remaps=@($inputRoots)+@(@{owner='cache';path=$CacheRoot},@{owner='tools';path=$InstallRoot},@{owner='output';path=$OutputRoot})
    foreach($root in $remaps|Sort-Object {$_.path.Length}){$flags+=('--remap-path-prefix='+$root.path+'=/r4os/'+$root.owner)}
    $envForCargo=@{CARGO_HOME=$cargoBuildHome;RUSTUP_HOME=$description.rustup_home;RUSTUP_TOOLCHAIN=([IO.Path]::GetFileName($description.toolchain));RUSTUP_AUTO_INSTALL='0';RUSTC=$compiler;CARGO_TARGET_DIR=$targetDir;CARGO_ENCODED_RUSTFLAGS=($flags -join [char]31);RUSTFLAGS=$null;R4OS_STARTUP_INFO_FILE=$startupFile;R4OS_MODULE_NAME=$facts.name;CARGO_INCREMENTAL='0';CARGO_PROFILE_RELEASE_OPT_LEVEL=$codegen.optimization[$facts.optimization];CARGO_PROFILE_RELEASE_PANIC='abort';CARGO_PROFILE_RELEASE_OVERFLOW_CHECKS='true';CARGO_PROFILE_RELEASE_DEBUG_ASSERTIONS='false';CARGO_PROFILE_RELEASE_DEBUG='0';CARGO_PROFILE_RELEASE_STRIP='none';CARGO_TERM_COLOR='never'}
    # Selected path crates satisfy these exact patched registry identities.
    # Other path/vendor crates are selected by the caller's Cargo manifests
    # and explicit roots. No registry/git download or ambient build step.
    $patches=@('--config',('patch.crates-io.r4os-contract.path='+('"'+(Join-Path $ContractRoot 'Generated/SDK/Rust').Replace('\','/')+'"')),'--config',('patch.crates-io.r4os-sdk.path='+('"'+(Join-Path $SdkRoot 'Rust').Replace('\','/')+'"')))
    $phase='cargo-metadata'
    $metadata=(Invoke-Tool $cargo (@('metadata','--format-version','1','--offline','--locked','--filter-platform',$codegen.target,'--manifest-path',(Join-Path $ProjectRoot 'Cargo.toml'))+$selection+$patches) $work $envForCargo)|ConvertFrom-Json -AsHashtable
    if(!(SamePath $metadata.workspace_root $ProjectRoot) -or $metadata.workspace_members.Count -ne 1){throw 'RustCargoAmbiguousWorkspace'}
    $package=@($metadata.packages|Where-Object id -CEQ $metadata.workspace_members[0]);if($package.Count -ne 1){throw 'RustCargoAmbiguousPackage'};$package=$package[0]
    if($null -ne $package.metadata -and $package.metadata.ContainsKey('r4os')){throw 'RustCargoModuleMetadataConflict'}
    $source=Canonical $ProjectRoot $rust.source
    if(!(SamePath $package.manifest_path (Join-Path $ProjectRoot 'Cargo.toml')) -or $package.targets.Count -ne 1){throw 'RustCargoSelectionMismatch'}
    $target=$package.targets[0]
    if($target.kind.Count -ne 1 -or $target.kind[0] -cne 'staticlib' -or $target.crate_types.Count -ne 1 -or $target.crate_types[0] -cne 'staticlib' -or !(SamePath $target.src_path $source) -or $target.edition -cne '2024'){throw 'RustCargoTargetMismatch'}
    $sdkFeatureNames=@();$crateInputs=@();$crateGraph=@()
    foreach($dep in $metadata.packages){
        $directory=[IO.Path]::GetDirectoryName([IO.Path]::GetFullPath($dep.manifest_path))
        $root=Find-InputOwner $directory $inputRoots
        if($null -ne $dep.source){throw 'RustCargoRequiresExplicitLocalSources'}
        Assert-NoCargoConfig $directory
        foreach($binding in @(@('r4os-sdk',(Join-Path $SdkRoot 'Rust'),$rustToolProfile.sdk.rust_crate.version),@('r4os-contract',(Join-Path $ContractRoot 'Generated/SDK/Rust'),$rustToolProfile.contract.binding_crate.version))){
            if($dep.name -ceq $binding[0] -and (!(SamePath $directory $binding[1]) -or $dep.version -cne $binding[2])){throw 'RustCargoBindingIdentityMismatch'}
        }
        foreach($t in $dep.targets){if($t.kind -contains 'custom-build' -or $t.kind -contains 'proc-macro'){throw 'RustCargoHostBuildStepForbidden'}}
        $crateInputs+=Observe-Input $dep.manifest_path $inputRoots
        $resolvedFeatures=@();$resolvedDependencies=@();$edges=@();$resolved=$false
        foreach($node in $metadata.resolve.nodes){
            if($node.id -ceq $dep.id){
                $resolvedFeatures=@($node.features);$resolvedDependencies=@($node.dependencies)
                $edges=@($node.deps);$resolved=$true
                if($dep.name -ceq 'r4os-sdk'){$sdkFeatureNames=$resolvedFeatures}
            }
        }
        $crateGraph+=@{id=$dep.id;name=$dep.name;version=$dep.version;owner=$root.owner;manifest=[IO.Path]::GetRelativePath($root.path,$dep.manifest_path).Replace('\','/');resolved=$resolved;features=$resolvedFeatures;dependencies=$resolvedDependencies;dependency_edges=$edges}
    }
    $phase='compile-c'
    $native=Build-RustCCompanions $rust $cpu $facts.optimization $work $inputRoots
    $phase='compile-library-helpers'
    $libraryHelpers=Build-RustLibraryHelpers $work $inputRoots
    $phase='compile'
    $messages=Invoke-Tool $cargo (@('build','--release','--lib','--locked','--offline','--target',$codegen.target,'--manifest-path',(Join-Path $ProjectRoot 'Cargo.toml'),'--message-format=json-render-diagnostics')+$selection+$patches) $work $envForCargo (Join-Path $work 'cargo')
    $archive=''
    foreach($line in $messages.Split("`n")){
        if(!$line.Trim()){continue};$message=$line|ConvertFrom-Json -AsHashtable
        if($message.reason -ceq 'compiler-artifact'){
            if($message.profile.opt_level -cne $codegen.optimization[$facts.optimization] -or $message.profile.debug_assertions -or !$message.profile.overflow_checks -or $message.profile.test){throw 'RustCargoCompiledProfileMismatch'}
            if($message.package_id -ceq $package.id){foreach($file in $message.filenames){if($file.EndsWith('.a')){if($archive){throw 'Ambiguous Rust archive'};$archive=$file}}}
        }
    }
    if(!$archive -or !(Test-Path -LiteralPath $archive -PathType Leaf)){throw 'RustArchiveMissing'}
    $phase='link'
    $linked=Join-Path $work 'module.elf';$script=Canonical $SdkRoot $codegen.linker_script
    Invoke-Tool $description.linker (@('-flavor','gnu','--emit-relocs','--gc-sections','--no-undefined','--strip-debug','--entry','R4XStart','-T',$script,'-o',$linked,$archive,$heapRuntime)+$facadeObjects+$native.objects+$libraryHelpers.objects) $work|Out-Null
    $phase='package'
    $candidate=Join-Path $work 'module.R4X'
    $packArgs=@('--r4m','--kind','r4x','--elf',$linked,'--output',$candidate,'--module-name',$facts.name,'--app-class',$facts.app_class,'--export','R4XStart:@R4XStart:1')
    foreach($import in $facts.imports){$packArgs+=@('--import',$import)}
    foreach($meta in $facts.metadata){$packArgs+=@('--meta',$meta)}
    $declared=@(Input $manifest $ProjectRoot 'project';Input (Join-Path $ProjectRoot 'Cargo.lock') $ProjectRoot 'project')+$crateInputs
    foreach($icon in $rust.icons){$path=Canonical $ProjectRoot $icon;$packArgs+=@('--icon',$path);$declared+=Input $path $ProjectRoot 'project'}
    if($rust.help){$path=Canonical $ProjectRoot $rust.help;$packArgs+=@('--help-file',$path);$declared+=Input $path $ProjectRoot 'project'}
    foreach($resource in $rust.resources){$path=Canonical $ProjectRoot $resource.path;$packArgs+=@('--resource',$resource.name,$path);$declared+=Input $path $ProjectRoot 'project'}
    $packing=Invoke-Tool $packager $packArgs $work -Diagnostics
    $inspection=Invoke-Tool $packager @('--inspect',$candidate) $work -Diagnostics
    $phase='dep-info'
    $depInfo=[IO.Path]::ChangeExtension($archive,'.d')
    $observed=@(foreach($pathText in (Read-CompilerDependencies $depInfo|Sort-Object -Unique)){
        $path=[IO.Path]::GetFullPath($pathText)
        if(SamePath $path $startupFile){Input $path $OutputRoot 'generated'}else{Observe-Input $path $inputRoots}
    })+@($native.inputs)+@($libraryHelpers.inputs)
    if(!@($observed|Where-Object {$_.owner -ceq 'project' -and $_.path -ceq $rust.source}).Count){throw 'RustCompilerSourceNotObserved'}
    if(!@($observed|Where-Object owner -CEQ 'generated').Count){throw 'RustCompilerStartupInfoNotObserved'}
    $result=[ordered]@{schema=1;profile=$rust.profile;status='success';technical=[bool]$Technical;module=@{name=$facts.name;version=$rust.module_version;kind='R4X';app_class=$facts.app_class;target=$facts.target;imports=$facts.imports};cargo=@{name=$package.name;version=$package.version;source=$rust.source;target=$codegen.target;lock_sha256=Hash (Join-Path $ProjectRoot 'Cargo.lock')};sdk=$rustToolProfile.sdk;contract=$rustToolProfile.contract;tools=@{profile_sha256=Hash $rustToolProfilePath;pin_sha256=$description.pin_sha256;rust=$description.rust_version;cargo=$description.cargo_version;linker_sha256=$description.linker_sha256;packager_sha256=Hash $packager;catalog_sha256=Hash $catalog};cpu=@{id=$cpu.name;sha256=Hash $cpuPath;features=$cpuFeatures};codegen=@{profile_sha256=Hash $codegenPath;code_model=$codegen.code_model;relocation_model=$codegen.relocation_model;lto=$codegen.lto;red_zone=$false;panic='abort';stack_probes=$codegen.stack_probes};declared_inputs=$declared;compiler_inputs=$observed;elf=@{file=[IO.Path]::GetFileName($elf);sha256=Hash $linked};artifact=@{file=[IO.Path]::GetFileName($artifact);sha256=Hash $candidate;bytes=([IO.FileInfo]$candidate).Length};container_inspection=$inspection.Trim()}
    $result['memory']=@{sdk_features=$sdkFeatureNames;heap_runtime=@{path=$rustToolProfile.runtime.heap.path;sha256=Hash $heapRuntime;owner='SDK/r4os/vm_allocator.zig';instance_checked=$true};alloc_sysroot_component='rust-std/'+$codegen.target;root_return_releases_heap=$false}
    $result['sdk_runtimes']=@{facades=$rustToolProfile.runtime.facades;storage=$rustToolProfile.runtime.storage}
    $result['library_helpers']=$libraryHelpers.receipt
    $result.codegen['target_features']=$effectiveCpuFeatures
    $result.codegen['backend_feature_policy']=$codegen.backend_features
    $result['schema']=2
    $result.cargo['graph']=$crateGraph
    $result.cargo['selected_features']=$Features
    $result.cargo['default_features']=!$NoDefaultFeatures
    $result['native_c']=$native.compiler
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
