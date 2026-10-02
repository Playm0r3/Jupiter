//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_BLENDOP_H
#define JUPITER_BLENDOP_H

#include <d3d12.h>

namespace jupiter::rendering
{
    enum BlendOperation
    {
        WM_BLEND_OPERATION_ADD,
    };

    namespace utils
    {
        D3D12_BLEND_OP getBlendOpFromBlendOperation(const BlendOperation& blendOp);
    }
}

#endif //JUPITER_BLENDOP_H
