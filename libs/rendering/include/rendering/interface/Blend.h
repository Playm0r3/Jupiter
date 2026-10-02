//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_BLEND_H
#define JUPITER_BLEND_H

#include <d3d12.h>

namespace jupiter::rendering
{
    enum Blend
    {
        WM_BLEND_ZERO,
        WM_BLEND_ONE,
    };

    namespace utils
    {
        D3D12_BLEND getBlendFromBlend(const Blend& blend);
    }
}

#endif //JUPITER_BLEND_H
