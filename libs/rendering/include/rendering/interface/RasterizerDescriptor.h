//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_RASTERIZERDESCRIPTOR_H
#define JUPITER_RASTERIZERDESCRIPTOR_H

#include <cstdint>

#include "rendering/interface/FillMode.h"
#include "rendering/interface/CullMode.h"
#include "rendering/interface/ConservativeRasterizationMode.h"

namespace jupiter::rendering
{

    struct RasterizerDescriptor
    {
        FillMode fillMode = WM_FILL_MODE_SOLID;
        CullMode cullMode = WM_CULL_MODE_NONE;
        bool frontCounterClockwise = false;
        uint32_t depthBias = 0;
        float depthBiasClamp = 0.0f;
        float slopeScaleDepthBias = 0.0f;
        bool depthClipEnable = true;
        bool multisampleEnable = false;
        bool antialiasedLineEnable = false;
        uint32_t forcedSampleCount = 0;
        ConservativeRasterizationMode conservativeRasterizationMode = WM_CONSERVATIVE_RASTERIZATION_MODE_OFF;
    };
}

#endif //JUPITER_RASTERIZERDESCRIPTOR_H
