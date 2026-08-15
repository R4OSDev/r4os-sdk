R4OS SDK Host-Profil Windows
============================

Dieses Profil ist der erste externe Host-Pfad fuer R4CodePad und fuer
freistehende Zig-/C-Projekte auf Windows.

Aktuelle 0.51.16-Regeln:
- Das SDK wird als Paket `r4os_sdk` ueber `build.zig.zon` gebunden.
- App-Projekte referenzieren nur eigene Quellen mit `b.path(...)`.
- Der SDK-Kern loest `r4os.zig`, Linker-Script, C-Header und C-Startup aus
  dem SDK-Root auf.
- `R4XBuilder` wird uebergangsweise ueber Host-Konfiguration oder
  `-Dr4os-r4xbuilder=...` angegeben, bis ein exportiertes SDK-Paket ihn
  selbst mitliefert.

Dieses Profil darf auf Windows-Tools zeigen, aber diese Pfade gehoeren nicht
in portable `module.R4MF`-Projektdateien. `.R4CP` ist nur noch Eingabe fuer
den ausdruecklichen Einmalkonverter und kein aktuelles Projektformat.
