//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_RESOURCEBARRIERFLAGS_H
#define JUPITER_RESOURCEBARRIERFLAGS_H

#include <d3d12.h>

namespace jupiter::rendering
{
    enum ResourceBarrierFlags
    {
        WM_RESOURCE_BARRIER_FLAGS_NONE,
        WM_RESOURCE_BARRIER_FLAGS_BEGIN_ONLY,
        WM_RESOURCE_BARRIER_FLAGS_END_ONLY,
    };

    namespace utils
    {
        D3D12_RESOURCE_BARRIER_FLAGS getResourceBarrierFlags(const ResourceBarrierFlags& flags);
    }
}

#endif //JUPITER_RESOURCEBARRIERFLAGS_H
