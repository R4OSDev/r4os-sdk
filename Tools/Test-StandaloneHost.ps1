param(
 [Parameter(Mandatory)][string]$ContractRoot,
 [Parameter(Mandatory)][string]$LibraryRoot,
 [Parameter(Mandatory)][string]$DevKitRoot,
 [Parameter(Mandatory)][string]$WorkRoot,
 [Parameter(Mandatory)][string]$ArtifactRoot
)
$ErrorActionPreference='Stop';Set-StrictMode -Version Latest
$sdk=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
foreach($key in @('ContractRoot','LibraryRoot','DevKitRoot','WorkRoot','ArtifactRoot')){Set-Variable $key ([IO.Path]::GetFullPath((Get-Variable $key -ValueOnly)))}
if(!$IsLinux -and !$IsWindows){throw 'An actual Linux or Windows host is required.'}
if((Test-Path -LiteralPath $WorkRoot) -or (Test-Path -LiteralPath $ArtifactRoot)){throw 'Select new private work/result directories.'}
[IO.Directory]::CreateDirectory($WorkRoot)|Out-Null
[IO.Directory]::CreateDirectory($ArtifactRoot)|Out-Null
$utf8=[Text.UTF8Encoding]::new($false);$pwsh=(Get-Process -Id $PID).Path
$hostName=if($IsWindows){'Windows'}else{'Linux'};$suffix=if($IsWindows){'.exe'}else{''}
$proof=[ordered]@{schema=1;status='pending';host=$hostName;os=[Runtime.InteropServices.RuntimeInformation]::OSDescription;architecture=[Runtime.InteropServices.RuntimeInformation]::OSArchitecture.ToString();powershell=$PSVersionTable.PSVersion.ToString();run_id=$env:GITHUB_RUN_ID;run_attempt=$env:GITHUB_RUN_ATTEMPT;sources=[ordered]@{};stages=@();projects=@();windows_guest_execution=$false}
$stage='initial';$success=$false
function Json([string]$Path,$Value){[IO.File]::WriteAllText($Path,($Value|ConvertTo-Json -Depth 18)+"`n",$utf8)}
function Notice([string]$Title,[string]$Message){
 if($env:GITHUB_ACTIONS -ceq 'true'){
  $escaped=$Message.Replace('%','%25').Replace("`r",'%0D').Replace("`n",'%0A')
  Write-Host ('::notice title='+$Title+'::'+$escaped)
 }else{Write-Host ($Title+': '+$Message)}
}
function Native([string]$Program,[string[]]$Arguments,[string]$Directory){
 $info=[Diagnostics.ProcessStartInfo]::new();$info.FileName=$Program;$info.WorkingDirectory=$Directory;$info.UseShellExecute=$false;$info.RedirectStandardOutput=$true;$info.RedirectStandardError=$true
 foreach($argument in $Arguments){$info.ArgumentList.Add($argument)}
 $process=[Diagnostics.Process]::new();$process.StartInfo=$info
 try{
  if(!$process.Start()){throw 'Cannot start selected tool.'}
  $stdout=$process.StandardOutput.ReadToEndAsync();$stderr=$process.StandardError.ReadToEndAsync();$process.WaitForExit()
  $out=$stdout.GetAwaiter().GetResult();$err=$stderr.GetAwaiter().GetResult()
  [IO.File]::WriteAllText((Join-Path $WorkRoot ($stage+'.log')),$out+$err,$utf8)
  if($process.ExitCode -ne 0){throw ('Selected tool failed '+$process.ExitCode+': '+[IO.Path]::GetFileName($Program)+"`n"+$err+"`n"+$out)}
  return $out
 }finally{$process.Dispose()}
}
function Passed([string]$Name){$proof.stages+=@{name=$Name;exit=0};Notice 'R4OS_SDK_STAGE' ($Name+' PASS')}
function Download([string]$Url,[string]$Destination,[string]$Sha){
 if($Url -cnotmatch '^https://(ziglang\.org|static\.rust-lang\.org)/'){throw 'Unexpected pinned compiler source.'}
 $curl=(Get-Command $(if($IsWindows){'curl.exe'}else{'curl'}) -CommandType Application|Select-Object -First 1).Source
 Native $curl @('--fail','--location','--proto','=https','--tlsv1.2','--retry','2','--connect-timeout','30','--max-time','300','--silent','--show-error','--output',$Destination,$Url) $WorkRoot|Out-Null
 if((Get-FileHash -LiteralPath $Destination -Algorithm SHA256).Hash.ToLowerInvariant() -cne $Sha){throw 'Pinned download checksum differs.'}
}
function Archive([string]$Source,[string]$Name){
 $destination=Join-Path $WorkRoot ('Components/'+$Name);[IO.Directory]::CreateDirectory($destination)|Out-Null
 $archive=Join-Path $WorkRoot ($Name+'.tar');$commit=$proof.sources[$Name]
 Native 'git' @('-C',$Source,'archive','--format=tar',('--output='+$archive),$commit) $WorkRoot|Out-Null
 Native 'tar' @('-xf',$archive,'-C',$destination) $WorkRoot|Out-Null
 [IO.File]::Delete($archive);return $destination
}
function SdkBuild([string]$Name,[string[]]$Flags,[string]$Output){
 $script:stage=$Name
 Native $script:zig (@('build',('--fork='+$ContractRoot),'--cache-dir',(Join-Path $WorkRoot 'ZigCache'),'--prefix',$Output,'-j1')+$Flags) $sdk|Out-Null
 Passed $Name
}
try{
 foreach($pair in @(@('SDK',$sdk),@('Contract',$ContractRoot),@('Libraries',$LibraryRoot),@('DevKit',$DevKitRoot))){
  $stage='source-'+$pair[0];$commit=(Native 'git' @('-C',$pair[1],'rev-parse','HEAD') $WorkRoot).Trim()
  $dirty=Native 'git' @('-C',$pair[1],'status','--porcelain','--untracked-files=normal') $WorkRoot
  if($commit -cnotmatch '^[0-9a-f]{40}$' -or $dirty.Trim()){throw 'Use exact clean source component repositories.'}
  $proof.sources[$pair[0]]=$commit
 }
 Notice 'R4OS_SDK_HOST' (($proof|ConvertTo-Json -Depth 5 -Compress))
 $stage='zig-download';$zigPin=Get-Content -LiteralPath (Join-Path $DevKitRoot 'Setup/ZigToolchain.json') -Raw|ConvertFrom-Json -AsHashtable
 $selected=$zigPin.hosts[$hostName];$archive=Join-Path $WorkRoot $(if($IsWindows){'zig.zip'}else{'zig.tar.xz'})
 Download $selected.url $archive $selected.sha256
 $zigDirectory=Join-Path $WorkRoot 'Compiler';[IO.Directory]::CreateDirectory($zigDirectory)|Out-Null
 if($IsWindows){Expand-Archive -LiteralPath $archive -DestinationPath $zigDirectory}else{Native 'tar' @('-xf',$archive,'-C',$zigDirectory) $WorkRoot|Out-Null}
 [IO.File]::Delete($archive)
 $zigRoot=Join-Path $zigDirectory ('zig-'+$selected.target+'-'+$zigPin.version);$script:zig=Join-Path $zigRoot ('zig'+$suffix)
 if((Native $zig @('version') $WorkRoot).Trim() -cne $zigPin.version){throw 'Zig version differs.'}
 $proof.zig=@{version=$zigPin.version;archive_sha256=$selected.sha256;executable_sha256=(Get-FileHash -LiteralPath $zig -Algorithm SHA256).Hash.ToLowerInvariant()};Passed 'isolated-pinned-zig'
 foreach($targetHost in @('Linux','Windows')){
  $target=if($targetHost -ceq 'Windows'){'x86_64-windows-gnu'}else{'x86_64-linux-gnu'}
  $prefix=Join-Path $WorkRoot ('HostTools/'+$targetHost)
  SdkBuild ('packager-'+$targetHost) @('-Dpackager-only=true',('-Dtarget='+$target),'-Doptimize=ReleaseSafe') $prefix
  SdkBuild ('catalog-'+$targetHost) @('-Dcatalog-only=true',('-Dtarget='+$target)) $prefix
 }
 $runtime=Join-Path $WorkRoot 'Runtime'
 SdkBuild 'shared-module-facades' @('-Dfacade-runtime-only=true') $runtime
 SdkBuild 'shared-module-heap' @('-Dheap-runtime-only=true') $runtime
 $stage='canonical-component-archives';$packages=Join-Path $WorkRoot 'Components'
 $packageSdk=Archive $sdk 'SDK';$packageContract=Archive $ContractRoot 'Contract';$packageLibraries=Archive $LibraryRoot 'Libraries'
 $tools=Join-Path $packages 'Tools';$stage='rust-release-manifest';$rustPin=Get-Content -LiteralPath (Join-Path $DevKitRoot 'Setup/RustToolchain.json') -Raw|ConvertFrom-Json -AsHashtable
 $manifest=Join-Path $WorkRoot 'rust-release.toml';Download ('https://static.rust-lang.org/dist/channel-rust-'+$rustPin.rust_version+'.toml') $manifest $rustPin.manifest_sha256
 $stage='export-matched-tools'
 Native $pwsh @('-NoLogo','-NoProfile','-File',(Join-Path $DevKitRoot 'Setup/Export-RustTools.ps1'),'-Destination',$tools,'-SdkRoot',$sdk,'-ContractRoot',$ContractRoot,'-ReleaseManifest',$manifest,'-PackagerLinux',(Join-Path $WorkRoot 'HostTools/Linux/bin/r4xbuilder'),'-PackagerWindows',(Join-Path $WorkRoot 'HostTools/Windows/bin/r4xbuilder.exe'),'-CatalogLinux',(Join-Path $WorkRoot 'HostTools/Linux/bin/module-catalog'),'-CatalogWindows',(Join-Path $WorkRoot 'HostTools/Windows/bin/module-catalog.exe'),'-HeapRuntime',(Join-Path $runtime 'lib/r4sdk_heap.o'),'-FacadeRuntime',(Join-Path $runtime 'lib/r4sdk_facades.o'),'-StorageRuntime',(Join-Path $runtime 'lib/r4sdk_storage.o')) $WorkRoot|Out-Null
 Passed 'canonical-matched-export'
 $launcher=Join-Path $tools 'Setup/Rust.ps1';$install=Join-Path $WorkRoot 'IsolatedTools';$cache=Join-Path $WorkRoot 'RustCache'
 $stage='rust-isolated-install';Native $pwsh @('-NoLogo','-NoProfile','-File',$launcher,'--root',$install,'--cache-root',$cache,'setup') $WorkRoot|Out-Null
 $stage='rust-isolated-check';$description=(Native $pwsh @('-NoLogo','-NoProfile','-File',$launcher,'--root',$install,'--cache-root',$cache,'check') $WorkRoot)|ConvertFrom-Json -AsHashtable
 if(!$description.installed -or !$description.complete_toolset -or $description.profile -cne 'sdk'){throw 'Isolated SDK compiler installation not ready.'}
 $proof.rust=@{version=$description.rust_version;host=$description.host;profile=$description.profile;pin_sha256=$description.pin_sha256;linker_sha256=$description.linker_sha256;installed_components=$description.installed_components};Passed 'isolated-pinned-rust'
 $stage='native-capabilities';Native $pwsh @('-NoLogo','-NoProfile','-File',(Join-Path $packageSdk 'Tools/Test-Capabilities.ps1'),'-SdkRoot',$packageSdk,'-ToolsRoot',$tools,'-WorkRoot',(Join-Path $WorkRoot 'Capabilities')) $WorkRoot|Out-Null;Passed 'native-compiler-free-capabilities'
 # Reuse the existing seven canonical interop cases on the actual host ABI.
 # This is native C/Zig/Rust execution, separate from the R4OS target build.
 $stage='native-rust-consumer';$targetDir=Join-Path $WorkRoot 'Interop';$hostTriple=$description.host
 Native $pwsh @('-NoLogo','-NoProfile','-File',$launcher,'--root',$install,'--cache-root',$cache,'cargo','build','--locked','--offline','--release','--manifest-path',(Join-Path $packageContract 'Tests/RustInterop/Cargo.toml'),'--target',$hostTriple,'--target-dir',$targetDir) $WorkRoot|Out-Null
 $library=Join-Path $targetDir ($hostTriple+'/release/'+$(if($IsWindows){'r4os_contract_interop.lib'}else{'libr4os_contract_interop.a'}))
 $stage='native-c-rust-roundtrip'
 Native $zig @('test','-O','ReleaseSafe','-lc','-I',(Join-Path $packageContract 'Generated/SDK/C/include'),'-cflags','-O1','-UNDEBUG','--',(Join-Path $packageContract 'Tests/RustInterop/interop.c'),$library,'--dep','r4os_technical_abi',('-Mroot='+(Join-Path $packageContract 'Tests/RustInterop/interop.zig')),('-Mr4os_technical_abi='+(Join-Path $packageContract 'Generated/SDK/Zig/abi.zig')),'--cache-dir',(Join-Path $WorkRoot 'NativeInteropCache')) $WorkRoot|Out-Null
 Passed 'existing-native-C-Zig-Rust-consumer'
 $stage='desktop-host-builds';$guest=Join-Path $ArtifactRoot 'Consumers'
 Native $pwsh @('-NoLogo','-NoProfile','-File',(Join-Path $packageSdk 'Tools/Test-DesktopHostBuild.ps1'),'-SdkRoot',$packageSdk,'-ContractRoot',$packageContract,'-LibraryRoot',$packageLibraries,'-ToolsRoot',$tools,'-ZigRoot',$zigRoot,'-InstallRoot',$install,'-CacheRoot',$cache,'-NativeCacheRoot',(Join-Path $WorkRoot 'ZigCache'),'-WorkRoot',(Join-Path $WorkRoot 'DesktopBuild'),'-ArtifactRoot',$guest) $WorkRoot|Out-Null
 $builds=Get-Content -LiteralPath (Join-Path $guest 'builds.json') -Raw|ConvertFrom-Json -AsHashtable
 if($builds.host -cne $hostName -or $builds.projects.Count -ne 2){throw 'Missing actual host project builds.'}
 $proof.projects=$builds.projects;$proof.toolset_sha256=(Get-FileHash -LiteralPath (Join-Path $tools 'RustToolsProfile.json') -Algorithm SHA256).Hash.ToLowerInvariant()
 foreach($file in @('r4sdk_heap.o','r4sdk_facades.o','r4sdk_storage.o')){$proof.stages+=@{name=$file;sha256=(Get-FileHash -LiteralPath (Join-Path $runtime ('lib/'+$file)) -Algorithm SHA256).Hash.ToLowerInvariant()}}
 Passed 'actual-standalone-C-Rust-desktop-host-builds'
 $proof.status='PASS';Json (Join-Path $ArtifactRoot 'result.json') $proof
 Notice 'R4OS_SDK_RESULT' ($proof|ConvertTo-Json -Depth 18 -Compress)
 $success=$true
}catch{
 $proof.status='FAIL';$proof.failed_stage=$stage;$proof.error=$_.Exception.Message
 Json (Join-Path $ArtifactRoot 'result.json') $proof
 Notice 'R4OS_SDK_RESULT' ($proof|ConvertTo-Json -Depth 18 -Compress)
 foreach($file in Get-ChildItem -LiteralPath $WorkRoot -File -Filter '*.log'){Copy-Item -LiteralPath $file.FullName -Destination (Join-Path $ArtifactRoot $file.Name)}
 throw
}finally{if($success){Remove-Item -LiteralPath $WorkRoot -Recurse -Force}}
