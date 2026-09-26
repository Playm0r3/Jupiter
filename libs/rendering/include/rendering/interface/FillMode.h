//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_FILLMODE_H
#define JUPITER_FILLMODE_H

#include <d3d12.h>

namespace jupiter::rendering
{
    enum FillMode
    {
        WM_FILL_MODE_WIREFRAME,
        WM_FILL_MODE_SOLID,
    };

    namespace utils
    {
        D3D12_FILL_MODE getFillModeFromFillMode(const FillMode& fillMode);
    }
}

#endif //JUPITER_FILLMODE_H
