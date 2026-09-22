//
// Created by Warren on 22/09/2026.
//

#ifndef JUPITER_DIRECTXINSTANCE_H
#define JUPITER_DIRECTXINSTANCE_H

#include <wrl.h>
#include <D3d12SDKLayers.h>

#include "../interface/Instance.h"

namespace jupiter::rendering
{
    class DirectXInstance : public Instance
    {
    public:

        DirectXInstance() = default;
        ~DirectXInstance() = default;

        void createInstance() override;
        void destroyInstance() override;

    private:

        Microsoft::WRL::ComPtr<ID3D12Debug> debugController;

    };
}


#endif //JUPITER_DIRECTXINSTANCE_H
