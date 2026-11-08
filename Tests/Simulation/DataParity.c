#include <r4os/facades.h>
#include <string.h>
#define WIRE_CHECK(test,code) do { if (!(test)) return (code); } while (0)
int32_t sdk_wire_c_case(void) {
    _Alignas(8) const uint8_t data[]={0xff,1,2,3,4,5,6,7,8};
    R4SdkWireReader reader;uint64_t value=99;
    WIRE_CHECK(R4SdkWireReaderInit(data+1,8,&reader)==0,101);
    WIRE_CHECK(R4SdkWireReadInteger(&reader,2,R4_WIRE_BIG,&value)==0 && value==0x0102,102);
    R4SdkWireMark mark;WIRE_CHECK(R4SdkWireReaderMark(&reader,&mark)==0,103);
    value=99;WIRE_CHECK(R4SdkWireReadInteger(&reader,8,R4_WIRE_LITTLE,&value)==R4_WIRE_TRUNCATED && value==99 && reader.position==2,104);
    WIRE_CHECK(R4SdkWireReaderRestore(&reader,mark)==0,105);
    WIRE_CHECK(R4SdkWireReadInteger(&reader,4,R4_WIRE_LITTLE,&value)==0 && value==0x06050403,106);
    mark.kind=2;WIRE_CHECK(R4SdkWireReaderRestore(&reader,mark)==R4_WIRE_INVALID_MARK && reader.position==6,107);
    WIRE_CHECK(R4SdkWireReaderInit(0,0,&reader)==0,108);
    R4SdkWireSpan span;WIRE_CHECK(R4SdkWireTake(&reader,0,&span)==0 && !span.length,109);
    WIRE_CHECK(R4SdkWireTake(&reader,1,&span)==R4_WIRE_TRUNCATED,110);
    uint8_t bytes[]={0,1,2,3,4,5,6,7};R4SdkWireWriter writer;
    WIRE_CHECK(R4SdkWireWriterInit(bytes,8,&writer)==0,111);writer.position=2;
    WIRE_CHECK(R4SdkWirePut(&writer,bytes,6)==0 && memcmp(bytes,(uint8_t[]){0,1,0,1,2,3,4,5},8)==0,112);
    WIRE_CHECK(R4SdkWireWriteInteger(&writer,2,R4_WIRE_BIG,65536)==R4_WIRE_VALUE_OVERFLOW && writer.position==8,113);
    uint8_t before[8];memcpy(before,bytes,8);
    WIRE_CHECK(R4SdkWireWriteInteger(&writer,2,R4_WIRE_BIG,1)==R4_WIRE_CAPACITY && memcmp(before,bytes,8)==0,114);
    const uint8_t rfc[]={0x00,0x01,0xf2,0x03,0xf4,0xf5,0xf6,0xf7};
    for(uintptr_t cut=0;cut<=sizeof(rfc);++cut){
        R4SdkChecksum16 checksum;uint16_t result=0;
        WIRE_CHECK(R4SdkChecksumInit(&checksum)==0,115);
        WIRE_CHECK(R4SdkChecksumAdd(&checksum,rfc,cut)==0 && R4SdkChecksumAdd(&checksum,rfc+cut,sizeof(rfc)-cut)==0,116);
        WIRE_CHECK(R4SdkChecksumFinish(&checksum,&result)==0 && result==0x220d,117);
    }
    R4SdkChecksum16 checksum;uint16_t sum=0;
    WIRE_CHECK(R4SdkChecksumInit(&checksum)==0 && R4SdkChecksumAdd(&checksum,(uint8_t[]){1},1)==0 && R4SdkChecksumAdd(&checksum,(uint8_t[]){2,3},2)==0,118);
    R4SdkChecksum16 saved=checksum;
    WIRE_CHECK(R4SdkChecksumFinish(&checksum,&sum)==0 && sum==0xfbfd && memcmp(&saved,&checksum,sizeof(saved))==0,119);
    checksum=(R4SdkChecksum16){.bytes=UINT64_MAX-1};saved=checksum;
    WIRE_CHECK(R4SdkChecksumAdd(&checksum,(uint8_t[]){0,1},2)==R4_CHECKSUM_LENGTH_OVERFLOW && memcmp(&saved,&checksum,sizeof(saved))==0,120);
    typedef struct {uint32_t version,size;uint64_t value;} Record;
    Record record={1,16,0x1234};R4ProtocolBuffer buffer={.data=&record,.len=16,.capacity=16};
    R4SdkNativePolicy policy=R4SDK_NATIVE_VERSIONED(Record,1,R4_NATIVE_INPUT,R4_NATIVE_EXACT);uintptr_t address=77;
    WIRE_CHECK(R4SdkNativeAdmit(&buffer,policy,R4_NATIVE_INPUT,&address)==0 && address==(uintptr_t)&record,121);
    record.version=2;address=77;
    WIRE_CHECK(R4SdkNativeAdmit(&buffer,policy,R4_NATIVE_INPUT,&address)==R4_NATIVE_UNSUPPORTED_VERSION && address==77,122);
    record.version=1;buffer.flags=1;
    WIRE_CHECK(R4SdkNativeAdmit(&buffer,policy,R4_NATIVE_INPUT,&address)==R4_NATIVE_FLAGS,123);buffer.flags=0;
    buffer.data=(uint8_t *)&record+1;
    WIRE_CHECK(R4SdkNativeAdmit(&buffer,policy,R4_NATIVE_INPUT,&address)==R4_NATIVE_MISALIGNED,124);
    Record output;buffer=(R4ProtocolBuffer){.data=&output,.capacity=16};
    policy=R4SDK_NATIVE_VERSIONED(Record,1,R4_NATIVE_OUTPUT,R4_NATIVE_EXACT);
    WIRE_CHECK(R4SdkNativeAdmit(&buffer,policy,R4_NATIVE_OUTPUT,&address)==0,125);
    output=(Record){2,16,55};
    WIRE_CHECK(R4SdkNativePublish(&buffer,policy,16)==R4_NATIVE_UNSUPPORTED_VERSION && !buffer.len,126);
    output.version=1;WIRE_CHECK(R4SdkNativePublish(&buffer,policy,16)==0 && buffer.len==16,127);
    R4SdkBlockLimits limits={1000,128,1048576,28,R4_BLOCK_EXACT};R4SdkBlockShape shape={0,0};
    WIRE_CHECK(R4SdkBlockTransfer(996,4,4096,16384,limits,&shape)==0 && shape.byte_count==16384 && shape.last_lba==999,128);
    R4SdkBlockShape old=shape;
    WIRE_CHECK(R4SdkBlockTransfer(997,4,4096,16384,limits,&shape)==R4_BLOCK_OUT_OF_RANGE && memcmp(&old,&shape,sizeof(old))==0,129);
    WIRE_CHECK(R4SdkBlockTransfer(UINT64_MAX,2,1,2,limits,&shape)==R4_BLOCK_OVERFLOW,130);
    limits.capacity_blocks=0;WIRE_CHECK(R4SdkBlockTransfer(0,1,512,512,limits,&shape)==R4_BLOCK_UNKNOWN_GEOMETRY,131);
    return 0;
}
#undef WIRE_CHECK
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

