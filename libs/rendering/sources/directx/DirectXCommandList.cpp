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
#include "rendering/directx/DirectXRootSignature.h"
#include "rendering/directx/DirectXDescriptorHeap.h"

#include "rendering/interface/CommandListDescriptor.h"
#include "rendering/interface/ResourceBarrier.h"
#include "rendering/interface/ResourceBarrierType.h"
#include "rendering/interface/PrimitiveTopology.h"

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

    void DirectXCommandList::reset(CommandAllocator* allocator, PipelineState* pipeline)
    {
        DirectXCommandAllocator* a = allocator->getDHandle();
        DirectXPipelineState* p = nullptr;
        HRESULT hr = S_OK;

        if (pipeline != nullptr)
        {
            p = pipeline->getDHandle();
            hr = commandList->Reset(a->allocator.Get(), p->pipelineState.Get());
        } else
        {
            hr = commandList->Reset(a->allocator.Get(), nullptr);
        }

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

    void DirectXCommandList::setGraphicsRootSignature(RootSignature* rootSignature)
    {
        DirectXRootSignature* r = rootSignature->getDHandle();
        commandList->SetGraphicsRootSignature(r->rootSignature.Get());
    }

    void DirectXCommandList::rootSignatureSetViewPort(uint32_t viewportCount, Viewport* viewport)
    {
        D3D12_VIEWPORT vp;
        vp.TopLeftX = viewport->topLeftX;
        vp.TopLeftY = viewport->topLeftY;
        vp.Width = viewport->width;
        vp.Height = viewport->height;
        vp.MinDepth = viewport->minDepth;
        vp.MaxDepth = viewport->maxDepth;

        commandList->RSSetViewports(viewportCount, &vp);
    }

    void DirectXCommandList::rootSignatureSetScissorRects(uint32_t scissorCount, Scissor* scissorRects)
    {
        D3D12_RECT scissor{};
        scissor.top = scissorRects->top;
        scissor.left = scissorRects->left;
        scissor.bottom = scissorRects->bottom;
        scissor.right = scissorRects->right;

        commandList->RSSetScissorRects(scissorCount, &scissor);
    }

    void DirectXCommandList::oMSetRenderTarget(uint32_t count, void* renderTargetDescriptor,
        bool singleDescriptor, void* depthStencilDescriptor)
    {
        D3D12_CPU_DESCRIPTOR_HANDLE* handle = nullptr;
        D3D12_CPU_DESCRIPTOR_HANDLE* depthHandle = nullptr;

        if (renderTargetDescriptor != nullptr) handle = ((D3D12_CPU_DESCRIPTOR_HANDLE*)renderTargetDescriptor);
        if (depthStencilDescriptor != nullptr) depthHandle = ((D3D12_CPU_DESCRIPTOR_HANDLE*)depthStencilDescriptor);

        commandList->OMSetRenderTargets(count, handle, static_cast<int>(singleDescriptor), depthHandle);
    }

    void DirectXCommandList::clearRenderTargetView(void* cpuHandle, float color[4], uint32_t rectNum, Rect* rect)
    {
        D3D12_CPU_DESCRIPTOR_HANDLE* handle = static_cast<D3D12_CPU_DESCRIPTOR_HANDLE*>(cpuHandle);
        D3D12_RECT* r = nullptr;

        if (rect != nullptr)
        {
            r = new D3D12_RECT;

            r->top = rect->top;
            r->bottom = rect->bottom;
            r->left = rect->left;
            r->right = rect->right;
        }

        commandList->ClearRenderTargetView(*handle, color, rectNum, r);
        delete r;
    }

    void DirectXCommandList::setPrimitiveTopology(PrimitiveTopology topology)
    {
        commandList->IASetPrimitiveTopology(utils::getPrimitiveTopology(topology));
    }

    void DirectXCommandList::setVertexBuffer(uint32_t startSlot, uint32_t numViews, Resource* vertexBuffer)
    {
        DirectXResource* r = vertexBuffer->getDHandle();

        D3D12_VERTEX_BUFFER_VIEW view{};
        view.BufferLocation = r->resource->GetGPUVirtualAddress();
        view.StrideInBytes = r->stride;
        view.SizeInBytes = r->size;

        commandList->IASetVertexBuffers(startSlot, numViews, &view);
    }

    void DirectXCommandList::drawInstanced(uint32_t vertexPerInstance, uint32_t instanceCount,
        uint32_t startVertexLocation, uint32_t startInstanceLocation)
    {
        commandList->DrawInstanced(vertexPerInstance, instanceCount, startVertexLocation, startInstanceLocation);
    }
}
