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
        uint32_t flags; // 0 for default usage and 0x1 for shader visible
    };
}

#endif //JUPITER_HEAPDESCRIPTOR_H
