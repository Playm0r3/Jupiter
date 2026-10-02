//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_COMMANDLIST_H
#define JUPITER_COMMANDLIST_H

#include <exception>

#include "PrimitiveTopology.h"
#include "Rect.h"
#include "Viewport.h"

namespace jupiter::rendering
{

    class CommandAllocator;
    class Resource;
    class PipelineState;
    class DescriptorHeap;
    class RootSignature;
    class DirectXCommandList;

    struct CommandListDescriptor;
    struct ResourceBarrier;

    class CommandList
    {

    public:

        CommandList() = default;
        virtual ~CommandList() = default;

        virtual void createCommandList(CommandListDescriptor* descriptor) = 0;
        virtual void destroyCommandList() = 0;

        virtual void close() = 0;
        virtual void reset(CommandAllocator* allocator, PipelineState* pipeline) = 0;
        virtual void resourceBarrier(int bCount, ResourceBarrier* barriers) = 0;
        virtual void copyResource(Resource* src, Resource* dst) = 0;

        virtual void setGraphicsRootSignature(RootSignature* rootSignature) = 0;
        virtual void rootSignatureSetViewPort(uint32_t viewPortCount, Viewport* viewport) = 0;
        virtual void rootSignatureSetScissorRects(uint32_t scissorCount, Scissor* scissorRects) = 0;

        virtual void oMSetRenderTarget(uint32_t count, void* renderTargetDescriptor, bool singleDescriptor, void* depthStencilDescriptor) = 0;
        virtual void clearRenderTargetView(void* cpuHandle, float color[4], uint32_t rectNum, Rect* rect) = 0;
        virtual void setPrimitiveTopology(PrimitiveTopology topology) = 0;
        virtual void setVertexBuffer(uint32_t count, uint32_t c2, Resource* vertexBuffer) = 0;
        virtual void drawInstanced(uint32_t vertexPerInstance, uint32_t instanceCount, uint32_t startVertexLocation, uint32_t startInstanceLocation) = 0;

        virtual DirectXCommandList* getDHandle() { throw std::exception{"[Soleil] Mauvais appel d'api !"};}

    };
}

#endif //JUPITER_COMMANDLIST_H
