//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_INPUTFORMAT_H
#define JUPITER_INPUTFORMAT_H

#include <d3d12.h>

namespace jupiter::rendering
{
    enum InputFormat
    {
        WM_INPUT_FORMAT_FLOAT,
        WM_INPUT_FORMAT_FLOAT_2,
        WM_INPUT_FORMAT_FLOAT_3,
        WM_INPUT_FORMAT_FLOAT_4,
    };

    namespace utils
    {
        DXGI_FORMAT getFormatFromInputFormat(const InputFormat& inputFormat);
    }

}

#endif //JUPITER_INPUTFORMAT_H
