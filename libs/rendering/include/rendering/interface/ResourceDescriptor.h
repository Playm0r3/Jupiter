//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_RESOURCEDESCRIPTOR_H
#define JUPITER_RESOURCEDESCRIPTOR_H

#include <cstdint>

#include "rendering/interface/InputFormat.h"
#include "rendering/interface/ResourceDimension.h"
#include "rendering/interface/TextureLayout.h"

namespace jupiter::rendering
{

    struct ResourceDescriptor
    {

        ResourceDimension dimension = WM_RESOURCE_DIMENSION_BUFFER;
        uint64_t allignment = 0;
        uint64_t width = 0;
        uint32_t height = 0;
        uint16_t depthOrArraySize = 1;
        uint16_t mipLevels = 0;
        InputFormat format = WM_INPUT_FORMAT_FLOAT;
        uint32_t sampleDescriptorCount = 0;
        uint32_t sampleDescriptorQuality = 0;
        TextureLayout layout = WM_TEXTURE_LAYOUT_UNKNOWN;
        uint32_t resourceFlags = 0;

    };

}

#endif //JUPITER_RESOURCEDESCRIPTOR_H
