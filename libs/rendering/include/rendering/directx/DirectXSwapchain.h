//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_DIRECTXSWAPCHAIN_H
#define JUPITER_DIRECTXSWAPCHAIN_H

#include "rendering/interface/Swapchain.h"

#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>

namespace jupiter::rendering
{

    struct SwapchainDescriptor;

    class DirectXSwapchain : public Swapchain
    {
    public:

        DirectXSwapchain() = default;
        ~DirectXSwapchain() override = default;

        void createSwapchain(SwapchainDescriptor* descriptor) override;
        void destroySwapchain() override;

        uint32_t getCurrentBackBufferIndex() override;
        void getBuffer(uint32_t bufferIndex, Resource* resource) override;

        DirectXSwapchain* getDHandle() override { return this; }

    private:

        Microsoft::WRL::ComPtr<IDXGISwapChain> buildSwapchain;
        Microsoft::WRL::ComPtr<IDXGISwapChain4> swapchain;

    };
}

#endif //JUPITER_DIRECTXSWAPCHAIN_H
