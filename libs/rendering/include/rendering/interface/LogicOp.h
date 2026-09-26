//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_LOGICOP_H
#define JUPITER_LOGICOP_H

#include <d3d12.h>

namespace jupiter::rendering
{
    enum LogicOperation
    {
        WM_LOGIC_OPERATION_NOOP,
    };

    namespace utils
    {
        D3D12_LOGIC_OP getLogicOpFromLogicOperation(const LogicOperation& logicOp);
    }
}

#endif //JUPITER_LOGICOP_H
