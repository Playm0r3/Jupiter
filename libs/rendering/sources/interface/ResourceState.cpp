//
// Created by Warren on 27/09/2026.
//

#include "rendering/interface/ResourceState.h"

namespace jupiter::rendering::utils
{

    D3D12_RESOURCE_STATES getResourceStateFromResourceState(const ResourceState& state)
    {
        switch (state)
        {
        case ResourceState::WM_RESOURCE_STATE_COMMON:
            return D3D12_RESOURCE_STATE_COMMON;
        case ResourceState::WM_RESOURCE_STATE_GENERIC_READ:
            return D3D12_RESOURCE_STATE_GENERIC_READ;
        case ResourceState::WM_RESOURCE_STATE_COPY_DESTINATION:
            return D3D12_RESOURCE_STATE_COPY_DEST;
        case ResourceState::WM_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER:
            return D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER;
        case ResourceState::WM_RESOURCE_STATE_INDEX_BUFFER:
            return D3D12_RESOURCE_STATE_INDEX_BUFFER;
        case ResourceState::WM_RESOURCE_STATE_RENDER_TARGET:
            return D3D12_RESOURCE_STATE_RENDER_TARGET;
        case ResourceState::WM_RESOURCE_STATE_PRESENT:
            return D3D12_RESOURCE_STATE_PRESENT;
        default:
            return D3D12_RESOURCE_STATE_COMMON;
        }
    }

}