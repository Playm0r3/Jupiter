//
// Created by Warren on 27/09/2026.
//

#include "rendering/interface/ResourceDimension.h"

namespace jupiter::rendering::utils
{

    D3D12_RESOURCE_DIMENSION getResourceDimensionFromResourceDimension(const ResourceDimension& dimension)
    {
        switch (dimension)
        {
        case ResourceDimension::WM_RESOURCE_DIMENSION_BUFFER:
            return D3D12_RESOURCE_DIMENSION_BUFFER;
        case ResourceDimension::WM_RESOURCE_DIMENSION_TEXTURE1D:
            return D3D12_RESOURCE_DIMENSION_TEXTURE1D;
        case ResourceDimension::WM_RESOURCE_DIMENSION_TEXTURE2D:
            return D3D12_RESOURCE_DIMENSION_TEXTURE2D;
        case ResourceDimension::WM_RESOURCE_DIMENSION_TEXTURE3D:
            return D3D12_RESOURCE_DIMENSION_TEXTURE3D;
        default:
            return D3D12_RESOURCE_DIMENSION_UNKNOWN;
        }
    }

}