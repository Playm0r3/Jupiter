//
// Created by Warren on 06/10/2026.
//

#ifndef JUPITER_RENDERER_H
#define JUPITER_RENDERER_H

#include "soleil.h"
#include "rendering/interface/MeshLoader.h"

namespace jupiter
{

    using namespace rendering;

    class Window;

    struct GpuMesh
    {
        Resource* vertices;
        Resource* indices;
        uint32_t indexCount;
    };

    class Renderer
    {

    public:

        Renderer();
        ~Renderer();

        void createRenderer(Api api, Window* window);
        void destroyRenderer();

        void loadMesh(const std::filesystem::path& fileToLoad);
        void render();

        Compiler* compiler;
        MeshLoader* meshLoader;

    private:

        InterfaceAllocator* allocator;

        Instance* instance;
        Device* device;
        Swapchain* swapchain;
        DescriptorHeap* rtv;
        DescriptorHeap* dsv;
        CpuDescriptorHandle* rtvDescriptorHandle;
        CpuDescriptorHandle* dsvDescriptorHandle;
        CpuDescriptorHandle* csuDescriptorHandle;
        RootSignature* signature;
        PipelineState* pipeline;

        CommandQueue* queue;
        CommandAllocator* commandAllocator;
        CommandList* commandList;

        Resource* resources[2];
        Resource* resourceDsv;

        uint32_t DescriptorIncrementSizeRTV;
        uint32_t DescriptorIncrementSizeDSV;
        uint32_t DescriptorIncrementSizeCSU;

        std::vector<MeshData> loadedMeshes{};
        std::vector<GpuMesh> loadedResources{};

        SwapchainDescriptor getSwapchainDescriptor(Device* device, CommandQueue* queue, Window* window);
        ResourceDescriptor getDepthStencilResourceDescriptor();

        Fence* currentFrameFence;

    };

}

#endif //JUPITER_RENDERER_H
