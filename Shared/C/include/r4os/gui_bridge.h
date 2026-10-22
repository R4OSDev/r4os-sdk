/* Compiler-generated GUI owner boundary. Do not edit.
 * Private objects are native storage: use MaybeUninit in Rust. Never read
 * their bytes or assume padding initialized. Initialize all required fields
 * through the typed constructor before use. Borrowed strings/arrays/contexts
 * must outlive every referencing object. Stateful contexts/frames stay at
 * their exact address; inspect native status before release/reuse. Raw field
 * mutation requires preservation of the original owner's invariants.
 * Slot.status is transport status; bits retain native scalar return values,
 * including negative i32. PRESENT marks optional payloads, NATIVE_ERROR
 * exposes a resident error-name view. A returned view borrows its inputs or
 * exact native owner. Float values cross only through pointers. */
#ifndef R4OS_GUI_BRIDGE_H
#define R4OS_GUI_BRIDGE_H
#include "abi.h"
#define R4SDK_GUI_PRESENT 1u
#define R4SDK_GUI_NATIVE_ERROR 2u
#define R4SDK_GUI_DEFAULT 4u
typedef struct R4SdkGuiSlot { void *ptr; uint64_t length,bits; int32_t status; uint32_t flags; } R4SdkGuiSlot;
R4SdkGuiSlot R4SdkGuiInvoke(uint64_t,uint32_t,const R4SdkGuiSlot *,uint32_t,void *);
R4SdkGuiSlot R4SdkGuiConstruct(uint64_t,uint32_t,const R4SdkGuiSlot *,uint32_t,void *);
R4SdkGuiSlot R4SdkGuiInspect(uint64_t,uint32_t,void *,void *);
R4SdkGuiSlot R4SdkGuiField(uint64_t,uint32_t,uint32_t,void *,const R4SdkGuiSlot *,void *);
/* gui.Align; native size 1, alignment 1. */
typedef struct R4SdkGuiAlign { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiAlign;
#define R4SdkGuiAlign_TYPE 0u
/* gui.Palette; native size 40, alignment 4. */
typedef struct R4SdkGuiPalette { _Alignas(4) uint8_t opaque_bytes[40]; } R4SdkGuiPalette;
#define R4SdkGuiPalette_TYPE 1u
/* gui.ControlMetrics; native size 108, alignment 4. */
typedef struct R4SdkGuiControlMetrics { _Alignas(4) uint8_t opaque_bytes[108]; } R4SdkGuiControlMetrics;
#define R4SdkGuiControlMetrics_TYPE 2u
/* gui.FontMetrics; native size 20, alignment 4. */
typedef struct R4SdkGuiFontMetrics { _Alignas(4) uint8_t opaque_bytes[20]; } R4SdkGuiFontMetrics;
#define R4SdkGuiFontMetrics_TYPE 3u
/* gui.Key; native size 0, alignment 1. */
typedef struct R4SdkGuiKey { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiKey;
#define R4SdkGuiKey_TYPE 4u
/* gui.ControlAction; native size 1, alignment 1. */
typedef struct R4SdkGuiControlAction { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiControlAction;
#define R4SdkGuiControlAction_TYPE 5u
/* gui.FocusDirection; native size 1, alignment 1. */
typedef struct R4SdkGuiFocusDirection { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiFocusDirection;
#define R4SdkGuiFocusDirection_TYPE 6u
/* gui.FocusItem; native size 1, alignment 1. */
typedef struct R4SdkGuiFocusItem { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiFocusItem;
#define R4SdkGuiFocusItem_TYPE 7u
/* gui.FocusResult; native size 16, alignment 8. */
typedef struct R4SdkGuiFocusResult { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiFocusResult;
#define R4SdkGuiFocusResult_TYPE 8u
/* gui.FocusState; native size 8, alignment 8. */
typedef struct R4SdkGuiFocusState { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiFocusState;
#define R4SdkGuiFocusState_TYPE 9u
/* gui.MouseCapture; native size 24, alignment 8. */
typedef struct R4SdkGuiMouseCapture { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiMouseCapture;
#define R4SdkGuiMouseCapture_TYPE 10u
/* ?usize; native size 16, alignment 8. */
typedef struct R4SdkGuiType11 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType11;
#define R4SdkGuiType11_TYPE 11u
/* gui.SelectionStep; native size 16, alignment 8. */
typedef struct R4SdkGuiSelectionStep { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiSelectionStep;
#define R4SdkGuiSelectionStep_TYPE 12u
/* gui.TextRange; native size 16, alignment 8. */
typedef struct R4SdkGuiTextRange { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiTextRange;
#define R4SdkGuiTextRange_TYPE 13u
/* gui.TextAreaPoint; native size 16, alignment 8. */
typedef struct R4SdkGuiTextAreaPoint { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiTextAreaPoint;
#define R4SdkGuiTextAreaPoint_TYPE 14u
/* gui.TextAreaView; native size 24, alignment 8. */
typedef struct R4SdkGuiTextAreaView { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiTextAreaView;
#define R4SdkGuiTextAreaView_TYPE 15u
/* gui.MenuKeyResult; native size 24, alignment 8. */
typedef struct R4SdkGuiMenuKeyResult { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiMenuKeyResult;
#define R4SdkGuiMenuKeyResult_TYPE 16u
/* gui.MenubarResult; native size 40, alignment 8. */
typedef struct R4SdkGuiMenubarResult { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkGuiMenubarResult;
#define R4SdkGuiMenubarResult_TYPE 17u
/* gui.MenubarHitPart; native size 1, alignment 1. */
typedef struct R4SdkGuiMenubarHitPart { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiMenubarHitPart;
#define R4SdkGuiMenubarHitPart_TYPE 18u
/* gui.MenubarHit; native size 40, alignment 8. */
typedef struct R4SdkGuiMenubarHit { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkGuiMenubarHit;
#define R4SdkGuiMenubarHit_TYPE 19u
/* gui.Rect; native size 16, alignment 4. */
typedef struct R4SdkGuiRect { _Alignas(4) uint8_t opaque_bytes[16]; } R4SdkGuiRect;
#define R4SdkGuiRect_TYPE 20u
/* gui.LayoutCursor; native size 16, alignment 4. */
typedef struct R4SdkGuiLayoutCursor { _Alignas(4) uint8_t opaque_bytes[16]; } R4SdkGuiLayoutCursor;
#define R4SdkGuiLayoutCursor_TYPE 21u
/* gui.HostedAppFrame; native size 112, alignment 8. */
typedef struct R4SdkGuiHostedAppFrame { _Alignas(8) uint8_t opaque_bytes[112]; } R4SdkGuiHostedAppFrame;
#define R4SdkGuiHostedAppFrame_TYPE 22u
/* gui.Canvas; native size 48, alignment 8. */
typedef struct R4SdkGuiCanvas { _Alignas(8) uint8_t opaque_bytes[48]; } R4SdkGuiCanvas;
#define R4SdkGuiCanvas_TYPE 24u
/* *const r4draw.Context; native size 8, alignment 8. */
typedef struct R4SdkGuiType25 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType25;
#define R4SdkGuiType25_TYPE 25u
/* r4draw.Context; native size 8, alignment 8. */
typedef struct R4SdkGuiDrawContext { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiDrawContext;
#define R4SdkGuiDrawContext_TYPE 26u
/* ?*gui.FrameCanvas; native size 8, alignment 8. */
typedef struct R4SdkGuiType27 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType27;
#define R4SdkGuiType27_TYPE 27u
/* *gui.FrameCanvas; native size 8, alignment 8. */
typedef struct R4SdkGuiType28 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType28;
#define R4SdkGuiType28_TYPE 28u
/* gui.FrameCanvas; native size 120, alignment 8. */
typedef struct R4SdkGuiFrameCanvas { _Alignas(8) uint8_t opaque_bytes[120]; } R4SdkGuiFrameCanvas;
#define R4SdkGuiFrameCanvas_TYPE 29u
/* []abi_generated.GuiFrameCommand; native size 16, alignment 8. */
typedef struct R4SdkGuiType30 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType30;
#define R4SdkGuiType30_TYPE 30u
/* []u8; native size 16, alignment 8. */
typedef struct R4SdkGuiType32 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType32;
#define R4SdkGuiType32_TYPE 32u
/* gui.FrameCanvasStats; native size 56, alignment 8. */
typedef struct R4SdkGuiFrameCanvasStats { _Alignas(8) uint8_t opaque_bytes[56]; } R4SdkGuiFrameCanvasStats;
#define R4SdkGuiFrameCanvasStats_TYPE 33u
/* gui.Label; native size 88, alignment 8. */
typedef struct R4SdkGuiLabel { _Alignas(8) uint8_t opaque_bytes[88]; } R4SdkGuiLabel;
#define R4SdkGuiLabel_TYPE 34u
/* []const u8; native size 16, alignment 8. */
typedef struct R4SdkGuiType35 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType35;
#define R4SdkGuiType35_TYPE 35u
/* gui.ButtonState; native size 1, alignment 1. */
typedef struct R4SdkGuiButtonState { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiButtonState;
#define R4SdkGuiButtonState_TYPE 36u
/* gui.Button; native size 80, alignment 8. */
typedef struct R4SdkGuiButton { _Alignas(8) uint8_t opaque_bytes[80]; } R4SdkGuiButton;
#define R4SdkGuiButton_TYPE 37u
/* gui.List; native size 128, alignment 8. */
typedef struct R4SdkGuiList { _Alignas(8) uint8_t opaque_bytes[128]; } R4SdkGuiList;
#define R4SdkGuiList_TYPE 38u
/* []const []const u8; native size 16, alignment 8. */
typedef struct R4SdkGuiType39 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType39;
#define R4SdkGuiType39_TYPE 39u
/* gui.Orientation; native size 1, alignment 1. */
typedef struct R4SdkGuiOrientation { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiOrientation;
#define R4SdkGuiOrientation_TYPE 40u
/* gui.ScrollbarPart; native size 1, alignment 1. */
typedef struct R4SdkGuiScrollbarPart { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiScrollbarPart;
#define R4SdkGuiScrollbarPart_TYPE 41u
/* gui.ScrollbarStep; native size 16, alignment 8. */
typedef struct R4SdkGuiScrollbarStep { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiScrollbarStep;
#define R4SdkGuiScrollbarStep_TYPE 42u
/* gui.Scrollbar; native size 88, alignment 8. */
typedef struct R4SdkGuiScrollbar { _Alignas(8) uint8_t opaque_bytes[88]; } R4SdkGuiScrollbar;
#define R4SdkGuiScrollbar_TYPE 43u
/* gui.ToolbarButton; native size 80, alignment 8. */
typedef struct R4SdkGuiToolbarButton { _Alignas(8) uint8_t opaque_bytes[80]; } R4SdkGuiToolbarButton;
#define R4SdkGuiToolbarButton_TYPE 44u
/* gui.TabItem; native size 24, alignment 8. */
typedef struct R4SdkGuiTabItem { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiTabItem;
#define R4SdkGuiTabItem_TYPE 45u
/* gui.TabBar; native size 104, alignment 8. */
typedef struct R4SdkGuiTabBar { _Alignas(8) uint8_t opaque_bytes[104]; } R4SdkGuiTabBar;
#define R4SdkGuiTabBar_TYPE 46u
/* []const gui.TabItem; native size 16, alignment 8. */
typedef struct R4SdkGuiType47 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType47;
#define R4SdkGuiType47_TYPE 47u
/* gui.TableColumn; native size 24, alignment 8. */
typedef struct R4SdkGuiTableColumn { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiTableColumn;
#define R4SdkGuiTableColumn_TYPE 48u
/* gui.TableView; native size 144, alignment 8. */
typedef struct R4SdkGuiTableView { _Alignas(8) uint8_t opaque_bytes[144]; } R4SdkGuiTableView;
#define R4SdkGuiTableView_TYPE 49u
/* []const gui.TableColumn; native size 16, alignment 8. */
typedef struct R4SdkGuiType50 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType50;
#define R4SdkGuiType50_TYPE 50u
/* gui.Checkbox; native size 80, alignment 8. */
typedef struct R4SdkGuiCheckbox { _Alignas(8) uint8_t opaque_bytes[80]; } R4SdkGuiCheckbox;
#define R4SdkGuiCheckbox_TYPE 51u
/* gui.RadioButton; native size 80, alignment 8. */
typedef struct R4SdkGuiRadioButton { _Alignas(8) uint8_t opaque_bytes[80]; } R4SdkGuiRadioButton;
#define R4SdkGuiRadioButton_TYPE 52u
/* gui.GroupBox; native size 72, alignment 8. */
typedef struct R4SdkGuiGroupBox { _Alignas(8) uint8_t opaque_bytes[72]; } R4SdkGuiGroupBox;
#define R4SdkGuiGroupBox_TYPE 53u
/* gui.Separator; native size 60, alignment 4. */
typedef struct R4SdkGuiSeparator { _Alignas(4) uint8_t opaque_bytes[60]; } R4SdkGuiSeparator;
#define R4SdkGuiSeparator_TYPE 54u
/* gui.Dropdown; native size 120, alignment 8. */
typedef struct R4SdkGuiDropdown { _Alignas(8) uint8_t opaque_bytes[120]; } R4SdkGuiDropdown;
#define R4SdkGuiDropdown_TYPE 55u
/* gui.MenuItem; native size 40, alignment 8. */
typedef struct R4SdkGuiMenuItem { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkGuiMenuItem;
#define R4SdkGuiMenuItem_TYPE 56u
/* gui.Menu; native size 112, alignment 8. */
typedef struct R4SdkGuiMenu { _Alignas(8) uint8_t opaque_bytes[112]; } R4SdkGuiMenu;
#define R4SdkGuiMenu_TYPE 57u
/* []const gui.MenuItem; native size 16, alignment 8. */
typedef struct R4SdkGuiType58 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType58;
#define R4SdkGuiType58_TYPE 58u
/* gui.MenubarMenu; native size 40, alignment 8. */
typedef struct R4SdkGuiMenubarMenu { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkGuiMenubarMenu;
#define R4SdkGuiMenubarMenu_TYPE 59u
/* gui.MenubarState; native size 72, alignment 8. */
typedef struct R4SdkGuiMenubarState { _Alignas(8) uint8_t opaque_bytes[72]; } R4SdkGuiMenubarState;
#define R4SdkGuiMenubarState_TYPE 60u
/* gui.Menubar; native size 144, alignment 8. */
typedef struct R4SdkGuiMenubar { _Alignas(8) uint8_t opaque_bytes[144]; } R4SdkGuiMenubar;
#define R4SdkGuiMenubar_TYPE 61u
/* []const gui.MenubarMenu; native size 16, alignment 8. */
typedef struct R4SdkGuiType62 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType62;
#define R4SdkGuiType62_TYPE 62u
/* gui.DialogAction; native size 1, alignment 1. */
typedef struct R4SdkGuiDialogAction { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiDialogAction;
#define R4SdkGuiDialogAction_TYPE 63u
/* gui.DialogButtonRole; native size 1, alignment 1. */
typedef struct R4SdkGuiDialogButtonRole { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiDialogButtonRole;
#define R4SdkGuiDialogButtonRole_TYPE 64u
/* gui.DialogButtonAlign; native size 1, alignment 1. */
typedef struct R4SdkGuiDialogButtonAlign { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiDialogButtonAlign;
#define R4SdkGuiDialogButtonAlign_TYPE 65u
/* gui.DialogButton; native size 24, alignment 8. */
typedef struct R4SdkGuiDialogButton { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiDialogButton;
#define R4SdkGuiDialogButton_TYPE 66u
/* gui.DialogFocusItem; native size 2, alignment 1. */
typedef struct R4SdkGuiDialogFocusItem { _Alignas(1) uint8_t opaque_bytes[2]; } R4SdkGuiDialogFocusItem;
#define R4SdkGuiDialogFocusItem_TYPE 67u
/* gui.DialogEvent; native size 4, alignment 1. */
typedef struct R4SdkGuiDialogEvent { _Alignas(1) uint8_t opaque_bytes[4]; } R4SdkGuiDialogEvent;
#define R4SdkGuiDialogEvent_TYPE 68u
/* gui.ModalHitPart; native size 1, alignment 1. */
typedef struct R4SdkGuiModalHitPart { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiModalHitPart;
#define R4SdkGuiModalHitPart_TYPE 69u
/* gui.ModalHit; native size 2, alignment 1. */
typedef struct R4SdkGuiModalHit { _Alignas(1) uint8_t opaque_bytes[2]; } R4SdkGuiModalHit;
#define R4SdkGuiModalHit_TYPE 70u
/* gui.DialogState; native size 2, alignment 1. */
typedef struct R4SdkGuiDialogState { _Alignas(1) uint8_t opaque_bytes[2]; } R4SdkGuiDialogState;
#define R4SdkGuiDialogState_TYPE 71u
/* gui.ModalDialog; native size 80, alignment 8. */
typedef struct R4SdkGuiModalDialog { _Alignas(8) uint8_t opaque_bytes[80]; } R4SdkGuiModalDialog;
#define R4SdkGuiModalDialog_TYPE 72u
/* gui.ModalOverlay; native size 104, alignment 8. */
typedef struct R4SdkGuiModalOverlay { _Alignas(8) uint8_t opaque_bytes[104]; } R4SdkGuiModalOverlay;
#define R4SdkGuiModalOverlay_TYPE 73u
/* gui.MessageKind; native size 1, alignment 1. */
typedef struct R4SdkGuiMessageKind { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiMessageKind;
#define R4SdkGuiMessageKind_TYPE 74u
/* gui.MessageButtons; native size 1, alignment 1. */
typedef struct R4SdkGuiMessageButtons { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiMessageButtons;
#define R4SdkGuiMessageButtons_TYPE 75u
/* gui.FileDialogMode; native size 1, alignment 1. */
typedef struct R4SdkGuiFileDialogMode { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiFileDialogMode;
#define R4SdkGuiFileDialogMode_TYPE 76u
/* gui.MessageDialog; native size 160, alignment 8. */
typedef struct R4SdkGuiMessageDialog { _Alignas(8) uint8_t opaque_bytes[160]; } R4SdkGuiMessageDialog;
#define R4SdkGuiMessageDialog_TYPE 77u
/* gui.FileDialog; native size 232, alignment 8. */
typedef struct R4SdkGuiFileDialog { _Alignas(8) uint8_t opaque_bytes[232]; } R4SdkGuiFileDialog;
#define R4SdkGuiFileDialog_TYPE 78u
/* gui.InputDialog; native size 176, alignment 8. */
typedef struct R4SdkGuiInputDialog { _Alignas(8) uint8_t opaque_bytes[176]; } R4SdkGuiInputDialog;
#define R4SdkGuiInputDialog_TYPE 79u
/* ?gui.TextArea([]u8); native size 136, alignment 8. */
typedef struct R4SdkGuiType80 { _Alignas(8) uint8_t opaque_bytes[136]; } R4SdkGuiType80;
#define R4SdkGuiType80_TYPE 80u
/* gui.TextArea([]u8); native size 128, alignment 8. */
typedef struct R4SdkGuiTextArea { _Alignas(8) uint8_t opaque_bytes[128]; } R4SdkGuiTextArea;
#define R4SdkGuiTextArea_TYPE 81u
/* ?gui.TextField([]u8); native size 104, alignment 8. */
typedef struct R4SdkGuiType82 { _Alignas(8) uint8_t opaque_bytes[104]; } R4SdkGuiType82;
#define R4SdkGuiType82_TYPE 82u
/* gui.TextField([]u8); native size 96, alignment 8. */
typedef struct R4SdkGuiTextField { _Alignas(8) uint8_t opaque_bytes[96]; } R4SdkGuiTextField;
#define R4SdkGuiTextField_TYPE 83u
/* *const r4sys.Context; native size 8, alignment 8. */
typedef struct R4SdkGuiType84 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType84;
#define R4SdkGuiType84_TYPE 84u
/* r4sys.Context; native size 8, alignment 8. */
typedef struct R4SdkGuiSystemContext { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiSystemContext;
#define R4SdkGuiSystemContext_TYPE 85u
/* *const r4desk.Context; native size 8, alignment 8. */
typedef struct R4SdkGuiType86 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType86;
#define R4SdkGuiType86_TYPE 86u
/* r4desk.Context; native size 8, alignment 8. */
typedef struct R4SdkGuiDesktopContext { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiDesktopContext;
#define R4SdkGuiDesktopContext_TYPE 87u
/* *abi_generated.GuiEvent; native size 8, alignment 8. */
typedef struct R4SdkGuiType88 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType88;
#define R4SdkGuiType88_TYPE 88u
/* ?abi.GuiEventKind; native size 8, alignment 4. */
typedef struct R4SdkGuiType90 { _Alignas(4) uint8_t opaque_bytes[8]; } R4SdkGuiType90;
#define R4SdkGuiType90_TYPE 90u
/* [*:0]const u8; native size 8, alignment 8. */
typedef struct R4SdkGuiType92 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType92;
#define R4SdkGuiType92_TYPE 92u
/* gui.TextAreaLayout; native size 2104, alignment 8. */
typedef struct R4SdkGuiTextAreaLayout { _Alignas(8) uint8_t opaque_bytes[2104]; } R4SdkGuiTextAreaLayout;
#define R4SdkGuiTextAreaLayout_TYPE 93u
/* [128]gui.TextRange; native size 2048, alignment 8. */
typedef struct R4SdkGuiType94 { _Alignas(8) uint8_t opaque_bytes[2048]; } R4SdkGuiType94;
#define R4SdkGuiType94_TYPE 94u
/* *const gui.TextAreaLayout; native size 8, alignment 8. */
typedef struct R4SdkGuiType95 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType95;
#define R4SdkGuiType95_TYPE 95u
/* []const gui.DialogButton; native size 16, alignment 8. */
typedef struct R4SdkGuiType96 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType96;
#define R4SdkGuiType96_TYPE 96u
/* []const gui.DialogFocusItem; native size 16, alignment 8. */
typedef struct R4SdkGuiType97 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType97;
#define R4SdkGuiType97_TYPE 97u
/* app_gui.CommandId; native size 4, alignment 4. */
typedef struct R4SdkGuiCommandId { _Alignas(4) uint8_t opaque_bytes[4]; } R4SdkGuiCommandId;
#define R4SdkGuiCommandId_TYPE 98u
/* app_gui.TimerId; native size 4, alignment 4. */
typedef struct R4SdkGuiTimerId { _Alignas(4) uint8_t opaque_bytes[4]; } R4SdkGuiTimerId;
#define R4SdkGuiTimerId_TYPE 99u
/* app_gui.ResizeMessage; native size 24, alignment 8. */
typedef struct R4SdkGuiResizeMessage { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiResizeMessage;
#define R4SdkGuiResizeMessage_TYPE 100u
/* app_gui.KeyMessage; native size 24, alignment 8. */
typedef struct R4SdkGuiKeyMessage { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiKeyMessage;
#define R4SdkGuiKeyMessage_TYPE 101u
/* app_gui.MouseAction; native size 1, alignment 1. */
typedef struct R4SdkGuiMouseAction { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiMouseAction;
#define R4SdkGuiMouseAction_TYPE 102u
/* app_gui.MouseMessage; native size 32, alignment 8. */
typedef struct R4SdkGuiMouseMessage { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkGuiMouseMessage;
#define R4SdkGuiMouseMessage_TYPE 103u
/* app_gui.ClipboardMessage; native size 4, alignment 4. */
typedef struct R4SdkGuiClipboardMessage { _Alignas(4) uint8_t opaque_bytes[4]; } R4SdkGuiClipboardMessage;
#define R4SdkGuiClipboardMessage_TYPE 104u
/* app_gui.TimerMessage; native size 16, alignment 8. */
typedef struct R4SdkGuiTimerMessage { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiTimerMessage;
#define R4SdkGuiTimerMessage_TYPE 105u
/* app_gui.Message; native size 48, alignment 8. */
typedef struct R4SdkGuiMessage { _Alignas(8) uint8_t opaque_bytes[48]; } R4SdkGuiMessage;
#define R4SdkGuiMessage_TYPE 106u
/* @typeInfo(app_gui.Message).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkGuiType107 { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiType107;
#define R4SdkGuiType107_TYPE 107u
/* app_gui.WaitResult; native size 56, alignment 8. */
typedef struct R4SdkGuiWaitResult { _Alignas(8) uint8_t opaque_bytes[56]; } R4SdkGuiWaitResult;
#define R4SdkGuiWaitResult_TYPE 108u
/* @typeInfo(app_gui.WaitResult).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkGuiType109 { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiType109;
#define R4SdkGuiType109_TYPE 109u
/* app_gui.Timer; native size 24, alignment 8. */
typedef struct R4SdkGuiTimer { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiTimer;
#define R4SdkGuiTimer_TYPE 110u
/* app_gui.EventLoop; native size 56, alignment 8. */
typedef struct R4SdkGuiEventLoop { _Alignas(8) uint8_t opaque_bytes[56]; } R4SdkGuiEventLoop;
#define R4SdkGuiEventLoop_TYPE 111u
/* []app_gui.Timer; native size 16, alignment 8. */
typedef struct R4SdkGuiType112 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType112;
#define R4SdkGuiType112_TYPE 112u
/* ?app_gui.CommandId; native size 8, alignment 4. */
typedef struct R4SdkGuiType113 { _Alignas(4) uint8_t opaque_bytes[8]; } R4SdkGuiType113;
#define R4SdkGuiType113_TYPE 113u
/* app_gui.PaintOpen; native size 72, alignment 8. */
typedef struct R4SdkGuiPaintOpen { _Alignas(8) uint8_t opaque_bytes[72]; } R4SdkGuiPaintOpen;
#define R4SdkGuiPaintOpen_TYPE 114u
/* @typeInfo(app_gui.PaintOpen).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkGuiType115 { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiType115;
#define R4SdkGuiType115_TYPE 115u
/* app_gui.PaintContext; native size 64, alignment 8. */
typedef struct R4SdkGuiPaintContext { _Alignas(8) uint8_t opaque_bytes[64]; } R4SdkGuiPaintContext;
#define R4SdkGuiPaintContext_TYPE 116u
/* app_gui.Window; native size 88, alignment 8. */
typedef struct R4SdkGuiWindow { _Alignas(8) uint8_t opaque_bytes[88]; } R4SdkGuiWindow;
#define R4SdkGuiWindow_TYPE 117u
/* gui_shapes.Point; native size 8, alignment 4. */
typedef struct R4SdkGuiShapePoint { _Alignas(4) uint8_t opaque_bytes[8]; } R4SdkGuiShapePoint;
#define R4SdkGuiShapePoint_TYPE 118u
/* gui_shapes.FillRule; native size 1, alignment 1. */
typedef struct R4SdkGuiShapeFillRule { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiShapeFillRule;
#define R4SdkGuiShapeFillRule_TYPE 119u
/* gui_shapes.LineJoin; native size 1, alignment 1. */
typedef struct R4SdkGuiShapeLineJoin { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiShapeLineJoin;
#define R4SdkGuiShapeLineJoin_TYPE 120u
/* gui_shapes.LineCap; native size 1, alignment 1. */
typedef struct R4SdkGuiShapeLineCap { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkGuiShapeLineCap;
#define R4SdkGuiShapeLineCap_TYPE 121u
/* gui_shapes.Clip; native size 16, alignment 4. */
typedef struct R4SdkGuiShapeClip { _Alignas(4) uint8_t opaque_bytes[16]; } R4SdkGuiShapeClip;
#define R4SdkGuiShapeClip_TYPE 122u
/* gui_shapes.Shadow; native size 24, alignment 4. */
typedef struct R4SdkGuiShapeShadow { _Alignas(4) uint8_t opaque_bytes[24]; } R4SdkGuiShapeShadow;
#define R4SdkGuiShapeShadow_TYPE 123u
/* gui_shapes.PathStyle; native size 60, alignment 4. */
typedef struct R4SdkGuiShapePathStyle { _Alignas(4) uint8_t opaque_bytes[60]; } R4SdkGuiShapePathStyle;
#define R4SdkGuiShapePathStyle_TYPE 124u
/* gui_shapes.Radii; native size 32, alignment 4. */
typedef struct R4SdkGuiShapeRadii { _Alignas(4) uint8_t opaque_bytes[32]; } R4SdkGuiShapeRadii;
#define R4SdkGuiShapeRadii_TYPE 125u
/* gui_shapes.Borders; native size 16, alignment 4. */
typedef struct R4SdkGuiShapeBorders { _Alignas(4) uint8_t opaque_bytes[16]; } R4SdkGuiShapeBorders;
#define R4SdkGuiShapeBorders_TYPE 126u
/* gui_shapes.RoundedRect; native size 112, alignment 4. */
typedef struct R4SdkGuiShapeRoundedRect { _Alignas(4) uint8_t opaque_bytes[112]; } R4SdkGuiShapeRoundedRect;
#define R4SdkGuiShapeRoundedRect_TYPE 127u
/* gui_shapes.PathBuilder; native size 192, alignment 8. */
typedef struct R4SdkGuiShapePathBuilder { _Alignas(8) uint8_t opaque_bytes[192]; } R4SdkGuiShapePathBuilder;
#define R4SdkGuiShapePathBuilder_TYPE 128u
/* error{BufferTooSmall,InvalidValue,SegmentLimit}![]const u8; native size 24, alignment 8. */
typedef struct R4SdkGuiType130 { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiType130;
#define R4SdkGuiType130_TYPE 130u
/* error{BufferTooSmall,InvalidValue,SegmentLimit}!abi_generated.GuiFrameCommand; native size 104, alignment 8. */
typedef struct R4SdkGuiType131 { _Alignas(8) uint8_t opaque_bytes[104]; } R4SdkGuiType131;
#define R4SdkGuiType131_TYPE 131u
/* chart.PieSlice; native size 16, alignment 8. */
typedef struct R4SdkGuiChartPieSlice { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiChartPieSlice;
#define R4SdkGuiChartPieSlice_TYPE 132u
/* chart.PieSegment; native size 24, alignment 8. */
typedef struct R4SdkGuiChartPieSegment { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiChartPieSegment;
#define R4SdkGuiChartPieSegment_TYPE 133u
/* chart.PieSummary; native size 24, alignment 8. */
typedef struct R4SdkGuiChartPieSummary { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkGuiChartPieSummary;
#define R4SdkGuiChartPieSummary_TYPE 134u
/* []const chart.PieSlice; native size 16, alignment 8. */
typedef struct R4SdkGuiType135 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType135;
#define R4SdkGuiType135_TYPE 135u
/* []chart.PieSegment; native size 16, alignment 8. */
typedef struct R4SdkGuiType136 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType136;
#define R4SdkGuiType136_TYPE 136u
/* error{BadImage,NoSlices,OutputTooSmall,Overflow,ZeroTotal}!chart.PieSummary; native size 32, alignment 8. */
typedef struct R4SdkGuiType137 { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkGuiType137;
#define R4SdkGuiType137_TYPE 137u
/* []u32; native size 16, alignment 8. */
typedef struct R4SdkGuiType138 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType138;
#define R4SdkGuiType138_TYPE 138u
/* []const chart.PieSegment; native size 16, alignment 8. */
typedef struct R4SdkGuiType139 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType139;
#define R4SdkGuiType139_TYPE 139u
/* error{BadImage,NoSlices,OutputTooSmall,Overflow,ZeroTotal}!void; native size 2, alignment 2. */
typedef struct R4SdkGuiType140 { _Alignas(2) uint8_t opaque_bytes[2]; } R4SdkGuiType140;
#define R4SdkGuiType140_TYPE 140u
/* clipboard.ReadResult; native size 32, alignment 8. */
typedef struct R4SdkGuiClipboardReadResult { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkGuiClipboardReadResult;
#define R4SdkGuiClipboardReadResult_TYPE 142u
/* *const program.Context; native size 8, alignment 8. */
typedef struct R4SdkGuiType143 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType143;
#define R4SdkGuiType143_TYPE 143u
/* program.Context; native size 8, alignment 8. */
typedef struct R4SdkGuiProgramContext { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiProgramContext;
#define R4SdkGuiProgramContext_TYPE 144u
/* ?abi_generated.ConsoleInputEvent; native size 20, alignment 4. */
typedef struct R4SdkGuiType145 { _Alignas(4) uint8_t opaque_bytes[20]; } R4SdkGuiType145;
#define R4SdkGuiType145_TYPE 145u
/* []abi_generated.ConsoleInputEvent; native size 16, alignment 8. */
typedef struct R4SdkGuiType147 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType147;
#define R4SdkGuiType147_TYPE 147u
/* ?input_events.Queue([]abi_generated.ConsoleInputEvent); native size 40, alignment 8. */
typedef struct R4SdkGuiType148 { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkGuiType148;
#define R4SdkGuiType148_TYPE 148u
/* input_events.Queue([]abi_generated.ConsoleInputEvent); native size 32, alignment 8. */
typedef struct R4SdkGuiInputQueue { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkGuiInputQueue;
#define R4SdkGuiInputQueue_TYPE 149u
/* window_mode.Mode; native size 4, alignment 4. */
typedef struct R4SdkGuiWindowModeMode { _Alignas(4) uint8_t opaque_bytes[4]; } R4SdkGuiWindowModeMode;
#define R4SdkGuiWindowModeMode_TYPE 150u
/* window_mode.Client; native size 224, alignment 8. */
typedef struct R4SdkGuiWindowModeClient { _Alignas(8) uint8_t opaque_bytes[224]; } R4SdkGuiWindowModeClient;
#define R4SdkGuiWindowModeClient_TYPE 151u
/* ?abi_generated.WindowModeRequest; native size 96, alignment 8. */
typedef struct R4SdkGuiType154 { _Alignas(8) uint8_t opaque_bytes[96]; } R4SdkGuiType154;
#define R4SdkGuiType154_TYPE 154u
/* *const abi_generated.WindowModeReply; native size 8, alignment 8. */
typedef struct R4SdkGuiType157 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType157;
#define R4SdkGuiType157_TYPE 157u
/* gui_session_support.Session; native size 712, alignment 8. */
typedef struct R4SdkGuiSession { _Alignas(8) uint8_t opaque_bytes[712]; } R4SdkGuiSession;
#define R4SdkGuiSession_TYPE 158u
/* *gui.FocusState; native size 8, alignment 8. */
typedef struct R4SdkGuiType159 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType159;
#define R4SdkGuiType159_TYPE 159u
/* []const gui.FocusItem; native size 16, alignment 8. */
typedef struct R4SdkGuiType160 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType160;
#define R4SdkGuiType160_TYPE 160u
/* *gui.MouseCapture; native size 8, alignment 8. */
typedef struct R4SdkGuiType161 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType161;
#define R4SdkGuiType161_TYPE 161u
/* *gui.LayoutCursor; native size 8, alignment 8. */
typedef struct R4SdkGuiType162 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType162;
#define R4SdkGuiType162_TYPE 162u
/* *gui.HostedAppFrame; native size 8, alignment 8. */
typedef struct R4SdkGuiType163 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType163;
#define R4SdkGuiType163_TYPE 163u
/* []const u32; native size 16, alignment 8. */
typedef struct R4SdkGuiType164 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType164;
#define R4SdkGuiType164_TYPE 164u
/* []const abi_generated.DisplayDamageRect; native size 16, alignment 8. */
typedef struct R4SdkGuiType165 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType165;
#define R4SdkGuiType165_TYPE 165u
/* []const abi_generated.GuiFrameCommand; native size 16, alignment 8. */
typedef struct R4SdkGuiType167 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType167;
#define R4SdkGuiType167_TYPE 167u
/* ?*const abi_generated.ProgramProcessHandle; native size 8, alignment 8. */
typedef struct R4SdkGuiType168 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType168;
#define R4SdkGuiType168_TYPE 168u
/* *const abi_generated.ProgramProcessHandle; native size 8, alignment 8. */
typedef struct R4SdkGuiType169 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType169;
#define R4SdkGuiType169_TYPE 169u
/* *abi_generated.GuiFrameInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType170 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType170;
#define R4SdkGuiType170_TYPE 170u
/* *abi_generated.GuiFrameGenerationInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType172 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType172;
#define R4SdkGuiType172_TYPE 172u
/* []abi_generated.DisplayDamageRect; native size 16, alignment 8. */
typedef struct R4SdkGuiType174 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType174;
#define R4SdkGuiType174_TYPE 174u
/* *abi_generated.GuiFrameStreamInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType175 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType175;
#define R4SdkGuiType175_TYPE 175u
/* *const abi_generated.GuiSharedRasterCreateInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType177 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType177;
#define R4SdkGuiType177_TYPE 177u
/* *abi_generated.GuiSharedRasterHandle; native size 8, alignment 8. */
typedef struct R4SdkGuiType179 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType179;
#define R4SdkGuiType179_TYPE 179u
/* *const abi_generated.GuiSharedRasterHandle; native size 8, alignment 8. */
typedef struct R4SdkGuiType181 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType181;
#define R4SdkGuiType181_TYPE 181u
/* *abi_generated.GuiSharedRasterWriteMap; native size 8, alignment 8. */
typedef struct R4SdkGuiType182 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType182;
#define R4SdkGuiType182_TYPE 182u
/* *const abi_generated.GuiSharedRasterWriteMap; native size 8, alignment 8. */
typedef struct R4SdkGuiType184 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType184;
#define R4SdkGuiType184_TYPE 184u
/* *u64; native size 8, alignment 8. */
typedef struct R4SdkGuiType185 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType185;
#define R4SdkGuiType185_TYPE 185u
/* *abi_generated.GuiSharedRasterMap; native size 8, alignment 8. */
typedef struct R4SdkGuiType186 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType186;
#define R4SdkGuiType186_TYPE 186u
/* *const abi_generated.GuiSharedRasterLease; native size 8, alignment 8. */
typedef struct R4SdkGuiType188 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType188;
#define R4SdkGuiType188_TYPE 188u
/* *abi_generated.GuiFontInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType190 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType190;
#define R4SdkGuiType190_TYPE 190u
/* *abi_generated.GuiTextMetrics; native size 8, alignment 8. */
typedef struct R4SdkGuiType192 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType192;
#define R4SdkGuiType192_TYPE 192u
/* *abi_generated.GuiGlyphBitmap; native size 8, alignment 8. */
typedef struct R4SdkGuiType194 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType194;
#define R4SdkGuiType194_TYPE 194u
/* *gui.MenubarState; native size 8, alignment 8. */
typedef struct R4SdkGuiType196 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType196;
#define R4SdkGuiType196_TYPE 196u
/* *gui.DialogState; native size 8, alignment 8. */
typedef struct R4SdkGuiType197 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType197;
#define R4SdkGuiType197_TYPE 197u
/* *const gui.TextArea([]u8); native size 8, alignment 8. */
typedef struct R4SdkGuiType198 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType198;
#define R4SdkGuiType198_TYPE 198u
/* *gui.TextArea([]u8); native size 8, alignment 8. */
typedef struct R4SdkGuiType199 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType199;
#define R4SdkGuiType199_TYPE 199u
/* *const gui.TextField([]u8); native size 8, alignment 8. */
typedef struct R4SdkGuiType200 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType200;
#define R4SdkGuiType200_TYPE 200u
/* *gui.TextField([]u8); native size 8, alignment 8. */
typedef struct R4SdkGuiType201 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType201;
#define R4SdkGuiType201_TYPE 201u
/* gui.TextField([]u8).selectionRange__struct_; native size 16, alignment 8. */
typedef struct R4SdkGuiType202 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType202;
#define R4SdkGuiType202_TYPE 202u
/* *abi_generated.Mouse; native size 8, alignment 8. */
typedef struct R4SdkGuiType203 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType203;
#define R4SdkGuiType203_TYPE 203u
/* *abi_generated.MouseMotion; native size 8, alignment 8. */
typedef struct R4SdkGuiType205 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType205;
#define R4SdkGuiType205_TYPE 205u
/* *abi_generated.RemoteFrameInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType207 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType207;
#define R4SdkGuiType207_TYPE 207u
/* *abi_generated.RemoteFrameLease; native size 8, alignment 8. */
typedef struct R4SdkGuiType209 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType209;
#define R4SdkGuiType209_TYPE 209u
/* *const abi_generated.RemoteFrameLease; native size 8, alignment 8. */
typedef struct R4SdkGuiType211 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType211;
#define R4SdkGuiType211_TYPE 211u
/* *abi_generated.RemoteFrameCaptureStats; native size 8, alignment 8. */
typedef struct R4SdkGuiType212 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType212;
#define R4SdkGuiType212_TYPE 212u
/* *abi_generated.KeyboardLayoutInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType214 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType214;
#define R4SdkGuiType214_TYPE 214u
/* *abi_generated.ProgramProcessHandle; native size 8, alignment 8. */
typedef struct R4SdkGuiType218 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType218;
#define R4SdkGuiType218_TYPE 218u
/* *abi_generated.ProgramHostLaunchRequest; native size 8, alignment 8. */
typedef struct R4SdkGuiType219 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType219;
#define R4SdkGuiType219_TYPE 219u
/* *abi_generated.GuiWindowInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType221 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType221;
#define R4SdkGuiType221_TYPE 221u
/* *const abi_generated.GuiWindowInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType222 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType222;
#define R4SdkGuiType222_TYPE 222u
/* *const abi_generated.GuiEvent; native size 8, alignment 8. */
typedef struct R4SdkGuiType223 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType223;
#define R4SdkGuiType223_TYPE 223u
/* *abi_generated.GuiCommand; native size 8, alignment 8. */
typedef struct R4SdkGuiType224 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType224;
#define R4SdkGuiType224_TYPE 224u
/* *abi_generated.GuiSize; native size 8, alignment 8. */
typedef struct R4SdkGuiType226 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType226;
#define R4SdkGuiType226_TYPE 226u
/* *abi_generated.ConsoleState; native size 8, alignment 8. */
typedef struct R4SdkGuiType228 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType228;
#define R4SdkGuiType228_TYPE 228u
/* *abi_generated.PhysicalKeyEvent; native size 8, alignment 8. */
typedef struct R4SdkGuiType231 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType231;
#define R4SdkGuiType231_TYPE 231u
/* *abi_generated.ClipboardInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType233 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType233;
#define R4SdkGuiType233_TYPE 233u
/* *abi_generated.RemoteFrameMapInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType234 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType234;
#define R4SdkGuiType234_TYPE 234u
/* *const abi_generated.RemoteFrameInfo; native size 8, alignment 8. */
typedef struct R4SdkGuiType236 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType236;
#define R4SdkGuiType236_TYPE 236u
/* *const abi_generated.RemoteInputEvent; native size 8, alignment 8. */
typedef struct R4SdkGuiType237 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType237;
#define R4SdkGuiType237_TYPE 237u
/* *abi_generated.RemoteInputEvent; native size 8, alignment 8. */
typedef struct R4SdkGuiType239 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType239;
#define R4SdkGuiType239_TYPE 239u
/* *abi_generated.RemoteInputStatus; native size 8, alignment 8. */
typedef struct R4SdkGuiType240 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType240;
#define R4SdkGuiType240_TYPE 240u
/* ?abi_generated.GuiEvent; native size 48, alignment 8. */
typedef struct R4SdkGuiType242 { _Alignas(8) uint8_t opaque_bytes[48]; } R4SdkGuiType242;
#define R4SdkGuiType242_TYPE 242u
/* *app_gui.Timer; native size 8, alignment 8. */
typedef struct R4SdkGuiType243 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType243;
#define R4SdkGuiType243_TYPE 243u
/* *app_gui.EventLoop; native size 8, alignment 8. */
typedef struct R4SdkGuiType245 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType245;
#define R4SdkGuiType245_TYPE 245u
/* ?app_gui.Message; native size 56, alignment 8. */
typedef struct R4SdkGuiType246 { _Alignas(8) uint8_t opaque_bytes[56]; } R4SdkGuiType246;
#define R4SdkGuiType246_TYPE 246u
/* *app_gui.PaintContext; native size 8, alignment 8. */
typedef struct R4SdkGuiType248 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType248;
#define R4SdkGuiType248_TYPE 248u
/* ?app_gui.Window; native size 96, alignment 8. */
typedef struct R4SdkGuiType249 { _Alignas(8) uint8_t opaque_bytes[96]; } R4SdkGuiType249;
#define R4SdkGuiType249_TYPE 249u
/* *app_gui.Window; native size 8, alignment 8. */
typedef struct R4SdkGuiType250 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType250;
#define R4SdkGuiType250_TYPE 250u
/* ?abi_generated.GuiWindowInfo; native size 44, alignment 4. */
typedef struct R4SdkGuiType251 { _Alignas(4) uint8_t opaque_bytes[44]; } R4SdkGuiType251;
#define R4SdkGuiType251_TYPE 251u
/* error{BufferTooSmall,InvalidValue,SegmentLimit}!gui_shapes.PathBuilder; native size 200, alignment 8. */
typedef struct R4SdkGuiType252 { _Alignas(8) uint8_t opaque_bytes[200]; } R4SdkGuiType252;
#define R4SdkGuiType252_TYPE 252u
/* *gui_shapes.PathBuilder; native size 8, alignment 8. */
typedef struct R4SdkGuiType253 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType253;
#define R4SdkGuiType253_TYPE 253u
/* error{BufferTooSmall,InvalidValue,SegmentLimit}!void; native size 2, alignment 2. */
typedef struct R4SdkGuiType254 { _Alignas(2) uint8_t opaque_bytes[2]; } R4SdkGuiType254;
#define R4SdkGuiType254_TYPE 254u
/* *input_events.Queue([]abi_generated.ConsoleInputEvent); native size 8, alignment 8. */
typedef struct R4SdkGuiType255 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType255;
#define R4SdkGuiType255_TYPE 255u
/* []const abi_generated.ConsoleInputEvent; native size 16, alignment 8. */
typedef struct R4SdkGuiType256 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkGuiType256;
#define R4SdkGuiType256_TYPE 256u
/* *const input_events.Queue([]abi_generated.ConsoleInputEvent); native size 8, alignment 8. */
typedef struct R4SdkGuiType257 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType257;
#define R4SdkGuiType257_TYPE 257u
/* *window_mode.Client; native size 8, alignment 8. */
typedef struct R4SdkGuiType258 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkGuiType258;
#define R4SdkGuiType258_TYPE 258u
#define R4SdkGui_ABI_FINGERPRINT UINT64_C(12818536255166343991)
int32_t R4SdkGuiVerifyAbi(uint64_t);
#define R4SdkGui_font_w (8)
#define R4SdkGui_font_h (8)
#define R4SdkGuiChart_turns_per_circle (65536)
#define R4SdkGuiClipboard_max_text_bytes (4095)
#define R4SdkGuiEventKind_close 1u
#define R4SdkGuiEventKind_resize 2u
#define R4SdkGuiEventKind_key 3u
#define R4SdkGuiEventKind_mouse_down 4u
#define R4SdkGuiEventKind_mouse_up 5u
#define R4SdkGuiEventKind_mouse_move 6u
#define R4SdkGuiEventKind_command 7u
#define R4SdkGuiEventKind_clipboard 8u
#define R4SdkGuiEventKind_timer 9u
#define R4SdkGuiEventKind_unknown 10u
#define R4SdkGuiAlign_left 0u
#define R4SdkGuiAlign_center 1u
#define R4SdkGuiAlign_right 2u
#define R4SdkGuiKey_ctrl_a (1)
#define R4SdkGuiKey_ctrl_c (3)
#define R4SdkGuiKey_ctrl_v (22)
#define R4SdkGuiKey_ctrl_x (24)
#define R4SdkGuiKey_backspace (8)
#define R4SdkGuiKey_tab (9)
#define R4SdkGuiKey_enter (13)
#define R4SdkGuiKey_escape (27)
#define R4SdkGuiKey_delete (127)
#define R4SdkGuiKey_up (128)
#define R4SdkGuiKey_down (129)
#define R4SdkGuiKey_f3 (130)
#define R4SdkGuiKey_shift_tab (132)
#define R4SdkGuiKey_left (136)
#define R4SdkGuiKey_right (137)
#define R4SdkGuiKey_home (138)
#define R4SdkGuiKey_end (139)
#define R4SdkGuiKey_start_menu (140)
#define R4SdkGuiKey_page_up (141)
#define R4SdkGuiKey_page_down (142)
#define R4SdkGuiKey_menu_focus (143)
#define R4SdkGuiKey_f10 (144)
#define R4SdkGuiControlAction_none 0u
#define R4SdkGuiControlAction_clicked 1u
#define R4SdkGuiControlAction_changed 2u
#define R4SdkGuiControlAction_submitted 3u
#define R4SdkGuiControlAction_cancelled 4u
#define R4SdkGuiControlAction_selection_changed 5u
#define R4SdkGuiFocusDirection_next 0u
#define R4SdkGuiFocusDirection_previous 1u
#define R4SdkGuiMenubarHitPart_none 0u
#define R4SdkGuiMenubarHitPart_header 1u
#define R4SdkGuiMenubarHitPart_item 2u
#define R4SdkGuiMenubarHitPart_backdrop 3u
#define R4SdkGuiButtonState_normal 0u
#define R4SdkGuiButtonState_hover 1u
#define R4SdkGuiButtonState_pressed 2u
#define R4SdkGuiButtonState_disabled 3u
#define R4SdkGuiOrientation_vertical 0u
#define R4SdkGuiOrientation_horizontal 1u
#define R4SdkGuiScrollbarPart_none 0u
#define R4SdkGuiScrollbarPart_decrement 1u
#define R4SdkGuiScrollbarPart_increment 2u
#define R4SdkGuiScrollbarPart_page_decrement 3u
#define R4SdkGuiScrollbarPart_page_increment 4u
#define R4SdkGuiScrollbarPart_thumb 5u
#define R4SdkGuiDialogAction_none 0u
#define R4SdkGuiDialogAction_ok 1u
#define R4SdkGuiDialogAction_cancel 2u
#define R4SdkGuiDialogAction_select 3u
#define R4SdkGuiDialogAction_previous 4u
#define R4SdkGuiDialogAction_next 5u
#define R4SdkGuiDialogAction_yes 6u
#define R4SdkGuiDialogAction_no 7u
#define R4SdkGuiDialogButtonRole_normal 0u
#define R4SdkGuiDialogButtonRole_default 1u
#define R4SdkGuiDialogButtonRole_cancel 2u
#define R4SdkGuiDialogButtonAlign_center 0u
#define R4SdkGuiDialogButtonAlign_right 1u
#define R4SdkGuiModalHitPart_none 0u
#define R4SdkGuiModalHitPart_backdrop 1u
#define R4SdkGuiModalHitPart_frame 2u
#define R4SdkGuiModalHitPart_title 3u
#define R4SdkGuiModalHitPart_content 4u
#define R4SdkGuiModalHitPart_button 5u
#define R4SdkGuiMessageKind_info 0u
#define R4SdkGuiMessageKind_warning 1u
#define R4SdkGuiMessageKind_failure 2u
#define R4SdkGuiMessageKind_question 3u
#define R4SdkGuiMessageButtons_ok 0u
#define R4SdkGuiMessageButtons_ok_cancel 1u
#define R4SdkGuiMessageButtons_yes_no 2u
#define R4SdkGuiFileDialogMode_open 0u
#define R4SdkGuiFileDialogMode_save 1u
#define R4SdkGuiMouseAction_down 0u
#define R4SdkGuiMouseAction_up 1u
#define R4SdkGuiMouseAction_move 2u
#define R4SdkGuiType107_close 0u
#define R4SdkGuiType107_resize 1u
#define R4SdkGuiType107_key 2u
#define R4SdkGuiType107_mouse 3u
#define R4SdkGuiType107_command 4u
#define R4SdkGuiType107_clipboard 5u
#define R4SdkGuiType107_timer 6u
#define R4SdkGuiType107_unknown 7u
#define R4SdkGuiType109_message 0u
#define R4SdkGuiType109_timed_out 1u
#define R4SdkGuiType109_failure 2u
#define R4SdkGuiType115_paint 0u
#define R4SdkGuiType115_failure 1u
#define R4SdkGuiShapeFillRule_nonzero 0u
#define R4SdkGuiShapeFillRule_evenodd 1u
#define R4SdkGuiShapeLineJoin_miter 0u
#define R4SdkGuiShapeLineJoin_round 1u
#define R4SdkGuiShapeLineJoin_bevel 2u
#define R4SdkGuiShapeLineCap_butt 0u
#define R4SdkGuiShapeLineCap_round 1u
#define R4SdkGuiShapeLineCap_square 2u
#define R4SdkGuiWindowModeMode_windowed 0u
#define R4SdkGuiWindowModeMode_fullscreen 1u
/* Session storage must stay at this address until Close. Open initializes
 * caller-owned timers. role=0 is a hosted app, role=1 an independent host.
 * HostReset closes only the endpoint; the WindowService binding remains
 * tied to the exact live process. Reopening is explicit, without retries. */
typedef struct R4SdkGuiEvent {
 uint32_t kind;
 int32_t window_id;
 int32_t width;
 int32_t height;
 int32_t x;
 int32_t y;
 uint32_t codepoint;
 uint32_t modifiers;
 uint32_t buttons;
 uint32_t id;
 uint32_t revision;
 uint32_t reserved;
 uint64_t tick;
 R4GuiEvent raw;
} R4SdkGuiEvent;
int32_t R4SdkGuiSessionOpenNative(uint64_t,R4SdkGuiSession *,const R4XStartContext *,uint32_t,R4SdkGuiTimer *,uintptr_t);
static inline int32_t R4SdkGuiSessionOpen(R4SdkGuiSession *s,const R4XStartContext *ctx,uint32_t role,R4SdkGuiTimer *timers,uintptr_t count) { return R4SdkGuiSessionOpenNative(R4SdkGui_ABI_FINGERPRINT,s,ctx,role,timers,count); }
void R4SdkGuiSessionClose(R4SdkGuiSession *);
R4SdkGuiProgramContext *R4SdkGuiSessionProgram(R4SdkGuiSession *);
R4SdkGuiSystemContext *R4SdkGuiSessionSystem(R4SdkGuiSession *);
R4SdkGuiDesktopContext *R4SdkGuiSessionDesktop(R4SdkGuiSession *);
R4SdkGuiDrawContext *R4SdkGuiSessionDraw(R4SdkGuiSession *);
R4SdkGuiWindow *R4SdkGuiSessionWindow(R4SdkGuiSession *);
R4SdkGuiCanvas *R4SdkGuiSessionCanvas(R4SdkGuiSession *);
int32_t R4SdkGuiSessionBegin(R4SdkGuiSession *,R4GuiFrameCommand *,uintptr_t,uint8_t *,uintptr_t);
int32_t R4SdkGuiSessionEnd(R4SdkGuiSession *,uint32_t);
int32_t R4SdkGuiSessionNext(R4SdkGuiSession *,const R4Timeout *,R4SdkGuiEvent *);
int32_t R4SdkGuiSessionTimer(R4SdkGuiSession *,uintptr_t,uint32_t,const R4Duration *,uint32_t);
int32_t R4SdkGuiSessionCancelTimer(R4SdkGuiSession *,uintptr_t);
int32_t R4SdkGuiSessionCommand(R4SdkGuiSession *,uint32_t);
int32_t R4SdkGuiSessionMode(R4SdkGuiSession *,uint32_t,uint32_t,R4WindowModeReply *);
int32_t R4SdkGuiSessionHostClaim(R4SdkGuiSession *,R4TrayDesktopExchange *,const R4Timeout *);
int32_t R4SdkGuiSessionHostExchange(R4SdkGuiSession *,uint16_t,const R4TrayDesktopExchange *,R4TrayDesktopExchange *,const R4Timeout *);
void R4SdkGuiSessionHostReset(R4SdkGuiSession *);
/* gui.borrowedTextArea -> ?gui.TextArea([]u8) */
static inline R4SdkGuiSlot R4SdkGui_borrowedTextArea(uint32_t reserved, uint8_t * p0, uintptr_t n0, R4SdkGuiTextArea *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,0u,a,1u,output);
}
/* gui.borrowedTextField -> ?gui.TextField([]u8) */
static inline R4SdkGuiSlot R4SdkGui_borrowedTextField(uint32_t reserved, uint8_t * p0, uintptr_t n0, R4SdkGuiTextField *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,1u,a,1u,output);
}
/* gui.hostedAppFrame -> gui.HostedAppFrame */
static inline R4SdkGuiSlot R4SdkGui_hostedAppFrame(uint32_t reserved, const R4SdkGuiSystemContext * p0, const R4SdkGuiDesktopContext * p1, const R4SdkGuiDrawContext * p2, int32_t p3, int32_t p4, R4SdkGuiHostedAppFrame *output) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,2u,a,5u,output);
}
/* gui.pollHostedEvent -> ?abi.GuiEventKind */
static inline R4SdkGuiSlot R4SdkGui_pollHostedEvent(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4GuiEvent * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,3u,a,2u,0);
}
/* gui.eventKey -> u8 */
static inline R4SdkGuiSlot R4SdkGui_eventKey(uint32_t reserved, const R4GuiEvent * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,4u,a,1u,0);
}
/* gui.eventCodepoint -> u32 */
static inline R4SdkGuiSlot R4SdkGui_eventCodepoint(uint32_t reserved, const R4GuiEvent * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,5u,a,1u,0);
}
/* gui.charsForWidth -> usize */
static inline R4SdkGuiSlot R4SdkGui_charsForWidth(uint32_t reserved, int32_t p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,6u,a,1u,0);
}
/* gui.textWidth -> i32 */
static inline R4SdkGuiSlot R4SdkGui_textWidth(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,7u,a,1u,0);
}
/* gui.copyEllipsized -> []const u8 */
static inline R4SdkGuiSlot R4SdkGui_copyEllipsized(uint32_t reserved, uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,8u,a,3u,0);
}
/* gui.copyEllipsizedForCanvas -> []const u8 */
static inline R4SdkGuiSlot R4SdkGui_copyEllipsizedForCanvas(uint32_t reserved, const R4SdkGuiCanvas * p0, uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, int32_t p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,9u,a,4u,0);
}
/* gui.spanZ -> []const u8 */
static inline R4SdkGuiSlot R4SdkGui_spanZ(uint32_t reserved, const uint8_t * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,10u,a,1u,0);
}
/* gui.textAreaClientRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_textAreaClientRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,11u,a,1u,output);
}
/* gui.textAreaViewForRect -> gui.TextAreaView */
static inline R4SdkGuiSlot R4SdkGui_textAreaViewForRect(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, R4SdkGuiTextAreaView *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,12u,a,2u,output);
}
/* gui.textAreaVisualPoint -> gui.TextAreaPoint */
static inline R4SdkGuiSlot R4SdkGui_textAreaVisualPoint(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1, uint64_t p2, R4SdkGuiTextAreaPoint *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,13u,a,3u,output);
}
/* gui.textAreaIndexForVisualPosition -> usize */
static inline R4SdkGuiSlot R4SdkGui_textAreaIndexForVisualPosition(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1, uint64_t p2, uint64_t p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,14u,a,4u,0);
}
/* gui.textAreaVisualLineRange -> gui.TextRange */
static inline R4SdkGuiSlot R4SdkGui_textAreaVisualLineRange(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1, uint64_t p2, R4SdkGuiTextRange *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,15u,a,3u,output);
}
/* gui.textAreaVisualLineCount -> usize */
static inline R4SdkGuiSlot R4SdkGui_textAreaVisualLineCount(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,16u,a,2u,0);
}
/* gui.textAreaLayout -> gui.TextAreaLayout */
static inline R4SdkGuiSlot R4SdkGui_textAreaLayout(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, R4SdkGuiTextAreaLayout *output) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,17u,a,5u,output);
}
/* gui.textAreaVisualMaxColumns -> usize */
static inline R4SdkGuiSlot R4SdkGui_textAreaVisualMaxColumns(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint64_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,18u,a,2u,0);
}
/* gui.drawTextInRect -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawTextInRect(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint32_t p4, uint32_t p5, uint32_t p6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,19u,a,7u,0);
}
/* gui.drawButton -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawButton(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint32_t p4, const R4SdkGuiPalette * p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,20u,a,6u,0);
}
/* gui.drawButtonEx -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawButtonEx(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint32_t p4, uint8_t p5, uint8_t p6, uint8_t p7, const R4SdkGuiPalette * p8) {
 (void)reserved; R4SdkGuiSlot a[9]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.ptr=(void *)p8,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,21u,a,9u,0);
}
/* gui.buttonMinWidth -> i32 */
static inline R4SdkGuiSlot R4SdkGui_buttonMinWidth(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,22u,a,1u,0);
}
/* gui.drawTextField -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawTextField(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint8_t p4, uint8_t p5, const R4SdkGuiPalette * p6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,23u,a,7u,0);
}
/* gui.drawTextArea -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawTextArea(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint8_t p4, uint8_t p5, const R4SdkGuiPalette * p6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,24u,a,7u,0);
}
/* gui.drawTextAreaEx -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawTextAreaEx(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint64_t p4, const R4SdkGuiTextRange * p5, uint64_t p6, uint64_t p7, uint8_t p8, uint8_t p9, const R4SdkGuiPalette * p10) {
 (void)reserved; R4SdkGuiSlot a[11]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDK_GUI_PRESENT};
 a[10] = (R4SdkGuiSlot){.ptr=(void *)p10,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,25u,a,11u,0);
}
/* gui.drawTextAreaExWithWrap -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawTextAreaExWithWrap(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint64_t p4, const R4SdkGuiTextRange * p5, uint64_t p6, uint64_t p7, uint8_t p8, uint8_t p9, uint8_t p10, const R4SdkGuiPalette * p11) {
 (void)reserved; R4SdkGuiSlot a[12]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDK_GUI_PRESENT};
 a[10] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4SDK_GUI_PRESENT};
 a[11] = (R4SdkGuiSlot){.ptr=(void *)p11,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,26u,a,12u,0);
}
/* gui.drawTextAreaWithLayout -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawTextAreaWithLayout(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const R4SdkGuiTextRange * p4, uint64_t p5, uint8_t p6, uint8_t p7, const R4SdkGuiPalette * p8, const R4SdkGuiTextAreaLayout * p9) {
 (void)reserved; R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.ptr=(void *)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.ptr=(void *)p9,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,27u,a,10u,0);
}
/* gui.drawCheckbox -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawCheckbox(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint8_t p4, uint8_t p5, uint8_t p6, const R4SdkGuiPalette * p7) {
 (void)reserved; R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,28u,a,8u,0);
}
/* gui.drawRadioButton -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawRadioButton(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint8_t p4, uint8_t p5, uint8_t p6, const R4SdkGuiPalette * p7) {
 (void)reserved; R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,29u,a,8u,0);
}
/* gui.drawGroupBox -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawGroupBox(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const R4SdkGuiPalette * p4) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,30u,a,5u,0);
}
/* gui.drawSeparator -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawSeparator(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t p2, const R4SdkGuiPalette * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,31u,a,4u,0);
}
/* gui.drawDropdown -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawDropdown(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const R4SdkGuiType35 * p3, uintptr_t n3, uint64_t p4, R4SdkGuiSlot p5, uint8_t p6, uint8_t p7, uint8_t p8, const R4SdkGuiPalette * p9) {
 (void)reserved; R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = p5;
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.ptr=(void *)p9,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,32u,a,10u,0);
}
/* gui.drawDropdownEx -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawDropdownEx(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const R4SdkGuiType35 * p3, uintptr_t n3, uint64_t p4, R4SdkGuiSlot p5, uint64_t p6, uint64_t p7, uint8_t p8, uint8_t p9, uint8_t p10, const R4SdkGuiPalette * p11) {
 (void)reserved; R4SdkGuiSlot a[12]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = p5;
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDK_GUI_PRESENT};
 a[10] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4SDK_GUI_PRESENT};
 a[11] = (R4SdkGuiSlot){.ptr=(void *)p11,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,33u,a,12u,0);
}
/* gui.drawList -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawList(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const R4SdkGuiType35 * p3, uintptr_t n3, uint64_t p4, int32_t p5, const R4SdkGuiPalette * p6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,34u,a,7u,0);
}
/* gui.drawListEx -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawListEx(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const R4SdkGuiType35 * p3, uintptr_t n3, uint64_t p4, R4SdkGuiSlot p5, uint64_t p6, R4SdkGuiSlot p7, int32_t p8, const R4SdkGuiPalette * p9) {
 (void)reserved; R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = p5;
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = p7;
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.ptr=(void *)p9,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,35u,a,10u,0);
}
/* gui.drawScrollbar -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawScrollbar(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiScrollbar * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,36u,a,3u,0);
}
/* gui.drawToolbarButton -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawToolbarButton(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint32_t p4, uint8_t p5, uint8_t p6, const R4SdkGuiPalette * p7) {
 (void)reserved; R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,37u,a,8u,0);
}
/* gui.drawTabBar -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawTabBar(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiTabBar * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,38u,a,3u,0);
}
/* gui.drawTableView -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawTableView(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiTableView * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,39u,a,3u,0);
}
/* gui.listIndexAt -> ?usize */
static inline R4SdkGuiSlot R4SdkGui_listIndexAt(uint32_t reserved, const R4SdkGuiRect * p0, uint64_t p1, int32_t p2, int32_t p3, int32_t p4) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,40u,a,5u,0);
}
/* gui.listIndexAtEx -> ?usize */
static inline R4SdkGuiSlot R4SdkGui_listIndexAtEx(uint32_t reserved, const R4SdkGuiRect * p0, uint64_t p1, uint64_t p2, R4SdkGuiSlot p3, int32_t p4, int32_t p5, int32_t p6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = p3;
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,41u,a,7u,0);
}
/* gui.visibleListRows -> usize */
static inline R4SdkGuiSlot R4SdkGui_visibleListRows(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,42u,a,2u,0);
}
/* gui.listFirstIndexForSelection -> usize */
static inline R4SdkGuiSlot R4SdkGui_listFirstIndexForSelection(uint32_t reserved, uint64_t p0, uint64_t p1, uint64_t p2, uint64_t p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,43u,a,4u,0);
}
/* gui.selectionStep -> gui.SelectionStep */
static inline R4SdkGuiSlot R4SdkGui_selectionStep(uint32_t reserved, uint64_t p0, uint64_t p1, uint8_t p2, R4SdkGuiSelectionStep *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,44u,a,3u,output);
}
/* gui.selectionStepPaged -> gui.SelectionStep */
static inline R4SdkGuiSlot R4SdkGui_selectionStepPaged(uint32_t reserved, uint64_t p0, uint64_t p1, uint64_t p2, uint8_t p3, R4SdkGuiSelectionStep *output) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,45u,a,4u,output);
}
/* gui.drawMenu -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawMenu(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const R4SdkGuiMenuItem * p3, uintptr_t n3, R4SdkGuiSlot p4, int32_t p5, const R4SdkGuiPalette * p6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = p4;
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,46u,a,7u,0);
}
/* gui.drawMenubar -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawMenubar(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const R4SdkGuiMenubarMenu * p3, uintptr_t n3, const R4SdkGuiMenubarState * p4, const R4SdkGuiPalette * p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,47u,a,6u,0);
}
/* gui.drawMenuEx -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawMenuEx(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const R4SdkGuiMenuItem * p3, uintptr_t n3, R4SdkGuiSlot p4, R4SdkGuiSlot p5, int32_t p6, const R4SdkGuiPalette * p7) {
 (void)reserved; R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = p4;
 a[5] = p5;
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,48u,a,8u,0);
}
/* gui.menubarHeaderRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_menubarHeaderRect(uint32_t reserved, const R4SdkGuiRect * p0, const R4SdkGuiMenubarMenu * p1, uintptr_t n1, uint64_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,49u,a,3u,output);
}
/* gui.menubarPopupRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_menubarPopupRect(uint32_t reserved, const R4SdkGuiRect * p0, const R4SdkGuiMenubarMenu * p1, uintptr_t n1, uint64_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,50u,a,3u,output);
}
/* gui.menubarMenuIndexAt -> ?usize */
static inline R4SdkGuiSlot R4SdkGui_menubarMenuIndexAt(uint32_t reserved, const R4SdkGuiRect * p0, const R4SdkGuiMenubarMenu * p1, uintptr_t n1, int32_t p2, int32_t p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,51u,a,4u,0);
}
/* gui.menubarHitTest -> gui.MenubarHit */
static inline R4SdkGuiSlot R4SdkGui_menubarHitTest(uint32_t reserved, const R4SdkGuiRect * p0, const R4SdkGuiMenubarMenu * p1, uintptr_t n1, R4SdkGuiSlot p2, int32_t p3, int32_t p4, R4SdkGuiMenubarHit *output) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = p2;
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,52u,a,5u,output);
}
/* gui.menubarHeaderWidth -> i32 */
static inline R4SdkGuiSlot R4SdkGui_menubarHeaderWidth(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,53u,a,1u,0);
}
/* gui.menuPopupWidth -> i32 */
static inline R4SdkGuiSlot R4SdkGui_menuPopupWidth(uint32_t reserved, const R4SdkGuiMenuItem * p0, uintptr_t n0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,54u,a,1u,0);
}
/* gui.menuPopupHeight -> i32 */
static inline R4SdkGuiSlot R4SdkGui_menuPopupHeight(uint32_t reserved, const R4SdkGuiMenuItem * p0, uintptr_t n0, int32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,55u,a,2u,0);
}
/* gui.menuIndexAt -> ?usize */
static inline R4SdkGuiSlot R4SdkGui_menuIndexAt(uint32_t reserved, const R4SdkGuiRect * p0, const R4SdkGuiMenuItem * p1, uintptr_t n1, int32_t p2, int32_t p3, int32_t p4) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,56u,a,5u,0);
}
/* gui.menuKeyAction -> gui.MenuKeyResult */
static inline R4SdkGuiSlot R4SdkGui_menuKeyAction(uint32_t reserved, const R4SdkGuiMenuItem * p0, uintptr_t n0, R4SdkGuiSlot p1, uint8_t p2, R4SdkGuiMenuKeyResult *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = p1;
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,57u,a,3u,output);
}
/* gui.modalDialogRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_modalDialogRect(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, int32_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,58u,a,3u,output);
}
/* gui.dialogTitleRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dialogTitleRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,59u,a,1u,output);
}
/* gui.dialogContentRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dialogContentRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,60u,a,1u,output);
}
/* gui.dialogButtonBarRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dialogButtonBarRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,61u,a,1u,output);
}
/* gui.dialogStatusRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dialogStatusRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,62u,a,1u,output);
}
/* gui.dialogRowRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dialogRowRect(uint32_t reserved, const R4SdkGuiRect * p0, uint64_t p1, int32_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,63u,a,3u,output);
}
/* gui.dialogLabelRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dialogLabelRect(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,64u,a,2u,output);
}
/* gui.dialogFieldRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dialogFieldRect(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,65u,a,2u,output);
}
/* gui.dialogDropdownRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dialogDropdownRect(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,66u,a,2u,output);
}
/* gui.dialogButtonRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dialogButtonRect(uint32_t reserved, const R4SdkGuiRect * p0, uint64_t p1, uint64_t p2, uint32_t p3, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,67u,a,4u,output);
}
/* gui.dialogButtonActionAt -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGui_dialogButtonActionAt(uint32_t reserved, const R4SdkGuiRect * p0, const R4SdkGuiDialogButton * p1, uintptr_t n1, uint32_t p2, int32_t p3, int32_t p4) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,68u,a,5u,0);
}
/* gui.dialogDefaultAction -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGui_dialogDefaultAction(uint32_t reserved, const R4SdkGuiDialogButton * p0, uintptr_t n0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,69u,a,1u,0);
}
/* gui.dialogCancelAction -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGui_dialogCancelAction(uint32_t reserved, const R4SdkGuiDialogButton * p0, uintptr_t n0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,70u,a,1u,0);
}
/* gui.dialogSubmitAction -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGui_dialogSubmitAction(uint32_t reserved, const R4SdkGuiDialogButton * p0, uintptr_t n0, uint32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,71u,a,2u,0);
}
/* gui.dialogKeyAction -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGui_dialogKeyAction(uint32_t reserved, const R4SdkGuiDialogButton * p0, uintptr_t n0, uint32_t p1, uint8_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,72u,a,3u,0);
}
/* gui.dialogFirstFocusAction -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGui_dialogFirstFocusAction(uint32_t reserved, const R4SdkGuiDialogFocusItem * p0, uintptr_t n0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,73u,a,1u,0);
}
/* gui.dialogFocusIndex -> ?usize */
static inline R4SdkGuiSlot R4SdkGui_dialogFocusIndex(uint32_t reserved, const R4SdkGuiDialogFocusItem * p0, uintptr_t n0, uint32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,74u,a,2u,0);
}
/* gui.dialogFocusStep -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGui_dialogFocusStep(uint32_t reserved, const R4SdkGuiDialogFocusItem * p0, uintptr_t n0, uint32_t p1, uint32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,75u,a,3u,0);
}
/* gui.drawDialogFrame -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawDialogFrame(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const R4SdkGuiPalette * p4) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,76u,a,5u,0);
}
/* gui.drawDialogButtons -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawDialogButtons(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const R4SdkGuiDialogButton * p3, uintptr_t n3, uint32_t p4, uint32_t p5, uint32_t p6, const R4SdkGuiPalette * p7) {
 (void)reserved; R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,77u,a,8u,0);
}
/* gui.drawDialogStatus -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawDialogStatus(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint8_t p4, const R4SdkGuiPalette * p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,78u,a,6u,0);
}
/* gui.drawMessageDialog -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawMessageDialog(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const uint8_t * p4, uintptr_t n4, const uint8_t * p5, uintptr_t n5, uint8_t p6, const R4SdkGuiPalette * p7) {
 (void)reserved; R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.length=n5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,79u,a,8u,0);
}
/* gui.drawMessageBox -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawMessageBox(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const uint8_t * p4, uintptr_t n4, uint32_t p5, uint32_t p6, const uint8_t * p7, uintptr_t n7, const uint8_t * p8, uintptr_t n8, const uint8_t * p9, uintptr_t n9, const uint8_t * p10, uintptr_t n10, uint32_t p11, const R4SdkGuiPalette * p12) {
 (void)reserved; R4SdkGuiSlot a[13]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.length=n7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.ptr=(void *)p8,.length=n8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.ptr=(void *)p9,.length=n9,.flags=R4SDK_GUI_PRESENT};
 a[10] = (R4SdkGuiSlot){.ptr=(void *)p10,.length=n10,.flags=R4SDK_GUI_PRESENT};
 a[11] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4SDK_GUI_PRESENT};
 a[12] = (R4SdkGuiSlot){.ptr=(void *)p12,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,80u,a,13u,0);
}
/* gui.messageDialogOkRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_messageDialogOkRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,81u,a,1u,output);
}
/* gui.messageDialogOkRectFor -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_messageDialogOkRectFor(uint32_t reserved, const R4SdkGuiRect * p0, uint32_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,82u,a,2u,output);
}
/* gui.messageDialogYesRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_messageDialogYesRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,83u,a,1u,output);
}
/* gui.messageDialogNoRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_messageDialogNoRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,84u,a,1u,output);
}
/* gui.messageDialogCancelRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_messageDialogCancelRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,85u,a,1u,output);
}
/* gui.drawFileDialog -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawFileDialog(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const uint8_t * p4, uintptr_t n4, const R4SdkGuiType35 * p5, uintptr_t n5, uint64_t p6, const uint8_t * p7, uintptr_t n7, const uint8_t * p8, uintptr_t n8, const R4SdkGuiPalette * p9) {
 (void)reserved; R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.length=n5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.length=n7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.ptr=(void *)p8,.length=n8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.ptr=(void *)p9,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,86u,a,10u,0);
}
/* gui.drawFileDialogEx -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawFileDialogEx(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const uint8_t * p4, uintptr_t n4, const R4SdkGuiType35 * p5, uintptr_t n5, uint64_t p6, R4SdkGuiSlot p7, uint64_t p8, uint64_t p9, uint32_t p10, const uint8_t * p11, uintptr_t n11, const uint8_t * p12, uintptr_t n12, const uint8_t * p13, uintptr_t n13, uint32_t p14, uint32_t p15, const R4SdkGuiPalette * p16) {
 (void)reserved; R4SdkGuiSlot a[17]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.length=n5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = p7;
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDK_GUI_PRESENT};
 a[10] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4SDK_GUI_PRESENT};
 a[11] = (R4SdkGuiSlot){.ptr=(void *)p11,.length=n11,.flags=R4SDK_GUI_PRESENT};
 a[12] = (R4SdkGuiSlot){.ptr=(void *)p12,.length=n12,.flags=R4SDK_GUI_PRESENT};
 a[13] = (R4SdkGuiSlot){.ptr=(void *)p13,.length=n13,.flags=R4SDK_GUI_PRESENT};
 a[14] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4SDK_GUI_PRESENT};
 a[15] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4SDK_GUI_PRESENT};
 a[16] = (R4SdkGuiSlot){.ptr=(void *)p16,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,87u,a,17u,0);
}
/* gui.fileDialogFileNameRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_fileDialogFileNameRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,88u,a,1u,output);
}
/* gui.fileDialogListRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_fileDialogListRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,89u,a,1u,output);
}
/* gui.fileDialogListOuterRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_fileDialogListOuterRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,90u,a,1u,output);
}
/* gui.fileDialogScrollbarRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_fileDialogScrollbarRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,91u,a,1u,output);
}
/* gui.fileDialogOkRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_fileDialogOkRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,92u,a,1u,output);
}
/* gui.fileDialogCancelRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_fileDialogCancelRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,93u,a,1u,output);
}
/* gui.drawInputDialog -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawInputDialog(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiInputDialog * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,94u,a,3u,0);
}
/* gui.inputDialogLabelRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_inputDialogLabelRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,95u,a,1u,output);
}
/* gui.inputDialogValueRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_inputDialogValueRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,96u,a,1u,output);
}
/* gui.inputDialogOkRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_inputDialogOkRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,97u,a,1u,output);
}
/* gui.inputDialogCancelRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_inputDialogCancelRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,98u,a,1u,output);
}
/* gui.scrollbarButtonRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_scrollbarButtonRect(uint32_t reserved, const R4SdkGuiRect * p0, uint32_t p1, uint32_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,99u,a,3u,output);
}
/* gui.scrollbarTrackRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_scrollbarTrackRect(uint32_t reserved, const R4SdkGuiRect * p0, uint32_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,100u,a,2u,output);
}
/* gui.scrollbarThumbRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_scrollbarThumbRect(uint32_t reserved, const R4SdkGuiRect * p0, uint32_t p1, uint64_t p2, uint64_t p3, uint64_t p4, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,101u,a,5u,output);
}
/* gui.scrollbarPartAt -> gui.ScrollbarPart */
static inline R4SdkGuiSlot R4SdkGui_scrollbarPartAt(uint32_t reserved, const R4SdkGuiScrollbar * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,102u,a,3u,0);
}
/* gui.scrollbarStep -> gui.ScrollbarStep */
static inline R4SdkGuiSlot R4SdkGui_scrollbarStep(uint32_t reserved, const R4SdkGuiScrollbar * p0, uint32_t p1, R4SdkGuiScrollbarStep *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,103u,a,2u,output);
}
/* gui.tabBarItemRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_tabBarItemRect(uint32_t reserved, const R4SdkGuiRect * p0, const R4SdkGuiTabItem * p1, uintptr_t n1, uint64_t p2, int32_t p3, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,104u,a,4u,output);
}
/* gui.tabBarIndexAt -> ?usize */
static inline R4SdkGuiSlot R4SdkGui_tabBarIndexAt(uint32_t reserved, const R4SdkGuiRect * p0, const R4SdkGuiTabItem * p1, uintptr_t n1, int32_t p2, int32_t p3, int32_t p4) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,105u,a,5u,0);
}
/* gui.tableHeaderRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_tableHeaderRect(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,106u,a,2u,output);
}
/* gui.tableBodyRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_tableBodyRect(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, uint8_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,107u,a,3u,output);
}
/* gui.tableScrollbarRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_tableScrollbarRect(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,108u,a,2u,output);
}
/* gui.visibleTableRows -> usize */
static inline R4SdkGuiSlot R4SdkGui_visibleTableRows(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,109u,a,2u,0);
}
/* gui.checkboxBoxRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_checkboxBoxRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,110u,a,1u,output);
}
/* gui.dropdownArrowRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dropdownArrowRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,111u,a,1u,output);
}
/* gui.dropdownListRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dropdownListRect(uint32_t reserved, const R4SdkGuiRect * p0, uint64_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,112u,a,2u,output);
}
/* gui.dropdownListRectEx -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dropdownListRectEx(uint32_t reserved, const R4SdkGuiRect * p0, uint64_t p1, uint64_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,113u,a,3u,output);
}
/* gui.screenRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_screenRect(uint32_t reserved, int32_t p0, int32_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,114u,a,2u,output);
}
/* gui.paddedRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_paddedRect(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,115u,a,2u,output);
}
/* gui.toolbarRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_toolbarRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,116u,a,1u,output);
}
/* gui.contentBelowToolbar -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_contentBelowToolbar(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,117u,a,1u,output);
}
/* gui.statusBarRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_statusBarRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,118u,a,1u,output);
}
/* gui.contentAboveStatus -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_contentAboveStatus(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,119u,a,1u,output);
}
/* gui.dialogButtonRowRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dialogButtonRowRect(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,120u,a,1u,output);
}
/* gui.dialogButtonFromRightRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_dialogButtonFromRightRect(uint32_t reserved, const R4SdkGuiRect * p0, uint64_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,121u,a,2u,output);
}
/* gui.centeredRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGui_centeredRect(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, int32_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,122u,a,3u,output);
}
/* gui.alignedTextX -> i32 */
static inline R4SdkGuiSlot R4SdkGui_alignedTextX(uint32_t reserved, const R4SdkGuiRect * p0, uint64_t p1, uint32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,123u,a,3u,0);
}
/* gui.alignedTextXWidth -> i32 */
static inline R4SdkGuiSlot R4SdkGui_alignedTextXWidth(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, uint32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,124u,a,3u,0);
}
/* gui.fontMetricsForId -> gui.FontMetrics */
static inline R4SdkGuiSlot R4SdkGui_fontMetricsForId(uint32_t reserved, const R4SdkGuiDrawContext * p0, uint32_t p1, R4SdkGuiFontMetrics *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,125u,a,2u,output);
}
/* gui.checkGraphemeEditing -> bool */
static inline R4SdkGuiSlot R4SdkGui_checkGraphemeEditing(uint32_t reserved) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,126u,a,0u,0);
}
/* app_gui.beginPaintForSize -> app_gui.PaintOpen */
static inline R4SdkGuiSlot R4SdkAppGui_beginPaintForSize(uint32_t reserved, const R4SdkGuiDrawContext * p0, int32_t p1, int32_t p2, R4SdkGuiPaintOpen *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,127u,a,3u,output);
}
/* gui_shapes.roundedRect -> error{BufferTooSmall,InvalidValue,SegmentLimit}![]const u8 */
static inline R4SdkGuiSlot R4SdkGuiShapes_roundedRect(uint32_t reserved, uint8_t * p0, uintptr_t n0, const R4SdkGuiShapeRoundedRect * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,128u,a,2u,0);
}
/* gui_shapes.command -> error{BufferTooSmall,InvalidValue,SegmentLimit}!abi_generated.GuiFrameCommand */
static inline R4SdkGuiSlot R4SdkGuiShapes_command(uint32_t reserved, uint32_t p0, int32_t p1, int32_t p2, uint32_t p3, uint32_t p4, uint64_t p5, uint64_t p6, R4GuiFrameCommand *output) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,129u,a,7u,output);
}
/* chart.buildPieSegments -> error{BadImage,NoSlices,OutputTooSmall,Overflow,ZeroTotal}!chart.PieSummary */
static inline R4SdkGuiSlot R4SdkGuiChart_buildPieSegments(uint32_t reserved, const R4SdkGuiChartPieSlice * p0, uintptr_t n0, R4SdkGuiChartPieSegment * p1, uintptr_t n1, R4SdkGuiChartPieSummary *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,130u,a,2u,output);
}
/* chart.drawPie -> error{BadImage,NoSlices,OutputTooSmall,Overflow,ZeroTotal}!void */
static inline R4SdkGuiSlot R4SdkGuiChart_drawPie(uint32_t reserved, uint32_t * p0, uintptr_t n0, uint32_t p1, uint32_t p2, const R4SdkGuiChartPieSegment * p3, uintptr_t n3, uint32_t p4, uint32_t p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,131u,a,6u,0);
}
/* chart.validateChartHelpers -> bool */
static inline R4SdkGuiSlot R4SdkGuiChart_validateChartHelpers(uint32_t reserved) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,132u,a,0u,0);
}
/* clipboard.writeText -> i32 */
static inline R4SdkGuiSlot R4SdkGuiClipboard_writeText(uint32_t reserved, const R4SdkGuiProgramContext * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,133u,a,2u,0);
}
/* clipboard.clear -> i32 */
static inline R4SdkGuiSlot R4SdkGuiClipboard_clear(uint32_t reserved, const R4SdkGuiProgramContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,134u,a,1u,0);
}
/* clipboard.query -> abi_generated.ClipboardInfo */
static inline R4SdkGuiSlot R4SdkGuiClipboard_query(uint32_t reserved, const R4SdkGuiProgramContext * p0, R4ClipboardInfo *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,135u,a,1u,output);
}
/* clipboard.hasText -> bool */
static inline R4SdkGuiSlot R4SdkGuiClipboard_hasText(uint32_t reserved, const R4SdkGuiProgramContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,136u,a,1u,0);
}
/* clipboard.readText -> clipboard.ReadResult */
static inline R4SdkGuiSlot R4SdkGuiClipboard_readText(uint32_t reserved, const R4SdkGuiProgramContext * p0, uint8_t * p1, uintptr_t n1, R4SdkGuiClipboardReadResult *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,137u,a,2u,output);
}
/* clipboard.resultName -> []const u8 */
static inline R4SdkGuiSlot R4SdkGuiClipboard_resultName(uint32_t reserved, int32_t p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,138u,a,1u,0);
}
/* input_events.text -> ?abi_generated.ConsoleInputEvent */
static inline R4SdkGuiSlot R4SdkGuiInput_text(uint32_t reserved, uint32_t p0, R4ConsoleInputEvent *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,139u,a,1u,output);
}
/* input_events.key -> abi_generated.ConsoleInputEvent */
static inline R4SdkGuiSlot R4SdkGuiInput_key(uint32_t reserved, uint8_t p0, R4ConsoleInputEvent *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,140u,a,1u,output);
}
/* input_events.utf8Byte -> abi_generated.ConsoleInputEvent */
static inline R4SdkGuiSlot R4SdkGuiInput_utf8Byte(uint32_t reserved, uint8_t p0, R4ConsoleInputEvent *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,141u,a,1u,output);
}
/* input_events.valid -> bool */
static inline R4SdkGuiSlot R4SdkGuiInput_valid(uint32_t reserved, const R4ConsoleInputEvent * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,142u,a,1u,0);
}
/* input_events.borrowedQueue -> ?input_events.Queue([]abi_generated.ConsoleInputEvent) */
static inline R4SdkGuiSlot R4SdkGuiInput_borrowedQueue(uint32_t reserved, R4ConsoleInputEvent * p0, uintptr_t n0, R4SdkGuiInputQueue *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,143u,a,1u,output);
}
/* window_mode.validIdentity -> bool */
static inline R4SdkGuiSlot R4SdkGuiWindowMode_validIdentity(uint32_t reserved, const R4WindowModeIdentity * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,144u,a,1u,0);
}
/* window_mode.validReply -> bool */
static inline R4SdkGuiSlot R4SdkGuiWindowMode_validReply(uint32_t reserved, const R4WindowModeReply * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,145u,a,1u,0);
}
/* gui_language.drawTextFieldEx -> i32 */
static inline R4SdkGuiSlot R4SdkGui_drawTextFieldEx(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint64_t p4, const R4SdkGuiTextRange * p5, uint8_t p6, uint8_t p7, const R4SdkGuiPalette * p8) {
 (void)reserved; R4SdkGuiSlot a[9]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.ptr=(void *)p8,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,146u,a,9u,0);
}
/* gui.FocusState.normalize -> bool */
static inline R4SdkGuiSlot R4SdkGuiFocusState_normalize(uint32_t reserved, R4SdkGuiFocusState * p0, const R4SdkGuiFocusItem * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,147u,a,2u,0);
}
/* gui.FocusState.set -> bool */
static inline R4SdkGuiSlot R4SdkGuiFocusState_set(uint32_t reserved, R4SdkGuiFocusState * p0, const R4SdkGuiFocusItem * p1, uintptr_t n1, uint64_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,148u,a,3u,0);
}
/* gui.FocusState.move -> bool */
static inline R4SdkGuiSlot R4SdkGuiFocusState_move(uint32_t reserved, R4SdkGuiFocusState * p0, const R4SdkGuiFocusItem * p1, uintptr_t n1, uint32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,149u,a,3u,0);
}
/* gui.FocusState.handleKey -> gui.FocusResult */
static inline R4SdkGuiSlot R4SdkGuiFocusState_handleKey(uint32_t reserved, R4SdkGuiFocusState * p0, const R4SdkGuiFocusItem * p1, uintptr_t n1, uint8_t p2, R4SdkGuiFocusResult *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,150u,a,3u,output);
}
/* gui.MouseCapture.begin -> void */
static inline R4SdkGuiSlot R4SdkGuiMouseCapture_begin(uint32_t reserved, R4SdkGuiMouseCapture * p0, uint64_t p1, uint32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,151u,a,3u,0);
}
/* gui.MouseCapture.release -> gui.ControlAction */
static inline R4SdkGuiSlot R4SdkGuiMouseCapture_release(uint32_t reserved, R4SdkGuiMouseCapture * p0, uint64_t p1, uint8_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,152u,a,3u,0);
}
/* gui.MouseCapture.clear -> void */
static inline R4SdkGuiSlot R4SdkGuiMouseCapture_clear(uint32_t reserved, R4SdkGuiMouseCapture * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,153u,a,1u,0);
}
/* gui.MouseCapture.isActive -> bool */
static inline R4SdkGuiSlot R4SdkGuiMouseCapture_isActive(uint32_t reserved, const R4SdkGuiMouseCapture * p0, uint64_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,154u,a,2u,0);
}
/* gui.TextRange.normalized -> gui.TextRange */
static inline R4SdkGuiSlot R4SdkGuiTextRange_normalized(uint32_t reserved, uint64_t p0, uint64_t p1, R4SdkGuiTextRange *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,155u,a,2u,output);
}
/* gui.TextRange.isEmpty -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextRange_isEmpty(uint32_t reserved, const R4SdkGuiTextRange * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,156u,a,1u,0);
}
/* gui.TextRange.count -> usize */
static inline R4SdkGuiSlot R4SdkGuiTextRange_count(uint32_t reserved, const R4SdkGuiTextRange * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,157u,a,1u,0);
}
/* gui.TextAreaView.init -> gui.TextAreaView */
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_init(uint32_t reserved, uint64_t p0, uint64_t p1, R4SdkGuiTextAreaView *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,158u,a,2u,output);
}
/* gui.TextAreaView.effectiveVisibleCols -> usize */
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_effectiveVisibleCols(uint32_t reserved, const R4SdkGuiTextAreaView * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,159u,a,1u,0);
}
/* gui.TextAreaView.effectiveVisibleRows -> usize */
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_effectiveVisibleRows(uint32_t reserved, const R4SdkGuiTextAreaView * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,160u,a,1u,0);
}
/* gui.TextAreaView.effectiveWrapCols -> usize */
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_effectiveWrapCols(uint32_t reserved, const R4SdkGuiTextAreaView * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,161u,a,1u,0);
}
/* gui.MenubarResult.hasCommand -> bool */
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_hasCommand(uint32_t reserved, const R4SdkGuiMenubarResult * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,162u,a,1u,0);
}
/* gui.Rect.isEmpty -> bool */
static inline R4SdkGuiSlot R4SdkGuiRect_isEmpty(uint32_t reserved, const R4SdkGuiRect * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,163u,a,1u,0);
}
/* gui.Rect.inset -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiRect_inset(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, int32_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,164u,a,3u,output);
}
/* gui.Rect.contains -> bool */
static inline R4SdkGuiSlot R4SdkGuiRect_contains(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,165u,a,3u,0);
}
/* gui.Rect.right -> i32 */
static inline R4SdkGuiSlot R4SdkGuiRect_right(uint32_t reserved, const R4SdkGuiRect * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,166u,a,1u,0);
}
/* gui.Rect.bottom -> i32 */
static inline R4SdkGuiSlot R4SdkGuiRect_bottom(uint32_t reserved, const R4SdkGuiRect * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,167u,a,1u,0);
}
/* gui.Rect.translated -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiRect_translated(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, int32_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,168u,a,3u,output);
}
/* gui.LayoutCursor.init -> gui.LayoutCursor */
static inline R4SdkGuiSlot R4SdkGuiLayoutCursor_init(uint32_t reserved, const R4SdkGuiRect * p0, R4SdkGuiLayoutCursor *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,169u,a,1u,output);
}
/* gui.LayoutCursor.remaining -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiLayoutCursor_remaining(uint32_t reserved, const R4SdkGuiLayoutCursor * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,170u,a,1u,output);
}
/* gui.LayoutCursor.takeTop -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiLayoutCursor_takeTop(uint32_t reserved, R4SdkGuiLayoutCursor * p0, int32_t p1, int32_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,171u,a,3u,output);
}
/* gui.LayoutCursor.takeBottom -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiLayoutCursor_takeBottom(uint32_t reserved, R4SdkGuiLayoutCursor * p0, int32_t p1, int32_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,172u,a,3u,output);
}
/* gui.LayoutCursor.takeLeft -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiLayoutCursor_takeLeft(uint32_t reserved, R4SdkGuiLayoutCursor * p0, int32_t p1, int32_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,173u,a,3u,output);
}
/* gui.LayoutCursor.takeRight -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiLayoutCursor_takeRight(uint32_t reserved, R4SdkGuiLayoutCursor * p0, int32_t p1, int32_t p2, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,174u,a,3u,output);
}
/* gui.HostedAppFrame.refresh -> void */
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_refresh(uint32_t reserved, R4SdkGuiHostedAppFrame * p0, const R4SdkGuiSystemContext * p1, const R4SdkGuiDesktopContext * p2, const R4SdkGuiDrawContext * p3, int32_t p4, int32_t p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,175u,a,6u,0);
}
/* gui.Canvas.init -> gui.Canvas */
static inline R4SdkGuiSlot R4SdkGuiCanvas_init(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4GuiWindowInfo * p1, R4SdkGuiCanvas *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,176u,a,2u,output);
}
/* gui.Canvas.initSize -> gui.Canvas */
static inline R4SdkGuiSlot R4SdkGuiCanvas_initSize(uint32_t reserved, const R4SdkGuiDrawContext * p0, int32_t p1, int32_t p2, R4SdkGuiCanvas *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,177u,a,3u,output);
}
/* gui.Canvas.bounds -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiCanvas_bounds(uint32_t reserved, const R4SdkGuiCanvas * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,178u,a,1u,output);
}
/* gui.Canvas.withFontId -> gui.Canvas */
static inline R4SdkGuiSlot R4SdkGuiCanvas_withFontId(uint32_t reserved, const R4SdkGuiCanvas * p0, uint32_t p1, R4SdkGuiCanvas *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,179u,a,2u,output);
}
/* gui.Canvas.clear -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_clear(uint32_t reserved, const R4SdkGuiCanvas * p0, uint32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,180u,a,2u,0);
}
/* gui.Canvas.rect -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_rect(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,181u,a,3u,0);
}
/* gui.Canvas.raster -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_raster(uint32_t reserved, const R4SdkGuiCanvas * p0, int32_t p1, int32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, const uint32_t * p6, uintptr_t n6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.length=n6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,182u,a,7u,0);
}
/* gui.Canvas.blendAlpha8 -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_blendAlpha8(uint32_t reserved, const R4SdkGuiCanvas * p0, int32_t p1, int32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, const uint8_t * p7, uintptr_t n7) {
 (void)reserved; R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.length=n7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,183u,a,8u,0);
}
/* gui.Canvas.text -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_text(uint32_t reserved, const R4SdkGuiCanvas * p0, int32_t p1, int32_t p2, const uint8_t * p3, uint32_t p4, uint32_t p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,184u,a,6u,0);
}
/* gui.Canvas.textFont -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_textFont(uint32_t reserved, const R4SdkGuiCanvas * p0, uint32_t p1, int32_t p2, int32_t p3, const uint8_t * p4, uint32_t p5, uint32_t p6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,185u,a,7u,0);
}
/* gui.Canvas.frameCommand -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_frameCommand(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4GuiFrameCommand * p1, const uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,186u,a,3u,0);
}
/* gui.Canvas.textWidthZ -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_textWidthZ(uint32_t reserved, const R4SdkGuiCanvas * p0, const uint8_t * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,187u,a,2u,0);
}
/* gui.Canvas.charsForWidth -> usize */
static inline R4SdkGuiSlot R4SdkGuiCanvas_charsForWidth(uint32_t reserved, const R4SdkGuiCanvas * p0, int32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,188u,a,2u,0);
}
/* gui.Canvas.textClipped -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_textClipped(uint32_t reserved, const R4SdkGuiCanvas * p0, int32_t p1, int32_t p2, int32_t p3, uint8_t * p4, uintptr_t n4, const uint8_t * p5, uintptr_t n5, uint32_t p6, uint32_t p7) {
 (void)reserved; R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.length=n5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,189u,a,8u,0);
}
/* gui.Canvas.label -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_label(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiLabel * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,190u,a,3u,0);
}
/* gui.Canvas.button -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_button(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiButton * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,191u,a,3u,0);
}
/* gui.Canvas.checkbox -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_checkbox(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiCheckbox * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,192u,a,3u,0);
}
/* gui.Canvas.radioButton -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_radioButton(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRadioButton * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,193u,a,3u,0);
}
/* gui.Canvas.groupBox -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_groupBox(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiGroupBox * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,194u,a,3u,0);
}
/* gui.Canvas.separator -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_separator(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiSeparator * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,195u,a,2u,0);
}
/* gui.Canvas.textField -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_textField(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint8_t p4, uint8_t p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,196u,a,6u,0);
}
/* gui.Canvas.textArea -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_textArea(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiRect * p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, uint64_t p4, const R4SdkGuiTextRange * p5, uint64_t p6, uint64_t p7, uint8_t p8, uint8_t p9) {
 (void)reserved; R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,197u,a,10u,0);
}
/* gui.Canvas.list -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_list(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiList * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,198u,a,3u,0);
}
/* gui.Canvas.scrollbar -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_scrollbar(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiScrollbar * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,199u,a,3u,0);
}
/* gui.Canvas.toolbarButton -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_toolbarButton(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiToolbarButton * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,200u,a,3u,0);
}
/* gui.Canvas.tabBar -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_tabBar(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiTabBar * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,201u,a,3u,0);
}
/* gui.Canvas.tableView -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_tableView(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiTableView * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,202u,a,3u,0);
}
/* gui.Canvas.menu -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_menu(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiMenu * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,203u,a,3u,0);
}
/* gui.Canvas.menubar -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_menubar(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiMenubar * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,204u,a,3u,0);
}
/* gui.Canvas.dropdown -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_dropdown(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiDropdown * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,205u,a,3u,0);
}
/* gui.Canvas.messageDialog -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_messageDialog(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiMessageDialog * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,206u,a,3u,0);
}
/* gui.Canvas.fileDialog -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_fileDialog(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiFileDialog * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,207u,a,3u,0);
}
/* gui.Canvas.inputDialog -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_inputDialog(uint32_t reserved, const R4SdkGuiCanvas * p0, const R4SdkGuiInputDialog * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,208u,a,3u,0);
}
/* gui.Canvas.present -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCanvas_present(uint32_t reserved, const R4SdkGuiCanvas * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,209u,a,1u,0);
}
/* r4draw.Context.guiClear -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiClear(uint32_t reserved, const R4SdkGuiDrawContext * p0, uint32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,210u,a,2u,0);
}
/* r4draw.Context.guiRect -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiRect(uint32_t reserved, const R4SdkGuiDrawContext * p0, int32_t p1, int32_t p2, uint32_t p3, uint32_t p4, uint32_t p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,211u,a,6u,0);
}
/* r4draw.Context.guiDrawText -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiDrawText(uint32_t reserved, const R4SdkGuiDrawContext * p0, int32_t p1, int32_t p2, const uint8_t * p3, uint32_t p4, uint32_t p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,212u,a,6u,0);
}
/* r4draw.Context.guiDrawTextEx -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiDrawTextEx(uint32_t reserved, const R4SdkGuiDrawContext * p0, int32_t p1, int32_t p2, const uint8_t * p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7) {
 (void)reserved; R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,213u,a,8u,0);
}
/* r4draw.Context.guiBlit -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiBlit(uint32_t reserved, const R4SdkGuiDrawContext * p0, int32_t p1, int32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, const uint32_t * p6, uintptr_t n6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.length=n6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,214u,a,7u,0);
}
/* r4draw.Context.guiBlendAlpha8 -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiBlendAlpha8(uint32_t reserved, const R4SdkGuiDrawContext * p0, int32_t p1, int32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, const uint8_t * p7, uintptr_t n7) {
 (void)reserved; R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.length=n7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,215u,a,8u,0);
}
/* r4draw.Context.guiRasterRead -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiRasterRead(uint32_t reserved, const R4SdkGuiDrawContext * p0, uint32_t p1, uint32_t p2, uint32_t * p3, uintptr_t n3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,216u,a,4u,0);
}
/* r4draw.Context.supportsGuiFrameContract -> bool */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_supportsGuiFrameContract(uint32_t reserved, const R4SdkGuiDrawContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,217u,a,1u,0);
}
/* r4draw.Context.supportsGuiFrameDamageContract -> bool */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_supportsGuiFrameDamageContract(uint32_t reserved, const R4SdkGuiDrawContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,218u,a,1u,0);
}
/* r4draw.Context.supportsGuiFrameStreamingContract -> bool */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_supportsGuiFrameStreamingContract(uint32_t reserved, const R4SdkGuiDrawContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,219u,a,1u,0);
}
/* r4draw.Context.supportsGuiSharedRasterContract -> bool */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_supportsGuiSharedRasterContract(uint32_t reserved, const R4SdkGuiDrawContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,220u,a,1u,0);
}
/* r4draw.Context.guiFrameBegin -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFrameBegin(uint32_t reserved, const R4SdkGuiDrawContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,221u,a,1u,0);
}
/* r4draw.Context.guiFrameBeginDamage -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFrameBeginDamage(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4DisplayDamageRect * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,222u,a,2u,0);
}
/* r4draw.Context.guiFrameBeginReplace -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFrameBeginReplace(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4DisplayDamageRect * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,223u,a,2u,0);
}
/* r4draw.Context.guiFrameAppend -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFrameAppend(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4GuiFrameCommand * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,224u,a,3u,0);
}
/* r4draw.Context.guiFrameCommit -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFrameCommit(uint32_t reserved, const R4SdkGuiDrawContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,225u,a,1u,0);
}
/* r4draw.Context.guiFrameCancel -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFrameCancel(uint32_t reserved, const R4SdkGuiDrawContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,226u,a,1u,0);
}
/* r4draw.Context.guiFrameInfo -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFrameInfo(uint32_t reserved, const R4SdkGuiDrawContext * p0, R4SdkGuiSlot p1, R4GuiFrameInfo * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = p1;
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,227u,a,3u,0);
}
/* r4draw.Context.guiFrameRead -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFrameRead(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4ProgramProcessHandle * p1, uint64_t p2, R4GuiFrameCommand * p3, uintptr_t n3, uint8_t * p4, uintptr_t n4, R4GuiFrameInfo * p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,228u,a,6u,0);
}
/* r4draw.Context.guiFrameGenerationInfo -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFrameGenerationInfo(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4ProgramProcessHandle * p1, uint64_t p2, R4GuiFrameGenerationInfo * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,229u,a,4u,0);
}
/* r4draw.Context.guiFrameGenerationRead -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFrameGenerationRead(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4ProgramProcessHandle * p1, uint64_t p2, R4GuiFrameCommand * p3, uintptr_t n3, uint8_t * p4, uintptr_t n4, R4DisplayDamageRect * p5, uintptr_t n5, R4GuiFrameGenerationInfo * p6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.length=n5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,230u,a,7u,0);
}
/* r4draw.Context.guiFrameStreamInfo -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFrameStreamInfo(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4ProgramProcessHandle * p1, R4GuiFrameStreamInfo * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,231u,a,3u,0);
}
/* r4draw.Context.guiSharedRasterCreate -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiSharedRasterCreate(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4GuiSharedRasterCreateInfo * p1, R4GuiSharedRasterHandle * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,232u,a,3u,0);
}
/* r4draw.Context.guiSharedRasterDestroy -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiSharedRasterDestroy(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4GuiSharedRasterHandle * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,233u,a,2u,0);
}
/* r4draw.Context.guiSharedRasterMapWrite -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiSharedRasterMapWrite(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4GuiSharedRasterHandle * p1, R4GuiSharedRasterWriteMap * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,234u,a,3u,0);
}
/* r4draw.Context.guiSharedRasterPublish -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiSharedRasterPublish(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4GuiSharedRasterWriteMap * p1, uint64_t * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,235u,a,3u,0);
}
/* r4draw.Context.guiSharedRasterAcquire -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiSharedRasterAcquire(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4ProgramProcessHandle * p1, uint64_t p2, const R4GuiSharedRasterHandle * p3, uint64_t p4, R4GuiSharedRasterMap * p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,236u,a,6u,0);
}
/* r4draw.Context.guiSharedRasterRelease -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiSharedRasterRelease(uint32_t reserved, const R4SdkGuiDrawContext * p0, const R4GuiSharedRasterLease * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,237u,a,2u,0);
}
/* r4draw.Context.guiPresent -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiPresent(uint32_t reserved, const R4SdkGuiDrawContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,238u,a,1u,0);
}
/* r4draw.Context.fontCount -> u32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_fontCount(uint32_t reserved, const R4SdkGuiDrawContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,239u,a,1u,0);
}
/* r4draw.Context.fontInfo -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_fontInfo(uint32_t reserved, const R4SdkGuiDrawContext * p0, uint32_t p1, R4GuiFontInfo * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,240u,a,3u,0);
}
/* r4draw.Context.fontMeasure -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_fontMeasure(uint32_t reserved, const R4SdkGuiDrawContext * p0, uint32_t p1, const uint8_t * p2, R4GuiTextMetrics * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,241u,a,4u,0);
}
/* r4draw.Context.fontGlyphRow -> u64 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_fontGlyphRow(uint32_t reserved, const R4SdkGuiDrawContext * p0, uint32_t p1, uint32_t p2, uint32_t p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,242u,a,4u,0);
}
/* r4draw.Context.fontGlyphBitmap -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_fontGlyphBitmap(uint32_t reserved, const R4SdkGuiDrawContext * p0, uint32_t p1, uint32_t p2, R4GuiGlyphBitmap * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,243u,a,4u,0);
}
/* r4draw.Context.fontRevision -> u32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_fontRevision(uint32_t reserved, const R4SdkGuiDrawContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,244u,a,1u,0);
}
/* r4draw.Context.fontReload -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_fontReload(uint32_t reserved, const R4SdkGuiDrawContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,245u,a,1u,0);
}
/* r4draw.Context.guiSetFont -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiSetFont(uint32_t reserved, const R4SdkGuiDrawContext * p0, uint32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,246u,a,2u,0);
}
/* r4draw.Context.guiFont -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDrawContext_guiFont(uint32_t reserved, const R4SdkGuiDrawContext * p0, uint32_t p1, R4GuiFontInfo * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,247u,a,3u,0);
}
/* gui.FrameCanvas.init -> gui.FrameCanvas */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_init(uint32_t reserved, const R4SdkGuiDrawContext * p0, R4GuiFrameCommand * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2, uint8_t p3, R4SdkGuiFrameCanvas *output) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,248u,a,4u,output);
}
/* gui.FrameCanvas.bind -> gui.Canvas */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_bind(uint32_t reserved, R4SdkGuiFrameCanvas * p0, const R4SdkGuiCanvas * p1, R4SdkGuiCanvas *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,249u,a,2u,output);
}
/* gui.FrameCanvas.finish -> i32 */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_finish(uint32_t reserved, R4SdkGuiFrameCanvas * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,250u,a,1u,0);
}
/* gui.FrameCanvas.complete -> void */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_complete(uint32_t reserved, R4SdkGuiFrameCanvas * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,251u,a,1u,0);
}
/* gui.FrameCanvas.cancel -> void */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_cancel(uint32_t reserved, R4SdkGuiFrameCanvas * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,252u,a,1u,0);
}
/* gui.FrameCanvas.clear -> i32 */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_clear(uint32_t reserved, R4SdkGuiFrameCanvas * p0, uint32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,253u,a,2u,0);
}
/* gui.FrameCanvas.rect -> i32 */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_rect(uint32_t reserved, R4SdkGuiFrameCanvas * p0, int32_t p1, int32_t p2, uint32_t p3, uint32_t p4, uint32_t p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,254u,a,6u,0);
}
/* gui.FrameCanvas.text -> i32 */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_text(uint32_t reserved, R4SdkGuiFrameCanvas * p0, int32_t p1, int32_t p2, const uint8_t * p3, uint32_t p4, uint32_t p5, const R4SdkGuiFontMetrics * p6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,255u,a,7u,0);
}
/* gui.FrameCanvas.raster -> i32 */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_raster(uint32_t reserved, R4SdkGuiFrameCanvas * p0, int32_t p1, int32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, const uint32_t * p6, uintptr_t n6) {
 (void)reserved; R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.length=n6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,256u,a,7u,0);
}
/* gui.FrameCanvas.alpha8 -> i32 */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_alpha8(uint32_t reserved, R4SdkGuiFrameCanvas * p0, int32_t p1, int32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, const uint8_t * p7, uintptr_t n7) {
 (void)reserved; R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.length=n7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,257u,a,8u,0);
}
/* gui.FrameCanvas.appendCommand -> i32 */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_appendCommand(uint32_t reserved, R4SdkGuiFrameCanvas * p0, const R4GuiFrameCommand * p1, const uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,258u,a,3u,0);
}
/* gui.FrameCanvasStats.drawTransitions -> u64 */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_drawTransitions(uint32_t reserved, const R4SdkGuiFrameCanvasStats * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,259u,a,1u,0);
}
/* gui.FrameCanvasStats.frameMutationEntries -> u64 */
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_frameMutationEntries(uint32_t reserved, const R4SdkGuiFrameCanvasStats * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,260u,a,1u,0);
}
/* gui.Label.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiLabel_draw(uint32_t reserved, const R4SdkGuiLabel * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,261u,a,3u,0);
}
/* gui.Button.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiButton_draw(uint32_t reserved, const R4SdkGuiButton * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,262u,a,3u,0);
}
/* gui.Button.contains -> bool */
static inline R4SdkGuiSlot R4SdkGuiButton_contains(uint32_t reserved, const R4SdkGuiButton * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,263u,a,3u,0);
}
/* gui.Button.minWidth -> i32 */
static inline R4SdkGuiSlot R4SdkGuiButton_minWidth(uint32_t reserved, const R4SdkGuiButton * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,264u,a,1u,0);
}
/* gui.List.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiList_draw(uint32_t reserved, const R4SdkGuiList * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,265u,a,3u,0);
}
/* gui.List.indexAt -> ?usize */
static inline R4SdkGuiSlot R4SdkGuiList_indexAt(uint32_t reserved, const R4SdkGuiList * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,266u,a,3u,0);
}
/* gui.List.visibleRows -> usize */
static inline R4SdkGuiSlot R4SdkGuiList_visibleRows(uint32_t reserved, const R4SdkGuiList * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,267u,a,1u,0);
}
/* gui.List.firstIndexForSelection -> usize */
static inline R4SdkGuiSlot R4SdkGuiList_firstIndexForSelection(uint32_t reserved, const R4SdkGuiList * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,268u,a,1u,0);
}
/* gui.List.keyAction -> gui.SelectionStep */
static inline R4SdkGuiSlot R4SdkGuiList_keyAction(uint32_t reserved, const R4SdkGuiList * p0, uint8_t p1, R4SdkGuiSelectionStep *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,269u,a,2u,output);
}
/* gui.Scrollbar.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiScrollbar_draw(uint32_t reserved, const R4SdkGuiScrollbar * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,270u,a,3u,0);
}
/* gui.Scrollbar.maxFirst -> usize */
static inline R4SdkGuiSlot R4SdkGuiScrollbar_maxFirst(uint32_t reserved, const R4SdkGuiScrollbar * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,271u,a,1u,0);
}
/* gui.Scrollbar.clampedFirst -> usize */
static inline R4SdkGuiSlot R4SdkGuiScrollbar_clampedFirst(uint32_t reserved, const R4SdkGuiScrollbar * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,272u,a,1u,0);
}
/* gui.Scrollbar.decrementRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiScrollbar_decrementRect(uint32_t reserved, const R4SdkGuiScrollbar * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,273u,a,1u,output);
}
/* gui.Scrollbar.incrementRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiScrollbar_incrementRect(uint32_t reserved, const R4SdkGuiScrollbar * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,274u,a,1u,output);
}
/* gui.Scrollbar.trackRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiScrollbar_trackRect(uint32_t reserved, const R4SdkGuiScrollbar * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,275u,a,1u,output);
}
/* gui.Scrollbar.thumbRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiScrollbar_thumbRect(uint32_t reserved, const R4SdkGuiScrollbar * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,276u,a,1u,output);
}
/* gui.Scrollbar.partAt -> gui.ScrollbarPart */
static inline R4SdkGuiSlot R4SdkGuiScrollbar_partAt(uint32_t reserved, const R4SdkGuiScrollbar * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,277u,a,3u,0);
}
/* gui.Scrollbar.step -> gui.ScrollbarStep */
static inline R4SdkGuiSlot R4SdkGuiScrollbar_step(uint32_t reserved, const R4SdkGuiScrollbar * p0, uint32_t p1, R4SdkGuiScrollbarStep *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,278u,a,2u,output);
}
/* gui.Scrollbar.wheel -> gui.ScrollbarStep */
static inline R4SdkGuiSlot R4SdkGuiScrollbar_wheel(uint32_t reserved, const R4SdkGuiScrollbar * p0, int32_t p1, R4SdkGuiScrollbarStep *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,279u,a,2u,output);
}
/* gui.ToolbarButton.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_draw(uint32_t reserved, const R4SdkGuiToolbarButton * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,280u,a,3u,0);
}
/* gui.ToolbarButton.contains -> bool */
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_contains(uint32_t reserved, const R4SdkGuiToolbarButton * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,281u,a,3u,0);
}
/* gui.TabBar.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiTabBar_draw(uint32_t reserved, const R4SdkGuiTabBar * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,282u,a,3u,0);
}
/* gui.TabBar.tabRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiTabBar_tabRect(uint32_t reserved, const R4SdkGuiTabBar * p0, uint64_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,283u,a,2u,output);
}
/* gui.TabBar.indexAt -> ?usize */
static inline R4SdkGuiSlot R4SdkGuiTabBar_indexAt(uint32_t reserved, const R4SdkGuiTabBar * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,284u,a,3u,0);
}
/* gui.TabBar.keyAction -> gui.SelectionStep */
static inline R4SdkGuiSlot R4SdkGuiTabBar_keyAction(uint32_t reserved, const R4SdkGuiTabBar * p0, uint8_t p1, R4SdkGuiSelectionStep *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,285u,a,2u,output);
}
/* gui.TableView.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiTableView_draw(uint32_t reserved, const R4SdkGuiTableView * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,286u,a,3u,0);
}
/* gui.TableView.effectiveRowCount -> usize */
static inline R4SdkGuiSlot R4SdkGuiTableView_effectiveRowCount(uint32_t reserved, const R4SdkGuiTableView * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,287u,a,1u,0);
}
/* gui.TableView.headerRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiTableView_headerRect(uint32_t reserved, const R4SdkGuiTableView * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,288u,a,1u,output);
}
/* gui.TableView.bodyRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiTableView_bodyRect(uint32_t reserved, const R4SdkGuiTableView * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,289u,a,1u,output);
}
/* gui.TableView.scrollbarRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiTableView_scrollbarRect(uint32_t reserved, const R4SdkGuiTableView * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,290u,a,1u,output);
}
/* gui.TableView.needsScrollbar -> bool */
static inline R4SdkGuiSlot R4SdkGuiTableView_needsScrollbar(uint32_t reserved, const R4SdkGuiTableView * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,291u,a,1u,0);
}
/* gui.TableView.visibleRows -> usize */
static inline R4SdkGuiSlot R4SdkGuiTableView_visibleRows(uint32_t reserved, const R4SdkGuiTableView * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,292u,a,1u,0);
}
/* gui.TableView.indexAt -> ?usize */
static inline R4SdkGuiSlot R4SdkGuiTableView_indexAt(uint32_t reserved, const R4SdkGuiTableView * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,293u,a,3u,0);
}
/* gui.TableView.firstIndexForSelection -> usize */
static inline R4SdkGuiSlot R4SdkGuiTableView_firstIndexForSelection(uint32_t reserved, const R4SdkGuiTableView * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,294u,a,1u,0);
}
/* gui.TableView.keyAction -> gui.SelectionStep */
static inline R4SdkGuiSlot R4SdkGuiTableView_keyAction(uint32_t reserved, const R4SdkGuiTableView * p0, uint8_t p1, R4SdkGuiSelectionStep *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,295u,a,2u,output);
}
/* gui.TableView.cell -> []const u8 */
static inline R4SdkGuiSlot R4SdkGuiTableView_cell(uint32_t reserved, const R4SdkGuiTableView * p0, uint64_t p1, uint64_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,296u,a,3u,0);
}
/* gui.Checkbox.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiCheckbox_draw(uint32_t reserved, const R4SdkGuiCheckbox * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,297u,a,3u,0);
}
/* gui.Checkbox.contains -> bool */
static inline R4SdkGuiSlot R4SdkGuiCheckbox_contains(uint32_t reserved, const R4SdkGuiCheckbox * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,298u,a,3u,0);
}
/* gui.RadioButton.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiRadioButton_draw(uint32_t reserved, const R4SdkGuiRadioButton * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,299u,a,3u,0);
}
/* gui.RadioButton.contains -> bool */
static inline R4SdkGuiSlot R4SdkGuiRadioButton_contains(uint32_t reserved, const R4SdkGuiRadioButton * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,300u,a,3u,0);
}
/* gui.GroupBox.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiGroupBox_draw(uint32_t reserved, const R4SdkGuiGroupBox * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,301u,a,3u,0);
}
/* gui.Separator.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiSeparator_draw(uint32_t reserved, const R4SdkGuiSeparator * p0, const R4SdkGuiCanvas * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,302u,a,2u,0);
}
/* gui.Dropdown.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDropdown_draw(uint32_t reserved, const R4SdkGuiDropdown * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,303u,a,3u,0);
}
/* gui.Dropdown.contains -> bool */
static inline R4SdkGuiSlot R4SdkGuiDropdown_contains(uint32_t reserved, const R4SdkGuiDropdown * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,304u,a,3u,0);
}
/* gui.Dropdown.listRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiDropdown_listRect(uint32_t reserved, const R4SdkGuiDropdown * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,305u,a,1u,output);
}
/* gui.Dropdown.indexAt -> ?usize */
static inline R4SdkGuiSlot R4SdkGuiDropdown_indexAt(uint32_t reserved, const R4SdkGuiDropdown * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,306u,a,3u,0);
}
/* gui.Dropdown.keyAction -> gui.SelectionStep */
static inline R4SdkGuiSlot R4SdkGuiDropdown_keyAction(uint32_t reserved, const R4SdkGuiDropdown * p0, uint8_t p1, R4SdkGuiSelectionStep *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,307u,a,2u,output);
}
/* gui.Dropdown.firstIndexForSelection -> usize */
static inline R4SdkGuiSlot R4SdkGuiDropdown_firstIndexForSelection(uint32_t reserved, const R4SdkGuiDropdown * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,308u,a,1u,0);
}
/* gui.Dropdown.visibleRows -> usize */
static inline R4SdkGuiSlot R4SdkGuiDropdown_visibleRows(uint32_t reserved, const R4SdkGuiDropdown * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,309u,a,1u,0);
}
/* gui.Menu.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiMenu_draw(uint32_t reserved, const R4SdkGuiMenu * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,310u,a,3u,0);
}
/* gui.Menu.indexAt -> ?usize */
static inline R4SdkGuiSlot R4SdkGuiMenu_indexAt(uint32_t reserved, const R4SdkGuiMenu * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,311u,a,3u,0);
}
/* gui.Menu.keyAction -> gui.MenuKeyResult */
static inline R4SdkGuiSlot R4SdkGuiMenu_keyAction(uint32_t reserved, const R4SdkGuiMenu * p0, uint8_t p1, R4SdkGuiMenuKeyResult *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,312u,a,2u,output);
}
/* gui.MenubarState.isOpen -> bool */
static inline R4SdkGuiSlot R4SdkGuiMenubarState_isOpen(uint32_t reserved, const R4SdkGuiMenubarState * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,313u,a,1u,0);
}
/* gui.MenubarState.close -> void */
static inline R4SdkGuiSlot R4SdkGuiMenubarState_close(uint32_t reserved, R4SdkGuiMenubarState * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,314u,a,1u,0);
}
/* gui.MenubarState.open -> bool */
static inline R4SdkGuiSlot R4SdkGuiMenubarState_open(uint32_t reserved, R4SdkGuiMenubarState * p0, const R4SdkGuiMenubarMenu * p1, uintptr_t n1, uint64_t p2, uint8_t p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,315u,a,4u,0);
}
/* gui.MenubarState.openFirst -> bool */
static inline R4SdkGuiSlot R4SdkGuiMenubarState_openFirst(uint32_t reserved, R4SdkGuiMenubarState * p0, const R4SdkGuiMenubarMenu * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,316u,a,2u,0);
}
/* gui.MenubarState.switchMenu -> bool */
static inline R4SdkGuiSlot R4SdkGuiMenubarState_switchMenu(uint32_t reserved, R4SdkGuiMenubarState * p0, const R4SdkGuiMenubarMenu * p1, uintptr_t n1, uint32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,317u,a,3u,0);
}
/* gui.MenubarState.keyAction -> gui.MenubarResult */
static inline R4SdkGuiSlot R4SdkGuiMenubarState_keyAction(uint32_t reserved, R4SdkGuiMenubarState * p0, const R4SdkGuiMenubarMenu * p1, uintptr_t n1, uint8_t p2, R4SdkGuiMenubarResult *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,318u,a,3u,output);
}
/* gui.MenubarState.mouseMove -> gui.MenubarResult */
static inline R4SdkGuiSlot R4SdkGuiMenubarState_mouseMove(uint32_t reserved, R4SdkGuiMenubarState * p0, const R4SdkGuiRect * p1, const R4SdkGuiMenubarMenu * p2, uintptr_t n2, int32_t p3, int32_t p4, R4SdkGuiMenubarResult *output) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,319u,a,5u,output);
}
/* gui.MenubarState.mouseDown -> gui.MenubarResult */
static inline R4SdkGuiSlot R4SdkGuiMenubarState_mouseDown(uint32_t reserved, R4SdkGuiMenubarState * p0, const R4SdkGuiRect * p1, const R4SdkGuiMenubarMenu * p2, uintptr_t n2, int32_t p3, int32_t p4, R4SdkGuiMenubarResult *output) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,320u,a,5u,output);
}
/* gui.MenubarState.mouseUp -> gui.MenubarResult */
static inline R4SdkGuiSlot R4SdkGuiMenubarState_mouseUp(uint32_t reserved, R4SdkGuiMenubarState * p0, const R4SdkGuiRect * p1, const R4SdkGuiMenubarMenu * p2, uintptr_t n2, int32_t p3, int32_t p4, R4SdkGuiMenubarResult *output) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,321u,a,5u,output);
}
/* gui.Menubar.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiMenubar_draw(uint32_t reserved, const R4SdkGuiMenubar * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,322u,a,3u,0);
}
/* gui.Menubar.headerRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiMenubar_headerRect(uint32_t reserved, const R4SdkGuiMenubar * p0, uint64_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,323u,a,2u,output);
}
/* gui.Menubar.popupRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiMenubar_popupRect(uint32_t reserved, const R4SdkGuiMenubar * p0, uint64_t p1, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,324u,a,2u,output);
}
/* gui.Menubar.menuIndexAt -> ?usize */
static inline R4SdkGuiSlot R4SdkGuiMenubar_menuIndexAt(uint32_t reserved, const R4SdkGuiMenubar * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,325u,a,3u,0);
}
/* gui.Menubar.hitTest -> gui.MenubarHit */
static inline R4SdkGuiSlot R4SdkGuiMenubar_hitTest(uint32_t reserved, const R4SdkGuiMenubar * p0, int32_t p1, int32_t p2, R4SdkGuiMenubarHit *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,326u,a,3u,output);
}
/* gui.DialogState.normalizeFocus -> void */
static inline R4SdkGuiSlot R4SdkGuiDialogState_normalizeFocus(uint32_t reserved, R4SdkGuiDialogState * p0, const R4SdkGuiDialogFocusItem * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,327u,a,2u,0);
}
/* gui.DialogState.keyAction -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGuiDialogState_keyAction(uint32_t reserved, R4SdkGuiDialogState * p0, const R4SdkGuiDialogFocusItem * p1, uintptr_t n1, const R4SdkGuiDialogButton * p2, uintptr_t n2, uint8_t p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,328u,a,4u,0);
}
/* gui.DialogState.mouseDown -> gui.DialogEvent */
static inline R4SdkGuiSlot R4SdkGuiDialogState_mouseDown(uint32_t reserved, R4SdkGuiDialogState * p0, const R4SdkGuiModalDialog * p1, const R4SdkGuiDialogButton * p2, uintptr_t n2, uint32_t p3, int32_t p4, int32_t p5, R4SdkGuiDialogEvent *output) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,329u,a,6u,output);
}
/* gui.DialogState.mouseUp -> gui.DialogEvent */
static inline R4SdkGuiSlot R4SdkGuiDialogState_mouseUp(uint32_t reserved, R4SdkGuiDialogState * p0, const R4SdkGuiModalDialog * p1, const R4SdkGuiDialogButton * p2, uintptr_t n2, uint32_t p3, int32_t p4, int32_t p5, R4SdkGuiDialogEvent *output) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,330u,a,6u,output);
}
/* gui.ModalDialog.centered -> gui.ModalDialog */
static inline R4SdkGuiSlot R4SdkGuiModalDialog_centered(uint32_t reserved, const R4SdkGuiRect * p0, int32_t p1, int32_t p2, const uint8_t * p3, uintptr_t n3, R4SdkGuiModalDialog *output) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,331u,a,4u,output);
}
/* gui.ModalDialog.titleRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiModalDialog_titleRect(uint32_t reserved, const R4SdkGuiModalDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,332u,a,1u,output);
}
/* gui.ModalDialog.contentRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiModalDialog_contentRect(uint32_t reserved, const R4SdkGuiModalDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,333u,a,1u,output);
}
/* gui.ModalDialog.buttonBarRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiModalDialog_buttonBarRect(uint32_t reserved, const R4SdkGuiModalDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,334u,a,1u,output);
}
/* gui.ModalDialog.statusRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiModalDialog_statusRect(uint32_t reserved, const R4SdkGuiModalDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,335u,a,1u,output);
}
/* gui.ModalDialog.buttonRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiModalDialog_buttonRect(uint32_t reserved, const R4SdkGuiModalDialog * p0, uint64_t p1, uint64_t p2, uint32_t p3, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,336u,a,4u,output);
}
/* gui.ModalDialog.buttonActionAt -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGuiModalDialog_buttonActionAt(uint32_t reserved, const R4SdkGuiModalDialog * p0, const R4SdkGuiDialogButton * p1, uintptr_t n1, uint32_t p2, int32_t p3, int32_t p4) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,337u,a,5u,0);
}
/* gui.ModalDialog.hitTest -> gui.ModalHit */
static inline R4SdkGuiSlot R4SdkGuiModalDialog_hitTest(uint32_t reserved, const R4SdkGuiModalDialog * p0, const R4SdkGuiDialogButton * p1, uintptr_t n1, uint32_t p2, int32_t p3, int32_t p4, R4SdkGuiModalHit *output) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,338u,a,5u,output);
}
/* gui.ModalDialog.drawFrame -> i32 */
static inline R4SdkGuiSlot R4SdkGuiModalDialog_drawFrame(uint32_t reserved, const R4SdkGuiModalDialog * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,339u,a,3u,0);
}
/* gui.ModalDialog.drawButtons -> i32 */
static inline R4SdkGuiSlot R4SdkGuiModalDialog_drawButtons(uint32_t reserved, const R4SdkGuiModalDialog * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2, const R4SdkGuiDialogButton * p3, uintptr_t n3, uint32_t p4) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,340u,a,5u,0);
}
/* gui.ModalOverlay.capturesInput -> bool */
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_capturesInput(uint32_t reserved, const R4SdkGuiModalOverlay * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,341u,a,3u,0);
}
/* gui.ModalOverlay.hitTest -> gui.ModalHit */
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_hitTest(uint32_t reserved, const R4SdkGuiModalOverlay * p0, const R4SdkGuiDialogButton * p1, uintptr_t n1, uint32_t p2, int32_t p3, int32_t p4, R4SdkGuiModalHit *output) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,342u,a,5u,output);
}
/* gui.ModalOverlay.actionAt -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_actionAt(uint32_t reserved, const R4SdkGuiModalOverlay * p0, const R4SdkGuiDialogButton * p1, uintptr_t n1, uint32_t p2, int32_t p3, int32_t p4) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,343u,a,5u,0);
}
/* gui.MessageDialog.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_draw(uint32_t reserved, const R4SdkGuiMessageDialog * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,344u,a,3u,0);
}
/* gui.MessageDialog.okRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_okRect(uint32_t reserved, const R4SdkGuiMessageDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,345u,a,1u,output);
}
/* gui.MessageDialog.yesRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_yesRect(uint32_t reserved, const R4SdkGuiMessageDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,346u,a,1u,output);
}
/* gui.MessageDialog.noRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_noRect(uint32_t reserved, const R4SdkGuiMessageDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,347u,a,1u,output);
}
/* gui.MessageDialog.cancelRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_cancelRect(uint32_t reserved, const R4SdkGuiMessageDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,348u,a,1u,output);
}
/* gui.MessageDialog.actionAt -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_actionAt(uint32_t reserved, const R4SdkGuiMessageDialog * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,349u,a,3u,0);
}
/* gui.MessageDialog.keyAction -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_keyAction(uint32_t reserved, const R4SdkGuiMessageDialog * p0, uint8_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,350u,a,2u,0);
}
/* gui.FileDialog.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiFileDialog_draw(uint32_t reserved, const R4SdkGuiFileDialog * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,351u,a,3u,0);
}
/* gui.FileDialog.listRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiFileDialog_listRect(uint32_t reserved, const R4SdkGuiFileDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,352u,a,1u,output);
}
/* gui.FileDialog.fileNameRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiFileDialog_fileNameRect(uint32_t reserved, const R4SdkGuiFileDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,353u,a,1u,output);
}
/* gui.FileDialog.okRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiFileDialog_okRect(uint32_t reserved, const R4SdkGuiFileDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,354u,a,1u,output);
}
/* gui.FileDialog.cancelRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiFileDialog_cancelRect(uint32_t reserved, const R4SdkGuiFileDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,355u,a,1u,output);
}
/* gui.FileDialog.indexAt -> ?usize */
static inline R4SdkGuiSlot R4SdkGuiFileDialog_indexAt(uint32_t reserved, const R4SdkGuiFileDialog * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,356u,a,3u,0);
}
/* gui.FileDialog.visibleRows -> usize */
static inline R4SdkGuiSlot R4SdkGuiFileDialog_visibleRows(uint32_t reserved, const R4SdkGuiFileDialog * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,357u,a,1u,0);
}
/* gui.FileDialog.firstIndexForSelection -> usize */
static inline R4SdkGuiSlot R4SdkGuiFileDialog_firstIndexForSelection(uint32_t reserved, const R4SdkGuiFileDialog * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,358u,a,1u,0);
}
/* gui.FileDialog.actionAt -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGuiFileDialog_actionAt(uint32_t reserved, const R4SdkGuiFileDialog * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,359u,a,3u,0);
}
/* gui.FileDialog.keyAction -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGuiFileDialog_keyAction(uint32_t reserved, const R4SdkGuiFileDialog * p0, uint8_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,360u,a,2u,0);
}
/* gui.FileDialog.selectedIndexForAction -> usize */
static inline R4SdkGuiSlot R4SdkGuiFileDialog_selectedIndexForAction(uint32_t reserved, const R4SdkGuiFileDialog * p0, uint32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,361u,a,2u,0);
}
/* gui.InputDialog.draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiInputDialog_draw(uint32_t reserved, const R4SdkGuiInputDialog * p0, const R4SdkGuiCanvas * p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,362u,a,3u,0);
}
/* gui.InputDialog.valueRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiInputDialog_valueRect(uint32_t reserved, const R4SdkGuiInputDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,363u,a,1u,output);
}
/* gui.InputDialog.okRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiInputDialog_okRect(uint32_t reserved, const R4SdkGuiInputDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,364u,a,1u,output);
}
/* gui.InputDialog.cancelRect -> gui.Rect */
static inline R4SdkGuiSlot R4SdkGuiInputDialog_cancelRect(uint32_t reserved, const R4SdkGuiInputDialog * p0, R4SdkGuiRect *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,365u,a,1u,output);
}
/* gui.InputDialog.actionAt -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGuiInputDialog_actionAt(uint32_t reserved, const R4SdkGuiInputDialog * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,366u,a,3u,0);
}
/* gui.InputDialog.keyAction -> gui.DialogAction */
static inline R4SdkGuiSlot R4SdkGuiInputDialog_keyAction(uint32_t reserved, const R4SdkGuiInputDialog * p0, uint8_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,367u,a,2u,0);
}
/* gui.TextArea([]u8).maxTextLen -> usize */
static inline R4SdkGuiSlot R4SdkGuiTextArea_maxTextLen(uint32_t reserved, const R4SdkGuiTextArea * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,368u,a,1u,0);
}
/* gui.TextArea([]u8).value -> []const u8 */
static inline R4SdkGuiSlot R4SdkGuiTextArea_value(uint32_t reserved, const R4SdkGuiTextArea * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,369u,a,1u,0);
}
/* gui.TextArea([]u8).isFull -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_isFull(uint32_t reserved, const R4SdkGuiTextArea * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,370u,a,1u,0);
}
/* gui.TextArea([]u8).available -> usize */
static inline R4SdkGuiSlot R4SdkGuiTextArea_available(uint32_t reserved, const R4SdkGuiTextArea * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,371u,a,1u,0);
}
/* gui.TextArea([]u8).set -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_set(uint32_t reserved, R4SdkGuiTextArea * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,372u,a,2u,0);
}
/* gui.TextArea([]u8).clear -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_clear(uint32_t reserved, R4SdkGuiTextArea * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,373u,a,1u,0);
}
/* gui.TextArea([]u8).selectAll -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_selectAll(uint32_t reserved, R4SdkGuiTextArea * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,374u,a,1u,0);
}
/* gui.TextArea([]u8).clearSelection -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_clearSelection(uint32_t reserved, R4SdkGuiTextArea * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,375u,a,1u,0);
}
/* gui.TextArea([]u8).hasSelection -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_hasSelection(uint32_t reserved, const R4SdkGuiTextArea * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,376u,a,1u,0);
}
/* gui.TextArea([]u8).selectionRange -> gui.TextRange */
static inline R4SdkGuiSlot R4SdkGuiTextArea_selectionRange(uint32_t reserved, const R4SdkGuiTextArea * p0, R4SdkGuiTextRange *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,377u,a,1u,output);
}
/* gui.TextArea([]u8).setSelection -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_setSelection(uint32_t reserved, R4SdkGuiTextArea * p0, uint64_t p1, uint64_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,378u,a,3u,0);
}
/* gui.TextArea([]u8).selectedValue -> []const u8 */
static inline R4SdkGuiSlot R4SdkGuiTextArea_selectedValue(uint32_t reserved, const R4SdkGuiTextArea * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,379u,a,1u,0);
}
/* gui.TextArea([]u8).copySelection -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_copySelection(uint32_t reserved, const R4SdkGuiTextArea * p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,380u,a,2u,0);
}
/* gui.TextArea([]u8).cutSelection -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_cutSelection(uint32_t reserved, R4SdkGuiTextArea * p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,381u,a,2u,0);
}
/* gui.TextArea([]u8).copyToClipboard -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_copyToClipboard(uint32_t reserved, const R4SdkGuiTextArea * p0, const R4SdkGuiDesktopContext * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,382u,a,2u,0);
}
/* gui.TextArea([]u8).cutToClipboard -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_cutToClipboard(uint32_t reserved, R4SdkGuiTextArea * p0, const R4SdkGuiDesktopContext * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,383u,a,2u,0);
}
/* gui.TextArea([]u8).pasteFromClipboard -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_pasteFromClipboard(uint32_t reserved, R4SdkGuiTextArea * p0, const R4SdkGuiDesktopContext * p1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,384u,a,3u,0);
}
/* gui.TextArea([]u8).pasteSlice -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_pasteSlice(uint32_t reserved, R4SdkGuiTextArea * p0, const uint8_t * p1, uintptr_t n1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,385u,a,3u,0);
}
/* gui.TextArea([]u8).insertByte -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_insertByte(uint32_t reserved, R4SdkGuiTextArea * p0, uint8_t p1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,386u,a,3u,0);
}
/* gui.TextArea([]u8).insertSlice -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_insertSlice(uint32_t reserved, R4SdkGuiTextArea * p0, const uint8_t * p1, uintptr_t n1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,387u,a,3u,0);
}
/* gui.TextArea([]u8).deleteSelection -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_deleteSelection(uint32_t reserved, R4SdkGuiTextArea * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,388u,a,1u,0);
}
/* gui.TextArea([]u8).deleteBackward -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_deleteBackward(uint32_t reserved, R4SdkGuiTextArea * p0, const R4SdkGuiTextAreaView * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,389u,a,2u,0);
}
/* gui.TextArea([]u8).deleteForward -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_deleteForward(uint32_t reserved, R4SdkGuiTextArea * p0, const R4SdkGuiTextAreaView * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,390u,a,2u,0);
}
/* gui.TextArea([]u8).removeRange -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_removeRange(uint32_t reserved, R4SdkGuiTextArea * p0, uint64_t p1, uint64_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,391u,a,3u,0);
}
/* gui.TextArea([]u8).moveCursorTo -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_moveCursorTo(uint32_t reserved, R4SdkGuiTextArea * p0, uint64_t p1, uint8_t p2, const R4SdkGuiTextAreaView * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,392u,a,4u,0);
}
/* gui.TextArea([]u8).moveLeft -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_moveLeft(uint32_t reserved, R4SdkGuiTextArea * p0, uint8_t p1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,393u,a,3u,0);
}
/* gui.TextArea([]u8).moveRight -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_moveRight(uint32_t reserved, R4SdkGuiTextArea * p0, uint8_t p1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,394u,a,3u,0);
}
/* gui.TextArea([]u8).moveHome -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_moveHome(uint32_t reserved, R4SdkGuiTextArea * p0, uint8_t p1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,395u,a,3u,0);
}
/* gui.TextArea([]u8).moveEnd -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_moveEnd(uint32_t reserved, R4SdkGuiTextArea * p0, uint8_t p1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,396u,a,3u,0);
}
/* gui.TextArea([]u8).moveVertical -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_moveVertical(uint32_t reserved, R4SdkGuiTextArea * p0, int32_t p1, uint8_t p2, const R4SdkGuiTextAreaView * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,397u,a,4u,0);
}
/* gui.TextArea([]u8).handleKey -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_handleKey(uint32_t reserved, R4SdkGuiTextArea * p0, uint8_t p1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,398u,a,3u,0);
}
/* gui.TextArea([]u8).handleKeyEx -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_handleKeyEx(uint32_t reserved, R4SdkGuiTextArea * p0, uint8_t p1, uint8_t p2, const R4SdkGuiTextAreaView * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,399u,a,4u,0);
}
/* gui.TextArea([]u8).handleCodepointEx -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_handleCodepointEx(uint32_t reserved, R4SdkGuiTextArea * p0, uint32_t p1, uint8_t p2, const R4SdkGuiTextAreaView * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,400u,a,4u,0);
}
/* gui.TextArea([]u8).handleClipboardKey -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextArea_handleClipboardKey(uint32_t reserved, R4SdkGuiTextArea * p0, const R4SdkGuiDesktopContext * p1, uint8_t p2, const R4SdkGuiTextAreaView * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,401u,a,4u,0);
}
/* gui.TextArea([]u8).beginMouseSelection -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_beginMouseSelection(uint32_t reserved, R4SdkGuiTextArea * p0, uint64_t p1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,402u,a,3u,0);
}
/* gui.TextArea([]u8).dragMouseSelection -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_dragMouseSelection(uint32_t reserved, R4SdkGuiTextArea * p0, uint64_t p1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,403u,a,3u,0);
}
/* gui.TextArea([]u8).finishMouseSelection -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_finishMouseSelection(uint32_t reserved, R4SdkGuiTextArea * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,404u,a,1u,0);
}
/* gui.TextArea([]u8).hitTest -> usize */
static inline R4SdkGuiSlot R4SdkGuiTextArea_hitTest(uint32_t reserved, const R4SdkGuiTextArea * p0, int32_t p1, int32_t p2, int32_t p3, int32_t p4, const R4SdkGuiTextAreaView * p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,405u,a,6u,0);
}
/* gui.TextArea([]u8).scrollTo -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_scrollTo(uint32_t reserved, R4SdkGuiTextArea * p0, uint64_t p1, uint64_t p2, const R4SdkGuiTextAreaView * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,406u,a,4u,0);
}
/* gui.TextArea([]u8).scrollByLines -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_scrollByLines(uint32_t reserved, R4SdkGuiTextArea * p0, int32_t p1, const R4SdkGuiTextAreaView * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,407u,a,3u,0);
}
/* gui.TextArea([]u8).clampScroll -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_clampScroll(uint32_t reserved, R4SdkGuiTextArea * p0, const R4SdkGuiTextAreaView * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,408u,a,2u,0);
}
/* gui.TextArea([]u8).ensureCursorVisible -> void */
static inline R4SdkGuiSlot R4SdkGuiTextArea_ensureCursorVisible(uint32_t reserved, R4SdkGuiTextArea * p0, const R4SdkGuiTextAreaView * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,409u,a,2u,0);
}
/* gui.TextArea([]u8).draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiTextArea_draw(uint32_t reserved, const R4SdkGuiTextArea * p0, const R4SdkGuiCanvas * p1, const R4SdkGuiRect * p2, uint8_t * p3, uintptr_t n3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,410u,a,4u,0);
}
/* gui.TextField([]u8).value -> []const u8 */
static inline R4SdkGuiSlot R4SdkGuiTextField_value(uint32_t reserved, const R4SdkGuiTextField * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,411u,a,1u,0);
}
/* gui.TextField([]u8).set -> void */
static inline R4SdkGuiSlot R4SdkGuiTextField_set(uint32_t reserved, R4SdkGuiTextField * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,412u,a,2u,0);
}
/* gui.TextField([]u8).setExact -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextField_setExact(uint32_t reserved, R4SdkGuiTextField * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,413u,a,2u,0);
}
/* gui.TextField([]u8).setSelection -> void */
static inline R4SdkGuiSlot R4SdkGuiTextField_setSelection(uint32_t reserved, R4SdkGuiTextField * p0, uint64_t p1, uint64_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,414u,a,3u,0);
}
/* gui.TextField([]u8).handleCodepointChecked -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextField_handleCodepointChecked(uint32_t reserved, R4SdkGuiTextField * p0, uint32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,415u,a,2u,0);
}
/* gui.TextField([]u8).clear -> void */
static inline R4SdkGuiSlot R4SdkGuiTextField_clear(uint32_t reserved, R4SdkGuiTextField * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,416u,a,1u,0);
}
/* gui.TextField([]u8).selectAll -> void */
static inline R4SdkGuiSlot R4SdkGuiTextField_selectAll(uint32_t reserved, R4SdkGuiTextField * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,417u,a,1u,0);
}
/* gui.TextField([]u8).clearSelection -> void */
static inline R4SdkGuiSlot R4SdkGuiTextField_clearSelection(uint32_t reserved, R4SdkGuiTextField * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,418u,a,1u,0);
}
/* gui.TextField([]u8).hasSelection -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextField_hasSelection(uint32_t reserved, const R4SdkGuiTextField * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,419u,a,1u,0);
}
/* gui.TextField([]u8).selectionRange -> gui.TextField([]u8).selectionRange__struct_ */
static inline R4SdkGuiSlot R4SdkGuiTextField_selectionRange(uint32_t reserved, const R4SdkGuiTextField * p0, R4SdkGuiType202 *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,420u,a,1u,output);
}
/* gui.TextField([]u8).handleKey -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextField_handleKey(uint32_t reserved, R4SdkGuiTextField * p0, uint8_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,421u,a,2u,0);
}
/* gui.TextField([]u8).handleCodepoint -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextField_handleCodepoint(uint32_t reserved, R4SdkGuiTextField * p0, uint32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,422u,a,2u,0);
}
/* gui.TextField([]u8).handleClipboardCodepoint -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextField_handleClipboardCodepoint(uint32_t reserved, R4SdkGuiTextField * p0, const R4SdkGuiDesktopContext * p1, uint32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,423u,a,3u,0);
}
/* gui.TextField([]u8).handleClipboardKey -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextField_handleClipboardKey(uint32_t reserved, R4SdkGuiTextField * p0, const R4SdkGuiDesktopContext * p1, uint8_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,424u,a,3u,0);
}
/* gui.TextField([]u8).copyToClipboard -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextField_copyToClipboard(uint32_t reserved, const R4SdkGuiTextField * p0, const R4SdkGuiDesktopContext * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,425u,a,2u,0);
}
/* gui.TextField([]u8).cutToClipboard -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextField_cutToClipboard(uint32_t reserved, R4SdkGuiTextField * p0, const R4SdkGuiDesktopContext * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,426u,a,2u,0);
}
/* gui.TextField([]u8).pasteFromClipboard -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextField_pasteFromClipboard(uint32_t reserved, R4SdkGuiTextField * p0, const R4SdkGuiDesktopContext * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,427u,a,2u,0);
}
/* gui.TextField([]u8).pasteSlice -> bool */
static inline R4SdkGuiSlot R4SdkGuiTextField_pasteSlice(uint32_t reserved, R4SdkGuiTextField * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,428u,a,2u,0);
}
/* gui.TextField([]u8).draw -> i32 */
static inline R4SdkGuiSlot R4SdkGuiTextField_draw(uint32_t reserved, const R4SdkGuiTextField * p0, const R4SdkGuiCanvas * p1, const R4SdkGuiRect * p2, uint8_t * p3, uintptr_t n3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,429u,a,4u,0);
}
/* r4desk.Context.readKey -> u8 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_readKey(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,430u,a,1u,0);
}
/* r4desk.Context.readKeyCodepoint -> u32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_readKeyCodepoint(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,431u,a,1u,0);
}
/* r4desk.Context.mouseState -> void */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_mouseState(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4Mouse * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,432u,a,2u,0);
}
/* r4desk.Context.mouseMotion -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_mouseMotion(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4MouseMotion * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,433u,a,2u,0);
}
/* r4desk.Context.remoteFrameSnapshotAcquire -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFrameSnapshotAcquire(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, R4RemoteFrameInfo * p2, R4RemoteFrameLease * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,434u,a,4u,0);
}
/* r4desk.Context.remoteFrameSnapshotRelease -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFrameSnapshotRelease(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const R4RemoteFrameLease * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,435u,a,2u,0);
}
/* r4desk.Context.remoteFrameSourceReset -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFrameSourceReset(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,436u,a,1u,0);
}
/* r4desk.Context.remoteFrameCaptureStats -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFrameCaptureStats(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4RemoteFrameCaptureStats * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,437u,a,2u,0);
}
/* r4desk.Context.mouseShow -> void */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_mouseShow(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,438u,a,1u,0);
}
/* r4desk.Context.mouseHide -> void */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_mouseHide(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,439u,a,1u,0);
}
/* r4desk.Context.keyboardLayoutCurrent -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_keyboardLayoutCurrent(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4KeyboardLayoutInfo * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,440u,a,2u,0);
}
/* r4desk.Context.keyboardLayoutAt -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_keyboardLayoutAt(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, R4KeyboardLayoutInfo * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,441u,a,3u,0);
}
/* r4desk.Context.keyboardLayoutSet -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_keyboardLayoutSet(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const uint8_t * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,442u,a,2u,0);
}
/* r4desk.Context.programSetWindow -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_programSetWindow(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,443u,a,3u,0);
}
/* r4desk.Context.programSetWindowHandle -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_programSetWindowHandle(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const R4ProgramProcessHandle * p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,444u,a,3u,0);
}
/* r4desk.Context.programSetConsoleHost -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_programSetConsoleHost(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, uint32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,445u,a,3u,0);
}
/* r4desk.Context.programSpawnWithConsoleHost -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_programSpawnWithConsoleHost(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const uint8_t * p1, const uint8_t * p2, uint32_t p3, uint32_t p4) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,446u,a,5u,0);
}
/* r4desk.Context.programSpawnWithConsoleHostHandle -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_programSpawnWithConsoleHostHandle(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const uint8_t * p1, const uint8_t * p2, uint32_t p3, uint32_t p4, R4ProgramProcessHandle * p5) {
 (void)reserved; R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,447u,a,6u,0);
}
/* r4desk.Context.programRequestHostLaunch -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_programRequestHostLaunch(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const uint8_t * p1, const uint8_t * p2, uint32_t p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,448u,a,4u,0);
}
/* r4desk.Context.programTakeHostLaunch -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_programTakeHostLaunch(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, R4ProgramHostLaunchRequest * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,449u,a,3u,0);
}
/* r4desk.Context.programWindowId -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_programWindowId(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,450u,a,1u,0);
}
/* r4desk.Context.guiWindowInfo -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiWindowInfo(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4GuiWindowInfo * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,451u,a,2u,0);
}
/* r4desk.Context.guiSetWindowInfo -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiSetWindowInfo(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, const R4GuiWindowInfo * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,452u,a,3u,0);
}
/* r4desk.Context.guiPollEvent -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiPollEvent(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4GuiEvent * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,453u,a,2u,0);
}
/* r4desk.Context.guiPushEvent -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiPushEvent(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, const R4GuiEvent * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,454u,a,3u,0);
}
/* r4desk.Context.guiSetText -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiSetText(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const uint8_t * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,455u,a,2u,0);
}
/* r4desk.Context.guiText -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiText(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,456u,a,3u,0);
}
/* r4desk.Context.guiRevision -> u32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiRevision(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,457u,a,2u,0);
}
/* r4desk.Context.guiCommand -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiCommand(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, uint32_t p2, R4GuiCommand * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,458u,a,4u,0);
}
/* r4desk.Context.guiSetTitle -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiSetTitle(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const uint8_t * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,459u,a,2u,0);
}
/* r4desk.Context.guiTitle -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiTitle(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,460u,a,3u,0);
}
/* r4desk.Context.guiSetMinSize -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiSetMinSize(uint32_t reserved, const R4SdkGuiDesktopContext * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,461u,a,3u,0);
}
/* r4desk.Context.guiMinSize -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_guiMinSize(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, R4GuiSize * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,462u,a,3u,0);
}
/* r4desk.Context.consoleOutput -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_consoleOutput(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,463u,a,3u,0);
}
/* r4desk.Context.consoleRevision -> u32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_consoleRevision(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,464u,a,2u,0);
}
/* r4desk.Context.consoleState -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_consoleState(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, R4ConsoleState * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,465u,a,3u,0);
}
/* r4desk.Context.consoleSetMetrics -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_consoleSetMetrics(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, uint32_t p2, uint32_t p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,466u,a,4u,0);
}
/* r4desk.Context.consolePushKey -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_consolePushKey(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, uint8_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,467u,a,3u,0);
}
/* r4desk.Context.consolePushInput -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_consolePushInput(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, const uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,468u,a,3u,0);
}
/* r4desk.Context.consoleWrite -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_consoleWrite(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, const uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,469u,a,3u,0);
}
/* r4desk.Context.stdout -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_stdout(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,470u,a,2u,0);
}
/* r4desk.Context.stderr -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_stderr(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,471u,a,2u,0);
}
/* r4desk.Context.consoleRead -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_consoleRead(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,472u,a,2u,0);
}
/* r4desk.Context.consoleInputWait -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_consoleInputWait(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint64_t p1, uint64_t p2, uint64_t * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,473u,a,4u,0);
}
/* r4desk.Context.physicalKeyPoll -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_physicalKeyPoll(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4PhysicalKeyEvent * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,474u,a,2u,0);
}
/* r4desk.Context.clipboardWrite -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_clipboardWrite(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,475u,a,2u,0);
}
/* r4desk.Context.clipboardRead -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_clipboardRead(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,476u,a,2u,0);
}
/* r4desk.Context.clipboardRevision -> u32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_clipboardRevision(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,477u,a,1u,0);
}
/* r4desk.Context.clipboardInfo -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_clipboardInfo(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4ClipboardInfo * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,478u,a,2u,0);
}
/* r4desk.Context.clipboardClear -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_clipboardClear(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,479u,a,1u,0);
}
/* r4desk.Context.supportsRemoteFrame -> bool */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_supportsRemoteFrame(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,480u,a,1u,0);
}
/* r4desk.Context.remoteFrameInfo -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFrameInfo(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4RemoteFrameInfo * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,481u,a,2u,0);
}
/* r4desk.Context.remoteFrameRead -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFrameRead(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, uint32_t * p2, uintptr_t n2, R4RemoteFrameInfo * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,482u,a,4u,0);
}
/* r4desk.Context.remoteFrameWait -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFrameWait(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint32_t p1, uint64_t p2, R4RemoteFrameInfo * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,483u,a,4u,0);
}
/* r4desk.Context.desktopActivityWait -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_desktopActivityWait(uint32_t reserved, const R4SdkGuiDesktopContext * p0, uint64_t p1, uint64_t p2, uint64_t * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,484u,a,4u,0);
}
/* r4desk.Context.desktopActivityNotify -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_desktopActivityNotify(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,485u,a,1u,0);
}
/* r4desk.Context.supportsRemoteFrameMap -> bool */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_supportsRemoteFrameMap(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,486u,a,1u,0);
}
/* r4desk.Context.remoteFrameMap -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFrameMap(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4RemoteFrameMapInfo * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,487u,a,2u,0);
}
/* r4desk.Context.remoteFramePublish -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFramePublish(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const R4RemoteFrameInfo * p1, const uint32_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,488u,a,3u,0);
}
/* r4desk.Context.supportsRemoteFrameRegions -> bool */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_supportsRemoteFrameRegions(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,489u,a,1u,0);
}
/* r4desk.Context.remoteFramePublishRegions -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFramePublishRegions(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const R4RemoteFrameInfo * p1, const uint32_t * p2, uintptr_t n2, const R4DisplayDamageRect * p3, uintptr_t n3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,490u,a,4u,0);
}
/* r4desk.Context.supportsRemoteFrameDemand -> bool */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_supportsRemoteFrameDemand(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,491u,a,1u,0);
}
/* r4desk.Context.remoteFrameAcquire -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFrameAcquire(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,492u,a,1u,0);
}
/* r4desk.Context.remoteFrameRelease -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFrameRelease(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,493u,a,1u,0);
}
/* r4desk.Context.remoteFrameConsumers -> u32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteFrameConsumers(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,494u,a,1u,0);
}
/* r4desk.Context.supportsRemoteInput -> bool */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_supportsRemoteInput(uint32_t reserved, const R4SdkGuiDesktopContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,495u,a,1u,0);
}
/* r4desk.Context.remoteInputPush -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteInputPush(uint32_t reserved, const R4SdkGuiDesktopContext * p0, const R4RemoteInputEvent * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,496u,a,2u,0);
}
/* r4desk.Context.remoteInputPoll -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteInputPoll(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4RemoteInputEvent * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,497u,a,2u,0);
}
/* r4desk.Context.remoteInputStatus -> i32 */
static inline R4SdkGuiSlot R4SdkGuiDesktopContext_remoteInputStatus(uint32_t reserved, const R4SdkGuiDesktopContext * p0, R4RemoteInputStatus * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,498u,a,2u,0);
}
/* app_gui.CommandId.init -> app_gui.CommandId */
static inline R4SdkGuiSlot R4SdkGuiCommandId_init(uint32_t reserved, uint32_t p0, R4SdkGuiCommandId *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,499u,a,1u,output);
}
/* app_gui.TimerId.init -> app_gui.TimerId */
static inline R4SdkGuiSlot R4SdkGuiTimerId_init(uint32_t reserved, uint32_t p0, R4SdkGuiTimerId *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,500u,a,1u,output);
}
/* app_gui.Message.guiEvent -> ?abi_generated.GuiEvent */
static inline R4SdkGuiSlot R4SdkGuiMessage_guiEvent(uint32_t reserved, const R4SdkGuiMessage * p0, R4GuiEvent *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,501u,a,1u,output);
}
/* app_gui.Timer.start -> bool */
static inline R4SdkGuiSlot R4SdkGuiTimer_start(uint32_t reserved, R4SdkGuiTimer * p0, const R4SdkGuiSystemContext * p1, const R4SdkGuiTimerId * p2, const R4Duration * p3, uint8_t p4) {
 (void)reserved; R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,502u,a,5u,0);
}
/* app_gui.Timer.cancel -> void */
static inline R4SdkGuiSlot R4SdkGuiTimer_cancel(uint32_t reserved, R4SdkGuiTimer * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,503u,a,1u,0);
}
/* app_gui.EventLoop.init -> app_gui.EventLoop */
static inline R4SdkGuiSlot R4SdkGuiEventLoop_init(uint32_t reserved, const R4SdkGuiSystemContext * p0, const R4SdkGuiDesktopContext * p1, R4SdkGuiTimer * p2, uintptr_t n2, R4SdkGuiEventLoop *output) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,504u,a,3u,output);
}
/* app_gui.EventLoop.postCommand -> bool */
static inline R4SdkGuiSlot R4SdkGuiEventLoop_postCommand(uint32_t reserved, R4SdkGuiEventLoop * p0, const R4SdkGuiCommandId * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,505u,a,2u,0);
}
/* app_gui.EventLoop.poll -> ?app_gui.Message */
static inline R4SdkGuiSlot R4SdkGuiEventLoop_poll(uint32_t reserved, R4SdkGuiEventLoop * p0, R4SdkGuiMessage *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,506u,a,1u,output);
}
/* app_gui.EventLoop.wait -> app_gui.WaitResult */
static inline R4SdkGuiSlot R4SdkGuiEventLoop_wait(uint32_t reserved, R4SdkGuiEventLoop * p0, const R4Timeout * p1, R4SdkGuiWaitResult *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,507u,a,2u,output);
}
/* app_gui.PaintContext.bufferedCanvas -> gui.Canvas */
static inline R4SdkGuiSlot R4SdkGuiPaintContext_bufferedCanvas(uint32_t reserved, R4SdkGuiPaintContext * p0, R4SdkGuiFrameCanvas * p1, R4GuiFrameCommand * p2, uintptr_t n2, uint8_t * p3, uintptr_t n3, R4SdkGuiCanvas *output) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,508u,a,4u,output);
}
/* app_gui.PaintContext.present -> i32 */
static inline R4SdkGuiSlot R4SdkGuiPaintContext_present(uint32_t reserved, R4SdkGuiPaintContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,509u,a,1u,0);
}
/* app_gui.PaintContext.discard -> void */
static inline R4SdkGuiSlot R4SdkGuiPaintContext_discard(uint32_t reserved, R4SdkGuiPaintContext * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,510u,a,1u,0);
}
/* app_gui.Window.init -> ?app_gui.Window */
static inline R4SdkGuiSlot R4SdkGuiWindow_init(uint32_t reserved, const R4SdkGuiSystemContext * p0, const R4SdkGuiDesktopContext * p1, const R4SdkGuiDrawContext * p2, R4SdkGuiTimer * p3, uintptr_t n3, R4SdkGuiWindow *output) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,511u,a,4u,output);
}
/* app_gui.Window.setTitle -> i32 */
static inline R4SdkGuiSlot R4SdkGuiWindow_setTitle(uint32_t reserved, R4SdkGuiWindow * p0, const uint8_t * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,512u,a,2u,0);
}
/* app_gui.Window.setMinimumSize -> i32 */
static inline R4SdkGuiSlot R4SdkGuiWindow_setMinimumSize(uint32_t reserved, R4SdkGuiWindow * p0, int32_t p1, int32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,513u,a,3u,0);
}
/* app_gui.Window.info -> ?abi_generated.GuiWindowInfo */
static inline R4SdkGuiSlot R4SdkGuiWindow_info(uint32_t reserved, R4SdkGuiWindow * p0, R4GuiWindowInfo *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,514u,a,1u,output);
}
/* app_gui.Window.beginPaint -> app_gui.PaintOpen */
static inline R4SdkGuiSlot R4SdkGuiWindow_beginPaint(uint32_t reserved, R4SdkGuiWindow * p0, R4SdkGuiPaintOpen *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,515u,a,1u,output);
}
/* app_gui.Window.pollMessage -> ?app_gui.Message */
static inline R4SdkGuiSlot R4SdkGuiWindow_pollMessage(uint32_t reserved, R4SdkGuiWindow * p0, R4SdkGuiMessage *output) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,516u,a,1u,output);
}
/* app_gui.Window.waitMessage -> app_gui.WaitResult */
static inline R4SdkGuiSlot R4SdkGuiWindow_waitMessage(uint32_t reserved, R4SdkGuiWindow * p0, const R4Timeout * p1, R4SdkGuiWaitResult *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,517u,a,2u,output);
}
/* gui_shapes.PathBuilder.init -> error{BufferTooSmall,InvalidValue,SegmentLimit}!gui_shapes.PathBuilder */
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_init(uint32_t reserved, uint8_t * p0, uintptr_t n0, const R4SdkGuiShapePathStyle * p1, R4SdkGuiShapePathBuilder *output) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,518u,a,2u,output);
}
/* gui_shapes.PathBuilder.moveTo -> error{BufferTooSmall,InvalidValue,SegmentLimit}!void */
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_moveTo(uint32_t reserved, R4SdkGuiShapePathBuilder * p0, const R4SdkGuiShapePoint * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,519u,a,2u,0);
}
/* gui_shapes.PathBuilder.lineTo -> error{BufferTooSmall,InvalidValue,SegmentLimit}!void */
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_lineTo(uint32_t reserved, R4SdkGuiShapePathBuilder * p0, const R4SdkGuiShapePoint * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,520u,a,2u,0);
}
/* gui_shapes.PathBuilder.quadraticTo -> error{BufferTooSmall,InvalidValue,SegmentLimit}!void */
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_quadraticTo(uint32_t reserved, R4SdkGuiShapePathBuilder * p0, const R4SdkGuiShapePoint * p1, const R4SdkGuiShapePoint * p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,521u,a,3u,0);
}
/* gui_shapes.PathBuilder.cubicTo -> error{BufferTooSmall,InvalidValue,SegmentLimit}!void */
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_cubicTo(uint32_t reserved, R4SdkGuiShapePathBuilder * p0, const R4SdkGuiShapePoint * p1, const R4SdkGuiShapePoint * p2, const R4SdkGuiShapePoint * p3) {
 (void)reserved; R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,522u,a,4u,0);
}
/* gui_shapes.PathBuilder.close -> error{BufferTooSmall,InvalidValue,SegmentLimit}!void */
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_close(uint32_t reserved, R4SdkGuiShapePathBuilder * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,523u,a,1u,0);
}
/* gui_shapes.PathBuilder.finish -> error{BufferTooSmall,InvalidValue,SegmentLimit}![]const u8 */
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_finish(uint32_t reserved, R4SdkGuiShapePathBuilder * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,524u,a,1u,0);
}
/* clipboard.ReadResult.ok -> bool */
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_ok(uint32_t reserved, const R4SdkGuiClipboardReadResult * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,525u,a,1u,0);
}
/* input_events.Queue([]abi_generated.ConsoleInputEvent).append -> bool */
static inline R4SdkGuiSlot R4SdkGuiInputQueue_append(uint32_t reserved, R4SdkGuiInputQueue * p0, const R4ConsoleInputEvent * p1, uintptr_t n1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,526u,a,2u,0);
}
/* input_events.Queue([]abi_generated.ConsoleInputEvent).peek -> []const abi_generated.ConsoleInputEvent */
static inline R4SdkGuiSlot R4SdkGuiInputQueue_peek(uint32_t reserved, const R4SdkGuiInputQueue * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,527u,a,1u,0);
}
/* input_events.Queue([]abi_generated.ConsoleInputEvent).consume -> bool */
static inline R4SdkGuiSlot R4SdkGuiInputQueue_consume(uint32_t reserved, R4SdkGuiInputQueue * p0, uint64_t p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,528u,a,2u,0);
}
/* input_events.Queue([]abi_generated.ConsoleInputEvent).clear -> void */
static inline R4SdkGuiSlot R4SdkGuiInputQueue_clear(uint32_t reserved, R4SdkGuiInputQueue * p0) {
 (void)reserved; R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,529u,a,1u,0);
}
/* window_mode.Client.poll -> bool */
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_poll(uint32_t reserved, R4SdkGuiWindowModeClient * p0, const R4SdkGuiSystemContext * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,530u,a,2u,0);
}
/* window_mode.Client.set -> bool */
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_set(uint32_t reserved, R4SdkGuiWindowModeClient * p0, const R4SdkGuiSystemContext * p1, uint32_t p2) {
 (void)reserved; R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,531u,a,3u,0);
}
/* window_mode.Client.retry -> bool */
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_retry(uint32_t reserved, R4SdkGuiWindowModeClient * p0, const R4SdkGuiSystemContext * p1) {
 (void)reserved; R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiInvoke(R4SdkGui_ABI_FINGERPRINT,532u,a,2u,0);
}
static inline R4SdkGuiSlot R4SdkGuiAlign_create(R4SdkGuiAlign *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,0u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiAlign_inspect(const R4SdkGuiAlign *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,0u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_create(R4SdkGuiPalette *output) {
 R4SdkGuiSlot a[10]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 a[9].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,1u,a,10u,output);
}
static inline R4SdkGuiSlot R4SdkGuiPalette_from_fields(R4SdkGuiPalette *output, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9) {
 R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,1u,a,10u,output);
}
static inline R4SdkGuiSlot R4SdkGuiPalette_get_text(const R4SdkGuiPalette *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_set_text(R4SdkGuiPalette *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_get_disabled_text(const R4SdkGuiPalette *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_set_disabled_text(R4SdkGuiPalette *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_get_face(const R4SdkGuiPalette *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_set_face(R4SdkGuiPalette *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_get_face_light(const R4SdkGuiPalette *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_set_face_light(R4SdkGuiPalette *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_get_face_shadow(const R4SdkGuiPalette *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_set_face_shadow(R4SdkGuiPalette *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_get_client_bg(const R4SdkGuiPalette *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_set_client_bg(R4SdkGuiPalette *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_get_select_bg(const R4SdkGuiPalette *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_set_select_bg(R4SdkGuiPalette *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_get_select_text(const R4SdkGuiPalette *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,7u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_set_select_text(R4SdkGuiPalette *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_get_title_bg(const R4SdkGuiPalette *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,8u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_set_title_bg(R4SdkGuiPalette *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_get_title_text(const R4SdkGuiPalette *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,9u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_set_title_text(R4SdkGuiPalette *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,1u,9u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPalette_inspect(const R4SdkGuiPalette *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,1u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_create(R4SdkGuiControlMetrics *output) {
 R4SdkGuiSlot a[27]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 a[9].flags=R4SDK_GUI_DEFAULT;
 a[10].flags=R4SDK_GUI_DEFAULT;
 a[11].flags=R4SDK_GUI_DEFAULT;
 a[12].flags=R4SDK_GUI_DEFAULT;
 a[13].flags=R4SDK_GUI_DEFAULT;
 a[14].flags=R4SDK_GUI_DEFAULT;
 a[15].flags=R4SDK_GUI_DEFAULT;
 a[16].flags=R4SDK_GUI_DEFAULT;
 a[17].flags=R4SDK_GUI_DEFAULT;
 a[18].flags=R4SDK_GUI_DEFAULT;
 a[19].flags=R4SDK_GUI_DEFAULT;
 a[20].flags=R4SDK_GUI_DEFAULT;
 a[21].flags=R4SDK_GUI_DEFAULT;
 a[22].flags=R4SDK_GUI_DEFAULT;
 a[23].flags=R4SDK_GUI_DEFAULT;
 a[24].flags=R4SDK_GUI_DEFAULT;
 a[25].flags=R4SDK_GUI_DEFAULT;
 a[26].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,2u,a,27u,output);
}
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_from_fields(R4SdkGuiControlMetrics *output, int32_t p0, int32_t p1, int32_t p2, int32_t p3, int32_t p4, int32_t p5, int32_t p6, int32_t p7, int32_t p8, int32_t p9, int32_t p10, int32_t p11, int32_t p12, int32_t p13, int32_t p14, int32_t p15, int32_t p16, int32_t p17, int32_t p18, int32_t p19, int32_t p20, int32_t p21, int32_t p22, int32_t p23, int32_t p24, int32_t p25, int32_t p26) {
 R4SdkGuiSlot a[27]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDK_GUI_PRESENT};
 a[10] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4SDK_GUI_PRESENT};
 a[11] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4SDK_GUI_PRESENT};
 a[12] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4SDK_GUI_PRESENT};
 a[13] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4SDK_GUI_PRESENT};
 a[14] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4SDK_GUI_PRESENT};
 a[15] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4SDK_GUI_PRESENT};
 a[16] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p16,.flags=R4SDK_GUI_PRESENT};
 a[17] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p17,.flags=R4SDK_GUI_PRESENT};
 a[18] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p18,.flags=R4SDK_GUI_PRESENT};
 a[19] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p19,.flags=R4SDK_GUI_PRESENT};
 a[20] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p20,.flags=R4SDK_GUI_PRESENT};
 a[21] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p21,.flags=R4SDK_GUI_PRESENT};
 a[22] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p22,.flags=R4SDK_GUI_PRESENT};
 a[23] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p23,.flags=R4SDK_GUI_PRESENT};
 a[24] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p24,.flags=R4SDK_GUI_PRESENT};
 a[25] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p25,.flags=R4SDK_GUI_PRESENT};
 a[26] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p26,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,2u,a,27u,output);
}
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_bevel(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_bevel(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_frame_inset(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_frame_inset(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_text_pad_x(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_text_pad_x(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_text_pad_y(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_text_pad_y(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_menu_text_pad_x(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_menu_text_pad_x(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_menu_bar_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_menu_bar_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_menu_bar_pad_x(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_menu_bar_pad_x(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_menu_popup_min_w(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,7u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_menu_popup_min_w(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_dialog_title_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,8u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_dialog_title_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_dialog_button_w(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,9u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_dialog_button_w(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,9u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_dialog_button_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,10u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_dialog_button_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,10u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_dialog_min_w(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,11u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_dialog_min_w(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,11u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_dialog_min_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,12u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_dialog_min_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,12u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_dialog_outer_pad(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,13u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_dialog_outer_pad(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,13u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_dialog_button_gap(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,14u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_dialog_button_gap(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,14u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_dialog_button_margin(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,15u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_dialog_button_margin(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,15u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_dialog_status_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,16u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_dialog_status_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,16u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_text_field_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,17u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_text_field_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,17u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_list_row_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,18u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_list_row_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,18u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_menu_row_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,19u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_menu_row_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,19u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_toolbar_button_w(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,20u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_toolbar_button_w(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,20u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_toolbar_button_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,21u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_toolbar_button_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,21u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_status_bar_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,22u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_status_bar_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,22u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_scrollbar_w(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,23u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_scrollbar_w(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,23u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_tab_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,24u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_tab_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,24u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_table_header_h(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,25u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_table_header_h(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,25u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_get_gap(const R4SdkGuiControlMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,26u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_set_gap(R4SdkGuiControlMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,2u,26u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiControlMetrics_inspect(const R4SdkGuiControlMetrics *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,2u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_create(R4SdkGuiFontMetrics *output) {
 R4SdkGuiSlot a[5]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,3u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_from_fields(R4SdkGuiFontMetrics *output, uint32_t p0, int32_t p1, int32_t p2, int32_t p3, int32_t p4) {
 R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,3u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_get_id(const R4SdkGuiFontMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,3u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_set_id(R4SdkGuiFontMetrics *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,3u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_get_max_advance(const R4SdkGuiFontMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,3u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_set_max_advance(R4SdkGuiFontMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,3u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_get_height(const R4SdkGuiFontMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,3u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_set_height(R4SdkGuiFontMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,3u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_get_line_height(const R4SdkGuiFontMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,3u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_set_line_height(R4SdkGuiFontMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,3u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_get_baseline(const R4SdkGuiFontMetrics *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,3u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_set_baseline(R4SdkGuiFontMetrics *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,3u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFontMetrics_inspect(const R4SdkGuiFontMetrics *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,3u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiKey_create(R4SdkGuiKey *output) {
 R4SdkGuiSlot a[1]={0};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,4u,a,0u,output);
}
static inline R4SdkGuiSlot R4SdkGuiKey_from_fields(R4SdkGuiKey *output) {
 R4SdkGuiSlot a[1]={0};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,4u,a,0u,output);
}
static inline R4SdkGuiSlot R4SdkGuiKey_inspect(const R4SdkGuiKey *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,4u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiControlAction_create(R4SdkGuiControlAction *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,5u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiControlAction_inspect(const R4SdkGuiControlAction *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,5u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusDirection_create(R4SdkGuiFocusDirection *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,6u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiFocusDirection_inspect(const R4SdkGuiFocusDirection *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,6u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusItem_create(R4SdkGuiFocusItem *output) {
 R4SdkGuiSlot a[1]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,7u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFocusItem_from_fields(R4SdkGuiFocusItem *output, uint8_t p0) {
 R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,7u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFocusItem_get_enabled(const R4SdkGuiFocusItem *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,7u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusItem_set_enabled(R4SdkGuiFocusItem *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,7u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusItem_inspect(const R4SdkGuiFocusItem *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,7u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusResult_create(R4SdkGuiFocusResult *output) {
 R4SdkGuiSlot a[2]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,8u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFocusResult_from_fields(R4SdkGuiFocusResult *output, uint32_t p0, uint64_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,8u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFocusResult_get_action(const R4SdkGuiFocusResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,8u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusResult_set_action(R4SdkGuiFocusResult *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,8u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusResult_get_index(const R4SdkGuiFocusResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,8u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusResult_set_index(R4SdkGuiFocusResult *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,8u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusResult_inspect(const R4SdkGuiFocusResult *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,8u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusState_create(R4SdkGuiFocusState *output) {
 R4SdkGuiSlot a[1]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,9u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFocusState_from_fields(R4SdkGuiFocusState *output, uint64_t p0) {
 R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,9u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFocusState_get_index(const R4SdkGuiFocusState *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,9u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusState_set_index(R4SdkGuiFocusState *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,9u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFocusState_inspect(const R4SdkGuiFocusState *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,9u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseCapture_create(R4SdkGuiMouseCapture *output) {
 R4SdkGuiSlot a[2]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,10u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMouseCapture_from_fields(R4SdkGuiMouseCapture *output, R4SdkGuiSlot p0, uint32_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = p0;
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,10u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMouseCapture_get_target(const R4SdkGuiMouseCapture *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,10u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseCapture_set_target(R4SdkGuiMouseCapture *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,10u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseCapture_get_action(const R4SdkGuiMouseCapture *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,10u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseCapture_set_action(R4SdkGuiMouseCapture *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,10u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseCapture_inspect(const R4SdkGuiMouseCapture *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,10u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType11_create(R4SdkGuiType11 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,11u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType11_inspect(const R4SdkGuiType11 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,11u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiSelectionStep_create(R4SdkGuiSelectionStep *output) {
 R4SdkGuiSlot a[2]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,12u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiSelectionStep_from_fields(R4SdkGuiSelectionStep *output, uint32_t p0, uint64_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,12u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiSelectionStep_get_action(const R4SdkGuiSelectionStep *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,12u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiSelectionStep_set_action(R4SdkGuiSelectionStep *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,12u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiSelectionStep_get_index(const R4SdkGuiSelectionStep *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,12u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiSelectionStep_set_index(R4SdkGuiSelectionStep *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,12u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiSelectionStep_inspect(const R4SdkGuiSelectionStep *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,12u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiTextRange_create(R4SdkGuiTextRange *output) {
 R4SdkGuiSlot a[2]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,13u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextRange_from_fields(R4SdkGuiTextRange *output, uint64_t p0, uint64_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,13u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextRange_get_start(const R4SdkGuiTextRange *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,13u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextRange_set_start(R4SdkGuiTextRange *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,13u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextRange_get_end(const R4SdkGuiTextRange *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,13u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextRange_set_end(R4SdkGuiTextRange *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,13u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextRange_inspect(const R4SdkGuiTextRange *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,13u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaPoint_create(R4SdkGuiTextAreaPoint *output) {
 R4SdkGuiSlot a[2]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,14u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextAreaPoint_from_fields(R4SdkGuiTextAreaPoint *output, uint64_t p0, uint64_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,14u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextAreaPoint_get_line(const R4SdkGuiTextAreaPoint *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,14u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaPoint_set_line(R4SdkGuiTextAreaPoint *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,14u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaPoint_get_column(const R4SdkGuiTextAreaPoint *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,14u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaPoint_set_column(R4SdkGuiTextAreaPoint *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,14u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaPoint_inspect(const R4SdkGuiTextAreaPoint *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,14u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_create(R4SdkGuiTextAreaView *output) {
 R4SdkGuiSlot a[3]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,15u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_from_fields(R4SdkGuiTextAreaView *output, uint64_t p0, uint64_t p1, uint64_t p2) {
 R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,15u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_get_visible_cols(const R4SdkGuiTextAreaView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,15u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_set_visible_cols(R4SdkGuiTextAreaView *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,15u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_get_visible_rows(const R4SdkGuiTextAreaView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,15u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_set_visible_rows(R4SdkGuiTextAreaView *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,15u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_get_wrap_cols(const R4SdkGuiTextAreaView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,15u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_set_wrap_cols(R4SdkGuiTextAreaView *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,15u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaView_inspect(const R4SdkGuiTextAreaView *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,15u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuKeyResult_create(R4SdkGuiMenuKeyResult *output) {
 R4SdkGuiSlot a[3]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,16u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenuKeyResult_from_fields(R4SdkGuiMenuKeyResult *output, uint32_t p0, R4SdkGuiSlot p1, uint32_t p2) {
 R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = p1;
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,16u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenuKeyResult_get_action(const R4SdkGuiMenuKeyResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,16u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuKeyResult_set_action(R4SdkGuiMenuKeyResult *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,16u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuKeyResult_get_index(const R4SdkGuiMenuKeyResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,16u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuKeyResult_set_index(R4SdkGuiMenuKeyResult *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,16u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuKeyResult_get_command_id(const R4SdkGuiMenuKeyResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,16u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuKeyResult_set_command_id(R4SdkGuiMenuKeyResult *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,16u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuKeyResult_inspect(const R4SdkGuiMenuKeyResult *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,16u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_create(R4SdkGuiMenubarResult *output) {
 R4SdkGuiSlot a[4]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,17u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_from_fields(R4SdkGuiMenubarResult *output, uint32_t p0, R4SdkGuiSlot p1, R4SdkGuiSlot p2, uint32_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = p1;
 a[2] = p2;
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,17u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_get_action(const R4SdkGuiMenubarResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,17u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_set_action(R4SdkGuiMenubarResult *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,17u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_get_menu_index(const R4SdkGuiMenubarResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,17u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_set_menu_index(R4SdkGuiMenubarResult *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,17u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_get_item_index(const R4SdkGuiMenubarResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,17u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_set_item_index(R4SdkGuiMenubarResult *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,17u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_get_command_id(const R4SdkGuiMenubarResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,17u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_set_command_id(R4SdkGuiMenubarResult *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,17u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarResult_inspect(const R4SdkGuiMenubarResult *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,17u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarHitPart_create(R4SdkGuiMenubarHitPart *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,18u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiMenubarHitPart_inspect(const R4SdkGuiMenubarHitPart *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,18u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarHit_create(R4SdkGuiMenubarHit *output) {
 R4SdkGuiSlot a[4]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,19u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenubarHit_from_fields(R4SdkGuiMenubarHit *output, uint32_t p0, R4SdkGuiSlot p1, R4SdkGuiSlot p2, uint32_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = p1;
 a[2] = p2;
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,19u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenubarHit_get_part(const R4SdkGuiMenubarHit *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,19u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarHit_set_part(R4SdkGuiMenubarHit *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,19u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarHit_get_menu_index(const R4SdkGuiMenubarHit *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,19u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarHit_set_menu_index(R4SdkGuiMenubarHit *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,19u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarHit_get_item_index(const R4SdkGuiMenubarHit *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,19u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarHit_set_item_index(R4SdkGuiMenubarHit *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,19u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarHit_get_command_id(const R4SdkGuiMenubarHit *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,19u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarHit_set_command_id(R4SdkGuiMenubarHit *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,19u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarHit_inspect(const R4SdkGuiMenubarHit *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,19u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiRect_create(R4SdkGuiRect *output) {
 R4SdkGuiSlot a[4]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,20u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiRect_from_fields(R4SdkGuiRect *output, int32_t p0, int32_t p1, int32_t p2, int32_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,20u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiRect_get_x(const R4SdkGuiRect *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,20u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiRect_set_x(R4SdkGuiRect *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,20u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiRect_get_y(const R4SdkGuiRect *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,20u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiRect_set_y(R4SdkGuiRect *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,20u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiRect_get_w(const R4SdkGuiRect *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,20u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiRect_set_w(R4SdkGuiRect *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,20u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiRect_get_h(const R4SdkGuiRect *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,20u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiRect_set_h(R4SdkGuiRect *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,20u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiRect_inspect(const R4SdkGuiRect *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,20u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiLayoutCursor_create(R4SdkGuiLayoutCursor *output, const R4SdkGuiRect * p0) {
 R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,21u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiLayoutCursor_from_fields(R4SdkGuiLayoutCursor *output, const R4SdkGuiRect * p0) {
 R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,21u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiLayoutCursor_get_remaining_rect(const R4SdkGuiLayoutCursor *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,21u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiLayoutCursor_set_remaining_rect(R4SdkGuiLayoutCursor *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,21u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiLayoutCursor_inspect(const R4SdkGuiLayoutCursor *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,21u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_create(R4SdkGuiHostedAppFrame *output, const R4SdkGuiCanvas * p1) {
 R4SdkGuiSlot a[4]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,22u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_from_fields(R4SdkGuiHostedAppFrame *output, const R4GuiWindowInfo * p0, const R4SdkGuiCanvas * p1, const R4SdkGuiRect * p2, uint8_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,22u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_get_info(const R4SdkGuiHostedAppFrame *self, R4GuiWindowInfo *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,22u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_set_info(R4SdkGuiHostedAppFrame *self, const R4GuiWindowInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,22u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_get_canvas(const R4SdkGuiHostedAppFrame *self, R4SdkGuiCanvas *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,22u,1u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_set_canvas(R4SdkGuiHostedAppFrame *self, const R4SdkGuiCanvas * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,22u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_get_client(const R4SdkGuiHostedAppFrame *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,22u,2u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_set_client(R4SdkGuiHostedAppFrame *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,22u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_get_should_close(const R4SdkGuiHostedAppFrame *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,22u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_set_should_close(R4SdkGuiHostedAppFrame *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,22u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiHostedAppFrame_inspect(const R4SdkGuiHostedAppFrame *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,22u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiCanvas_create(R4SdkGuiCanvas *output, const R4SdkGuiDrawContext * p0, int32_t p1, int32_t p2) {
 R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,24u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiCanvas_from_fields(R4SdkGuiCanvas *output, const R4SdkGuiDrawContext * p0, int32_t p1, int32_t p2, const R4SdkGuiFontMetrics * p3, R4SdkGuiSlot p4) {
 R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = p4;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,24u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiCanvas_get_ctx(const R4SdkGuiCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,24u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiCanvas_set_ctx(R4SdkGuiCanvas *self, const R4SdkGuiDrawContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,24u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCanvas_get_w(const R4SdkGuiCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,24u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiCanvas_set_w(R4SdkGuiCanvas *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,24u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCanvas_get_h(const R4SdkGuiCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,24u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiCanvas_set_h(R4SdkGuiCanvas *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,24u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCanvas_get_font(const R4SdkGuiCanvas *self, R4SdkGuiFontMetrics *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,24u,3u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiCanvas_set_font(R4SdkGuiCanvas *self, const R4SdkGuiFontMetrics * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,24u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCanvas_get_frame_canvas(const R4SdkGuiCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,24u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiCanvas_set_frame_canvas(R4SdkGuiCanvas *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,24u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCanvas_inspect(const R4SdkGuiCanvas *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,24u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType25_create(R4SdkGuiType25 *output, const R4SdkGuiDrawContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,25u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType25_inspect(const R4SdkGuiType25 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,25u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType27_create(R4SdkGuiType27 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,27u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType27_inspect(const R4SdkGuiType27 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,27u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType28_create(R4SdkGuiType28 *output, R4SdkGuiFrameCanvas * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,28u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType28_inspect(const R4SdkGuiType28 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,28u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_create(R4SdkGuiFrameCanvas *output, const R4SdkGuiDrawContext * p0, R4GuiFrameCommand * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2, uint8_t p3) {
 R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 a[9].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,29u,a,10u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_from_fields(R4SdkGuiFrameCanvas *output, const R4SdkGuiDrawContext * p0, R4GuiFrameCommand * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2, uint8_t p3, uint64_t p4, uint64_t p5, uint8_t p6, uint8_t p7, int32_t p8, const R4SdkGuiFrameCanvasStats * p9) {
 R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.ptr=(void *)p9,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,29u,a,10u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_get_ctx(const R4SdkGuiFrameCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_set_ctx(R4SdkGuiFrameCanvas *self, const R4SdkGuiDrawContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_get_commands(const R4SdkGuiFrameCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_set_commands(R4SdkGuiFrameCanvas *self, R4GuiFrameCommand * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_get_resources(const R4SdkGuiFrameCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_set_resources(R4SdkGuiFrameCanvas *self, uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_get_transactional(const R4SdkGuiFrameCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_set_transactional(R4SdkGuiFrameCanvas *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_get_command_len(const R4SdkGuiFrameCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_set_command_len(R4SdkGuiFrameCanvas *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_get_resource_len(const R4SdkGuiFrameCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_set_resource_len(R4SdkGuiFrameCanvas *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_get_active(const R4SdkGuiFrameCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_set_active(R4SdkGuiFrameCanvas *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_get_submitted(const R4SdkGuiFrameCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,7u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_set_submitted(R4SdkGuiFrameCanvas *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_get_failure(const R4SdkGuiFrameCanvas *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,8u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_set_failure(R4SdkGuiFrameCanvas *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_get_stats(const R4SdkGuiFrameCanvas *self, R4SdkGuiFrameCanvasStats *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,9u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_set_stats(R4SdkGuiFrameCanvas *self, const R4SdkGuiFrameCanvasStats * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,29u,9u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvas_inspect(const R4SdkGuiFrameCanvas *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,29u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType30_create(R4SdkGuiType30 *output, R4GuiFrameCommand * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,30u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType30_inspect(const R4SdkGuiType30 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,30u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType32_create(R4SdkGuiType32 *output, uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,32u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType32_inspect(const R4SdkGuiType32 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,32u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_create(R4SdkGuiFrameCanvasStats *output) {
 R4SdkGuiSlot a[7]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,33u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_from_fields(R4SdkGuiFrameCanvasStats *output, uint64_t p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5, uint64_t p6) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,33u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_get_logical_commands(const R4SdkGuiFrameCanvasStats *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_set_logical_commands(R4SdkGuiFrameCanvasStats *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_get_resource_bytes(const R4SdkGuiFrameCanvasStats *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_set_resource_bytes(R4SdkGuiFrameCanvasStats *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_get_flushes(const R4SdkGuiFrameCanvasStats *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_set_flushes(R4SdkGuiFrameCanvasStats *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_get_append_calls(const R4SdkGuiFrameCanvasStats *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_set_append_calls(R4SdkGuiFrameCanvasStats *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_get_direct_chunks(const R4SdkGuiFrameCanvasStats *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_set_direct_chunks(R4SdkGuiFrameCanvasStats *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_get_legacy_calls(const R4SdkGuiFrameCanvasStats *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_set_legacy_calls(R4SdkGuiFrameCanvasStats *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_get_failed_calls(const R4SdkGuiFrameCanvasStats *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_set_failed_calls(R4SdkGuiFrameCanvasStats *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,33u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFrameCanvasStats_inspect(const R4SdkGuiFrameCanvasStats *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,33u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_create(R4SdkGuiLabel *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,34u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiLabel_from_fields(R4SdkGuiLabel *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, uint32_t p2, uint8_t p3, uint32_t p4, uint32_t p5, const R4SdkGuiPalette * p6) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,34u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiLabel_get_rect(const R4SdkGuiLabel *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiLabel_set_rect(R4SdkGuiLabel *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_get_text(const R4SdkGuiLabel *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_set_text(R4SdkGuiLabel *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_get_alignment(const R4SdkGuiLabel *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_set_alignment(R4SdkGuiLabel *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_get_disabled(const R4SdkGuiLabel *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_set_disabled(R4SdkGuiLabel *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_get_fg(const R4SdkGuiLabel *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_set_fg(R4SdkGuiLabel *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_get_bg(const R4SdkGuiLabel *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_set_bg(R4SdkGuiLabel *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_get_palette(const R4SdkGuiLabel *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,6u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiLabel_set_palette(R4SdkGuiLabel *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,34u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiLabel_inspect(const R4SdkGuiLabel *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,34u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType35_create(R4SdkGuiType35 *output, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,35u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType35_inspect(const R4SdkGuiType35 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,35u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiButtonState_create(R4SdkGuiButtonState *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,36u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiButtonState_inspect(const R4SdkGuiButtonState *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,36u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_create(R4SdkGuiButton *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,37u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiButton_from_fields(R4SdkGuiButton *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, uint32_t p2, uint8_t p3, uint8_t p4, uint8_t p5, const R4SdkGuiPalette * p6) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,37u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiButton_get_rect(const R4SdkGuiButton *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiButton_set_rect(R4SdkGuiButton *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_get_text(const R4SdkGuiButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_set_text(R4SdkGuiButton *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_get_state(const R4SdkGuiButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_set_state(R4SdkGuiButton *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_get_focused(const R4SdkGuiButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_set_focused(R4SdkGuiButton *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_get_is_default(const R4SdkGuiButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_set_is_default(R4SdkGuiButton *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_get_is_cancel(const R4SdkGuiButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_set_is_cancel(R4SdkGuiButton *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_get_palette(const R4SdkGuiButton *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,6u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiButton_set_palette(R4SdkGuiButton *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,37u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiButton_inspect(const R4SdkGuiButton *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,37u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiList_create(R4SdkGuiList *output, const R4SdkGuiRect * p0, const R4SdkGuiType35 * p1, uintptr_t n1) {
 R4SdkGuiSlot a[9]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,38u,a,9u,output);
}
static inline R4SdkGuiSlot R4SdkGuiList_from_fields(R4SdkGuiList *output, const R4SdkGuiRect * p0, const R4SdkGuiType35 * p1, uintptr_t n1, uint64_t p2, R4SdkGuiSlot p3, uint64_t p4, R4SdkGuiSlot p5, uint8_t p6, int32_t p7, const R4SdkGuiPalette * p8) {
 R4SdkGuiSlot a[9]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = p3;
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = p5;
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.ptr=(void *)p8,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,38u,a,9u,output);
}
static inline R4SdkGuiSlot R4SdkGuiList_get_rect(const R4SdkGuiList *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiList_set_rect(R4SdkGuiList *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiList_get_items(const R4SdkGuiList *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiList_set_items(R4SdkGuiList *self, const R4SdkGuiType35 * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiList_get_selected_index(const R4SdkGuiList *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiList_set_selected_index(R4SdkGuiList *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiList_get_hover_index(const R4SdkGuiList *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiList_set_hover_index(R4SdkGuiList *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiList_get_first_index(const R4SdkGuiList *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiList_set_first_index(R4SdkGuiList *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiList_get_disabled_index(const R4SdkGuiList *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiList_set_disabled_index(R4SdkGuiList *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiList_get_focused(const R4SdkGuiList *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiList_set_focused(R4SdkGuiList *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiList_get_row_h(const R4SdkGuiList *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,7u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiList_set_row_h(R4SdkGuiList *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiList_get_palette(const R4SdkGuiList *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,8u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiList_set_palette(R4SdkGuiList *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,38u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiList_inspect(const R4SdkGuiList *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,38u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType39_create(R4SdkGuiType39 *output, const R4SdkGuiType35 * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,39u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType39_inspect(const R4SdkGuiType39 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,39u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiOrientation_create(R4SdkGuiOrientation *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,40u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiOrientation_inspect(const R4SdkGuiOrientation *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,40u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbarPart_create(R4SdkGuiScrollbarPart *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,41u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiScrollbarPart_inspect(const R4SdkGuiScrollbarPart *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,41u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbarStep_create(R4SdkGuiScrollbarStep *output) {
 R4SdkGuiSlot a[3]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,42u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiScrollbarStep_from_fields(R4SdkGuiScrollbarStep *output, uint32_t p0, uint64_t p1, uint32_t p2) {
 R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,42u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiScrollbarStep_get_action(const R4SdkGuiScrollbarStep *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,42u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbarStep_set_action(R4SdkGuiScrollbarStep *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,42u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbarStep_get_first_index(const R4SdkGuiScrollbarStep *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,42u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbarStep_set_first_index(R4SdkGuiScrollbarStep *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,42u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbarStep_get_part(const R4SdkGuiScrollbarStep *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,42u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbarStep_set_part(R4SdkGuiScrollbarStep *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,42u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbarStep_inspect(const R4SdkGuiScrollbarStep *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,42u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_create(R4SdkGuiScrollbar *output, const R4SdkGuiRect * p0) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,43u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiScrollbar_from_fields(R4SdkGuiScrollbar *output, const R4SdkGuiRect * p0, uint32_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint8_t p5, const R4SdkGuiPalette * p6) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,43u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiScrollbar_get_rect(const R4SdkGuiScrollbar *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_set_rect(R4SdkGuiScrollbar *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_get_orientation(const R4SdkGuiScrollbar *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_set_orientation(R4SdkGuiScrollbar *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_get_total_items(const R4SdkGuiScrollbar *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_set_total_items(R4SdkGuiScrollbar *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_get_visible_items(const R4SdkGuiScrollbar *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_set_visible_items(R4SdkGuiScrollbar *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_get_first_index(const R4SdkGuiScrollbar *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_set_first_index(R4SdkGuiScrollbar *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_get_disabled(const R4SdkGuiScrollbar *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_set_disabled(R4SdkGuiScrollbar *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_get_palette(const R4SdkGuiScrollbar *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,6u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_set_palette(R4SdkGuiScrollbar *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,43u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiScrollbar_inspect(const R4SdkGuiScrollbar *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,43u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_create(R4SdkGuiToolbarButton *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,44u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_from_fields(R4SdkGuiToolbarButton *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, uint32_t p2, uint8_t p3, uint8_t p4, uint8_t p5, const R4SdkGuiPalette * p6) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,44u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_get_rect(const R4SdkGuiToolbarButton *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_set_rect(R4SdkGuiToolbarButton *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_get_text(const R4SdkGuiToolbarButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_set_text(R4SdkGuiToolbarButton *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_get_state(const R4SdkGuiToolbarButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_set_state(R4SdkGuiToolbarButton *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_get_focused(const R4SdkGuiToolbarButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_set_focused(R4SdkGuiToolbarButton *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_get_selected(const R4SdkGuiToolbarButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_set_selected(R4SdkGuiToolbarButton *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_get_disabled(const R4SdkGuiToolbarButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_set_disabled(R4SdkGuiToolbarButton *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_get_palette(const R4SdkGuiToolbarButton *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,6u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_set_palette(R4SdkGuiToolbarButton *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,44u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiToolbarButton_inspect(const R4SdkGuiToolbarButton *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,44u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiTabItem_create(R4SdkGuiTabItem *output, const uint8_t * p0, uintptr_t n0) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,45u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTabItem_from_fields(R4SdkGuiTabItem *output, const uint8_t * p0, uintptr_t n0, uint8_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,45u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTabItem_get_text(const R4SdkGuiTabItem *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,45u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTabItem_set_text(R4SdkGuiTabItem *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,45u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTabItem_get_enabled(const R4SdkGuiTabItem *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,45u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTabItem_set_enabled(R4SdkGuiTabItem *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,45u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTabItem_inspect(const R4SdkGuiTabItem *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,45u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_create(R4SdkGuiTabBar *output, const R4SdkGuiRect * p0, const R4SdkGuiTabItem * p1, uintptr_t n1) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,46u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTabBar_from_fields(R4SdkGuiTabBar *output, const R4SdkGuiRect * p0, const R4SdkGuiTabItem * p1, uintptr_t n1, uint64_t p2, R4SdkGuiSlot p3, uint8_t p4, int32_t p5, const R4SdkGuiPalette * p6) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = p3;
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,46u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTabBar_get_rect(const R4SdkGuiTabBar *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_set_rect(R4SdkGuiTabBar *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_get_items(const R4SdkGuiTabBar *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_set_items(R4SdkGuiTabBar *self, const R4SdkGuiTabItem * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_get_selected_index(const R4SdkGuiTabBar *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_set_selected_index(R4SdkGuiTabBar *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_get_hover_index(const R4SdkGuiTabBar *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_set_hover_index(R4SdkGuiTabBar *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_get_focused(const R4SdkGuiTabBar *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_set_focused(R4SdkGuiTabBar *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_get_tab_h(const R4SdkGuiTabBar *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_set_tab_h(R4SdkGuiTabBar *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_get_palette(const R4SdkGuiTabBar *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,6u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_set_palette(R4SdkGuiTabBar *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,46u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTabBar_inspect(const R4SdkGuiTabBar *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,46u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType47_create(R4SdkGuiType47 *output, const R4SdkGuiTabItem * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,47u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType47_inspect(const R4SdkGuiType47 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,47u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiTableColumn_create(R4SdkGuiTableColumn *output, const uint8_t * p0, uintptr_t n0) {
 R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,48u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTableColumn_from_fields(R4SdkGuiTableColumn *output, const uint8_t * p0, uintptr_t n0, int32_t p1, uint32_t p2) {
 R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,48u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTableColumn_get_title(const R4SdkGuiTableColumn *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,48u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableColumn_set_title(R4SdkGuiTableColumn *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,48u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableColumn_get_width(const R4SdkGuiTableColumn *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,48u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableColumn_set_width(R4SdkGuiTableColumn *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,48u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableColumn_get_alignment(const R4SdkGuiTableColumn *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,48u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableColumn_set_alignment(R4SdkGuiTableColumn *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,48u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableColumn_inspect(const R4SdkGuiTableColumn *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,48u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_create(R4SdkGuiTableView *output, const R4SdkGuiRect * p0, const R4SdkGuiTableColumn * p1, uintptr_t n1, const R4SdkGuiType35 * p2, uintptr_t n2) {
 R4SdkGuiSlot a[11]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 a[9].flags=R4SDK_GUI_DEFAULT;
 a[10].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,49u,a,11u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTableView_from_fields(R4SdkGuiTableView *output, const R4SdkGuiRect * p0, const R4SdkGuiTableColumn * p1, uintptr_t n1, const R4SdkGuiType35 * p2, uintptr_t n2, uint64_t p3, uint64_t p4, R4SdkGuiSlot p5, uint64_t p6, uint8_t p7, int32_t p8, int32_t p9, const R4SdkGuiPalette * p10) {
 R4SdkGuiSlot a[11]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = p5;
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDK_GUI_PRESENT};
 a[10] = (R4SdkGuiSlot){.ptr=(void *)p10,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,49u,a,11u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTableView_get_rect(const R4SdkGuiTableView *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiTableView_set_rect(R4SdkGuiTableView *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_get_columns(const R4SdkGuiTableView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_set_columns(R4SdkGuiTableView *self, const R4SdkGuiTableColumn * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_get_cells(const R4SdkGuiTableView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_set_cells(R4SdkGuiTableView *self, const R4SdkGuiType35 * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_get_row_count(const R4SdkGuiTableView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_set_row_count(R4SdkGuiTableView *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_get_selected_index(const R4SdkGuiTableView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_set_selected_index(R4SdkGuiTableView *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_get_hover_index(const R4SdkGuiTableView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_set_hover_index(R4SdkGuiTableView *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_get_first_index(const R4SdkGuiTableView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_set_first_index(R4SdkGuiTableView *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_get_focused(const R4SdkGuiTableView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,7u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_set_focused(R4SdkGuiTableView *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_get_row_h(const R4SdkGuiTableView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,8u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_set_row_h(R4SdkGuiTableView *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_get_header_h(const R4SdkGuiTableView *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,9u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_set_header_h(R4SdkGuiTableView *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,9u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_get_palette(const R4SdkGuiTableView *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,10u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiTableView_set_palette(R4SdkGuiTableView *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,49u,10u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTableView_inspect(const R4SdkGuiTableView *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,49u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType50_create(R4SdkGuiType50 *output, const R4SdkGuiTableColumn * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,50u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType50_inspect(const R4SdkGuiType50 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,50u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_create(R4SdkGuiCheckbox *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1) {
 R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,51u,a,6u,output);
}
static inline R4SdkGuiSlot R4SdkGuiCheckbox_from_fields(R4SdkGuiCheckbox *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, uint8_t p2, uint8_t p3, uint8_t p4, const R4SdkGuiPalette * p5) {
 R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,51u,a,6u,output);
}
static inline R4SdkGuiSlot R4SdkGuiCheckbox_get_rect(const R4SdkGuiCheckbox *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_set_rect(R4SdkGuiCheckbox *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_get_text(const R4SdkGuiCheckbox *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_set_text(R4SdkGuiCheckbox *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_get_checked(const R4SdkGuiCheckbox *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_set_checked(R4SdkGuiCheckbox *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_get_disabled(const R4SdkGuiCheckbox *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_set_disabled(R4SdkGuiCheckbox *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_get_focused(const R4SdkGuiCheckbox *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_set_focused(R4SdkGuiCheckbox *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_get_palette(const R4SdkGuiCheckbox *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,5u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_set_palette(R4SdkGuiCheckbox *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,51u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCheckbox_inspect(const R4SdkGuiCheckbox *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,51u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_create(R4SdkGuiRadioButton *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1) {
 R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,52u,a,6u,output);
}
static inline R4SdkGuiSlot R4SdkGuiRadioButton_from_fields(R4SdkGuiRadioButton *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, uint8_t p2, uint8_t p3, uint8_t p4, const R4SdkGuiPalette * p5) {
 R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,52u,a,6u,output);
}
static inline R4SdkGuiSlot R4SdkGuiRadioButton_get_rect(const R4SdkGuiRadioButton *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_set_rect(R4SdkGuiRadioButton *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_get_text(const R4SdkGuiRadioButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_set_text(R4SdkGuiRadioButton *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_get_selected(const R4SdkGuiRadioButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_set_selected(R4SdkGuiRadioButton *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_get_disabled(const R4SdkGuiRadioButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_set_disabled(R4SdkGuiRadioButton *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_get_focused(const R4SdkGuiRadioButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_set_focused(R4SdkGuiRadioButton *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_get_palette(const R4SdkGuiRadioButton *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,5u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_set_palette(R4SdkGuiRadioButton *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,52u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiRadioButton_inspect(const R4SdkGuiRadioButton *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,52u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiGroupBox_create(R4SdkGuiGroupBox *output, const R4SdkGuiRect * p0) {
 R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,53u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiGroupBox_from_fields(R4SdkGuiGroupBox *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, const R4SdkGuiPalette * p2) {
 R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,53u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiGroupBox_get_rect(const R4SdkGuiGroupBox *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,53u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiGroupBox_set_rect(R4SdkGuiGroupBox *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,53u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiGroupBox_get_title(const R4SdkGuiGroupBox *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,53u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiGroupBox_set_title(R4SdkGuiGroupBox *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,53u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiGroupBox_get_palette(const R4SdkGuiGroupBox *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,53u,2u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiGroupBox_set_palette(R4SdkGuiGroupBox *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,53u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiGroupBox_inspect(const R4SdkGuiGroupBox *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,53u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiSeparator_create(R4SdkGuiSeparator *output, const R4SdkGuiRect * p0) {
 R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,54u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiSeparator_from_fields(R4SdkGuiSeparator *output, const R4SdkGuiRect * p0, uint8_t p1, const R4SdkGuiPalette * p2) {
 R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,54u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiSeparator_get_rect(const R4SdkGuiSeparator *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,54u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiSeparator_set_rect(R4SdkGuiSeparator *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,54u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiSeparator_get_vertical(const R4SdkGuiSeparator *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,54u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiSeparator_set_vertical(R4SdkGuiSeparator *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,54u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiSeparator_get_palette(const R4SdkGuiSeparator *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,54u,2u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiSeparator_set_palette(R4SdkGuiSeparator *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,54u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiSeparator_inspect(const R4SdkGuiSeparator *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,54u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_create(R4SdkGuiDropdown *output, const R4SdkGuiRect * p0, const R4SdkGuiType35 * p1, uintptr_t n1) {
 R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 a[9].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,55u,a,10u,output);
}
static inline R4SdkGuiSlot R4SdkGuiDropdown_from_fields(R4SdkGuiDropdown *output, const R4SdkGuiRect * p0, const R4SdkGuiType35 * p1, uintptr_t n1, uint64_t p2, R4SdkGuiSlot p3, uint64_t p4, uint64_t p5, uint8_t p6, uint8_t p7, uint8_t p8, const R4SdkGuiPalette * p9) {
 R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = p3;
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.ptr=(void *)p9,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,55u,a,10u,output);
}
static inline R4SdkGuiSlot R4SdkGuiDropdown_get_rect(const R4SdkGuiDropdown *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_set_rect(R4SdkGuiDropdown *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_get_items(const R4SdkGuiDropdown *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_set_items(R4SdkGuiDropdown *self, const R4SdkGuiType35 * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_get_selected_index(const R4SdkGuiDropdown *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_set_selected_index(R4SdkGuiDropdown *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_get_hover_index(const R4SdkGuiDropdown *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_set_hover_index(R4SdkGuiDropdown *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_get_first_index(const R4SdkGuiDropdown *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_set_first_index(R4SdkGuiDropdown *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_get_max_visible_rows(const R4SdkGuiDropdown *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_set_max_visible_rows(R4SdkGuiDropdown *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_get_open(const R4SdkGuiDropdown *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_set_open(R4SdkGuiDropdown *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_get_disabled(const R4SdkGuiDropdown *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,7u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_set_disabled(R4SdkGuiDropdown *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_get_focused(const R4SdkGuiDropdown *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,8u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_set_focused(R4SdkGuiDropdown *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_get_palette(const R4SdkGuiDropdown *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,9u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_set_palette(R4SdkGuiDropdown *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,55u,9u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDropdown_inspect(const R4SdkGuiDropdown *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,55u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuItem_create(R4SdkGuiMenuItem *output, const uint8_t * p0, uintptr_t n0) {
 R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,56u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenuItem_from_fields(R4SdkGuiMenuItem *output, const uint8_t * p0, uintptr_t n0, uint32_t p1, const uint8_t * p2, uintptr_t n2, uint8_t p3, uint8_t p4) {
 R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,56u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenuItem_get_text(const R4SdkGuiMenuItem *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,56u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuItem_set_text(R4SdkGuiMenuItem *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,56u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuItem_get_id(const R4SdkGuiMenuItem *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,56u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuItem_set_id(R4SdkGuiMenuItem *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,56u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuItem_get_shortcut(const R4SdkGuiMenuItem *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,56u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuItem_set_shortcut(R4SdkGuiMenuItem *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,56u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuItem_get_enabled(const R4SdkGuiMenuItem *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,56u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuItem_set_enabled(R4SdkGuiMenuItem *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,56u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuItem_get_separator_before(const R4SdkGuiMenuItem *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,56u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuItem_set_separator_before(R4SdkGuiMenuItem *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,56u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenuItem_inspect(const R4SdkGuiMenuItem *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,56u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMenu_create(R4SdkGuiMenu *output, const R4SdkGuiRect * p0, const R4SdkGuiMenuItem * p1, uintptr_t n1) {
 R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,57u,a,6u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenu_from_fields(R4SdkGuiMenu *output, const R4SdkGuiRect * p0, const R4SdkGuiMenuItem * p1, uintptr_t n1, R4SdkGuiSlot p2, R4SdkGuiSlot p3, int32_t p4, const R4SdkGuiPalette * p5) {
 R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = p2;
 a[3] = p3;
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,57u,a,6u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenu_get_rect(const R4SdkGuiMenu *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMenu_set_rect(R4SdkGuiMenu *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenu_get_items(const R4SdkGuiMenu *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenu_set_items(R4SdkGuiMenu *self, const R4SdkGuiMenuItem * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenu_get_selected_index(const R4SdkGuiMenu *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenu_set_selected_index(R4SdkGuiMenu *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenu_get_hover_index(const R4SdkGuiMenu *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenu_set_hover_index(R4SdkGuiMenu *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenu_get_row_h(const R4SdkGuiMenu *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenu_set_row_h(R4SdkGuiMenu *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenu_get_palette(const R4SdkGuiMenu *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,5u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMenu_set_palette(R4SdkGuiMenu *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,57u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenu_inspect(const R4SdkGuiMenu *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,57u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType58_create(R4SdkGuiType58 *output, const R4SdkGuiMenuItem * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,58u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType58_inspect(const R4SdkGuiType58 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,58u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarMenu_create(R4SdkGuiMenubarMenu *output, const uint8_t * p0, uintptr_t n0, const R4SdkGuiMenuItem * p1, uintptr_t n1) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,59u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenubarMenu_from_fields(R4SdkGuiMenubarMenu *output, const uint8_t * p0, uintptr_t n0, const R4SdkGuiMenuItem * p1, uintptr_t n1, uint8_t p2, int32_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,59u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenubarMenu_get_text(const R4SdkGuiMenubarMenu *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,59u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarMenu_set_text(R4SdkGuiMenubarMenu *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,59u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarMenu_get_items(const R4SdkGuiMenubarMenu *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,59u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarMenu_set_items(R4SdkGuiMenubarMenu *self, const R4SdkGuiMenuItem * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,59u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarMenu_get_enabled(const R4SdkGuiMenubarMenu *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,59u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarMenu_set_enabled(R4SdkGuiMenubarMenu *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,59u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarMenu_get_min_popup_w(const R4SdkGuiMenubarMenu *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,59u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarMenu_set_min_popup_w(R4SdkGuiMenubarMenu *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,59u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarMenu_inspect(const R4SdkGuiMenubarMenu *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,59u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarState_create(R4SdkGuiMenubarState *output) {
 R4SdkGuiSlot a[5]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,60u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenubarState_from_fields(R4SdkGuiMenubarState *output, R4SdkGuiSlot p0, R4SdkGuiSlot p1, R4SdkGuiSlot p2, R4SdkGuiSlot p3, uint8_t p4) {
 R4SdkGuiSlot a[5]={0};
 a[0] = p0;
 a[1] = p1;
 a[2] = p2;
 a[3] = p3;
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,60u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenubarState_get_active_menu(const R4SdkGuiMenubarState *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,60u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarState_set_active_menu(R4SdkGuiMenubarState *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,60u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarState_get_selected_item(const R4SdkGuiMenubarState *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,60u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarState_set_selected_item(R4SdkGuiMenubarState *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,60u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarState_get_hover_menu(const R4SdkGuiMenubarState *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,60u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarState_set_hover_menu(R4SdkGuiMenubarState *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,60u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarState_get_pressed_menu(const R4SdkGuiMenubarState *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,60u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarState_set_pressed_menu(R4SdkGuiMenubarState *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,60u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarState_get_keyboard_active(const R4SdkGuiMenubarState *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,60u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarState_set_keyboard_active(R4SdkGuiMenubarState *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,60u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubarState_inspect(const R4SdkGuiMenubarState *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,60u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubar_create(R4SdkGuiMenubar *output, const R4SdkGuiRect * p0, const R4SdkGuiMenubarMenu * p1, uintptr_t n1) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,61u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenubar_from_fields(R4SdkGuiMenubar *output, const R4SdkGuiRect * p0, const R4SdkGuiMenubarMenu * p1, uintptr_t n1, const R4SdkGuiMenubarState * p2, const R4SdkGuiPalette * p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,61u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMenubar_get_rect(const R4SdkGuiMenubar *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,61u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMenubar_set_rect(R4SdkGuiMenubar *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,61u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubar_get_menus(const R4SdkGuiMenubar *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,61u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubar_set_menus(R4SdkGuiMenubar *self, const R4SdkGuiMenubarMenu * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,61u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubar_get_state(const R4SdkGuiMenubar *self, R4SdkGuiMenubarState *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,61u,2u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMenubar_set_state(R4SdkGuiMenubar *self, const R4SdkGuiMenubarState * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,61u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubar_get_palette(const R4SdkGuiMenubar *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,61u,3u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMenubar_set_palette(R4SdkGuiMenubar *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,61u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMenubar_inspect(const R4SdkGuiMenubar *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,61u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType62_create(R4SdkGuiType62 *output, const R4SdkGuiMenubarMenu * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,62u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType62_inspect(const R4SdkGuiType62 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,62u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogAction_create(R4SdkGuiDialogAction *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,63u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiDialogAction_inspect(const R4SdkGuiDialogAction *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,63u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogButtonRole_create(R4SdkGuiDialogButtonRole *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,64u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiDialogButtonRole_inspect(const R4SdkGuiDialogButtonRole *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,64u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogButtonAlign_create(R4SdkGuiDialogButtonAlign *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,65u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiDialogButtonAlign_inspect(const R4SdkGuiDialogButtonAlign *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,65u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogButton_create(R4SdkGuiDialogButton *output) {
 R4SdkGuiSlot a[4]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,66u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiDialogButton_from_fields(R4SdkGuiDialogButton *output, uint32_t p0, const uint8_t * p1, uintptr_t n1, uint32_t p2, uint8_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,66u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiDialogButton_get_action(const R4SdkGuiDialogButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,66u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogButton_set_action(R4SdkGuiDialogButton *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,66u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogButton_get_text(const R4SdkGuiDialogButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,66u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogButton_set_text(R4SdkGuiDialogButton *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,66u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogButton_get_role(const R4SdkGuiDialogButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,66u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogButton_set_role(R4SdkGuiDialogButton *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,66u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogButton_get_enabled(const R4SdkGuiDialogButton *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,66u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogButton_set_enabled(R4SdkGuiDialogButton *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,66u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogButton_inspect(const R4SdkGuiDialogButton *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,66u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogFocusItem_create(R4SdkGuiDialogFocusItem *output) {
 R4SdkGuiSlot a[2]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,67u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiDialogFocusItem_from_fields(R4SdkGuiDialogFocusItem *output, uint32_t p0, uint8_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,67u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiDialogFocusItem_get_action(const R4SdkGuiDialogFocusItem *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,67u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogFocusItem_set_action(R4SdkGuiDialogFocusItem *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,67u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogFocusItem_get_enabled(const R4SdkGuiDialogFocusItem *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,67u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogFocusItem_set_enabled(R4SdkGuiDialogFocusItem *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,67u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogFocusItem_inspect(const R4SdkGuiDialogFocusItem *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,67u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogEvent_create(R4SdkGuiDialogEvent *output) {
 R4SdkGuiSlot a[4]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,68u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiDialogEvent_from_fields(R4SdkGuiDialogEvent *output, uint32_t p0, uint32_t p1, uint32_t p2, uint8_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,68u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiDialogEvent_get_action(const R4SdkGuiDialogEvent *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,68u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogEvent_set_action(R4SdkGuiDialogEvent *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,68u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogEvent_get_focus_action(const R4SdkGuiDialogEvent *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,68u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogEvent_set_focus_action(R4SdkGuiDialogEvent *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,68u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogEvent_get_pressed_action(const R4SdkGuiDialogEvent *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,68u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogEvent_set_pressed_action(R4SdkGuiDialogEvent *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,68u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogEvent_get_captured(const R4SdkGuiDialogEvent *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,68u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogEvent_set_captured(R4SdkGuiDialogEvent *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,68u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogEvent_inspect(const R4SdkGuiDialogEvent *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,68u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiModalHitPart_create(R4SdkGuiModalHitPart *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,69u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiModalHitPart_inspect(const R4SdkGuiModalHitPart *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,69u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiModalHit_create(R4SdkGuiModalHit *output) {
 R4SdkGuiSlot a[2]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,70u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiModalHit_from_fields(R4SdkGuiModalHit *output, uint32_t p0, uint32_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,70u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiModalHit_get_part(const R4SdkGuiModalHit *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,70u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiModalHit_set_part(R4SdkGuiModalHit *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,70u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiModalHit_get_action(const R4SdkGuiModalHit *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,70u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiModalHit_set_action(R4SdkGuiModalHit *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,70u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiModalHit_inspect(const R4SdkGuiModalHit *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,70u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogState_create(R4SdkGuiDialogState *output) {
 R4SdkGuiSlot a[2]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,71u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiDialogState_from_fields(R4SdkGuiDialogState *output, uint32_t p0, uint32_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,71u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiDialogState_get_focus_action(const R4SdkGuiDialogState *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,71u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogState_set_focus_action(R4SdkGuiDialogState *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,71u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogState_get_pressed_action(const R4SdkGuiDialogState *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,71u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogState_set_pressed_action(R4SdkGuiDialogState *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,71u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiDialogState_inspect(const R4SdkGuiDialogState *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,71u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiModalDialog_create(R4SdkGuiModalDialog *output, const R4SdkGuiRect * p0) {
 R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,72u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiModalDialog_from_fields(R4SdkGuiModalDialog *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, uint32_t p2, uint32_t p3, const R4SdkGuiPalette * p4) {
 R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,72u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiModalDialog_get_rect(const R4SdkGuiModalDialog *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,72u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiModalDialog_set_rect(R4SdkGuiModalDialog *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,72u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiModalDialog_get_title(const R4SdkGuiModalDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,72u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiModalDialog_set_title(R4SdkGuiModalDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,72u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiModalDialog_get_focus_action(const R4SdkGuiModalDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,72u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiModalDialog_set_focus_action(R4SdkGuiModalDialog *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,72u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiModalDialog_get_pressed_action(const R4SdkGuiModalDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,72u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiModalDialog_set_pressed_action(R4SdkGuiModalDialog *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,72u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiModalDialog_get_palette(const R4SdkGuiModalDialog *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,72u,4u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiModalDialog_set_palette(R4SdkGuiModalDialog *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,72u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiModalDialog_inspect(const R4SdkGuiModalDialog *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,72u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_create(R4SdkGuiModalOverlay *output, const R4SdkGuiRect * p0, const R4SdkGuiModalDialog * p1) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,73u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_from_fields(R4SdkGuiModalOverlay *output, const R4SdkGuiRect * p0, const R4SdkGuiModalDialog * p1, uint8_t p2, uint8_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,73u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_get_bounds(const R4SdkGuiModalOverlay *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,73u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_set_bounds(R4SdkGuiModalOverlay *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,73u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_get_dialog(const R4SdkGuiModalOverlay *self, R4SdkGuiModalDialog *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,73u,1u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_set_dialog(R4SdkGuiModalOverlay *self, const R4SdkGuiModalDialog * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,73u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_get_active(const R4SdkGuiModalOverlay *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,73u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_set_active(R4SdkGuiModalOverlay *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,73u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_get_close_on_backdrop(const R4SdkGuiModalOverlay *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,73u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_set_close_on_backdrop(R4SdkGuiModalOverlay *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,73u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiModalOverlay_inspect(const R4SdkGuiModalOverlay *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,73u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageKind_create(R4SdkGuiMessageKind *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,74u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiMessageKind_inspect(const R4SdkGuiMessageKind *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,74u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageButtons_create(R4SdkGuiMessageButtons *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,75u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiMessageButtons_inspect(const R4SdkGuiMessageButtons *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,75u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialogMode_create(R4SdkGuiFileDialogMode *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,76u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiFileDialogMode_inspect(const R4SdkGuiFileDialogMode *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,76u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_create(R4SdkGuiMessageDialog *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2) {
 R4SdkGuiSlot a[12]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 a[9].flags=R4SDK_GUI_DEFAULT;
 a[10].flags=R4SDK_GUI_DEFAULT;
 a[11].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,77u,a,12u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_from_fields(R4SdkGuiMessageDialog *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, uint32_t p3, uint32_t p4, const uint8_t * p5, uintptr_t n5, const uint8_t * p6, uintptr_t n6, const uint8_t * p7, uintptr_t n7, const uint8_t * p8, uintptr_t n8, uint8_t p9, uint32_t p10, const R4SdkGuiPalette * p11) {
 R4SdkGuiSlot a[12]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.length=n5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.length=n6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.length=n7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.ptr=(void *)p8,.length=n8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDK_GUI_PRESENT};
 a[10] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4SDK_GUI_PRESENT};
 a[11] = (R4SdkGuiSlot){.ptr=(void *)p11,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,77u,a,12u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_rect(const R4SdkGuiMessageDialog *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_rect(R4SdkGuiMessageDialog *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_title(const R4SdkGuiMessageDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_title(R4SdkGuiMessageDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_message(const R4SdkGuiMessageDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_message(R4SdkGuiMessageDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_kind(const R4SdkGuiMessageDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_kind(R4SdkGuiMessageDialog *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_buttons(const R4SdkGuiMessageDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_buttons(R4SdkGuiMessageDialog *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_ok_text(const R4SdkGuiMessageDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_ok_text(R4SdkGuiMessageDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_cancel_text(const R4SdkGuiMessageDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_cancel_text(R4SdkGuiMessageDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_yes_text(const R4SdkGuiMessageDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,7u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_yes_text(R4SdkGuiMessageDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_no_text(const R4SdkGuiMessageDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,8u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_no_text(R4SdkGuiMessageDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_ok_pressed(const R4SdkGuiMessageDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,9u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_ok_pressed(R4SdkGuiMessageDialog *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,9u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_pressed_action(const R4SdkGuiMessageDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,10u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_pressed_action(R4SdkGuiMessageDialog *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,10u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_get_palette(const R4SdkGuiMessageDialog *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,11u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_set_palette(R4SdkGuiMessageDialog *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,77u,11u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessageDialog_inspect(const R4SdkGuiMessageDialog *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,77u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_create(R4SdkGuiFileDialog *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, const R4SdkGuiType35 * p3, uintptr_t n3) {
 R4SdkGuiSlot a[17]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 a[9].flags=R4SDK_GUI_DEFAULT;
 a[10].flags=R4SDK_GUI_DEFAULT;
 a[11].flags=R4SDK_GUI_DEFAULT;
 a[12].flags=R4SDK_GUI_DEFAULT;
 a[13].flags=R4SDK_GUI_DEFAULT;
 a[14].flags=R4SDK_GUI_DEFAULT;
 a[15].flags=R4SDK_GUI_DEFAULT;
 a[16].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,78u,a,17u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFileDialog_from_fields(R4SdkGuiFileDialog *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, const R4SdkGuiType35 * p3, uintptr_t n3, uint32_t p4, const uint8_t * p5, uintptr_t n5, R4SdkGuiSlot p6, const R4SdkGuiTextRange * p7, uint64_t p8, R4SdkGuiSlot p9, uint64_t p10, uint64_t p11, const uint8_t * p12, uintptr_t n12, const uint8_t * p13, uintptr_t n13, uint32_t p14, uint32_t p15, const R4SdkGuiPalette * p16) {
 R4SdkGuiSlot a[17]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.length=n5,.flags=R4SDK_GUI_PRESENT};
 a[6] = p6;
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = p9;
 a[10] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4SDK_GUI_PRESENT};
 a[11] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4SDK_GUI_PRESENT};
 a[12] = (R4SdkGuiSlot){.ptr=(void *)p12,.length=n12,.flags=R4SDK_GUI_PRESENT};
 a[13] = (R4SdkGuiSlot){.ptr=(void *)p13,.length=n13,.flags=R4SDK_GUI_PRESENT};
 a[14] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p14,.flags=R4SDK_GUI_PRESENT};
 a[15] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p15,.flags=R4SDK_GUI_PRESENT};
 a[16] = (R4SdkGuiSlot){.ptr=(void *)p16,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,78u,a,17u,output);
}
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_rect(const R4SdkGuiFileDialog *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_rect(R4SdkGuiFileDialog *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_title(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_title(R4SdkGuiFileDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_path(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_path(R4SdkGuiFileDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_items(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_items(R4SdkGuiFileDialog *self, const R4SdkGuiType35 * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_mode(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_mode(R4SdkGuiFileDialog *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_file_name(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_file_name(R4SdkGuiFileDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_file_name_cursor(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_file_name_cursor(R4SdkGuiFileDialog *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_file_name_selection(const R4SdkGuiFileDialog *self, R4SdkGuiTextRange *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,7u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_file_name_selection(R4SdkGuiFileDialog *self, const R4SdkGuiTextRange * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_selected_index(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,8u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_selected_index(R4SdkGuiFileDialog *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_hover_index(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,9u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_hover_index(R4SdkGuiFileDialog *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,9u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_first_index(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,10u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_first_index(R4SdkGuiFileDialog *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,10u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_max_visible_rows(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,11u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_max_visible_rows(R4SdkGuiFileDialog *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,11u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_ok_text(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,12u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_ok_text(R4SdkGuiFileDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,12u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_cancel_text(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,13u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_cancel_text(R4SdkGuiFileDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,13u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_focus_action(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,14u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_focus_action(R4SdkGuiFileDialog *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,14u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_pressed_action(const R4SdkGuiFileDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,15u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_pressed_action(R4SdkGuiFileDialog *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,15u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_get_palette(const R4SdkGuiFileDialog *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,16u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_set_palette(R4SdkGuiFileDialog *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,78u,16u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiFileDialog_inspect(const R4SdkGuiFileDialog *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,78u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_create(R4SdkGuiInputDialog *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3) {
 R4SdkGuiSlot a[11]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 a[9].flags=R4SDK_GUI_DEFAULT;
 a[10].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,79u,a,11u,output);
}
static inline R4SdkGuiSlot R4SdkGuiInputDialog_from_fields(R4SdkGuiInputDialog *output, const R4SdkGuiRect * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, R4SdkGuiSlot p4, const R4SdkGuiTextRange * p5, const uint8_t * p6, uintptr_t n6, const uint8_t * p7, uintptr_t n7, uint32_t p8, uint32_t p9, const R4SdkGuiPalette * p10) {
 R4SdkGuiSlot a[11]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDK_GUI_PRESENT};
 a[4] = p4;
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.length=n6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.length=n7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDK_GUI_PRESENT};
 a[10] = (R4SdkGuiSlot){.ptr=(void *)p10,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,79u,a,11u,output);
}
static inline R4SdkGuiSlot R4SdkGuiInputDialog_get_rect(const R4SdkGuiInputDialog *self, R4SdkGuiRect *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_set_rect(R4SdkGuiInputDialog *self, const R4SdkGuiRect * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_get_title(const R4SdkGuiInputDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_set_title(R4SdkGuiInputDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_get_label(const R4SdkGuiInputDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_set_label(R4SdkGuiInputDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_get_value(const R4SdkGuiInputDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_set_value(R4SdkGuiInputDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_get_value_cursor(const R4SdkGuiInputDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_set_value_cursor(R4SdkGuiInputDialog *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_get_value_selection(const R4SdkGuiInputDialog *self, R4SdkGuiTextRange *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,5u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_set_value_selection(R4SdkGuiInputDialog *self, const R4SdkGuiTextRange * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_get_ok_text(const R4SdkGuiInputDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_set_ok_text(R4SdkGuiInputDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_get_cancel_text(const R4SdkGuiInputDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,7u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_set_cancel_text(R4SdkGuiInputDialog *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_get_focus_action(const R4SdkGuiInputDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,8u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_set_focus_action(R4SdkGuiInputDialog *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_get_pressed_action(const R4SdkGuiInputDialog *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,9u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_set_pressed_action(R4SdkGuiInputDialog *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,9u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_get_palette(const R4SdkGuiInputDialog *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,10u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_set_palette(R4SdkGuiInputDialog *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,79u,10u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputDialog_inspect(const R4SdkGuiInputDialog *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,79u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType80_create(R4SdkGuiType80 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,80u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType80_inspect(const R4SdkGuiType80 *self, R4SdkGuiTextArea *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,80u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_create(R4SdkGuiTextArea *output) {
 R4SdkGuiSlot a[10]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 a[9].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,81u,a,10u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextArea_from_fields(R4SdkGuiTextArea *output, uint8_t * p0, uintptr_t n0, uint64_t p1, uint64_t p2, R4SdkGuiSlot p3, uint64_t p4, uint64_t p5, R4SdkGuiSlot p6, uint8_t p7, uint8_t p8, const R4SdkGuiPalette * p9) {
 R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = p3;
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = p6;
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.ptr=(void *)p9,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,81u,a,10u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextArea_get_buffer(const R4SdkGuiTextArea *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_set_buffer(R4SdkGuiTextArea *self, uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_get_len(const R4SdkGuiTextArea *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_set_len(R4SdkGuiTextArea *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_get_cursor(const R4SdkGuiTextArea *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_set_cursor(R4SdkGuiTextArea *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_get_selection_anchor(const R4SdkGuiTextArea *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_set_selection_anchor(R4SdkGuiTextArea *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_get_scroll_line(const R4SdkGuiTextArea *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_set_scroll_line(R4SdkGuiTextArea *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_get_scroll_col(const R4SdkGuiTextArea *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_set_scroll_col(R4SdkGuiTextArea *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_get_preferred_col(const R4SdkGuiTextArea *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_set_preferred_col(R4SdkGuiTextArea *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_get_focused(const R4SdkGuiTextArea *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,7u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_set_focused(R4SdkGuiTextArea *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_get_disabled(const R4SdkGuiTextArea *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,8u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_set_disabled(R4SdkGuiTextArea *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_get_palette(const R4SdkGuiTextArea *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,9u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_set_palette(R4SdkGuiTextArea *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,81u,9u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextArea_inspect(const R4SdkGuiTextArea *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,81u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType82_create(R4SdkGuiType82 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,82u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType82_inspect(const R4SdkGuiType82 *self, R4SdkGuiTextField *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,82u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiTextField_create(R4SdkGuiTextField *output) {
 R4SdkGuiSlot a[7]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,83u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextField_from_fields(R4SdkGuiTextField *output, uint8_t * p0, uintptr_t n0, uint64_t p1, uint64_t p2, R4SdkGuiSlot p3, uint8_t p4, uint8_t p5, const R4SdkGuiPalette * p6) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = p3;
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,83u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextField_get_buffer(const R4SdkGuiTextField *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_set_buffer(R4SdkGuiTextField *self, uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_get_len(const R4SdkGuiTextField *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_set_len(R4SdkGuiTextField *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_get_cursor(const R4SdkGuiTextField *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_set_cursor(R4SdkGuiTextField *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_get_selection_anchor(const R4SdkGuiTextField *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_set_selection_anchor(R4SdkGuiTextField *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_get_focused(const R4SdkGuiTextField *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_set_focused(R4SdkGuiTextField *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_get_disabled(const R4SdkGuiTextField *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_set_disabled(R4SdkGuiTextField *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_get_palette(const R4SdkGuiTextField *self, R4SdkGuiPalette *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,6u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiTextField_set_palette(R4SdkGuiTextField *self, const R4SdkGuiPalette * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,83u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextField_inspect(const R4SdkGuiTextField *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,83u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType84_create(R4SdkGuiType84 *output, const R4SdkGuiSystemContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,84u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType84_inspect(const R4SdkGuiType84 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,84u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType86_create(R4SdkGuiType86 *output, const R4SdkGuiDesktopContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,86u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType86_inspect(const R4SdkGuiType86 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,86u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType88_create(R4SdkGuiType88 *output, R4GuiEvent * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,88u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType88_inspect(const R4SdkGuiType88 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,88u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType90_create(R4SdkGuiType90 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,90u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType90_inspect(const R4SdkGuiType90 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,90u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType92_create(R4SdkGuiType92 *output, const uint8_t * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,92u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType92_inspect(const R4SdkGuiType92 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,92u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_create(R4SdkGuiTextAreaLayout *output, uint64_t p2) {
 R4SdkGuiSlot a[7]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,93u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_from_fields(R4SdkGuiTextAreaLayout *output, const R4SdkGuiType94 * p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, const R4SdkGuiTextAreaPoint * p5, uint64_t p6) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,93u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_get_ranges(const R4SdkGuiTextAreaLayout *self, R4SdkGuiType94 *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_set_ranges(R4SdkGuiTextAreaLayout *self, const R4SdkGuiType94 * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_get_range_count(const R4SdkGuiTextAreaLayout *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_set_range_count(R4SdkGuiTextAreaLayout *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_get_first_line(const R4SdkGuiTextAreaLayout *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_set_first_line(R4SdkGuiTextAreaLayout *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_get_total_lines(const R4SdkGuiTextAreaLayout *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_set_total_lines(R4SdkGuiTextAreaLayout *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_get_max_columns(const R4SdkGuiTextAreaLayout *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_set_max_columns(R4SdkGuiTextAreaLayout *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_get_caret(const R4SdkGuiTextAreaLayout *self, R4SdkGuiTextAreaPoint *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,5u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_set_caret(R4SdkGuiTextAreaLayout *self, const R4SdkGuiTextAreaPoint * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_get_visited_bytes(const R4SdkGuiTextAreaLayout *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_set_visited_bytes(R4SdkGuiTextAreaLayout *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,93u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTextAreaLayout_inspect(const R4SdkGuiTextAreaLayout *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,93u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType94_create(R4SdkGuiType94 *output, const R4SdkGuiType94 * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,94u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType94_inspect(const R4SdkGuiType94 *self, R4SdkGuiType94 *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,94u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiType95_create(R4SdkGuiType95 *output, const R4SdkGuiTextAreaLayout * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,95u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType95_inspect(const R4SdkGuiType95 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,95u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType96_create(R4SdkGuiType96 *output, const R4SdkGuiDialogButton * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,96u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType96_inspect(const R4SdkGuiType96 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,96u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType97_create(R4SdkGuiType97 *output, const R4SdkGuiDialogFocusItem * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,97u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType97_inspect(const R4SdkGuiType97 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,97u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiCommandId_create(R4SdkGuiCommandId *output, uint32_t p0) {
 R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,98u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiCommandId_from_fields(R4SdkGuiCommandId *output, uint32_t p0) {
 R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,98u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiCommandId_get_value(const R4SdkGuiCommandId *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,98u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiCommandId_set_value(R4SdkGuiCommandId *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,98u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiCommandId_inspect(const R4SdkGuiCommandId *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,98u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiTimerId_create(R4SdkGuiTimerId *output, uint32_t p0) {
 R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,99u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTimerId_from_fields(R4SdkGuiTimerId *output, uint32_t p0) {
 R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,99u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTimerId_get_value(const R4SdkGuiTimerId *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,99u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTimerId_set_value(R4SdkGuiTimerId *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,99u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTimerId_inspect(const R4SdkGuiTimerId *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,99u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiResizeMessage_create(R4SdkGuiResizeMessage *output, int32_t p0, int32_t p1, int32_t p2, uint64_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,100u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiResizeMessage_from_fields(R4SdkGuiResizeMessage *output, int32_t p0, int32_t p1, int32_t p2, uint64_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,100u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiResizeMessage_get_window_id(const R4SdkGuiResizeMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,100u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiResizeMessage_set_window_id(R4SdkGuiResizeMessage *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,100u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiResizeMessage_get_width(const R4SdkGuiResizeMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,100u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiResizeMessage_set_width(R4SdkGuiResizeMessage *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,100u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiResizeMessage_get_height(const R4SdkGuiResizeMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,100u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiResizeMessage_set_height(R4SdkGuiResizeMessage *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,100u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiResizeMessage_get_tick(const R4SdkGuiResizeMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,100u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiResizeMessage_set_tick(R4SdkGuiResizeMessage *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,100u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiResizeMessage_inspect(const R4SdkGuiResizeMessage *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,100u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_create(R4SdkGuiKeyMessage *output, int32_t p0, uint8_t p1, uint32_t p2, uint32_t p3, uint64_t p4) {
 R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,101u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_from_fields(R4SdkGuiKeyMessage *output, int32_t p0, uint8_t p1, uint32_t p2, uint32_t p3, uint64_t p4) {
 R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,101u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_get_window_id(const R4SdkGuiKeyMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,101u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_set_window_id(R4SdkGuiKeyMessage *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,101u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_get_key(const R4SdkGuiKeyMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,101u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_set_key(R4SdkGuiKeyMessage *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,101u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_get_codepoint(const R4SdkGuiKeyMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,101u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_set_codepoint(R4SdkGuiKeyMessage *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,101u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_get_modifiers(const R4SdkGuiKeyMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,101u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_set_modifiers(R4SdkGuiKeyMessage *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,101u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_get_tick(const R4SdkGuiKeyMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,101u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_set_tick(R4SdkGuiKeyMessage *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,101u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiKeyMessage_inspect(const R4SdkGuiKeyMessage *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,101u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseAction_create(R4SdkGuiMouseAction *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,102u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiMouseAction_inspect(const R4SdkGuiMouseAction *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,102u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_create(R4SdkGuiMouseMessage *output, int32_t p0, uint32_t p1, int32_t p2, int32_t p3, uint32_t p4, uint32_t p5, uint64_t p6) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,103u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_from_fields(R4SdkGuiMouseMessage *output, int32_t p0, uint32_t p1, int32_t p2, int32_t p3, uint32_t p4, uint32_t p5, uint64_t p6) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,103u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_get_window_id(const R4SdkGuiMouseMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_set_window_id(R4SdkGuiMouseMessage *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_get_action(const R4SdkGuiMouseMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_set_action(R4SdkGuiMouseMessage *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_get_x(const R4SdkGuiMouseMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_set_x(R4SdkGuiMouseMessage *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_get_y(const R4SdkGuiMouseMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_set_y(R4SdkGuiMouseMessage *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_get_buttons(const R4SdkGuiMouseMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_set_buttons(R4SdkGuiMouseMessage *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_get_modifiers(const R4SdkGuiMouseMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_set_modifiers(R4SdkGuiMouseMessage *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_get_tick(const R4SdkGuiMouseMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_set_tick(R4SdkGuiMouseMessage *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,103u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMouseMessage_inspect(const R4SdkGuiMouseMessage *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,103u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardMessage_create(R4SdkGuiClipboardMessage *output, uint32_t p0) {
 R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,104u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiClipboardMessage_from_fields(R4SdkGuiClipboardMessage *output, uint32_t p0) {
 R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,104u,a,1u,output);
}
static inline R4SdkGuiSlot R4SdkGuiClipboardMessage_get_revision(const R4SdkGuiClipboardMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,104u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardMessage_set_revision(R4SdkGuiClipboardMessage *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,104u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardMessage_inspect(const R4SdkGuiClipboardMessage *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,104u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiTimerMessage_create(R4SdkGuiTimerMessage *output, const R4SdkGuiTimerId * p0, uint64_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,105u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTimerMessage_from_fields(R4SdkGuiTimerMessage *output, const R4SdkGuiTimerId * p0, uint64_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,105u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTimerMessage_get_id(const R4SdkGuiTimerMessage *self, R4SdkGuiTimerId *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,105u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiTimerMessage_set_id(R4SdkGuiTimerMessage *self, const R4SdkGuiTimerId * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,105u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTimerMessage_get_tick(const R4SdkGuiTimerMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,105u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTimerMessage_set_tick(R4SdkGuiTimerMessage *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,105u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTimerMessage_inspect(const R4SdkGuiTimerMessage *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,105u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiMessage_get_close(const R4SdkGuiMessage *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiMessage_set_close(R4SdkGuiMessage *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessage_get_resize(const R4SdkGuiMessage *self, R4SdkGuiResizeMessage *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,1u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMessage_set_resize(R4SdkGuiMessage *self, const R4SdkGuiResizeMessage * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessage_get_key(const R4SdkGuiMessage *self, R4SdkGuiKeyMessage *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,2u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMessage_set_key(R4SdkGuiMessage *self, const R4SdkGuiKeyMessage * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessage_get_mouse(const R4SdkGuiMessage *self, R4SdkGuiMouseMessage *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,3u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMessage_set_mouse(R4SdkGuiMessage *self, const R4SdkGuiMouseMessage * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessage_get_command(const R4SdkGuiMessage *self, R4SdkGuiCommandId *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,4u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMessage_set_command(R4SdkGuiMessage *self, const R4SdkGuiCommandId * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessage_get_clipboard(const R4SdkGuiMessage *self, R4SdkGuiClipboardMessage *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,5u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMessage_set_clipboard(R4SdkGuiMessage *self, const R4SdkGuiClipboardMessage * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessage_get_timer(const R4SdkGuiMessage *self, R4SdkGuiTimerMessage *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,6u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMessage_set_timer(R4SdkGuiMessage *self, const R4SdkGuiTimerMessage * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessage_get_unknown(const R4SdkGuiMessage *self, R4GuiEvent *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,7u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiMessage_set_unknown(R4SdkGuiMessage *self, const R4GuiEvent * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,106u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiMessage_inspect(const R4SdkGuiMessage *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,106u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType107_create(R4SdkGuiType107 *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,107u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType107_inspect(const R4SdkGuiType107 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,107u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiWaitResult_get_message(const R4SdkGuiWaitResult *self, R4SdkGuiMessage *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,108u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiWaitResult_set_message(R4SdkGuiWaitResult *self, const R4SdkGuiMessage * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,108u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWaitResult_get_timed_out(const R4SdkGuiWaitResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,108u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiWaitResult_set_timed_out(R4SdkGuiWaitResult *self) { R4SdkGuiSlot a[1]={0};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,108u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWaitResult_get_failure(const R4SdkGuiWaitResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,108u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiWaitResult_set_failure(R4SdkGuiWaitResult *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,108u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWaitResult_inspect(const R4SdkGuiWaitResult *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,108u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType109_create(R4SdkGuiType109 *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,109u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType109_inspect(const R4SdkGuiType109 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,109u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiTimer_create(R4SdkGuiTimer *output) {
 R4SdkGuiSlot a[4]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,110u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTimer_from_fields(R4SdkGuiTimer *output, const R4SdkGuiTimerId * p0, uint64_t p1, uint64_t p2, uint8_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,110u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiTimer_get_id(const R4SdkGuiTimer *self, R4SdkGuiTimerId *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,110u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiTimer_set_id(R4SdkGuiTimer *self, const R4SdkGuiTimerId * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,110u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTimer_get_deadline_tick(const R4SdkGuiTimer *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,110u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTimer_set_deadline_tick(R4SdkGuiTimer *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,110u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTimer_get_interval_ticks(const R4SdkGuiTimer *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,110u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTimer_set_interval_ticks(R4SdkGuiTimer *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,110u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTimer_get_active(const R4SdkGuiTimer *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,110u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiTimer_set_active(R4SdkGuiTimer *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,110u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiTimer_inspect(const R4SdkGuiTimer *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,110u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_create(R4SdkGuiEventLoop *output, const R4SdkGuiSystemContext * p0, const R4SdkGuiDesktopContext * p1, R4SdkGuiTimer * p2, uintptr_t n2) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,111u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiEventLoop_from_fields(R4SdkGuiEventLoop *output, const R4SdkGuiSystemContext * p0, const R4SdkGuiDesktopContext * p1, R4SdkGuiTimer * p2, uintptr_t n2, uint64_t p3, uint32_t p4, R4SdkGuiSlot p5, uint8_t p6) {
 R4SdkGuiSlot a[7]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = p5;
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,111u,a,7u,output);
}
static inline R4SdkGuiSlot R4SdkGuiEventLoop_get_sys(const R4SdkGuiEventLoop *self, R4SdkGuiSystemContext *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_set_sys(R4SdkGuiEventLoop *self, const R4SdkGuiSystemContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_get_desk(const R4SdkGuiEventLoop *self, R4SdkGuiDesktopContext *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,1u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_set_desk(R4SdkGuiEventLoop *self, const R4SdkGuiDesktopContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_get_timers(const R4SdkGuiEventLoop *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_set_timers(R4SdkGuiEventLoop *self, R4SdkGuiTimer * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_get_activity_sequence(const R4SdkGuiEventLoop *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_set_activity_sequence(R4SdkGuiEventLoop *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_get_clipboard_revision(const R4SdkGuiEventLoop *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_set_clipboard_revision(R4SdkGuiEventLoop *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_get_pending_command(const R4SdkGuiEventLoop *self, R4SdkGuiCommandId *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,5u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_set_pending_command(R4SdkGuiEventLoop *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_get_close_delivered(const R4SdkGuiEventLoop *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_set_close_delivered(R4SdkGuiEventLoop *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,111u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiEventLoop_inspect(const R4SdkGuiEventLoop *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,111u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType112_create(R4SdkGuiType112 *output, R4SdkGuiTimer * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,112u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType112_inspect(const R4SdkGuiType112 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,112u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType113_create(R4SdkGuiType113 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,113u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType113_inspect(const R4SdkGuiType113 *self, R4SdkGuiCommandId *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,113u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiPaintOpen_get_paint(const R4SdkGuiPaintOpen *self, R4SdkGuiPaintContext *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,114u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiPaintOpen_set_paint(R4SdkGuiPaintOpen *self, const R4SdkGuiPaintContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,114u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPaintOpen_get_failure(const R4SdkGuiPaintOpen *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,114u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPaintOpen_set_failure(R4SdkGuiPaintOpen *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,114u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPaintOpen_inspect(const R4SdkGuiPaintOpen *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,114u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType115_create(R4SdkGuiType115 *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,115u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType115_inspect(const R4SdkGuiType115 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,115u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiPaintContext_create(R4SdkGuiPaintContext *output, const R4SdkGuiCanvas * p0) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,116u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiPaintContext_from_fields(R4SdkGuiPaintContext *output, const R4SdkGuiCanvas * p0, uint8_t p1, uint8_t p2, R4SdkGuiSlot p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = p3;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,116u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiPaintContext_get_canvas(const R4SdkGuiPaintContext *self, R4SdkGuiCanvas *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,116u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiPaintContext_set_canvas(R4SdkGuiPaintContext *self, const R4SdkGuiCanvas * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,116u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPaintContext_get_active(const R4SdkGuiPaintContext *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,116u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPaintContext_set_active(R4SdkGuiPaintContext *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,116u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPaintContext_get_transactional(const R4SdkGuiPaintContext *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,116u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPaintContext_set_transactional(R4SdkGuiPaintContext *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,116u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPaintContext_get_frame_canvas(const R4SdkGuiPaintContext *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,116u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiPaintContext_set_frame_canvas(R4SdkGuiPaintContext *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,116u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiPaintContext_inspect(const R4SdkGuiPaintContext *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,116u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiWindow_create(R4SdkGuiWindow *output, const R4SdkGuiSystemContext * p0, const R4SdkGuiDesktopContext * p1, const R4SdkGuiDrawContext * p2, int32_t p3, const R4SdkGuiEventLoop * p4) {
 R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,117u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiWindow_from_fields(R4SdkGuiWindow *output, const R4SdkGuiSystemContext * p0, const R4SdkGuiDesktopContext * p1, const R4SdkGuiDrawContext * p2, int32_t p3, const R4SdkGuiEventLoop * p4) {
 R4SdkGuiSlot a[5]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,117u,a,5u,output);
}
static inline R4SdkGuiSlot R4SdkGuiWindow_get_sys(const R4SdkGuiWindow *self, R4SdkGuiSystemContext *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,117u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiWindow_set_sys(R4SdkGuiWindow *self, const R4SdkGuiSystemContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,117u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWindow_get_desk(const R4SdkGuiWindow *self, R4SdkGuiDesktopContext *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,117u,1u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiWindow_set_desk(R4SdkGuiWindow *self, const R4SdkGuiDesktopContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,117u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWindow_get_draw(const R4SdkGuiWindow *self, R4SdkGuiDrawContext *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,117u,2u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiWindow_set_draw(R4SdkGuiWindow *self, const R4SdkGuiDrawContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,117u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWindow_get_id(const R4SdkGuiWindow *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,117u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiWindow_set_id(R4SdkGuiWindow *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,117u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWindow_get_events(const R4SdkGuiWindow *self, R4SdkGuiEventLoop *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,117u,4u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiWindow_set_events(R4SdkGuiWindow *self, const R4SdkGuiEventLoop * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,117u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWindow_inspect(const R4SdkGuiWindow *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,117u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePoint_create(R4SdkGuiShapePoint *output, const float * p0, const float * p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,118u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapePoint_from_fields(R4SdkGuiShapePoint *output, const float * p0, const float * p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,118u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapePoint_get_x(const R4SdkGuiShapePoint *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,118u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapePoint_set_x(R4SdkGuiShapePoint *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,118u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePoint_get_y(const R4SdkGuiShapePoint *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,118u,1u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapePoint_set_y(R4SdkGuiShapePoint *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,118u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePoint_inspect(const R4SdkGuiShapePoint *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,118u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeFillRule_create(R4SdkGuiShapeFillRule *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,119u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeFillRule_inspect(const R4SdkGuiShapeFillRule *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,119u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeLineJoin_create(R4SdkGuiShapeLineJoin *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,120u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeLineJoin_inspect(const R4SdkGuiShapeLineJoin *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,120u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeLineCap_create(R4SdkGuiShapeLineCap *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,121u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeLineCap_inspect(const R4SdkGuiShapeLineCap *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,121u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeClip_create(R4SdkGuiShapeClip *output) {
 R4SdkGuiSlot a[4]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,122u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapeClip_from_fields(R4SdkGuiShapeClip *output, int32_t p0, int32_t p1, uint32_t p2, uint32_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,122u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapeClip_get_x(const R4SdkGuiShapeClip *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,122u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeClip_set_x(R4SdkGuiShapeClip *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,122u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeClip_get_y(const R4SdkGuiShapeClip *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,122u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeClip_set_y(R4SdkGuiShapeClip *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,122u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeClip_get_w(const R4SdkGuiShapeClip *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,122u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeClip_set_w(R4SdkGuiShapeClip *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,122u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeClip_get_h(const R4SdkGuiShapeClip *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,122u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeClip_set_h(R4SdkGuiShapeClip *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,122u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeClip_inspect(const R4SdkGuiShapeClip *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,122u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_create(R4SdkGuiShapeShadow *output) {
 R4SdkGuiSlot a[6]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,123u,a,6u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_from_fields(R4SdkGuiShapeShadow *output, uint32_t p0, const float * p1, const float * p2, const float * p3, const float * p4, uint8_t p5) {
 R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,123u,a,6u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_get_argb(const R4SdkGuiShapeShadow *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_set_argb(R4SdkGuiShapeShadow *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_get_offset_x(const R4SdkGuiShapeShadow *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,1u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_set_offset_x(R4SdkGuiShapeShadow *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_get_offset_y(const R4SdkGuiShapeShadow *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,2u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_set_offset_y(R4SdkGuiShapeShadow *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_get_spread(const R4SdkGuiShapeShadow *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,3u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_set_spread(R4SdkGuiShapeShadow *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_get_blur(const R4SdkGuiShapeShadow *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,4u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_set_blur(R4SdkGuiShapeShadow *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_get_inset(const R4SdkGuiShapeShadow *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_set_inset(R4SdkGuiShapeShadow *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,123u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeShadow_inspect(const R4SdkGuiShapeShadow *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,123u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_create(R4SdkGuiShapePathStyle *output) {
 R4SdkGuiSlot a[9]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,124u,a,9u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_from_fields(R4SdkGuiShapePathStyle *output, uint32_t p0, uint32_t p1, uint32_t p2, const float * p3, uint32_t p4, uint32_t p5, const float * p6, const R4SdkGuiShapeClip * p7, const R4SdkGuiShapeShadow * p8) {
 R4SdkGuiSlot a[9]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.ptr=(void *)p8,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,124u,a,9u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_get_fill_rule(const R4SdkGuiShapePathStyle *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_set_fill_rule(R4SdkGuiShapePathStyle *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_get_fill_argb(const R4SdkGuiShapePathStyle *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_set_fill_argb(R4SdkGuiShapePathStyle *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_get_stroke_argb(const R4SdkGuiShapePathStyle *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_set_stroke_argb(R4SdkGuiShapePathStyle *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_get_stroke_width(const R4SdkGuiShapePathStyle *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,3u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_set_stroke_width(R4SdkGuiShapePathStyle *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_get_line_join(const R4SdkGuiShapePathStyle *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_set_line_join(R4SdkGuiShapePathStyle *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_get_line_cap(const R4SdkGuiShapePathStyle *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_set_line_cap(R4SdkGuiShapePathStyle *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_get_miter_limit(const R4SdkGuiShapePathStyle *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,6u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_set_miter_limit(R4SdkGuiShapePathStyle *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_get_clip(const R4SdkGuiShapePathStyle *self, R4SdkGuiShapeClip *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,7u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_set_clip(R4SdkGuiShapePathStyle *self, const R4SdkGuiShapeClip * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_get_shadow(const R4SdkGuiShapePathStyle *self, R4SdkGuiShapeShadow *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,8u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_set_shadow(R4SdkGuiShapePathStyle *self, const R4SdkGuiShapeShadow * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,124u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathStyle_inspect(const R4SdkGuiShapePathStyle *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,124u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_create(R4SdkGuiShapeRadii *output) {
 R4SdkGuiSlot a[8]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,125u,a,8u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_from_fields(R4SdkGuiShapeRadii *output, const float * p0, const float * p1, const float * p2, const float * p3, const float * p4, const float * p5, const float * p6, const float * p7) {
 R4SdkGuiSlot a[8]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.ptr=(void *)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.ptr=(void *)p7,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,125u,a,8u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_get_top_left_x(const R4SdkGuiShapeRadii *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_set_top_left_x(R4SdkGuiShapeRadii *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_get_top_left_y(const R4SdkGuiShapeRadii *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,1u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_set_top_left_y(R4SdkGuiShapeRadii *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_get_top_right_x(const R4SdkGuiShapeRadii *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,2u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_set_top_right_x(R4SdkGuiShapeRadii *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_get_top_right_y(const R4SdkGuiShapeRadii *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,3u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_set_top_right_y(R4SdkGuiShapeRadii *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_get_bottom_right_x(const R4SdkGuiShapeRadii *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,4u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_set_bottom_right_x(R4SdkGuiShapeRadii *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_get_bottom_right_y(const R4SdkGuiShapeRadii *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,5u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_set_bottom_right_y(R4SdkGuiShapeRadii *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_get_bottom_left_x(const R4SdkGuiShapeRadii *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,6u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_set_bottom_left_x(R4SdkGuiShapeRadii *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_get_bottom_left_y(const R4SdkGuiShapeRadii *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,7u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_set_bottom_left_y(R4SdkGuiShapeRadii *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,125u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRadii_inspect(const R4SdkGuiShapeRadii *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,125u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeBorders_create(R4SdkGuiShapeBorders *output) {
 R4SdkGuiSlot a[4]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,126u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapeBorders_from_fields(R4SdkGuiShapeBorders *output, const float * p0, const float * p1, const float * p2, const float * p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,126u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapeBorders_get_top(const R4SdkGuiShapeBorders *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,126u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeBorders_set_top(R4SdkGuiShapeBorders *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,126u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeBorders_get_right(const R4SdkGuiShapeBorders *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,126u,1u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeBorders_set_right(R4SdkGuiShapeBorders *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,126u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeBorders_get_bottom(const R4SdkGuiShapeBorders *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,126u,2u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeBorders_set_bottom(R4SdkGuiShapeBorders *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,126u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeBorders_get_left(const R4SdkGuiShapeBorders *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,126u,3u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeBorders_set_left(R4SdkGuiShapeBorders *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,126u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeBorders_inspect(const R4SdkGuiShapeBorders *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,126u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_create(R4SdkGuiShapeRoundedRect *output, const float * p0, const float * p1, const float * p2, const float * p3) {
 R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 a[6].flags=R4SDK_GUI_DEFAULT;
 a[7].flags=R4SDK_GUI_DEFAULT;
 a[8].flags=R4SDK_GUI_DEFAULT;
 a[9].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,127u,a,10u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_from_fields(R4SdkGuiShapeRoundedRect *output, const float * p0, const float * p1, const float * p2, const float * p3, const R4SdkGuiShapeRadii * p4, const R4SdkGuiShapeBorders * p5, uint32_t p6, uint32_t p7, const R4SdkGuiShapeClip * p8, const R4SdkGuiShapeShadow * p9) {
 R4SdkGuiSlot a[10]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.ptr=(void *)p3,.flags=R4SDK_GUI_PRESENT};
 a[4] = (R4SdkGuiSlot){.ptr=(void *)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.ptr=(void *)p5,.flags=R4SDK_GUI_PRESENT};
 a[6] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDK_GUI_PRESENT};
 a[7] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDK_GUI_PRESENT};
 a[8] = (R4SdkGuiSlot){.ptr=(void *)p8,.flags=R4SDK_GUI_PRESENT};
 a[9] = (R4SdkGuiSlot){.ptr=(void *)p9,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,127u,a,10u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_get_x(const R4SdkGuiShapeRoundedRect *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_set_x(R4SdkGuiShapeRoundedRect *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_get_y(const R4SdkGuiShapeRoundedRect *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,1u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_set_y(R4SdkGuiShapeRoundedRect *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_get_w(const R4SdkGuiShapeRoundedRect *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,2u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_set_w(R4SdkGuiShapeRoundedRect *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_get_h(const R4SdkGuiShapeRoundedRect *self, float *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,3u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_set_h(R4SdkGuiShapeRoundedRect *self, const float * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_get_radii(const R4SdkGuiShapeRoundedRect *self, R4SdkGuiShapeRadii *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,4u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_set_radii(R4SdkGuiShapeRoundedRect *self, const R4SdkGuiShapeRadii * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_get_borders(const R4SdkGuiShapeRoundedRect *self, R4SdkGuiShapeBorders *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,5u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_set_borders(R4SdkGuiShapeRoundedRect *self, const R4SdkGuiShapeBorders * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_get_fill_argb(const R4SdkGuiShapeRoundedRect *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,6u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_set_fill_argb(R4SdkGuiShapeRoundedRect *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,6u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_get_border_argb(const R4SdkGuiShapeRoundedRect *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,7u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_set_border_argb(R4SdkGuiShapeRoundedRect *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,7u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_get_clip(const R4SdkGuiShapeRoundedRect *self, R4SdkGuiShapeClip *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,8u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_set_clip(R4SdkGuiShapeRoundedRect *self, const R4SdkGuiShapeClip * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,8u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_get_shadow(const R4SdkGuiShapeRoundedRect *self, R4SdkGuiShapeShadow *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,9u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_set_shadow(R4SdkGuiShapeRoundedRect *self, const R4SdkGuiShapeShadow * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,127u,9u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapeRoundedRect_inspect(const R4SdkGuiShapeRoundedRect *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,127u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_create(R4SdkGuiShapePathBuilder *output, uint8_t * p0, uintptr_t n0, const R4GuiShapeResource * p1) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,128u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_from_fields(R4SdkGuiShapePathBuilder *output, uint8_t * p0, uintptr_t n0, const R4GuiShapeResource * p1, uint64_t p2, uint8_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,128u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_get_output(const R4SdkGuiShapePathBuilder *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,128u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_set_output(R4SdkGuiShapePathBuilder *self, uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,128u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_get_header(const R4SdkGuiShapePathBuilder *self, R4GuiShapeResource *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,128u,1u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_set_header(R4SdkGuiShapePathBuilder *self, const R4GuiShapeResource * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,128u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_get_length(const R4SdkGuiShapePathBuilder *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,128u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_set_length(R4SdkGuiShapePathBuilder *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,128u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_get_active(const R4SdkGuiShapePathBuilder *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,128u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_set_active(R4SdkGuiShapePathBuilder *self, uint8_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,128u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiShapePathBuilder_inspect(const R4SdkGuiShapePathBuilder *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,128u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType130_inspect(const R4SdkGuiType130 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,130u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType131_inspect(const R4SdkGuiType131 *self, R4GuiFrameCommand *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,131u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSlice_create(R4SdkGuiChartPieSlice *output) {
 R4SdkGuiSlot a[2]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,132u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiChartPieSlice_from_fields(R4SdkGuiChartPieSlice *output, uint64_t p0, uint32_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,132u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiChartPieSlice_get_value(const R4SdkGuiChartPieSlice *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,132u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSlice_set_value(R4SdkGuiChartPieSlice *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,132u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSlice_get_color(const R4SdkGuiChartPieSlice *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,132u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSlice_set_color(R4SdkGuiChartPieSlice *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,132u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSlice_inspect(const R4SdkGuiChartPieSlice *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,132u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSegment_create(R4SdkGuiChartPieSegment *output) {
 R4SdkGuiSlot a[4]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,133u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiChartPieSegment_from_fields(R4SdkGuiChartPieSegment *output, uint32_t p0, uint32_t p1, uint64_t p2, uint32_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,133u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiChartPieSegment_get_start_turn(const R4SdkGuiChartPieSegment *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,133u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSegment_set_start_turn(R4SdkGuiChartPieSegment *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,133u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSegment_get_end_turn(const R4SdkGuiChartPieSegment *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,133u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSegment_set_end_turn(R4SdkGuiChartPieSegment *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,133u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSegment_get_value(const R4SdkGuiChartPieSegment *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,133u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSegment_set_value(R4SdkGuiChartPieSegment *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,133u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSegment_get_color(const R4SdkGuiChartPieSegment *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,133u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSegment_set_color(R4SdkGuiChartPieSegment *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,133u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSegment_inspect(const R4SdkGuiChartPieSegment *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,133u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSummary_create(R4SdkGuiChartPieSummary *output) {
 R4SdkGuiSlot a[3]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,134u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiChartPieSummary_from_fields(R4SdkGuiChartPieSummary *output, uint64_t p0, uint64_t p1, uint64_t p2) {
 R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,134u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiChartPieSummary_get_total(const R4SdkGuiChartPieSummary *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,134u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSummary_set_total(R4SdkGuiChartPieSummary *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,134u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSummary_get_count(const R4SdkGuiChartPieSummary *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,134u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSummary_set_count(R4SdkGuiChartPieSummary *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,134u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSummary_get_skipped(const R4SdkGuiChartPieSummary *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,134u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSummary_set_skipped(R4SdkGuiChartPieSummary *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,134u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiChartPieSummary_inspect(const R4SdkGuiChartPieSummary *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,134u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType135_create(R4SdkGuiType135 *output, const R4SdkGuiChartPieSlice * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,135u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType135_inspect(const R4SdkGuiType135 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,135u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType136_create(R4SdkGuiType136 *output, R4SdkGuiChartPieSegment * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,136u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType136_inspect(const R4SdkGuiType136 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,136u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType137_inspect(const R4SdkGuiType137 *self, R4SdkGuiChartPieSummary *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,137u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiType138_create(R4SdkGuiType138 *output, uint32_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,138u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType138_inspect(const R4SdkGuiType138 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,138u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType139_create(R4SdkGuiType139 *output, const R4SdkGuiChartPieSegment * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,139u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType139_inspect(const R4SdkGuiType139 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,139u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType140_inspect(const R4SdkGuiType140 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,140u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_create(R4SdkGuiClipboardReadResult *output) {
 R4SdkGuiSlot a[4]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,142u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_from_fields(R4SdkGuiClipboardReadResult *output, int32_t p0, const uint8_t * p1, uintptr_t n1, uint32_t p2, uint32_t p3) {
 R4SdkGuiSlot a[4]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,142u,a,4u,output);
}
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_get_code(const R4SdkGuiClipboardReadResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,142u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_set_code(R4SdkGuiClipboardReadResult *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,142u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_get_text(const R4SdkGuiClipboardReadResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,142u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_set_text(R4SdkGuiClipboardReadResult *self, const uint8_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,142u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_get_required_len(const R4SdkGuiClipboardReadResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,142u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_set_required_len(R4SdkGuiClipboardReadResult *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,142u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_get_revision(const R4SdkGuiClipboardReadResult *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,142u,3u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_set_revision(R4SdkGuiClipboardReadResult *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,142u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiClipboardReadResult_inspect(const R4SdkGuiClipboardReadResult *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,142u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType143_create(R4SdkGuiType143 *output, const R4SdkGuiProgramContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,143u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType143_inspect(const R4SdkGuiType143 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,143u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType145_create(R4SdkGuiType145 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,145u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType145_inspect(const R4SdkGuiType145 *self, R4ConsoleInputEvent *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,145u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiType147_create(R4SdkGuiType147 *output, R4ConsoleInputEvent * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,147u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType147_inspect(const R4SdkGuiType147 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,147u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType148_create(R4SdkGuiType148 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,148u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType148_inspect(const R4SdkGuiType148 *self, R4SdkGuiInputQueue *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,148u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiInputQueue_create(R4SdkGuiInputQueue *output) {
 R4SdkGuiSlot a[3]={0};
 a[0].flags=R4SDK_GUI_DEFAULT;
 a[1].flags=R4SDK_GUI_DEFAULT;
 a[2].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,149u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiInputQueue_from_fields(R4SdkGuiInputQueue *output, R4ConsoleInputEvent * p0, uintptr_t n0, uint64_t p1, uint64_t p2) {
 R4SdkGuiSlot a[3]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,149u,a,3u,output);
}
static inline R4SdkGuiSlot R4SdkGuiInputQueue_get_data(const R4SdkGuiInputQueue *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,149u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiInputQueue_set_data(R4SdkGuiInputQueue *self, R4ConsoleInputEvent * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,149u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputQueue_get_head(const R4SdkGuiInputQueue *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,149u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiInputQueue_set_head(R4SdkGuiInputQueue *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,149u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputQueue_get_len(const R4SdkGuiInputQueue *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,149u,2u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiInputQueue_set_len(R4SdkGuiInputQueue *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,149u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiInputQueue_inspect(const R4SdkGuiInputQueue *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,149u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeMode_create(R4SdkGuiWindowModeMode *output, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,150u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeMode_inspect(const R4SdkGuiWindowModeMode *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,150u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_create(R4SdkGuiWindowModeClient *output, const R4ProgramProcessHandle * p0, uint32_t p1) {
 R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2].flags=R4SDK_GUI_DEFAULT;
 a[3].flags=R4SDK_GUI_DEFAULT;
 a[4].flags=R4SDK_GUI_DEFAULT;
 a[5].flags=R4SDK_GUI_DEFAULT;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,151u,a,6u,output);
}
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_from_fields(R4SdkGuiWindowModeClient *output, const R4ProgramProcessHandle * p0, uint32_t p1, const R4WindowModeReply * p2, R4SdkGuiSlot p3, uint64_t p4, int32_t p5) {
 R4SdkGuiSlot a[6]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 a[2] = (R4SdkGuiSlot){.ptr=(void *)p2,.flags=R4SDK_GUI_PRESENT};
 a[3] = p3;
 a[4] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDK_GUI_PRESENT};
 a[5] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,151u,a,6u,output);
}
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_get_owner(const R4SdkGuiWindowModeClient *self, R4ProgramProcessHandle *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,0u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_set_owner(R4SdkGuiWindowModeClient *self, const R4ProgramProcessHandle * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_get_window_id(const R4SdkGuiWindowModeClient *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_set_window_id(R4SdkGuiWindowModeClient *self, uint32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_get_state(const R4SdkGuiWindowModeClient *self, R4WindowModeReply *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,2u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_set_state(R4SdkGuiWindowModeClient *self, const R4WindowModeReply * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,2u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_get_pending(const R4SdkGuiWindowModeClient *self, R4WindowModeRequest *output) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,3u,(void *)self,0,output); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_set_pending(R4SdkGuiWindowModeClient *self, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,3u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_get_next_request(const R4SdkGuiWindowModeClient *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,4u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_set_next_request(R4SdkGuiWindowModeClient *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,4u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_get_last_error(const R4SdkGuiWindowModeClient *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,5u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_set_last_error(R4SdkGuiWindowModeClient *self, int32_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,151u,5u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiWindowModeClient_inspect(const R4SdkGuiWindowModeClient *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,151u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType154_create(R4SdkGuiType154 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,154u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType154_inspect(const R4SdkGuiType154 *self, R4WindowModeRequest *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,154u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiType157_create(R4SdkGuiType157 *output, const R4WindowModeReply * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,157u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType157_inspect(const R4SdkGuiType157 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,157u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType159_create(R4SdkGuiType159 *output, R4SdkGuiFocusState * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,159u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType159_inspect(const R4SdkGuiType159 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,159u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType160_create(R4SdkGuiType160 *output, const R4SdkGuiFocusItem * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,160u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType160_inspect(const R4SdkGuiType160 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,160u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType161_create(R4SdkGuiType161 *output, R4SdkGuiMouseCapture * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,161u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType161_inspect(const R4SdkGuiType161 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,161u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType162_create(R4SdkGuiType162 *output, R4SdkGuiLayoutCursor * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,162u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType162_inspect(const R4SdkGuiType162 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,162u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType163_create(R4SdkGuiType163 *output, R4SdkGuiHostedAppFrame * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,163u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType163_inspect(const R4SdkGuiType163 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,163u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType164_create(R4SdkGuiType164 *output, const uint32_t * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,164u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType164_inspect(const R4SdkGuiType164 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,164u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType165_create(R4SdkGuiType165 *output, const R4DisplayDamageRect * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,165u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType165_inspect(const R4SdkGuiType165 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,165u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType167_create(R4SdkGuiType167 *output, const R4GuiFrameCommand * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,167u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType167_inspect(const R4SdkGuiType167 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,167u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType168_create(R4SdkGuiType168 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,168u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType168_inspect(const R4SdkGuiType168 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,168u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType169_create(R4SdkGuiType169 *output, const R4ProgramProcessHandle * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,169u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType169_inspect(const R4SdkGuiType169 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,169u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType170_create(R4SdkGuiType170 *output, R4GuiFrameInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,170u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType170_inspect(const R4SdkGuiType170 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,170u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType172_create(R4SdkGuiType172 *output, R4GuiFrameGenerationInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,172u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType172_inspect(const R4SdkGuiType172 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,172u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType174_create(R4SdkGuiType174 *output, R4DisplayDamageRect * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,174u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType174_inspect(const R4SdkGuiType174 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,174u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType175_create(R4SdkGuiType175 *output, R4GuiFrameStreamInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,175u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType175_inspect(const R4SdkGuiType175 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,175u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType177_create(R4SdkGuiType177 *output, const R4GuiSharedRasterCreateInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,177u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType177_inspect(const R4SdkGuiType177 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,177u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType179_create(R4SdkGuiType179 *output, R4GuiSharedRasterHandle * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,179u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType179_inspect(const R4SdkGuiType179 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,179u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType181_create(R4SdkGuiType181 *output, const R4GuiSharedRasterHandle * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,181u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType181_inspect(const R4SdkGuiType181 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,181u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType182_create(R4SdkGuiType182 *output, R4GuiSharedRasterWriteMap * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,182u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType182_inspect(const R4SdkGuiType182 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,182u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType184_create(R4SdkGuiType184 *output, const R4GuiSharedRasterWriteMap * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,184u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType184_inspect(const R4SdkGuiType184 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,184u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType185_create(R4SdkGuiType185 *output, uint64_t * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,185u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType185_inspect(const R4SdkGuiType185 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,185u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType186_create(R4SdkGuiType186 *output, R4GuiSharedRasterMap * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,186u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType186_inspect(const R4SdkGuiType186 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,186u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType188_create(R4SdkGuiType188 *output, const R4GuiSharedRasterLease * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,188u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType188_inspect(const R4SdkGuiType188 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,188u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType190_create(R4SdkGuiType190 *output, R4GuiFontInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,190u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType190_inspect(const R4SdkGuiType190 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,190u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType192_create(R4SdkGuiType192 *output, R4GuiTextMetrics * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,192u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType192_inspect(const R4SdkGuiType192 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,192u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType194_create(R4SdkGuiType194 *output, R4GuiGlyphBitmap * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,194u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType194_inspect(const R4SdkGuiType194 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,194u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType196_create(R4SdkGuiType196 *output, R4SdkGuiMenubarState * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,196u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType196_inspect(const R4SdkGuiType196 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,196u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType197_create(R4SdkGuiType197 *output, R4SdkGuiDialogState * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,197u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType197_inspect(const R4SdkGuiType197 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,197u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType198_create(R4SdkGuiType198 *output, const R4SdkGuiTextArea * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,198u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType198_inspect(const R4SdkGuiType198 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,198u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType199_create(R4SdkGuiType199 *output, R4SdkGuiTextArea * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,199u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType199_inspect(const R4SdkGuiType199 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,199u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType200_create(R4SdkGuiType200 *output, const R4SdkGuiTextField * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,200u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType200_inspect(const R4SdkGuiType200 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,200u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType201_create(R4SdkGuiType201 *output, R4SdkGuiTextField * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,201u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType201_inspect(const R4SdkGuiType201 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,201u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType202_create(R4SdkGuiType202 *output, uint64_t p0, uint64_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,202u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiType202_from_fields(R4SdkGuiType202 *output, uint64_t p0, uint64_t p1) {
 R4SdkGuiSlot a[2]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 a[1] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,202u,a,2u,output);
}
static inline R4SdkGuiSlot R4SdkGuiType202_get_start(const R4SdkGuiType202 *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,202u,0u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiType202_set_start(R4SdkGuiType202 *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,202u,0u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiType202_get_end(const R4SdkGuiType202 *self) { return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,202u,1u,(void *)self,0,0); }
static inline R4SdkGuiSlot R4SdkGuiType202_set_end(R4SdkGuiType202 *self, uint64_t p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiField(R4SdkGui_ABI_FINGERPRINT,202u,1u,self,a,0); }
static inline R4SdkGuiSlot R4SdkGuiType202_inspect(const R4SdkGuiType202 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,202u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType203_create(R4SdkGuiType203 *output, R4Mouse * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,203u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType203_inspect(const R4SdkGuiType203 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,203u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType205_create(R4SdkGuiType205 *output, R4MouseMotion * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,205u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType205_inspect(const R4SdkGuiType205 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,205u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType207_create(R4SdkGuiType207 *output, R4RemoteFrameInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,207u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType207_inspect(const R4SdkGuiType207 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,207u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType209_create(R4SdkGuiType209 *output, R4RemoteFrameLease * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,209u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType209_inspect(const R4SdkGuiType209 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,209u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType211_create(R4SdkGuiType211 *output, const R4RemoteFrameLease * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,211u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType211_inspect(const R4SdkGuiType211 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,211u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType212_create(R4SdkGuiType212 *output, R4RemoteFrameCaptureStats * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,212u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType212_inspect(const R4SdkGuiType212 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,212u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType214_create(R4SdkGuiType214 *output, R4KeyboardLayoutInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,214u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType214_inspect(const R4SdkGuiType214 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,214u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType218_create(R4SdkGuiType218 *output, R4ProgramProcessHandle * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,218u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType218_inspect(const R4SdkGuiType218 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,218u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType219_create(R4SdkGuiType219 *output, R4ProgramHostLaunchRequest * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,219u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType219_inspect(const R4SdkGuiType219 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,219u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType221_create(R4SdkGuiType221 *output, R4GuiWindowInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,221u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType221_inspect(const R4SdkGuiType221 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,221u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType222_create(R4SdkGuiType222 *output, const R4GuiWindowInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,222u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType222_inspect(const R4SdkGuiType222 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,222u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType223_create(R4SdkGuiType223 *output, const R4GuiEvent * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,223u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType223_inspect(const R4SdkGuiType223 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,223u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType224_create(R4SdkGuiType224 *output, R4GuiCommand * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,224u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType224_inspect(const R4SdkGuiType224 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,224u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType226_create(R4SdkGuiType226 *output, R4GuiSize * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,226u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType226_inspect(const R4SdkGuiType226 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,226u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType228_create(R4SdkGuiType228 *output, R4ConsoleState * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,228u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType228_inspect(const R4SdkGuiType228 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,228u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType231_create(R4SdkGuiType231 *output, R4PhysicalKeyEvent * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,231u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType231_inspect(const R4SdkGuiType231 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,231u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType233_create(R4SdkGuiType233 *output, R4ClipboardInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,233u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType233_inspect(const R4SdkGuiType233 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,233u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType234_create(R4SdkGuiType234 *output, R4RemoteFrameMapInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,234u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType234_inspect(const R4SdkGuiType234 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,234u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType236_create(R4SdkGuiType236 *output, const R4RemoteFrameInfo * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,236u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType236_inspect(const R4SdkGuiType236 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,236u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType237_create(R4SdkGuiType237 *output, const R4RemoteInputEvent * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,237u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType237_inspect(const R4SdkGuiType237 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,237u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType239_create(R4SdkGuiType239 *output, R4RemoteInputEvent * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,239u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType239_inspect(const R4SdkGuiType239 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,239u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType240_create(R4SdkGuiType240 *output, R4RemoteInputStatus * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,240u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType240_inspect(const R4SdkGuiType240 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,240u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType242_create(R4SdkGuiType242 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,242u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType242_inspect(const R4SdkGuiType242 *self, R4GuiEvent *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,242u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiType243_create(R4SdkGuiType243 *output, R4SdkGuiTimer * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,243u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType243_inspect(const R4SdkGuiType243 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,243u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType245_create(R4SdkGuiType245 *output, R4SdkGuiEventLoop * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,245u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType245_inspect(const R4SdkGuiType245 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,245u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType246_create(R4SdkGuiType246 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,246u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType246_inspect(const R4SdkGuiType246 *self, R4SdkGuiMessage *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,246u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiType248_create(R4SdkGuiType248 *output, R4SdkGuiPaintContext * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,248u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType248_inspect(const R4SdkGuiType248 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,248u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType249_create(R4SdkGuiType249 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,249u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType249_inspect(const R4SdkGuiType249 *self, R4SdkGuiWindow *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,249u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiType250_create(R4SdkGuiType250 *output, R4SdkGuiWindow * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,250u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType250_inspect(const R4SdkGuiType250 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,250u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType251_create(R4SdkGuiType251 *output, R4SdkGuiSlot p0) { R4SdkGuiSlot a[1]={0};
 a[0] = p0;
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,251u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType251_inspect(const R4SdkGuiType251 *self, R4GuiWindowInfo *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,251u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiType252_inspect(const R4SdkGuiType252 *self, R4SdkGuiShapePathBuilder *output) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,252u,(void *)self,output); }
static inline R4SdkGuiSlot R4SdkGuiType253_create(R4SdkGuiType253 *output, R4SdkGuiShapePathBuilder * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,253u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType253_inspect(const R4SdkGuiType253 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,253u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType254_inspect(const R4SdkGuiType254 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,254u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType255_create(R4SdkGuiType255 *output, R4SdkGuiInputQueue * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,255u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType255_inspect(const R4SdkGuiType255 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,255u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType256_create(R4SdkGuiType256 *output, const R4ConsoleInputEvent * p0, uintptr_t n0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,256u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType256_inspect(const R4SdkGuiType256 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,256u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType257_create(R4SdkGuiType257 *output, const R4SdkGuiInputQueue * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,257u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType257_inspect(const R4SdkGuiType257 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,257u,(void *)self,0); }
static inline R4SdkGuiSlot R4SdkGuiType258_create(R4SdkGuiType258 *output, R4SdkGuiWindowModeClient * p0) { R4SdkGuiSlot a[1]={0};
 a[0] = (R4SdkGuiSlot){.ptr=(void *)p0,.flags=R4SDK_GUI_PRESENT};
 return R4SdkGuiConstruct(R4SdkGui_ABI_FINGERPRINT,258u,a,1u,output); }
static inline R4SdkGuiSlot R4SdkGuiType258_inspect(const R4SdkGuiType258 *self) { return R4SdkGuiInspect(R4SdkGui_ABI_FINGERPRINT,258u,(void *)self,0); }
#endif
