//
// Created by Warren on 23/09/2026.
//

#include "rendering/directx/DirectXCpuDescriptorHandle.h"
#include "rendering/directx/DirectXDescriptorHeap.h"

namespace jupiter::rendering
{
    void DirectXCpuDescriptorHandle::createCpuDescriptorHandle(DescriptorHeap* descriptorHeap)
    {
        DirectXDescriptorHeap* descriptor = descriptorHeap->getDHandle();
        handle = descriptor->getCPUDescriptorHandleForHeapStart();
    }

    void DirectXCpuDescriptorHandle::destroyCpuDescriptorHandle()
    {

    }

    void DirectXCpuDescriptorHandle::offset(uint32_t rtvDescriptorSize)
    {
        handle.ptr += (1 * rtvDescriptorSize);
    }
}
