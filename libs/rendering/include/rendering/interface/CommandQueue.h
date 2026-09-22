//
// Created by Warren on 22/09/2026.
//

#ifndef JUPITER_COMMANDQUE_H
#define JUPITER_COMMANDQUE_H

namespace jupiter::rendering
{

    class Device;

    class CommandQueue
    {
    public:

        CommandQueue() = default;
        virtual ~CommandQueue() = default;

        virtual void createCommandQueue(Device* device) = 0;
        virtual void destroyCommandQueue() = 0;
    };
}

#endif //JUPITER_COMMANDQUE_H
