//
// Created by Warren on 22/09/2026.
//

#ifndef JUPITER_COMMANDQUE_H
#define JUPITER_COMMANDQUE_H

#include <exception>

namespace jupiter::rendering
{

    class Device;
    class CommandList;
    class Fence;
    class DirectXCommandQueue;

    class CommandQueue
    {
    public:

        CommandQueue() = default;
        virtual ~CommandQueue() = default;

        virtual void createCommandQueue(Device* device) = 0;
        virtual void destroyCommandQueue() = 0;

        virtual void executeCommandLists(uint32_t commandListCount, CommandList** commandLists) = 0;
        virtual void signal(Fence* fence) = 0;

        virtual DirectXCommandQueue* getDHandle() {throw std::exception{"[Soleil] Mauvais appel d'api"};}
    };
}

#endif //JUPITER_COMMANDQUE_H
