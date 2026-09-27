//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_RESOURCEBARRIERTYPE_H
#define JUPITER_RESOURCEBARRIERTYPE_H

#include <d3d12.h>

namespace jupiter::rendering
{

    enum ResourceBarrierType
    {
        WM_RESOURCE_BARRIER_TYPE_TRANSITION,
        WM_RESOURCE_BARRIER_TYPE_ALIASING,
        WM_RESOURCE_BARRIER_TYPE_UAV,
    };

    namespace utils
    {
        D3D12_RESOURCE_BARRIER_TYPE getBarrierType(const ResourceBarrierType& barrierType);
    }

}

#endif //JUPITER_RESOURCEBARRIERTYPE_H
