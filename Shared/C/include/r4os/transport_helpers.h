/* Compiler-generated SDK data helper boundary. Do not edit.
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
#ifndef R4SDKTRANSPORT_HELPERS_H
#define R4SDKTRANSPORT_HELPERS_H
#include "r4os/abi.h"
#define R4SDKTRANSPORT_PRESENT 1u
#define R4SDKTRANSPORT_NATIVE_ERROR 2u
#define R4SDKTRANSPORT_DEFAULT 4u
typedef struct R4SdkTransportSlot { void *ptr; uint64_t length,bits; int32_t status; uint32_t flags; } R4SdkTransportSlot;
R4SdkTransportSlot R4SdkTransportInvoke(uint64_t,uint32_t,const R4SdkTransportSlot *,uint32_t,void *);
R4SdkTransportSlot R4SdkTransportConstruct(uint64_t,uint32_t,const R4SdkTransportSlot *,uint32_t,void *);
R4SdkTransportSlot R4SdkTransportInspect(uint64_t,uint32_t,void *,void *);
R4SdkTransportSlot R4SdkTransportField(uint64_t,uint32_t,uint32_t,void *,const R4SdkTransportSlot *,void *);
/* app_web.RequestDeadline; native size 16, alignment 8. */
typedef struct R4SdkTransportRequestDeadline { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportRequestDeadline;
#define R4SdkTransportRequestDeadline_TYPE 1u
/* app_web.Error; native size 1, alignment 1. */
typedef struct R4SdkTransportError { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportError;
#define R4SdkTransportError_TYPE 2u
/* app_web.RedirectMode; native size 1, alignment 1. */
typedef struct R4SdkTransportRedirectMode { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportRedirectMode;
#define R4SdkTransportRedirectMode_TYPE 3u
/* app_web.TransportStats; native size 48, alignment 8. */
typedef struct R4SdkTransportTransportStats { _Alignas(8) uint8_t opaque_bytes[48]; } R4SdkTransportTransportStats;
#define R4SdkTransportTransportStats_TYPE 4u
/* app_web.FetchOptions; native size 304, alignment 8. */
typedef struct R4SdkTransportFetchOptions { _Alignas(8) uint8_t opaque_bytes[304]; } R4SdkTransportFetchOptions;
#define R4SdkTransportFetchOptions_TYPE 5u
/* ?*app_web.SessionPool; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue6 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue6;
#define R4SdkTransportNativeValue6_TYPE 6u
/* *app_web.SessionPool; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue7 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue7;
#define R4SdkTransportNativeValue7_TYPE 7u
/* app_web.SessionPool; native size 70152, alignment 8. */
typedef struct R4SdkTransportSessionPool { _Alignas(8) uint8_t opaque_bytes[70152]; } R4SdkTransportSessionPool;
#define R4SdkTransportSessionPool_TYPE 8u
/* [2]app_web.SessionPool.Entry; native size 4512, alignment 8. */
typedef struct R4SdkTransportNativeValue9 { _Alignas(8) uint8_t opaque_bytes[4512]; } R4SdkTransportNativeValue9;
#define R4SdkTransportNativeValue9_TYPE 9u
/* app_web.SessionPool.Entry; native size 2256, alignment 8. */
typedef struct R4SdkTransportSessionPool_Entry { _Alignas(8) uint8_t opaque_bytes[2256]; } R4SdkTransportSessionPool_Entry;
#define R4SdkTransportSessionPool_Entry_TYPE 10u
/* [2048]u8; native size 2048, alignment 1. */
typedef struct R4SdkTransportNativeValue11 { _Alignas(1) uint8_t opaque_bytes[2048]; } R4SdkTransportNativeValue11;
#define R4SdkTransportNativeValue11_TYPE 11u
/* ?app_network.TcpSocket; native size 40, alignment 8. */
typedef struct R4SdkTransportNativeValue12 { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkTransportNativeValue12;
#define R4SdkTransportNativeValue12_TYPE 12u
/* app_network.TcpSocket; native size 32, alignment 8. */
typedef struct R4SdkTransportNative_app_network_TcpSocket { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkTransportNative_app_network_TcpSocket;
#define R4SdkTransportNative_app_network_TcpSocket_TYPE 13u
/* app_network.Network; native size 16, alignment 8. */
typedef struct R4SdkTransportNative_app_network_Network { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportNative_app_network_Network;
#define R4SdkTransportNative_app_network_Network_TYPE 14u
/* r4sys.Context; native size 8, alignment 8. */
typedef struct R4SdkTransportNative_r4sys_Context { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNative_r4sys_Context;
#define R4SdkTransportNative_r4sys_Context_TYPE 15u
/* r4net.Context; native size 8, alignment 8. */
typedef struct R4SdkTransportNative_r4net_Context { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNative_r4net_Context;
#define R4SdkTransportNative_r4net_Context_TYPE 16u
/* app_network.SocketAddress; native size 6, alignment 2. */
typedef struct R4SdkTransportNative_app_network_SocketAddress { _Alignas(2) uint8_t opaque_bytes[6]; } R4SdkTransportNative_app_network_SocketAddress;
#define R4SdkTransportNative_app_network_SocketAddress_TYPE 17u
/* app_network.Ipv4Address; native size 4, alignment 1. */
typedef struct R4SdkTransportNative_app_network_Ipv4Address { _Alignas(1) uint8_t opaque_bytes[4]; } R4SdkTransportNative_app_network_Ipv4Address;
#define R4SdkTransportNative_app_network_Ipv4Address_TYPE 18u
/* [4]u8; native size 4, alignment 1. */
typedef struct R4SdkTransportNativeValue19 { _Alignas(1) uint8_t opaque_bytes[4]; } R4SdkTransportNativeValue19;
#define R4SdkTransportNativeValue19_TYPE 19u
/* ?app_web.TlsSession; native size 141, alignment 1. */
typedef struct R4SdkTransportNativeValue20 { _Alignas(1) uint8_t opaque_bytes[141]; } R4SdkTransportNativeValue20;
#define R4SdkTransportNativeValue20_TYPE 20u
/* app_web.TlsSession; native size 140, alignment 1. */
typedef struct R4SdkTransportTlsSession { _Alignas(1) uint8_t opaque_bytes[140]; } R4SdkTransportTlsSession;
#define R4SdkTransportTlsSession_TYPE 21u
/* [140]u8; native size 140, alignment 1. */
typedef struct R4SdkTransportNativeValue22 { _Alignas(1) uint8_t opaque_bytes[140]; } R4SdkTransportNativeValue22;
#define R4SdkTransportNativeValue22_TYPE 22u
/* [4]app_web.SessionPool.Preflight; native size 65632, alignment 8. */
typedef struct R4SdkTransportNativeValue23 { _Alignas(8) uint8_t opaque_bytes[65632]; } R4SdkTransportNativeValue23;
#define R4SdkTransportNativeValue23_TYPE 23u
/* app_web.SessionPool.Preflight; native size 16408, alignment 8. */
typedef struct R4SdkTransportSessionPool_Preflight { _Alignas(8) uint8_t opaque_bytes[16408]; } R4SdkTransportSessionPool_Preflight;
#define R4SdkTransportSessionPool_Preflight_TYPE 24u
/* ?app_web.RequestDeadline; native size 24, alignment 8. */
typedef struct R4SdkTransportNativeValue27 { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportNativeValue27;
#define R4SdkTransportNativeValue27_TYPE 27u
/* ?*app_web.TransportStats; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue28 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue28;
#define R4SdkTransportNativeValue28_TYPE 28u
/* *app_web.TransportStats; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue29 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue29;
#define R4SdkTransportNativeValue29_TYPE 29u
/* ?*const abi_generated.R4StopFlag; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue31 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue31;
#define R4SdkTransportNativeValue31_TYPE 31u
/* *const abi_generated.R4StopFlag; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue32 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue32;
#define R4SdkTransportNativeValue32_TYPE 32u
/* ?*const fn (?*anyopaque) callconv(.c) bool; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue34 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue34;
#define R4SdkTransportNativeValue34_TYPE 34u
/* ?*const fn (?*anyopaque, []const u8, []u8) []const u8; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue38 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue38;
#define R4SdkTransportNativeValue38_TYPE 38u
/* ?*const fn (?*anyopaque, []const u8, []const u8) void; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue39 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue39;
#define R4SdkTransportNativeValue39_TYPE 39u
/* ?*const fn (?*anyopaque, []const u8) bool; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue40 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue40;
#define R4SdkTransportNativeValue40_TYPE 40u
/* app_web.FetchResponse; native size 1408, alignment 8. */
typedef struct R4SdkTransportFetchResponse { _Alignas(8) uint8_t opaque_bytes[1408]; } R4SdkTransportFetchResponse;
#define R4SdkTransportFetchResponse_TYPE 41u
/* app_web.FinalUrl; native size 1040, alignment 8. */
typedef struct R4SdkTransportFinalUrl { _Alignas(8) uint8_t opaque_bytes[1040]; } R4SdkTransportFinalUrl;
#define R4SdkTransportFinalUrl_TYPE 44u
/* [1025]u8; native size 1025, alignment 1. */
typedef struct R4SdkTransportNativeValue45 { _Alignas(1) uint8_t opaque_bytes[1025]; } R4SdkTransportNativeValue45;
#define R4SdkTransportNativeValue45_TYPE 45u
/* app_web.FetchResult; native size 1416, alignment 8. */
typedef struct R4SdkTransportFetchResult { _Alignas(8) uint8_t opaque_bytes[1416]; } R4SdkTransportFetchResult;
#define R4SdkTransportFetchResult_TYPE 46u
/* @typeInfo(app_web.FetchResult).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_app_web_FetchResult____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_app_web_FetchResult____union__tag_type__;
#define R4SdkTransportNative__typeInfo_app_web_FetchResult____union__tag_type___TYPE 47u
/* app_web.DownloadSink; native size 16, alignment 8. */
typedef struct R4SdkTransportDownloadSink { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportDownloadSink;
#define R4SdkTransportDownloadSink_TYPE 48u
/* app_web.DownloadOptions; native size 136, alignment 8. */
typedef struct R4SdkTransportDownloadOptions { _Alignas(8) uint8_t opaque_bytes[136]; } R4SdkTransportDownloadOptions;
#define R4SdkTransportDownloadOptions_TYPE 49u
/* ?*const fn (?*anyopaque, u64, u64) bool; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue50 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue50;
#define R4SdkTransportNativeValue50_TYPE 50u
/* ?u64; native size 16, alignment 8. */
typedef struct R4SdkTransportNativeValue51 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportNativeValue51;
#define R4SdkTransportNativeValue51_TYPE 51u
/* app_web.DownloadResponse; native size 1080, alignment 8. */
typedef struct R4SdkTransportDownloadResponse { _Alignas(8) uint8_t opaque_bytes[1080]; } R4SdkTransportDownloadResponse;
#define R4SdkTransportDownloadResponse_TYPE 52u
/* app_web.DownloadResult; native size 1088, alignment 8. */
typedef struct R4SdkTransportDownloadResult { _Alignas(8) uint8_t opaque_bytes[1088]; } R4SdkTransportDownloadResult;
#define R4SdkTransportDownloadResult_TYPE 53u
/* @typeInfo(app_web.DownloadResult).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_app_web_DownloadResult____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_app_web_DownloadResult____union__tag_type__;
#define R4SdkTransportNative__typeInfo_app_web_DownloadResult____union__tag_type___TYPE 54u
/* app_web.WebTransport; native size 24, alignment 8. */
typedef struct R4SdkTransportWebTransport { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportWebTransport;
#define R4SdkTransportWebTransport_TYPE 55u
/* r4dev.Context; native size 8, alignment 8. */
typedef struct R4SdkTransportNative_r4dev_Context { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNative_r4dev_Context;
#define R4SdkTransportNative_r4dev_Context_TYPE 56u
/* *[32]u8; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue57 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue57;
#define R4SdkTransportNativeValue57_TYPE 57u
/* http.Scheme; native size 1, alignment 1. */
typedef struct R4SdkTransportHttpScheme { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportHttpScheme;
#define R4SdkTransportHttpScheme_TYPE 59u
/* http.UrlError; native size 1, alignment 1. */
typedef struct R4SdkTransportHttpUrlError { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportHttpUrlError;
#define R4SdkTransportHttpUrlError_TYPE 60u
/* http.ParsedUrl; native size 40, alignment 8. */
typedef struct R4SdkTransportHttpParsedUrl { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkTransportHttpParsedUrl;
#define R4SdkTransportHttpParsedUrl_TYPE 61u
/* http.UrlResult; native size 48, alignment 8. */
typedef struct R4SdkTransportHttpUrlResult { _Alignas(8) uint8_t opaque_bytes[48]; } R4SdkTransportHttpUrlResult;
#define R4SdkTransportHttpUrlResult_TYPE 62u
/* @typeInfo(http.UrlResult).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_http_UrlResult____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_http_UrlResult____union__tag_type__;
#define R4SdkTransportNative__typeInfo_http_UrlResult____union__tag_type___TYPE 63u
/* http.RequestOptions; native size 120, alignment 8. */
typedef struct R4SdkTransportHttpRequestOptions { _Alignas(8) uint8_t opaque_bytes[120]; } R4SdkTransportHttpRequestOptions;
#define R4SdkTransportHttpRequestOptions_TYPE 64u
/* http.BuildResult; native size 24, alignment 8. */
typedef struct R4SdkTransportHttpBuildResult { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportHttpBuildResult;
#define R4SdkTransportHttpBuildResult_TYPE 65u
/* @typeInfo(http.BuildResult).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_http_BuildResult____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_http_BuildResult____union__tag_type__;
#define R4SdkTransportNative__typeInfo_http_BuildResult____union__tag_type___TYPE 66u
/* http.Transfer; native size 1, alignment 1. */
typedef struct R4SdkTransportHttpTransfer { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportHttpTransfer;
#define R4SdkTransportHttpTransfer_TYPE 67u
/* http.ContentRange; native size 32, alignment 8. */
typedef struct R4SdkTransportHttpContentRange { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkTransportHttpContentRange;
#define R4SdkTransportHttpContentRange_TYPE 68u
/* http.ResponseError; native size 1, alignment 1. */
typedef struct R4SdkTransportHttpResponseError { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportHttpResponseError;
#define R4SdkTransportHttpResponseError_TYPE 69u
/* http.Response; native size 432, alignment 8. */
typedef struct R4SdkTransportHttpResponse { _Alignas(8) uint8_t opaque_bytes[432]; } R4SdkTransportHttpResponse;
#define R4SdkTransportHttpResponse_TYPE 70u
/* ?http.ContentRange; native size 40, alignment 8. */
typedef struct R4SdkTransportNativeValue71 { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkTransportNativeValue71;
#define R4SdkTransportNativeValue71_TYPE 71u
/* http.DecodeResult; native size 440, alignment 8. */
typedef struct R4SdkTransportHttpDecodeResult { _Alignas(8) uint8_t opaque_bytes[440]; } R4SdkTransportHttpDecodeResult;
#define R4SdkTransportHttpDecodeResult_TYPE 72u
/* @typeInfo(http.DecodeResult).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_http_DecodeResult____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_http_DecodeResult____union__tag_type__;
#define R4SdkTransportNative__typeInfo_http_DecodeResult____union__tag_type___TYPE 73u
/* http.ResponseDecoder; native size 512, alignment 8. */
typedef struct R4SdkTransportHttpResponseDecoder { _Alignas(8) uint8_t opaque_bytes[512]; } R4SdkTransportHttpResponseDecoder;
#define R4SdkTransportHttpResponseDecoder_TYPE 74u
/* ?http.ParsedHead; native size 432, alignment 8. */
typedef struct R4SdkTransportNativeValue75 { _Alignas(8) uint8_t opaque_bytes[432]; } R4SdkTransportNativeValue75;
#define R4SdkTransportNativeValue75_TYPE 75u
/* http.ParsedHead; native size 424, alignment 8. */
typedef struct R4SdkTransportHttpParsedHead { _Alignas(8) uint8_t opaque_bytes[424]; } R4SdkTransportHttpParsedHead;
#define R4SdkTransportHttpParsedHead_TYPE 76u
/* http.ResponseDecoder__enum_; native size 1, alignment 1. */
typedef struct R4SdkTransportNativeValue77 { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNativeValue77;
#define R4SdkTransportNativeValue77_TYPE 77u
/* ?http.ResponseError; native size 2, alignment 1. */
typedef struct R4SdkTransportNativeValue78 { _Alignas(1) uint8_t opaque_bytes[2]; } R4SdkTransportNativeValue78;
#define R4SdkTransportNativeValue78_TYPE 78u
/* http.StreamResponse; native size 88, alignment 8. */
typedef struct R4SdkTransportHttpStreamResponse { _Alignas(8) uint8_t opaque_bytes[88]; } R4SdkTransportHttpStreamResponse;
#define R4SdkTransportHttpStreamResponse_TYPE 79u
/* http.StreamChunk; native size 24, alignment 8. */
typedef struct R4SdkTransportHttpStreamChunk { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportHttpStreamChunk;
#define R4SdkTransportHttpStreamChunk_TYPE 80u
/* http.StreamDecodeResult; native size 32, alignment 8. */
typedef struct R4SdkTransportHttpStreamDecodeResult { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkTransportHttpStreamDecodeResult;
#define R4SdkTransportHttpStreamDecodeResult_TYPE 81u
/* @typeInfo(http.StreamDecodeResult).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type__;
#define R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type___TYPE 82u
/* http.StreamDecoder; native size 472, alignment 8. */
typedef struct R4SdkTransportHttpStreamDecoder { _Alignas(8) uint8_t opaque_bytes[472]; } R4SdkTransportHttpStreamDecoder;
#define R4SdkTransportHttpStreamDecoder_TYPE 83u
/* http.RedirectResult; native size 24, alignment 8. */
typedef struct R4SdkTransportHttpRedirectResult { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportHttpRedirectResult;
#define R4SdkTransportHttpRedirectResult_TYPE 84u
/* @typeInfo(http.RedirectResult).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_http_RedirectResult____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_http_RedirectResult____union__tag_type__;
#define R4SdkTransportNative__typeInfo_http_RedirectResult____union__tag_type___TYPE 85u
/* web_response_cache.Limits; native size 16, alignment 8. */
typedef struct R4SdkTransportCacheLimits { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportCacheLimits;
#define R4SdkTransportCacheLimits_TYPE 103u
/* web_response_cache.Clock; native size 24, alignment 8. */
typedef struct R4SdkTransportCacheClock { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportCacheClock;
#define R4SdkTransportCacheClock_TYPE 104u
/* web_response_cache.Key; native size 48, alignment 8. */
typedef struct R4SdkTransportCacheKey { _Alignas(8) uint8_t opaque_bytes[48]; } R4SdkTransportCacheKey;
#define R4SdkTransportCacheKey_TYPE 105u
/* web_response_cache.Handle; native size 16, alignment 8. */
typedef struct R4SdkTransportCacheHandle { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportCacheHandle;
#define R4SdkTransportCacheHandle_TYPE 106u
/* web_response_cache.Action; native size 1, alignment 1. */
typedef struct R4SdkTransportCacheAction { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportCacheAction;
#define R4SdkTransportCacheAction_TYPE 107u
/* web_response_cache.Lookup; native size 32, alignment 8. */
typedef struct R4SdkTransportCacheLookup { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkTransportCacheLookup;
#define R4SdkTransportCacheLookup_TYPE 108u
/* ?web_response_cache.Handle; native size 24, alignment 8. */
typedef struct R4SdkTransportNativeValue109 { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportNativeValue109;
#define R4SdkTransportNativeValue109_TYPE 109u
/* web_response_cache.View; native size 48, alignment 8. */
typedef struct R4SdkTransportCacheView { _Alignas(8) uint8_t opaque_bytes[48]; } R4SdkTransportCacheView;
#define R4SdkTransportCacheView_TYPE 110u
/* web_response_cache.Stats; native size 40, alignment 8. */
typedef struct R4SdkTransportCacheStats { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkTransportCacheStats;
#define R4SdkTransportCacheStats_TYPE 111u
/* web_response_cache.Cache; native size 992, alignment 8. */
typedef struct R4SdkTransportCacheCache { _Alignas(8) uint8_t opaque_bytes[992]; } R4SdkTransportCacheCache;
#define R4SdkTransportCacheCache_TYPE 112u
/* [8]web_response_cache.Entry; native size 896, alignment 8. */
typedef struct R4SdkTransportNativeValue114 { _Alignas(8) uint8_t opaque_bytes[896]; } R4SdkTransportNativeValue114;
#define R4SdkTransportNativeValue114_TYPE 114u
/* web_response_cache.Entry; native size 112, alignment 8. */
typedef struct R4SdkTransportCacheEntry { _Alignas(8) uint8_t opaque_bytes[112]; } R4SdkTransportCacheEntry;
#define R4SdkTransportCacheEntry_TYPE 115u
/* [5]usize; native size 40, alignment 8. */
typedef struct R4SdkTransportNativeValue116 { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkTransportNativeValue116;
#define R4SdkTransportNativeValue116_TYPE 116u
/* web_response_cache.Header; native size 32, alignment 8. */
typedef struct R4SdkTransportCacheHeader { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkTransportCacheHeader;
#define R4SdkTransportCacheHeader_TYPE 117u
/* web_response_cache.HeaderIterator; native size 40, alignment 8. */
typedef struct R4SdkTransportCacheHeaderIterator { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkTransportCacheHeaderIterator;
#define R4SdkTransportCacheHeaderIterator_TYPE 118u
/* mem.SplitIterator(u8,.scalar); native size 40, alignment 8. */
typedef struct R4SdkTransportNative_mem_SplitIterator_u8__scalar_ { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkTransportNative_mem_SplitIterator_u8__scalar_;
#define R4SdkTransportNative_mem_SplitIterator_u8__scalar__TYPE 119u
/* web_response_cache.Directives; native size 24, alignment 8. */
typedef struct R4SdkTransportCacheDirectives { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportCacheDirectives;
#define R4SdkTransportCacheDirectives_TYPE 121u
/* app_web_jobs.Job; native size 72096, alignment 8. */
typedef struct R4SdkTransportJobsJob { _Alignas(8) uint8_t opaque_bytes[72096]; } R4SdkTransportJobsJob;
#define R4SdkTransportJobsJob_TYPE 122u
/* ?app_resources.JoinHandle; native size 56, alignment 8. */
typedef struct R4SdkTransportNativeValue123 { _Alignas(8) uint8_t opaque_bytes[56]; } R4SdkTransportNativeValue123;
#define R4SdkTransportNativeValue123_TYPE 123u
/* app_resources.JoinHandle; native size 48, alignment 8. */
typedef struct R4SdkTransportNative_app_resources_JoinHandle { _Alignas(8) uint8_t opaque_bytes[48]; } R4SdkTransportNative_app_resources_JoinHandle;
#define R4SdkTransportNative_app_resources_JoinHandle_TYPE 124u
/* ?*const fn (*anyopaque) void; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue126 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue126;
#define R4SdkTransportNativeValue126_TYPE 126u
/* web_runtime_jobs.Owner; native size 16, alignment 8. */
typedef struct R4SdkTransportRuntimeJobsOwner { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportRuntimeJobsOwner;
#define R4SdkTransportRuntimeJobsOwner_TYPE 127u
/* web_runtime_jobs.RequestJob; native size 74344, alignment 8. */
typedef struct R4SdkTransportRuntimeJobsRequestJob { _Alignas(8) uint8_t opaque_bytes[74344]; } R4SdkTransportRuntimeJobsRequestJob;
#define R4SdkTransportRuntimeJobsRequestJob_TYPE 128u
/* [277]u8; native size 277, alignment 1. */
typedef struct R4SdkTransportNativeValue131 { _Alignas(1) uint8_t opaque_bytes[277]; } R4SdkTransportNativeValue131;
#define R4SdkTransportNativeValue131_TYPE 131u
/* ?web_resources.Kind; native size 2, alignment 1. */
typedef struct R4SdkTransportNativeValue140 { _Alignas(1) uint8_t opaque_bytes[2]; } R4SdkTransportNativeValue140;
#define R4SdkTransportNativeValue140_TYPE 140u
/* web_documents.Context; native size 3330648, alignment 8. */
typedef struct R4SdkTransportDocumentsContext { _Alignas(8) uint8_t opaque_bytes[3330648]; } R4SdkTransportDocumentsContext;
#define R4SdkTransportDocumentsContext_TYPE 141u
/* web_documents.Set; native size 232, alignment 8. */
typedef struct R4SdkTransportDocumentsSet { _Alignas(8) uint8_t opaque_bytes[232]; } R4SdkTransportDocumentsSet;
#define R4SdkTransportDocumentsSet_TYPE 144u
/* [4]?*web_documents.Context; native size 32, alignment 8. */
typedef struct R4SdkTransportNativeValue147 { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkTransportNativeValue147;
#define R4SdkTransportNativeValue147_TYPE 147u
/* ?*web_documents.Context; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue148 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue148;
#define R4SdkTransportNativeValue148_TYPE 148u
/* *web_documents.Context; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue149 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue149;
#define R4SdkTransportNativeValue149_TYPE 149u
/* web_fetch.Headers; native size 70664, alignment 8. */
typedef struct R4SdkTransportFetchHeaders { _Alignas(8) uint8_t opaque_bytes[70664]; } R4SdkTransportFetchHeaders;
#define R4SdkTransportFetchHeaders_TYPE 153u
/* [64]web_fetch.Header; native size 70656, alignment 8. */
typedef struct R4SdkTransportNativeValue154 { _Alignas(8) uint8_t opaque_bytes[70656]; } R4SdkTransportNativeValue154;
#define R4SdkTransportNativeValue154_TYPE 154u
/* web_fetch.Header; native size 1104, alignment 8. */
typedef struct R4SdkTransportFetchHeader { _Alignas(8) uint8_t opaque_bytes[1104]; } R4SdkTransportFetchHeader;
#define R4SdkTransportFetchHeader_TYPE 155u
/* transport_helper_adapters.Context; native size 80, alignment 8. */
typedef struct R4SdkTransportContext { _Alignas(8) uint8_t opaque_bytes[80]; } R4SdkTransportContext;
#define R4SdkTransportContext_TYPE 158u
/* *transport_helper_adapters.Context; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue159 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue159;
#define R4SdkTransportNativeValue159_TYPE 159u
/* *const abi_generated.R4XStartContext; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue160 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue160;
#define R4SdkTransportNativeValue160_TYPE 160u
/* *app_web.WebTransport; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue162 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue162;
#define R4SdkTransportNativeValue162_TYPE 162u
/* *app_web_jobs.Job; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue163 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue163;
#define R4SdkTransportNativeValue163_TYPE 163u
/* *const transport_helper_adapters.Context; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue164 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue164;
#define R4SdkTransportNativeValue164_TYPE 164u
/* *web_runtime_jobs.RequestJob; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue165 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue165;
#define R4SdkTransportNativeValue165_TYPE 165u
/* error{MissingCallback}!web_runtime_jobs.Owner; native size 24, alignment 8. */
typedef struct R4SdkTransportNativeValue167 { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportNativeValue167;
#define R4SdkTransportNativeValue167_TYPE 167u
/* *app_web.FetchOptions; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue168 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue168;
#define R4SdkTransportNativeValue168_TYPE 168u
/* *app_web.DownloadOptions; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue169 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue169;
#define R4SdkTransportNativeValue169_TYPE 169u
/* error{MissingCallback}!app_web.DownloadSink; native size 24, alignment 8. */
typedef struct R4SdkTransportNativeValue170 { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportNativeValue170;
#define R4SdkTransportNativeValue170_TYPE 170u
/* *const app_network.Network; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue172 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue172;
#define R4SdkTransportNativeValue172_TYPE 172u
/* *const app_network.TcpSocket; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue173 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue173;
#define R4SdkTransportNativeValue173_TYPE 173u
/* *app_network.TcpSocket; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue174 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue174;
#define R4SdkTransportNativeValue174_TYPE 174u
/* app_network.SocketIo; native size 16, alignment 8. */
typedef struct R4SdkTransportNative_app_network_SocketIo { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportNative_app_network_SocketIo;
#define R4SdkTransportNative_app_network_SocketIo_TYPE 175u
/* @typeInfo(app_network.SocketIo).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type__;
#define R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type___TYPE 176u
/* app_network.Resolver; native size 16, alignment 8. */
typedef struct R4SdkTransportNative_app_network_Resolver { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportNative_app_network_Resolver;
#define R4SdkTransportNative_app_network_Resolver_TYPE 177u
/* app_network.TcpOpen; native size 40, alignment 8. */
typedef struct R4SdkTransportNative_app_network_TcpOpen { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkTransportNative_app_network_TcpOpen;
#define R4SdkTransportNative_app_network_TcpOpen_TYPE 178u
/* @typeInfo(app_network.TcpOpen).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type__;
#define R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type___TYPE 179u
/* app_network.ListenerOpen; native size 32, alignment 8. */
typedef struct R4SdkTransportNative_app_network_ListenerOpen { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkTransportNative_app_network_ListenerOpen;
#define R4SdkTransportNative_app_network_ListenerOpen_TYPE 180u
/* @typeInfo(app_network.ListenerOpen).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_app_network_ListenerOpen____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_app_network_ListenerOpen____union__tag_type__;
#define R4SdkTransportNative__typeInfo_app_network_ListenerOpen____union__tag_type___TYPE 181u
/* app_network.TcpListener; native size 24, alignment 8. */
typedef struct R4SdkTransportNative_app_network_TcpListener { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportNative_app_network_TcpListener;
#define R4SdkTransportNative_app_network_TcpListener_TYPE 182u
/* app_network.UdpOpen; native size 32, alignment 8. */
typedef struct R4SdkTransportNative_app_network_UdpOpen { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkTransportNative_app_network_UdpOpen;
#define R4SdkTransportNative_app_network_UdpOpen_TYPE 183u
/* @typeInfo(app_network.UdpOpen).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_app_network_UdpOpen____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_app_network_UdpOpen____union__tag_type__;
#define R4SdkTransportNative__typeInfo_app_network_UdpOpen____union__tag_type___TYPE 184u
/* app_network.UdpSocket; native size 24, alignment 8. */
typedef struct R4SdkTransportNative_app_network_UdpSocket { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportNative_app_network_UdpSocket;
#define R4SdkTransportNative_app_network_UdpSocket_TYPE 185u
/* *const app_web.FinalUrl; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue186 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue186;
#define R4SdkTransportNativeValue186_TYPE 186u
/* *const app_web.WebTransport; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue187 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue187;
#define R4SdkTransportNativeValue187_TYPE 187u
/* *http.ResponseDecoder; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue188 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue188;
#define R4SdkTransportNativeValue188_TYPE 188u
/* *const http.StreamDecoder; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue189 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue189;
#define R4SdkTransportNativeValue189_TYPE 189u
/* ?http.StreamResponse; native size 96, alignment 8. */
typedef struct R4SdkTransportNativeValue190 { _Alignas(8) uint8_t opaque_bytes[96]; } R4SdkTransportNativeValue190;
#define R4SdkTransportNativeValue190_TYPE 190u
/* *http.StreamDecoder; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue191 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue191;
#define R4SdkTransportNativeValue191_TYPE 191u
/* *web_response_cache.Cache; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue192 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue192;
#define R4SdkTransportNativeValue192_TYPE 192u
/* ?web_response_cache.View; native size 56, alignment 8. */
typedef struct R4SdkTransportNativeValue193 { _Alignas(8) uint8_t opaque_bytes[56]; } R4SdkTransportNativeValue193;
#define R4SdkTransportNativeValue193_TYPE 193u
/* @typeInfo(@typeInfo(@TypeOf(web_response_cache.Cache.store)).@"fn".return_type.?).error_union.error_set!?u64; native size 24, alignment 8. */
typedef struct R4SdkTransportNativeValue194 { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportNativeValue194;
#define R4SdkTransportNativeValue194_TYPE 194u
/* *web_response_cache.HeaderIterator; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue195 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue195;
#define R4SdkTransportNativeValue195_TYPE 195u
/* ?web_response_cache.Header; native size 40, alignment 8. */
typedef struct R4SdkTransportNativeValue196 { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkTransportNativeValue196;
#define R4SdkTransportNativeValue196_TYPE 196u
/* *mem.SplitIterator(u8,.scalar); native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue197 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue197;
#define R4SdkTransportNativeValue197_TYPE 197u
/* *const mem.SplitIterator(u8,.scalar); native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue198 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue198;
#define R4SdkTransportNativeValue198_TYPE 198u
/* *const app_resources.JoinHandle; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue199 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue199;
#define R4SdkTransportNativeValue199_TYPE 199u
/* *abi_generated.ThreadPlacementInfo; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue200 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue200;
#define R4SdkTransportNativeValue200_TYPE 200u
/* []u64; native size 16, alignment 8. */
typedef struct R4SdkTransportNativeValue202 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportNativeValue202;
#define R4SdkTransportNativeValue202_TYPE 202u
/* *const abi_generated.ThreadPlacementRequest; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue203 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue203;
#define R4SdkTransportNativeValue203_TYPE 203u
/* app_resources.ThreadInfo; native size 96, alignment 8. */
typedef struct R4SdkTransportNative_app_resources_ThreadInfo { _Alignas(8) uint8_t opaque_bytes[96]; } R4SdkTransportNative_app_resources_ThreadInfo;
#define R4SdkTransportNative_app_resources_ThreadInfo_TYPE 206u
/* @typeInfo(app_resources.ThreadInfo).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_app_resources_ThreadInfo____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_app_resources_ThreadInfo____union__tag_type__;
#define R4SdkTransportNative__typeInfo_app_resources_ThreadInfo____union__tag_type___TYPE 207u
/* *app_resources.JoinHandle; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue209 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue209;
#define R4SdkTransportNativeValue209_TYPE 209u
/* app_resources.JoinWait; native size 8, alignment 4. */
typedef struct R4SdkTransportNative_app_resources_JoinWait { _Alignas(4) uint8_t opaque_bytes[8]; } R4SdkTransportNative_app_resources_JoinWait;
#define R4SdkTransportNative_app_resources_JoinWait_TYPE 210u
/* @typeInfo(app_resources.JoinWait).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_app_resources_JoinWait____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_app_resources_JoinWait____union__tag_type__;
#define R4SdkTransportNative__typeInfo_app_resources_JoinWait____union__tag_type___TYPE 211u
/* @typeInfo(@typeInfo(@TypeOf(web_runtime_jobs.RequestJob.prepare)).@"fn".return_type.?).error_union.error_set!void; native size 2, alignment 2. */
typedef struct R4SdkTransportNativeValue214 { _Alignas(2) uint8_t opaque_bytes[2]; } R4SdkTransportNativeValue214;
#define R4SdkTransportNativeValue214_TYPE 214u
/* *web_documents.Set; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue215 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue215;
#define R4SdkTransportNativeValue215_TYPE 215u
/* error{AbortLimit,ActionLimit,AllocationFailed,AttributeLimit,BindingLimit,BytecodeFrameLimit,BytecodeInvalid,BytecodeLimit,BytecodeSegmentLimit,BytecodeStack,CallDepth,Cancelled,CellLimit,ConstAssignment,CookieLimit,CorsBlocked,CssDepthLimit,DepthLimit,DescriptorLimit,Empty,EntropyUnavailable,FaceLimit,FamilyListTooLong,GeneratorAllocation,GeneratorReturn,HeaderLimit,InputTooLarge,InvalidAssignment,InvalidCharacter,InvalidCookie,InvalidName,InvalidNode,InvalidPolicy,InvalidResource,InvalidSequence,InvalidSerialized,InvalidSurface,InvalidTransition,InvalidUrl,InvalidValue,ItemLimit,JobLimit,KeyTooLarge,ListenerLimit,MalformedPersistence,MissingHost,ModuleCycle,ModuleLimit,ModuleNotFound,MutationLimit,NameTooLong,NodeLimit,NotCallable,NotInitialized,NotObject,OriginLimit,OutputLimit,OutputTooSmall,PairLimit,PersistenceLimit,PolicyTooLarge,ProgramAllocation,PropertyLimit,RangeError,RequestLimit,RequestNotFound,RequestState,ResourceLimit,ResponseTooLarge,RootLimit,ScriptAllocation,ScriptLimit,ScriptThrown,SecurityBlocked,SerializedTooLong,SizeLimit,SourceLimit,SourceSectionLimit,SourceTooLarge,StaleGeneration,StaleParent,StepLimit,StorageLimit,StringLimit,StylesheetTooLarge,SubdocumentLimit,SubdocumentNotFound,SurfaceLimit,SyntaxError,TextRunTooLong,TimerLimit,TokenLimit,TooLong,TypeError,UncaughtException,UnexpectedToken,UnicodeRangeLimit,UnknownEncoding,UnknownIdentifier,UnsupportedAlgorithm,UnsupportedEncoding,UnsupportedMediaType,UnsupportedOrigin,UnsupportedRelativeBase,UnsupportedScheme,ValueTooLarge,ValueTooLong,ViewLimit,XhrLimit}!*web_documents.Context; native size 16, alignment 8. */
typedef struct R4SdkTransportNativeValue218 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportNativeValue218;
#define R4SdkTransportNativeValue218_TYPE 218u
/* *const web_documents.Set; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue219 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue219;
#define R4SdkTransportNativeValue219_TYPE 219u
/* error{AbortLimit,ActionLimit,AllocationFailed,AttributeLimit,BindingLimit,BytecodeFrameLimit,BytecodeInvalid,BytecodeLimit,BytecodeSegmentLimit,BytecodeStack,CallDepth,Cancelled,CellLimit,ConstAssignment,CookieLimit,CorsBlocked,CssDepthLimit,DepthLimit,DescriptorLimit,Empty,EntropyUnavailable,FaceLimit,FamilyListTooLong,GeneratorAllocation,GeneratorReturn,HeaderLimit,InputTooLarge,InvalidAssignment,InvalidCharacter,InvalidCookie,InvalidName,InvalidNode,InvalidPolicy,InvalidResource,InvalidSequence,InvalidSerialized,InvalidSurface,InvalidTransition,InvalidUrl,InvalidValue,ItemLimit,JobLimit,KeyTooLarge,ListenerLimit,MalformedPersistence,MissingHost,ModuleCycle,ModuleLimit,ModuleNotFound,MutationLimit,NameTooLong,NodeLimit,NotCallable,NotInitialized,NotObject,OriginLimit,OutputLimit,OutputTooSmall,PairLimit,PersistenceLimit,PolicyTooLarge,ProgramAllocation,PropertyLimit,RangeError,RequestLimit,RequestNotFound,RequestState,ResourceLimit,ResponseTooLarge,RootLimit,ScriptAllocation,ScriptLimit,ScriptThrown,SecurityBlocked,SerializedTooLong,SizeLimit,SourceLimit,SourceSectionLimit,SourceTooLarge,StaleGeneration,StaleParent,StepLimit,StorageLimit,StringLimit,StylesheetTooLarge,SubdocumentLimit,SubdocumentNotFound,SurfaceLimit,SyntaxError,TextRunTooLong,TimerLimit,TokenLimit,TooLong,TypeError,UncaughtException,UnexpectedToken,UnicodeRangeLimit,UnknownEncoding,UnknownIdentifier,UnsupportedAlgorithm,UnsupportedEncoding,UnsupportedMediaType,UnsupportedOrigin,UnsupportedRelativeBase,UnsupportedScheme,ValueTooLarge,ValueTooLong,ViewLimit,XhrLimit}!usize; native size 16, alignment 8. */
typedef struct R4SdkTransportNativeValue221 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportNativeValue221;
#define R4SdkTransportNativeValue221_TYPE 221u
/* error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}!web_fetch.Headers; native size 70672, alignment 8. */
typedef struct R4SdkTransportNativeValue222 { _Alignas(8) uint8_t opaque_bytes[70672]; } R4SdkTransportNativeValue222;
#define R4SdkTransportNativeValue222_TYPE 222u
/* *web_fetch.Headers; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue223 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue223;
#define R4SdkTransportNativeValue223_TYPE 223u
/* error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}!void; native size 2, alignment 2. */
typedef struct R4SdkTransportNativeValue224 { _Alignas(2) uint8_t opaque_bytes[2]; } R4SdkTransportNativeValue224;
#define R4SdkTransportNativeValue224_TYPE 224u
/* *const web_fetch.Headers; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue225 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue225;
#define R4SdkTransportNativeValue225_TYPE 225u
/* error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}!bool; native size 4, alignment 2. */
typedef struct R4SdkTransportNativeValue226 { _Alignas(2) uint8_t opaque_bytes[4]; } R4SdkTransportNativeValue226;
#define R4SdkTransportNativeValue226_TYPE 226u
/* error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}!?[]const u8; native size 24, alignment 8. */
typedef struct R4SdkTransportNativeValue227 { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportNativeValue227;
#define R4SdkTransportNativeValue227_TYPE 227u
/* *[64][]const u8; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue228 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue228;
#define R4SdkTransportNativeValue228_TYPE 228u
/* [64][]const u8; native size 1024, alignment 8. */
typedef struct R4SdkTransportNativeValue229 { _Alignas(8) uint8_t opaque_bytes[1024]; } R4SdkTransportNativeValue229;
#define R4SdkTransportNativeValue229_TYPE 229u
/* error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}![]const u8; native size 24, alignment 8. */
typedef struct R4SdkTransportNativeValue230 { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportNativeValue230;
#define R4SdkTransportNativeValue230_TYPE 230u
/* *[64]usize; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue231 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue231;
#define R4SdkTransportNativeValue231_TYPE 231u
/* [64]usize; native size 512, alignment 8. */
typedef struct R4SdkTransportNativeValue232 { _Alignas(8) uint8_t opaque_bytes[512]; } R4SdkTransportNativeValue232;
#define R4SdkTransportNativeValue232_TYPE 232u
/* []const usize; native size 16, alignment 8. */
typedef struct R4SdkTransportNativeValue233 { _Alignas(8) uint8_t opaque_bytes[16]; } R4SdkTransportNativeValue233;
#define R4SdkTransportNativeValue233_TYPE 233u
/* *app_network.Resolver; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue234 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue234;
#define R4SdkTransportNativeValue234_TYPE 234u
/* ?app_network.Ipv4Address; native size 5, alignment 1. */
typedef struct R4SdkTransportNativeValue235 { _Alignas(1) uint8_t opaque_bytes[5]; } R4SdkTransportNativeValue235;
#define R4SdkTransportNativeValue235_TYPE 235u
/* app_network.ResolveResult; native size 8, alignment 4. */
typedef struct R4SdkTransportNative_app_network_ResolveResult { _Alignas(4) uint8_t opaque_bytes[8]; } R4SdkTransportNative_app_network_ResolveResult;
#define R4SdkTransportNative_app_network_ResolveResult_TYPE 236u
/* @typeInfo(app_network.ResolveResult).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type__;
#define R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type___TYPE 237u
/* *const app_network.TcpListener; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue238 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue238;
#define R4SdkTransportNativeValue238_TYPE 238u
/* *app_network.TcpListener; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue239 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue239;
#define R4SdkTransportNativeValue239_TYPE 239u
/* app_network.TcpAccept; native size 40, alignment 8. */
typedef struct R4SdkTransportNative_app_network_TcpAccept { _Alignas(8) uint8_t opaque_bytes[40]; } R4SdkTransportNative_app_network_TcpAccept;
#define R4SdkTransportNative_app_network_TcpAccept_TYPE 240u
/* @typeInfo(app_network.TcpAccept).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type__;
#define R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type___TYPE 241u
/* *const app_network.UdpSocket; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue242 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue242;
#define R4SdkTransportNativeValue242_TYPE 242u
/* *app_network.UdpSocket; native size 8, alignment 8. */
typedef struct R4SdkTransportNativeValue243 { _Alignas(8) uint8_t opaque_bytes[8]; } R4SdkTransportNativeValue243;
#define R4SdkTransportNativeValue243_TYPE 243u
/* app_network.UdpReceive; native size 32, alignment 8. */
typedef struct R4SdkTransportNative_app_network_UdpReceive { _Alignas(8) uint8_t opaque_bytes[32]; } R4SdkTransportNative_app_network_UdpReceive;
#define R4SdkTransportNative_app_network_UdpReceive_TYPE 244u
/* @typeInfo(app_network.UdpReceive).@"union".tag_type.?; native size 1, alignment 1. */
typedef struct R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type__ { _Alignas(1) uint8_t opaque_bytes[1]; } R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type__;
#define R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type___TYPE 245u
/* app_network.Datagram; native size 24, alignment 8. */
typedef struct R4SdkTransportNative_app_network_Datagram { _Alignas(8) uint8_t opaque_bytes[24]; } R4SdkTransportNative_app_network_Datagram;
#define R4SdkTransportNative_app_network_Datagram_TYPE 246u
#define R4SdkTransport_ABI_FINGERPRINT UINT64_C(3079459800984226674)
int32_t R4SdkTransportVerifyAbi(uint64_t);
#define R4SdkTransport_tls_workspace_bytes (18432)
#define R4SdkTransport_tls_scratch_bytes (55296)
#define R4SdkTransportHttp_max_header_bytes (16384)
#define R4SdkTransportHttp_max_header_count (64)
#define R4SdkTransportHttp_max_set_cookie_headers (16)
#define R4SdkTransportHttp_max_redirects (20)
#define R4SdkTransportSecurity_max_origin_host_bytes (253)
#define R4SdkTransportSecurity_max_policy_bytes (1024)
#define R4SdkTransportSecurity_max_cookies (32)
#define R4SdkTransportSecurity_max_cookie_name_bytes (64)
#define R4SdkTransportSecurity_max_cookie_value_bytes (4096)
#define R4SdkTransportSecurity_max_cookie_path_bytes (256)
#define R4SdkTransportSecurity_max_storage_origins (8)
#define R4SdkTransportSecurity_max_storage_entries (24)
#define R4SdkTransportSecurity_max_storage_key_bytes (96)
#define R4SdkTransportSecurity_max_storage_value_bytes (512)
#define R4SdkTransportSecurity_max_persistence_bytes (196608)
#define R4SdkTransportCache_max_entries (8)
#define R4SdkTransportCache_max_key_bytes (16384)
#define R4SdkTransportCache_max_header_bytes (8192)
#define R4SdkTransportJobs_capacity (2)
#define R4SdkTransportResources_max_resources (64)
#define R4SdkTransportResources_no_request (0)
#define R4SdkTransportDocuments_max_subdocuments (4)
#define R4SdkTransportDocuments_max_document_owners (5)
#define R4SdkTransportFetch_max_headers (64)
#define R4SdkTransportFetch_max_name_bytes (64)
#define R4SdkTransportFetch_max_value_bytes (1024)
#define R4SdkTransportFetch_max_serialized_bytes (16384)
#include "r4os/web_helpers.h"
#define R4SdkTransportError_invalid_url 0u
#define R4SdkTransportError_unsupported_scheme 1u
#define R4SdkTransportError_cancelled 2u
#define R4SdkTransportError_dns_timeout 3u
#define R4SdkTransportError_dns_not_found 4u
#define R4SdkTransportError_dns_failed 5u
#define R4SdkTransportError_connect_timeout 6u
#define R4SdkTransportError_connect_failed 7u
#define R4SdkTransportError_write_failed 8u
#define R4SdkTransportError_read_failed 9u
#define R4SdkTransportError_response_too_large 10u
#define R4SdkTransportError_malformed_response 11u
#define R4SdkTransportError_cors_preflight_failed 12u
#define R4SdkTransportError_cors_rejected 13u
#define R4SdkTransportError_policy_rejected 14u
#define R4SdkTransportError_redirect_disallowed 15u
#define R4SdkTransportError_redirect_without_location 16u
#define R4SdkTransportError_redirect_limit 17u
#define R4SdkTransportError_tls_unavailable 18u
#define R4SdkTransportError_tls_entropy_required 19u
#define R4SdkTransportError_tls_handshake_failed 20u
#define R4SdkTransportError_tls_alert_handshake_failure 21u
#define R4SdkTransportError_tls_alert_illegal_parameter 22u
#define R4SdkTransportError_tls_alert_decode_error 23u
#define R4SdkTransportError_tls_alert_protocol_version 24u
#define R4SdkTransportError_tls_alert_insufficient_security 25u
#define R4SdkTransportError_tls_alert_unexpected_message 26u
#define R4SdkTransportError_tls_server_flight_malformed 27u
#define R4SdkTransportError_tls_server_record_header_invalid 28u
#define R4SdkTransportError_tls_server_message_framing_invalid 29u
#define R4SdkTransportError_tls_server_hello_invalid 30u
#define R4SdkTransportError_tls_server_certificate_list_invalid 31u
#define R4SdkTransportError_tls_server_key_exchange_invalid 32u
#define R4SdkTransportError_tls_server_hello_done_invalid 33u
#define R4SdkTransportError_tls_server_message_unsupported 34u
#define R4SdkTransportError_tls_server_flight_incomplete 35u
#define R4SdkTransportError_tls_client_flight_buffer_invalid 36u
#define R4SdkTransportError_tls_client_flight_header_invalid 37u
#define R4SdkTransportError_tls_client_flight_lengths_invalid 38u
#define R4SdkTransportError_tls_client_state_length_mismatch 39u
#define R4SdkTransportError_tls_server_flight_length_mismatch 40u
#define R4SdkTransportError_tls_client_flight_total_length_mismatch 41u
#define R4SdkTransportError_tls_client_state_length_zero 42u
#define R4SdkTransportError_tls_server_flight_length_zero 43u
#define R4SdkTransportError_tls_client_flight_declared_too_large 44u
#define R4SdkTransportError_tls_client_flight_has_trailing_input 45u
#define R4SdkTransportError_tls_client_state_invalid 46u
#define R4SdkTransportError_tls_certificate_rejected 47u
#define R4SdkTransportError_tls_certificate_material_unavailable 48u
#define R4SdkTransportError_tls_certificate_clock_invalid 49u
#define R4SdkTransportError_tls_certificate_parse_failed 50u
#define R4SdkTransportError_tls_certificate_hostname_rejected 51u
#define R4SdkTransportError_tls_certificate_validity_rejected 52u
#define R4SdkTransportError_tls_certificate_chain_rejected 53u
#define R4SdkTransportError_tls_certificate_root_rejected 54u
#define R4SdkTransportError_tls_server_signature_rejected 55u
#define R4SdkTransportError_tls_server_flight_unsupported 56u
#define R4SdkTransportError_tls_server_final_flight_invalid 57u
#define R4SdkTransportError_tls_server_finished_rejected 58u
#define R4SdkTransportError_tls_finished_state_invalid 59u
#define R4SdkTransportError_tls_record_failed 60u
#define R4SdkTransportError_scratch_too_small 61u
#define R4SdkTransportError_request_too_large 62u
#define R4SdkTransportError_read_timeout 63u
#define R4SdkTransportError_read_reset 64u
#define R4SdkTransportError_read_peer_closed 65u
#define R4SdkTransportError_tls_close_notify 66u
#define R4SdkTransportError_tls_alert_received 67u
#define R4SdkTransportError_header_buffer_too_small 68u
#define R4SdkTransportError_io_buffer_too_small 69u
#define R4SdkTransportError_sink_failed 70u
#define R4SdkTransportError_content_length_required 71u
#define R4SdkTransportError_content_range_required 72u
#define R4SdkTransportError_content_range_mismatch 73u
#define R4SdkTransportError_range_header_conflict 74u
#define R4SdkTransportError_unsupported_method 75u
#define R4SdkTransportRedirectMode_follow 0u
#define R4SdkTransportRedirectMode_error_mode 1u
#define R4SdkTransportRedirectMode_manual 2u
#define R4SdkTransportNative__typeInfo_app_web_FetchResult____union__tag_type___response 0u
#define R4SdkTransportNative__typeInfo_app_web_FetchResult____union__tag_type___failure 1u
#define R4SdkTransportNative__typeInfo_app_web_DownloadResult____union__tag_type___response 0u
#define R4SdkTransportNative__typeInfo_app_web_DownloadResult____union__tag_type___range_not_satisfiable 1u
#define R4SdkTransportNative__typeInfo_app_web_DownloadResult____union__tag_type___failure 2u
#define R4SdkTransportHttpScheme_http 0u
#define R4SdkTransportHttpScheme_https 1u
#define R4SdkTransportHttpUrlError_empty 0u
#define R4SdkTransportHttpUrlError_unsupported_scheme 1u
#define R4SdkTransportHttpUrlError_missing_host 2u
#define R4SdkTransportHttpUrlError_userinfo_forbidden 3u
#define R4SdkTransportHttpUrlError_ipv6_not_supported 4u
#define R4SdkTransportHttpUrlError_bad_port 5u
#define R4SdkTransportHttpUrlError_fragment_forbidden 6u
#define R4SdkTransportHttpUrlError_output_too_small 7u
#define R4SdkTransportHttpUrlError_invalid_target 8u
#define R4SdkTransportNative__typeInfo_http_UrlResult____union__tag_type___value 0u
#define R4SdkTransportNative__typeInfo_http_UrlResult____union__tag_type___failure 1u
#define R4SdkTransportNative__typeInfo_http_BuildResult____union__tag_type___bytes 0u
#define R4SdkTransportNative__typeInfo_http_BuildResult____union__tag_type___invalid_url 1u
#define R4SdkTransportNative__typeInfo_http_BuildResult____union__tag_type___output_too_small 2u
#define R4SdkTransportHttpTransfer_none 0u
#define R4SdkTransportHttpTransfer_content_length 1u
#define R4SdkTransportHttpTransfer_chunked 2u
#define R4SdkTransportHttpTransfer_close_delimited 3u
#define R4SdkTransportHttpResponseError_malformed_status 0u
#define R4SdkTransportHttpResponseError_unsupported_version 1u
#define R4SdkTransportHttpResponseError_header_too_large 2u
#define R4SdkTransportHttpResponseError_too_many_headers 3u
#define R4SdkTransportHttpResponseError_malformed_header 4u
#define R4SdkTransportHttpResponseError_invalid_content_length 5u
#define R4SdkTransportHttpResponseError_conflicting_length 6u
#define R4SdkTransportHttpResponseError_unsupported_transfer_encoding 7u
#define R4SdkTransportHttpResponseError_malformed_chunk 8u
#define R4SdkTransportHttpResponseError_body_too_large 9u
#define R4SdkTransportHttpResponseError_redirect_without_location 10u
#define R4SdkTransportHttpResponseError_redirect_loop 11u
#define R4SdkTransportHttpResponseError_transport_closed_early 12u
#define R4SdkTransportHttpResponseError_content_length_required 13u
#define R4SdkTransportHttpResponseError_unexpected_body 14u
#define R4SdkTransportNative__typeInfo_http_DecodeResult____union__tag_type___complete 0u
#define R4SdkTransportNative__typeInfo_http_DecodeResult____union__tag_type___need_more 1u
#define R4SdkTransportNative__typeInfo_http_DecodeResult____union__tag_type___aborted 2u
#define R4SdkTransportNative__typeInfo_http_DecodeResult____union__tag_type___failure 3u
#define R4SdkTransportNativeValue77_size 0u
#define R4SdkTransportNativeValue77_data 1u
#define R4SdkTransportNativeValue77_data_crlf 2u
#define R4SdkTransportNativeValue77_trailers 3u
#define R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type___chunk 0u
#define R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type___complete 1u
#define R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type___need_more 2u
#define R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type___aborted 3u
#define R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type___failure 4u
#define R4SdkTransportNative__typeInfo_http_RedirectResult____union__tag_type___url 0u
#define R4SdkTransportNative__typeInfo_http_RedirectResult____union__tag_type___invalid 1u
#define R4SdkTransportNative__typeInfo_http_RedirectResult____union__tag_type___output_too_small 2u
#define R4SdkTransportCacheAction_miss 0u
#define R4SdkTransportCacheAction_hit 1u
#define R4SdkTransportCacheAction_revalidate 2u
#define R4SdkTransportCacheAction_only_miss 3u
#define R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type___bytes 0u
#define R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type___would_block 1u
#define R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type___timed_out 2u
#define R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type___reset 3u
#define R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type___peer_closed 4u
#define R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type___closed 5u
#define R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type___failure 6u
#define R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type___socket 0u
#define R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type___would_block 1u
#define R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type___timed_out 2u
#define R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type___reset 3u
#define R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type___peer_closed 4u
#define R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type___no_service 5u
#define R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type___failure 6u
#define R4SdkTransportNative__typeInfo_app_network_ListenerOpen____union__tag_type___listener 0u
#define R4SdkTransportNative__typeInfo_app_network_ListenerOpen____union__tag_type___timed_out 1u
#define R4SdkTransportNative__typeInfo_app_network_ListenerOpen____union__tag_type___no_service 2u
#define R4SdkTransportNative__typeInfo_app_network_ListenerOpen____union__tag_type___failure 3u
#define R4SdkTransportNative__typeInfo_app_network_UdpOpen____union__tag_type___socket 0u
#define R4SdkTransportNative__typeInfo_app_network_UdpOpen____union__tag_type___timed_out 1u
#define R4SdkTransportNative__typeInfo_app_network_UdpOpen____union__tag_type___no_service 2u
#define R4SdkTransportNative__typeInfo_app_network_UdpOpen____union__tag_type___failure 3u
#define R4SdkTransportNative__typeInfo_app_resources_ThreadInfo____union__tag_type___value 0u
#define R4SdkTransportNative__typeInfo_app_resources_ThreadInfo____union__tag_type___failure 1u
#define R4SdkTransportNative__typeInfo_app_resources_JoinWait____union__tag_type___exited 0u
#define R4SdkTransportNative__typeInfo_app_resources_JoinWait____union__tag_type___timed_out 1u
#define R4SdkTransportNative__typeInfo_app_resources_JoinWait____union__tag_type___failure 2u
#define R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type___address 0u
#define R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type___timed_out 1u
#define R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type___not_found 2u
#define R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type___no_service 3u
#define R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type___failure 4u
#define R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type___socket 0u
#define R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type___would_block 1u
#define R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type___timed_out 2u
#define R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type___reset 3u
#define R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type___closed 4u
#define R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type___no_service 5u
#define R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type___failure 6u
#define R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type___datagram 0u
#define R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type___would_block 1u
#define R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type___timed_out 2u
#define R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type___reset 3u
#define R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type___peer_closed 4u
#define R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type___closed 5u
#define R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type___no_service 6u
#define R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type___failure 7u
/* app_web.fillSecureEntropy -> bool */
static inline R4SdkTransportSlot R4SdkTransport_fillSecureEntropy(uint32_t reserved, R4SdkWebNativeValue151 * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,0u,a,1u,0);
}
/* http.parseUrl -> http.UrlResult */
static inline R4SdkTransportSlot R4SdkTransportHttp_parseUrl(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4SdkTransportHttpUrlResult *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,1u,a,1u,output);
}
/* http.buildGetRequest -> http.BuildResult */
static inline R4SdkTransportSlot R4SdkTransportHttp_buildGetRequest(uint32_t reserved, uint8_t * p0, uintptr_t n0, const R4SdkTransportHttpParsedUrl * p1, const R4SdkTransportHttpRequestOptions * p2, R4SdkTransportHttpBuildResult *output) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,2u,a,3u,output);
}
/* http.buildRequest -> http.BuildResult */
static inline R4SdkTransportSlot R4SdkTransportHttp_buildRequest(uint32_t reserved, uint8_t * p0, uintptr_t n0, uint32_t p1, const R4SdkTransportHttpParsedUrl * p2, const R4SdkTransportHttpRequestOptions * p3, R4SdkTransportHttpBuildResult *output) {
 (void)reserved; R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,3u,a,4u,output);
}
/* http.decodeResponse -> http.DecodeResult */
static inline R4SdkTransportSlot R4SdkTransportHttp_decodeResponse(uint32_t reserved, const uint8_t * p0, uintptr_t n0, uint8_t * p1, uintptr_t n1, uint8_t p2, uint8_t p3, R4SdkTransportHttpDecodeResult *output) {
 (void)reserved; R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,4u,a,4u,output);
}
/* http.responseAllowsReuse -> bool */
static inline R4SdkTransportSlot R4SdkTransportHttp_responseAllowsReuse(uint32_t reserved, const uint8_t * p0, uintptr_t n0, const R4SdkTransportHttpResponse * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,5u,a,2u,0);
}
/* http.serializedHeadersContain -> bool */
static inline R4SdkTransportSlot R4SdkTransportHttp_serializedHeadersContain(uint32_t reserved, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,6u,a,2u,0);
}
/* http.resolveRedirect -> http.RedirectResult */
static inline R4SdkTransportSlot R4SdkTransportHttp_resolveRedirect(uint32_t reserved, const R4SdkTransportHttpParsedUrl * p0, const uint8_t * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2, R4SdkTransportHttpRedirectResult *output) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,7u,a,3u,output);
}
/* web_response_cache.header -> ?[]const u8 */
static inline R4SdkTransportSlot R4SdkTransportCache_header(uint32_t reserved, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,8u,a,2u,0);
}
/* web_response_cache.directives -> web_response_cache.Directives */
static inline R4SdkTransportSlot R4SdkTransportCache_directives(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4SdkTransportCacheDirectives *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,9u,a,1u,output);
}
/* web_response_cache.initialAgeSeconds -> u64 */
static inline R4SdkTransportSlot R4SdkTransportCache_initialAgeSeconds(uint32_t reserved, const uint8_t * p0, uintptr_t n0, const R4SdkTransportCacheClock * p1, uint64_t p2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,10u,a,3u,0);
}
/* web_response_cache.parseDate -> ?u64 */
static inline R4SdkTransportSlot R4SdkTransportCache_parseDate(uint32_t reserved, const uint8_t * p0, uintptr_t n0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,11u,a,1u,0);
}
/* web_resources.classifyScript -> web_resources.ScriptMode */
static inline R4SdkTransportSlot R4SdkTransportResources_classifyScript(uint32_t reserved, const R4SdkWebHtmlDocument * p0, uint16_t p1, uint8_t p2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,12u,a,3u,0);
}
/* web_resources.resourceKind -> ?web_resources.Kind */
static inline R4SdkTransportSlot R4SdkTransportResources_resourceKind(uint32_t reserved, const R4SdkWebHtmlDocument * p0, uint16_t p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,13u,a,2u,0);
}
/* web_resources.hasPotentialImageSource -> bool */
static inline R4SdkTransportSlot R4SdkTransportResources_hasPotentialImageSource(uint32_t reserved, const R4SdkWebHtmlDocument * p0, uint16_t p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,14u,a,2u,0);
}
/* transport_helper_adapters.open -> bool */
static inline R4SdkTransportSlot R4SdkTransport_open(uint32_t reserved, R4SdkTransportContext * p0, const R4XStartContext * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,15u,a,2u,0);
}
/* transport_helper_adapters.transport -> *app_web.WebTransport */
static inline R4SdkTransportSlot R4SdkTransport_transport(uint32_t reserved, R4SdkTransportContext * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,16u,a,1u,0);
}
/* transport_helper_adapters.job -> void */
static inline R4SdkTransportSlot R4SdkTransport_job(uint32_t reserved, R4SdkTransportJobsJob * p0, const R4SdkTransportContext * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,17u,a,2u,0);
}
/* transport_helper_adapters.requestJob -> void */
static inline R4SdkTransportSlot R4SdkTransport_requestJob(uint32_t reserved, R4SdkTransportRuntimeJobsRequestJob * p0, const R4SdkTransportContext * p1, const R4SdkDataAllocator * p2, const R4SdkTransportRuntimeJobsOwner * p3) {
 (void)reserved; R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,18u,a,4u,0);
}
/* transport_helper_adapters.owner -> error{MissingCallback}!web_runtime_jobs.Owner */
static inline R4SdkTransportSlot R4SdkTransport_owner(uint32_t reserved, const R4SdkWebCallbackTable * p0, R4SdkTransportRuntimeJobsOwner *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,19u,a,1u,output);
}
/* transport_helper_adapters.fetchCallbacks -> void */
static inline R4SdkTransportSlot R4SdkTransport_fetchCallbacks(uint32_t reserved, R4SdkTransportFetchOptions * p0, const R4SdkWebCallbackTable * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,20u,a,2u,0);
}
/* transport_helper_adapters.downloadCallbacks -> void */
static inline R4SdkTransportSlot R4SdkTransport_downloadCallbacks(uint32_t reserved, R4SdkTransportDownloadOptions * p0, const R4SdkWebCallbackTable * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,21u,a,2u,0);
}
/* transport_helper_adapters.sink -> error{MissingCallback}!app_web.DownloadSink */
static inline R4SdkTransportSlot R4SdkTransport_sink(uint32_t reserved, const R4SdkWebCallbackTable * p0, R4SdkTransportDownloadSink *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,22u,a,1u,output);
}
/* app_web.RequestDeadline.start -> app_web.RequestDeadline */
static inline R4SdkTransportSlot R4SdkTransportRequestDeadline_start(uint32_t reserved, const R4SdkTransportNative_app_network_Network * p0, const R4Timeout * p1, R4SdkTransportRequestDeadline *output) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,23u,a,2u,output);
}
/* app_web.SessionPool.deinit -> void */
static inline R4SdkTransportSlot R4SdkTransportSessionPool_deinit(uint32_t reserved, R4SdkTransportSessionPool * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,24u,a,1u,0);
}
/* app_network.TcpSocket.valid -> bool */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_valid(uint32_t reserved, const R4SdkTransportNative_app_network_TcpSocket * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,25u,a,1u,0);
}
/* app_network.TcpSocket.write -> app_network.SocketIo */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_write(uint32_t reserved, R4SdkTransportNative_app_network_TcpSocket * p0, const uint8_t * p1, uintptr_t n1, const R4Timeout * p2, R4SdkTransportNative_app_network_SocketIo *output) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,26u,a,3u,output);
}
/* app_network.TcpSocket.read -> app_network.SocketIo */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_read(uint32_t reserved, R4SdkTransportNative_app_network_TcpSocket * p0, uint8_t * p1, uintptr_t n1, const R4Timeout * p2, R4SdkTransportNative_app_network_SocketIo *output) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,27u,a,3u,output);
}
/* app_network.TcpSocket.poll -> app_network.SocketIo */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_poll(uint32_t reserved, R4SdkTransportNative_app_network_TcpSocket * p0, const R4Timeout * p1, R4SdkTransportNative_app_network_SocketIo *output) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,28u,a,2u,output);
}
/* app_network.TcpSocket.close -> app_network.SocketIo */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_close(uint32_t reserved, R4SdkTransportNative_app_network_TcpSocket * p0, const R4Timeout * p1, R4SdkTransportNative_app_network_SocketIo *output) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,29u,a,2u,output);
}
/* app_network.Network.available -> bool */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_available(uint32_t reserved, const R4SdkTransportNative_app_network_Network * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,30u,a,1u,0);
}
/* app_network.Network.resolver -> app_network.Resolver */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_resolver(uint32_t reserved, const R4SdkTransportNative_app_network_Network * p0, R4SdkTransportNative_app_network_Resolver *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,31u,a,1u,output);
}
/* app_network.Network.connectTcp -> app_network.TcpOpen */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_connectTcp(uint32_t reserved, const R4SdkTransportNative_app_network_Network * p0, const R4SdkTransportNative_app_network_SocketAddress * p1, const R4Timeout * p2, R4SdkTransportNative_app_network_TcpOpen *output) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,32u,a,3u,output);
}
/* app_network.Network.listenTcp -> app_network.ListenerOpen */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_listenTcp(uint32_t reserved, const R4SdkTransportNative_app_network_Network * p0, uint16_t p1, const R4Timeout * p2, R4SdkTransportNative_app_network_ListenerOpen *output) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,33u,a,3u,output);
}
/* app_network.Network.bindUdp -> app_network.UdpOpen */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_bindUdp(uint32_t reserved, const R4SdkTransportNative_app_network_Network * p0, uint16_t p1, const R4Timeout * p2, R4SdkTransportNative_app_network_UdpOpen *output) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,34u,a,3u,output);
}
/* app_network.Ipv4Address.init -> app_network.Ipv4Address */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Ipv4Address_init(uint32_t reserved, uint8_t p0, uint8_t p1, uint8_t p2, uint8_t p3, R4SdkTransportNative_app_network_Ipv4Address *output) {
 (void)reserved; R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,35u,a,4u,output);
}
/* app_network.Ipv4Address.fromBytes -> app_network.Ipv4Address */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Ipv4Address_fromBytes(uint32_t reserved, const R4SdkTransportNativeValue19 * p0, R4SdkTransportNative_app_network_Ipv4Address *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,36u,a,1u,output);
}
/* app_network.Ipv4Address.isUnspecified -> bool */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Ipv4Address_isUnspecified(uint32_t reserved, const R4SdkTransportNative_app_network_Ipv4Address * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,37u,a,1u,0);
}
/* app_web.FinalUrl.bytes -> []const u8 */
static inline R4SdkTransportSlot R4SdkTransportFinalUrl_bytes(uint32_t reserved, const R4SdkTransportFinalUrl * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,38u,a,1u,0);
}
/* app_web.DownloadSink.write -> bool */
static inline R4SdkTransportSlot R4SdkTransportDownloadSink_write(uint32_t reserved, const R4SdkTransportDownloadSink * p0, uint64_t p1, const uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,39u,a,3u,0);
}
/* app_web.WebTransport.available -> bool */
static inline R4SdkTransportSlot R4SdkTransportWebTransport_available(uint32_t reserved, const R4SdkTransportWebTransport * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,40u,a,1u,0);
}
/* app_web.WebTransport.fetch -> app_web.FetchResult */
static inline R4SdkTransportSlot R4SdkTransportWebTransport_fetch(uint32_t reserved, R4SdkTransportWebTransport * p0, const uint8_t * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2, uint8_t * p3, uintptr_t n3, uint8_t * p4, uintptr_t n4, const R4SdkTransportFetchOptions * p5, R4SdkTransportFetchResult *output) {
 (void)reserved; R4SdkTransportSlot a[6]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.ptr=(void *)p5,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,41u,a,6u,output);
}
/* app_web.WebTransport.download -> app_web.DownloadResult */
static inline R4SdkTransportSlot R4SdkTransportWebTransport_download(uint32_t reserved, R4SdkTransportWebTransport * p0, const uint8_t * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2, uint8_t * p3, uintptr_t n3, uint8_t * p4, uintptr_t n4, const R4SdkTransportDownloadSink * p5, const R4SdkTransportDownloadOptions * p6, R4SdkTransportDownloadResult *output) {
 (void)reserved; R4SdkTransportSlot a[7]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.ptr=(void *)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.ptr=(void *)p6,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,42u,a,7u,output);
}
/* http.Scheme.defaultPort -> u16 */
static inline R4SdkTransportSlot R4SdkTransportHttpScheme_defaultPort(uint32_t reserved, uint32_t p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,43u,a,1u,0);
}
/* http.Scheme.text -> []const u8 */
static inline R4SdkTransportSlot R4SdkTransportHttpScheme_text(uint32_t reserved, uint32_t p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,44u,a,1u,0);
}
/* http.Response.isRedirect -> bool */
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_isRedirect(uint32_t reserved, const R4SdkTransportHttpResponse * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,45u,a,1u,0);
}
/* http.ResponseDecoder.init -> http.ResponseDecoder */
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_init(uint32_t reserved, uint32_t p0, R4SdkTransportHttpResponseDecoder *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,46u,a,1u,output);
}
/* http.ResponseDecoder.decode -> http.DecodeResult */
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_decode(uint32_t reserved, R4SdkTransportHttpResponseDecoder * p0, const uint8_t * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2, uint8_t p3, uint8_t p4, R4SdkTransportHttpDecodeResult *output) {
 (void)reserved; R4SdkTransportSlot a[5]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,47u,a,5u,output);
}
/* http.StreamResponse.isRedirect -> bool */
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_isRedirect(uint32_t reserved, const R4SdkTransportHttpStreamResponse * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,48u,a,1u,0);
}
/* http.StreamDecoder.init -> http.StreamDecoder */
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_init(uint32_t reserved, uint8_t * p0, uintptr_t n0, uint32_t p1, R4SdkTransportHttpStreamDecoder *output) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,49u,a,2u,output);
}
/* http.StreamDecoder.response -> ?http.StreamResponse */
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_response(uint32_t reserved, const R4SdkTransportHttpStreamDecoder * p0, R4SdkTransportHttpStreamResponse *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,50u,a,1u,output);
}
/* http.StreamDecoder.receivedBytes -> u64 */
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_receivedBytes(uint32_t reserved, const R4SdkTransportHttpStreamDecoder * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,51u,a,1u,0);
}
/* http.StreamDecoder.push -> http.StreamDecodeResult */
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_push(uint32_t reserved, R4SdkTransportHttpStreamDecoder * p0, const uint8_t * p1, uintptr_t n1, uint8_t p2, uint8_t p3, R4SdkTransportHttpStreamDecodeResult *output) {
 (void)reserved; R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,52u,a,4u,output);
}
/* web_response_cache.Cache.init -> web_response_cache.Cache */
static inline R4SdkTransportSlot R4SdkTransportCacheCache_init(uint32_t reserved, const R4SdkDataAllocator * p0, const R4SdkTransportCacheLimits * p1, R4SdkTransportCacheCache *output) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,53u,a,2u,output);
}
/* web_response_cache.Cache.deinit -> void */
static inline R4SdkTransportSlot R4SdkTransportCacheCache_deinit(uint32_t reserved, R4SdkTransportCacheCache * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,54u,a,1u,0);
}
/* web_response_cache.Cache.invalidateUrl -> void */
static inline R4SdkTransportSlot R4SdkTransportCacheCache_invalidateUrl(uint32_t reserved, R4SdkTransportCacheCache * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,55u,a,2u,0);
}
/* web_response_cache.Cache.invalidate -> void */
static inline R4SdkTransportSlot R4SdkTransportCacheCache_invalidate(uint32_t reserved, R4SdkTransportCacheCache * p0, const R4SdkTransportCacheKey * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,56u,a,2u,0);
}
/* web_response_cache.Cache.lookup -> web_response_cache.Lookup */
static inline R4SdkTransportSlot R4SdkTransportCacheCache_lookup(uint32_t reserved, R4SdkTransportCacheCache * p0, const R4SdkTransportCacheKey * p1, uint32_t p2, const R4SdkTransportCacheClock * p3, R4SdkTransportCacheLookup *output) {
 (void)reserved; R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,57u,a,4u,output);
}
/* web_response_cache.Cache.view -> ?web_response_cache.View */
static inline R4SdkTransportSlot R4SdkTransportCacheCache_view(uint32_t reserved, R4SdkTransportCacheCache * p0, const R4SdkTransportCacheHandle * p1, const R4SdkTransportCacheClock * p2, R4SdkTransportCacheView *output) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,58u,a,3u,output);
}
/* web_response_cache.Cache.release -> void */
static inline R4SdkTransportSlot R4SdkTransportCacheCache_release(uint32_t reserved, R4SdkTransportCacheCache * p0, const R4SdkTransportCacheHandle * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,59u,a,2u,0);
}
/* web_response_cache.Cache.store -> @typeInfo(@typeInfo(@TypeOf(web_response_cache.Cache.store)).@"fn".return_type.?).error_union.error_set!?u64 */
static inline R4SdkTransportSlot R4SdkTransportCacheCache_store(uint32_t reserved, R4SdkTransportCacheCache * p0, const R4SdkTransportCacheKey * p1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const R4SdkTransportCacheClock * p4, uint64_t p5, R4SdkTransportSlot p6) {
 (void)reserved; R4SdkTransportSlot a[7]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.ptr=(void *)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = p6;
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,60u,a,7u,0);
}
/* web_response_cache.Cache.newIdentity -> u64 */
static inline R4SdkTransportSlot R4SdkTransportCacheCache_newIdentity(uint32_t reserved, R4SdkTransportCacheCache * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,61u,a,1u,0);
}
/* web_response_cache.HeaderIterator.init -> web_response_cache.HeaderIterator */
static inline R4SdkTransportSlot R4SdkTransportCacheHeaderIterator_init(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4SdkTransportCacheHeaderIterator *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,62u,a,1u,output);
}
/* web_response_cache.HeaderIterator.next -> ?web_response_cache.Header */
static inline R4SdkTransportSlot R4SdkTransportCacheHeaderIterator_next(uint32_t reserved, R4SdkTransportCacheHeaderIterator * p0, R4SdkTransportCacheHeader *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,63u,a,1u,output);
}
/* mem.SplitIterator(u8,.scalar).first -> []const u8 */
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__first(uint32_t reserved, R4SdkTransportNative_mem_SplitIterator_u8__scalar_ * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,64u,a,1u,0);
}
/* mem.SplitIterator(u8,.scalar).next -> ?[]const u8 */
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__next(uint32_t reserved, R4SdkTransportNative_mem_SplitIterator_u8__scalar_ * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,65u,a,1u,0);
}
/* mem.SplitIterator(u8,.scalar).peek -> ?[]const u8 */
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__peek(uint32_t reserved, const R4SdkTransportNative_mem_SplitIterator_u8__scalar_ * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,66u,a,1u,0);
}
/* mem.SplitIterator(u8,.scalar).rest -> []const u8 */
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__rest(uint32_t reserved, const R4SdkTransportNative_mem_SplitIterator_u8__scalar_ * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,67u,a,1u,0);
}
/* mem.SplitIterator(u8,.scalar).reset -> void */
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__reset(uint32_t reserved, R4SdkTransportNative_mem_SplitIterator_u8__scalar_ * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,68u,a,1u,0);
}
/* app_web_jobs.Job.start -> bool */
static inline R4SdkTransportSlot R4SdkTransportJobsJob_start(uint32_t reserved, R4SdkTransportJobsJob * p0, const uint8_t * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2, uint8_t * p3, uintptr_t n3, uint8_t * p4, uintptr_t n4, const R4SdkTransportFetchOptions * p5) {
 (void)reserved; R4SdkTransportSlot a[6]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.ptr=(void *)p5,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,69u,a,6u,0);
}
/* app_web_jobs.Job.cancel -> void */
static inline R4SdkTransportSlot R4SdkTransportJobsJob_cancel(uint32_t reserved, R4SdkTransportJobsJob * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,70u,a,1u,0);
}
/* app_web_jobs.Job.service -> bool */
static inline R4SdkTransportSlot R4SdkTransportJobsJob_service(uint32_t reserved, R4SdkTransportJobsJob * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,71u,a,1u,0);
}
/* app_web_jobs.Job.collect -> bool */
static inline R4SdkTransportSlot R4SdkTransportJobsJob_collect(uint32_t reserved, R4SdkTransportJobsJob * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,72u,a,1u,0);
}
/* app_web_jobs.Job.deinit -> void */
static inline R4SdkTransportSlot R4SdkTransportJobsJob_deinit(uint32_t reserved, R4SdkTransportJobsJob * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,73u,a,1u,0);
}
/* app_resources.JoinHandle.valid -> bool */
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_valid(uint32_t reserved, const R4SdkTransportNative_app_resources_JoinHandle * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,74u,a,1u,0);
}
/* app_resources.JoinHandle.placement -> i32 */
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_placement(uint32_t reserved, const R4SdkTransportNative_app_resources_JoinHandle * p0, R4ThreadPlacementInfo * p1, uint64_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,75u,a,3u,0);
}
/* app_resources.JoinHandle.setPlacement -> i32 */
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_setPlacement(uint32_t reserved, const R4SdkTransportNative_app_resources_JoinHandle * p0, const R4ThreadPlacementRequest * p1, const uint64_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,76u,a,3u,0);
}
/* app_resources.JoinHandle.status -> app_resources.ThreadInfo */
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_status(uint32_t reserved, const R4SdkTransportNative_app_resources_JoinHandle * p0, R4SdkTransportNative_app_resources_ThreadInfo *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,77u,a,1u,output);
}
/* app_resources.JoinHandle.join -> app_resources.JoinWait */
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_join(uint32_t reserved, R4SdkTransportNative_app_resources_JoinHandle * p0, const R4Timeout * p1, R4SdkTransportNative_app_resources_JoinWait *output) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,78u,a,2u,output);
}
/* web_runtime_jobs.RequestJob.prepare -> @typeInfo(@typeInfo(@TypeOf(web_runtime_jobs.RequestJob.prepare)).@"fn".return_type.?).error_union.error_set!void */
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_prepare(uint32_t reserved, R4SdkTransportRuntimeJobsRequestJob * p0, R4SdkWebRuntimeWebRuntime * p1, R4SdkWebRuntimePendingRequest * p2, uint64_t p3, uint64_t p4) {
 (void)reserved; R4SdkTransportSlot a[5]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,79u,a,5u,0);
}
/* web_runtime_jobs.RequestJob.start -> bool */
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_start(uint32_t reserved, R4SdkTransportRuntimeJobsRequestJob * p0, const R4SdkTransportFetchOptions * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,80u,a,2u,0);
}
/* web_runtime_jobs.RequestJob.activeRuntime -> ?*web_runtime.WebRuntime */
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_activeRuntime(uint32_t reserved, R4SdkTransportRuntimeJobsRequestJob * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,81u,a,1u,0);
}
/* web_runtime_jobs.RequestJob.poll -> bool */
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_poll(uint32_t reserved, R4SdkTransportRuntimeJobsRequestJob * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,82u,a,1u,0);
}
/* web_runtime_jobs.RequestJob.release -> void */
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_release(uint32_t reserved, R4SdkTransportRuntimeJobsRequestJob * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,83u,a,1u,0);
}
/* web_runtime_jobs.RequestJob.deinit -> void */
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_deinit(uint32_t reserved, R4SdkTransportRuntimeJobsRequestJob * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,84u,a,1u,0);
}
/* web_runtime_jobs.RequestJob.fail -> void */
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_fail(uint32_t reserved, R4SdkTransportRuntimeJobsRequestJob * p0, const uint8_t * p1, uintptr_t n1, uint8_t p2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,85u,a,3u,0);
}
/* web_runtime_jobs.RequestJob.complete -> void */
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_complete(uint32_t reserved, R4SdkTransportRuntimeJobsRequestJob * p0, const R4SdkTransportFetchResponse * p1, uint64_t p2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,86u,a,3u,0);
}
/* web_documents.Set.init -> web_documents.Set */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_init(uint32_t reserved, const R4SdkDataAllocator * p0, const R4SdkWebJsProgramAllocator * p1, R4SdkWebNative_web_security_BrowserStorage * p2, R4SdkTransportDocumentsSet *output) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,87u,a,3u,output);
}
/* web_documents.Set.deinit -> void */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_deinit(uint32_t reserved, R4SdkTransportDocumentsSet * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,88u,a,1u,0);
}
/* web_documents.Set.setExecutionPolicy -> void */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_setExecutionPolicy(uint32_t reserved, R4SdkTransportDocumentsSet * p0, const R4SdkWebJsStop * p1, uint64_t p2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,89u,a,3u,0);
}
/* web_documents.Set.setEnvironment -> void */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_setEnvironment(uint32_t reserved, R4SdkTransportDocumentsSet * p0, const R4SdkWebRuntimeEnvironment * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,90u,a,2u,0);
}
/* web_documents.Set.setMonotonicClock -> void */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_setMonotonicClock(uint32_t reserved, R4SdkTransportDocumentsSet * p0, const R4SdkWebRuntimeMonotonicClock * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,91u,a,2u,0);
}
/* web_documents.Set.setViewport -> void */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_setViewport(uint32_t reserved, R4SdkTransportDocumentsSet * p0, uint32_t p1, uint32_t p2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,92u,a,3u,0);
}
/* web_documents.Set.create -> error{AbortLimit,ActionLimit,AllocationFailed,AttributeLimit,BindingLimit,BytecodeFrameLimit,BytecodeInvalid,BytecodeLimit,BytecodeSegmentLimit,BytecodeStack,CallDepth,Cancelled,CellLimit,ConstAssignment,CookieLimit,CorsBlocked,CssDepthLimit,DepthLimit,DescriptorLimit,Empty,EntropyUnavailable,FaceLimit,FamilyListTooLong,GeneratorAllocation,GeneratorReturn,HeaderLimit,InputTooLarge,InvalidAssignment,InvalidCharacter,InvalidCookie,InvalidName,InvalidNode,InvalidPolicy,InvalidResource,InvalidSequence,InvalidSerialized,InvalidSurface,InvalidTransition,InvalidUrl,InvalidValue,ItemLimit,JobLimit,KeyTooLarge,ListenerLimit,MalformedPersistence,MissingHost,ModuleCycle,ModuleLimit,ModuleNotFound,MutationLimit,NameTooLong,NodeLimit,NotCallable,NotInitialized,NotObject,OriginLimit,OutputLimit,OutputTooSmall,PairLimit,PersistenceLimit,PolicyTooLarge,ProgramAllocation,PropertyLimit,RangeError,RequestLimit,RequestNotFound,RequestState,ResourceLimit,ResponseTooLarge,RootLimit,ScriptAllocation,ScriptLimit,ScriptThrown,SecurityBlocked,SerializedTooLong,SizeLimit,SourceLimit,SourceSectionLimit,SourceTooLarge,StaleGeneration,StaleParent,StepLimit,StorageLimit,StringLimit,StylesheetTooLarge,SubdocumentLimit,SubdocumentNotFound,SurfaceLimit,SyntaxError,TextRunTooLong,TimerLimit,TokenLimit,TooLong,TypeError,UncaughtException,UnexpectedToken,UnicodeRangeLimit,UnknownEncoding,UnknownIdentifier,UnsupportedAlgorithm,UnsupportedEncoding,UnsupportedMediaType,UnsupportedOrigin,UnsupportedRelativeBase,UnsupportedScheme,ValueTooLarge,ValueTooLong,ViewLimit,XhrLimit}!*web_documents.Context */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_create(uint32_t reserved, R4SdkTransportDocumentsSet * p0, uint32_t p1, const R4SdkWebNative_web_security_Origin * p2, uint16_t p3, const R4SdkWebNavigationUrl * p4, const uint8_t * p5, uintptr_t n5, const uint8_t * p6, uintptr_t n6, const uint8_t * p7, uintptr_t n7, uint8_t p8, const R4SdkWebRuntimeResourceHandler * p9, const R4SdkWebRuntimeFrameLookup * p10) {
 (void)reserved; R4SdkTransportSlot a[11]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.ptr=(void *)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.ptr=(void *)p5,.length=n5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.ptr=(void *)p6,.length=n6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = (R4SdkTransportSlot){.ptr=(void *)p7,.length=n7,.flags=R4SDKTRANSPORT_PRESENT};
 a[8] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDKTRANSPORT_PRESENT};
 a[9] = (R4SdkTransportSlot){.ptr=(void *)p9,.flags=R4SDKTRANSPORT_PRESENT};
 a[10] = (R4SdkTransportSlot){.ptr=(void *)p10,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,93u,a,11u,0);
}
/* web_documents.Set.find -> ?*web_documents.Context */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_find(uint32_t reserved, const R4SdkTransportDocumentsSet * p0, uint32_t p1, uint16_t p2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,94u,a,3u,0);
}
/* web_documents.Set.findGeneration -> ?*web_documents.Context */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_findGeneration(uint32_t reserved, const R4SdkTransportDocumentsSet * p0, uint32_t p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,95u,a,2u,0);
}
/* web_documents.Set.sameOrigin -> bool */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_sameOrigin(uint32_t reserved, const R4SdkTransportDocumentsSet * p0, const R4SdkWebNative_web_security_Origin * p1, uint32_t p2, uint16_t p3) {
 (void)reserved; R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,96u,a,4u,0);
}
/* web_documents.Set.retireParent -> void */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_retireParent(uint32_t reserved, R4SdkTransportDocumentsSet * p0, uint32_t p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,97u,a,2u,0);
}
/* web_documents.Set.activeCount -> usize */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_activeCount(uint32_t reserved, const R4SdkTransportDocumentsSet * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,98u,a,1u,0);
}
/* web_documents.Set.pumpFair -> error{AbortLimit,ActionLimit,AllocationFailed,AttributeLimit,BindingLimit,BytecodeFrameLimit,BytecodeInvalid,BytecodeLimit,BytecodeSegmentLimit,BytecodeStack,CallDepth,Cancelled,CellLimit,ConstAssignment,CookieLimit,CorsBlocked,CssDepthLimit,DepthLimit,DescriptorLimit,Empty,EntropyUnavailable,FaceLimit,FamilyListTooLong,GeneratorAllocation,GeneratorReturn,HeaderLimit,InputTooLarge,InvalidAssignment,InvalidCharacter,InvalidCookie,InvalidName,InvalidNode,InvalidPolicy,InvalidResource,InvalidSequence,InvalidSerialized,InvalidSurface,InvalidTransition,InvalidUrl,InvalidValue,ItemLimit,JobLimit,KeyTooLarge,ListenerLimit,MalformedPersistence,MissingHost,ModuleCycle,ModuleLimit,ModuleNotFound,MutationLimit,NameTooLong,NodeLimit,NotCallable,NotInitialized,NotObject,OriginLimit,OutputLimit,OutputTooSmall,PairLimit,PersistenceLimit,PolicyTooLarge,ProgramAllocation,PropertyLimit,RangeError,RequestLimit,RequestNotFound,RequestState,ResourceLimit,ResponseTooLarge,RootLimit,ScriptAllocation,ScriptLimit,ScriptThrown,SecurityBlocked,SerializedTooLong,SizeLimit,SourceLimit,SourceSectionLimit,SourceTooLarge,StaleGeneration,StaleParent,StepLimit,StorageLimit,StringLimit,StylesheetTooLarge,SubdocumentLimit,SubdocumentNotFound,SurfaceLimit,SyntaxError,TextRunTooLong,TimerLimit,TokenLimit,TooLong,TypeError,UncaughtException,UnexpectedToken,UnicodeRangeLimit,UnknownEncoding,UnknownIdentifier,UnsupportedAlgorithm,UnsupportedEncoding,UnsupportedMediaType,UnsupportedOrigin,UnsupportedRelativeBase,UnsupportedScheme,ValueTooLarge,ValueTooLong,ViewLimit,XhrLimit}!usize */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_pumpFair(uint32_t reserved, R4SdkTransportDocumentsSet * p0, const double * p1, uint64_t p2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,99u,a,3u,0);
}
/* web_documents.Set.finalizeSettled -> error{AbortLimit,ActionLimit,AllocationFailed,AttributeLimit,BindingLimit,BytecodeFrameLimit,BytecodeInvalid,BytecodeLimit,BytecodeSegmentLimit,BytecodeStack,CallDepth,Cancelled,CellLimit,ConstAssignment,CookieLimit,CorsBlocked,CssDepthLimit,DepthLimit,DescriptorLimit,Empty,EntropyUnavailable,FaceLimit,FamilyListTooLong,GeneratorAllocation,GeneratorReturn,HeaderLimit,InputTooLarge,InvalidAssignment,InvalidCharacter,InvalidCookie,InvalidName,InvalidNode,InvalidPolicy,InvalidResource,InvalidSequence,InvalidSerialized,InvalidSurface,InvalidTransition,InvalidUrl,InvalidValue,ItemLimit,JobLimit,KeyTooLarge,ListenerLimit,MalformedPersistence,MissingHost,ModuleCycle,ModuleLimit,ModuleNotFound,MutationLimit,NameTooLong,NodeLimit,NotCallable,NotInitialized,NotObject,OriginLimit,OutputLimit,OutputTooSmall,PairLimit,PersistenceLimit,PolicyTooLarge,ProgramAllocation,PropertyLimit,RangeError,RequestLimit,RequestNotFound,RequestState,ResourceLimit,ResponseTooLarge,RootLimit,ScriptAllocation,ScriptLimit,ScriptThrown,SecurityBlocked,SerializedTooLong,SizeLimit,SourceLimit,SourceSectionLimit,SourceTooLarge,StaleGeneration,StaleParent,StepLimit,StorageLimit,StringLimit,StylesheetTooLarge,SubdocumentLimit,SubdocumentNotFound,SurfaceLimit,SyntaxError,TextRunTooLong,TimerLimit,TokenLimit,TooLong,TypeError,UncaughtException,UnexpectedToken,UnicodeRangeLimit,UnknownEncoding,UnknownIdentifier,UnsupportedAlgorithm,UnsupportedEncoding,UnsupportedMediaType,UnsupportedOrigin,UnsupportedRelativeBase,UnsupportedScheme,ValueTooLarge,ValueTooLong,ViewLimit,XhrLimit}!usize */
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_finalizeSettled(uint32_t reserved, R4SdkTransportDocumentsSet * p0, const double * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,100u,a,2u,0);
}
/* web_fetch.Headers.init -> error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}!web_fetch.Headers */
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_init(uint32_t reserved, const uint8_t * p0, uintptr_t n0, R4SdkTransportFetchHeaders *output) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,101u,a,1u,output);
}
/* web_fetch.Headers.append -> error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}!void */
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_append(uint32_t reserved, R4SdkTransportFetchHeaders * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,102u,a,3u,0);
}
/* web_fetch.Headers.delete -> error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}!void */
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_delete(uint32_t reserved, R4SdkTransportFetchHeaders * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,103u,a,2u,0);
}
/* web_fetch.Headers.has -> error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}!bool */
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_has(uint32_t reserved, const R4SdkTransportFetchHeaders * p0, const uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,104u,a,2u,0);
}
/* web_fetch.Headers.set -> error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}!void */
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_set(uint32_t reserved, R4SdkTransportFetchHeaders * p0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,105u,a,3u,0);
}
/* web_fetch.Headers.get -> error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}!?[]const u8 */
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_get(uint32_t reserved, const R4SdkTransportFetchHeaders * p0, const uint8_t * p1, uintptr_t n1, uint8_t * p2, uintptr_t n2) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,106u,a,3u,0);
}
/* web_fetch.Headers.getSetCookie -> usize */
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_getSetCookie(uint32_t reserved, const R4SdkTransportFetchHeaders * p0, R4SdkTransportNativeValue229 * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,107u,a,2u,0);
}
/* web_fetch.Headers.serialize -> error{HeaderLimit,InvalidName,InvalidSerialized,InvalidValue,NameTooLong,SerializedTooLong,ValueTooLong}![]const u8 */
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_serialize(uint32_t reserved, const R4SdkTransportFetchHeaders * p0, uint8_t * p1, uintptr_t n1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,108u,a,2u,0);
}
/* web_fetch.Headers.ordered -> []const usize */
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_ordered(uint32_t reserved, const R4SdkTransportFetchHeaders * p0, R4SdkTransportNativeValue232 * p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,109u,a,2u,0);
}
/* web_fetch.Headers.name -> []const u8 */
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_name(uint32_t reserved, const R4SdkTransportFetchHeaders * p0, uint64_t p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,110u,a,2u,0);
}
/* web_fetch.Headers.value -> []const u8 */
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_value(uint32_t reserved, const R4SdkTransportFetchHeaders * p0, uint64_t p1) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,111u,a,2u,0);
}
/* app_network.Resolver.resolveA -> app_network.ResolveResult */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Resolver_resolveA(uint32_t reserved, R4SdkTransportNative_app_network_Resolver * p0, const uint8_t * p1, uintptr_t n1, R4SdkTransportSlot p2, const R4Timeout * p3, R4SdkTransportNative_app_network_ResolveResult *output) {
 (void)reserved; R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = p2;
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,112u,a,4u,output);
}
/* app_network.TcpListener.valid -> bool */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_valid(uint32_t reserved, const R4SdkTransportNative_app_network_TcpListener * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,113u,a,1u,0);
}
/* app_network.TcpListener.accept -> app_network.TcpAccept */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_accept(uint32_t reserved, R4SdkTransportNative_app_network_TcpListener * p0, const R4Timeout * p1, R4SdkTransportNative_app_network_TcpAccept *output) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,114u,a,2u,output);
}
/* app_network.TcpListener.close -> app_network.SocketIo */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_close(uint32_t reserved, R4SdkTransportNative_app_network_TcpListener * p0, const R4Timeout * p1, R4SdkTransportNative_app_network_SocketIo *output) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,115u,a,2u,output);
}
/* app_network.UdpSocket.valid -> bool */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_valid(uint32_t reserved, const R4SdkTransportNative_app_network_UdpSocket * p0) {
 (void)reserved; R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,116u,a,1u,0);
}
/* app_network.UdpSocket.sendTo -> app_network.SocketIo */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_sendTo(uint32_t reserved, R4SdkTransportNative_app_network_UdpSocket * p0, const R4SdkTransportNative_app_network_SocketAddress * p1, const uint8_t * p2, uintptr_t n2, const R4Timeout * p3, R4SdkTransportNative_app_network_SocketIo *output) {
 (void)reserved; R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,117u,a,4u,output);
}
/* app_network.UdpSocket.receiveFrom -> app_network.UdpReceive */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_receiveFrom(uint32_t reserved, R4SdkTransportNative_app_network_UdpSocket * p0, uint8_t * p1, uintptr_t n1, const R4Timeout * p2, R4SdkTransportNative_app_network_UdpReceive *output) {
 (void)reserved; R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,118u,a,3u,output);
}
/* app_network.UdpSocket.close -> app_network.SocketIo */
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_close(uint32_t reserved, R4SdkTransportNative_app_network_UdpSocket * p0, const R4Timeout * p1, R4SdkTransportNative_app_network_SocketIo *output) {
 (void)reserved; R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportInvoke(R4SdkTransport_ABI_FINGERPRINT,119u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportRequestDeadline_create(R4SdkTransportRequestDeadline *output) {
 R4SdkTransportSlot a[3]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,1u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportRequestDeadline_from_fields(R4SdkTransportRequestDeadline *output, uint64_t p0, uint8_t p1, uint8_t p2) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,1u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportRequestDeadline_get_deadline_tick(const R4SdkTransportRequestDeadline *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,1u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRequestDeadline_set_deadline_tick(R4SdkTransportRequestDeadline *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,1u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRequestDeadline_get_forever(const R4SdkTransportRequestDeadline *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,1u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRequestDeadline_set_forever(R4SdkTransportRequestDeadline *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,1u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRequestDeadline_get_valid(const R4SdkTransportRequestDeadline *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,1u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRequestDeadline_set_valid(R4SdkTransportRequestDeadline *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,1u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRequestDeadline_inspectNative(const R4SdkTransportRequestDeadline *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,1u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportError_create(R4SdkTransportError *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,2u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportError_inspectNative(const R4SdkTransportError *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,2u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportRedirectMode_create(R4SdkTransportRedirectMode *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,3u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportRedirectMode_inspectNative(const R4SdkTransportRedirectMode *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,3u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_create(R4SdkTransportTransportStats *output) {
 R4SdkTransportSlot a[6]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,4u,a,6u,output);
}
static inline R4SdkTransportSlot R4SdkTransportTransportStats_from_fields(R4SdkTransportTransportStats *output, uint64_t p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5) {
 R4SdkTransportSlot a[6]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,4u,a,6u,output);
}
static inline R4SdkTransportSlot R4SdkTransportTransportStats_get_dns_resolutions(const R4SdkTransportTransportStats *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_set_dns_resolutions(R4SdkTransportTransportStats *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_get_connections(const R4SdkTransportTransportStats *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_set_connections(R4SdkTransportTransportStats *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_get_tls_handshakes(const R4SdkTransportTransportStats *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_set_tls_handshakes(R4SdkTransportTransportStats *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_get_reused_connections(const R4SdkTransportTransportStats *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_set_reused_connections(R4SdkTransportTransportStats *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_get_preflights(const R4SdkTransportTransportStats *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_set_preflights(R4SdkTransportTransportStats *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_get_payload_copied_bytes(const R4SdkTransportTransportStats *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_set_payload_copied_bytes(R4SdkTransportTransportStats *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,4u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportTransportStats_inspectNative(const R4SdkTransportTransportStats *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,4u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_create(R4SdkTransportFetchOptions *output) {
 R4SdkTransportSlot a[27]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 a[7].flags=R4SDKTRANSPORT_DEFAULT;
 a[8].flags=R4SDKTRANSPORT_DEFAULT;
 a[9].flags=R4SDKTRANSPORT_DEFAULT;
 a[10].flags=R4SDKTRANSPORT_DEFAULT;
 a[11].flags=R4SDKTRANSPORT_DEFAULT;
 a[12].flags=R4SDKTRANSPORT_DEFAULT;
 a[13].flags=R4SDKTRANSPORT_DEFAULT;
 a[14].flags=R4SDKTRANSPORT_DEFAULT;
 a[15].flags=R4SDKTRANSPORT_DEFAULT;
 a[16].flags=R4SDKTRANSPORT_DEFAULT;
 a[17].flags=R4SDKTRANSPORT_DEFAULT;
 a[18].flags=R4SDKTRANSPORT_DEFAULT;
 a[19].flags=R4SDKTRANSPORT_DEFAULT;
 a[20].flags=R4SDKTRANSPORT_DEFAULT;
 a[21].flags=R4SDKTRANSPORT_DEFAULT;
 a[22].flags=R4SDKTRANSPORT_DEFAULT;
 a[23].flags=R4SDKTRANSPORT_DEFAULT;
 a[24].flags=R4SDKTRANSPORT_DEFAULT;
 a[25].flags=R4SDKTRANSPORT_DEFAULT;
 a[26].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,5u,a,27u,output);
}
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_from_fields(R4SdkTransportFetchOptions *output, R4SdkTransportSlot p0, const uint8_t * p1, uintptr_t n1, R4SdkTransportSlot p2, R4SdkTransportSlot p3, const R4Timeout * p4, uint8_t p5, uint32_t p6, R4SdkTransportSlot p7, R4SdkTransportSlot p8, R4SdkTransportSlot p9, R4SdkTransportSlot p10, const uint8_t * p11, uintptr_t n11, R4SdkTransportSlot p12, const uint8_t * p13, uintptr_t n13, const uint8_t * p14, uintptr_t n14, const uint8_t * p15, uintptr_t n15, const uint8_t * p16, uintptr_t n16, uint32_t p17, const uint8_t * p18, uintptr_t n18, const uint8_t * p19, uintptr_t n19, uint8_t p20, uint8_t p21, R4SdkTransportSlot p22, R4SdkTransportSlot p23, R4SdkTransportSlot p24, R4SdkTransportSlot p25, R4SdkTransportSlot p26) {
 R4SdkTransportSlot a[27]={0};
 a[0] = p0;
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = p2;
 a[3] = p3;
 a[4] = (R4SdkTransportSlot){.ptr=(void *)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = p7;
 a[8] = p8;
 a[9] = p9;
 a[10] = p10;
 a[11] = (R4SdkTransportSlot){.ptr=(void *)p11,.length=n11,.flags=R4SDKTRANSPORT_PRESENT};
 a[12] = p12;
 a[13] = (R4SdkTransportSlot){.ptr=(void *)p13,.length=n13,.flags=R4SDKTRANSPORT_PRESENT};
 a[14] = (R4SdkTransportSlot){.ptr=(void *)p14,.length=n14,.flags=R4SDKTRANSPORT_PRESENT};
 a[15] = (R4SdkTransportSlot){.ptr=(void *)p15,.length=n15,.flags=R4SDKTRANSPORT_PRESENT};
 a[16] = (R4SdkTransportSlot){.ptr=(void *)p16,.length=n16,.flags=R4SDKTRANSPORT_PRESENT};
 a[17] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p17,.flags=R4SDKTRANSPORT_PRESENT};
 a[18] = (R4SdkTransportSlot){.ptr=(void *)p18,.length=n18,.flags=R4SDKTRANSPORT_PRESENT};
 a[19] = (R4SdkTransportSlot){.ptr=(void *)p19,.length=n19,.flags=R4SDKTRANSPORT_PRESENT};
 a[20] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p20,.flags=R4SDKTRANSPORT_PRESENT};
 a[21] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p21,.flags=R4SDKTRANSPORT_PRESENT};
 a[22] = p22;
 a[23] = p23;
 a[24] = p24;
 a[25] = p25;
 a[26] = p26;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,5u,a,27u,output);
}
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_sessions(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_sessions(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_network_partition(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_network_partition(R4SdkTransportFetchOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_absolute_deadline(const R4SdkTransportFetchOptions *self, R4SdkTransportRequestDeadline *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,2u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_absolute_deadline(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_stats(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_stats(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_timeout(const R4SdkTransportFetchOptions *self, R4Timeout *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,4u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_timeout(R4SdkTransportFetchOptions *self, const R4Timeout * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_redirect_limit(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_redirect_limit(R4SdkTransportFetchOptions *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_redirect(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_redirect(R4SdkTransportFetchOptions *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_entropy(const R4SdkTransportFetchOptions *self, R4SdkWebNativeValue151 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,7u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_entropy(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_stop(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,8u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_stop(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,8u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_progress(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,9u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_progress(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,9u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_progress_context(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,10u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_progress_context(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,10u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_cookie(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,11u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_cookie(R4SdkTransportFetchOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,11u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_initial_cookie(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,12u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_initial_cookie(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,12u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_origin(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,13u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_origin(R4SdkTransportFetchOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,13u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_headers(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,14u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_headers(R4SdkTransportFetchOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,14u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_conditional_headers(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,15u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_conditional_headers(R4SdkTransportFetchOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,15u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_cache_headers(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,16u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_cache_headers(R4SdkTransportFetchOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,16u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_method(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,17u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_method(R4SdkTransportFetchOptions *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,17u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_content_type(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,18u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_content_type(R4SdkTransportFetchOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,18u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_body(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,19u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_body(R4SdkTransportFetchOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,19u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_cors(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,20u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_cors(R4SdkTransportFetchOptions *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,20u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_credentials_include(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,21u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_credentials_include(R4SdkTransportFetchOptions *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,21u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_cookie_provider(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,22u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_cookie_provider(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,22u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_cookie_sink(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,23u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_cookie_sink(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,23u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_cookie_context(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,24u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_cookie_context(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,24u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_target_authorizer(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,25u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_target_authorizer(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,25u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_get_target_authorization_context(const R4SdkTransportFetchOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,26u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_set_target_authorization_context(R4SdkTransportFetchOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,5u,26u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchOptions_inspectNative(const R4SdkTransportFetchOptions *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,5u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue6_create(R4SdkTransportNativeValue6 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,6u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue6_inspectNative(const R4SdkTransportNativeValue6 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,6u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue7_create(R4SdkTransportNativeValue7 *output, R4SdkTransportSessionPool * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,7u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue7_inspectNative(const R4SdkTransportNativeValue7 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,7u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_create(R4SdkTransportSessionPool *output) {
 R4SdkTransportSlot a[3]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,8u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportSessionPool_from_fields(R4SdkTransportSessionPool *output, const R4SdkTransportNativeValue9 * p0, const R4SdkTransportNativeValue23 * p1, uint64_t p2) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,8u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportSessionPool_get_entries(const R4SdkTransportSessionPool *self, R4SdkTransportNativeValue9 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,8u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_set_entries(R4SdkTransportSessionPool *self, const R4SdkTransportNativeValue9 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,8u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_get_preflights(const R4SdkTransportSessionPool *self, R4SdkTransportNativeValue23 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,8u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_set_preflights(R4SdkTransportSessionPool *self, const R4SdkTransportNativeValue23 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,8u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_get_serial(const R4SdkTransportSessionPool *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,8u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_set_serial(R4SdkTransportSessionPool *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,8u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_inspectNative(const R4SdkTransportSessionPool *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,8u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue9_create(R4SdkTransportNativeValue9 *output, const R4SdkTransportNativeValue9 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,9u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue9_inspectNative(const R4SdkTransportNativeValue9 *self, R4SdkTransportNativeValue9 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,9u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_create(R4SdkTransportSessionPool_Entry *output) {
 R4SdkTransportSlot a[7]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,10u,a,7u,output);
}
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_from_fields(R4SdkTransportSessionPool_Entry *output, const R4SdkTransportNativeValue11 * p0, uint64_t p1, R4SdkTransportSlot p2, R4SdkTransportSlot p3, uint8_t p4, uint64_t p5, uint64_t p6) {
 R4SdkTransportSlot a[7]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = p2;
 a[3] = p3;
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,10u,a,7u,output);
}
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_get_key(const R4SdkTransportSessionPool_Entry *self, R4SdkTransportNativeValue11 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_set_key(R4SdkTransportSessionPool_Entry *self, const R4SdkTransportNativeValue11 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_get_key_len(const R4SdkTransportSessionPool_Entry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_set_key_len(R4SdkTransportSessionPool_Entry *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_get_socket(const R4SdkTransportSessionPool_Entry *self, R4SdkTransportNative_app_network_TcpSocket *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,2u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_set_socket(R4SdkTransportSessionPool_Entry *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_get_tls(const R4SdkTransportSessionPool_Entry *self, R4SdkTransportTlsSession *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,3u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_set_tls(R4SdkTransportSessionPool_Entry *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_get_leased(const R4SdkTransportSessionPool_Entry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_set_leased(R4SdkTransportSessionPool_Entry *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_get_expires(const R4SdkTransportSessionPool_Entry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_set_expires(R4SdkTransportSessionPool_Entry *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_get_used(const R4SdkTransportSessionPool_Entry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_set_used(R4SdkTransportSessionPool_Entry *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,10u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Entry_inspectNative(const R4SdkTransportSessionPool_Entry *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,10u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue11_create(R4SdkTransportNativeValue11 *output, const R4SdkTransportNativeValue11 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,11u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue11_inspectNative(const R4SdkTransportNativeValue11 *self, R4SdkTransportNativeValue11 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,11u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue12_create(R4SdkTransportNativeValue12 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,12u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue12_inspectNative(const R4SdkTransportNativeValue12 *self, R4SdkTransportNative_app_network_TcpSocket *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,12u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_create(R4SdkTransportNative_app_network_TcpSocket *output, const R4SdkTransportNative_app_network_Network * p0) {
 R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,13u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_from_fields(R4SdkTransportNative_app_network_TcpSocket *output, const R4SdkTransportNative_app_network_Network * p0, uint32_t p1, uint8_t p2, const R4SdkTransportNative_app_network_SocketAddress * p3) {
 R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,13u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_get_network(const R4SdkTransportNative_app_network_TcpSocket *self, R4SdkTransportNative_app_network_Network *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,13u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_set_network(R4SdkTransportNative_app_network_TcpSocket *self, const R4SdkTransportNative_app_network_Network * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,13u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_get_raw(const R4SdkTransportNative_app_network_TcpSocket *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,13u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_set_raw(R4SdkTransportNative_app_network_TcpSocket *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,13u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_get_owned(const R4SdkTransportNative_app_network_TcpSocket *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,13u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_set_owned(R4SdkTransportNative_app_network_TcpSocket *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,13u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_get_remote(const R4SdkTransportNative_app_network_TcpSocket *self, R4SdkTransportNative_app_network_SocketAddress *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,13u,3u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_set_remote(R4SdkTransportNative_app_network_TcpSocket *self, const R4SdkTransportNative_app_network_SocketAddress * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,13u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpSocket_inspectNative(const R4SdkTransportNative_app_network_TcpSocket *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,13u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_create(R4SdkTransportNative_app_network_Network *output, const R4SdkTransportNative_r4sys_Context * p0, const R4SdkTransportNative_r4net_Context * p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,14u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_from_fields(R4SdkTransportNative_app_network_Network *output, const R4SdkTransportNative_r4sys_Context * p0, const R4SdkTransportNative_r4net_Context * p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,14u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_get_sys(const R4SdkTransportNative_app_network_Network *self, R4SdkTransportNative_r4sys_Context *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,14u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_set_sys(R4SdkTransportNative_app_network_Network *self, const R4SdkTransportNative_r4sys_Context * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,14u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_get_net(const R4SdkTransportNative_app_network_Network *self, R4SdkTransportNative_r4net_Context *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,14u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_set_net(R4SdkTransportNative_app_network_Network *self, const R4SdkTransportNative_r4net_Context * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,14u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Network_inspectNative(const R4SdkTransportNative_app_network_Network *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,14u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketAddress_create(R4SdkTransportNative_app_network_SocketAddress *output, const R4SdkTransportNative_app_network_Ipv4Address * p0, uint16_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,17u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketAddress_from_fields(R4SdkTransportNative_app_network_SocketAddress *output, const R4SdkTransportNative_app_network_Ipv4Address * p0, uint16_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,17u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketAddress_get_address(const R4SdkTransportNative_app_network_SocketAddress *self, R4SdkTransportNative_app_network_Ipv4Address *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,17u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketAddress_set_address(R4SdkTransportNative_app_network_SocketAddress *self, const R4SdkTransportNative_app_network_Ipv4Address * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,17u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketAddress_get_port(const R4SdkTransportNative_app_network_SocketAddress *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,17u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketAddress_set_port(R4SdkTransportNative_app_network_SocketAddress *self, uint16_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,17u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketAddress_inspectNative(const R4SdkTransportNative_app_network_SocketAddress *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,17u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Ipv4Address_create(R4SdkTransportNative_app_network_Ipv4Address *output) {
 R4SdkTransportSlot a[1]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,18u,a,1u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Ipv4Address_from_fields(R4SdkTransportNative_app_network_Ipv4Address *output, const R4SdkTransportNativeValue19 * p0) {
 R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,18u,a,1u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Ipv4Address_get_octets(const R4SdkTransportNative_app_network_Ipv4Address *self, R4SdkTransportNativeValue19 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,18u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Ipv4Address_set_octets(R4SdkTransportNative_app_network_Ipv4Address *self, const R4SdkTransportNativeValue19 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,18u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Ipv4Address_inspectNative(const R4SdkTransportNative_app_network_Ipv4Address *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,18u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue19_create(R4SdkTransportNativeValue19 *output, const R4SdkTransportNativeValue19 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,19u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue19_inspectNative(const R4SdkTransportNativeValue19 *self, R4SdkTransportNativeValue19 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,19u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue20_create(R4SdkTransportNativeValue20 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,20u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue20_inspectNative(const R4SdkTransportNativeValue20 *self, R4SdkTransportTlsSession *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,20u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportTlsSession_create(R4SdkTransportTlsSession *output, const R4SdkTransportNativeValue22 * p0) {
 R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,21u,a,1u,output);
}
static inline R4SdkTransportSlot R4SdkTransportTlsSession_from_fields(R4SdkTransportTlsSession *output, const R4SdkTransportNativeValue22 * p0) {
 R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,21u,a,1u,output);
}
static inline R4SdkTransportSlot R4SdkTransportTlsSession_get_stream_state(const R4SdkTransportTlsSession *self, R4SdkTransportNativeValue22 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,21u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportTlsSession_set_stream_state(R4SdkTransportTlsSession *self, const R4SdkTransportNativeValue22 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,21u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportTlsSession_inspectNative(const R4SdkTransportTlsSession *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,21u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue22_create(R4SdkTransportNativeValue22 *output, const R4SdkTransportNativeValue22 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,22u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue22_inspectNative(const R4SdkTransportNativeValue22 *self, R4SdkTransportNativeValue22 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,22u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue23_create(R4SdkTransportNativeValue23 *output, const R4SdkTransportNativeValue23 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,23u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue23_inspectNative(const R4SdkTransportNativeValue23 *self, R4SdkTransportNativeValue23 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,23u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Preflight_create(R4SdkTransportSessionPool_Preflight *output) {
 R4SdkTransportSlot a[4]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,24u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Preflight_from_fields(R4SdkTransportSessionPool_Preflight *output, const R4SdkWebNativeValue367 * p0, uint64_t p1, uint64_t p2, uint64_t p3) {
 R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,24u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Preflight_get_key(const R4SdkTransportSessionPool_Preflight *self, R4SdkWebNativeValue367 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,24u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Preflight_set_key(R4SdkTransportSessionPool_Preflight *self, const R4SdkWebNativeValue367 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,24u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Preflight_get_key_len(const R4SdkTransportSessionPool_Preflight *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,24u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Preflight_set_key_len(R4SdkTransportSessionPool_Preflight *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,24u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Preflight_get_expires(const R4SdkTransportSessionPool_Preflight *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,24u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Preflight_set_expires(R4SdkTransportSessionPool_Preflight *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,24u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Preflight_get_used(const R4SdkTransportSessionPool_Preflight *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,24u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Preflight_set_used(R4SdkTransportSessionPool_Preflight *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,24u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportSessionPool_Preflight_inspectNative(const R4SdkTransportSessionPool_Preflight *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,24u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue27_create(R4SdkTransportNativeValue27 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,27u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue27_inspectNative(const R4SdkTransportNativeValue27 *self, R4SdkTransportRequestDeadline *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,27u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue28_create(R4SdkTransportNativeValue28 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,28u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue28_inspectNative(const R4SdkTransportNativeValue28 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,28u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue29_create(R4SdkTransportNativeValue29 *output, R4SdkTransportTransportStats * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,29u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue29_inspectNative(const R4SdkTransportNativeValue29 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,29u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue31_create(R4SdkTransportNativeValue31 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,31u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue31_inspectNative(const R4SdkTransportNativeValue31 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,31u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue32_create(R4SdkTransportNativeValue32 *output, const R4StopFlag * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,32u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue32_inspectNative(const R4SdkTransportNativeValue32 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,32u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue34_create(R4SdkTransportNativeValue34 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,34u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue34_inspectNative(const R4SdkTransportNativeValue34 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,34u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue38_create(R4SdkTransportNativeValue38 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,38u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue38_inspectNative(const R4SdkTransportNativeValue38 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,38u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue39_create(R4SdkTransportNativeValue39 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,39u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue39_inspectNative(const R4SdkTransportNativeValue39 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,39u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue40_create(R4SdkTransportNativeValue40 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,40u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue40_inspectNative(const R4SdkTransportNativeValue40 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,40u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_create(R4SdkTransportFetchResponse *output, uint16_t p0, uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, R4SdkTransportSlot p3, R4SdkTransportSlot p4, R4SdkTransportSlot p5, uint8_t p6, R4SdkTransportSlot p7, const R4SdkWebNativeValue373 * p8, uint64_t p9, uint8_t p10, uint8_t p11, uint8_t p12, const R4SdkTransportFinalUrl * p13) {
 R4SdkTransportSlot a[14]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = p3;
 a[4] = p4;
 a[5] = p5;
 a[6] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = p7;
 a[8] = (R4SdkTransportSlot){.ptr=(void *)p8,.flags=R4SDKTRANSPORT_PRESENT};
 a[9] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDKTRANSPORT_PRESENT};
 a[10] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4SDKTRANSPORT_PRESENT};
 a[11] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4SDKTRANSPORT_PRESENT};
 a[12] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4SDKTRANSPORT_PRESENT};
 a[13] = (R4SdkTransportSlot){.ptr=(void *)p13,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,41u,a,14u,output);
}
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_from_fields(R4SdkTransportFetchResponse *output, uint16_t p0, uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, R4SdkTransportSlot p3, R4SdkTransportSlot p4, R4SdkTransportSlot p5, uint8_t p6, R4SdkTransportSlot p7, const R4SdkWebNativeValue373 * p8, uint64_t p9, uint8_t p10, uint8_t p11, uint8_t p12, const R4SdkTransportFinalUrl * p13) {
 R4SdkTransportSlot a[14]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = p3;
 a[4] = p4;
 a[5] = p5;
 a[6] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = p7;
 a[8] = (R4SdkTransportSlot){.ptr=(void *)p8,.flags=R4SDKTRANSPORT_PRESENT};
 a[9] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDKTRANSPORT_PRESENT};
 a[10] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4SDKTRANSPORT_PRESENT};
 a[11] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4SDKTRANSPORT_PRESENT};
 a[12] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4SDKTRANSPORT_PRESENT};
 a[13] = (R4SdkTransportSlot){.ptr=(void *)p13,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,41u,a,14u,output);
}
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_status(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_status(R4SdkTransportFetchResponse *self, uint16_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_body(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_body(R4SdkTransportFetchResponse *self, uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_headers(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_headers(R4SdkTransportFetchResponse *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_content_type(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_content_type(R4SdkTransportFetchResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_content_security_policy(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_content_security_policy(R4SdkTransportFetchResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_access_control_allow_origin(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_access_control_allow_origin(R4SdkTransportFetchResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_access_control_allow_credentials(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_access_control_allow_credentials(R4SdkTransportFetchResponse *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_set_cookie(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,7u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_set_cookie(R4SdkTransportFetchResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_set_cookies(const R4SdkTransportFetchResponse *self, R4SdkWebNativeValue373 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,8u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_set_cookies(R4SdkTransportFetchResponse *self, const R4SdkWebNativeValue373 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,8u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_set_cookie_count(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,9u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_set_cookie_count(R4SdkTransportFetchResponse *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,9u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_redirects(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,10u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_redirects(R4SdkTransportFetchResponse *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,10u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_manual_redirect(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,11u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_manual_redirect(R4SdkTransportFetchResponse *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,11u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_secure(const R4SdkTransportFetchResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,12u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_secure(R4SdkTransportFetchResponse *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,12u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_get_final_url(const R4SdkTransportFetchResponse *self, R4SdkTransportFinalUrl *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,13u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_set_final_url(R4SdkTransportFetchResponse *self, const R4SdkTransportFinalUrl * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,41u,13u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResponse_inspectNative(const R4SdkTransportFetchResponse *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,41u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportFinalUrl_create(R4SdkTransportFinalUrl *output) {
 R4SdkTransportSlot a[2]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,44u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportFinalUrl_from_fields(R4SdkTransportFinalUrl *output, const R4SdkTransportNativeValue45 * p0, uint64_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,44u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportFinalUrl_get_storage(const R4SdkTransportFinalUrl *self, R4SdkTransportNativeValue45 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,44u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportFinalUrl_set_storage(R4SdkTransportFinalUrl *self, const R4SdkTransportNativeValue45 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,44u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFinalUrl_get_len(const R4SdkTransportFinalUrl *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,44u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFinalUrl_set_len(R4SdkTransportFinalUrl *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,44u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFinalUrl_inspectNative(const R4SdkTransportFinalUrl *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,44u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue45_create(R4SdkTransportNativeValue45 *output, const R4SdkTransportNativeValue45 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,45u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue45_inspectNative(const R4SdkTransportNativeValue45 *self, R4SdkTransportNativeValue45 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,45u,(void *)self,output); }
#define R4SdkTransportFetchResult_TAG_response 0u
#define R4SdkTransportFetchResult_TAG_failure 1u
static inline R4SdkTransportSlot R4SdkTransportFetchResult_get_response(const R4SdkTransportFetchResult *self, R4SdkTransportFetchResponse *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,46u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportFetchResult_set_response(R4SdkTransportFetchResult *self, const R4SdkTransportFetchResponse * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,46u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResult_get_failure(const R4SdkTransportFetchResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,46u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResult_set_failure(R4SdkTransportFetchResult *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,46u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchResult_inspectNative(const R4SdkTransportFetchResult *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,46u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_web_FetchResult____union__tag_type___create(R4SdkTransportNative__typeInfo_app_web_FetchResult____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,47u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_web_FetchResult____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_app_web_FetchResult____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,47u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadSink_create(R4SdkTransportDownloadSink *output, R4SdkTransportSlot p0, uintptr_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = p0;
 a[1] = (R4SdkTransportSlot){.ptr=(void *)(uintptr_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,48u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportDownloadSink_from_fields(R4SdkTransportDownloadSink *output, R4SdkTransportSlot p0, uintptr_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = p0;
 a[1] = (R4SdkTransportSlot){.ptr=(void *)(uintptr_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,48u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportDownloadSink_get_context(const R4SdkTransportDownloadSink *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,48u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadSink_set_context(R4SdkTransportDownloadSink *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,48u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadSink_get_write_fn(const R4SdkTransportDownloadSink *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,48u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadSink_set_write_fn(R4SdkTransportDownloadSink *self, uintptr_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,48u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadSink_inspectNative(const R4SdkTransportDownloadSink *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,48u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_create(R4SdkTransportDownloadOptions *output) {
 R4SdkTransportSlot a[12]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 a[7].flags=R4SDKTRANSPORT_DEFAULT;
 a[8].flags=R4SDKTRANSPORT_DEFAULT;
 a[9].flags=R4SDKTRANSPORT_DEFAULT;
 a[10].flags=R4SDKTRANSPORT_DEFAULT;
 a[11].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,49u,a,12u,output);
}
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_from_fields(R4SdkTransportDownloadOptions *output, const R4Timeout * p0, uint8_t p1, R4SdkTransportSlot p2, R4SdkTransportSlot p3, R4SdkTransportSlot p4, R4SdkTransportSlot p5, const uint8_t * p6, uintptr_t n6, uint32_t p7, uint64_t p8, R4SdkTransportSlot p9, R4SdkTransportSlot p10, R4SdkTransportSlot p11) {
 R4SdkTransportSlot a[12]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = p2;
 a[3] = p3;
 a[4] = p4;
 a[5] = p5;
 a[6] = (R4SdkTransportSlot){.ptr=(void *)p6,.length=n6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDKTRANSPORT_PRESENT};
 a[8] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDKTRANSPORT_PRESENT};
 a[9] = p9;
 a[10] = p10;
 a[11] = p11;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,49u,a,12u,output);
}
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_timeout(const R4SdkTransportDownloadOptions *self, R4Timeout *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_timeout(R4SdkTransportDownloadOptions *self, const R4Timeout * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_redirect_limit(const R4SdkTransportDownloadOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_redirect_limit(R4SdkTransportDownloadOptions *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_entropy(const R4SdkTransportDownloadOptions *self, R4SdkWebNativeValue151 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,2u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_entropy(R4SdkTransportDownloadOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_stop(const R4SdkTransportDownloadOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_stop(R4SdkTransportDownloadOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_progress(const R4SdkTransportDownloadOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_progress(R4SdkTransportDownloadOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_progress_context(const R4SdkTransportDownloadOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_progress_context(R4SdkTransportDownloadOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_headers(const R4SdkTransportDownloadOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_headers(R4SdkTransportDownloadOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_method(const R4SdkTransportDownloadOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,7u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_method(R4SdkTransportDownloadOptions *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_resume_from(const R4SdkTransportDownloadOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,8u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_resume_from(R4SdkTransportDownloadOptions *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,8u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_expected_size(const R4SdkTransportDownloadOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,9u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_expected_size(R4SdkTransportDownloadOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,9u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_target_authorizer(const R4SdkTransportDownloadOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,10u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_target_authorizer(R4SdkTransportDownloadOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,10u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_get_target_authorization_context(const R4SdkTransportDownloadOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,11u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_set_target_authorization_context(R4SdkTransportDownloadOptions *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,49u,11u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadOptions_inspectNative(const R4SdkTransportDownloadOptions *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,49u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue50_create(R4SdkTransportNativeValue50 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,50u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue50_inspectNative(const R4SdkTransportNativeValue50 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,50u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue51_create(R4SdkTransportNativeValue51 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,51u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue51_inspectNative(const R4SdkTransportNativeValue51 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,51u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_create(R4SdkTransportDownloadResponse *output, uint16_t p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint8_t p5, uint8_t p6, const R4SdkTransportFinalUrl * p7) {
 R4SdkTransportSlot a[8]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = (R4SdkTransportSlot){.ptr=(void *)p7,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,52u,a,8u,output);
}
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_from_fields(R4SdkTransportDownloadResponse *output, uint16_t p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint8_t p5, uint8_t p6, const R4SdkTransportFinalUrl * p7) {
 R4SdkTransportSlot a[8]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = (R4SdkTransportSlot){.ptr=(void *)p7,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,52u,a,8u,output);
}
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_get_status(const R4SdkTransportDownloadResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_set_status(R4SdkTransportDownloadResponse *self, uint16_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_get_content_length(const R4SdkTransportDownloadResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_set_content_length(R4SdkTransportDownloadResponse *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_get_total_size(const R4SdkTransportDownloadResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_set_total_size(R4SdkTransportDownloadResponse *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_get_transferred(const R4SdkTransportDownloadResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_set_transferred(R4SdkTransportDownloadResponse *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_get_resumed_from(const R4SdkTransportDownloadResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_set_resumed_from(R4SdkTransportDownloadResponse *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_get_redirects(const R4SdkTransportDownloadResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_set_redirects(R4SdkTransportDownloadResponse *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_get_secure(const R4SdkTransportDownloadResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_set_secure(R4SdkTransportDownloadResponse *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_get_final_url(const R4SdkTransportDownloadResponse *self, R4SdkTransportFinalUrl *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,7u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_set_final_url(R4SdkTransportDownloadResponse *self, const R4SdkTransportFinalUrl * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,52u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResponse_inspectNative(const R4SdkTransportDownloadResponse *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,52u,(void *)self,0); }
#define R4SdkTransportDownloadResult_TAG_response 0u
#define R4SdkTransportDownloadResult_TAG_range_not_satisfiable 1u
#define R4SdkTransportDownloadResult_TAG_failure 2u
static inline R4SdkTransportSlot R4SdkTransportDownloadResult_get_response(const R4SdkTransportDownloadResult *self, R4SdkTransportDownloadResponse *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,53u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResult_set_response(R4SdkTransportDownloadResult *self, const R4SdkTransportDownloadResponse * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,53u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResult_get_range_not_satisfiable(const R4SdkTransportDownloadResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,53u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResult_set_range_not_satisfiable(R4SdkTransportDownloadResult *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,53u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResult_get_failure(const R4SdkTransportDownloadResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,53u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResult_set_failure(R4SdkTransportDownloadResult *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,53u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDownloadResult_inspectNative(const R4SdkTransportDownloadResult *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,53u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_web_DownloadResult____union__tag_type___create(R4SdkTransportNative__typeInfo_app_web_DownloadResult____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,54u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_web_DownloadResult____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_app_web_DownloadResult____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,54u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportWebTransport_create(R4SdkTransportWebTransport *output, const R4SdkTransportNative_app_network_Network * p0, const R4SdkTransportNative_r4dev_Context * p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,55u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportWebTransport_from_fields(R4SdkTransportWebTransport *output, const R4SdkTransportNative_app_network_Network * p0, const R4SdkTransportNative_r4dev_Context * p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,55u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportWebTransport_get_network(const R4SdkTransportWebTransport *self, R4SdkTransportNative_app_network_Network *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,55u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportWebTransport_set_network(R4SdkTransportWebTransport *self, const R4SdkTransportNative_app_network_Network * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,55u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportWebTransport_get_dev(const R4SdkTransportWebTransport *self, R4SdkTransportNative_r4dev_Context *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,55u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportWebTransport_set_dev(R4SdkTransportWebTransport *self, const R4SdkTransportNative_r4dev_Context * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,55u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportWebTransport_inspectNative(const R4SdkTransportWebTransport *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,55u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue57_create(R4SdkTransportNativeValue57 *output, R4SdkWebNativeValue151 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,57u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue57_inspectNative(const R4SdkTransportNativeValue57 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,57u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpScheme_create(R4SdkTransportHttpScheme *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,59u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpScheme_inspectNative(const R4SdkTransportHttpScheme *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,59u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpUrlError_create(R4SdkTransportHttpUrlError *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,60u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpUrlError_inspectNative(const R4SdkTransportHttpUrlError *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,60u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_create(R4SdkTransportHttpParsedUrl *output, uint32_t p0, const uint8_t * p1, uintptr_t n1, uint16_t p2, const uint8_t * p3, uintptr_t n3, uint8_t p4, uint8_t p5) {
 R4SdkTransportSlot a[6]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,61u,a,6u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_from_fields(R4SdkTransportHttpParsedUrl *output, uint32_t p0, const uint8_t * p1, uintptr_t n1, uint16_t p2, const uint8_t * p3, uintptr_t n3, uint8_t p4, uint8_t p5) {
 R4SdkTransportSlot a[6]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,61u,a,6u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_get_scheme(const R4SdkTransportHttpParsedUrl *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_set_scheme(R4SdkTransportHttpParsedUrl *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_get_host(const R4SdkTransportHttpParsedUrl *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_set_host(R4SdkTransportHttpParsedUrl *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_get_port(const R4SdkTransportHttpParsedUrl *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_set_port(R4SdkTransportHttpParsedUrl *self, uint16_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_get_path(const R4SdkTransportHttpParsedUrl *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_set_path(R4SdkTransportHttpParsedUrl *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_get_explicit_port(const R4SdkTransportHttpParsedUrl *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_set_explicit_port(R4SdkTransportHttpParsedUrl *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_get_query_only(const R4SdkTransportHttpParsedUrl *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_set_query_only(R4SdkTransportHttpParsedUrl *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,61u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedUrl_inspectNative(const R4SdkTransportHttpParsedUrl *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,61u,(void *)self,0); }
#define R4SdkTransportHttpUrlResult_TAG_value 0u
#define R4SdkTransportHttpUrlResult_TAG_failure 1u
static inline R4SdkTransportSlot R4SdkTransportHttpUrlResult_get_value(const R4SdkTransportHttpUrlResult *self, R4SdkTransportHttpParsedUrl *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,62u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpUrlResult_set_value(R4SdkTransportHttpUrlResult *self, const R4SdkTransportHttpParsedUrl * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,62u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpUrlResult_get_failure(const R4SdkTransportHttpUrlResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,62u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpUrlResult_set_failure(R4SdkTransportHttpUrlResult *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,62u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpUrlResult_inspectNative(const R4SdkTransportHttpUrlResult *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,62u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_http_UrlResult____union__tag_type___create(R4SdkTransportNative__typeInfo_http_UrlResult____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,63u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_http_UrlResult____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_http_UrlResult____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,63u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_create(R4SdkTransportHttpRequestOptions *output) {
 R4SdkTransportSlot a[8]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 a[7].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,64u,a,8u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_from_fields(R4SdkTransportHttpRequestOptions *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, const uint8_t * p4, uintptr_t n4, uint8_t p5, const uint8_t * p6, uintptr_t n6, const uint8_t * p7, uintptr_t n7) {
 R4SdkTransportSlot a[8]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.ptr=(void *)p6,.length=n6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = (R4SdkTransportSlot){.ptr=(void *)p7,.length=n7,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,64u,a,8u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_get_user_agent(const R4SdkTransportHttpRequestOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_set_user_agent(R4SdkTransportHttpRequestOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_get_accept(const R4SdkTransportHttpRequestOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_set_accept(R4SdkTransportHttpRequestOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_get_cookie(const R4SdkTransportHttpRequestOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_set_cookie(R4SdkTransportHttpRequestOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_get_origin(const R4SdkTransportHttpRequestOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_set_origin(R4SdkTransportHttpRequestOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_get_headers(const R4SdkTransportHttpRequestOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_set_headers(R4SdkTransportHttpRequestOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_get_connection_close(const R4SdkTransportHttpRequestOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_set_connection_close(R4SdkTransportHttpRequestOptions *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_get_content_type(const R4SdkTransportHttpRequestOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_set_content_type(R4SdkTransportHttpRequestOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_get_body(const R4SdkTransportHttpRequestOptions *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,7u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_set_body(R4SdkTransportHttpRequestOptions *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,64u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRequestOptions_inspectNative(const R4SdkTransportHttpRequestOptions *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,64u,(void *)self,0); }
#define R4SdkTransportHttpBuildResult_TAG_bytes 0u
#define R4SdkTransportHttpBuildResult_TAG_invalid_url 1u
#define R4SdkTransportHttpBuildResult_TAG_output_too_small 2u
static inline R4SdkTransportSlot R4SdkTransportHttpBuildResult_get_bytes(const R4SdkTransportHttpBuildResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,65u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpBuildResult_set_bytes(R4SdkTransportHttpBuildResult *self, uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,65u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpBuildResult_get_invalid_url(const R4SdkTransportHttpBuildResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,65u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpBuildResult_set_invalid_url(R4SdkTransportHttpBuildResult *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,65u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpBuildResult_get_output_too_small(const R4SdkTransportHttpBuildResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,65u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpBuildResult_set_output_too_small(R4SdkTransportHttpBuildResult *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,65u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpBuildResult_inspectNative(const R4SdkTransportHttpBuildResult *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,65u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_http_BuildResult____union__tag_type___create(R4SdkTransportNative__typeInfo_http_BuildResult____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,66u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_http_BuildResult____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_http_BuildResult____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,66u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpTransfer_create(R4SdkTransportHttpTransfer *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,67u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpTransfer_inspectNative(const R4SdkTransportHttpTransfer *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,67u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpContentRange_create(R4SdkTransportHttpContentRange *output, uint8_t p0, uint64_t p1, uint64_t p2, uint64_t p3) {
 R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,68u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpContentRange_from_fields(R4SdkTransportHttpContentRange *output, uint8_t p0, uint64_t p1, uint64_t p2, uint64_t p3) {
 R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,68u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpContentRange_get_satisfied(const R4SdkTransportHttpContentRange *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,68u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpContentRange_set_satisfied(R4SdkTransportHttpContentRange *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,68u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpContentRange_get_start(const R4SdkTransportHttpContentRange *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,68u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpContentRange_set_start(R4SdkTransportHttpContentRange *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,68u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpContentRange_get_end(const R4SdkTransportHttpContentRange *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,68u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpContentRange_set_end(R4SdkTransportHttpContentRange *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,68u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpContentRange_get_total(const R4SdkTransportHttpContentRange *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,68u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpContentRange_set_total(R4SdkTransportHttpContentRange *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,68u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpContentRange_inspectNative(const R4SdkTransportHttpContentRange *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,68u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseError_create(R4SdkTransportHttpResponseError *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,69u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseError_inspectNative(const R4SdkTransportHttpResponseError *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,69u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_create(R4SdkTransportHttpResponse *output, uint16_t p0, uint32_t p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, R4SdkTransportSlot p4, R4SdkTransportSlot p5, R4SdkTransportSlot p6, R4SdkTransportSlot p7, uint8_t p8, R4SdkTransportSlot p9, const R4SdkWebNativeValue373 * p10, uint64_t p11, R4SdkTransportSlot p12, uint64_t p13) {
 R4SdkTransportSlot a[14]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = p4;
 a[5] = p5;
 a[6] = p6;
 a[7] = p7;
 a[8] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDKTRANSPORT_PRESENT};
 a[9] = p9;
 a[10] = (R4SdkTransportSlot){.ptr=(void *)p10,.flags=R4SDKTRANSPORT_PRESENT};
 a[11] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4SDKTRANSPORT_PRESENT};
 a[12] = p12;
 a[13] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,70u,a,14u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_from_fields(R4SdkTransportHttpResponse *output, uint16_t p0, uint32_t p1, uint8_t * p2, uintptr_t n2, const uint8_t * p3, uintptr_t n3, R4SdkTransportSlot p4, R4SdkTransportSlot p5, R4SdkTransportSlot p6, R4SdkTransportSlot p7, uint8_t p8, R4SdkTransportSlot p9, const R4SdkWebNativeValue373 * p10, uint64_t p11, R4SdkTransportSlot p12, uint64_t p13) {
 R4SdkTransportSlot a[14]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = p4;
 a[5] = p5;
 a[6] = p6;
 a[7] = p7;
 a[8] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDKTRANSPORT_PRESENT};
 a[9] = p9;
 a[10] = (R4SdkTransportSlot){.ptr=(void *)p10,.flags=R4SDKTRANSPORT_PRESENT};
 a[11] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4SDKTRANSPORT_PRESENT};
 a[12] = p12;
 a[13] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,70u,a,14u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_status(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_status(R4SdkTransportHttpResponse *self, uint16_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_transfer(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_transfer(R4SdkTransportHttpResponse *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_body(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_body(R4SdkTransportHttpResponse *self, uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_headers(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_headers(R4SdkTransportHttpResponse *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_location(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_location(R4SdkTransportHttpResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_content_type(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_content_type(R4SdkTransportHttpResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_content_security_policy(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_content_security_policy(R4SdkTransportHttpResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_access_control_allow_origin(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,7u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_access_control_allow_origin(R4SdkTransportHttpResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_access_control_allow_credentials(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,8u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_access_control_allow_credentials(R4SdkTransportHttpResponse *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,8u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_set_cookie(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,9u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_set_cookie(R4SdkTransportHttpResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,9u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_set_cookies(const R4SdkTransportHttpResponse *self, R4SdkWebNativeValue373 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,10u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_set_cookies(R4SdkTransportHttpResponse *self, const R4SdkWebNativeValue373 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,10u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_set_cookie_count(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,11u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_set_cookie_count(R4SdkTransportHttpResponse *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,11u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_content_range(const R4SdkTransportHttpResponse *self, R4SdkTransportHttpContentRange *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,12u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_content_range(R4SdkTransportHttpResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,12u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_get_consumed(const R4SdkTransportHttpResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,13u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_set_consumed(R4SdkTransportHttpResponse *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,70u,13u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponse_inspectNative(const R4SdkTransportHttpResponse *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,70u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue71_create(R4SdkTransportNativeValue71 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,71u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue71_inspectNative(const R4SdkTransportNativeValue71 *self, R4SdkTransportHttpContentRange *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,71u,(void *)self,output); }
#define R4SdkTransportHttpDecodeResult_TAG_complete 0u
#define R4SdkTransportHttpDecodeResult_TAG_need_more 1u
#define R4SdkTransportHttpDecodeResult_TAG_aborted 2u
#define R4SdkTransportHttpDecodeResult_TAG_failure 3u
static inline R4SdkTransportSlot R4SdkTransportHttpDecodeResult_get_complete(const R4SdkTransportHttpDecodeResult *self, R4SdkTransportHttpResponse *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,72u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpDecodeResult_set_complete(R4SdkTransportHttpDecodeResult *self, const R4SdkTransportHttpResponse * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,72u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpDecodeResult_get_need_more(const R4SdkTransportHttpDecodeResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,72u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpDecodeResult_set_need_more(R4SdkTransportHttpDecodeResult *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,72u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpDecodeResult_get_aborted(const R4SdkTransportHttpDecodeResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,72u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpDecodeResult_set_aborted(R4SdkTransportHttpDecodeResult *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,72u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpDecodeResult_get_failure(const R4SdkTransportHttpDecodeResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,72u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpDecodeResult_set_failure(R4SdkTransportHttpDecodeResult *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,72u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpDecodeResult_inspectNative(const R4SdkTransportHttpDecodeResult *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,72u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_http_DecodeResult____union__tag_type___create(R4SdkTransportNative__typeInfo_http_DecodeResult____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,73u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_http_DecodeResult____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_http_DecodeResult____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,73u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_create(R4SdkTransportHttpResponseDecoder *output) {
 R4SdkTransportSlot a[15]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 a[7].flags=R4SDKTRANSPORT_DEFAULT;
 a[8].flags=R4SDKTRANSPORT_DEFAULT;
 a[9].flags=R4SDKTRANSPORT_DEFAULT;
 a[10].flags=R4SDKTRANSPORT_DEFAULT;
 a[11].flags=R4SDKTRANSPORT_DEFAULT;
 a[12].flags=R4SDKTRANSPORT_DEFAULT;
 a[13].flags=R4SDKTRANSPORT_DEFAULT;
 a[14].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,74u,a,15u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_from_fields(R4SdkTransportHttpResponseDecoder *output, uint32_t p0, R4SdkTransportSlot p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5, uint64_t p6, uint64_t p7, uint64_t p8, uint64_t p9, uint64_t p10, uint32_t p11, uint8_t p12, uint8_t p13, R4SdkTransportSlot p14) {
 R4SdkTransportSlot a[15]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = p1;
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDKTRANSPORT_PRESENT};
 a[8] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDKTRANSPORT_PRESENT};
 a[9] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDKTRANSPORT_PRESENT};
 a[10] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4SDKTRANSPORT_PRESENT};
 a[11] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4SDKTRANSPORT_PRESENT};
 a[12] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4SDKTRANSPORT_PRESENT};
 a[13] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p13,.flags=R4SDKTRANSPORT_PRESENT};
 a[14] = p14;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,74u,a,15u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_method(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_method(R4SdkTransportHttpResponseDecoder *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_head(const R4SdkTransportHttpResponseDecoder *self, R4SdkTransportHttpParsedHead *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_head(R4SdkTransportHttpResponseDecoder *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_cursor(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_cursor(R4SdkTransportHttpResponseDecoder *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_written(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_written(R4SdkTransportHttpResponseDecoder *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_copied_bytes(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_copied_bytes(R4SdkTransportHttpResponseDecoder *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_seen_input(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_seen_input(R4SdkTransportHttpResponseDecoder *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_header_scan(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_header_scan(R4SdkTransportHttpResponseDecoder *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_line_scan(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,7u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_line_scan(R4SdkTransportHttpResponseDecoder *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_remaining(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,8u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_remaining(R4SdkTransportHttpResponseDecoder *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,8u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_trailer_start(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,9u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_trailer_start(R4SdkTransportHttpResponseDecoder *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,9u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_trailer_count(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,10u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_trailer_count(R4SdkTransportHttpResponseDecoder *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,10u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_phase(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,11u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_phase(R4SdkTransportHttpResponseDecoder *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,11u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_done(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,12u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_done(R4SdkTransportHttpResponseDecoder *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,12u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_cancelled(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,13u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_cancelled(R4SdkTransportHttpResponseDecoder *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,13u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_get_failure(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,14u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_set_failure(R4SdkTransportHttpResponseDecoder *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,74u,14u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpResponseDecoder_inspectNative(const R4SdkTransportHttpResponseDecoder *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,74u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue75_create(R4SdkTransportNativeValue75 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,75u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue75_inspectNative(const R4SdkTransportNativeValue75 *self, R4SdkTransportHttpParsedHead *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,75u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_create(R4SdkTransportHttpParsedHead *output, uint16_t p0, uint64_t p1, uint32_t p2, uint64_t p3, const uint8_t * p4, uintptr_t n4, R4SdkTransportSlot p5, R4SdkTransportSlot p6, R4SdkTransportSlot p7, R4SdkTransportSlot p8, uint8_t p9, R4SdkTransportSlot p10, const R4SdkWebNativeValue373 * p11, uint64_t p12, R4SdkTransportSlot p13) {
 R4SdkTransportSlot a[14]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = p5;
 a[6] = p6;
 a[7] = p7;
 a[8] = p8;
 a[9] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDKTRANSPORT_PRESENT};
 a[10] = p10;
 a[11] = (R4SdkTransportSlot){.ptr=(void *)p11,.flags=R4SDKTRANSPORT_PRESENT};
 a[12] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4SDKTRANSPORT_PRESENT};
 a[13] = p13;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,76u,a,14u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_from_fields(R4SdkTransportHttpParsedHead *output, uint16_t p0, uint64_t p1, uint32_t p2, uint64_t p3, const uint8_t * p4, uintptr_t n4, R4SdkTransportSlot p5, R4SdkTransportSlot p6, R4SdkTransportSlot p7, R4SdkTransportSlot p8, uint8_t p9, R4SdkTransportSlot p10, const R4SdkWebNativeValue373 * p11, uint64_t p12, R4SdkTransportSlot p13) {
 R4SdkTransportSlot a[14]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.ptr=(void *)p4,.length=n4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = p5;
 a[6] = p6;
 a[7] = p7;
 a[8] = p8;
 a[9] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDKTRANSPORT_PRESENT};
 a[10] = p10;
 a[11] = (R4SdkTransportSlot){.ptr=(void *)p11,.flags=R4SDKTRANSPORT_PRESENT};
 a[12] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p12,.flags=R4SDKTRANSPORT_PRESENT};
 a[13] = p13;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,76u,a,14u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_status(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_status(R4SdkTransportHttpParsedHead *self, uint16_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_body_start(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_body_start(R4SdkTransportHttpParsedHead *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_transfer(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_transfer(R4SdkTransportHttpParsedHead *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_content_length(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_content_length(R4SdkTransportHttpParsedHead *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_headers(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_headers(R4SdkTransportHttpParsedHead *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_location(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_location(R4SdkTransportHttpParsedHead *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_content_type(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_content_type(R4SdkTransportHttpParsedHead *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_content_security_policy(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,7u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_content_security_policy(R4SdkTransportHttpParsedHead *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_access_control_allow_origin(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,8u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_access_control_allow_origin(R4SdkTransportHttpParsedHead *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,8u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_access_control_allow_credentials(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,9u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_access_control_allow_credentials(R4SdkTransportHttpParsedHead *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,9u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_set_cookie(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,10u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_set_cookie(R4SdkTransportHttpParsedHead *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,10u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_set_cookies(const R4SdkTransportHttpParsedHead *self, R4SdkWebNativeValue373 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,11u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_set_cookies(R4SdkTransportHttpParsedHead *self, const R4SdkWebNativeValue373 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,11u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_set_cookie_count(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,12u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_set_cookie_count(R4SdkTransportHttpParsedHead *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,12u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_get_content_range(const R4SdkTransportHttpParsedHead *self, R4SdkTransportHttpContentRange *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,13u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_set_content_range(R4SdkTransportHttpParsedHead *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,76u,13u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpParsedHead_inspectNative(const R4SdkTransportHttpParsedHead *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,76u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue77_create(R4SdkTransportNativeValue77 *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,77u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue77_inspectNative(const R4SdkTransportNativeValue77 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,77u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue78_create(R4SdkTransportNativeValue78 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,78u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue78_inspectNative(const R4SdkTransportNativeValue78 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,78u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_create(R4SdkTransportHttpStreamResponse *output, uint16_t p0, uint32_t p1, uint64_t p2, R4SdkTransportSlot p3, R4SdkTransportSlot p4, R4SdkTransportSlot p5) {
 R4SdkTransportSlot a[6]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = p3;
 a[4] = p4;
 a[5] = p5;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,79u,a,6u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_from_fields(R4SdkTransportHttpStreamResponse *output, uint16_t p0, uint32_t p1, uint64_t p2, R4SdkTransportSlot p3, R4SdkTransportSlot p4, R4SdkTransportSlot p5) {
 R4SdkTransportSlot a[6]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = p3;
 a[4] = p4;
 a[5] = p5;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,79u,a,6u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_get_status(const R4SdkTransportHttpStreamResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_set_status(R4SdkTransportHttpStreamResponse *self, uint16_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_get_transfer(const R4SdkTransportHttpStreamResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_set_transfer(R4SdkTransportHttpStreamResponse *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_get_content_length(const R4SdkTransportHttpStreamResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_set_content_length(R4SdkTransportHttpStreamResponse *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_get_location(const R4SdkTransportHttpStreamResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_set_location(R4SdkTransportHttpStreamResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_get_content_type(const R4SdkTransportHttpStreamResponse *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_set_content_type(R4SdkTransportHttpStreamResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_get_content_range(const R4SdkTransportHttpStreamResponse *self, R4SdkTransportHttpContentRange *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,5u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_set_content_range(R4SdkTransportHttpStreamResponse *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,79u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamResponse_inspectNative(const R4SdkTransportHttpStreamResponse *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,79u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamChunk_create(R4SdkTransportHttpStreamChunk *output, const uint8_t * p0, uintptr_t n0, uint8_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,80u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpStreamChunk_from_fields(R4SdkTransportHttpStreamChunk *output, const uint8_t * p0, uintptr_t n0, uint8_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,80u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpStreamChunk_get_bytes(const R4SdkTransportHttpStreamChunk *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,80u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamChunk_set_bytes(R4SdkTransportHttpStreamChunk *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,80u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamChunk_get_complete(const R4SdkTransportHttpStreamChunk *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,80u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamChunk_set_complete(R4SdkTransportHttpStreamChunk *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,80u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamChunk_inspectNative(const R4SdkTransportHttpStreamChunk *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,80u,(void *)self,0); }
#define R4SdkTransportHttpStreamDecodeResult_TAG_chunk 0u
#define R4SdkTransportHttpStreamDecodeResult_TAG_complete 1u
#define R4SdkTransportHttpStreamDecodeResult_TAG_need_more 2u
#define R4SdkTransportHttpStreamDecodeResult_TAG_aborted 3u
#define R4SdkTransportHttpStreamDecodeResult_TAG_failure 4u
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecodeResult_get_chunk(const R4SdkTransportHttpStreamDecodeResult *self, R4SdkTransportHttpStreamChunk *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,81u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecodeResult_set_chunk(R4SdkTransportHttpStreamDecodeResult *self, const R4SdkTransportHttpStreamChunk * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,81u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecodeResult_get_complete(const R4SdkTransportHttpStreamDecodeResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,81u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecodeResult_set_complete(R4SdkTransportHttpStreamDecodeResult *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,81u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecodeResult_get_need_more(const R4SdkTransportHttpStreamDecodeResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,81u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecodeResult_set_need_more(R4SdkTransportHttpStreamDecodeResult *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,81u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecodeResult_get_aborted(const R4SdkTransportHttpStreamDecodeResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,81u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecodeResult_set_aborted(R4SdkTransportHttpStreamDecodeResult *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,81u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecodeResult_get_failure(const R4SdkTransportHttpStreamDecodeResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,81u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecodeResult_set_failure(R4SdkTransportHttpStreamDecodeResult *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,81u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecodeResult_inspectNative(const R4SdkTransportHttpStreamDecodeResult *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,81u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type___create(R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,82u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_http_StreamDecodeResult____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,82u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_create(R4SdkTransportHttpStreamDecoder *output, uint8_t * p0, uintptr_t n0, uint32_t p1) {
 R4SdkTransportSlot a[7]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,83u,a,7u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_from_fields(R4SdkTransportHttpStreamDecoder *output, uint8_t * p0, uintptr_t n0, uint32_t p1, uint64_t p2, R4SdkTransportSlot p3, uint64_t p4, uint8_t p5, R4SdkTransportSlot p6) {
 R4SdkTransportSlot a[7]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = p3;
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = p6;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,83u,a,7u,output);
}
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_get_header_buffer(const R4SdkTransportHttpStreamDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_set_header_buffer(R4SdkTransportHttpStreamDecoder *self, uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_get_method(const R4SdkTransportHttpStreamDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_set_method(R4SdkTransportHttpStreamDecoder *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_get_header_len(const R4SdkTransportHttpStreamDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_set_header_len(R4SdkTransportHttpStreamDecoder *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_get_head(const R4SdkTransportHttpStreamDecoder *self, R4SdkTransportHttpParsedHead *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,3u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_set_head(R4SdkTransportHttpStreamDecoder *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_get_received(const R4SdkTransportHttpStreamDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_set_received(R4SdkTransportHttpStreamDecoder *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_get_done(const R4SdkTransportHttpStreamDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_set_done(R4SdkTransportHttpStreamDecoder *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_get_failure(const R4SdkTransportHttpStreamDecoder *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_set_failure(R4SdkTransportHttpStreamDecoder *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,83u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpStreamDecoder_inspectNative(const R4SdkTransportHttpStreamDecoder *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,83u,(void *)self,0); }
#define R4SdkTransportHttpRedirectResult_TAG_url 0u
#define R4SdkTransportHttpRedirectResult_TAG_invalid 1u
#define R4SdkTransportHttpRedirectResult_TAG_output_too_small 2u
static inline R4SdkTransportSlot R4SdkTransportHttpRedirectResult_get_url(const R4SdkTransportHttpRedirectResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,84u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRedirectResult_set_url(R4SdkTransportHttpRedirectResult *self, uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,84u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRedirectResult_get_invalid(const R4SdkTransportHttpRedirectResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,84u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRedirectResult_set_invalid(R4SdkTransportHttpRedirectResult *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,84u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRedirectResult_get_output_too_small(const R4SdkTransportHttpRedirectResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,84u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRedirectResult_set_output_too_small(R4SdkTransportHttpRedirectResult *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,84u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportHttpRedirectResult_inspectNative(const R4SdkTransportHttpRedirectResult *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,84u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_http_RedirectResult____union__tag_type___create(R4SdkTransportNative__typeInfo_http_RedirectResult____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,85u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_http_RedirectResult____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_http_RedirectResult____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,85u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheLimits_create(R4SdkTransportCacheLimits *output) {
 R4SdkTransportSlot a[2]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,103u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheLimits_from_fields(R4SdkTransportCacheLimits *output, uint64_t p0, uint64_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,103u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheLimits_get_object_bytes(const R4SdkTransportCacheLimits *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,103u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheLimits_set_object_bytes(R4SdkTransportCacheLimits *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,103u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheLimits_get_total_bytes(const R4SdkTransportCacheLimits *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,103u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheLimits_set_total_bytes(R4SdkTransportCacheLimits *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,103u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheLimits_inspectNative(const R4SdkTransportCacheLimits *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,103u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheClock_create(R4SdkTransportCacheClock *output, uint64_t p0) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,104u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheClock_from_fields(R4SdkTransportCacheClock *output, uint64_t p0, R4SdkTransportSlot p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = p1;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,104u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheClock_get_monotonic_ms(const R4SdkTransportCacheClock *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,104u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheClock_set_monotonic_ms(R4SdkTransportCacheClock *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,104u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheClock_get_unix_seconds(const R4SdkTransportCacheClock *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,104u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheClock_set_unix_seconds(R4SdkTransportCacheClock *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,104u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheClock_inspectNative(const R4SdkTransportCacheClock *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,104u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheKey_create(R4SdkTransportCacheKey *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,105u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheKey_from_fields(R4SdkTransportCacheKey *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, const uint8_t * p2, uintptr_t n2) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.length=n2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,105u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheKey_get_url(const R4SdkTransportCacheKey *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,105u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheKey_set_url(R4SdkTransportCacheKey *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,105u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheKey_get_context(const R4SdkTransportCacheKey *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,105u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheKey_set_context(R4SdkTransportCacheKey *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,105u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheKey_get_headers(const R4SdkTransportCacheKey *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,105u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheKey_set_headers(R4SdkTransportCacheKey *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,105u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheKey_inspectNative(const R4SdkTransportCacheKey *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,105u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheHandle_create(R4SdkTransportCacheHandle *output, uint8_t p0, uint64_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,106u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheHandle_from_fields(R4SdkTransportCacheHandle *output, uint8_t p0, uint64_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,106u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheHandle_get_index(const R4SdkTransportCacheHandle *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,106u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheHandle_set_index(R4SdkTransportCacheHandle *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,106u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheHandle_get_identity(const R4SdkTransportCacheHandle *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,106u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheHandle_set_identity(R4SdkTransportCacheHandle *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,106u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheHandle_inspectNative(const R4SdkTransportCacheHandle *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,106u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheAction_create(R4SdkTransportCacheAction *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,107u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportCacheAction_inspectNative(const R4SdkTransportCacheAction *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,107u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheLookup_create(R4SdkTransportCacheLookup *output, uint32_t p0) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,108u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheLookup_from_fields(R4SdkTransportCacheLookup *output, uint32_t p0, R4SdkTransportSlot p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = p1;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,108u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheLookup_get_action(const R4SdkTransportCacheLookup *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,108u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheLookup_set_action(R4SdkTransportCacheLookup *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,108u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheLookup_get_handle(const R4SdkTransportCacheLookup *self, R4SdkTransportCacheHandle *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,108u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportCacheLookup_set_handle(R4SdkTransportCacheLookup *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,108u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheLookup_inspectNative(const R4SdkTransportCacheLookup *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,108u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue109_create(R4SdkTransportNativeValue109 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,109u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue109_inspectNative(const R4SdkTransportNativeValue109 *self, R4SdkTransportCacheHandle *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,109u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportCacheView_create(R4SdkTransportCacheView *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, uint64_t p2, uint64_t p3) {
 R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,110u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheView_from_fields(R4SdkTransportCacheView *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1, uint64_t p2, uint64_t p3) {
 R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,110u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheView_get_headers(const R4SdkTransportCacheView *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,110u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheView_set_headers(R4SdkTransportCacheView *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,110u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheView_get_body(const R4SdkTransportCacheView *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,110u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheView_set_body(R4SdkTransportCacheView *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,110u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheView_get_identity(const R4SdkTransportCacheView *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,110u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheView_set_identity(R4SdkTransportCacheView *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,110u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheView_get_age_seconds(const R4SdkTransportCacheView *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,110u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheView_set_age_seconds(R4SdkTransportCacheView *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,110u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheView_inspectNative(const R4SdkTransportCacheView *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,110u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheStats_create(R4SdkTransportCacheStats *output) {
 R4SdkTransportSlot a[5]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,111u,a,5u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheStats_from_fields(R4SdkTransportCacheStats *output, uint64_t p0, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4) {
 R4SdkTransportSlot a[5]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,111u,a,5u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheStats_get_hits(const R4SdkTransportCacheStats *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,111u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheStats_set_hits(R4SdkTransportCacheStats *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,111u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheStats_get_misses(const R4SdkTransportCacheStats *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,111u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheStats_set_misses(R4SdkTransportCacheStats *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,111u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheStats_get_validations(const R4SdkTransportCacheStats *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,111u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheStats_set_validations(R4SdkTransportCacheStats *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,111u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheStats_get_stores(const R4SdkTransportCacheStats *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,111u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheStats_set_stores(R4SdkTransportCacheStats *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,111u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheStats_get_evictions(const R4SdkTransportCacheStats *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,111u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheStats_set_evictions(R4SdkTransportCacheStats *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,111u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheStats_inspectNative(const R4SdkTransportCacheStats *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,111u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_create(R4SdkTransportCacheCache *output, const R4SdkDataAllocator * p0, const R4SdkTransportCacheLimits * p1) {
 R4SdkTransportSlot a[7]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,112u,a,7u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheCache_from_fields(R4SdkTransportCacheCache *output, const R4SdkDataAllocator * p0, const R4SdkTransportCacheLimits * p1, const R4SdkTransportNativeValue114 * p2, uint64_t p3, uint64_t p4, uint64_t p5, const R4SdkTransportCacheStats * p6) {
 R4SdkTransportSlot a[7]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.ptr=(void *)p6,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,112u,a,7u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheCache_get_allocator(const R4SdkTransportCacheCache *self, R4SdkDataAllocator *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_set_allocator(R4SdkTransportCacheCache *self, const R4SdkDataAllocator * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_get_limits(const R4SdkTransportCacheCache *self, R4SdkTransportCacheLimits *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_set_limits(R4SdkTransportCacheCache *self, const R4SdkTransportCacheLimits * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_get_entries(const R4SdkTransportCacheCache *self, R4SdkTransportNativeValue114 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,2u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_set_entries(R4SdkTransportCacheCache *self, const R4SdkTransportNativeValue114 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_get_bytes(const R4SdkTransportCacheCache *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_set_bytes(R4SdkTransportCacheCache *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_get_serial(const R4SdkTransportCacheCache *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_set_serial(R4SdkTransportCacheCache *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_get_next_identity(const R4SdkTransportCacheCache *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_set_next_identity(R4SdkTransportCacheCache *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_get_stats(const R4SdkTransportCacheCache *self, R4SdkTransportCacheStats *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,6u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_set_stats(R4SdkTransportCacheCache *self, const R4SdkTransportCacheStats * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,112u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheCache_inspectNative(const R4SdkTransportCacheCache *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,112u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue114_create(R4SdkTransportNativeValue114 *output, const R4SdkTransportNativeValue114 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,114u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue114_inspectNative(const R4SdkTransportNativeValue114 *self, R4SdkTransportNativeValue114 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,114u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_create(R4SdkTransportCacheEntry *output) {
 R4SdkTransportSlot a[11]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 a[7].flags=R4SDKTRANSPORT_DEFAULT;
 a[8].flags=R4SDKTRANSPORT_DEFAULT;
 a[9].flags=R4SDKTRANSPORT_DEFAULT;
 a[10].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,115u,a,11u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_from_fields(R4SdkTransportCacheEntry *output, uint8_t * p0, uintptr_t n0, const R4SdkTransportNativeValue116 * p1, uint64_t p2, uint64_t p3, uint64_t p4, uint16_t p5, uint8_t p6, uint64_t p7, uint64_t p8, uint64_t p9, uint8_t p10) {
 R4SdkTransportSlot a[11]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDKTRANSPORT_PRESENT};
 a[8] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDKTRANSPORT_PRESENT};
 a[9] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDKTRANSPORT_PRESENT};
 a[10] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,115u,a,11u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_get_data(const R4SdkTransportCacheEntry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_set_data(R4SdkTransportCacheEntry *self, uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_get_ends(const R4SdkTransportCacheEntry *self, R4SdkTransportNativeValue116 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_set_ends(R4SdkTransportCacheEntry *self, const R4SdkTransportNativeValue116 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_get_identity(const R4SdkTransportCacheEntry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_set_identity(R4SdkTransportCacheEntry *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_get_token(const R4SdkTransportCacheEntry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_set_token(R4SdkTransportCacheEntry *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_get_used(const R4SdkTransportCacheEntry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_set_used(R4SdkTransportCacheEntry *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_get_pins(const R4SdkTransportCacheEntry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_set_pins(R4SdkTransportCacheEntry *self, uint16_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_get_retired(const R4SdkTransportCacheEntry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_set_retired(R4SdkTransportCacheEntry *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_get_stored_ms(const R4SdkTransportCacheEntry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,7u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_set_stored_ms(R4SdkTransportCacheEntry *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_get_initial_age_ms(const R4SdkTransportCacheEntry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,8u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_set_initial_age_ms(R4SdkTransportCacheEntry *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,8u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_get_lifetime_ms(const R4SdkTransportCacheEntry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,9u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_set_lifetime_ms(R4SdkTransportCacheEntry *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,9u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_get_validate(const R4SdkTransportCacheEntry *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,10u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_set_validate(R4SdkTransportCacheEntry *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,115u,10u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheEntry_inspectNative(const R4SdkTransportCacheEntry *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,115u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue116_create(R4SdkTransportNativeValue116 *output, const R4SdkTransportNativeValue116 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,116u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue116_inspectNative(const R4SdkTransportNativeValue116 *self, R4SdkTransportNativeValue116 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,116u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportCacheHeader_create(R4SdkTransportCacheHeader *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,117u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheHeader_from_fields(R4SdkTransportCacheHeader *output, const uint8_t * p0, uintptr_t n0, const uint8_t * p1, uintptr_t n1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.length=n1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,117u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheHeader_get_name(const R4SdkTransportCacheHeader *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,117u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheHeader_set_name(R4SdkTransportCacheHeader *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,117u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheHeader_get_value(const R4SdkTransportCacheHeader *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,117u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheHeader_set_value(R4SdkTransportCacheHeader *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,117u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheHeader_inspectNative(const R4SdkTransportCacheHeader *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,117u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheHeaderIterator_create(R4SdkTransportCacheHeaderIterator *output, const R4SdkTransportNative_mem_SplitIterator_u8__scalar_ * p0) {
 R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,118u,a,1u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheHeaderIterator_from_fields(R4SdkTransportCacheHeaderIterator *output, const R4SdkTransportNative_mem_SplitIterator_u8__scalar_ * p0) {
 R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,118u,a,1u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheHeaderIterator_get_lines(const R4SdkTransportCacheHeaderIterator *self, R4SdkTransportNative_mem_SplitIterator_u8__scalar_ *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,118u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportCacheHeaderIterator_set_lines(R4SdkTransportCacheHeaderIterator *self, const R4SdkTransportNative_mem_SplitIterator_u8__scalar_ * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,118u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheHeaderIterator_inspectNative(const R4SdkTransportCacheHeaderIterator *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,118u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__create(R4SdkTransportNative_mem_SplitIterator_u8__scalar_ *output, const uint8_t * p0, uintptr_t n0, R4SdkTransportSlot p1, uint8_t p2) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = p1;
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,119u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__from_fields(R4SdkTransportNative_mem_SplitIterator_u8__scalar_ *output, const uint8_t * p0, uintptr_t n0, R4SdkTransportSlot p1, uint8_t p2) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = p1;
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,119u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__get_buffer(const R4SdkTransportNative_mem_SplitIterator_u8__scalar_ *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,119u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__set_buffer(R4SdkTransportNative_mem_SplitIterator_u8__scalar_ *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,119u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__get_index(const R4SdkTransportNative_mem_SplitIterator_u8__scalar_ *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,119u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__set_index(R4SdkTransportNative_mem_SplitIterator_u8__scalar_ *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,119u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__get_delimiter(const R4SdkTransportNative_mem_SplitIterator_u8__scalar_ *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,119u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__set_delimiter(R4SdkTransportNative_mem_SplitIterator_u8__scalar_ *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,119u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_mem_SplitIterator_u8__scalar__inspectNative(const R4SdkTransportNative_mem_SplitIterator_u8__scalar_ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,119u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheDirectives_create(R4SdkTransportCacheDirectives *output) {
 R4SdkTransportSlot a[4]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,121u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheDirectives_from_fields(R4SdkTransportCacheDirectives *output, uint8_t p0, uint8_t p1, R4SdkTransportSlot p2, uint8_t p3) {
 R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = p2;
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,121u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportCacheDirectives_get_no_store(const R4SdkTransportCacheDirectives *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,121u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheDirectives_set_no_store(R4SdkTransportCacheDirectives *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,121u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheDirectives_get_no_cache(const R4SdkTransportCacheDirectives *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,121u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheDirectives_set_no_cache(R4SdkTransportCacheDirectives *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,121u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheDirectives_get_max_age(const R4SdkTransportCacheDirectives *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,121u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheDirectives_set_max_age(R4SdkTransportCacheDirectives *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,121u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheDirectives_get_invalid_age(const R4SdkTransportCacheDirectives *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,121u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheDirectives_set_invalid_age(R4SdkTransportCacheDirectives *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,121u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportCacheDirectives_inspectNative(const R4SdkTransportCacheDirectives *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,121u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_create(R4SdkTransportJobsJob *output, const R4SdkTransportWebTransport * p0) {
 R4SdkTransportSlot a[15]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 a[7].flags=R4SDKTRANSPORT_DEFAULT;
 a[8].flags=R4SDKTRANSPORT_DEFAULT;
 a[9].flags=R4SDKTRANSPORT_DEFAULT;
 a[10].flags=R4SDKTRANSPORT_DEFAULT;
 a[11].flags=R4SDKTRANSPORT_DEFAULT;
 a[12].flags=R4SDKTRANSPORT_DEFAULT;
 a[13].flags=R4SDKTRANSPORT_DEFAULT;
 a[14].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,122u,a,15u,output);
}
static inline R4SdkTransportSlot R4SdkTransportJobsJob_from_fields(R4SdkTransportJobsJob *output, const R4SdkTransportWebTransport * p0, const R4SdkTransportSessionPool * p1, const R4SdkTransportTransportStats * p2, R4SdkTransportSlot p3, const R4StopFlag * p4, uint32_t p5, uint32_t p6, R4SdkTransportSlot p7, R4SdkTransportSlot p8, const uint8_t * p9, uintptr_t n9, uint8_t * p10, uintptr_t n10, uint8_t * p11, uintptr_t n11, uint8_t * p12, uintptr_t n12, const R4SdkTransportFetchOptions * p13, const R4SdkTransportFetchResult * p14) {
 R4SdkTransportSlot a[15]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = p3;
 a[4] = (R4SdkTransportSlot){.ptr=(void *)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = p7;
 a[8] = p8;
 a[9] = (R4SdkTransportSlot){.ptr=(void *)p9,.length=n9,.flags=R4SDKTRANSPORT_PRESENT};
 a[10] = (R4SdkTransportSlot){.ptr=(void *)p10,.length=n10,.flags=R4SDKTRANSPORT_PRESENT};
 a[11] = (R4SdkTransportSlot){.ptr=(void *)p11,.length=n11,.flags=R4SDKTRANSPORT_PRESENT};
 a[12] = (R4SdkTransportSlot){.ptr=(void *)p12,.length=n12,.flags=R4SDKTRANSPORT_PRESENT};
 a[13] = (R4SdkTransportSlot){.ptr=(void *)p13,.flags=R4SDKTRANSPORT_PRESENT};
 a[14] = (R4SdkTransportSlot){.ptr=(void *)p14,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,122u,a,15u,output);
}
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_transport(const R4SdkTransportJobsJob *self, R4SdkTransportWebTransport *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_transport(R4SdkTransportJobsJob *self, const R4SdkTransportWebTransport * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_sessions(const R4SdkTransportJobsJob *self, R4SdkTransportSessionPool *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_sessions(R4SdkTransportJobsJob *self, const R4SdkTransportSessionPool * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_stats(const R4SdkTransportJobsJob *self, R4SdkTransportTransportStats *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,2u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_stats(R4SdkTransportJobsJob *self, const R4SdkTransportTransportStats * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_handle(const R4SdkTransportJobsJob *self, R4SdkTransportNative_app_resources_JoinHandle *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,3u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_handle(R4SdkTransportJobsJob *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_stop(const R4SdkTransportJobsJob *self, R4StopFlag *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,4u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_stop(R4SdkTransportJobsJob *self, const R4StopFlag * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_done(const R4SdkTransportJobsJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_done(R4SdkTransportJobsJob *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_invocation_pending(const R4SdkTransportJobsJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_invocation_pending(R4SdkTransportJobsJob *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_invocation_context(const R4SdkTransportJobsJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,7u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_invocation_context(R4SdkTransportJobsJob *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_invocation_fn(const R4SdkTransportJobsJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,8u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_invocation_fn(R4SdkTransportJobsJob *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,8u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_url(const R4SdkTransportJobsJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,9u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_url(R4SdkTransportJobsJob *self, const uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,9u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_raw(const R4SdkTransportJobsJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,10u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_raw(R4SdkTransportJobsJob *self, uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,10u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_body(const R4SdkTransportJobsJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,11u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_body(R4SdkTransportJobsJob *self, uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,11u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_scratch(const R4SdkTransportJobsJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,12u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_scratch(R4SdkTransportJobsJob *self, uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,12u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_owner_options(const R4SdkTransportJobsJob *self, R4SdkTransportFetchOptions *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,13u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_owner_options(R4SdkTransportJobsJob *self, const R4SdkTransportFetchOptions * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,13u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_get_result(const R4SdkTransportJobsJob *self, R4SdkTransportFetchResult *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,14u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_set_result(R4SdkTransportJobsJob *self, const R4SdkTransportFetchResult * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,122u,14u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportJobsJob_inspectNative(const R4SdkTransportJobsJob *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,122u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue123_create(R4SdkTransportNativeValue123 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,123u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue123_inspectNative(const R4SdkTransportNativeValue123 *self, R4SdkTransportNative_app_resources_JoinHandle *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,123u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_create(R4SdkTransportNative_app_resources_JoinHandle *output, const R4SdkTransportNative_r4sys_Context * p0) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,124u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_from_fields(R4SdkTransportNative_app_resources_JoinHandle *output, const R4SdkTransportNative_r4sys_Context * p0, const R4ProgramJoinHandle * p1, uint8_t p2) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,124u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_get_sys(const R4SdkTransportNative_app_resources_JoinHandle *self, R4SdkTransportNative_r4sys_Context *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,124u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_set_sys(R4SdkTransportNative_app_resources_JoinHandle *self, const R4SdkTransportNative_r4sys_Context * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,124u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_get_handle(const R4SdkTransportNative_app_resources_JoinHandle *self, R4ProgramJoinHandle *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,124u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_set_handle(R4SdkTransportNative_app_resources_JoinHandle *self, const R4ProgramJoinHandle * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,124u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_get_owned(const R4SdkTransportNative_app_resources_JoinHandle *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,124u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_set_owned(R4SdkTransportNative_app_resources_JoinHandle *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,124u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinHandle_inspectNative(const R4SdkTransportNative_app_resources_JoinHandle *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,124u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue126_create(R4SdkTransportNativeValue126 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,126u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue126_inspectNative(const R4SdkTransportNativeValue126 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,126u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsOwner_create(R4SdkTransportRuntimeJobsOwner *output, R4SdkTransportSlot p0, uintptr_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = p0;
 a[1] = (R4SdkTransportSlot){.ptr=(void *)(uintptr_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,127u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsOwner_from_fields(R4SdkTransportRuntimeJobsOwner *output, R4SdkTransportSlot p0, uintptr_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = p0;
 a[1] = (R4SdkTransportSlot){.ptr=(void *)(uintptr_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,127u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsOwner_get_context(const R4SdkTransportRuntimeJobsOwner *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,127u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsOwner_set_context(R4SdkTransportRuntimeJobsOwner *self, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,127u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsOwner_get_find(const R4SdkTransportRuntimeJobsOwner *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,127u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsOwner_set_find(R4SdkTransportRuntimeJobsOwner *self, uintptr_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)(uintptr_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,127u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsOwner_inspectNative(const R4SdkTransportRuntimeJobsOwner *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,127u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_create(R4SdkTransportRuntimeJobsRequestJob *output, const R4SdkTransportJobsJob * p0, const R4SdkTransportRuntimeJobsOwner * p1, const R4SdkDataAllocator * p2) {
 R4SdkTransportSlot a[17]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 a[7].flags=R4SDKTRANSPORT_DEFAULT;
 a[8].flags=R4SDKTRANSPORT_DEFAULT;
 a[9].flags=R4SDKTRANSPORT_DEFAULT;
 a[10].flags=R4SDKTRANSPORT_DEFAULT;
 a[11].flags=R4SDKTRANSPORT_DEFAULT;
 a[12].flags=R4SDKTRANSPORT_DEFAULT;
 a[13].flags=R4SDKTRANSPORT_DEFAULT;
 a[14].flags=R4SDKTRANSPORT_DEFAULT;
 a[15].flags=R4SDKTRANSPORT_DEFAULT;
 a[16].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,128u,a,17u,output);
}
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_from_fields(R4SdkTransportRuntimeJobsRequestJob *output, const R4SdkTransportJobsJob * p0, const R4SdkTransportRuntimeJobsOwner * p1, const R4SdkDataAllocator * p2, uint8_t * p3, uintptr_t n3, uint8_t p4, uint32_t p5, const R4SdkWebNativeValue629 * p6, uint64_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11, const R4SdkWebNative_web_security_Origin * p12, const R4SdkTransportNativeValue131 * p13, const R4SdkWebNativeValue226 * p14, const R4SdkWebNavigationUrl * p15, const R4SdkTransportFetchOptions * p16) {
 R4SdkTransportSlot a[17]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.length=n3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.ptr=(void *)p6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDKTRANSPORT_PRESENT};
 a[8] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p8,.flags=R4SDKTRANSPORT_PRESENT};
 a[9] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p9,.flags=R4SDKTRANSPORT_PRESENT};
 a[10] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p10,.flags=R4SDKTRANSPORT_PRESENT};
 a[11] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p11,.flags=R4SDKTRANSPORT_PRESENT};
 a[12] = (R4SdkTransportSlot){.ptr=(void *)p12,.flags=R4SDKTRANSPORT_PRESENT};
 a[13] = (R4SdkTransportSlot){.ptr=(void *)p13,.flags=R4SDKTRANSPORT_PRESENT};
 a[14] = (R4SdkTransportSlot){.ptr=(void *)p14,.flags=R4SDKTRANSPORT_PRESENT};
 a[15] = (R4SdkTransportSlot){.ptr=(void *)p15,.flags=R4SDKTRANSPORT_PRESENT};
 a[16] = (R4SdkTransportSlot){.ptr=(void *)p16,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,128u,a,17u,output);
}
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_job(const R4SdkTransportRuntimeJobsRequestJob *self, R4SdkTransportJobsJob *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_job(R4SdkTransportRuntimeJobsRequestJob *self, const R4SdkTransportJobsJob * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_owner(const R4SdkTransportRuntimeJobsRequestJob *self, R4SdkTransportRuntimeJobsOwner *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_owner(R4SdkTransportRuntimeJobsRequestJob *self, const R4SdkTransportRuntimeJobsOwner * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_allocator(const R4SdkTransportRuntimeJobsRequestJob *self, R4SdkDataAllocator *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,2u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_allocator(R4SdkTransportRuntimeJobsRequestJob *self, const R4SdkDataAllocator * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_memory(const R4SdkTransportRuntimeJobsRequestJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_memory(R4SdkTransportRuntimeJobsRequestJob *self, uint8_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_active(const R4SdkTransportRuntimeJobsRequestJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_active(R4SdkTransportRuntimeJobsRequestJob *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_generation(const R4SdkTransportRuntimeJobsRequestJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_generation(R4SdkTransportRuntimeJobsRequestJob *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_ids(const R4SdkTransportRuntimeJobsRequestJob *self, R4SdkWebNativeValue629 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,6u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_ids(R4SdkTransportRuntimeJobsRequestJob *self, const R4SdkWebNativeValue629 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_count(const R4SdkTransportRuntimeJobsRequestJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,7u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_count(R4SdkTransportRuntimeJobsRequestJob *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_kind(const R4SdkTransportRuntimeJobsRequestJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,8u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_kind(R4SdkTransportRuntimeJobsRequestJob *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,8u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_mode(const R4SdkTransportRuntimeJobsRequestJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,9u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_mode(R4SdkTransportRuntimeJobsRequestJob *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,9u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_credentials(const R4SdkTransportRuntimeJobsRequestJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,10u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_credentials(R4SdkTransportRuntimeJobsRequestJob *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,10u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_cache_mode(const R4SdkTransportRuntimeJobsRequestJob *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,11u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_cache_mode(R4SdkTransportRuntimeJobsRequestJob *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,11u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_origin(const R4SdkTransportRuntimeJobsRequestJob *self, R4SdkWebNative_web_security_Origin *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,12u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_origin(R4SdkTransportRuntimeJobsRequestJob *self, const R4SdkWebNative_web_security_Origin * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,12u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_origin_text(const R4SdkTransportRuntimeJobsRequestJob *self, R4SdkTransportNativeValue131 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,13u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_origin_text(R4SdkTransportRuntimeJobsRequestJob *self, const R4SdkTransportNativeValue131 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,13u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_partition(const R4SdkTransportRuntimeJobsRequestJob *self, R4SdkWebNativeValue226 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,14u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_partition(R4SdkTransportRuntimeJobsRequestJob *self, const R4SdkWebNativeValue226 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,14u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_url(const R4SdkTransportRuntimeJobsRequestJob *self, R4SdkWebNavigationUrl *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,15u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_url(R4SdkTransportRuntimeJobsRequestJob *self, const R4SdkWebNavigationUrl * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,15u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_get_options(const R4SdkTransportRuntimeJobsRequestJob *self, R4SdkTransportFetchOptions *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,16u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_set_options(R4SdkTransportRuntimeJobsRequestJob *self, const R4SdkTransportFetchOptions * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,128u,16u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportRuntimeJobsRequestJob_inspectNative(const R4SdkTransportRuntimeJobsRequestJob *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,128u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue131_create(R4SdkTransportNativeValue131 *output, const R4SdkTransportNativeValue131 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,131u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue131_inspectNative(const R4SdkTransportNativeValue131 *self, R4SdkTransportNativeValue131 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,131u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue140_create(R4SdkTransportNativeValue140 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,140u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue140_inspectNative(const R4SdkTransportNativeValue140 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,140u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_create(R4SdkTransportDocumentsContext *output, uint32_t p0, uint32_t p1, uint16_t p2, const R4SdkWebNavigationUrl * p3) {
 R4SdkTransportSlot a[7]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,141u,a,7u,output);
}
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_from_fields(R4SdkTransportDocumentsContext *output, uint32_t p0, uint32_t p1, uint16_t p2, const R4SdkWebNavigationUrl * p3, const R4SdkWebHtmlDocument * p4, const R4SdkWebRuntimeWebRuntime * p5, uint8_t p6) {
 R4SdkTransportSlot a[7]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.ptr=(void *)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.ptr=(void *)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p6,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,141u,a,7u,output);
}
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_get_parent_generation(const R4SdkTransportDocumentsContext *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_set_parent_generation(R4SdkTransportDocumentsContext *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_get_generation(const R4SdkTransportDocumentsContext *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_set_generation(R4SdkTransportDocumentsContext *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_get_node(const R4SdkTransportDocumentsContext *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_set_node(R4SdkTransportDocumentsContext *self, uint16_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_get_url(const R4SdkTransportDocumentsContext *self, R4SdkWebNavigationUrl *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,3u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_set_url(R4SdkTransportDocumentsContext *self, const R4SdkWebNavigationUrl * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_get_document(const R4SdkTransportDocumentsContext *self, R4SdkWebHtmlDocument *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,4u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_set_document(R4SdkTransportDocumentsContext *self, const R4SdkWebHtmlDocument * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_get_runtime(const R4SdkTransportDocumentsContext *self, R4SdkWebRuntimeWebRuntime *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,5u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_set_runtime(R4SdkTransportDocumentsContext *self, const R4SdkWebRuntimeWebRuntime * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_get_finalized(const R4SdkTransportDocumentsContext *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_set_finalized(R4SdkTransportDocumentsContext *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,141u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsContext_inspectNative(const R4SdkTransportDocumentsContext *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,141u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_constructNative(R4SdkTransportDocumentsSet *output, const R4SdkDataAllocator * p0, const R4SdkWebJsProgramAllocator * p1, R4SdkWebNative_web_security_BrowserStorage * p2) {
 R4SdkTransportSlot a[10]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 a[4].flags=R4SDKTRANSPORT_DEFAULT;
 a[5].flags=R4SDKTRANSPORT_DEFAULT;
 a[6].flags=R4SDKTRANSPORT_DEFAULT;
 a[7].flags=R4SDKTRANSPORT_DEFAULT;
 a[8].flags=R4SDKTRANSPORT_DEFAULT;
 a[9].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,144u,a,10u,output);
}
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_from_fields(R4SdkTransportDocumentsSet *output, const R4SdkDataAllocator * p0, const R4SdkWebJsProgramAllocator * p1, R4SdkWebNative_web_security_BrowserStorage * p2, const R4SdkTransportNativeValue147 * p3, uint32_t p4, uint64_t p5, const R4SdkWebJsStop * p6, uint64_t p7, const R4SdkWebRuntimeEnvironment * p8, const R4SdkWebRuntimeMonotonicClock * p9) {
 R4SdkTransportSlot a[10]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.ptr=(void *)p3,.flags=R4SDKTRANSPORT_PRESENT};
 a[4] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p4,.flags=R4SDKTRANSPORT_PRESENT};
 a[5] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p5,.flags=R4SDKTRANSPORT_PRESENT};
 a[6] = (R4SdkTransportSlot){.ptr=(void *)p6,.flags=R4SDKTRANSPORT_PRESENT};
 a[7] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p7,.flags=R4SDKTRANSPORT_PRESENT};
 a[8] = (R4SdkTransportSlot){.ptr=(void *)p8,.flags=R4SDKTRANSPORT_PRESENT};
 a[9] = (R4SdkTransportSlot){.ptr=(void *)p9,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,144u,a,10u,output);
}
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_get_allocator(const R4SdkTransportDocumentsSet *self, R4SdkDataAllocator *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_set_allocator(R4SdkTransportDocumentsSet *self, const R4SdkDataAllocator * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_get_program_allocator(const R4SdkTransportDocumentsSet *self, R4SdkWebJsProgramAllocator *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_set_program_allocator(R4SdkTransportDocumentsSet *self, const R4SdkWebJsProgramAllocator * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_get_storage(const R4SdkTransportDocumentsSet *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_set_storage(R4SdkTransportDocumentsSet *self, R4SdkWebNative_web_security_BrowserStorage * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_get_entries(const R4SdkTransportDocumentsSet *self, R4SdkTransportNativeValue147 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,3u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_set_entries(R4SdkTransportDocumentsSet *self, const R4SdkTransportNativeValue147 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_get_next_generation(const R4SdkTransportDocumentsSet *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_set_next_generation(R4SdkTransportDocumentsSet *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_get_pump_cursor(const R4SdkTransportDocumentsSet *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_set_pump_cursor(R4SdkTransportDocumentsSet *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_get_execution_stop(const R4SdkTransportDocumentsSet *self, R4SdkWebJsStop *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,6u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_set_execution_stop(R4SdkTransportDocumentsSet *self, const R4SdkWebJsStop * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_get_execution_step_budget(const R4SdkTransportDocumentsSet *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,7u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_set_execution_step_budget(R4SdkTransportDocumentsSet *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_get_environment(const R4SdkTransportDocumentsSet *self, R4SdkWebRuntimeEnvironment *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,8u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_set_environment(R4SdkTransportDocumentsSet *self, const R4SdkWebRuntimeEnvironment * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,8u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_get_monotonic_clock(const R4SdkTransportDocumentsSet *self, R4SdkWebRuntimeMonotonicClock *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,9u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_set_monotonic_clock(R4SdkTransportDocumentsSet *self, const R4SdkWebRuntimeMonotonicClock * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,144u,9u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportDocumentsSet_inspectNative(const R4SdkTransportDocumentsSet *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,144u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue147_create(R4SdkTransportNativeValue147 *output, const R4SdkTransportNativeValue147 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,147u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue147_inspectNative(const R4SdkTransportNativeValue147 *self, R4SdkTransportNativeValue147 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,147u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue148_create(R4SdkTransportNativeValue148 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,148u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue148_inspectNative(const R4SdkTransportNativeValue148 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,148u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue149_create(R4SdkTransportNativeValue149 *output, R4SdkTransportDocumentsContext * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,149u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue149_inspectNative(const R4SdkTransportNativeValue149 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,149u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_create(R4SdkTransportFetchHeaders *output) {
 R4SdkTransportSlot a[2]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,153u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_from_fields(R4SdkTransportFetchHeaders *output, const R4SdkTransportNativeValue154 * p0, uint64_t p1) {
 R4SdkTransportSlot a[2]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,153u,a,2u,output);
}
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_get_entries(const R4SdkTransportFetchHeaders *self, R4SdkTransportNativeValue154 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,153u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_set_entries(R4SdkTransportFetchHeaders *self, const R4SdkTransportNativeValue154 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,153u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_get_count(const R4SdkTransportFetchHeaders *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,153u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_set_count(R4SdkTransportFetchHeaders *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,153u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeaders_inspectNative(const R4SdkTransportFetchHeaders *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,153u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue154_create(R4SdkTransportNativeValue154 *output, const R4SdkTransportNativeValue154 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,154u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue154_inspectNative(const R4SdkTransportNativeValue154 *self, R4SdkTransportNativeValue154 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,154u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeader_create(R4SdkTransportFetchHeader *output) {
 R4SdkTransportSlot a[4]={0};
 a[0].flags=R4SDKTRANSPORT_DEFAULT;
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,155u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportFetchHeader_from_fields(R4SdkTransportFetchHeader *output, const R4SdkWebNativeValue164 * p0, uint64_t p1, const R4SdkWebNativeValue351 * p2, uint64_t p3) {
 R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.ptr=(void *)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,155u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportFetchHeader_get_name(const R4SdkTransportFetchHeader *self, R4SdkWebNativeValue164 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,155u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeader_set_name(R4SdkTransportFetchHeader *self, const R4SdkWebNativeValue164 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,155u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeader_get_name_len(const R4SdkTransportFetchHeader *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,155u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeader_set_name_len(R4SdkTransportFetchHeader *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,155u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeader_get_value(const R4SdkTransportFetchHeader *self, R4SdkWebNativeValue351 *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,155u,2u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeader_set_value(R4SdkTransportFetchHeader *self, const R4SdkWebNativeValue351 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,155u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeader_get_value_len(const R4SdkTransportFetchHeader *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,155u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeader_set_value_len(R4SdkTransportFetchHeader *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,155u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportFetchHeader_inspectNative(const R4SdkTransportFetchHeader *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,155u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue159_create(R4SdkTransportNativeValue159 *output, R4SdkTransportContext * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,159u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue159_inspectNative(const R4SdkTransportNativeValue159 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,159u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue160_create(R4SdkTransportNativeValue160 *output, const R4XStartContext * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,160u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue160_inspectNative(const R4SdkTransportNativeValue160 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,160u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue162_create(R4SdkTransportNativeValue162 *output, R4SdkTransportWebTransport * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,162u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue162_inspectNative(const R4SdkTransportNativeValue162 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,162u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue163_create(R4SdkTransportNativeValue163 *output, R4SdkTransportJobsJob * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,163u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue163_inspectNative(const R4SdkTransportNativeValue163 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,163u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue164_create(R4SdkTransportNativeValue164 *output, const R4SdkTransportContext * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,164u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue164_inspectNative(const R4SdkTransportNativeValue164 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,164u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue165_create(R4SdkTransportNativeValue165 *output, R4SdkTransportRuntimeJobsRequestJob * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,165u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue165_inspectNative(const R4SdkTransportNativeValue165 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,165u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue167_inspectNative(const R4SdkTransportNativeValue167 *self, R4SdkTransportRuntimeJobsOwner *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,167u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue168_create(R4SdkTransportNativeValue168 *output, R4SdkTransportFetchOptions * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,168u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue168_inspectNative(const R4SdkTransportNativeValue168 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,168u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue169_create(R4SdkTransportNativeValue169 *output, R4SdkTransportDownloadOptions * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,169u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue169_inspectNative(const R4SdkTransportNativeValue169 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,169u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue170_inspectNative(const R4SdkTransportNativeValue170 *self, R4SdkTransportDownloadSink *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,170u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue172_create(R4SdkTransportNativeValue172 *output, const R4SdkTransportNative_app_network_Network * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,172u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue172_inspectNative(const R4SdkTransportNativeValue172 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,172u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue173_create(R4SdkTransportNativeValue173 *output, const R4SdkTransportNative_app_network_TcpSocket * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,173u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue173_inspectNative(const R4SdkTransportNativeValue173 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,173u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue174_create(R4SdkTransportNativeValue174 *output, R4SdkTransportNative_app_network_TcpSocket * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,174u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue174_inspectNative(const R4SdkTransportNativeValue174 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,174u,(void *)self,0); }
#define R4SdkTransportNative_app_network_SocketIo_TAG_bytes 0u
#define R4SdkTransportNative_app_network_SocketIo_TAG_would_block 1u
#define R4SdkTransportNative_app_network_SocketIo_TAG_timed_out 2u
#define R4SdkTransportNative_app_network_SocketIo_TAG_reset 3u
#define R4SdkTransportNative_app_network_SocketIo_TAG_peer_closed 4u
#define R4SdkTransportNative_app_network_SocketIo_TAG_closed 5u
#define R4SdkTransportNative_app_network_SocketIo_TAG_failure 6u
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_get_bytes(const R4SdkTransportNative_app_network_SocketIo *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_set_bytes(R4SdkTransportNative_app_network_SocketIo *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_get_would_block(const R4SdkTransportNative_app_network_SocketIo *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_set_would_block(R4SdkTransportNative_app_network_SocketIo *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_get_timed_out(const R4SdkTransportNative_app_network_SocketIo *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_set_timed_out(R4SdkTransportNative_app_network_SocketIo *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_get_reset(const R4SdkTransportNative_app_network_SocketIo *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_set_reset(R4SdkTransportNative_app_network_SocketIo *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_get_peer_closed(const R4SdkTransportNative_app_network_SocketIo *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_set_peer_closed(R4SdkTransportNative_app_network_SocketIo *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_get_closed(const R4SdkTransportNative_app_network_SocketIo *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_set_closed(R4SdkTransportNative_app_network_SocketIo *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_get_failure(const R4SdkTransportNative_app_network_SocketIo *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_set_failure(R4SdkTransportNative_app_network_SocketIo *self, int32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,175u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_SocketIo_inspectNative(const R4SdkTransportNative_app_network_SocketIo *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,175u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type___create(R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,176u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_app_network_SocketIo____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,176u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Resolver_create(R4SdkTransportNative_app_network_Resolver *output, const R4SdkTransportNative_app_network_Network * p0) {
 R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,177u,a,1u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Resolver_from_fields(R4SdkTransportNative_app_network_Resolver *output, const R4SdkTransportNative_app_network_Network * p0) {
 R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,177u,a,1u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Resolver_get_network(const R4SdkTransportNative_app_network_Resolver *self, R4SdkTransportNative_app_network_Network *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,177u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Resolver_set_network(R4SdkTransportNative_app_network_Resolver *self, const R4SdkTransportNative_app_network_Network * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,177u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Resolver_inspectNative(const R4SdkTransportNative_app_network_Resolver *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,177u,(void *)self,0); }
#define R4SdkTransportNative_app_network_TcpOpen_TAG_socket 0u
#define R4SdkTransportNative_app_network_TcpOpen_TAG_would_block 1u
#define R4SdkTransportNative_app_network_TcpOpen_TAG_timed_out 2u
#define R4SdkTransportNative_app_network_TcpOpen_TAG_reset 3u
#define R4SdkTransportNative_app_network_TcpOpen_TAG_peer_closed 4u
#define R4SdkTransportNative_app_network_TcpOpen_TAG_no_service 5u
#define R4SdkTransportNative_app_network_TcpOpen_TAG_failure 6u
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_get_socket(const R4SdkTransportNative_app_network_TcpOpen *self, R4SdkTransportNative_app_network_TcpSocket *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_set_socket(R4SdkTransportNative_app_network_TcpOpen *self, const R4SdkTransportNative_app_network_TcpSocket * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_get_would_block(const R4SdkTransportNative_app_network_TcpOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_set_would_block(R4SdkTransportNative_app_network_TcpOpen *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_get_timed_out(const R4SdkTransportNative_app_network_TcpOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_set_timed_out(R4SdkTransportNative_app_network_TcpOpen *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_get_reset(const R4SdkTransportNative_app_network_TcpOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_set_reset(R4SdkTransportNative_app_network_TcpOpen *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_get_peer_closed(const R4SdkTransportNative_app_network_TcpOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_set_peer_closed(R4SdkTransportNative_app_network_TcpOpen *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_get_no_service(const R4SdkTransportNative_app_network_TcpOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_set_no_service(R4SdkTransportNative_app_network_TcpOpen *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_get_failure(const R4SdkTransportNative_app_network_TcpOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_set_failure(R4SdkTransportNative_app_network_TcpOpen *self, int32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,178u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpOpen_inspectNative(const R4SdkTransportNative_app_network_TcpOpen *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,178u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type___create(R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,179u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_app_network_TcpOpen____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,179u,(void *)self,0); }
#define R4SdkTransportNative_app_network_ListenerOpen_TAG_listener 0u
#define R4SdkTransportNative_app_network_ListenerOpen_TAG_timed_out 1u
#define R4SdkTransportNative_app_network_ListenerOpen_TAG_no_service 2u
#define R4SdkTransportNative_app_network_ListenerOpen_TAG_failure 3u
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ListenerOpen_get_listener(const R4SdkTransportNative_app_network_ListenerOpen *self, R4SdkTransportNative_app_network_TcpListener *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,180u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ListenerOpen_set_listener(R4SdkTransportNative_app_network_ListenerOpen *self, const R4SdkTransportNative_app_network_TcpListener * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,180u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ListenerOpen_get_timed_out(const R4SdkTransportNative_app_network_ListenerOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,180u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ListenerOpen_set_timed_out(R4SdkTransportNative_app_network_ListenerOpen *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,180u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ListenerOpen_get_no_service(const R4SdkTransportNative_app_network_ListenerOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,180u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ListenerOpen_set_no_service(R4SdkTransportNative_app_network_ListenerOpen *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,180u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ListenerOpen_get_failure(const R4SdkTransportNative_app_network_ListenerOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,180u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ListenerOpen_set_failure(R4SdkTransportNative_app_network_ListenerOpen *self, int32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,180u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ListenerOpen_inspectNative(const R4SdkTransportNative_app_network_ListenerOpen *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,180u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_ListenerOpen____union__tag_type___create(R4SdkTransportNative__typeInfo_app_network_ListenerOpen____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,181u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_ListenerOpen____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_app_network_ListenerOpen____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,181u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_create(R4SdkTransportNative_app_network_TcpListener *output, const R4SdkTransportNative_app_network_Network * p0) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,182u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_from_fields(R4SdkTransportNative_app_network_TcpListener *output, const R4SdkTransportNative_app_network_Network * p0, uint16_t p1, uint8_t p2) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,182u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_get_network(const R4SdkTransportNative_app_network_TcpListener *self, R4SdkTransportNative_app_network_Network *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,182u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_set_network(R4SdkTransportNative_app_network_TcpListener *self, const R4SdkTransportNative_app_network_Network * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,182u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_get_port(const R4SdkTransportNative_app_network_TcpListener *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,182u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_set_port(R4SdkTransportNative_app_network_TcpListener *self, uint16_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,182u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_get_owned(const R4SdkTransportNative_app_network_TcpListener *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,182u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_set_owned(R4SdkTransportNative_app_network_TcpListener *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,182u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpListener_inspectNative(const R4SdkTransportNative_app_network_TcpListener *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,182u,(void *)self,0); }
#define R4SdkTransportNative_app_network_UdpOpen_TAG_socket 0u
#define R4SdkTransportNative_app_network_UdpOpen_TAG_timed_out 1u
#define R4SdkTransportNative_app_network_UdpOpen_TAG_no_service 2u
#define R4SdkTransportNative_app_network_UdpOpen_TAG_failure 3u
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpOpen_get_socket(const R4SdkTransportNative_app_network_UdpOpen *self, R4SdkTransportNative_app_network_UdpSocket *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,183u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpOpen_set_socket(R4SdkTransportNative_app_network_UdpOpen *self, const R4SdkTransportNative_app_network_UdpSocket * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,183u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpOpen_get_timed_out(const R4SdkTransportNative_app_network_UdpOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,183u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpOpen_set_timed_out(R4SdkTransportNative_app_network_UdpOpen *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,183u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpOpen_get_no_service(const R4SdkTransportNative_app_network_UdpOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,183u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpOpen_set_no_service(R4SdkTransportNative_app_network_UdpOpen *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,183u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpOpen_get_failure(const R4SdkTransportNative_app_network_UdpOpen *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,183u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpOpen_set_failure(R4SdkTransportNative_app_network_UdpOpen *self, int32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,183u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpOpen_inspectNative(const R4SdkTransportNative_app_network_UdpOpen *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,183u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_UdpOpen____union__tag_type___create(R4SdkTransportNative__typeInfo_app_network_UdpOpen____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,184u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_UdpOpen____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_app_network_UdpOpen____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,184u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_create(R4SdkTransportNative_app_network_UdpSocket *output, const R4SdkTransportNative_app_network_Network * p0) {
 R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1].flags=R4SDKTRANSPORT_DEFAULT;
 a[2].flags=R4SDKTRANSPORT_DEFAULT;
 a[3].flags=R4SDKTRANSPORT_DEFAULT;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,185u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_from_fields(R4SdkTransportNative_app_network_UdpSocket *output, const R4SdkTransportNative_app_network_Network * p0, uint32_t p1, uint8_t p2, uint16_t p3) {
 R4SdkTransportSlot a[4]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 a[3] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p3,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,185u,a,4u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_get_network(const R4SdkTransportNative_app_network_UdpSocket *self, R4SdkTransportNative_app_network_Network *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,185u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_set_network(R4SdkTransportNative_app_network_UdpSocket *self, const R4SdkTransportNative_app_network_Network * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,185u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_get_raw(const R4SdkTransportNative_app_network_UdpSocket *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,185u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_set_raw(R4SdkTransportNative_app_network_UdpSocket *self, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,185u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_get_owned(const R4SdkTransportNative_app_network_UdpSocket *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,185u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_set_owned(R4SdkTransportNative_app_network_UdpSocket *self, uint8_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,185u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_get_local_port(const R4SdkTransportNative_app_network_UdpSocket *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,185u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_set_local_port(R4SdkTransportNative_app_network_UdpSocket *self, uint16_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,185u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpSocket_inspectNative(const R4SdkTransportNative_app_network_UdpSocket *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,185u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue186_create(R4SdkTransportNativeValue186 *output, const R4SdkTransportFinalUrl * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,186u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue186_inspectNative(const R4SdkTransportNativeValue186 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,186u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue187_create(R4SdkTransportNativeValue187 *output, const R4SdkTransportWebTransport * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,187u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue187_inspectNative(const R4SdkTransportNativeValue187 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,187u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue188_create(R4SdkTransportNativeValue188 *output, R4SdkTransportHttpResponseDecoder * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,188u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue188_inspectNative(const R4SdkTransportNativeValue188 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,188u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue189_create(R4SdkTransportNativeValue189 *output, const R4SdkTransportHttpStreamDecoder * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,189u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue189_inspectNative(const R4SdkTransportNativeValue189 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,189u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue190_create(R4SdkTransportNativeValue190 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,190u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue190_inspectNative(const R4SdkTransportNativeValue190 *self, R4SdkTransportHttpStreamResponse *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,190u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue191_create(R4SdkTransportNativeValue191 *output, R4SdkTransportHttpStreamDecoder * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,191u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue191_inspectNative(const R4SdkTransportNativeValue191 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,191u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue192_create(R4SdkTransportNativeValue192 *output, R4SdkTransportCacheCache * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,192u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue192_inspectNative(const R4SdkTransportNativeValue192 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,192u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue193_create(R4SdkTransportNativeValue193 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,193u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue193_inspectNative(const R4SdkTransportNativeValue193 *self, R4SdkTransportCacheView *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,193u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue194_inspectNative(const R4SdkTransportNativeValue194 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,194u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue195_create(R4SdkTransportNativeValue195 *output, R4SdkTransportCacheHeaderIterator * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,195u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue195_inspectNative(const R4SdkTransportNativeValue195 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,195u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue196_create(R4SdkTransportNativeValue196 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,196u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue196_inspectNative(const R4SdkTransportNativeValue196 *self, R4SdkTransportCacheHeader *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,196u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue197_create(R4SdkTransportNativeValue197 *output, R4SdkTransportNative_mem_SplitIterator_u8__scalar_ * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,197u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue197_inspectNative(const R4SdkTransportNativeValue197 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,197u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue198_create(R4SdkTransportNativeValue198 *output, const R4SdkTransportNative_mem_SplitIterator_u8__scalar_ * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,198u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue198_inspectNative(const R4SdkTransportNativeValue198 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,198u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue199_create(R4SdkTransportNativeValue199 *output, const R4SdkTransportNative_app_resources_JoinHandle * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,199u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue199_inspectNative(const R4SdkTransportNativeValue199 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,199u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue200_create(R4SdkTransportNativeValue200 *output, R4ThreadPlacementInfo * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,200u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue200_inspectNative(const R4SdkTransportNativeValue200 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,200u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue202_create(R4SdkTransportNativeValue202 *output, uint64_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,202u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue202_inspectNative(const R4SdkTransportNativeValue202 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,202u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue203_create(R4SdkTransportNativeValue203 *output, const R4ThreadPlacementRequest * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,203u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue203_inspectNative(const R4SdkTransportNativeValue203 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,203u,(void *)self,0); }
#define R4SdkTransportNative_app_resources_ThreadInfo_TAG_value 0u
#define R4SdkTransportNative_app_resources_ThreadInfo_TAG_failure 1u
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_ThreadInfo_get_value(const R4SdkTransportNative_app_resources_ThreadInfo *self, R4ProgramThreadInfo *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,206u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_ThreadInfo_set_value(R4SdkTransportNative_app_resources_ThreadInfo *self, const R4ProgramThreadInfo * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,206u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_ThreadInfo_get_failure(const R4SdkTransportNative_app_resources_ThreadInfo *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,206u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_ThreadInfo_set_failure(R4SdkTransportNative_app_resources_ThreadInfo *self, int32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,206u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_ThreadInfo_inspectNative(const R4SdkTransportNative_app_resources_ThreadInfo *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,206u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_resources_ThreadInfo____union__tag_type___create(R4SdkTransportNative__typeInfo_app_resources_ThreadInfo____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,207u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_resources_ThreadInfo____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_app_resources_ThreadInfo____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,207u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue209_create(R4SdkTransportNativeValue209 *output, R4SdkTransportNative_app_resources_JoinHandle * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,209u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue209_inspectNative(const R4SdkTransportNativeValue209 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,209u,(void *)self,0); }
#define R4SdkTransportNative_app_resources_JoinWait_TAG_exited 0u
#define R4SdkTransportNative_app_resources_JoinWait_TAG_timed_out 1u
#define R4SdkTransportNative_app_resources_JoinWait_TAG_failure 2u
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinWait_get_exited(const R4SdkTransportNative_app_resources_JoinWait *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,210u,0u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinWait_set_exited(R4SdkTransportNative_app_resources_JoinWait *self, int32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,210u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinWait_get_timed_out(const R4SdkTransportNative_app_resources_JoinWait *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,210u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinWait_set_timed_out(R4SdkTransportNative_app_resources_JoinWait *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,210u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinWait_get_failure(const R4SdkTransportNative_app_resources_JoinWait *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,210u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinWait_set_failure(R4SdkTransportNative_app_resources_JoinWait *self, int32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,210u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_resources_JoinWait_inspectNative(const R4SdkTransportNative_app_resources_JoinWait *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,210u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_resources_JoinWait____union__tag_type___create(R4SdkTransportNative__typeInfo_app_resources_JoinWait____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,211u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_resources_JoinWait____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_app_resources_JoinWait____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,211u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue214_inspectNative(const R4SdkTransportNativeValue214 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,214u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue215_create(R4SdkTransportNativeValue215 *output, R4SdkTransportDocumentsSet * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,215u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue215_inspectNative(const R4SdkTransportNativeValue215 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,215u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue218_inspectNative(const R4SdkTransportNativeValue218 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,218u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue219_create(R4SdkTransportNativeValue219 *output, const R4SdkTransportDocumentsSet * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,219u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue219_inspectNative(const R4SdkTransportNativeValue219 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,219u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue221_inspectNative(const R4SdkTransportNativeValue221 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,221u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue222_inspectNative(const R4SdkTransportNativeValue222 *self, R4SdkTransportFetchHeaders *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,222u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue223_create(R4SdkTransportNativeValue223 *output, R4SdkTransportFetchHeaders * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,223u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue223_inspectNative(const R4SdkTransportNativeValue223 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,223u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue224_inspectNative(const R4SdkTransportNativeValue224 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,224u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue225_create(R4SdkTransportNativeValue225 *output, const R4SdkTransportFetchHeaders * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,225u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue225_inspectNative(const R4SdkTransportNativeValue225 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,225u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue226_inspectNative(const R4SdkTransportNativeValue226 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,226u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue227_inspectNative(const R4SdkTransportNativeValue227 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,227u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue228_create(R4SdkTransportNativeValue228 *output, R4SdkTransportNativeValue229 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,228u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue228_inspectNative(const R4SdkTransportNativeValue228 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,228u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue229_create(R4SdkTransportNativeValue229 *output, const R4SdkTransportNativeValue229 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,229u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue229_inspectNative(const R4SdkTransportNativeValue229 *self, R4SdkTransportNativeValue229 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,229u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue230_inspectNative(const R4SdkTransportNativeValue230 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,230u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue231_create(R4SdkTransportNativeValue231 *output, R4SdkTransportNativeValue232 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,231u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue231_inspectNative(const R4SdkTransportNativeValue231 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,231u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue232_create(R4SdkTransportNativeValue232 *output, const R4SdkTransportNativeValue232 * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,232u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue232_inspectNative(const R4SdkTransportNativeValue232 *self, R4SdkTransportNativeValue232 *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,232u,(void *)self,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue233_create(R4SdkTransportNativeValue233 *output, const uint64_t * p0, uintptr_t n0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.length=n0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,233u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue233_inspectNative(const R4SdkTransportNativeValue233 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,233u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue234_create(R4SdkTransportNativeValue234 *output, R4SdkTransportNative_app_network_Resolver * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,234u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue234_inspectNative(const R4SdkTransportNativeValue234 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,234u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue235_create(R4SdkTransportNativeValue235 *output, R4SdkTransportSlot p0) { R4SdkTransportSlot a[1]={0};
 a[0] = p0;
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,235u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue235_inspectNative(const R4SdkTransportNativeValue235 *self, R4SdkTransportNative_app_network_Ipv4Address *output) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,235u,(void *)self,output); }
#define R4SdkTransportNative_app_network_ResolveResult_TAG_address 0u
#define R4SdkTransportNative_app_network_ResolveResult_TAG_timed_out 1u
#define R4SdkTransportNative_app_network_ResolveResult_TAG_not_found 2u
#define R4SdkTransportNative_app_network_ResolveResult_TAG_no_service 3u
#define R4SdkTransportNative_app_network_ResolveResult_TAG_failure 4u
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ResolveResult_get_address(const R4SdkTransportNative_app_network_ResolveResult *self, R4SdkTransportNative_app_network_Ipv4Address *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,236u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ResolveResult_set_address(R4SdkTransportNative_app_network_ResolveResult *self, const R4SdkTransportNative_app_network_Ipv4Address * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,236u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ResolveResult_get_timed_out(const R4SdkTransportNative_app_network_ResolveResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,236u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ResolveResult_set_timed_out(R4SdkTransportNative_app_network_ResolveResult *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,236u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ResolveResult_get_not_found(const R4SdkTransportNative_app_network_ResolveResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,236u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ResolveResult_set_not_found(R4SdkTransportNative_app_network_ResolveResult *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,236u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ResolveResult_get_no_service(const R4SdkTransportNative_app_network_ResolveResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,236u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ResolveResult_set_no_service(R4SdkTransportNative_app_network_ResolveResult *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,236u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ResolveResult_get_failure(const R4SdkTransportNative_app_network_ResolveResult *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,236u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ResolveResult_set_failure(R4SdkTransportNative_app_network_ResolveResult *self, int32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,236u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_ResolveResult_inspectNative(const R4SdkTransportNative_app_network_ResolveResult *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,236u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type___create(R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,237u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_app_network_ResolveResult____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,237u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue238_create(R4SdkTransportNativeValue238 *output, const R4SdkTransportNative_app_network_TcpListener * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,238u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue238_inspectNative(const R4SdkTransportNativeValue238 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,238u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue239_create(R4SdkTransportNativeValue239 *output, R4SdkTransportNative_app_network_TcpListener * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,239u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue239_inspectNative(const R4SdkTransportNativeValue239 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,239u,(void *)self,0); }
#define R4SdkTransportNative_app_network_TcpAccept_TAG_socket 0u
#define R4SdkTransportNative_app_network_TcpAccept_TAG_would_block 1u
#define R4SdkTransportNative_app_network_TcpAccept_TAG_timed_out 2u
#define R4SdkTransportNative_app_network_TcpAccept_TAG_reset 3u
#define R4SdkTransportNative_app_network_TcpAccept_TAG_closed 4u
#define R4SdkTransportNative_app_network_TcpAccept_TAG_no_service 5u
#define R4SdkTransportNative_app_network_TcpAccept_TAG_failure 6u
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_get_socket(const R4SdkTransportNative_app_network_TcpAccept *self, R4SdkTransportNative_app_network_TcpSocket *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_set_socket(R4SdkTransportNative_app_network_TcpAccept *self, const R4SdkTransportNative_app_network_TcpSocket * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_get_would_block(const R4SdkTransportNative_app_network_TcpAccept *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_set_would_block(R4SdkTransportNative_app_network_TcpAccept *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_get_timed_out(const R4SdkTransportNative_app_network_TcpAccept *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_set_timed_out(R4SdkTransportNative_app_network_TcpAccept *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_get_reset(const R4SdkTransportNative_app_network_TcpAccept *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_set_reset(R4SdkTransportNative_app_network_TcpAccept *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_get_closed(const R4SdkTransportNative_app_network_TcpAccept *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_set_closed(R4SdkTransportNative_app_network_TcpAccept *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_get_no_service(const R4SdkTransportNative_app_network_TcpAccept *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_set_no_service(R4SdkTransportNative_app_network_TcpAccept *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_get_failure(const R4SdkTransportNative_app_network_TcpAccept *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_set_failure(R4SdkTransportNative_app_network_TcpAccept *self, int32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,240u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_TcpAccept_inspectNative(const R4SdkTransportNative_app_network_TcpAccept *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,240u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type___create(R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,241u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_app_network_TcpAccept____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,241u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue242_create(R4SdkTransportNativeValue242 *output, const R4SdkTransportNative_app_network_UdpSocket * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,242u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue242_inspectNative(const R4SdkTransportNativeValue242 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,242u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue243_create(R4SdkTransportNativeValue243 *output, R4SdkTransportNative_app_network_UdpSocket * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,243u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNativeValue243_inspectNative(const R4SdkTransportNativeValue243 *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,243u,(void *)self,0); }
#define R4SdkTransportNative_app_network_UdpReceive_TAG_datagram 0u
#define R4SdkTransportNative_app_network_UdpReceive_TAG_would_block 1u
#define R4SdkTransportNative_app_network_UdpReceive_TAG_timed_out 2u
#define R4SdkTransportNative_app_network_UdpReceive_TAG_reset 3u
#define R4SdkTransportNative_app_network_UdpReceive_TAG_peer_closed 4u
#define R4SdkTransportNative_app_network_UdpReceive_TAG_closed 5u
#define R4SdkTransportNative_app_network_UdpReceive_TAG_no_service 6u
#define R4SdkTransportNative_app_network_UdpReceive_TAG_failure 7u
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_get_datagram(const R4SdkTransportNative_app_network_UdpReceive *self, R4SdkTransportNative_app_network_Datagram *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_set_datagram(R4SdkTransportNative_app_network_UdpReceive *self, const R4SdkTransportNative_app_network_Datagram * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_get_would_block(const R4SdkTransportNative_app_network_UdpReceive *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,1u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_set_would_block(R4SdkTransportNative_app_network_UdpReceive *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_get_timed_out(const R4SdkTransportNative_app_network_UdpReceive *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_set_timed_out(R4SdkTransportNative_app_network_UdpReceive *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_get_reset(const R4SdkTransportNative_app_network_UdpReceive *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,3u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_set_reset(R4SdkTransportNative_app_network_UdpReceive *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,3u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_get_peer_closed(const R4SdkTransportNative_app_network_UdpReceive *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,4u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_set_peer_closed(R4SdkTransportNative_app_network_UdpReceive *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,4u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_get_closed(const R4SdkTransportNative_app_network_UdpReceive *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,5u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_set_closed(R4SdkTransportNative_app_network_UdpReceive *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,5u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_get_no_service(const R4SdkTransportNative_app_network_UdpReceive *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,6u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_set_no_service(R4SdkTransportNative_app_network_UdpReceive *self) { R4SdkTransportSlot a[1]={0};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,6u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_get_failure(const R4SdkTransportNative_app_network_UdpReceive *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,7u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_set_failure(R4SdkTransportNative_app_network_UdpReceive *self, int32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,244u,7u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_UdpReceive_inspectNative(const R4SdkTransportNative_app_network_UdpReceive *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,244u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type___create(R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type__ *output, uint32_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,245u,a,1u,output); }
static inline R4SdkTransportSlot R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type___inspectNative(const R4SdkTransportNative__typeInfo_app_network_UdpReceive____union__tag_type__ *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,245u,(void *)self,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Datagram_create(R4SdkTransportNative_app_network_Datagram *output, const R4SdkTransportNative_app_network_SocketAddress * p0, const R4SdkTransportNative_app_network_SocketAddress * p1, uint64_t p2) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,246u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Datagram_from_fields(R4SdkTransportNative_app_network_Datagram *output, const R4SdkTransportNative_app_network_SocketAddress * p0, const R4SdkTransportNative_app_network_SocketAddress * p1, uint64_t p2) {
 R4SdkTransportSlot a[3]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 a[1] = (R4SdkTransportSlot){.ptr=(void *)p1,.flags=R4SDKTRANSPORT_PRESENT};
 a[2] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p2,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportConstruct(R4SdkTransport_ABI_FINGERPRINT,246u,a,3u,output);
}
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Datagram_get_source(const R4SdkTransportNative_app_network_Datagram *self, R4SdkTransportNative_app_network_SocketAddress *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,246u,0u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Datagram_set_source(R4SdkTransportNative_app_network_Datagram *self, const R4SdkTransportNative_app_network_SocketAddress * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,246u,0u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Datagram_get_destination(const R4SdkTransportNative_app_network_Datagram *self, R4SdkTransportNative_app_network_SocketAddress *output) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,246u,1u,(void *)self,0,output); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Datagram_set_destination(R4SdkTransportNative_app_network_Datagram *self, const R4SdkTransportNative_app_network_SocketAddress * p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.ptr=(void *)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,246u,1u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Datagram_get_bytes(const R4SdkTransportNative_app_network_Datagram *self) { return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,246u,2u,(void *)self,0,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Datagram_set_bytes(R4SdkTransportNative_app_network_Datagram *self, uint64_t p0) { R4SdkTransportSlot a[1]={0};
 a[0] = (R4SdkTransportSlot){.bits=(uint64_t)(int64_t)p0,.flags=R4SDKTRANSPORT_PRESENT};
 return R4SdkTransportField(R4SdkTransport_ABI_FINGERPRINT,246u,2u,self,a,0); }
static inline R4SdkTransportSlot R4SdkTransportNative_app_network_Datagram_inspectNative(const R4SdkTransportNative_app_network_Datagram *self) { return R4SdkTransportInspect(R4SdkTransport_ABI_FINGERPRINT,246u,(void *)self,0); }
#endif
