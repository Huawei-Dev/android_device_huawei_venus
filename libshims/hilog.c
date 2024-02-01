#define LOG_TAG "libhilog"

#include <log/log.h>
#include <stdint.h>
#include <stdio.h>

void __hi_log_print(int param1, char* param2, char* param3, int param4) {
    ALOGV("%s: param1: %d, param2: %s, param3: %s, param4: %d", __func__, param1, param2, param3, param4);
    return;
}
