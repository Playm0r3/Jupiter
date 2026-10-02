//
// Created by Warren on 30/09/2026.
//

#ifndef JUPITER_VIEWPORT_H
#define JUPITER_VIEWPORT_H
#include <cstdint>

namespace jupiter::rendering
{

    struct Viewport
    {
        uint32_t topLeftX = 0;
        uint32_t topLeftY = 0;
        uint32_t width = 0;
        uint32_t height = 0;
        uint32_t minDepth = 0;
        uint32_t maxDepth = 0;
    };

}

#endif //JUPITER_VIEWPORT_H
