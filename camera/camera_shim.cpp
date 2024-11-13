/*
 * Copyright (C) 2017 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string>
#include <ui/GraphicBuffer.h>

using android::PixelFormat;
using android::status_t;

extern "C" {

void* _ZN7android13GraphicBufferC1EjjijjjP13native_handleb(
        void* thisptr,
        const native_handle_t* handle,
        android::GraphicBuffer::HandleWrapMethod method,
        uint32_t width,
        uint32_t height,
        int format,
        uint32_t layerCount,
        uint64_t usage,
        uint32_t stride);

void* _ZN7android13GraphicBufferC1EjjijjP13native_handleb(
        void* thisptr,
        uint32_t inWidth,
        uint32_t inHeight,
        int inFormat,
        uint32_t inUsage,
        uint32_t inStride,
        native_handle_t* inHandle,
        bool keepOwnership)
{
    android::GraphicBuffer::HandleWrapMethod inMethod =
        (keepOwnership ? android::GraphicBuffer::TAKE_HANDLE : android::GraphicBuffer::WRAP_HANDLE);
    return _ZN7android13GraphicBufferC1EjjijjjP13native_handleb(thisptr, inHandle, inMethod, inWidth, inHeight,
        inFormat, static_cast<uint32_t>(1), static_cast<uint64_t>(inUsage), inStride);
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
status_t _ZN7android19GraphicBufferMapper12importBufferEPK13native_handlePS3_(
        void* thisptr, buffer_handle_t rawHandle, buffer_handle_t* outHandle) {
#if defined(__LP64__)
    return _ZN7android19GraphicBufferMapper12importBufferEPK13native_handlejjjimjPS3_(
            thisptr, rawHandle, -1, -1, -1, android::PIXEL_FORMAT_NONE, -1, -1, outHandle);
#else
    return _ZN7android19GraphicBufferMapper12importBufferEPK13native_handlejjjiyjPS3_(
            thisptr, rawHandle, -1, -1, -1, android::PIXEL_FORMAT_NONE, -1, -1, outHandle);
#endif
}

} // extern "C"
