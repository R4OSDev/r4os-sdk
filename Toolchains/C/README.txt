R4OS SDK C Toolchain
====================

Dieser Ordner ist der installierte Zielpfad fuer die native R4OS-C-Toolchain:

    C:\R4OS\SDK\Toolchains\C\

Ab 0.51.48 liegt der erste Compilerpfad hier:

    C:\R4OS\SDK\Toolchains\C\bin\R4CC.R4X

R4CC ist ein R4OS-eigener Bootstrap-Compiler. Es wird kein fremder
Hostcompiler und keine private Compiler-Kopie unter R4CODE genutzt.
Seit 0.58.33 kompiliert R4CC den aktuellen R4MF-v2-App-Subset-Vertrag:

    #include <r4os/r4os.h>
    R4OS_TEXT(name, "text")
    int32_t r4_app_main(R4App *app)
    r4sys_write_line(&app->system, name)

Der Compiler erzeugt in dieser Stufe rohe `.text`-Codebytes fuer
R4XStart/R4SYS. R4BUILD verpackt diese Bytes danach mit dem R4PACK-Core zu
einem R4M0-`.R4X` im Projekt-`out\`-Verzeichnis.

R4CC kann ausserdem das abgeleitete Profil `R4X_C_App_Desktop`
kompilieren. Dieses Profil ist weiterhin ein enger Bootstrap-C-Subset, nutzt
aber R4DESK/R4DRAW ueber die SDK-Header und erzeugt Code fuer ein gehostetes
GUI-Fenster mit `OK`-Button.

Die einzigen unterstuetzten R4MF-Profile sind `R4X_C_App_Console` und
`R4X_C_App_Desktop`. Andere Profile oder Sprachen liefern einen sichtbaren
Capabilityfehler im R4BUILD-Vertrag; ein alter Einstieg oder Hostcompiler wird
nicht als Ersatz gewaehlt.

`R4CC.STATUS` ist der installierte Toolchain-Status fuer R4BUILD. R4BUILD
liest diese Datei, weil ein Worker keinen zweiten Console-Compilerprozess aus
einem laufenden `programRun` heraus starten soll. Der Buildpfad nutzt deshalb
die gleiche R4CC-/R4PACK-Logik direkt im Worker, aber keine Hosttools und kein
vorgebautes Beispielartefakt.

Unterstruktur:
- `bin\` enthaelt ausfuehrbare Toolchain-Programme wie `R4CC.R4X`.
- `lib\` ist fuer spaetere Runtime-/Hilfsobjekte reserviert.
- `include-extra\` ist fuer toolchainspezifische Zusatz-Header reserviert.
