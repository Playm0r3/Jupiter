//
// Created by Warren on 27/09/2026.
//

#include <iostream>

#include "rendering/directx/DirectXFence.h"
#include "rendering/directx/DirectXDevice.h"

namespace jupiter::rendering
{

    void DirectXFence::createFence(uint64_t initValue, Device* device)
    {
        const DirectXDevice* d = device->getDHandle();
        HRESULT hr = d->device->CreateFence(initValue, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence));
        fenceEvent = CreateEvent(nullptr, false, false, nullptr);
        fenceValue = 1;

        if (!FAILED(hr) && fenceEvent != nullptr) return;

        std::cout << "[Soleil] Impossible de creer une barrier de syncronisation !" << std::endl;
    }

    void DirectXFence::destroyFence()
    {
        waitForPreviousFrame();
        CloseHandle(fenceEvent);
    }

    void DirectXFence::createEvent()
    {
        // Vide pour le moment
    }

    void DirectXFence::waitForPreviousFrame()
    {
        // Vide pour le moment
    }

    void DirectXFence::waitGpuIdle()
    {
        fence->SetEventOnCompletion(fenceValue, fenceEvent);
        WaitForSingleObject(fenceEvent, 20000);
    }
}
