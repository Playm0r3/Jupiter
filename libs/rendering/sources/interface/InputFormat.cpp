//
// Created by Warren on 26/09/2026.
//

#include "rendering/interface/InputFormat.h"

namespace jupiter::rendering
{

    DXGI_FORMAT getFormatFromInputFormat(const InputFormat& inputFormat)
    {
        switch (inputFormat)
        {
        case InputFormat::WM_INPUT_FORMAT_FLOAT_3:
            return DXGI_FORMAT_R32G32B32_FLOAT;
        case InputFormat::WM_INPUT_FORMAT_FLOAT_4:
            return DXGI_FORMAT_R32G32B32A32_FLOAT;
        default:
            return DXGI_FORMAT_UNKNOWN;
        }
    }

}