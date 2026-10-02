//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_DIRECTXCPUDESCRIPTORHANDLE_H
#define JUPITER_DIRECTXCPUDESCRIPTORHANDLE_H

#include <d3d12.h>

#include "rendering/interface/CpuDescriptorHandle.h"

namespace jupiter::rendering
{
    class DirectXCpuDescriptorHandle : public CpuDescriptorHandle
    {

    public:

        DirectXCpuDescriptorHandle() = default;
        ~DirectXCpuDescriptorHandle() override = default;

        void createCpuDescriptorHandle(DescriptorHeap* descriptorHeap) override;
        void destroyCpuDescriptorHandle() override;

        void offset(uint32_t rtvDescriptorSize) override;

        DirectXCpuDescriptorHandle* getDHandle() override { return this; }

    private:

        D3D12_CPU_DESCRIPTOR_HANDLE handle {};

        friend class DirectXDevice;

    };
}

#endif //JUPITER_DIRECTXCPUDESCRIPTORHANDLE_H
