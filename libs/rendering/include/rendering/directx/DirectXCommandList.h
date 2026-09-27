//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_DIRECTXCOMMANDLIST_H
#define JUPITER_DIRECTXCOMMANDLIST_H

#include <d3d12.h>
#include <wrl.h>

#include "rendering/interface/CommandList.h"

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
        void reset(CommandAllocator* allocator) override;
        void resourceBarrier(int bCount, ResourceBarrier* barriers) override;
        void copyResource(Resource* src, Resource* dst) override;

        DirectXCommandList* getDHandle() override { return this; };

    private:

        Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;

        friend class DirectXCommandQueue;

    };

}

#endif //JUPITER_DIRECTXCOMMANDLIST_H
