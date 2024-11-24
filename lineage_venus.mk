# Copyright (C) 2020 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

$(call inherit-product, $(LOCAL_PATH)/pre-base.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base_telephony.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Inherit from frd device
$(call inherit-product, $(LOCAL_PATH)/device.mk)

# Boot animation
TARGET_SCREEN_HEIGHT := 1920
TARGET_SCREEN_WIDTH := 1080

# Shipping API level (for CTS backward compatibility)
PRODUCT_SHIPPING_API_LEVEL := 23

PRODUCT_GMS_CLIENTID_BASE := android-huawei

LINEAGE_BUILDTYPE := RELEASE

PRODUCT_NAME := lineage_venus
PRODUCT_DEVICE := venus
PRODUCT_BRAND := Huawei
PRODUCT_MANUFACTURER := HUAWEI
PRODUCT_MODEL := Huawei-P9-Lite

PRODUCT_SYSTEM_NAME := venus

PRODUCT_BUILD_PROP_OVERRIDES += \
    TARGET_PRODUCT=venus \
    PRIVATE_BUILD_DESC="VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys"

# Set BUILD_FINGERPRINT variable to be picked up by both system and vendor build.prop
BUILD_FINGERPRINT := "HUAWEI/VNS-L23/HWVNS-H:7.0/HUAWEIVNS-L23/C605B396:user/release-keys"
