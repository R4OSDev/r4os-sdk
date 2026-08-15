R4OS SDK BuildProfiles
======================

Diese Dateien beschreiben installierbare Buildprofile fuer R4OS-interne
Werkzeuge wie R4CODE und R4BUILD.

Die Profile sind keine zweite ABI-Wahrheit. Sie verweisen auf das installierte
SDK unter C:\R4OS\SDK und auf den Contract-Snapshot unter
C:\R4OS\SDK\Contract. Die Quelle fuer ABI und API bleibt Code/System/SDK/Contract im
Repository.

Die ersten internen R4CODE-/R4BUILD-Profile sind:

  R4X_C_Console
  R4X_C_Desktop_OK

Seit 0.51.51 baut `R4X_C_Desktop_OK` ein GUI-R4X mit R4SYS-, R4DESK- und
R4DRAW-Imports sowie AppClass `gui`.

`R4X_C` bleibt als bestehendes externes R4CodePad-Kompatibilitaetsprofil
lesbar. Der interne R4OS-Buildpfad soll die praeziseren Profile verwenden.

Seit 0.53.40 ist AVX2 Teil des Standard-SIMD-Profils fuer R4X/R4D/R4P-
Artefakte, wenn R4OS XSAVE x87+SSE+YMM aktiviert. Die Profile fuehren keine
SSE-only- oder soft-float-Ersatzroute.
