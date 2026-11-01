#![cfg(test)]
use core::{mem::MaybeUninit, pin::pin};
use r4os_sdk::{
    data::{Arena, ArenaStorage},
    web::transport::{Cache, CacheClock, CacheKey, CacheMode, raw as c},
};
unsafe extern "C" {
    fn sdk_transport_c_case(scratch: *mut u8, capacity: usize) -> i32;
    fn sdk_transport_bootstrap_case() -> i32;
}
fn check(v: c::R4SdkTransportSlot) -> c::R4SdkTransportSlot {
    assert_eq!(v.status, 0);
    assert_eq!(v.flags & 2, 0);
    v
}
#[test]
fn original_c_parser_cache_callbacks_and_ipv4() {
    let mut scratch = vec![0; 32768];
    let code = unsafe { sdk_transport_c_case(scratch.as_mut_ptr(), scratch.len()) };
    assert_eq!(code, 0);
}
#[test]
fn generated_registration_endpoint_preserves_public_ip_and_tls_mode() {
    let mut ip = MaybeUninit::<c::R4SdkTransportNative_app_network_Ipv4Address>::uninit();
    let mut endpoint = MaybeUninit::<c::R4SdkTransportRegistrationEndpoint>::uninit();
    let name = b"138.201.253.143";
    unsafe {
        check(c::R4SdkTransportNative_app_network_Ipv4Address_init(
            0, 138, 201, 253, 143, ip.as_mut_ptr(),
        ));
        check(c::R4SdkTransportRegistrationEndpoint_from_fields(
            endpoint.as_mut_ptr(), ip.as_ptr(), name.as_ptr(), name.len() as u64, 4021, 1,
        ));
        let hostname = check(c::R4SdkTransportRegistrationEndpoint_get_hostname(endpoint.as_ptr()));
        assert_eq!(core::slice::from_raw_parts(hostname.ptr.cast::<u8>(), hostname.length as usize), name);
        assert_eq!(check(c::R4SdkTransportRegistrationEndpoint_get_port(endpoint.as_ptr())).bits, 4021);
        assert_eq!(check(c::R4SdkTransportRegistrationEndpoint_get_tls(endpoint.as_ptr())).bits, 1);
    }
}
#[test]
fn common_startup_binds_original_entropy_without_optional_host_instructions() {
    assert_eq!(unsafe { sdk_transport_bootstrap_case() }, 0);
}
#[test]
fn cache_invalidation_keeps_exact_pinned_view_until_release() {
    let mut arena_storage = pin!(ArenaStorage::new());
    let mut bytes = vec![0; 65536];
    let mut arena = Arena::open(arena_storage.as_mut(), &mut bytes).unwrap();
    let mut storage = MaybeUninit::uninit();
    let mut cache = Cache::open(&mut storage, &mut arena, 256, 4096).unwrap();
    let key = || CacheKey {
        url: b"http://local/x",
        context: b"partition",
        headers: b"accept:x\r\n",
    };
    let now = CacheClock {
        monotonic_ms: 1000,
        unix_seconds: None,
    };
    assert!(
        cache
            .store(key(), b"Cache-Control: max-age=60\r\n", b"body", now, 1000)
            .unwrap()
            .is_some()
    );
    {
        let lease = cache
            .lookup(key(), CacheMode::Normal, now)
            .unwrap()
            .unwrap();
        let body = lease.body().unwrap();
        cache.invalidate(key()).unwrap();
        assert_eq!(body, b"body");
        assert_eq!(lease.headers().unwrap(), b"Cache-Control: max-age=60\r\n");
    }
    assert!(
        cache
            .lookup(key(), CacheMode::OnlyIfCached, now)
            .unwrap()
            .is_none()
    );
}
#[test]
fn original_response_decoding_rejects_truncation_and_preserves_cancel() {
    let input = b"HTTP/1.1 200 OK\r\nContent-Length: 5\r\n\r\nabc";
    let mut out = [0; 16];
    let mut decoder = MaybeUninit::uninit();
    let mut result = MaybeUninit::uninit();
    unsafe {
        check(c::R4SdkTransportHttpResponseDecoder_init(
            0,
            c::R4SdkWebNative_http_Method_get,
            decoder.as_mut_ptr(),
        ));
        check(c::R4SdkTransportHttpResponseDecoder_decode(
            0,
            decoder.as_mut_ptr(),
            input.as_ptr(),
            input.len() as u64,
            out.as_mut_ptr(),
            16,
            1,
            0,
            result.as_mut_ptr(),
        ));
        assert_eq!(
            check(c::R4SdkTransportHttpDecodeResult_inspectNative(
                result.as_ptr()
            ))
            .bits,
            u64::from(c::R4SdkTransportHttpDecodeResult_TAG_failure)
        );
        check(c::R4SdkTransportHttpResponseDecoder_init(
            0,
            c::R4SdkWebNative_http_Method_get,
            decoder.as_mut_ptr(),
        ));
        check(c::R4SdkTransportHttpResponseDecoder_decode(
            0,
            decoder.as_mut_ptr(),
            input.as_ptr(),
            input.len() as u64,
            out.as_mut_ptr(),
            16,
            0,
            1,
            result.as_mut_ptr(),
        ));
        assert_eq!(
            check(c::R4SdkTransportHttpDecodeResult_inspectNative(
                result.as_ptr()
            ))
            .bits,
            u64::from(c::R4SdkTransportHttpDecodeResult_TAG_aborted)
        );
    }
}
