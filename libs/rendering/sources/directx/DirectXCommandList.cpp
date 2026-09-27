//
// Created by Warren on 27/09/2026.
//



#include <iostream>
#include <vector>

#include "rendering/directx/DirectXCommandList.h"
#include "rendering/directx/DirectXDevice.h"
#include "rendering/directx/DirectXCommandAllocator.h"
#include "rendering/directx/DirectXPipelineState.h"
#include "rendering/directx/DirectXResource.h"

#include "rendering/interface/CommandListDescriptor.h"
#include "rendering/interface/ResourceBarrier.h"
#include "rendering/interface/ResourceBarrierType.h"


namespace jupiter::rendering
{
    void DirectXCommandList::createCommandList(CommandListDescriptor* desc)
    {
        DirectXDevice* d = desc->device->getDHandle();
        DirectXCommandAllocator* a = desc->allocator->getDHandle();
        DirectXPipelineState* p = desc->pipeline->getDHandle();

        D3D12_COMMAND_LIST_TYPE type = utils::getCommandListTypeFromCommandListType(desc->type);

        HRESULT hr = d->device->CreateCommandList(desc->nodeMask, type, a->allocator.Get(), p->pipelineState.Get(), IID_PPV_ARGS(&commandList));
        if (!FAILED(hr)) return;

        std::cout << "[Soleil] Impossible de creer la list de commande" << std::endl;
    }

    void DirectXCommandList::destroyCommandList()
    {

    }

    void DirectXCommandList::close()
    {
        HRESULT hr = commandList->Close();
        if (!FAILED(hr)) return;

        std::cout << "[Soleil] Impossible de fermer la list de commande" << std::endl;
    }

    void DirectXCommandList::reset(CommandAllocator* allocator)
    {
        DirectXCommandAllocator* a = allocator->getDHandle();
        HRESULT hr = commandList->Reset(a->allocator.Get(), nullptr);
        if (!FAILED(hr)) return;

        std::cout << "[Soleil] Impossible de reinitialiser la liste de commande" << std::endl;
    }

    void DirectXCommandList::resourceBarrier(int bCount, ResourceBarrier* barriers)
    {
        std::vector<D3D12_RESOURCE_BARRIER> barrier(bCount);
        for (int i = 0 ; i < bCount ; i++)
        {
            DirectXResource* r = barriers[i].transition->resource->getDHandle();

            barrier[i].Type = utils::getBarrierType(barriers[i].type);
            barrier[i].Flags = static_cast<D3D12_RESOURCE_BARRIER_FLAGS>(barriers[i].flag);
            barrier[i].Transition.pResource = r->resource.Get();
            barrier[i].Transition.Subresource = barriers[i].transition->subResource;
            barrier[i].Transition.StateBefore = utils::getResourceStateFromResourceState(barriers[i].transition->stateBefore);
            barrier[i].Transition.StateAfter = utils::getResourceStateFromResourceState(barriers[i].transition->stateAfter);
        }

        commandList->ResourceBarrier(barrier.size(), barrier.data());
    }

    void DirectXCommandList::copyResource(Resource* src, Resource* dst)
    {
        const DirectXResource* r1 = src->getDHandle();
        const DirectXResource* r2 = dst->getDHandle();

        commandList->CopyResource(r1->resource.Get(), r2->resource.Get());
    }
}
