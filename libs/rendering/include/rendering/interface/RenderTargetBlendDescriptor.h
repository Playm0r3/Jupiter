//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_RENDERTARGETBLEND_H
#define JUPITER_RENDERTARGETBLEND_H
#include <cstdint>

#include "rendering/interface/Blend.h"
#include "rendering/interface/BlendOp.h"
#include "rendering/interface/LogicOp.h"

namespace jupiter::rendering
{
    struct RenderTarget
    {
        bool blendEnable = false;
        bool logicOpEnable = false;
        Blend srcBlend = WM_BLEND_ONE;
        Blend dstBlend = WM_BLEND_ZERO;
        BlendOperation blendOperation = WM_BLEND_OPERATION_ADD;
        Blend srcBlendAlpha = WM_BLEND_ONE;
        Blend dstBlendAlpha = WM_BLEND_ZERO;
        BlendOperation blendOperationAlpha = WM_BLEND_OPERATION_ADD;
        LogicOperation logicOperation = WM_LOGIC_OPERATION_NOOP;
        uint8_t renderTargetWriteMask = 0xFF; // all renderTargetWriteMask
    };
}

#endif //JUPITER_RENDERTARGETBLEND_H
