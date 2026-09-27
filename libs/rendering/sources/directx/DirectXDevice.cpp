//
// Created by Warren on 22/09/2026.
//

#include "rendering/directx/DirectXDevice.h"
#include "rendering/directx/DirectXResource.h"
#include "rendering/directx/DirectXCpuDescriptorHandle.h"
#include "rendering/directx/DirectXCommandAllocator.h"

#include "rendering/interface/CommitedResourceDescriptor.h"
#include "rendering/interface/ResourceDescriptor.h"
#include "rendering/interface/HeapProperties.h"
#include "rendering/interface/InputFormat.h"

#include <iostream>

namespace jupiter::rendering
{

    void DirectXDevice::createDevice()
    {
#ifdef DEBUG
        dxgiFactoryFlag |= DXGI_CREATE_FACTORY_DEBUG;
#endif

        CreateDXGIFactory2(dxgiFactoryFlag, IID_PPV_ARGS(&factory));
        factory->EnumAdapterByGpuPreference(0, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&adapter));
        HRESULT hr = D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device));

        if (FAILED(hr))
        {
            std::cout << "[Soleil] Impossible de creer un 'device'" << std::endl;
        }
    }

    void DirectXDevice::destroyDevice()
    {

    }

    uint32_t DirectXDevice::getDescriptorHandleIncrementSize(HeapDescriptorType type)
    {
        return device->GetDescriptorHandleIncrementSize(utils::getHeapTypeFromDescriptorType(type));
    }

    void DirectXDevice::createRenderTargetView(Resource* resource, CpuDescriptorHandle* cdh)
    {
        DirectXResource* r = resource->getDHandle();
        DirectXCpuDescriptorHandle* handle = cdh->getDHandle();

        device->CreateRenderTargetView(r->resource.Get(), nullptr, handle->handle);
    }

    void DirectXDevice::createCommandAllocator(CommandListType type, CommandAllocator* allocator)
    {
        DirectXCommandAllocator* a = allocator->getDHandle();
        HRESULT hr = device->CreateCommandAllocator(utils::getCommandListTypeFromCommandListType(type), IID_PPV_ARGS(&a->allocator));
        if (!FAILED(hr)) return;

        std::cout << "[Soleil] Impossible de creer un alloueur de commande !" << std::endl;
    }

    void DirectXDevice::createCommitedResource(CommittedResourceDescriptor* descriptor)
    {
        D3D12_HEAP_PROPERTIES hProps = getHeapProperties(descriptor->heapProperties);
        D3D12_RESOURCE_DESC rDesc = getResourceDescriptor(descriptor->resourceDescriptor);
        descriptor->resource = new DirectXResource{};
        DirectXResource* r = descriptor->resource->getDHandle();

        HRESULT hr = device->CreateCommittedResource(&hProps, D3D12_HEAP_FLAG_NONE, &rDesc,
            utils::getResourceStateFromResourceState(descriptor->resourceState), nullptr, IID_PPV_ARGS(&r->resource));;
        if (!FAILED(hr)) return;

        std::cout << "[Soleil] Impossible de creer une committed resource" << std::endl;
    }

    D3D12_HEAP_PROPERTIES DirectXDevice::getHeapProperties(HeapProperties* props)
    {
        D3D12_HEAP_PROPERTIES heapProps{};
        heapProps.Type = utils::getHeapTypeFromHeapType(props->heapType);
        heapProps.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
        heapProps.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
        heapProps.CreationNodeMask = props->creationNodeMask;
        heapProps.VisibleNodeMask = props->visibleNodeMask;

        return heapProps;
    }

    D3D12_RESOURCE_DESC DirectXDevice::getResourceDescriptor(ResourceDescriptor* desc)
    {
        D3D12_RESOURCE_DESC rDesc{};
        rDesc.Dimension = utils::getResourceDimensionFromResourceDimension(desc->dimension);
        rDesc.Alignment = desc->allignment;
        rDesc.Width = desc->width;
        rDesc.Height = desc->height;
        rDesc.DepthOrArraySize = desc->depthOrArraySize;
        rDesc.MipLevels = desc->mipLevels;
        rDesc.Format = utils::getFormat(desc->format);
        rDesc.SampleDesc.Count = desc->sampleDescriptorCount;
        rDesc.SampleDesc.Quality = desc->sampleDescriptorQuality;
        rDesc.Layout = utils::getTextureLayoutFromTextureLayout(desc->layout);
        rDesc.Flags = static_cast<D3D12_RESOURCE_FLAGS>(desc->resourceFlags);

        return rDesc;
    }
}
