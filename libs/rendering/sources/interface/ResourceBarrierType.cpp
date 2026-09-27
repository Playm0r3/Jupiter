//
// Created by Warren on 27/09/2026.
//

#include "rendering/interface/ResourceBarrierType.h"

namespace jupiter::rendering::utils
{

    D3D12_RESOURCE_BARRIER_TYPE getBarrierType(const ResourceBarrierType& barrierType)
    {
        switch (barrierType)
        {
        case ResourceBarrierType::WM_RESOURCE_BARRIER_TYPE_TRANSITION:
            return D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        case ResourceBarrierType::WM_RESOURCE_BARRIER_TYPE_ALIASING:
            return D3D12_RESOURCE_BARRIER_TYPE_ALIASING;
        case ResourceBarrierType::WM_RESOURCE_BARRIER_TYPE_UAV:
            return D3D12_RESOURCE_BARRIER_TYPE_UAV;
        default:
            return D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        }
    }

}