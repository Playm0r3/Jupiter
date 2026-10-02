//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_DIRECTXFENCE_H
#define JUPITER_DIRECTXFENCE_H

#include <d3d12.h>
#include <wrl.h>

#include "rendering/interface/Fence.h"

namespace jupiter::rendering
{

    class DirectXFence : public Fence
    {

    public:

        DirectXFence() = default;
        ~DirectXFence() override = default;

        void createFence(uint64_t initValue, Device* device) override;
        void destroyFence() override;

        void createEvent() override;
        void waitForPreviousFrame()override;
        void waitGpuIdle() override;

        DirectXFence* getDHandle() override {return this;}

    private:

        Microsoft::WRL::ComPtr<ID3D12Fence> fence;
        HANDLE fenceEvent;

        uint32_t fenceValue;

        friend class DirectXCommandQueue;

    };

}

#endif //JUPITER_DIRECTXFENCE_H
