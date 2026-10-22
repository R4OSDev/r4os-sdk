#![no_std]
use r4os_r4std::{
    ConfigV1Client, R4StdTextInfo, TextV1Client, text_kind_utf8, text_v1_expectation,
};
use r4os_sdk::{App, abi, r4l};
unsafe extern "C" {
    fn r4_library_c_consumer(context: *const abi::R4XStartContext) -> i32;
}
fn main(app: &mut App<'_>) -> i32 {
    let Ok(text) = TextV1Client::init(app) else {
        return 1;
    };
    let Ok(Some(_)) = TextV1Client::optional(app) else {
        return 2;
    };
    let Ok(None) = ConfigV1Client::optional(app) else {
        return 3;
    };
    let Ok(None) = r4l::Interface::optional(app, "SDKABSENT", "API_V1", text_v1_expectation) else {
        return 4;
    };
    let Ok(query) = r4l::query(app, "R4STD") else {
        return 5;
    };
    if query.group != 0 || query.kernel_bridge != 0 {
        return 6;
    }
    let bytes = "Aä€".as_bytes();
    let mut info = R4StdTextInfo::default();
    if unsafe {
        text.inspect(
            bytes.as_ptr(),
            bytes.len() as u64,
            text_kind_utf8,
            &mut info,
        )
    } != 0
        || info.scalar_count != 3
        || info.content_length != bytes.len() as u64
    {
        return 7;
    }
    if unsafe { r4_library_c_consumer(app.start_context()) } != 0 {
        return 8;
    }
    let _=app.write("[RUSTLIB] generated Rust/C named interfaces, Query, optional absence and real R4STD call OK\n");
    0
}
r4os_sdk::app!(main);
