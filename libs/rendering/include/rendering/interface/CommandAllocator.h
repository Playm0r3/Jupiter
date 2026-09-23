//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_COMMANDALLOCATOR_H
#define JUPITER_COMMANDALLOCATOR_H

#include <exception>

namespace jupiter::rendering
{

    class DirectXCommandAllocator;

    class CommandAllocator
    {

    public:

        CommandAllocator() = default;
        virtual ~CommandAllocator() = default;

        virtual void createCommandAllocator() = 0;
        virtual void destroyCommandAllocator() = 0;

        virtual DirectXCommandAllocator* getDHandle() {throw std::exception{"[Soleil] Mauvais appel d'api !"}; }

    };

}

#endif //JUPITER_COMMANDALLOCATOR_H
