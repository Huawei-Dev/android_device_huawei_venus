/*
 * Copyright (C) 2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "libinit_variants"
#include <libinit_utils.h>
#include <libinit_variants.h>

#include <android-base/logging.h>
#include <android-base/strings.h>

#include <sstream>

#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

struct ProductInfo {
    string model;
    string version;
    string region_type;
};

constexpr const char* kOemInfoPath = "/dev/block/by-name/oeminfo";
vector<unsigned char> pattern = {0x4F, 0x45, 0x4D, 0x5F, 0x49, 0x4E, 0x46, 0x4F, 0x06, 0x00,
                                      0x00, 0x00, 0x4E, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
                                      0x80, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};

ProductInfo ParseProductInfo(const string& product_info_str) {
    ProductInfo product_info;
    istringstream iss(product_info_str);

    // Extract the model (i.e. "PRA-LX1").
    getline(iss, product_info.model, ' ');

    // Extract the version (i.e. "9.1.0.311").
    getline(iss, product_info.version, '(');

    // Remove trailing whitespace.
    if (!product_info.version.empty() && product_info.version.back() == ')') {
        product_info.version.pop_back();
    }

    // Extract the baseband (i.e. "C185E3R2P1").
    getline(iss, product_info.region_type, ')');
    return product_info;
}

ProductInfo ReadProductInfo() {
    ProductInfo product_info = {};

    int fd = open(kOemInfoPath, O_RDONLY);
    if (fd == -1) {
        LOG(ERROR) << "Unable to open: " << kOemInfoPath << ", error: " << strerror(errno);
        return product_info;
    }

    off_t size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);  // Go back.

    void* buffer = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buffer == MAP_FAILED) {
        LOG(ERROR) << "Unable to map: " << kOemInfoPath << ", error: " << strerror(errno);
        close(fd);
        return product_info;
    }

    auto begin = static_cast<unsigned char*>(buffer);
    auto end = begin + size;
    auto it = search(begin, end, pattern.begin(), pattern.end());

    if (it != end) {
        // Skip over 0xFF bytes
        auto name_start = it + pattern.size();
        while (*name_start == 0xFF && name_start < end) {
            ++name_start;
        }
        // Parse the product info
        product_info = ParseProductInfo(string(reinterpret_cast<char*>(name_start)));
    } else {
        LOG(ERROR) << "Unable to find product name in: " << kOemInfoPath;
    }

    munmap(buffer, size);
    close(fd);

    return product_info;
}

void load_variants() {
    ProductInfo product_info = ReadProductInfo();
    string model_info, camera_info;
    int i;

    // Load the phone model dynamically from the oeminfo partition.
    if (!product_info.model.empty()) {
        LOG(INFO) << "Found product info: " << product_info.model << " " << product_info.version
                  << " " << product_info.region_type;
        for (int i = 0; i < 7; i++)
       	    model_info.push_back(product_info.model[i]);
        set_ro_build_prop("model", model_info, true);
        for (int i = 0; i < 3; i++)
            camera_info.push_back(model_info[i]);
        set_ro_build_prop("camera_product", camera_info, true);    
    } else {
        LOG(ERROR) << "Unable to parse product information!";
    }
}
