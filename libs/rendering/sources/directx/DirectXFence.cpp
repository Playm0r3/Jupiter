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
        if (!FAILED(hr)) return;

        std::cout << "[Soleil] Impossible de creer une barrier de syncronisation !" << std::endl;
    }

    void DirectXFence::destroyFence(uint64_t fenceValue)
    {
        waitForPreviousFrame(fenceValue);
        CloseHandle(fenceEvent);
    }

    void DirectXFence::createEvent()
    {
        fenceEvent = CreateEvent(nullptr, false, false, nullptr);
        if (fenceEvent != nullptr) return;

        std::cout << "[Soleil] Impossible de creer un evenenement de barrier de syncronisation !" << std::endl;
    }

    void DirectXFence::waitForPreviousFrame(uint64_t fenceValue)
    {
        if (fence->GetCompletedValue() < fenceValue)
        {
            fence->SetEventOnCompletion(fenceValue, fenceEvent);
            WaitForSingleObject(fenceEvent, INFINITE);
        }
    }
}
