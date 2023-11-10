#
# Copyright (C) 2020 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

DEVICE_PATH := device/huawei/vns

# Architecture
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_ABI2 :=
TARGET_CPU_VARIANT := generic
TARGET_CPU_VARIANT_RUNTIME := cortex-a53

TARGET_2ND_ARCH := arm
TARGET_2ND_ARCH_VARIANT := armv8-a
TARGET_2ND_CPU_ABI := armeabi-v7a
TARGET_2ND_CPU_ABI2 := armeabi
TARGET_2ND_CPU_VARIANT := generic
TARGET_2ND_CPU_VARIANT_RUNTIME := cortex-a53

TARGET_BOARD_SUFFIX := _64
TARGET_USES_64_BIT_BINDER := true

TARGET_BOARD_PLATFORM_GPU := Mali-T830
TARGET_BOARD_PLATFORM := hi6250
BOARD_VENDOR_PLATFORM := hi6250

# Assert
TARGET_OTA_ASSERT_DEVICE := hi6250,vns

# Android Q
BUILD_BROKEN_DUP_RULES := true

# Audio
BOARD_USES_ALSA_AUDIO := true
BOARD_SUPPORTS_SOUND_TRIGGER := true
USE_XML_AUDIO_POLICY_CONF := 1

TARGET_ENABLE_QC_AV_ENHANCEMENTS := true

# Bootloader
TARGET_BOOTLOADER_BOARD_NAME := hi6250
TARGET_NO_BOOTLOADER := true
TARGET_NO_RADIOIMAGE := true

# Bluetooth
BOARD_HAVE_BLUETOOTH := true

# Bootanimation
TARGET_BOOTANIMATION_PRELOAD := true
TARGET_BOOTANIMATION_TEXTURE_CACHE := true

# Charger 
BOARD_CHARGER_DISABLE_INIT_BLANK := true
BACKLIGHT_PATH := /sys/class/leds/lcd_backlight0/brightness

# Extended Filesystem Support
TARGET_FS_CONFIG_GEN := $(DEVICE_PATH)/prebuilts/config.fs
TARGET_EXFAT_DRIVER := sdfat

# FONTS
EXTENDED_FONT_FOOTPRINT := true
    
# Display
USE_OPENGL_RENDERER := true
TARGET_HARDWARE_3D := true
ANDROID_ENABLE_RENDERSCRIPT := true
TARGET_USES_ION := true
TARGET_SCREEN_DENSITY := 400
TARGET_ADDITIONAL_GRALLOC_10_USAGE_BITS := 0x2080000U

# Encryption
TARGET_PROVIDES_KEYMASTER := true

# GPS
USE_DEVICE_SPECIFIC_GPS := true
TARGET_NO_RPC := true

# HIDL
DEVICE_MANIFEST_FILE := $(DEVICE_PATH)/prebuilts/manifest.xml
DEVICE_MATRIX_FILE := $(DEVICE_PATH)/prebuilts/compatibility_matrix.xml

# Kernel
BOARD_KERNEL_PAGESIZE := 2048
BOARD_KERNEL_BASE := 0x00478000
BOARD_KERNEL_CMDLINE := loglevel=4 coherent_pool=512K page_tracker=on slub_min_objects=12 unmovable_isolate1=2:192M,3:224M,4:256M androidboot.selinux=permissive
BOARD_KERNEL_CMDLINE += loop.max_part=7
BOARD_MKBOOTIMG_ARGS := --kernel_offset 0x00008000 --ramdisk_offset 0x07b88000 --tags_offset 0x07588000
TARGET_KERNEL_ARCH := arm64
TARGET_KERNEL_HEADER_ARCH := arm64
BOARD_KERNEL_IMAGE_NAME := Image.gz
TARGET_KERNEL_SOURCE := kernel/huawei/vns
TARGET_KERNEL_CONFIG := hisi_6250_defconfig
TARGET_KERNEL_VERSION := 4.4

# Lights
TARGET_PROVIDES_LIBLIGHT := true

# Malloc
MALLOC_SVELTE := true

# NFC
TARGET_USES_NQ_NFC := true

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 33554432
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 67108864
BOARD_CACHEIMAGE_PARTITION_SIZE := 268435456
#BOARD_SYSTEMIMAGE_PARTITION_SIZE := 4262461440 
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2080374784
BOARD_USERDATAIMAGE_PARTITION_SIZE := 11546918912
BOARD_VENDORIMAGE_PARTITION_SIZE   := 637534208

BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_VENDORIMAGE_FILE_SYSTEM_TYPE := ext4

TARGET_USERIMAGES_USE_EXT4 := true
TARGET_USERIMAGES_USE_F2FS := true
BOARD_FLASH_BLOCK_SIZE := 131072
TARGET_USES_MKE2FS := true

