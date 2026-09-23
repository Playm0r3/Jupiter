//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_SWAPCHAIN_H
#define JUPITER_SWAPCHAIN_H

#include <exception>

namespace jupiter::rendering
{

    class DirectXSwapchain;
    class Resource;

    struct SwapchainDescriptor;

    class Swapchain
    {
    public:

        Swapchain() = default;
        virtual ~Swapchain() = default;

        virtual void createSwapchain(SwapchainDescriptor* descriptor) = 0;
        virtual void destroySwapchain() = 0;

        virtual uint32_t getCurrentBackBufferIndex() = 0;
        virtual void getBuffer(uint32_t bufferIndex, Resource* resource) = 0;

        virtual DirectXSwapchain* getDHandle() { throw std::exception{"[Soleil] Mauvais appel d'api"}; }
    };
}

#endif //JUPITER_SWAPCHAIN_H
