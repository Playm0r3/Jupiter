//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_COMMANDLISTTYPE_H
#define JUPITER_COMMANDLISTTYPE_H

#include <d3d12.h>

namespace jupiter::rendering
{
    enum CommandListType
    {
        WM_COMMAND_LIST_TYPE_DIRECT
    };

    namespace utils
    {
        D3D12_COMMAND_LIST_TYPE getCommandListTypeFromCommandListType(CommandListType type);
    }
}

#endif //JUPITER_COMMANDLISTTYPE_H
