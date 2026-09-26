//
// Created by Warren on 25/09/2026.
//

#ifndef JUPITER_PIPELINESTATE_H
#define JUPITER_PIPELINESTATE_H

#include <exception>

namespace jupiter::rendering
{

    class Device;
    class DirectXPipelineState;

    struct PipelineStateDescriptor;

    class PipelineState
    {

    public:

        PipelineState();
        virtual ~PipelineState() = 0;

        virtual void createPipelineState(Device* device, PipelineStateDescriptor* descriptor) = 0;
        virtual void destroyPipelineState() = 0;

        virtual DirectXPipelineState* getDHandle() { throw std::exception{"[Soleil] Mauvais appel d'api !"};}
    };

}

#endif //JUPITER_PIPELINESTATE_H
