//
// Created by Warren on 06/10/2026.
//

#include "jupiter/Renderer.h"

#include <iostream>

#include "jupiter/Window.h"
#include "rendering/interface/DepthBufferDescriptor.h"
#include "rendering/interface/MeshLoader.h"

namespace jupiter
{

    Renderer::Renderer()
    {

    }

    Renderer::~Renderer()
    {

    }

    void Renderer::createRenderer(Api api, Window* window)
    {
        allocator = InterfaceAllocator::selectApi(api);
        meshLoader = allocator->allocateMeshLoader();

        instance = allocator->allocateInstance();
        device = allocator->allocateDevice();
        queue = allocator->allocateCommandQueue();
        swapchain = allocator->allocateSwapchain();
        rtv = allocator->allocateDescriptorHeap();
        dsv = allocator->allocateDescriptorHeap();
        rtvDescriptorHandle = allocator->allocateCpuDescriptorHandle();
        dsvDescriptorHandle = allocator->allocateCpuDescriptorHandle();
        csuDescriptorHandle = allocator->allocateCpuDescriptorHandle();
        signature = allocator->allocateRootSignature();
        commandAllocator = allocator->allocateCommandAllocator();
        currentFrameFence = allocator->allocateFence();
        commandList = allocator->allocateCommandList();

        instance->createInstance();
        device->createDevice();
        queue->createCommandQueue(device);

        currentFrameFence->createFence(0, device);
        pipeline = allocator->allocatePipelineState();

        SwapchainDescriptor swapchainDescriptor = getSwapchainDescriptor(device, queue, window);
        swapchain->createSwapchain(&swapchainDescriptor);

        HeapDescriptor heapDescriptor{};
        heapDescriptor.type = WM_HEAP_DESCRIPTOR_TYPE_RTV;
        heapDescriptor.numberDescriptor = 2;

        HeapDescriptor heapDescriptorDsv{};
        heapDescriptorDsv.type = WM_HEAP_DESCRIPTOR_TYPE_DSV;
        heapDescriptorDsv.numberDescriptor = 1;

        rtv->createDescriptorHeap(device, &heapDescriptor);
        DescriptorIncrementSizeRTV = device->getDescriptorHandleIncrementSize(WM_HEAP_DESCRIPTOR_TYPE_RTV);

        dsv->createDescriptorHeap(device, &heapDescriptorDsv);
        DescriptorIncrementSizeDSV = device->getDescriptorHandleIncrementSize(WM_HEAP_DESCRIPTOR_TYPE_DSV);

        rtvDescriptorHandle->createCpuDescriptorHandle(rtv);
        dsvDescriptorHandle->createCpuDescriptorHandle(dsv);

        resources[0] = allocator->allocateResource();
        resources[1] = allocator->allocateResource();
        resourceDsv = allocator->allocateResource();

        swapchain->getBuffer(0, resources[0]);
        device->createRenderTargetView(resources[0], rtvDescriptorHandle);
        rtvDescriptorHandle->offset(DescriptorIncrementSizeRTV);

        swapchain->getBuffer(1, resources[1]);
        device->createRenderTargetView(resources[1], rtvDescriptorHandle);
        // Peut être ajouter un offset ici

        ResourceDescriptor dsvResourceDescriptor = getDepthStencilResourceDescriptor();

        HeapProperties properties{};
        properties.heapType = WM_HEAP_TYPE_DEFAULT;
        properties.creationNodeMask = 1;
        properties.visibleNodeMask = 1;

        ClearValue clearValue{};
        clearValue.format = WM_INPUT_FORMAT_FLOAT_32_BIT;
        clearValue.depth = 1.0f;
        clearValue.stencil = 0.0f;
        clearValue.color[0] = 0.0f;
        clearValue.color[1] = 0.0f;
        clearValue.color[2] = 0.0f;
        clearValue.color[3] = 1.0f;

        CommittedResourceDescriptor crDesc{};
        crDesc.heapProperties = &properties;
        crDesc.heapFlags = 0;
        crDesc.resource = resourceDsv;
        crDesc.resourceDescriptor = &dsvResourceDescriptor;
        crDesc.resourceState = WM_RESOURCE_STATE_DEPTH_WRITE;
        crDesc.clearValue = clearValue;

        DepthBufferDescriptor dbd{};
        dbd.format = WM_INPUT_FORMAT_FLOAT_32_BIT;

        device->createCommitedResource(&crDesc);

        device->createDepthStencilView(resourceDsv, dsv, &dbd);

        device->createCommandAllocator(WM_COMMAND_LIST_TYPE_DIRECT, commandAllocator);

        CommandListDescriptor desc{};
        desc.allocator = commandAllocator;
        desc.device = device;
        desc.pipeline = nullptr;
        desc.nodeMask = 1;
        desc.type = WM_COMMAND_LIST_TYPE_DIRECT;

        commandList->createCommandList(&desc);
        commandList->close();

        Fence* fence = allocator->allocateFence();
        fence->createFence(1, device);

        signature->createRootSignature(device);

        compiler = allocator->allocateCompiler();
        compiler->createCompiler();

        Shader* vertex = compiler->compileShader(L"Debug.hlsl", L"VSMain", L"vs_6_0");
        Shader* pixel = compiler->compileShader(L"Debug.hlsl", L"PSMain", L"ps_6_0");

        InputLayout pLayout = InputLayout();
        pLayout.semanticName = "POSITION";
        pLayout.semanticIndex = 0;
        pLayout.inputFormat = WM_INPUT_FORMAT_FLOAT_3;
        pLayout.inputSlot = 0;
        pLayout.alignedByteOffset = 0;
        pLayout.instanceDataStepRate = 0;

        InputLayout nLayout = InputLayout();
        nLayout.semanticName = "NORMAL";
        nLayout.semanticIndex = 0;
        nLayout.inputFormat = WM_INPUT_FORMAT_FLOAT_3;
        nLayout.inputSlot = 0;
        nLayout.alignedByteOffset = 12;
        nLayout.instanceDataStepRate = 0;

        InputLayout tLayout = InputLayout();
        tLayout.semanticName = "TEXCOORD";
        tLayout.semanticIndex = 0;
        tLayout.inputFormat = WM_INPUT_FORMAT_FLOAT_3;
        tLayout.inputSlot = 0;
        tLayout.alignedByteOffset = 24;
        tLayout.instanceDataStepRate = 0;

        InputLayout* layouts = new InputLayout[3] {pLayout, nLayout, tLayout};

        RasterizerDescriptor rasterizer = {};
        BlendDescriptor blend = {};

        PipelineStateDescriptor* pipelineDescriptor = new PipelineStateDescriptor();
        pipelineDescriptor->inputLayout = layouts;
        pipelineDescriptor->inputLayoutCount = 3;
        pipelineDescriptor->rootSignature = signature;
        pipelineDescriptor->vertexShader = vertex;
        pipelineDescriptor->pixelShader = pixel;
        pipelineDescriptor->rasterizer = &rasterizer;
        pipelineDescriptor->blend = &blend;
        pipelineDescriptor->numRenderTargets = 1;

        pipeline = allocator->allocatePipelineState();
        pipeline->createPipelineState(device, pipelineDescriptor);

        commandAllocator->createCommandAllocator();

        // Chargement de resources test...

        loadMesh("Cube.fbx");
    }

