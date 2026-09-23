//
// Created by Warren on 23/09/2026.
//

#include "rendering/directx/DirectXDescriptorHeap.h"
#include "rendering/directx/DirectXDevice.h"
#include "rendering/interface/HeapDescriptor.h"

#include <iostream>

namespace jupiter::rendering
{

    void DirectXDescriptorHeap::createDescriptorHeap(Device* device, HeapDescriptor* descriptor)
    {
        DirectXDevice* d = device->getDHandle();

        D3D12_DESCRIPTOR_HEAP_DESC desc = {};
        desc.NumDescriptors = descriptor->numberDescriptor;
        desc.Type = utils::getHeapTypeFromDescriptorType(descriptor->type);
        desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

        HRESULT hr = d->device->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&descriptorHeap));
        if (!FAILED(hr)) return;

        std::cout << "[Soleil] Impossible de creer un tas de descripteur !" << std::endl;
    }

    void DirectXDescriptorHeap::destroyDescriptorHeap()
    {

    }

    D3D12_CPU_DESCRIPTOR_HANDLE DirectXDescriptorHeap::getCPUDescriptorHandleForHeapStart()
    {
        return descriptorHeap->GetCPUDescriptorHandleForHeapStart();
    }

}
