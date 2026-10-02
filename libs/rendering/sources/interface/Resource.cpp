//
// Created by Warren on 30/09/2026.
//

#include "rendering/interface/Resource.h"

namespace jupiter::rendering
{
    void Resource::setResourceSize(uint32_t size)
    {
        this->size = size;
    }

    void Resource::setResourceStride(uint32_t stride)
    {
        this->stride = stride;
    }

    void Resource::setResourceSizeAndStride(uint32_t size, uint32_t stride)
    {
        this->setResourceSize(size);
        this->setResourceStride(stride);
    }
}