    void Renderer::destroyRenderer()
    {
        for (const GpuMesh mesh : loadedResources)
        {
            delete mesh.vertices;
            delete mesh.indices;
        }
    }

    SwapchainDescriptor Renderer::getSwapchainDescriptor(Device* device, CommandQueue* queue, Window* window)
    {
        SwapchainDescriptor swapchainDescriptor;
        swapchainDescriptor.bufferCount = 2;
        swapchainDescriptor.device = device;
        swapchainDescriptor.commandQueue = queue;
        swapchainDescriptor.windowHandles = window->getWindowHandle();

        return swapchainDescriptor;
    }

    ResourceDescriptor Renderer::getDepthStencilResourceDescriptor()
    {
        ResourceDescriptor d{};
        d.dimension = WM_RESOURCE_DIMENSION_TEXTURE2D;
        d.allignment = 0;
        d.width = 1080;
        d.height = 720;
        d.depthOrArraySize = 1;
        d.mipLevels = 1;
        d.format = WM_INPUT_FORMAT_FLOAT_32_BIT;
        d.sampleDescriptorQuality = 0;
        d.sampleDescriptorCount = 1;
        d.layout = WM_TEXTURE_LAYOUT_UNKNOWN;
        d.resourceFlags = 0x2;

        return d;
    }

