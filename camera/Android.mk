include $(CLEAR_VARS)
LOCAL_STATIC_LIBRARIES := android.hardware.camera.common@1.0-helper
LOCAL_MODULE := android.hardware.camera.common@1.0-helper
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MULTILIB := 64
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)
