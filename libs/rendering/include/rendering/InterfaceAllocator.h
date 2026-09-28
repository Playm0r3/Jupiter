//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_INTERFACEALLOCATOR_H
#define JUPITER_INTERFACEALLOCATOR_H

#include "Api.h"

#include "interface/Device.h"
#include "interface/Instance.h"
#include "interface/CommandQueue.h"
#include "interface/Compiler.h"
#include "interface/DescriptorHeap.h"
#include "interface/RootSignature.h"
#include "interface/Swapchain.h"
#include "interface/PipelineState.h"

namespace jupiter::rendering
{

    class InterfaceAllocator
    {
    public:

        InterfaceAllocator() = default;
        virtual ~InterfaceAllocator() = default;

        virtual Instance* allocateInstance() = 0;
        virtual void freeInstance(Instance* instance) = 0;

        virtual Device* allocateDevice() = 0;
        virtual void freeDevice(Device* device) = 0;

        virtual CommandQueue* allocateCommandQueue() = 0;
        virtual void freeCommandQueue(CommandQueue* queue) = 0;

        virtual Swapchain* allocateSwapchain() = 0;
        virtual void freeSwapchain(Swapchain* swapchain) = 0;

        virtual DescriptorHeap* allocateDescriptorHeap() = 0;
        virtual void freeDescriptorHeap(DescriptorHeap* descriptorHeap) = 0;

        virtual CpuDescriptorHandle* allocateCpuDescriptorHandle() = 0;
        virtual void freeCpuDescriptorHandle(CpuDescriptorHandle* descriptorHandle) = 0;

        virtual CommandAllocator* allocateCommandAllocator() = 0;
        virtual void freeCommandAllocator(CommandAllocator* allocator) = 0;

        virtual RootSignature* allocateRootSignature() = 0;
        virtual void freeRootSignature(RootSignature* rootSignature) = 0;

        virtual Compiler* allocateCompiler() = 0;
        virtual void freeCompiler(Compiler* compiler) = 0;

        virtual PipelineState* allocatePipelineState() = 0;
        virtual void freePipelineState(PipelineState* pipelineState) = 0;

        virtual CommandList* allocateCommandList() = 0;
        virtual void freeCommandList(CommandList* commandList) = 0;

        static InterfaceAllocator* selectApi(Api api);
    };

}

#endif //JUPITER_INTERFACEALLOCATOR_H
