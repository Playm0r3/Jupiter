//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_DIRECTXRESOURCE_H
#define JUPITER_DIRECTXRESOURCE_H
#include "rendering/interface/Resource.h"

#include <d3d12.h>
#include <wrl.h>

namespace jupiter::rendering
{

    class DirectXResource : public Resource
    {

    public:

        DirectXResource() = default;
        ~DirectXResource() override = default;

        void createResource() override;
        void destroyResource() override;

        DirectXResource* getDHandle() override {return this;};

    private:

        Microsoft::WRL::ComPtr<ID3D12Resource> resource;

        friend class DirectXSwapchain;
        friend class DirectXDevice;

    };

}

#endif //JUPITER_DIRECTXRESOURCE_H
