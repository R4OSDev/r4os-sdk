# Canvas example

`Canvas.zig` is a complete ordinary hosted GUI entry point. It paints the full
current client rectangle with bounded caller-owned command/resource arrays and
waits for events when unchanged. Resize paints a new transaction; drawing,
resource overflow or publication failure discards the entire frame and exits.
No driver detection, direct framebuffer access or private NVIDIA route exists.

Build it as an SDK R4X using `ENTRY_MODE=app`, `APP_CLASS=gui` and imports
`R4SYS:Query:1`, `R4DESK:Query:1`, `R4DRAW:Query:1`. Copy this source into an
application created from `Templates/R4X`; use its normal Build.bat/Build.sh.
Launch from Desktop: a GUI window is a prerequisite. The same source uses
software composition or the admitted native output chosen by Desktop.
This example is source documentation, not an installed module or a new test gate.

For retained resources and output ownership see Libraries/R4GFX/Examples;
Vulkan bootstrap: Libraries/R4VK/Examples; a complete ordinary OpenGL window:
Libraries/R4GL/Examples/Triangle.zig. The integration/cost report is
Docs/Desktop/GrafikIntegration07944.txt in the workspace Docs repository.
