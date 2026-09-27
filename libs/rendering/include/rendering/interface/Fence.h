//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_FENCE_H
#define JUPITER_FENCE_H
#include <cstdint>
#include <exception>

namespace jupiter::rendering
{

    class Device;
    class DirectXFence;

    class Fence
    {

    public:

        Fence() = default;
        virtual ~Fence() = default;

        virtual void createFence(uint64_t initValue, Device* device) = 0;
        virtual void destroyFence(uint64_t fenceValue) = 0;

        virtual void createEvent() = 0;
        virtual void waitForPreviousFrame(uint64_t fenceValue) = 0;

        virtual DirectXFence* getDHandle() {throw std::exception{"[Soleil] Mauvais appel d'api !"};}

    };

}

#endif //JUPITER_FENCE_H
