# GUI examples

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

`GuiEvents.c` is a complete C application using only `<r4os/app_gui.h>`.
Use the same GUI imports and `ENTRY_MODE=app`, with `LANGUAGE=C` and
`SOURCE=src/main.c` in an ordinary R4X project. Copy the example to that source
path and build with the project's normal starter. It waits for messages,
paints on change, and changes its caption on focus or font notifications.

The window loop waits on the current per-program `gui_activity_wait` callback
with shared clipboard notifications. It requires that current callback; the
Desktop host activity channel does not deliver these client event wakeups.

The C event loop returns `R4_MESSAGE_FOCUS_GAINED` and
`R4_MESSAGE_FOCUS_LOST` with `message.value.focus.window_id` and `.tick`.
`R4_MESSAGE_FONT_CHANGED` uses `message.value.font_changed`; query the current
font/metrics or repaint when handling it. The existing global font broadcast
has `window_id=-1` and `tick=0`, with no font ID or revision. The facade preserves
these absent values. Other unknown raw events remain in
`R4_MESSAGE_UNKNOWN` and `message.value.unknown`.

`R4GuiWindowInfo.flags` can be tested with `R4_GUI_WINDOW_FLAG_VISIBLE`,
`R4_GUI_WINDOW_FLAG_MINIMIZED`, `R4_GUI_WINDOW_FLAG_MAXIMIZED`,
`R4_GUI_WINDOW_FLAG_CLOSE_REQUESTED` and `R4_GUI_WINDOW_FLAG_FULLSCREEN`.
These public names alias the canonical Contract definitions. The technical
header `<r4os/abi_generated.h>` also exposes the generated
`R4ABI_GUI_WINDOW_FLAG_*` names for the first four flags and the existing raw
`R4ABI_GUI_EVENT_KIND_FOCUS_GAINED`, `...FOCUS_LOST`, `...FONT_CHANGED` names.
The SDK's shared session bridge and Rust `gui::EventKind` expose the same three
new semantic events. Existing message numbers and public C payload sizes remain
stable; raw, higher C, and shared session event kinds are distinct enums.

For retained resources and output ownership see Libraries/R4GFX/Examples;
Vulkan bootstrap: Libraries/R4VK/Examples; a complete ordinary OpenGL window:
Libraries/R4GL/Examples/Triangle.zig. The integration/cost report is
Docs/Desktop/GrafikIntegration07944.txt in the workspace Docs repository.
