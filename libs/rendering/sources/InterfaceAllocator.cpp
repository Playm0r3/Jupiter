//
// Created by Warren on 27/09/2026.
//

#include "rendering/InterfaceAllocator.h"

#include "rendering/directx/DirectXAllocator.h"

namespace jupiter::rendering
{

    InterfaceAllocator* InterfaceAllocator::selectApi(Api api)
    {
        switch (api)
        {
        case DIRECTX_12:
            return new DirectXAllocator();
        default:
            return new DirectXAllocator();
        }
    }

}
