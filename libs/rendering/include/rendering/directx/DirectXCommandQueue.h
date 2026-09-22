//
// Created by Warren on 22/09/2026.
//

#ifndef JUPITER_DIRECTXCOMMANDQUEUE_H
#define JUPITER_DIRECTXCOMMANDQUEUE_H

#include <d3d12.h>
#include <wrl.h>

#include "rendering/interface/CommandQueue.h"

namespace jupiter::rendering
{

    class Device;

    class DirectXCommandQueue : public CommandQueue
    {
    public:

        DirectXCommandQueue() = default;
        ~DirectXCommandQueue() override = default;

        void createCommandQueue(Device* device) override;
        void destroyCommandQueue() override;

    private:

        Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

    };
}

#endif //JUPITER_DIRECTXCOMMANDQUEUE_H
