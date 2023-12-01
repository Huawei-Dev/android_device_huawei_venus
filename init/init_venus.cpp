#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/file.h>
#include <android-base/properties.h>
#include <android-base/logging.h>
#include <android-base/strings.h>

#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/sysinfo.h>

#include "vendor_init.h"

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_2x(char const product_prop[], char const system_prop[], char const value[])
{
    property_override(product_prop, value);
    property_override(system_prop, value);
}

void property_override_3x(char const product_prop[], char const system_prop[], char const vendor_prop[], char const value[])
{
    property_override(product_prop, value);
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void property_override_4x(char const product_prop[], char const system_prop[], char const vendor_prop[], char const bootimage[], char const value[])
{
    property_override(product_prop, value);
    property_override(system_prop, value);
    property_override(vendor_prop, value);
    property_override(bootimage, value);
}

static void set_model(const char *model) {
    property_override_3x("ro.hw.oemName", "ro.lineage.device", "ro.build.product", model);
    property_override_3x("ro.product.name", "ro.product.odm.name", "ro.product.product.name", model);
    property_override_3x("ro.product.system.name", "ro.product.system_ext.name", "ro.product.vendor.name", model);
    property_override_2x("ro.product.odm_dlkm.name", "ro.product.vendor_dlkm.name", model);
    property_override_3x("ro.product.device", "ro.product.odm.device", "ro.product.product.device", model);
    property_override_3x("ro.product.system.device", "ro.product.system_ext.device", "ro.product.vendor.device", model);
    property_override_2x("ro.product.odm_dlkm.device", "ro.product.vendor_dlkm.device", model);
    property_override_3x("ro.product.model", "ro.product.odm.model", "ro.product.product.model", model);
    property_override_3x("ro.product.system.model", "ro.product.system_ext.model", "ro.product.vendor.model", model);
    property_override_2x("ro.product.odm_dlkm.model", "ro.product.vendor_dlkm.model", model);
}

void vendor_load_properties()
{
    int i;
    std::ifstream fin;
    std::string buf;

    fin.open("/sys/firmware/devicetree/base/hisi,product_name");
    while (std::getline(fin, buf, ' '))
        if ((buf.find("VNS-L21") != std::string::npos) || (buf.find("VNS-L22") != std::string::npos) || (buf.find("VNS-L23") != std::string::npos) || (buf.find("VNS-L31") != std::string::npos)
	    || (buf.find("VNS-L52") != std::string::npos) || (buf.find("VNS-L53") != std::string::npos) || (buf.find("VNS-L62") != std::string::npos) || (buf.find("VNS-AL00") != std::string::npos)
	    || (buf.find("VNS-DL00") != std::string::npos) || (buf.find("VNS-TL00") != std::string::npos) || (buf.find("NEM-L21") != std::string::npos) || (buf.find("NEM-L22") != std::string::npos)
	    || (buf.find("NEM-L51") != std::string::npos) || (buf.find("NEM-AL10") != std::string::npos) || (buf.find("NEM-TL00") != std::string::npos) || (buf.find("NEM-TL00H") != std::string::npos)
	    || (buf.find("NEM-UL10") != std::string::npos) || (buf.find("NMO-L01") != std::string::npos) || (buf.find("NMO-L22") != std::string::npos) || (buf.find("NMO-L23") != std::string::npos)
	    || (buf.find("NMO-L31") != std::string::npos))
            break;
    fin.close();

    if (buf.find("VNS-L11") != std::string::npos) {
        set_model("VNS-L31");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-L21") != std::string::npos) {
        set_model("VNS-L21");
        property_override("ro.build.description", "VNS-L21-user 7.0 HUAWEIVNS-L21 C432B391 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HUAWEI/VNS-L21/HWVNS-H:7.0/HUAWEIVNS-L21/C432B391:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HUAWEI/VNS-L23/HWVNS-H:7.0/HUAWEIVNS-L23/C605B396:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L23/HWVNS-H:7.0/HUAWEIVNS-L23/C605B396:user/release-keys");
    }
    else if (buf.find("VNS-L22") != std::string::npos) {
        set_model("VNS-L22");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-L23") != std::string::npos) {
        set_model("VNS-L23");
        property_override("ro.build.description", "VNS-L23-user 7.0 HUAWEIVNS-L23 C605B396 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HUAWEI/VNS-L23/HWVNS-H:7.0/HUAWEIVNS-L23/C605B396:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HUAWEI/VNS-L23/HWVNS-H:7.0/HUAWEIVNS-L23/C605B396:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L23/HWVNS-H:7.0/HUAWEIVNS-L23/C605B396:user/release-keys");
    }
    else if (buf.find("VNS-L31") != std::string::npos) {
        set_model("VNS-L31");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-L52") != std::string::npos) {
        set_model("VNS-L52");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-L53") != std::string::npos) {
        set_model("VNS-L53");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-L62") != std::string::npos) {
        set_model("VNS-L62");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-AL00") != std::string::npos) {
        set_model("VNS-AL00");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-DL00") != std::string::npos) {
        set_model("VNS-DL00");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-TL00") != std::string::npos) {
        set_model("VNS-TL00");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("NEM-L21") != std::string::npos) {
        set_model("NEM-L21");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NEM-L22") != std::string::npos) {
        set_model("NEM-L22");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NEM-L51") != std::string::npos) {
        set_model("NEM-L51");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if ((buf.find("NEM-AL00") != std::string::npos) || (buf.find("NEM-AL10") != std::string::npos)) {
        set_model("NEM-AL10");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NEM-TL00") != std::string::npos) {
        set_model("NEM-TL00");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NEM-TL00H") != std::string::npos) {
        set_model("NEM-TL00H");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NEM-UL10") != std::string::npos) {
        set_model("NEM-UL10");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NMO-L01") != std::string::npos) {
        set_model("NMO-L01");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if ((buf.find("NMO-L22") != std::string::npos) || (buf.find("NMO-L02") != std::string::npos)) {
        set_model("NMO-L22");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if ((buf.find("NMO-L23") != std::string::npos) || (buf.find("NMO-L03") != std::string::npos)) {
        set_model("NMO-L23");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if ((buf.find("NMO-L31") != std::string::npos) || (buf.find("NMO-L51") != std::string::npos)) {
        set_model("NMO-L31");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_4x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_3x("ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
        property_override_2x("ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else {
	property_override("ro.product.model", "UNKNOWN");
    }
    
    fin.open("/proc/connectivity/chiptype");
    while (std::getline(fin, buf, ' ')) {
    	if (buf.find("hisi") != std::string::npos) {
        	property_override("ro.connectivity.chiptype", "hisi");
        	property_override("is_hisi_connectivity_chip", "1");
    		property_override("ro.boot.odm.conn.chiptype", "hisi");
    		}
            break;
       }
    fin.close();
    
    fin.open("/sys/firmware/devicetree/base/hi1102/name");
    while (std::getline(fin, buf, ' ')) {
        if (buf.find("hi1102") != std::string::npos) {
        	property_override("ro.connectivity.sub_chiptype", "hi1102");
        	property_override("ro.boot.odm.conn.schiptype", "hi1102");
        	}
            break;
       }
    fin.close();
}
