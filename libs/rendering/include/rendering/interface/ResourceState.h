//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_RESOURCESTATE_H
#define JUPITER_RESOURCESTATE_H

#include <d3d12.h>

namespace jupiter::rendering
{
    enum ResourceState
    {
        WM_RESOURCE_STATE_COMMON,
        WM_RESOURCE_STATE_GENERIC_READ,
        WM_RESOURCE_STATE_COPY_DESTINATION,
        WM_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER,
        WM_RESOURCE_STATE_INDEX_BUFFER,
        WM_RESOURCE_STATE_PRESENT,
        WM_RESOURCE_STATE_RENDER_TARGET,
    };

    namespace utils
    {
        D3D12_RESOURCE_STATES getResourceStateFromResourceState(const ResourceState& state);
    }
}

#endif //JUPITER_RESOURCESTATE_H
