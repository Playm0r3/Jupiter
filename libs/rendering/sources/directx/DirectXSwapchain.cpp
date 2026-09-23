//
// Created by Warren on 23/09/2026.
//

#include "rendering/directx/DirectXSwapchain.h"
#include "rendering/directx/DirectXDevice.h"
#include "rendering/directx/DirectXCommandQueue.h"

#include "rendering/interface/SwapchainDescriptor.h"
#include "rendering/directx/DirectXResource.h"

#include <iostream>

namespace jupiter::rendering
{

    void DirectXSwapchain::createSwapchain(SwapchainDescriptor* descriptor)
    {
        DirectXDevice* device = descriptor->device->getDHandle();
        DirectXCommandQueue* commandQueue = descriptor->commandQueue->getDHandle();

        DXGI_SWAP_CHAIN_DESC desc = {};
        desc.BufferCount = descriptor->bufferCount;
        desc.BufferDesc.Width = 1920;
        desc.BufferDesc.Height = 1080;
        desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        desc.OutputWindow = (*descriptor->windowHandles);
        desc.SampleDesc.Count = 1;
        desc.Windowed = TRUE;

        HRESULT fhr = device->factory->CreateSwapChain(commandQueue->commandQueue.Get(), &desc, &buildSwapchain);
        HRESULT shr = buildSwapchain.As(&swapchain);

        if (!FAILED(fhr) && !FAILED(shr)) return;
        std::cout << "[Soleil] Impossible de creer la swapchain !" << std::endl;
    }

    void DirectXSwapchain::destroySwapchain()
    {

    }

    uint32_t DirectXSwapchain::getCurrentBackBufferIndex()
    {
        return swapchain->GetCurrentBackBufferIndex();
    }

    void DirectXSwapchain::getBuffer(uint32_t index, Resource* resource)
    {
        DirectXResource* r = resource->getDHandle();
        swapchain->GetBuffer(index, IID_PPV_ARGS(&r->resource));
    }
}
