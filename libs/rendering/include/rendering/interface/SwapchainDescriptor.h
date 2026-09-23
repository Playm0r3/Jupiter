//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_SWAPCHAINDESCRIPTOR_H
#define JUPITER_SWAPCHAINDESCRIPTOR_H
#include <cstdint>

#include "CommandListType.h"

namespace jupiter::rendering
{

    class Device;
    class CommandQueue;

    struct SwapchainDescriptor
    {
        Device* device = nullptr;
        CommandQueue* commandQueue = nullptr;
        uint32_t bufferCount = 3;
        HWND* windowHandles = nullptr;
    };
}

#endif //JUPITER_SWAPCHAINDESCRIPTOR_H
