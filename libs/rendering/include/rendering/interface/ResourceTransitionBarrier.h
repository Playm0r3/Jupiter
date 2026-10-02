//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_RESOURCETRANSITIONBARRIER_H
#define JUPITER_RESOURCETRANSITIONBARRIER_H

#include <cstdint>

#include "rendering/interface/ResourceState.h"

namespace jupiter::rendering
{

    class Resource;

    struct ResourceTransitionBarrier
    {
        Resource* resource = nullptr;
        uint32_t subResource = 0;
        ResourceState stateBefore = ResourceState::WM_RESOURCE_STATE_COMMON;
        ResourceState stateAfter = ResourceState::WM_RESOURCE_STATE_COMMON;
    };

}

#endif //JUPITER_RESOURCETRANSITIONBARRIER_H
