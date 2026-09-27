//
// Created by Warren on 27/09/2026.
//

#include "rendering/interface/ResourceBarrierFlags.h"

namespace jupiter::rendering::utils
{
    D3D12_RESOURCE_BARRIER_FLAGS getResourceBarrierFlags(const ResourceBarrierFlags& flags)
    {
        switch (flags)
        {
        case ResourceBarrierFlags::WM_RESOURCE_BARRIER_FLAGS_NONE:
            return D3D12_RESOURCE_BARRIER_FLAG_NONE;
        case ResourceBarrierFlags::WM_RESOURCE_BARRIER_FLAGS_BEGIN_ONLY:
            return D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY;
        case ResourceBarrierFlags::WM_RESOURCE_BARRIER_FLAGS_END_ONLY:
            return D3D12_RESOURCE_BARRIER_FLAG_END_ONLY;
        default:
            return D3D12_RESOURCE_BARRIER_FLAG_NONE;
        }
    }
}
