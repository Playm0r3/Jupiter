//
// Created by Warren on 25/09/2026.
//

#ifndef JUPITER_PIPELINESTATEDESCRIPTOR_H
#define JUPITER_PIPELINESTATEDESCRIPTOR_H
#include <cstdint>

namespace jupiter::rendering
{

    class RootSignature;

    struct PipelineStateDescriptor
    {
        RootSignature* rootSignature = nullptr;
        uint32_t numRenderTargets = 0;
    };
}

#endif //JUPITER_PIPELINESTATEDESCRIPTOR_H
