//
// Created by Warren on 26/09/2026.
//

#include "rendering/interface/CullMode.h"

namespace jupiter::rendering::utils
{
    D3D12_CULL_MODE getCullModeFromCullMode(const CullMode& cullMode)
    {
        switch (cullMode)
        {
        case CullMode::WM_CULL_MODE_NONE:
            return D3D12_CULL_MODE_NONE;
        case CullMode::WM_CULL_MODE_FRONT:
            return D3D12_CULL_MODE_FRONT;
        case CullMode::WM_CULL_MODE_BACK:
            return D3D12_CULL_MODE_BACK;
        default:
            return D3D12_CULL_MODE_FRONT;
        }
    }
}