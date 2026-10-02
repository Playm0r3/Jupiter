//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_HEAPPROPERTIES_H
#define JUPITER_HEAPPROPERTIES_H

#include <cstdint>

#include "rendering/interface/HeapType.h"

namespace jupiter::rendering
{
    struct HeapProperties
    {
        HeapType heapType = WM_HEAP_TYPE_DEFAULT;
        uint32_t creationNodeMask = 0;
        uint32_t visibleNodeMask = 0;
    };
}

#endif //JUPITER_HEAPPROPERTIES_H
