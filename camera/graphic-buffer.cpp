/*
 * Copyright (C) 2015 The Android Open Source Project
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

#include <ui/GraphicBufferMapper.h>
#include <ui/Rect.h>

using android::PixelFormat;
using android::Rect;
using android::status_t;

extern "C" {

/* status_t GraphicBufferMapper::lock */
status_t _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPvPiS9_(
        void* thisptr, buffer_handle_t handle, uint32_t usage, const Rect& bounds, void** vaddr,
        int32_t* outBytesPerPixel, int32_t* outBytesPerStride);

status_t _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPv(
        void* thisptr, buffer_handle_t handle, uint32_t usage, const Rect& bounds, void** vaddr)
{
    return _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPvPiS9_(
            thisptr, handle, usage, bounds, vaddr, nullptr, nullptr);
}

void* _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(
        void *thisptr, uint32_t inWidth, uint32_t inHeight, PixelFormat inFormat,
        uint32_t inUsage, std::string requestorName);

void* _ZN7android13GraphicBufferC1Ejjij(
        void *thisptr, uint32_t inWidth, uint32_t inHeight,
        PixelFormat inFormat, uint32_t inUsage)
{
    std::string requestorName = "<Unknown>";
    return _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(
        thisptr, inWidth, inHeight, inFormat, inUsage, requestorName);
}

} // extern "C"
