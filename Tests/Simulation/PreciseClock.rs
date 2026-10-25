//! Fractional-tick work budgets require the admitted precise platform source.
use r4os_sdk::{App, ImportSpec, StartupInfo, abi as a, storage::Error, time::Clock};
use std::sync::atomic::{AtomicI32, Ordering};
static MODE: AtomicI32 = AtomicI32::new(0);
static CALENDAR_CALLS: AtomicI32 = AtomicI32::new(0);
unsafe extern "C" fn state(out: *mut a::TimeState) {
    CALENDAR_CALLS.fetch_add(1, Ordering::Relaxed);
    unsafe {
        out.write(a::TimeState {
            monotonic_ticks: 1,
            monotonic_hz: 1,
            ..Default::default()
        });
    }
}
unsafe extern "C" fn ticks() -> u64 {
    123
}
unsafe extern "C" fn precise(out: *mut a::MonotonicClockInfo) -> i32 {
    let mode = MODE.load(Ordering::Relaxed);
    unsafe {
        out.write(a::MonotonicClockInfo {
            flags: if mode == 1 {
                0
            } else {
                a::monotonic_clock_flag_valid
            },
            frequency_hz: if mode == 2 {
                1_000_000
            } else {
                a::monotonic_clock_frequency_hz
            },
            instant_ns: 1_000_250_001,
            event_requested_hz: if mode == 5 { 250 } else { 1000 },
            event_effective_hz: if mode == 5 { 251 } else { 1001 },
            ..Default::default()
        });
    }
    match mode {
        3 => 0,
        4 => -13,
        _ => 1,
    }
}
fn with(table: &a::R4XStartR4Sys, run: impl FnOnce(&App<'_>)) {
    let import = [a::R4XStartImport {
        group_id: 1,
        min_version: 1,
        resolved_version: 1,
        flags: a::r4xstart_import_flag_group_interface,
        module_name: c"R4SYS".as_ptr() as u64,
        symbol_name: c"Query".as_ptr() as u64,
        table: table as *const _ as u64,
        ..Default::default()
    }];
    let raw = a::R4XStartContext {
        app_class: a::R4XStartAppClass::console.0,
        instance_id: 86,
        flags: a::r4xstart_flag_imports_valid,
        imports: import.as_ptr() as u64,
        import_count: 1,
        ..Default::default()
    };
    let imports = [ImportSpec {
        module_name: b"R4SYS",
        symbol_name: b"Query",
        minimum: 1,
        optional: false,
        group_id: 1,
        magic: table.magic,
        version: table.abi_version,
        size: table.size,
    }];
    let expected = StartupInfo {
        app_class: a::R4XStartAppClass::console,
        required_groups: 2,
        imports: &imports,
    };
    let app = unsafe { App::from_raw(&raw, &expected, c"CLOCK") }.unwrap();
    run(&app);
}
#[test]
fn sub_tick_nanoseconds_require_valid_admission_and_never_substitute_ticks() {
    let mut table = a::R4XStartR4Sys {
        time_state: state as *const () as usize,
        monotonic_clock: precise as *const () as usize,
        ticks: ticks as *const () as usize,
        ..Default::default()
    };
    with(&table, |app| {
        let clock = Clock::new(app);
        let coarse = clock.state().unwrap();
        assert_eq!((coarse.monotonic_ticks, coarse.monotonic_hz), (1, 1));
        let calendar_calls = CALENDAR_CALLS.load(Ordering::Relaxed);
        MODE.store(0, Ordering::Relaxed);
        assert_eq!(clock.precise_instant().unwrap().nanoseconds, 1_000_250_001);
        for (mode, rate) in [(0, 1000), (5, 250)] {
            MODE.store(mode, Ordering::Relaxed);
            let current = clock.monotonic().unwrap();
            assert_eq!(current.event_requested_hz, rate);
            assert_eq!(clock.ticks().unwrap(), 123);
            assert_eq!(current.instant_ns, 1_000_250_001);
        }
        for mode in [1, 2] {
            MODE.store(mode, Ordering::Relaxed);
            assert!(matches!(
                clock.precise_instant(),
                Err(Error::InvalidProvider)
            ));
        }
        MODE.store(3, Ordering::Relaxed);
        assert!(matches!(clock.precise_instant(), Err(Error::Unavailable)));
        MODE.store(4, Ordering::Relaxed);
        assert!(matches!(clock.precise_instant(), Err(Error::Raw(-13))));
        assert_eq!(CALENDAR_CALLS.load(Ordering::Relaxed), calendar_calls);
    });
    table.monotonic_clock = 0;
    with(&table, |app| {
        assert!(matches!(
            Clock::new(app).precise_instant(),
            Err(Error::Raw(a::err_no_fn))
        ))
    });
    MODE.store(0, Ordering::Relaxed);
}
