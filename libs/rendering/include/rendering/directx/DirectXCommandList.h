//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_DIRECTXCOMMANDLIST_H
#define JUPITER_DIRECTXCOMMANDLIST_H

#include <d3d12.h>
#include <wrl.h>

#include "rendering/interface/CommandList.h"
#include "rendering/interface/CpuDescriptorHandle.h"
#include "rendering/interface/RootSignature.h"

namespace jupiter::rendering
{


    class DirectXCommandList : public CommandList
    {

    public:

        DirectXCommandList() = default;
        ~DirectXCommandList() override = default;

        void createCommandList(CommandListDescriptor* descriptor) override;
        void destroyCommandList() override;

        void close() override;
        void reset(CommandAllocator* allocator, PipelineState* pipeline) override;
        void resourceBarrier(int bCount, ResourceBarrier* barriers) override;
        void copyResource(Resource* src, Resource* dst) override;

        void setGraphicsRootSignature(RootSignature* rootSignature) override;
        void rootSignatureSetViewPort(uint32_t viewPortCount, Viewport* viewport) override;
        void rootSignatureSetScissorRects(uint32_t scissorCount, Scissor* scissorRects) override;

        void oMSetRenderTarget(uint32_t count, void* renderTargetDescriptor, bool singleDescriptor, void* depthStencilDescriptor) override;
        void clearRenderTargetView(void* cpuHandle, float color[4], uint32_t rectNum, Rect* rect) override;
        void setPrimitiveTopology(PrimitiveTopology topology) override;
        void setVertexBuffer(uint32_t startSlot, uint32_t numViews, Resource* vertexBuffer) override;
        void drawInstanced(uint32_t vertexPerInstance, uint32_t instanceCount, uint32_t startVertexLocation, uint32_t startInstanceLocation) override;

        DirectXCommandList* getDHandle() override { return this; };

    private:

        Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;

        friend class DirectXCommandQueue;

    };

}

#endif //JUPITER_DIRECTXCOMMANDLIST_H
