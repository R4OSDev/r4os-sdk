param(
    [Parameter(Mandatory)][string]$Catalog,
    [Parameter(Mandatory)][string]$WorkRoot,
    [string]$PreviousCatalog = ''
)
$ErrorActionPreference='Stop'; Set-StrictMode -Version Latest
$sdk=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$Catalog=[IO.Path]::GetFullPath($Catalog)
$WorkRoot=[IO.Path]::GetFullPath($WorkRoot)
if(Test-Path -LiteralPath $WorkRoot){throw 'Use a new empty test root.'}
[IO.Directory]::CreateDirectory($WorkRoot)|Out-Null
$utf8=[Text.UTF8Encoding]::new($false)
$fixture=Join-Path $sdk 'Tests/Build/RustManifest'
$original=[IO.File]::ReadAllText((Join-Path $fixture 'module.R4MF'))
$cargo=[IO.File]::ReadAllText((Join-Path $fixture 'Cargo.toml'))
function Run([string]$Action,[string]$Manifest,[bool]$Success,[string]$Expected=''){
    $result=@(& $Catalog $Action --manifest $Manifest 2>&1)
    $code=$LASTEXITCODE; $text=$result -join "`n"
    if(($code -eq 0) -ne $Success -or ($Expected -and !$text.Contains($Expected))){throw "Unexpected $Action result ($code): $text"}
    return $text
}
foreach($class in @('console','gui','service')){
    $root=Join-Path $WorkRoot $class; Copy-Item -LiteralPath $fixture -Destination $root -Recurse
    $manifest=Join-Path $root 'module.R4MF'; $text=$original.Replace('APP_CLASS=console',"APP_CLASS=$class")
    if($class -eq 'gui'){$text+="`nIMPORT=R4DESK:Query:1`nIMPORT=R4DRAW:Query:1`n"}
    [IO.File]::WriteAllText($manifest,$text,$utf8)
    Run validate $manifest $true|Out-Null
    $plan=(Run plan $manifest $true)|ConvertFrom-Json
    if($plan.plan.language -cne 'Rust' -or $plan.plan.rust_project.cargo_package -cne 'rust-manifest-probe' -or $plan.plan.rust_project.module_version -cne '0.1.0'){throw 'Rust plan identity drift.'}
    Run contract-plan $manifest $true 'R4MF_PLAN=1'|Out-Null
}
$manifest=Join-Path $WorkRoot 'console/module.R4MF'
$cases=@(
    @{find='src/main.rs';replace='../main.rs';error='SourcePathEscape'},
    @{find='src/main.rs';replace='src/main.c';error='SourceLanguageMismatch'},
    @{find='VERSION=0.1.0';replace='VERSION=bad';error='BadModuleVersion'},
    @{find='ENTRY_MODE=app';replace='ENTRY_MODE=lowlevel';error='RustLowlevelUnsupported'},
    @{find='SOURCE=src/main.rs';replace="SOURCE=src/main.rs`nSOURCE=other.rs";error='RustRequiresSingleSource'},
    @{find='SOURCE=src/main.rs';replace="SOURCE=src/main.rs`nC_FLAG=-O2";error='RustForbidsForeignBuildFields'}
)
foreach($case in $cases){
    [IO.File]::WriteAllText($manifest,$original.Replace($case.find,$case.replace),$utf8)
    Run validate $manifest $false $case.error|Out-Null
}
[IO.File]::WriteAllText($manifest,$original,$utf8)
$cargoPath=Join-Path $WorkRoot 'console/Cargo.toml'
[IO.File]::WriteAllText($cargoPath,$cargo.Replace('src/main.rs','src/other.rs'),$utf8)
Run validate $manifest $false 'RustCargoSourceMismatch'|Out-Null
[IO.File]::WriteAllText($cargoPath,$cargo+"`n[profile.release]`npanic=`"unwind`"`n",$utf8)
Run validate $manifest $false 'RustCargoUnsupportedTable'|Out-Null
[IO.File]::WriteAllText($cargoPath,$cargo,$utf8)
$lockPath=Join-Path $WorkRoot 'console/Cargo.lock';[IO.File]::Move($lockPath,$lockPath+'.held')
try {Run validate $manifest $false 'RustCargoLockMissing'|Out-Null} finally {[IO.File]::Move($lockPath+'.held',$lockPath)}
foreach($language in @('Zig','C')){
    $path=Join-Path $sdk "Smoke/AppEntry/$language/Console/module.R4MF"
    Run validate $path $true|Out-Null
    if($PreviousCatalog){
        foreach($action in @('plan','contract-plan')){
            $old=@(& $PreviousCatalog $action --manifest $path 2>&1);if($LASTEXITCODE -ne 0){throw 'Previous catalog failed.'}
            $new=Run $action $path $true
            if(($old -join "`n") -cne $new){throw "$language $action changed."}
        }
    }
}
Write-Host 'Rust project file/plan cases and existing Zig/C contracts PASS.'
