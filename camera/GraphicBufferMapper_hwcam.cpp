/*
 * Copyright (C) 2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <ui/GraphicBufferMapper.h>
#include <utils/Errors.h>
#include <libexif/exif-entry.h>

using android::PixelFormat;
using android::status_t;

extern "C" {
void exif_entry_gps_initialize(ExifEntry * e, ExifTag tag) {
    exif_entry_initialize(e,tag);
}

#if defined(__LP64__)
status_t _ZN7android19GraphicBufferMapper12importBufferEPK13native_handlejjjimjPS3_(
        void* thisptr, buffer_handle_t rawHandle, uint32_t width, uint32_t height,
        uint32_t layerCount, PixelFormat format, uint64_t usage, uint32_t stride,
        buffer_handle_t* outHandle);
#else
status_t _ZN7android19GraphicBufferMapper12importBufferEPK13native_handlejjjiyjPS3_(
        void* thisptr, buffer_handle_t rawHandle, uint32_t width, uint32_t height,
        uint32_t layerCount, PixelFormat format, uint64_t usage, uint32_t stride,
        buffer_handle_t* outHandle);
#endif

status_t _ZN7android19GraphicBufferMapper14registerBufferEPK13native_handle(
    void *thisptr, buffer_handle_t rawHandle) {
#if defined(__LP64__)
return _ZN7android19GraphicBufferMapper12importBufferEPK13native_handlejjjimjPS3_(
            thisptr, rawHandle, -1, -1, -1, android::PIXEL_FORMAT_NONE, -1, -1, nullptr);
#else
return _ZN7android19GraphicBufferMapper12importBufferEPK13native_handlejjjiyjPS3_(
            thisptr, rawHandle, -1, -1, -1, android::PIXEL_FORMAT_NONE, -1, -1, nullptr);
#endif
}

status_t _ZN7android19GraphicBufferMapper10freeBufferEPK13native_handle(
    void *thisptr, buffer_handle_t handle);

status_t _ZN7android19GraphicBufferMapper16unregisterBufferEPK13native_handle(
    void *thisptr, buffer_handle_t handle) {
  return _ZN7android19GraphicBufferMapper10freeBufferEPK13native_handle(thisptr,
                                                                        handle);
}

}
