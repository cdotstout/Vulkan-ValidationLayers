/* Copyright (c) 2015-2017, 2019 The Khronos Group Inc.
 * Copyright (c) 2015-2017, 2019 Valve Corporation
 * Copyright (c) 2015-2017, 2019 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Mark Lobodzinski <mark@lunarg.com>
 * Author: Courtney Goeltzenleuchter <courtney@LunarG.com>
 * Author: Dave Houlton <daveh@lunarg.com>
 */

#pragma once

#include <vulkan/vk_layer.h>
#include "vk_layer_dispatch_table.h"

#ifdef __cplusplus

typedef void *dispatch_key;
static inline dispatch_key get_dispatch_key(const void *object) { return (dispatch_key) * (VkLayerDispatchTable **)object; }

VK_LAYER_EXPORT VkLayerInstanceCreateInfo *get_chain_info(const VkInstanceCreateInfo *pCreateInfo, VkLayerFunction func);
VK_LAYER_EXPORT VkLayerDeviceCreateInfo *get_chain_info(const VkDeviceCreateInfo *pCreateInfo, VkLayerFunction func);

#endif
