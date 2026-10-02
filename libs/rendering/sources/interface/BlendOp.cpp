//
// Created by Warren on 26/09/2026.
//

#include "rendering/interface/BlendOp.h"

namespace jupiter::rendering::utils
{
    D3D12_BLEND_OP getBlendOpFromBlendOperation(const BlendOperation& blendOp)
    {
        switch (blendOp)
        {
        case BlendOperation::WM_BLEND_OPERATION_ADD:
            return D3D12_BLEND_OP_ADD;
        default:
            return D3D12_BLEND_OP_ADD;
        }
    }
}
