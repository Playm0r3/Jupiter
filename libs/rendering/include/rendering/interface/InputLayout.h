//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_INPUTLAYOUT_H
#define JUPITER_INPUTLAYOUT_H
#include <cstdint>

#include "InputFormat.h"


namespace jupiter::rendering
{
    struct InputLayout
    {
        const char* semanticName = nullptr;
        uint32_t semanticIndex = 0;
        InputFormat inputFormat;
        uint32_t inputSlot = 0;
        uint32_t alignedByteOffset = 0;
        uint32_t instanceDataStepRate = 0;
    };
}

#endif //JUPITER_INPUTLAYOUT_H
