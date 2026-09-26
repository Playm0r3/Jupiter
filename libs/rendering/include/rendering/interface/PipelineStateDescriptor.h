//
// Created by Warren on 25/09/2026.
//

#ifndef JUPITER_PIPELINESTATEDESCRIPTOR_H
#define JUPITER_PIPELINESTATEDESCRIPTOR_H
#include <cstdint>

namespace jupiter::rendering
{

    class RootSignature;
    class InputLayout;
    class Shader;

    struct RasterizerDescriptor;
    struct BlendDescriptor;

    struct PipelineStateDescriptor
    {
        InputLayout* inputLayout = nullptr;
        uint32_t inputLayoutCount = 0;
        RootSignature* rootSignature = nullptr;
        uint32_t numRenderTargets = 0;
        Shader* vertexShader = nullptr;
        Shader* pixelShader = nullptr; // it's fragment
        RasterizerDescriptor* rasterizer = nullptr;
        BlendDescriptor* blend = nullptr;
    };
}

#endif //JUPITER_PIPELINESTATEDESCRIPTOR_H
