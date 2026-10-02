//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_HEAPTYPE_H
#define JUPITER_HEAPTYPE_H

#include <d3d12.h>

namespace jupiter::rendering
{

    enum HeapType
    {
        WM_HEAP_TYPE_DEFAULT,
        WM_HEAP_TYPE_UPLOAD,
    };

    namespace utils
    {

        D3D12_HEAP_TYPE getHeapTypeFromHeapType(const HeapType& heapType);

    }

}

#endif //JUPITER_HEAPTYPE_H
