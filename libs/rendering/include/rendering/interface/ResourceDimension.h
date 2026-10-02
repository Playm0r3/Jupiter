//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_RESOURCEDIMENSION_H
#define JUPITER_RESOURCEDIMENSION_H

#include <d3d12.h>

namespace jupiter::rendering
{

    enum ResourceDimension
    {

        WM_RESOURCE_DIMENSION_BUFFER,
        WM_RESOURCE_DIMENSION_TEXTURE1D,
        WM_RESOURCE_DIMENSION_TEXTURE2D,
        WM_RESOURCE_DIMENSION_TEXTURE3D,

    };

    namespace utils
    {

        D3D12_RESOURCE_DIMENSION getResourceDimensionFromResourceDimension(const ResourceDimension& dimenion);

    }

}

#endif //JUPITER_RESOURCEDIMENSION_H
