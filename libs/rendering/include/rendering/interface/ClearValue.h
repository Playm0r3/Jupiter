//
// Created by Warren on 07/10/2026.
//

#ifndef JUPITER_CLEARVALUE_H
#define JUPITER_CLEARVALUE_H

#include <cstdint>
#include <d3d12.h>

#include "InputFormat.h"

namespace jupiter::rendering
{
    struct ClearValue
    {
        InputFormat format;
        float color[4];
        float depth;
        uint8_t stencil;
    };
}

#endif //JUPITER_CLEARVALUE_H
