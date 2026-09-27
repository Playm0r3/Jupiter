//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_COMMANDLIST_H
#define JUPITER_COMMANDLIST_H

#include <exception>

namespace jupiter::rendering
{

    class CommandAllocator;
    class Resource;
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
        virtual void reset(CommandAllocator* allocator) = 0;
        virtual void resourceBarrier(int bCount, ResourceBarrier* barriers) = 0;
        virtual void copyResource(Resource* src, Resource* dst) = 0;

        virtual DirectXCommandList* getDHandle() { throw std::exception{"[Soleil] Mauvais appel d'api !"};}

    };
}

#endif //JUPITER_COMMANDLIST_H
