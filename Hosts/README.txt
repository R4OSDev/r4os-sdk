R4OS SDK Host-Profile
=====================

`Code/System/SDK/Shared` enthaelt den gemeinsamen SDK-Kern fuer R4OS/x86_64:
Bindings, Header, Startup-Stubs, Linkprofile, Templates und Buildprofile.

`Code/System/SDK/Hosts` enthaelt nur Host-spezifische Huellen. Ein Host ist die
Umgebung, in der gebaut wird, nicht das R4OS-Zielsystem.

Profile:
- Windows: erster externer Host fuer R4CodePad und lokale Zig-Builds.
- Linux: spaeterer externer Host mit demselben SDK-Kern.
- R4OS: spaeteres internes Paket fuer eine IDE im laufenden R4OS.

Die ABI-/API-Wahrheit bleibt unter `Code/System/SDK/Contract`. Host-Profile duerfen
Pfade und Tools konfigurieren, aber keine zweite ABI definieren.
