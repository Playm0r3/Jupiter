//
// Created by Warren on 23/09/2026.
//

#include <iostream>

#include "rendering/directx/DirectXResource.h"

namespace jupiter::rendering
{
    void DirectXResource::createResource()
    {

    }

    void DirectXResource::destroyResource()
    {

    }

    void DirectXResource::copyToUpload(void* data, size_t size)
    {
        void* mappedData = nullptr;
        HRESULT hr = resource->Map(0, nullptr, &mappedData);
        if (FAILED(hr)) throw std::exception{"[Soleil] Impossible de mapper la resource"};
        memcpy(mappedData, data, size);
        resource->Unmap(0, nullptr);
    }
}
