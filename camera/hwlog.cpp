#include <log/log.h>
#include <stdio.h>
#include <string.h>

extern "C" int __android_log_print(int prio, const char *tag, const char *fmt, ...)
{
    va_list ap;
    char buf[512];
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    return __android_log_write(prio, tag, buf);
}
