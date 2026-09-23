//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_DIRECTXCOMMANDALLOCATOR_H
#define JUPITER_DIRECTXCOMMANDALLOCATOR_H

#include <iostream>

#include <d3d12.h>
#include <wrl.h>

#include "rendering/interface/CommandAllocator.h"

namespace jupiter::rendering
{

    class DirectXCommandAllocator : public CommandAllocator
    {

    public:

        DirectXCommandAllocator() = default;
        ~DirectXCommandAllocator() = default;

        void createCommandAllocator() override;
        void destroyCommandAllocator() override;

        DirectXCommandAllocator* getDHandle() override {return this;}

    private:

        Microsoft::WRL::ComPtr<ID3D12CommandAllocator> allocator;

        friend class DirectXDevice;

    };

}

#endif //JUPITER_DIRECTXCOMMANDALLOCATOR_H
