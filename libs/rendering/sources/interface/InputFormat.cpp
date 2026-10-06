//
// Created by Warren on 26/09/2026.
//

#include "rendering/interface/InputFormat.h"

namespace jupiter::rendering::utils
{

    DXGI_FORMAT getFormat(const InputFormat& inputFormat)
    {
        switch (inputFormat)
        {
        case InputFormat::WM_INPUT_FORMAT_FLOAT_3:
            return DXGI_FORMAT_R32G32B32_FLOAT;
        case InputFormat::WM_INPUT_FORMAT_FLOAT_4:
            return DXGI_FORMAT_R32G32B32A32_FLOAT;
        case InputFormat::WM_INPUT_FORMAT_FLOAT_32_BIT:
            return DXGI_FORMAT_D32_FLOAT;
        case InputFormat::WM_INPUT_FORMAT_UNDEFINED:
        default:
            return DXGI_FORMAT_UNKNOWN;
        }
    }

}