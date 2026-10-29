#![cfg(test)]
use r4os_sdk::{
    App, ImportSpec, StartupInfo, abi,
    directory_page::{DialogPage, Snapshot},
    path::{FilePath, RegistryPath},
    storage::{Error, RegistryBatch, SaveResult, SnapshotKind, System},
};
#[path = "../Conformance/StorageCodecChecks.rs"]
mod common;
unsafe extern "C" {
    fn sdk_storage_c_fixture() -> i32;
    fn sdk_storage_table(out: *mut abi::R4XStartR4Sys);
    fn sdk_storage_mode(mode: i32);
    fn sdk_storage_directory_stale(mode: i32);
    fn sdk_storage_close_mode(mode: i32);
    fn sdk_storage_console(out: *mut u8, capacity: u32) -> u32;
}
#[test]
fn existing_bytes_real_facades_and_explicit_failure_ownership() {
    assert_eq!(unsafe { sdk_storage_c_fixture() }, 0);
    common::codecs();
    let mut api = abi::R4XStartR4Sys::default();
    unsafe { sdk_storage_table(&mut api) };
    let import = abi::R4XStartImport {
        group_id: 1,
        min_version: 1,
        resolved_version: 1,
        flags: abi::r4xstart_import_flag_group_interface,
        module_name: c"R4SYS".as_ptr() as u64,
        symbol_name: c"Query".as_ptr() as u64,
        table: std::ptr::from_ref(&api) as u64,
    };
    let ctx = abi::R4XStartContext {
        app_class: abi::R4XStartAppClass::console.0,
        instance_id: 42,
        flags: abi::r4xstart_flag_imports_valid,
        imports: std::ptr::from_ref(&import) as u64,
        import_count: 1,
        ..Default::default()
    };
    let expected = StartupInfo {
        app_class: abi::R4XStartAppClass::console,
        required_groups: 2,
        imports: &[ImportSpec {
            module_name: b"R4SYS",
            symbol_name: b"Query",
            minimum: 1,
            optional: false,
            group_id: 1,
            magic: api.magic,
            version: api.abi_version,
            size: api.size,
        }],
    };
    let app = unsafe { App::from_raw(&ctx, &expected, c"STORAGE") }.unwrap();
    let system = System::new(&app).unwrap();
    let console = system.console();
    let mut captured = [0; 64];
    unsafe { sdk_storage_mode(40) };
    console.write(&[b'X', 0, 0xc4]).unwrap();
    let n = unsafe { sdk_storage_console(captured.as_mut_ptr(), 64) };
    assert_eq!(&captured[..n as usize], &[b'X', 0, 0xc4]);
    unsafe { sdk_storage_mode(41) };
    console.line(&[b'X', 0, 0xc4]).unwrap();
    let n = unsafe { sdk_storage_console(captured.as_mut_ptr(), 64) };
    assert_eq!(&captured[..n as usize], &[b'X', 0, 0xc4, b'\r', b'\n']);
    unsafe { sdk_storage_mode(0) };
    assert!(!r4os_sdk::registry_diagnostics::private_image(&system));
    let files = system.files();
    let path = FilePath::parse(b"C:\\TEMP\\FILE.TXT").unwrap();
    unsafe { sdk_storage_mode(50) };
    let limits = files.name_limits(&path).unwrap();
    assert_eq!(
        (
            limits.size,
            limits.provider,
            limits.mount_slot,
            limits.mount_generation
        ),
        (56, 2, 7, 99)
    );
    assert_eq!(
        (
            limits.max_path_bytes,
            limits.max_component_bytes,
            limits.max_component_utf16_units
        ),
        (1023, 765, 255)
    );
    assert_eq!(
        (
            limits.short_base_bytes,
            limits.short_extension_bytes,
            limits.atomic_rules
        ),
        (8, 3, 7)
    );
    for (mode, code) in [
        (51, -2),
        (52, abi::file_stream_error_name_not_supported),
        (53, abi::file_stream_error_name_too_long),
    ] {
        unsafe { sdk_storage_mode(mode) };
        assert!(matches!(files.name_limits(&path),Err(Error::Raw(raw)) if raw==code));
    }
    unsafe { sdk_storage_mode(54) };
    assert!(matches!(
        files.name_limits(&path),
        Err(Error::InvalidProvider)
    ));
    for (mode, code) in [
        (55, abi::file_stream_error_name_not_supported),
        (56, abi::file_stream_error_name_too_long),
    ] {
        unsafe { sdk_storage_mode(mode) };
        let failure = files
            .stream_writer(&path, abi::file_stream_open_create)
            .err()
            .unwrap();
        assert!(matches!(failure.error,Error::Raw(raw) if raw==code));
        assert!(!failure.writer.needs_abort());
    }
    unsafe { sdk_storage_mode(0) };
    let directory = FilePath::parse(b"C:\\").unwrap();
    let mut bytes = [0; 128];
    assert_eq!(files.read(&path, &mut bytes).unwrap(), Some(5));
    assert_eq!(&bytes[..5], b"hello");
    let mut reader = files.stream_reader(&path);
    assert_eq!(reader.read(&mut bytes[..2]).unwrap(), Some(2));
    assert_eq!(reader.read(&mut bytes).unwrap(), Some(3));
    assert_eq!(reader.read(&mut bytes).unwrap(), None);
    assert_eq!(reader.offset(), 5);
    let mut iterator = files.iterate(&directory);
    assert!(!iterator.next_entry().unwrap().unwrap().is_directory);
    unsafe { sdk_storage_directory_stale(1) };
    assert!(matches!(iterator.next_entry(), Err(Error::Raw(-10))));
    unsafe { sdk_storage_directory_stale(0) };
    assert!(iterator.next_entry().unwrap().unwrap().is_directory);
    assert!(iterator.next_entry().unwrap().is_none());
    let mut cursor = abi::DirectoryBatchCursor::default();
    let mut records = [abi::DirectoryBatchEntry::default(); 2];
    assert_eq!(
        app.directory_batch(c"C:\\", &mut cursor, &mut records),
        Some(2)
    );
    assert_eq!(
        app.directory_batch(c"Z:\\IGNORED", &mut cursor, &mut []),
        Some(0)
    );
    let mut writer = files
        .stream_writer(&path, abi::file_stream_open_replace)
        .unwrap();
    writer.write(b"stream").unwrap();
    writer.finish().unwrap();
    assert!(!writer.needs_abort());
    unsafe { sdk_storage_mode(20) };
    let mut failed = files
        .stream_writer(&path, abi::file_stream_open_replace)
        .err()
        .unwrap();
    assert!(matches!(failed.error, Error::Raw(-7)));
    assert!(failed.writer.needs_abort());
    unsafe { sdk_storage_mode(0) };
    failed.writer.abort().unwrap();
    let mut writer = files
        .stream_writer(&path, abi::file_stream_open_replace)
        .unwrap();
    unsafe { sdk_storage_mode(21) };
    assert!(writer.write(b"short").is_err());
    assert_eq!(writer.offset(), 0);
    unsafe { sdk_storage_mode(23) };
    assert!(writer.abort().is_err());
    assert!(writer.needs_abort());
    unsafe { sdk_storage_mode(0) };
    writer.abort().unwrap();
    let mut sequence = 0;
    assert_eq!(
        files.save(&mut sequence, &path, b"saved", false),
        SaveResult::Saved
    );
    unsafe { sdk_storage_mode(1) };
    assert_eq!(
        files.save(&mut sequence, &path, b"saved", false),
        SaveResult::CopiesRetained
    );
    unsafe { sdk_storage_mode(2) };
    assert_eq!(
        files.save(&mut sequence, &path, b"saved", false),
        SaveResult::BackupRetained
    );
    unsafe { sdk_storage_mode(22) };
    assert_eq!(
        files.save(&mut sequence, &path, b"saved", false),
        SaveResult::Failed
    );
    unsafe { sdk_storage_mode(0) };
    let registry = system.registry();
    let key = RegistryPath::parse(b"HKCU/Software/Test").unwrap();
    assert_eq!(
        registry
            .get(&key, c"COUNT", &mut bytes)
            .unwrap()
            .unwrap()
            .as_u32(),
        Some(0x12345678)
    );
    assert_eq!(
        registry
            .get(&key, c"WIDE", &mut bytes)
            .unwrap()
            .unwrap()
            .as_u64(),
        Some(0x0102030405060708)
    );
    assert_eq!(
        registry
            .get(&key, c"ENABLED", &mut bytes)
            .unwrap()
            .unwrap()
            .as_bool(),
        Some(true)
    );
    assert_eq!(
        registry
            .get(&key, c"TEXT", &mut bytes)
            .unwrap()
            .unwrap()
            .as_string(),
        Some(&b"OK"[..])
    );
    assert!(
        registry
            .get(&key, c"MISSING", &mut bytes)
            .unwrap()
            .is_none()
    );
    assert!(registry.get(&key, c"COUNT", &mut bytes[..1]).is_err());
    let mut ops = [abi::RegistryBatchOperation::default(); 1];
    let mut blob = [0; 128];
    let mut batch = RegistryBatch::new(&mut ops, &mut blob).unwrap();
    batch.set_u32(&key, c"COUNT", 99).unwrap();
    let before = batch.blob().len();
    assert!(batch.set_u32(&key, c"COUNT", 1).is_err());
    assert_eq!(batch.operations().len(), 1);
    assert_eq!(batch.blob().len(), before);
    let applied = registry.apply_batch(&batch);
    assert_eq!(applied.raw_code, 0);
    assert_eq!(applied.result.status, abi::registry_batch_status_committed);
    let mut snapshot = registry
        .begin_snapshot(&key, SnapshotKind::Values)
        .unwrap()
        .unwrap();
    let mut entries = [abi::RegistrySnapshotEntry::default(); 2];
    let p = snapshot.page(&mut entries, &mut bytes).unwrap();
    assert_eq!((p.generation, p.returned, p.data_bytes), (77, 1, 4));
    unsafe { sdk_storage_mode(30) };
    let p = snapshot.page(&mut entries, &mut bytes).unwrap();
    assert_eq!(p.status, abi::registry_snapshot_status_restart);
    assert_eq!(snapshot.cursor().generation, 78);
    unsafe { sdk_storage_mode(0) };
    let physical = system.physical_storage();
    let mut claim = physical.claim(&abi::StorageTarget::default()).unwrap();
    assert_eq!(claim.id(), 17);
    assert_eq!(claim.end(false), Err(Error::Raw(abi::storage_error_busy)));
    assert_eq!(claim.id(), 17);
    unsafe { sdk_storage_close_mode(abi::storage_error_io) };
    assert!(claim.end(false).is_err());
    assert_eq!(claim.id(), 0);
    let mut page = DialogPage::<4>::new().unwrap();
    let mut scratch = unsafe { std::mem::zeroed::<[r4os_sdk::c_facades::R4DialogRow; 4]>() };
    assert!(
        page.load(&files, &mut scratch, &directory, 0, b".TXT")
            .unwrap()
    );
    assert_eq!(page.rows().len(), 3);
    let mut snapshot = Snapshot::<u32>::new(257 * 4).unwrap();
    for n in (0..257).rev() {
        snapshot.append(n).unwrap()
    }
    snapshot.sort(u32::cmp);
    assert!(snapshot.values().iter().copied().eq(0..257));
    assert!(snapshot.append(999).is_err());
}