    void Renderer::loadMesh(const std::filesystem::path& fileToLoad)
    {
        meshLoader->createMeshLoader();
        std::vector<MeshData> data = meshLoader->loadMesh(fileToLoad);
        if (data.size() > 1) throw std::exception("[Jupiter] Pour le moment le moteur ne supporte pas l'import de fichier avec plusieurs models");
        if (data.empty()) return;
        loadedMeshes.push_back(data[0]);

        uint32_t vertexBufferSize = data[0].vertices.size() * sizeof(Vertex);
        uint32_t indexBufferSize = data[0].indices.size() * sizeof(uint32_t);

        HeapProperties d{};
        d.heapType = WM_HEAP_TYPE_DEFAULT;
        d.creationNodeMask = 1;
        d.visibleNodeMask = 1;

        HeapProperties u{};
        u.heapType = WM_HEAP_TYPE_UPLOAD;
        u.creationNodeMask = 1;
        u.visibleNodeMask = 1;

        ResourceDescriptor vDesc = {};
        vDesc.dimension = WM_RESOURCE_DIMENSION_BUFFER;
        vDesc.allignment = 0;
        vDesc.width = vertexBufferSize;
        vDesc.height = 1;
        vDesc.mipLevels = 1;
        vDesc.format = WM_INPUT_FORMAT_UNDEFINED;
        vDesc.sampleDescriptorCount = 1;
        vDesc.sampleDescriptorQuality = 0;
        vDesc.layout = WM_TEXTURE_LAYOUT_ROW_MAJOR;
        vDesc.resourceFlags = 0x0;
        vDesc.depthOrArraySize = 1;

        ResourceDescriptor iDesc = {};
        iDesc.dimension = WM_RESOURCE_DIMENSION_BUFFER;
        iDesc.allignment = 0;
        iDesc.width = indexBufferSize;
        iDesc.height = 1;
        iDesc.mipLevels = 1;
        iDesc.format = WM_INPUT_FORMAT_UNDEFINED;
        iDesc.sampleDescriptorCount = 1;
        iDesc.sampleDescriptorQuality = 0;
        iDesc.layout = WM_TEXTURE_LAYOUT_ROW_MAJOR;
        iDesc.resourceFlags = 0x0;
        iDesc.depthOrArraySize = 1;

        CommittedResourceDescriptor vertexCommittedResource = {};
        vertexCommittedResource.resourceDescriptor = &vDesc;
        vertexCommittedResource.resource = nullptr; // Indispensable
        vertexCommittedResource.resourceState = WM_RESOURCE_STATE_COPY_DESTINATION;
        vertexCommittedResource.heapProperties = &d;
        vertexCommittedResource.heapFlags = 0;

        CommittedResourceDescriptor vertexCommittedResourceUpload = {};
        vertexCommittedResourceUpload.resourceDescriptor = &vDesc;
        vertexCommittedResourceUpload.resource = nullptr; // Indispensable
        vertexCommittedResourceUpload.resourceState = WM_RESOURCE_STATE_GENERIC_READ;
        vertexCommittedResourceUpload.heapProperties = &u;
        vertexCommittedResourceUpload.heapFlags = 0;

        CommittedResourceDescriptor indexCommittedResource = {};
        indexCommittedResource.resourceDescriptor = &iDesc;
        indexCommittedResource.resource = nullptr; // Indispensable
        indexCommittedResource.resourceState = WM_RESOURCE_STATE_COPY_DESTINATION;
        indexCommittedResource.heapProperties = &d;
        indexCommittedResource.heapFlags = 0;

        CommittedResourceDescriptor indexCommittedResourceUpload = {};
        indexCommittedResourceUpload.resourceDescriptor = &iDesc;
        indexCommittedResourceUpload.resource = nullptr; // Indispensable
        indexCommittedResourceUpload.resourceState = WM_RESOURCE_STATE_GENERIC_READ;
        indexCommittedResourceUpload.heapProperties = &u;
        indexCommittedResourceUpload.heapFlags = 0;

        device->createCommitedResource(&vertexCommittedResource);
        device->createCommitedResource(&vertexCommittedResourceUpload);
        device->createCommitedResource(&indexCommittedResource);
        device->createCommitedResource(&indexCommittedResourceUpload);

        Resource* vertexBuffer = vertexCommittedResource.resource;
        Resource* vertexBufferUpload = vertexCommittedResourceUpload.resource;
        Resource* indexBuffer = indexCommittedResource.resource;
        Resource* indexBufferUpload = indexCommittedResourceUpload.resource;

        vertexBuffer->setResourceSizeAndStride(data[0].vertices.size(), sizeof(Vertex));
        indexBuffer->setResourceSizeAndStride(data[0].indices.size(), sizeof(uint32_t));

        vertexBufferUpload->copyToUpload(data[0].vertices.data(), vertexBufferSize); // 8 float par Vertex (3p, 3n, 2t)
        indexBufferUpload->copyToUpload(data[0].indices.data(), indexBufferSize);

        ResourceTransitionBarrier iTransition = {};
        iTransition.resource = indexBuffer;
        iTransition.stateBefore = WM_RESOURCE_STATE_COPY_DESTINATION;
        iTransition.stateAfter = WM_RESOURCE_STATE_INDEX_BUFFER;
        iTransition.subResource = 0xffffffff;

        ResourceBarrier barriers[2]{};
        barriers[0].transition->resource = vertexBuffer;
        barriers[0].transition->stateBefore = WM_RESOURCE_STATE_COPY_DESTINATION;
        barriers[0].transition->stateAfter = WM_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER;
        barriers[0].transition->subResource = 0xffffffff;

        barriers[1].transition->resource = indexBuffer;
        barriers[1].transition->stateBefore = WM_RESOURCE_STATE_COPY_DESTINATION;
        barriers[1].transition->stateAfter = WM_RESOURCE_STATE_INDEX_BUFFER;
        barriers[1].transition->subResource = 0xffffffff;

        commandAllocator->reset();
        commandList->reset(commandAllocator, nullptr);

        commandList->copyResource(vertexBuffer, vertexBufferUpload);
        commandList->copyResource(indexBuffer, indexBufferUpload);

        commandList->resourceBarrier(2, &barriers[0]);
        commandList->close();

        CommandList* cmdLists[] = {commandList};
        queue->executeCommandLists(1, cmdLists);

        Fence* fence = allocator->allocateFence();
        fence->createFence(0, device);
        queue->signal(fence);

        fence->waitGpuIdle();

        GpuMesh mesh{};
        mesh.vertices = vertexBuffer;
        mesh.indices = indexBuffer;
        mesh.indexCount = static_cast<uint32_t>(data[0].indices.size());
        loadedResources.push_back(mesh);

        delete vertexBufferUpload;
        delete indexBufferUpload;
    }

