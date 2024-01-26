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

void property_override_4x(char const prop0[], char const prop1[], char const prop2[], char const prop3[], char const value[])
{
    property_override(prop0, value);
    property_override(prop1, value);
    property_override(prop2, value);
    property_override(prop3, value);
}

void property_override_9x(char const prop0[], char const prop1[], char const prop2[], char const prop3[], char const prop4[], char const prop5[], char const prop6[], char const prop7[], char const prop8[], char const value[])
{
    property_override_4x(prop0, prop1, prop2, prop3, value);
    property_override_4x(prop4, prop5, prop6, prop7, value);
    property_override(prop8, value);
}

static void set_model(const char *model) {
    property_override_4x("ro.build.product", "ro.product.device", "ro.product.model", "ro.product.name", model);
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
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-L21") != std::string::npos) {
        set_model("VNS-L21");
        property_override("ro.build.description", "VNS-L21-user 7.0 HUAWEIVNS-L21 C432B391 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L21/HWVNS-H:7.0/HUAWEIVNS-L21/C432B391:user/release-keys");
    }
    else if (buf.find("VNS-L22") != std::string::npos) {
        set_model("VNS-L22");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-L23") != std::string::npos) {
        set_model("VNS-L23");
        property_override("ro.build.description", "VNS-L23-user 7.0 HUAWEIVNS-L23 C605B396 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L23/HWVNS-H:7.0/HUAWEIVNS-L23/C605B396:user/release-keys");
    }
    else if (buf.find("VNS-L31") != std::string::npos) {
        set_model("VNS-L31");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-L52") != std::string::npos) {
        set_model("VNS-L52");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-L53") != std::string::npos) {
        set_model("VNS-L53");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-L62") != std::string::npos) {
        set_model("VNS-L62");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-AL00") != std::string::npos) {
        set_model("VNS-AL00");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-DL00") != std::string::npos) {
        set_model("VNS-DL00");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("VNS-TL00") != std::string::npos) {
        set_model("VNS-TL00");
        property_override("ro.build.description", "VNS-L31-user 7.0 HUAWEIVNS-L31 C530B385 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HUAWEI/VNS-L31/HWVNS-H:7.0/HUAWEIVNS-L31/C530B385:user/release-keys");
    }
    else if (buf.find("NEM-L21") != std::string::npos) {
        set_model("NEM-L21");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NEM-L22") != std::string::npos) {
        set_model("NEM-L22");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NEM-L51") != std::string::npos) {
        set_model("NEM-L51");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if ((buf.find("NEM-AL00") != std::string::npos) || (buf.find("NEM-AL10") != std::string::npos)) {
        set_model("NEM-AL10");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NEM-TL00") != std::string::npos) {
        set_model("NEM-TL00");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NEM-TL00H") != std::string::npos) {
        set_model("NEM-TL00H");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NEM-UL10") != std::string::npos) {
        set_model("NEM-UL10");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if (buf.find("NMO-L01") != std::string::npos) {
        set_model("NMO-L01");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if ((buf.find("NMO-L22") != std::string::npos) || (buf.find("NMO-L02") != std::string::npos)) {
        set_model("NMO-L22");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if ((buf.find("NMO-L23") != std::string::npos) || (buf.find("NMO-L03") != std::string::npos)) {
        set_model("NMO-L23");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else if ((buf.find("NMO-L31") != std::string::npos) || (buf.find("NMO-L51") != std::string::npos)) {
        set_model("NMO-L31");
        property_override("ro.build.description", "NEM-L51-user 7.0 HONORNEM-L51 C432B359 release-keys");
        property_override_9x("ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "ro.odm.build.fingerprint", "ro.bootimage.build.fingerprint", "ro.build.fingerprint", "ro.product.build.fingerprint", "ro.system_ext.build.fingerprint",  "ro.odm_dlkm.build.fingerprint", "ro.vendor_dlkm.build.fingerprint",  "HONOR/NEM-L51/HNNEM-H:7.0/HONORNEM-L51/C432B359:user/release-keys");
    }
    else {
	set_model("UNKNOWN");
    }
    
    property_override("ro.connectivity.chiptype", "hisi");
    property_override("is_hisi_connectivity_chip", "1");
    property_override("ro.boot.odm.conn.chiptype", "hisi");
    property_override("ro.connectivity.sub_chiptype", "hi1102");
    property_override("ro.boot.odm.conn.schiptype", "hi1102");
    property_override("wifi.interface", "wlan0");
    property_override("wifi.direct.interface", "p2p-dev-wlan0");
}
