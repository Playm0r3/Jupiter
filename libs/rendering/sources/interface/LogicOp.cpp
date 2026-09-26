//
// Created by Warren on 26/09/2026.
//

#include "rendering/interface/LogicOp.h"

#include "rendering/interface/BlendOp.h"

namespace jupiter::rendering::utils
{
    D3D12_LOGIC_OP getLogicOpFromLogicOperation(const LogicOperation& blendOp)
    {
        switch (blendOp)
        {
        case LogicOperation::WM_LOGIC_OPERATION_NOOP:
            return D3D12_LOGIC_OP_NOOP;
        default:
            return D3D12_LOGIC_OP_NOOP;
        }
    }
}
