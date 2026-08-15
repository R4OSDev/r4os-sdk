R4OS SDK
========

Dieses Repository enthaelt das hostneutrale Kern-SDK von R4OS: Zig- und
C-Fassaden, Buildprofile, Templates, Smokeprojekte sowie die generischen
Werkzeuge R4XBuilder, R4LContractGen und ModuleCatalog.

Pfade
-----

`Settings.R4S` ist die zentrale Pfadzuordnung. `WORKSPACE_ROOT` und
`REPOSITORIES_ROOT` beginnen am SDK-Root. Komponentenpfade beginnen am
gemappten Repositories-Verzeichnis, DevKit und Artifacts an der Workspace-
Wurzel und Zig am DevKit. Jeder Wert darf durch einen anderen relativen oder
einen absoluten Pfad ersetzt werden. Werte werden ohne Anfuehrungszeichen
eingetragen und weder als Shellausdruck noch als Umgebungsvariable ausgewertet.

Die Voreinstellung passt zur normalen Workspace-Struktur:

    R4OS/
      DevKit/
      Artifacts/
      Repositories/
        Contract/
        SDK/
        Libraries/
        Kernel/
        Distribution/

Aktuell verwenden die SDK-Buildstarter `CONTRACT_ROOT` und `ZIG_ROOT`. Die
weiteren Eintraege bilden bereits die gemeinsamen Komponentenwurzeln fuer
kommende Werkzeuge ab.

Build
-----

Unter Windows:

    Build.bat
    Build.bat test

Unter Linux und macOS:

    ./Build.sh
    ./Build.sh test

Die Starter sind der verbindliche Einstieg, weil sie `Settings.R4S` vor der
Zig-Paketaufloesung anwenden. Das Paketmanifest pinnt die Contract-Identitaet
und dessen Inhalt; der gemappte lokale Checkout wird von Zig als passende
lokale Projektvariante verwendet. Der SDK-Build benoetigt dadurch weder einen
festen Nachbarpfad noch GitHub-Zugangsdaten.

Herkunft und absichtliche Grenzaenderungen stehen in `PROVENANCE.txt`.
