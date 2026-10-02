//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_COMMANDLISTDESCRIPTOR_H
#define JUPITER_COMMANDLISTDESCRIPTOR_H

#include <cstdint>

#include "rendering/interface/CommandListType.h"

namespace jupiter::rendering
{

    class Device;
    class CommandAllocator;
    class PipelineState;

    struct CommandListDescriptor
    {
        Device* device = nullptr;
        CommandListType type = WM_COMMAND_LIST_TYPE_DIRECT;
        CommandAllocator* allocator = nullptr;
        PipelineState* pipeline = nullptr;
        uint32_t nodeMask = 0;
    };

}

#endif //JUPITER_COMMANDLISTDESCRIPTOR_H
