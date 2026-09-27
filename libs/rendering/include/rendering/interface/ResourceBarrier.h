//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_RESOURCEBARRIER_H
#define JUPITER_RESOURCEBARRIER_H

#include "rendering/interface/ResourceBarrierType.h"
#include "rendering/interface/ResourceBarrierFlags.h"
#include "rendering/interface/ResourceTransitionBarrier.h"

namespace jupiter::rendering
{

    struct ResourceBarrier
    {
        ResourceBarrierType type = WM_RESOURCE_BARRIER_TYPE_TRANSITION;
        ResourceBarrierFlags flag = WM_RESOURCE_BARRIER_FLAGS_NONE;
        ResourceTransitionBarrier* transition = nullptr;
    };

}

#endif //JUPITER_RESOURCEBARRIER_H
