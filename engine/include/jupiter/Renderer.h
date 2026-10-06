//
// Created by Warren on 06/10/2026.
//

#ifndef JUPITER_RENDERER_H
#define JUPITER_RENDERER_H

#include "soleil.h"

namespace jupiter
{

    using namespace rendering;

    class Window;

    class Renderer
    {

    public:

        Renderer();
        ~Renderer();

        void createRenderer(Api api, Window* window);
        void destroyRenderer();

    private:

        InterfaceAllocator* allocator;

        Instance* instance;
        Device* device;
        Swapchain* swapchain;
        DescriptorHeap* rtv;
        DescriptorHeap* dsv;
        CpuDescriptorHandle* rtvDescriptorHandle;
        CpuDescriptorHandle* dsvDescriptorHandle;

        CommandQueue* queue;
        CommandAllocator* commandAllocator;
        CommandList* commandList;

        Resource* resources[3];
        Resource* resourceDsv;

        uint32_t DescriptorIncrementSizeRTV;
        uint32_t DescriptorIncrementSizeDSV;

        SwapchainDescriptor getSwapchainDescriptor(Device* device, CommandQueue* queue, Window* window);
        ResourceDescriptor getDepthStencilResourceDescriptor();

    };

}

#endif //JUPITER_RENDERER_H
