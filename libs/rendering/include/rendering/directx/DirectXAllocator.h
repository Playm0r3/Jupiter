//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_DIRECTXALLOCATOR_H
#define JUPITER_DIRECTXALLOCATOR_H


#include "rendering/InterfaceAllocator.h"

#include "DirectXInstance.h"
#include "DirectXDevice.h"
#include "DirectXCommandQueue.h"
#include "DirectXCpuDescriptorHandle.h"
#include "DirectXDescriptorHeap.h"
#include "DirectXSwapchain.h"
#include "DirectXCommandAllocator.h"
#include "DirectXCommandList.h"
#include "DirectXCompiler.h"
#include "DirectXRootSignature.h"
#include "DirectXResource.h"
#include "DirectXPipelineState.h"
#include "DirectXFence.h"

namespace jupiter::rendering
{

    class DirectXAllocator : public InterfaceAllocator
    {

    public:

        DirectXAllocator() = default;
        ~DirectXAllocator() override = default;

        Instance* allocateInstance() override { return new DirectXInstance(); }
        void freeInstance(Instance* instance) override { instance->destroyInstance(); }

        Device* allocateDevice() override { return new DirectXDevice(); }
        void freeDevice(Device* device) override {device->destroyDevice(); }

        CommandQueue* allocateCommandQueue() override { return new DirectXCommandQueue();}
        void freeCommandQueue(CommandQueue* commandQueue) override {commandQueue->destroyCommandQueue();}

        Swapchain* allocateSwapchain() override {return new DirectXSwapchain();}
        void freeSwapchain(Swapchain* swapchain) override {swapchain->destroySwapchain();}

        DescriptorHeap* allocateDescriptorHeap() override {return new DirectXDescriptorHeap(); }
        void freeDescriptorHeap(DescriptorHeap* descriptorHeap) override { descriptorHeap->destroyDescriptorHeap(); }

        CpuDescriptorHandle* allocateCpuDescriptorHandle() override { return new DirectXCpuDescriptorHandle(); }
        void freeCpuDescriptorHandle(CpuDescriptorHandle* descriptorHandle) override { descriptorHandle->destroyCpuDescriptorHandle(); }

        CommandAllocator* allocateCommandAllocator() override { return new DirectXCommandAllocator();}
        void freeCommandAllocator(CommandAllocator* allocator) override { allocator->destroyCommandAllocator(); }

        RootSignature* allocateRootSignature() override { return new DirectXRootSignature();}
        void freeRootSignature(RootSignature* rootSignature) override { rootSignature->destroyRootSignature();}

        Compiler* allocateCompiler() override { return new DirectXCompiler(); }
        void freeCompiler(Compiler* compiler) override { compiler->destroyCompiler(); }

        PipelineState* allocatePipelineState() override { return new DirectXPipelineState();}
        void freePipelineState(PipelineState* pipelineState) override {pipelineState->destroyPipelineState();}

        CommandList* allocateCommandList() override {return new DirectXCommandList();}
        void freeCommandList(CommandList* cmdList) override { cmdList->destroyCommandList();}

        Fence* allocateFence() override { return new DirectXFence(); }
        void freeFence(Fence* fence) override { fence->destroyFence(); }

        Resource* allocateResource() override {return new DirectXResource();}
        void freeResource(Resource* resource) override {resource->destroyResource();}

    };

}

#endif //JUPITER_DIRECTXALLOCATOR_H
