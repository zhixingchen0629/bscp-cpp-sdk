/*
 * Tencent is pleased to support the open source community by making Blueking Container Service available.
 * Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
 * Licensed under the MIT License (the "License"); you may not use this file except
 * in compliance with the License. You may obtain a copy of the License at
 * http://opensource.org/licenses/MIT
 * Unless required by applicable law or agreed to in writing, software distributed under
 * the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BSCP_CPP_SDK_INTERNAL_PKG_TYPE_H_
#define _BSCP_CPP_SDK_INTERNAL_PKG_TYPE_H_

// C++ standard.
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

// bscp-cpp-sdk.
#include "../core/options.h"
#include "../tools/finger_print.h"
#include "sf-share/type.h"

#include "pkg/protocol/core/config-item/config_item.pb.h"
#include "pkg/protocol/core/hook/hook.pb.h"

namespace bscp {

/**
 * @brief ConfigItemFile define config item file.
 */
struct ConfigItemFile
{
    // config file name.
    std::string m_name;
    // path of config file.
    std::string m_path;
    // permission file permission.
    pbci::FilePermission m_permission;
    // FileMeta data.
    sfs::ConfigItemMetaV1 m_fileData;
};

/**
 * @brief Release define bscp service version.
 */
struct Release
{
    uint32_t m_releaseID = 0;
    std::vector<ConfigItemFile> m_fileItems;
    std::vector<sfs::KvMetaV1> m_kvItems;
    pbhook::HookSpec m_preHook;
    pbhook::HookSpec m_postHook;
};

/**
 * @brief SidecarMeta
 */
struct SidecarMeta
{
    uint32_t m_bid = 0;
    std::string m_fpt;

    /**
     * @brief Marshal marshal the metadata to json string.
     *
     * @param value output marshal json string.
     *
     * @return returns 0 on success and others on failure.
     */
    int Marshal(std::string& value) const;
};

// callback function define.
using Callback = int (*)(const Release&);

} // namespace bscp

#endif // _BSCP_CPP_SDK_INTERNAL_PKG_TYPE_H_