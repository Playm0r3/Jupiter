//
// Created by Warren on 26/09/2026.
//

#include "rendering/interface/Blend.h"

namespace jupiter::rendering::utils
{
    D3D12_BLEND getBlendFromBlend(const Blend& blend)
    {
        switch (blend)
        {
        case Blend::WM_BLEND_ONE:
            return D3D12_BLEND_ONE;
        case Blend::WM_BLEND_ZERO:
            return D3D12_BLEND_ZERO;
        default:
            return D3D12_BLEND_ZERO;
        }
    }
}
