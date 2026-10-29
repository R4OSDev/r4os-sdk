#![cfg(test)]
use core::pin::pin;
use r4os_sdk::{
    abi,
    data::{
        Arena, ArenaStorage, Decoder, Encoding, Icon, MemoryPolicy, Raster, SearchParams, Sha256,
        digest, encode_into, resolve_url,
    },
};
unsafe extern "C" {
    fn sdk_data_c_case(manifest: *const u8, length: usize) -> i32;
    fn sdk_ico_c_case(bytes: *const u8, length: usize) -> i32;
}
const MANIFEST: &[u8] = include_bytes!("../Fixtures/Data/manifest.r4mf.txt");
#[test]
fn c_scalar_facades_use_original_state_error_values_and_allocator() {
    assert_eq!(
        unsafe { sdk_data_c_case(MANIFEST.as_ptr(), MANIFEST.len()) },
        0
    );
}
#[test]
fn original_streaming_hash_and_overlap_policy_preserve_exact_bytes() {
    let mut hash = Sha256::software().unwrap();
    hash.update(b"a").unwrap();
    hash.update(b"bc").unwrap();
    assert_eq!(hash.peek().unwrap(), hash.finish().unwrap());
    let mut out = [0; 32];
    let expected = digest(b"sHa-256", b"abc", &mut out).unwrap();
    assert_eq!(expected[0], 0xba);
    assert_eq!(expected[31], 0xad);
    assert!(digest(b"SHA-1", b"abc", &mut [0; 32]).is_err());
    assert!(digest(b"SHA-256", b"abc", &mut [0; 31]).is_err());
    let input: Vec<u8> = (0..12289).map(|i| (i * 73) as u8).collect();
    let expected = digest(b"SHA-256", &input, &mut out).unwrap();
    let mut streaming = Sha256::software().unwrap();
    for part in input.chunks(511) {
        streaming.update(part).unwrap();
    }
    assert_eq!(streaming.counters().unwrap(), (0, 0));
    assert_eq!(streaming.finish().unwrap(), expected);
    let policy = MemoryPolicy::from_info(&abi::CpuAccelerationInfo::default()).unwrap();
    let mut buffer: [u8; 32] = core::array::from_fn(|i| i as u8);
    let mut oracle = buffer;
    oracle.copy_within(0..24, 4);
    policy.copy_within(&mut buffer, 0..24, 4).unwrap();
    assert_eq!(buffer, oracle);
    assert!(policy.copy_within(&mut buffer, 0..33, 0).is_err());
}
#[test]
fn text_streams_and_url_views_preserve_owner_progress_and_failures() {
    assert_eq!(Encoding::parse(b"latin1").unwrap(), Encoding::Windows1252);
    assert!(Encoding::parse(b"utf-16").is_err());
    let mut d = Decoder::new(Encoding::Utf8, true, false).unwrap();
    let mut bytes = [0; 16];
    assert_eq!(d.decode(b"\xc3", &mut bytes, true).unwrap(), "");
    let mut d = Decoder::from_packed(d.packed().unwrap()).unwrap();
    assert_eq!(d.decode(b"\xbc", &mut bytes, false).unwrap(), "ü");
    assert!(d.decode(b"\xff", &mut bytes, false).is_err());
    assert_eq!(d.decode(b"A", &mut bytes, false).unwrap(), "A");
    assert_eq!(encode_into("🙂!", &mut [0; 3]).unwrap(), (0, 0));
    assert_eq!(encode_into("🙂!", &mut [0; 4]).unwrap(), (2, 4));
    let mut params = SearchParams::new(b"a=one+two&a=three&b=%e2%82%ac").unwrap();
    assert_eq!(params.get(b"a").unwrap(), Some(&b"one two"[..]));
    assert!(params.has(b"a", Some(b"three")).unwrap());
    params.delete(b"a", Some(b"one two")).unwrap();
    params.append(b"c", b"!").unwrap();
    params.sort().unwrap();
    let mut out = [0; 128];
    assert_eq!(
        params.serialize(&mut out).unwrap(),
        b"a=three&b=%E2%82%AC&c=%21"
    );
    assert_eq!(
        resolve_url(b"https://example.test", b"/a/b", b"../c?x=1", &mut out).unwrap(),
        b"https://example.test/c?x=1"
    );
}
#[test]
fn original_raster_resize_and_existing_ico_fixture_match_owner_oracles() {
    let mut pixels = [0; 16];
    let mut raster = Raster::new(&mut pixels, 2, 2, 0xffffff).unwrap();
    assert!(raster.set(1, 0, 0x010203).unwrap());
    raster.resize(3, 3, 0x090909).unwrap();
    assert_eq!(raster.pixel(1, 0).unwrap(), Some(0x010203));
    assert_eq!(raster.pixel(2, 2).unwrap(), Some(0x090909));
    assert!(raster.resize(129, 1, 0).is_err());
    assert_eq!(raster.pixels().unwrap().len(), 9);
    let icon = Icon::open(include_bytes!("../Fixtures/Icons/windows32.ico")).unwrap();
    assert_eq!(icon.count().unwrap(), 1);
    let image = icon.bitmap(0).unwrap();
    assert_eq!(image.dimensions().unwrap(), (2, 2));
    assert_eq!(image.pixel(0, 0).unwrap(), Some((0xff, 0xff)));
    assert_eq!(image.pixel(1, 0).unwrap().unwrap().1, 0);
    assert!(Icon::open(b"bad").is_err());
    for (bytes, colors) in [
        (
            include_bytes!("../Fixtures/Icons/windows32.ico").as_slice(),
            [0xff, 0xff00, 0xff0000, 0xffffff],
        ),
        (
            include_bytes!("../Fixtures/Icons/indexed8.ico").as_slice(),
            [0xff0000, 0xff, 0xff, 0xff0000],
        ),
    ] {
        assert_eq!(unsafe { sdk_ico_c_case(bytes.as_ptr(), bytes.len()) }, 0);
        let bitmap = Icon::open(bytes).unwrap().best_bitmap(32).unwrap();
        let mut rgb = [0x12345678; 24];
        let mut alpha = [91; 24];
        bitmap
            .copy_scaled_pixels(&mut rgb, &mut alpha, 4, 4, 6)
            .unwrap();
        for i in 0..24 {
            let (x, y) = (i % 6, i / 6);
            if x < 4 {
                let at = y / 2 * 2 + x / 2;
                assert_eq!(rgb[i], colors[at]);
                assert_eq!(alpha[i], [255, 0, 255, 255][at]);
            } else {
                assert_eq!((rgb[i], alpha[i]), (0x12345678, 91));
            }
        }
        let before = (rgb, alpha);
        assert_eq!(
            bitmap.copy_scaled_pixels(&mut rgb[..3], &mut alpha, 2, 2, 2),
            Err(r4os_sdk::data::Error::Bounds)
        );
        assert_eq!((rgb, alpha), before);
    }
}
#[test]
fn current_manifest_parser_plan_and_scratch_bounds_are_shared() {
    let mut storage = pin!(ArenaStorage::new());
    let mut bytes = [0; 65536];
    let mut arena = Arena::open(storage.as_mut(), &mut bytes).unwrap();
    {
        let m = arena.manifest(b"module.R4MF", MANIFEST).unwrap();
        assert_eq!(m.name().unwrap(), b"DATAUNIT");
        assert_eq!(m.version().unwrap(), (1, 2, 3));
        let mut plan = [0; 8192];
        let (text, ok) = m.contract_plan(&mut plan).unwrap();
        assert!(ok && text.windows(8).any(|b| b == b"DATAUNIT"));
    }
    assert!(arena.used().unwrap() > 0);
    arena.reset().unwrap();
    assert_eq!(arena.used().unwrap(), 0);
    assert!(
        arena
            .manifest(b"module.R4MF", b"R4OS_MODULE_MANIFEST=1\n")
            .is_err()
    );
    let mut small_storage = pin!(ArenaStorage::new());
    let mut tiny = [0; 8];
    let mut small = Arena::open(small_storage.as_mut(), &mut tiny).unwrap();
    assert!(small.manifest(b"module.R4MF", MANIFEST).is_err());
}
