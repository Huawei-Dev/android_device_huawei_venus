#include <dlfcn.h>

#include <hardware/hardware.h>
#include <hardware/memtrack.h>

#define LOG_TAG "libshim_memtrack"
#include <cutils/log.h>
#include <string.h>

static const memtrack_module_t *module;

extern "C" int memtrack_init(void)
{
    int err;
    if (module) return 0;

    err = hw_get_module("memtrack",
            (hw_module_t const**)&module);
    if (err) {
        ALOGE("Couldn't load memtrack module (%s)",
            strerror(-err));
        return err;
    }

    return module->init(module);
}
