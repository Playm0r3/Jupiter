//
// Created by Warren on 26/09/2026.
//

#include "rendering/interface/FillMode.h"

namespace jupiter::rendering
{
    namespace utils
    {
        D3D12_FILL_MODE getFillModeFromFillMode(const FillMode& fillMode)
        {
            switch (fillMode)
            {
            case FillMode::WM_FILL_MODE_WIREFRAME:
                return D3D12_FILL_MODE_WIREFRAME;
            case FillMode::WM_FILL_MODE_SOLID:
                return D3D12_FILL_MODE_SOLID;
            default:
                return D3D12_FILL_MODE_SOLID;
            }
        }
    }
}