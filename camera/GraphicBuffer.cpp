/*
 * Copyright (C) 2022-2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <ui/GraphicBuffer.h>

using android::PixelFormat;

extern "C" {

void _ZN7android13GraphicBufferC1EjjijjjP13native_handleb(void* thisptr, uint32_t inWidth, uint32_t inHeight,
        PixelFormat inFormat, uint32_t inLayerCount, uint32_t inUsage,
        uint32_t inStride, native_handle_t* inHandle, bool keepOwnership);

void _ZN7android13GraphicBufferC1EjjijjP13native_handleb(void* thisptr, uint32_t inWidth, uint32_t inHeight,
        PixelFormat inFormat, uint32_t inUsage, uint32_t inStride,
        native_handle_t* inHandle, bool keepOwnership) {
    _ZN7android13GraphicBufferC1EjjijjjP13native_handleb(thisptr, inWidth, inHeight, inFormat, -1, inUsage, inStride, inHandle, keepOwnership);
}

}
