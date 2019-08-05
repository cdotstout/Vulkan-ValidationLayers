/*
 * Copyright (c) 2015-2019 The Khronos Group Inc.
 * Copyright (c) 2015-2019 Valve Corporation
 * Copyright (c) 2015-2019 LunarG, Inc.
 * Copyright (c) 2015-2019 Google, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Author: Chia-I Wu <olvaffe@gmail.com>
 * Author: Chris Forbes <chrisf@ijw.co.nz>
 * Author: Courtney Goeltzenleuchter <courtney@LunarG.com>
 * Author: Mark Lobodzinski <mark@lunarg.com>
 * Author: Mike Stroyan <mike@LunarG.com>
 * Author: Tobin Ehlis <tobine@google.com>
 * Author: Tony Barbour <tony@LunarG.com>
 * Author: Cody Northrop <cnorthrop@google.com>
 * Author: Dave Houlton <daveh@lunarg.com>
 * Author: Jeremy Kniager <jeremyk@lunarg.com>
 * Author: Shannon McPherson <shannon@lunarg.com>
 * Author: John Zulauf <jzulauf@lunarg.com>
 */

#include "cast_utils.h"
#include "layer_validation_tests.h"
//
// POSITIVE VALIDATION TESTS
//
// These tests do not expect to encounter ANY validation errors pass only if this is true

TEST_F(VkPositiveLayerTest, TestRasterizationDiscardEnableTrue0) {
    TEST_DESCRIPTION("Ensure it doesn't crash and trigger error msg when rasterizerDiscardEnable = true");
    VkTestFramework::m_devsim_layer = true;
    m_instance_layer_names.clear();

    ASSERT_NO_FATAL_FAILURE(Init());
    ASSERT_NO_FATAL_FAILURE(InitRenderTarget());

    CreatePipelineHelper pipe(*this);
    pipe.InitInfo();

    m_errorMonitor->ExpectSuccess();
    pipe.rs_state_ci_.rasterizerDiscardEnable = VK_TRUE;
    pipe.InitState();
    print_android("TestRasterizationDiscardEnableTrue0 aaa");
    pipe.CreateGraphicsPipeline();
    print_android("TestRasterizationDiscardEnableTrue0 bbb");
    m_errorMonitor->VerifyNotFound();
    VkTestFramework::m_devsim_layer = false;
}

TEST_F(VkPositiveLayerTest, TestRasterizationDiscardEnableTrue1) {
    TEST_DESCRIPTION("Ensure it doesn't crash and trigger error msg when rasterizerDiscardEnable = true");
    VkTestFramework::m_devsim_layer = true;
    m_instance_layer_names.clear();

    ASSERT_NO_FATAL_FAILURE(Init());
    ASSERT_NO_FATAL_FAILURE(InitRenderTarget());

    CreatePipelineHelper pipe(*this);
    pipe.InitInfo();
    pipe.gp_ci_.pViewportState = nullptr;
    pipe.gp_ci_.pMultisampleState = nullptr;
    pipe.gp_ci_.pDepthStencilState = nullptr;
    pipe.gp_ci_.pColorBlendState = nullptr;

    m_errorMonitor->ExpectSuccess();
    pipe.rs_state_ci_.rasterizerDiscardEnable = VK_TRUE;
    pipe.InitState();
    print_android("TestRasterizationDiscardEnableTrue1 aaa");
    pipe.CreateGraphicsPipeline();
    print_android("TestRasterizationDiscardEnableTrue1 bbb");
    m_errorMonitor->VerifyNotFound();
    VkTestFramework::m_devsim_layer = false;
}

TEST_F(VkPositiveLayerTest, TestRasterizationDiscardEnableTrue2) {
    TEST_DESCRIPTION("Ensure it doesn't crash and trigger error msg when rasterizerDiscardEnable = true");
    ASSERT_NO_FATAL_FAILURE(Init());
    ASSERT_NO_FATAL_FAILURE(InitRenderTarget());

    CreatePipelineHelper pipe(*this);
    pipe.InitInfo();
    pipe.gp_ci_.pViewportState = nullptr;
    pipe.gp_ci_.pMultisampleState = nullptr;
    pipe.gp_ci_.pDepthStencilState = nullptr;
    pipe.gp_ci_.pColorBlendState = nullptr;

    m_errorMonitor->ExpectSuccess();
    pipe.rs_state_ci_.rasterizerDiscardEnable = VK_TRUE;
    pipe.InitState();
    print_android("TestRasterizationDiscardEnableTrue2 aaa");
    pipe.CreateGraphicsPipeline();
    print_android("TestRasterizationDiscardEnableTrue2 bbb");
    m_errorMonitor->VerifyNotFound();
}
