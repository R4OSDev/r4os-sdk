#ifndef R4OS_FACADES_H
#define R4OS_FACADES_H
#include "app_storage.h"
#include "app_resources.h"
#include "storage.h"
#include "storage_helpers.h"
#include "directory_page.h"

int32_t R4SdkAppFacade(const R4XStartContext *, R4App *);

/* SDK-local object functions. These are not new platform API slots. */
int32_t R4SdkFilePath(const uint8_t *, uintptr_t, int32_t, uint8_t *, uintptr_t, uint16_t *, uint8_t *);
int32_t R4SdkRegistryPath(const uint8_t *, uintptr_t, uint8_t *, uintptr_t, uint16_t *);
#endif
