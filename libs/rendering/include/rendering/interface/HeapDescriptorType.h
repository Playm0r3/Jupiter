//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_HEAPDESCRIPTORTYPE_H
#define JUPITER_HEAPDESCRIPTORTYPE_H

#include <d3d12.h>

namespace jupiter::rendering
{
    enum HeapDescriptorType
    {
        WM_HEAP_DESCRIPTOR_TYPE_RTV
    };

    namespace utils
    {
        D3D12_DESCRIPTOR_HEAP_TYPE getHeapTypeFromDescriptorType(HeapDescriptorType type);
    }
}

#endif //JUPITER_HEAPDESCRIPTORTYPE_H
