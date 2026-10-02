//
// Created by Warren on 27/09/2026.
//

#include "rendering/interface/HeapType.h"

namespace jupiter::rendering::utils
{

    D3D12_HEAP_TYPE getHeapTypeFromHeapType(const HeapType& heapType)
    {
        switch (heapType)
        {
        case WM_HEAP_TYPE_DEFAULT:
            return D3D12_HEAP_TYPE_DEFAULT;
        case WM_HEAP_TYPE_UPLOAD:
            return D3D12_HEAP_TYPE_UPLOAD;
        default:
            return D3D12_HEAP_TYPE_DEFAULT;
        }
    }

}