//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_RESOURCE_H
#define JUPITER_RESOURCE_H

#include <exception>

namespace jupiter::rendering
{

    class DirectXResource;

    class Resource
    {
    public:

        Resource() = default;
        virtual ~Resource() = default;

        virtual void createResource() = 0;
        virtual void destroyResource() = 0;

        virtual void setResourceSize(uint32_t size);
        virtual void setResourceStride(uint32_t stride);
        virtual void setResourceSizeAndStride(uint32_t size, uint32_t stride);

        virtual void copyToUpload(void* data, size_t size) = 0;

        virtual DirectXResource* getDHandle() { throw std::exception{"[Soleil] Mauvais appel d'api !"}; }

    protected:

        uint32_t stride = 0;
        uint32_t size = 0;
    };

}

#endif //JUPITER_RESOURCE_H
