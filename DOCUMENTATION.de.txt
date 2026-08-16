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
        Apps/
        Services/
        Diagnostics/
        Drivers/
        Protocols/

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
Zig-Paketaufloesung anwenden. Der gemappte aktuelle lokale Contract-Checkout
wird mit Zig `--fork` als Projektvariante verwendet. URL und Commit im
Paketmanifest dokumentieren nur den zuletzt geprueften
Standalone-Referenzstand fuer einen direkten Build ohne Starter; sie sperren
den normalen Workspace-Build nicht auf diesen Stand. Der SDK-Build benoetigt
dadurch weder einen festen Nachbarpfad noch GitHub-Zugangsdaten.

Herkunft und absichtliche Grenzaenderungen stehen in `PROVENANCE.txt`.

Modulbuilds
-----------

`Sdk.addR4MF` baut ein Modul ausschliesslich aus dessen `module.R4MF`. Fuer
ZIG_MODULE-Abhaengigkeiten aus anderen Repositories verwendet ein Modulbuild
`Sdk.addR4MFWithOptions`: Die Namen und ihre Reihenfolge bleiben im Manifest,
waehrend `zig_module_roots` die vom Zig-Paketmanager aufgeloesten, explizit
eingebundenen Quellpfade in derselben Reihenfolge liefert. Der jeweilige
Buildstarter stellt mit `--fork` die aktuell gemappten lokalen SDK-, Contract-
und Libraries-Checkouts bereit. Eine inkompatible aktuelle Aenderung bricht
den Verbraucherbuild sichtbar; der Stand in `build.zig.zon` bleibt lediglich
der gepruefte Standalone-Referenzstand. Dadurch sind weder feste Nachbarpfade
noch eine zweite Library-Importliste im Buildscript erforderlich.

Mehrrepo-Imageplaene
--------------------

`ModuleCatalog workspace-image-plan` liest eine explizite Textzuordnung aus
`MANIFEST|ARTEFAKT`-Zeilen und erzeugt daraus einen Slim-, Full- oder
Test-Plan. Manifestparsing, Profilregeln, Zielkollisionen und der
Runtime-R4L-Abhaengigkeitsschluss bleiben beim gemeinsamen R4MF-Vertrag; die
Workspace-Orchestrierung liefert nur den Ort des bereits vom jeweiligen
Repository gebauten Artefakts.

Optional erzeugt derselbe Aufruf mit `--inventory-output` aus genau dieser
Auswahl das installierte `MODULES.JSON`; zusammen mit Kernel-Version und
-Artefakt enthaelt es damit keine handgepflegte zweite Komponentenliste.

Plattformbruecken
-----------------

Die sechs kernelimplementierten Gruppen R4SYS, R4DESK, R4DRAW, R4NET,
R4AUDIO und R4DEV benoetigen kleine R4L-Query-Container. Deren Manifeste und
die generische, aus den Contract-Gruppendaten gespeiste Verpackungslogik
liegen unter `PlatformBridges/`. Sie implementieren keine API-Funktion:
Contract bleibt Tabellenwahrheit, Kernel bleibt Provider und das SDK erzeugt
nur den Query-/Import-Glue fuer den allgemeinen R4M0-Lader. Optionale
Runtime-Libraries bleiben davon vollstaendig getrennt.
