//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_DIRECTXPIPELINESTATE_H
#define JUPITER_DIRECTXPIPELINESTATE_H

#include <d3d12.h>
#include <wrl.h>

#include "rendering/interface/PipelineState.h"
#include "rendering/interface/RasterizerDescriptor.h"
#include "rendering/interface/BlendDescriptor.h"

namespace jupiter::rendering
{
    class DirectXPipelineState : public PipelineState
    {

    public:

        DirectXPipelineState() = default;
        ~DirectXPipelineState() override = default;

        void createPipelineState(Device* device, PipelineStateDescriptor* descriptor) override;
        void destroyPipelineState() override;

        DirectXPipelineState* getDHandle() override { return this;}

    private:

        Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;

        D3D12_RASTERIZER_DESC getRasterizerDescriptor(RasterizerDescriptor* descriptor);
        D3D12_BLEND_DESC getBlendDescriptor(BlendDescriptor* descriptor);

    };
}

#endif //JUPITER_DIRECTXPIPELINESTATE_H
