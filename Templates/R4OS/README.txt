R4OS SDK Templates
==================

Diese Templates sind die installierbaren Projektvorlagen fuer R4CODE und
R4BUILD unter C:\R4OS\SDK\Templates.

Templates gehoeren ins SDK, nicht in C:\SOFTWARE\R4CODE. R4CODE liest sie aus
dem installierten SDK-Paket und erzeugt daraus Projektdateien plus Quelltext.

Die ersten Vorlagen sind:

  R4X C Terminal Hello  -> R4X_C_Console
  R4X C Desktop OK     -> R4X_C_Desktop_OK

Seit 0.58.33 erzeugt R4CODE daraus `module.R4MF` und Quelltext. R4BUILD
validiert, plant und baut dieses Manifest direkt ueber R4PACK und R4CC.

Eine Vorlagen-Quelle (Stand 0.58.33)
-----------------------------------

Das Host-Tool `DevTools/Scripts/New-R4XProject.ps1` legt neue R4X-Projekte
host-seitig an und nutzt dabei DIESELBEN Quelltext-Vorlagen wie R4CODE:

- C-Konsole: `R4X_C_Console/module.R4MF.template` und
  `R4X_C_Console/src/main.c.template` sind die Inside-R4OS-Wahrheit. Die
  entsprechenden Hosttemplates liegen unter `../R4X/CConsole/` und bilden
  denselben R4MF-v2-Vertrag ab. Die gemeinsamen Hosttemplates unter
  `../R4X/` erzeugen die duennen projektlokalen build.zig/build.zig.zon,
  die ausschliesslich an module.R4MF und das SDK delegieren.
- C-Desktop: `R4X_C_Desktop_OK/module.R4MF.template` und die zugehoerige
  Quelle bilden das aktuelle Desktop-Profil mit R4SYS, R4DESK und R4DRAW ab.
- Zig-Konsole: `../R4X/ZigConsole/` traegt src/main.zig (platzhalterfrei,
  direkt baubar; der Generator ersetzt definiert nur den Hello-Text)
  plus das R4MF-v2-Manifesttemplate. Inside-R4OS gibt es keinen Zig-Buildpfad
  (R4CC ist das C-Subset) - Zig-Projekte sind Host-only.

New-R4XProject.ps1 erzeugt Manifest, Quelle und den eigenstaendigen duennen
SDK-Buildeinstieg. Root-Aggregat und Imageplan entdecken das neue Projekt aus
dem Manifest; der Generator bearbeitet weder zentrale Builddateien noch
Image-Listen oder Anker.

Keine zweite Vorlagen-Wahrheit anlegen: neue Vorlagen entstehen hier im
SDK und werden von beiden Wegen gelesen.

`template.ini` beschreibt nur den Vorlagenkatalog und die Dateinamen. Sprache,
Modulart, App-Klasse, Imports und Ziel stehen ausschliesslich im
`module.R4MF.template` und werden nicht in `template.ini` dupliziert.
