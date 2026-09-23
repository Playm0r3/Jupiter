//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_DIRECTXHEAPRTV_H
#define JUPITER_DIRECTXHEAPRTV_H

#include <wrl.h>

#include "rendering/interface/DescriptorHeap.h"
#include "rendering/interface/HeapDescriptor.h"

namespace jupiter::rendering
{

    class DirectXDescriptorHeap : public DescriptorHeap
    {

    public:

        DirectXDescriptorHeap() = default;
        ~DirectXDescriptorHeap() override = default;

        void createDescriptorHeap(Device* device, HeapDescriptor* descriptor) override;
        void destroyDescriptorHeap() override;

        DirectXDescriptorHeap* getDHandle() override { return this; }

    private:

        D3D12_CPU_DESCRIPTOR_HANDLE getCPUDescriptorHandleForHeapStart();

        Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> descriptorHeap;

        friend class DirectXCpuDescriptorHandle;

    };

}

#endif //JUPITER_DIRECTXHEAPRTV_H
