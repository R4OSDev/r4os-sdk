#include <r4os/facades.h>
#include <string.h>
static int ok(R4SdkDataSlot v){return !v.status && !(v.flags&R4SDKDATA_NATIVE_ERROR);}
int32_t sdk_data_c_case(const uint8_t *manifest,uintptr_t length){
    R4SdkDataSlot role=R4SdkDataJson_constant_role();
    if(!ok(role) || role.length!=11 || memcmp(role.ptr,"format.json",11))return 16;
    R4SdkDataSha256 hash;uint8_t digest[R4SdkDataSha256_digest_length];
    _Static_assert(R4SdkDataSha256_digest_length==32,"SHA256 digest bytes");
    if(!ok(R4SdkData_hashInit(0,&hash)) || !ok(R4SdkDataSha256_update(0,&hash,(const uint8_t *)"abc",3)) || !ok(R4SdkDataSha256_finalResult(0,&hash,(void *)digest)))return 1;
    if(digest[0]!=0xba || digest[31]!=0xad)return 2;
    R4SdkDataEncodingDecoder decoder;uint8_t out[16];
    if(!ok(R4SdkDataEncodingDecoder_init(0,R4SdkDataEncodingEncoding_utf8,1,0,&decoder)))return 3;
    R4SdkDataSlot value=R4SdkDataEncodingDecoder_decode(0,&decoder,(const uint8_t *)"\xc3",1,out,sizeof(out),1);
    if(!ok(value) || value.length)return 4;
    value=R4SdkDataEncodingDecoder_decode(0,&decoder,(const uint8_t *)"\xbc",1,out,sizeof(out),0);
    if(!ok(value) || value.length!=2 || memcmp(value.ptr,"\xc3\xbc",2))return 5;
    R4SdkDataRandomProvider random;
    if(!ok(R4SdkDataRandomProvider_create(&random)))return 6;
    memset(out,0xa5,sizeof(out));value=R4SdkDataRandomProvider_fill(0,&random,out,sizeof(out));
    if(!ok(value) || value.bits)return 7;
    for(uintptr_t i=0;i<sizeof(out);++i)if(out[i])return 8;
    value=R4SdkDataJson_mapStatus(0,-9);
    if(!ok(value) || !(value.flags&R4SDKDATA_PRESENT) || value.length!=10 || memcmp(value.ptr,"WrongToken",10))return 9;
    R4SdkDataArena arena;R4SdkDataAllocator allocator;R4SdkDataManifestManifest parsed;uint8_t scratch[65536];
    if(!ok(R4SdkData_arena(0,&arena,scratch,sizeof(scratch))) || !ok(R4SdkData_allocator(0,&arena,&allocator)))return 10;
    if(!ok(R4SdkDataManifest_parse(0,&allocator,(const uint8_t *)"module.R4MF",11,manifest,length,&parsed)))return 11;
    value=R4SdkDataManifestManifest_get_name(&parsed);
    if(!ok(value) || value.length!=8 || memcmp(value.ptr,"DATAUNIT",8))return 12;
    R4SdkDataManifestModuleVersion version;
    if(!ok(R4SdkDataManifestManifest_get_module_version(&parsed,&version)) || R4SdkDataManifestModuleVersion_get_patch(&version).bits!=3)return 13;
    R4SdkDataUrlSearchParams params;
    if(!ok(R4SdkDataUrlSearchParams_init(0,(const uint8_t *)"a=one+two&a=three",17,&params)))return 14;
    value=R4SdkDataUrlSearchParams_get(0,&params,(const uint8_t *)"a",1);
    if(!ok(value) || value.length!=7 || memcmp(value.ptr,"one two",7))return 15;
    return 0;
}
