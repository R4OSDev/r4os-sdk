#![cfg(test)]
use core::{mem::MaybeUninit, pin::pin};
use r4os_sdk::{
    App, ImportSpec, StartupInfo, abi,
    gui::{self, InputQueue, Rect, Role, Session, SessionStorage, TextArea, TextField, raw as c},
    resources::Timeout,
};
unsafe extern "C" {
    fn sdk_gui_c_case() -> i32;
    fn sdk_gui_native_tables(
        sys: *mut abi::R4XStartR4Sys,
        desk: *mut abi::R4XStartR4Desk,
        draw: *mut abi::R4XStartR4Draw,
    );
    fn sdk_gui_host_tables(
        sys: *mut abi::R4XStartR4Sys,
        desk: *mut abi::R4XStartR4Desk,
        draw: *mut abi::R4XStartR4Draw,
    );
    fn sdk_gui_oracle_pixels(out: *mut u32, count: usize) -> i32;
    fn sdk_gui_oracle_fail_append(at: u32);
    fn sdk_gui_oracle_cancelled() -> u32;
    fn sdk_gui_host_mode(value: u32);
    fn sdk_gui_host_count(kind: u32) -> u32;
}
fn with_app(host: bool, body: impl FnOnce(&App<'_>)) {
    let (mut sys, mut desk, mut draw) = (
        abi::R4XStartR4Sys::default(),
        abi::R4XStartR4Desk::default(),
        abi::R4XStartR4Draw::default(),
    );
    unsafe {
        if host {
            sdk_gui_host_tables(&mut sys, &mut desk, &mut draw)
        } else {
            sdk_gui_native_tables(&mut sys, &mut desk, &mut draw)
        }
    };
    let records = [
        (
            abi::R4LGroup::r4sys.0,
            c"R4SYS",
            (&sys as *const _) as u64,
            sys.magic,
            sys.abi_version,
            sys.size,
        ),
        (
            abi::R4LGroup::r4desk.0,
            c"R4DESK",
            (&desk as *const _) as u64,
            desk.magic,
            desk.abi_version,
            desk.size,
        ),
        (
            abi::R4LGroup::r4draw.0,
            c"R4DRAW",
            (&draw as *const _) as u64,
            draw.magic,
            draw.abi_version,
            draw.size,
        ),
    ];
    let imports = records.map(|(id, name, table, _, _, _)| abi::R4XStartImport {
        group_id: id,
        min_version: 1,
        resolved_version: 1,
        flags: abi::r4xstart_import_flag_group_interface,
        module_name: name.as_ptr() as u64,
        symbol_name: c"Query".as_ptr() as u64,
        table,
    });
    let specs = records.map(|(id, name, _, magic, version, size)| ImportSpec {
        module_name: name.to_bytes(),
        symbol_name: b"Query",
        minimum: 1,
        optional: false,
        group_id: id,
        magic,
        version,
        size,
    });
    let context = abi::R4XStartContext {
        app_class: abi::R4XStartAppClass::gui.0,
        instance_id: 42,
        flags: abi::r4xstart_flag_imports_valid,
        imports: imports.as_ptr() as u64,
        import_count: 3,
        ..Default::default()
    };
    let expected = StartupInfo {
        app_class: abi::R4XStartAppClass::gui,
        required_groups: records.iter().fold(0, |m, r| m | (1 << r.0)),
        imports: &specs,
    };
    let app = unsafe { App::from_raw(&context, &expected, c"GuiParity") }.unwrap();
    body(&app);
}
#[test]
fn original_gui_pixels_frames_unicode_input_and_exact_host_session() {
    assert_eq!(unsafe { sdk_gui_c_case() }, 0);
    with_app(false, |app| {
        let mut storage = pin!(SessionStorage::new());
        let mut timers = [MaybeUninit::uninit(); 1];
        let mut window = Session::open(storage.as_mut(), app, Role::Window, &mut timers).unwrap();
        // Current font capability absence is an error, never a row-based or
        // invented-revision substitute; caller bitmap storage is untouched.
        let draw = unsafe { window.native_draw() };
        let mut glyph = abi::GuiGlyphBitmap { width: 77, ..Default::default() };
        assert_eq!(unsafe { c::R4SdkGuiDrawContext_fontGlyphBitmap(0, draw, 0, 65, &mut glyph) }.status, abi::err_no_fn);
        assert_eq!(glyph.width, 77);
        assert_eq!(unsafe { c::R4SdkGuiDrawContext_fontRevision(0, draw) }.status, abi::err_no_fn);
        assert_eq!(window.window_info().unwrap().unwrap().client_w, 320);
        window.set_title(c"Test").unwrap();
        window.set_minimum_size(100, 80).unwrap();
        assert_eq!(window.next(Timeout::Poll).unwrap().unwrap().kind, 2);
        let key = window.next(Timeout::Poll).unwrap().unwrap();
        assert_eq!(key.kind(), Some(gui::EventKind::Key));
        assert_eq!((key.kind, key.codepoint, key.modifiers), (3, 0x1f642, 2));
        for kind in [4, 5, 6, 1] {
            assert_eq!(window.next(Timeout::Poll).unwrap().unwrap().kind, kind)
        }
        assert!(window.next(Timeout::Poll).unwrap().is_none());
        window.post_command(42).unwrap();
        assert!(window.post_command(43).is_err());
        assert_eq!(window.next(Timeout::Poll).unwrap().unwrap().id, 42);
        window.start_timer(0, 7, 2_000_000, false).unwrap();
        let event = window
            .next(Timeout::AfterNanos(10_000_000))
            .unwrap()
            .unwrap();
        assert_eq!((event.kind, event.id), (9, 7));
        let mut commands = [abi::GuiFrameCommand::default(); 8];
        let mut resources = [0u8; 64];
        let mut paint = window.begin(&mut commands, &mut resources).unwrap();
        paint.clear(0).unwrap();
        paint
            .rect(
                Rect {
                    x: 2,
                    y: 1,
                    width: 2,
                    height: 1,
                },
                0xcc0000,
            )
            .unwrap();
        paint
            .raster(0, 0, 2, 1, 1, &[0xaa112233, 0xff445566])
            .unwrap();
        paint
            .blend_alpha8(0, 1, 2, 2, 3, 0xffffff, &[0, 255, 77, 255, 0])
            .unwrap();
        paint
            .rect(
                Rect {
                    x: 3,
                    y: 2,
                    width: 1,
                    height: 1,
                },
                0x010203,
            )
            .unwrap();
        paint.present().unwrap();
        let mut output = [0u32; 12];
        assert_eq!(unsafe { sdk_gui_oracle_pixels(output.as_mut_ptr(), 12) }, 0);
        assert_eq!(
            output,
            [
                0x112233, 0x445566, 0, 0, 0, 0xffffff, 0xcc0000, 0xcc0000, 0xffffff, 0, 0, 0x010203
            ]
        );
        // Actual partial-flush failure must cancel the opened transaction.
        unsafe { sdk_gui_oracle_fail_append(2) };
        let mut tiny_commands = [abi::GuiFrameCommand::default(); 1];
        let mut paint = window.begin(&mut tiny_commands, &mut resources).unwrap();
        paint.clear(0).unwrap();
        assert!(
            paint
                .rect(
                    Rect {
                        x: 0,
                        y: 0,
                        width: 1,
                        height: 1
                    },
                    1
                )
                .is_err()
        );
        drop(paint);
        assert!(unsafe { sdk_gui_oracle_cancelled() } > 0);
    });
    let mut bytes = [0u8; 24];
    let mut field = TextField::new(&mut bytes).unwrap();
    assert!(field.set_exact("A\u{301}B".as_bytes()).unwrap());
    field.set_selection(0, 1).unwrap();
    assert!(field.paste("🙂".as_bytes()).unwrap());
    assert_eq!(field.value().unwrap(), "🙂B".as_bytes());
    assert!(!field.set_exact(b"\xc0\xaf").unwrap());
    assert_eq!(field.value().unwrap(), "🙂B".as_bytes());
    assert!(field.handle_codepoint(8).unwrap());
    assert_eq!(field.value().unwrap(), b"B");
    let mut area_bytes = [0u8; 48];
    let mut area = TextArea::new(&mut area_bytes, 5, 3).unwrap();
    area.set("ä\n🙂".as_bytes()).unwrap();
    assert!(area.delete_backward().unwrap());
    assert_eq!(area.value().unwrap(), "ä\n".as_bytes());
    assert!(area.paste("🙂".as_bytes()).unwrap());
    assert_eq!(area.value().unwrap(), "ä\n🙂".as_bytes());
    let mut input = [abi::ConsoleInputEvent::default(); 3];
    let mut queue = InputQueue::new(&mut input).unwrap();
    let text = abi::ConsoleInputEvent {
        kind: abi::console_input_event_text,
        value: 0x1f642,
        ..Default::default()
    };
    assert!(queue.append(&[text, text, text]).unwrap());
    assert!(!queue.append(&[text]).unwrap());
    assert!(queue.consume(2).unwrap());
    assert!(queue.append(&[text, text]).unwrap());
    assert_eq!(queue.peek().unwrap().len(), 1);
    assert!(queue.consume(1).unwrap());
    assert_eq!(queue.peek().unwrap().len(), 2);
    assert!(
        !queue
            .append(&[abi::ConsoleInputEvent {
                value: 0xd800,
                ..text
            }])
            .unwrap()
    );
    // Native float data crosses by pointer. Returned values do not assume the
    // unqualified bare Rust scalar FP calling convention.
    let mut point = MaybeUninit::<c::R4SdkGuiShapePoint>::uninit();
    let x = 1.25f32;
    let y = -2.5f32;
    assert_eq!(
        unsafe { c::R4SdkGuiShapePoint_create(point.as_mut_ptr(), &x, &y) }.status,
        0
    );
    let mut got = 0f32;
    assert_eq!(
        unsafe { c::R4SdkGuiShapePoint_get_y(point.as_ptr(), &mut got) }.status,
        0
    );
    assert_eq!(got, y);
    assert_eq!(
        unsafe { c::R4SdkGuiVerifyAbi(c::R4SdkGui_ABI_FINGERPRINT) },
        0
    );
    assert!(unsafe { c::R4SdkGuiVerifyAbi(c::R4SdkGui_ABI_FINGERPRINT ^ 1) } < 0);
    with_app(true, |app| {
        let mut storage = pin!(SessionStorage::new());
        let mut timers = [];
        let mut host =
            Session::open(storage.as_mut(), app, Role::DesktopHost, &mut timers).unwrap();
        assert!(host.window_info().unwrap().is_none());
        assert_eq!(unsafe { sdk_gui_host_count(3) }, 0);
        let timeout = Timeout::AfterNanos(250_000_000);
        let exchange = host.claim_host(timeout).unwrap();
        assert_eq!(exchange.desktop_epoch, 0x100000007);
        unsafe { sdk_gui_host_mode(1) };
        assert!(
            host.host_exchange(abi::tray_service_op_desktop_sync, &exchange, timeout)
                .is_err()
        );
        assert_eq!(unsafe { sdk_gui_host_count(1) }, 1);
        assert_eq!(unsafe { sdk_gui_host_count(0) }, 1);
        unsafe { sdk_gui_host_mode(0) };
        assert!(
            host.host_exchange(abi::tray_service_op_desktop_sync, &exchange, timeout)
                .is_err()
        );
        assert_eq!(unsafe { sdk_gui_host_count(0) }, 1);
        host.reset_host_connection();
        host.claim_host(timeout).unwrap();
        assert_eq!(unsafe { sdk_gui_host_count(0) }, 2);
        drop(host);
        assert_eq!(unsafe { sdk_gui_host_count(1) }, 2);
        assert_eq!(unsafe { sdk_gui_host_count(3) }, 0);
    });
    let _ = core::mem::size_of::<gui::TimerStorage>();
}