BOARD_ROOT_EXTRA_FOLDERS :=  \
	cust \
	version \
	produce \
	3rdmodem \
	3rdmodemnvm \
	3rdmodemnvmbkp \
	sec_storage \
	modem_log \
	mnvm2:0 \
	modem_fw \
	splash2 \
	patch_hw
    
BOARD_ROOT_EXTRA_SYMLINKS += \
	/vendor/odm:/odm \
	/vendor/odm/hw_odm:/hw_odm
	
# Power
TARGET_HAS_LEGACY_POWER_STATS := true

# Recovery
TARGET_RECOVERY_FSTAB := $(DEVICE_PATH)/rootdir/fstab.hi6250

# RIL
TARGET_BUILD_JAVA_SUPPORT_LEVEL := platform
TARGET_USES_OLD_MNC_FORMAT := true

#GO
PRODUCT_SYSTEM_SERVER_COMPILER_FILTER := speed-profile
PRODUCT_ALWAYS_PREOPT_EXTRACTED_APK := true
PRODUCT_ART_TARGET_INCLUDE_DEBUG_BUILD := false
PRODUCT_PACKAGES += InProcessNetworkStack
PRODUCT_MINIMIZE_JAVA_DEBUG_INFO := true
PRODUCT_DISABLE_SCUDO := true

# Vendor
TARGET_COPY_OUT_VENDOR := vendor

# Vendor Init
TARGET_INIT_VENDOR_LIB := //$(DEVICE_PATH):libinit_hi6250
TARGET_RECOVERY_DEVICE_MODULES := libinit_hi6250

# Sepolicy
BOARD_SEPOLICY_DIRS += device/huawei/vns/sepolicy
SELINUX_IGNORE_NEVERALLOWS := true

# Wifi
ENABLE_VENDOR_IMAGE := true
PRODUCT_VENDOR_MOVE_ENABLED := true
WPA_SUPPLICANT_VERSION         := VER_0_8_X
BOARD_WPA_SUPPLICANT_DRIVER 	:= NL80211
BOARD_HOSTAPD_DRIVER 		:= NL80211
CONFIG_DRIVER_NL80211		:= y
WIFI_HIDL_FEATURE_DISABLE_AP_MAC_RANDOMIZATION := true

# Vendor Security patch level
VENDOR_SECURITY_PATCH := 2023-08-05

# VNDK
BOARD_VNDK_VERSION := current
BOARD_AVB_ENABLE := false

# Thermal
TARGET_USES_CUSTOM_THERMAL := true

# Shims
TARGET_LD_SHIM_LIBS += /vendor/lib/libhwlog.so|libshim_log.so:/vendor/lib64/libhwlog.so|libshim_log.so

TARGET_LD_SHIM_LIBS += /vendor/lib/egl/libGLES_mali.so|/system/lib/vndk-sp-29/libutilscallstack.so:/vendor/lib64/egl/libGLES_mali.so|/system/lib64/vndk-sp-29/libutilscallstack.so
TARGET_LD_SHIM_LIBS += /vendor/lib/hw/gralloc.hi6250.so|/system/lib/vndk-sp-29/libutilscallstack.so:/vendor/lib64/hw/gralloc.hi6250.so|/system/lib64/vndk-sp-29/libutilscallstack.so
TARGET_LD_SHIM_LIBS += /vendor/lib/hw/vulkan.hi6250.so|/system/lib/vndk-sp-29/libutilscallstack.so:/vendor/lib64/hw/vulkan.hi6250.so|/system/lib64/vndk-sp-29/libutilscallstack.so

TARGET_LD_SHIM_LIBS += /vendor/lib/libshim_hivwservice.so|/system/lib/vndk-sp-29/libprocessgroup.so

TARGET_LD_SHIM_LIBS += /vendor/lib64/libxcollie.so|/system/lib64/vndk-sp-29/libbase.so

TARGET_LD_SHIM_LIBS += /vendor/lib/hw/audio.primary.hi6250.so|/system/lib/vndk-29/libshim_icu.so
TARGET_LD_SHIM_LIBS += /vendor/lib/hw/audio.primary.hi6250.so|libshim_audioroute.so
TARGET_LD_SHIM_LIBS += /vendor/lib/hw/audio.primary.hi6250.so|libshim_hivwservice.so

# Pie + Ten
TARGET_LD_SHIM_LIBS += /vendor/lib64/vendor.huawei.hardware.radio@1.0.so|libshim_android.hardware.radio@1.0.so

# inherit from the proprietary version
-include vendor/huawei/vns/BoardConfigVendor.mk