    void Renderer::render()
    {

        currentFrameFence->waitGpuIdle();

        commandAllocator->reset();
        commandList->reset(commandAllocator, pipeline);

        uint32_t currentFrame = swapchain->getCurrentBackBufferIndex();

        ResourceBarrier barrier{};
        barrier.type = WM_RESOURCE_BARRIER_TYPE_TRANSITION;
        barrier.flag = WM_RESOURCE_BARRIER_FLAGS_NONE;
        barrier.transition->resource = resources[currentFrame];
        barrier.transition->stateBefore = WM_RESOURCE_STATE_PRESENT;
        barrier.transition->stateAfter = WM_RESOURCE_STATE_RENDER_TARGET;
        barrier.transition->subResource = 0;

        Viewport viewport {};
        viewport.topLeftX = 0;
        viewport.topLeftY = 0;
        viewport.height = 720;
        viewport.width = 1080;
        viewport.minDepth = 0;
        viewport.maxDepth = 1.f;

        Scissor scissor{};
        scissor.left = 0;
        scissor.top = 0;
        scissor.right = 720L;
        scissor.bottom = 1080L;

        commandList->setGraphicsRootSignature(signature);
        commandList->rootSignatureSetViewPort(1, &viewport);
        commandList->rootSignatureSetScissorRects(1, &scissor);

        commandList->resourceBarrier(1, &barrier);

        size_t rtvMemPos = rtv->getCpuHandleWithOffset(currentFrame * DescriptorIncrementSizeRTV);
        size_t dsvMemPos = dsv->getCpuHandleWithOffset(0);
        commandList->oMSetRenderTarget(1, rtvMemPos, false, dsvMemPos);

        std::cout << "DSV create : " << std::endl;
        std::cout << "DSV clear : " << dsvDescriptorHandle->getAddress() << std::endl;

        float clearColor[] = {0.0f, 0.2f, 0.4f, 1.0f};
        commandList->clearRenderTargetView(rtvMemPos, clearColor, 0, nullptr);
        commandList->clearDepthStencilView(dsvDescriptorHandle->getAddress(), 1.0f, 0);
        commandList->setPrimitiveTopology(WM_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST);

        for (GpuMesh& mesh : loadedResources)
        {
            commandList->setVertexBuffer(0, 1, mesh.vertices);
            commandList->setIndexBuffer(mesh.indices);
            commandList->drawIndexedInstanced(mesh.indexCount, 1, 0, 0, 0);
        }

        barrier.transition->stateBefore = WM_RESOURCE_STATE_RENDER_TARGET;
        barrier.transition->stateAfter = WM_RESOURCE_STATE_PRESENT;

        commandList->resourceBarrier(1, &barrier);
        commandList->close();

        CommandList* cs[] = {commandList};
        queue->executeCommandLists(_countof(cs), cs);
        swapchain->present(1, 0);
        queue->signal(currentFrameFence);
    }
}
