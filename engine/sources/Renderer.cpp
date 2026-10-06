//
// Created by Warren on 06/10/2026.
//

#include "jupiter/Renderer.h"

#include "jupiter/Window.h"
#include "rendering/interface/DepthBufferDescriptor.h"

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

        instance = allocator->allocateInstance();
        device = allocator->allocateDevice();
        queue = allocator->allocateCommandQueue();
        swapchain = allocator->allocateSwapchain();
        rtv = allocator->allocateDescriptorHeap();
        dsv = allocator->allocateDescriptorHeap();
        rtvDescriptorHandle = allocator->allocateCpuDescriptorHandle();
        dsvDescriptorHandle = allocator->allocateCpuDescriptorHandle();

        instance->createInstance();
        device->createDevice();
        queue->createCommandQueue(device);

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
        device->createDepthStencilView(resourceDsv, dsvDescriptorHandle, &dbd);
    }

    void Renderer::destroyRenderer()
    {

    }

    SwapchainDescriptor Renderer::getSwapchainDescriptor(Device* device, CommandQueue* queue, Window* window)
    {
        SwapchainDescriptor swapchainDescriptor;
        swapchainDescriptor.bufferCount = 2;
        swapchainDescriptor.device = device;
        swapchainDescriptor.commandQueue = queue;
        swapchainDescriptor.windowHandles = static_cast<HWND*>(window->getWindowHandle());

        return swapchainDescriptor;
    }

    ResourceDescriptor Renderer::getDepthStencilResourceDescriptor()
    {
        ResourceDescriptor dsv{};
        dsv.dimension = WM_RESOURCE_DIMENSION_TEXTURE2D;
        dsv.width = 1080;
        dsv.height = 720;
        dsv.depthOrArraySize = 1;
        dsv.mipLevels = 1;
        dsv.format = WM_INPUT_FORMAT_FLOAT_32_BIT;
        dsv.sampleDescriptorQuality = 0;
        dsv.sampleDescriptorCount = 1;
        dsv.layout = WM_TEXTURE_LAYOUT_UNKNOWN;
        dsv.resourceFlags = 0x2;

        return dsv;
    }
}
