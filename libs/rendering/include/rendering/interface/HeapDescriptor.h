//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_HEAPDESCRIPTOR_H
#define JUPITER_HEAPDESCRIPTOR_H
#include <cstdint>

#include "rendering/interface/HeapDescriptorType.h"

namespace jupiter::rendering
{
    struct HeapDescriptor
    {
        uint32_t numberDescriptor;
        HeapDescriptorType type;
    };
}

#endif //JUPITER_HEAPDESCRIPTOR_H
