//
// Created by Warren on 24/09/2026.
//

#ifndef JUPITER_DIRECTXROOTSIGNATURE_H
#define JUPITER_DIRECTXROOTSIGNATURE_H

#include "rendering/interface/RootSignature.h"

#include <d3d12.h>
#include <wrl.h>

namespace jupiter::rendering
{

    class DirectXRootSignature : public RootSignature
    {

    public:

        DirectXRootSignature() = default;
        ~DirectXRootSignature() override = default;

        void createRootSignature(Device* device) override;
        void destroyRootSignature() override;

    private:

        Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;
        Microsoft::WRL::ComPtr<ID3DBlob> signature;

    };

}

#endif //JUPITER_DIRECTXROOTSIGNATURE_H
