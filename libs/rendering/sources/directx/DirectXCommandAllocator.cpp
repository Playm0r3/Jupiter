//
// Created by Warren on 23/09/2026.
//

#include <iostream>

#include "rendering/directx/DirectXCommandAllocator.h"

namespace jupiter::rendering
{
    void DirectXCommandAllocator::createCommandAllocator()
    {

    }

    void DirectXCommandAllocator::destroyCommandAllocator()
    {

    }

    void DirectXCommandAllocator::reset()
    {
        HRESULT hr = allocator->Reset();
        if (!FAILED(hr)) return;

        std::cout << "[Soleil] Impossible de reinitialiser l'alloeur de commande" << std::endl;
    }
}