int32_t sdk_ico_c_case(const uint8_t *bytes,uintptr_t length){
    R4SdkDataIcoEntry entry;R4SdkDataIcoBitmapImage image;
    if(!ok(R4SdkDataIco_chooseBest(0,bytes,length,32,&entry)) ||
       !ok(R4SdkDataIco_parseBmpImage(0,bytes,length,&entry,&image)))return 1;
    const uint32_t colors[2][4]={{0x0000ff,0x00ff00,0xff0000,0xffffff},{0xff0000,0x0000ff,0x0000ff,0xff0000}};
    const uint8_t opacity[4]={255,0,255,255};
    uint32_t rgb[24];uint8_t alpha[24];
    for(uint32_t i=0;i<24;++i){rgb[i]=0x12345678;alpha[i]=91;}
    R4SdkDataSlot value=R4SdkDataIco_copyScaledPixels(0,bytes,length,&image,rgb,24,alpha,24,4,4,6);
    if(!ok(value)||value.bits!=1)return 2;
    uint32_t indexed=R4SdkDataIcoBitmapImage_get_bpp(&image).bits==8;
    for(uint32_t i=0;i<24;++i){
        uint32_t x=i%6,y=i/6;
        if(x<4){uint32_t at=(y/2)*2+x/2;if(rgb[i]!=colors[indexed][at]||alpha[i]!=opacity[at])return 3;}
        else if(rgb[i]!=0x12345678||alpha[i]!=91)return 4;
    }
    uint32_t before[24];memcpy(before,rgb,sizeof rgb);
    value=R4SdkDataIco_copyScaledPixels(0,bytes,length,&image,rgb,3,alpha,24,2,2,2);
    if(!ok(value)||value.bits||memcmp(before,rgb,sizeof rgb))return 5;
    value=R4SdkDataIco_copyScaledPixels(0,bytes,length,&image,rgb,24,(uint8_t *)rgb,sizeof rgb,2,2,2);
    if(!ok(value)||value.bits||memcmp(before,rgb,sizeof rgb))return 6;
    value=R4SdkDataIco_copyScaledPixels(0,bytes,length,&image,rgb,24,alpha,24,2,2,UINTPTR_MAX);
    if(!ok(value)||value.bits||memcmp(before,rgb,sizeof rgb))return 7;
    if(!ok(R4SdkDataIcoBitmapImage_set_pixel_offset(&image,UINTPTR_MAX)))return 8;
    value=R4SdkDataIco_copyScaledPixels(0,bytes,length,&image,rgb,24,alpha,24,2,2,2);
    if(!ok(value)||value.bits||memcmp(before,rgb,sizeof rgb))return 9;
    return 0;
}
