//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_CULLMODE_H
#define JUPITER_CULLMODE_H

#include <d3d12.h>

namespace jupiter::rendering
{
    enum CullMode
    {
        WM_CULL_MODE_NONE,
        WM_CULL_MODE_FRONT,
        WM_CULL_MODE_BACK,
    };

    namespace utils
    {
        D3D12_CULL_MODE getCullModeFromCullMode(const CullMode& cullMode);
    }

}

#endif //JUPITER_CULLMODE_H
