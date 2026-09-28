//
// Created by Warren on 22/09/2026.
//

#include "soleil.h"

#include <d3d12.h>
#include<SDL3/SDL.h>
#include <iostream>

using namespace jupiter::rendering;

struct Vertex
{
    float position[3]{};
    float color[4]{};
};

int main()
{
    try
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
            throw std::exception(SDL_GetError());

        SDL_Window* window = SDL_CreateWindow("SandBox", 1080, 720, 0);
        if (!window) throw std::exception(SDL_GetError());
        SDL_PropertiesID props = SDL_GetWindowProperties(window);
        if (!props) throw std::exception(SDL_GetError());
        HWND hwnd = (HWND)SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
        if (!hwnd) throw std::exception("Impossible de récupérer le HWND");
        uint32_t frameCount = 3;

        InterfaceAllocator* allocator = InterfaceAllocator::selectApi(DIRECTX_12);

        Instance* instance = allocator->allocateInstance();
        Device* device = allocator->allocateDevice();
        CommandQueue* cmdQueue = allocator->allocateCommandQueue();
        Swapchain* swapchain = allocator->allocateSwapchain();
        DescriptorHeap* descriptorHeap = allocator->allocateDescriptorHeap();
        CpuDescriptorHandle* heapHandle = allocator->allocateCpuDescriptorHandle();

        instance->createInstance();
        device->createDevice();

        std::cout << "Device created" << std::endl;

        cmdQueue->createCommandQueue(device);
        std::cout << "CommandQueue created" << std::endl;

        jupiter::rendering::SwapchainDescriptor scDesc = {};
        scDesc.device = device;
        scDesc.commandQueue = cmdQueue;
        scDesc.bufferCount = frameCount;
        scDesc.windowHandles = &hwnd;

        swapchain->createSwapchain(&scDesc);
        std::cout << "Swapchain created" << std::endl;
        uint32_t frameIndex = swapchain->getCurrentBackBufferIndex();

        // Création des DescriptorHeap pour les RTV

        jupiter::rendering::HeapDescriptor heapDesc = {};
        heapDesc.numberDescriptor = frameCount;
        heapDesc.type = jupiter::rendering::WM_HEAP_DESCRIPTOR_TYPE_RTV;

        descriptorHeap->createDescriptorHeap(device, &heapDesc);
        std::cout << "DescriptorHeap created" << std::endl;

        uint32_t descriptorSize = device->getDescriptorHandleIncrementSize(jupiter::rendering::WM_HEAP_DESCRIPTOR_TYPE_RTV);

        heapHandle->createCpuDescriptorHandle(descriptorHeap);
        std::cout << "CpuDescriptorHandle created" << std::endl;

        jupiter::rendering::Resource* resources[3];
        resources[0] = new jupiter::rendering::DirectXResource();
        resources[1] = new jupiter::rendering::DirectXResource();
        resources[2] = new jupiter::rendering::DirectXResource();

        for (uint32_t i = 0 ; i < frameCount ; i++)
        {
            swapchain->getBuffer(i, resources[i]);
            device->createRenderTargetView(resources[i], heapHandle);
            heapHandle->offset(descriptorSize);
        }

        std::cout << "RTVs Descriptor created" << std::endl;

        jupiter::rendering::CommandAllocator* a = new jupiter::rendering::DirectXCommandAllocator();
        device->createCommandAllocator(jupiter::rendering::WM_COMMAND_LIST_TYPE_DIRECT, a);
        std::cout << "CommandAllocator created" << std::endl;

        jupiter::rendering::RootSignature* root = new jupiter::rendering::DirectXRootSignature();
        root->createRootSignature(device);

        jupiter::rendering::Compiler* compiler = new jupiter::rendering::DirectXCompiler();
        compiler->createCompiler();

        Shader* vertex = compiler->compileShader(L"main.hlsl", L"VSMain", L"vs_6_0");
        Shader* pixel = compiler->compileShader(L"main.hlsl", L"PSMain", L"ps_6_0");

        InputLayout pLayout = InputLayout();
        pLayout.semanticName = "POSITION";
        pLayout.semanticIndex = 0;
        pLayout.inputFormat = WM_INPUT_FORMAT_FLOAT_3;
        pLayout.inputSlot = 0;
        pLayout.alignedByteOffset = 0;
        pLayout.instanceDataStepRate = 0;

        InputLayout cLayout = InputLayout();
        cLayout.semanticName = "COLOR";
        cLayout.semanticIndex = 0;
        cLayout.inputFormat = WM_INPUT_FORMAT_FLOAT_4;
        cLayout.inputSlot = 0;
        cLayout.alignedByteOffset = 12;
        cLayout.instanceDataStepRate = 0;

        InputLayout* layout = new InputLayout[2] {};
        layout[0] = pLayout;
        layout[1] = cLayout;

        RasterizerDescriptor rasterizer = {};
        BlendDescriptor blend = {};

        PipelineStateDescriptor* pipelineDescriptor = new PipelineStateDescriptor();
        pipelineDescriptor->inputLayout = layout;
        pipelineDescriptor->inputLayoutCount = 2;
        pipelineDescriptor->rootSignature = root;
        pipelineDescriptor->vertexShader = vertex;
        pipelineDescriptor->pixelShader = pixel;
        pipelineDescriptor->rasterizer = &rasterizer;
        pipelineDescriptor->blend = &blend;
        pipelineDescriptor->numRenderTargets = 1;

        PipelineState* pipeline = allocator->allocatePipelineState();
        pipeline->createPipelineState(device, pipelineDescriptor);

        CommandListDescriptor clDescriptor = {};
        clDescriptor.allocator = a;
        clDescriptor.device = device;
        clDescriptor.pipeline = pipeline;
        clDescriptor.type = WM_COMMAND_LIST_TYPE_DIRECT;
        clDescriptor.nodeMask = 0;

        CommandList* cmdList = allocator->allocateCommandList();
        cmdList->createCommandList(&clDescriptor);
        cmdList->close();

        Vertex triangleVertices[] =
        {
            { { 0.0f, 0.25f, 0.0f }, { 1.0f, 0.0f, 0.0f, 1.0f } },
            { { 0.25f, -0.25f, 0.0f }, { 0.0f, 1.0f, 0.0f, 1.0f } },
            { { -0.25f, -0.25f, 0.0f }, { 0.0f, 0.0f, 1.0f, 1.0f } }
        };

        const uint32_t vertexBufferCount = sizeof(triangleVertices);

        Resource* vertexBufferResource;
        Resource* vertexBufferResourceUpload;

        HeapProperties hProps = {};
        hProps.heapType = WM_HEAP_TYPE_DEFAULT;
        hProps.creationNodeMask = 1;
        hProps.visibleNodeMask = 1;

        HeapProperties hPropsUpload = {};
        hPropsUpload.heapType = WM_HEAP_TYPE_UPLOAD;
        hPropsUpload.creationNodeMask = 1;
        hPropsUpload.visibleNodeMask = 1;

        ResourceDescriptor rDesc = {};
        rDesc.dimension = WM_RESOURCE_DIMENSION_BUFFER;
        rDesc.allignment = 0;
        rDesc.width = vertexBufferCount;
        rDesc.height = 1;
        rDesc.mipLevels = 1;
        rDesc.format = WM_INPUT_FORMAT_UNDEFINED;
        rDesc.sampleDescriptorCount = 1;
        rDesc.sampleDescriptorQuality = 0;
        rDesc.layout = WM_TEXTURE_LAYOUT_ROW_MAJOR;
        rDesc.resourceFlags = 0x0;
        rDesc.depthOrArraySize = 1;

        CommittedResourceDescriptor vertexCommittedResource = {};
        vertexCommittedResource.resourceDescriptor = &rDesc;
        vertexCommittedResource.resource = nullptr; // Indispensable
        vertexCommittedResource.resourceState = WM_RESOURCE_STATE_COMMON;
        vertexCommittedResource.heapProperties = &hProps;
        vertexCommittedResource.heapFlags = 0;

        CommittedResourceDescriptor vertexCommittedResourceUpload = {};
        vertexCommittedResourceUpload.resourceDescriptor = &rDesc;
        vertexCommittedResourceUpload.resource = nullptr; // Indispensable
        vertexCommittedResourceUpload.resourceState = WM_RESOURCE_STATE_GENERIC_READ;
        vertexCommittedResourceUpload.heapProperties = &hPropsUpload;
        vertexCommittedResourceUpload.heapFlags = 0;

        device->createCommitedResource(&vertexCommittedResource);
        device->createCommitedResource(&vertexCommittedResourceUpload);

        Resource* vertexBuffer = vertexCommittedResource.resource;
        Resource* vertexBufferUpload = vertexCommittedResourceUpload.resource;

        vertexBufferUpload->copyToUpload(triangleVertices, vertexBufferCount * sizeof(float));

        a->reset();
        cmdList->reset(a);

        ResourceTransitionBarrier transition = {};
        transition.resource = vertexBuffer;
        transition.stateBefore = WM_RESOURCE_STATE_COMMON;
        transition.stateAfter = WM_RESOURCE_STATE_COPY_DESTINATION;
        transition.subResource = 0xffffffff;

        ResourceBarrier barriers[1]{};
        barriers[0].transition = &transition;

        cmdList->resourceBarrier(1, &barriers[0]);
        cmdList->copyResource(vertexBuffer, vertexBufferUpload);

        barriers[0].transition->stateBefore = WM_RESOURCE_STATE_COPY_DESTINATION;
        barriers[0].transition->stateAfter = WM_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER;

        cmdList->resourceBarrier(1, &barriers[0]);
        cmdList->close();

        CommandList* cmdLists[] = {cmdList};
        cmdQueue->executeCommandLists(1, cmdLists);

        bool running = true;
        while (running)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_EVENT_QUIT) running = false;
                if (event.type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED)
                {
                    // changer la swapchain
                }
            }

            //update
        }

        delete pipelineDescriptor;

    } catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
