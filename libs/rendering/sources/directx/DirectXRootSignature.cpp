//
// Created by Warren on 24/09/2026.
//

#include "rendering/directx/DirectXRootSignature.h"
#include "rendering/directx/DirectXDevice.h"

#include <iostream>

namespace jupiter::rendering
{

    void DirectXRootSignature::createRootSignature(Device* device)
    {
        DirectXDevice* d = device->getDHandle();

        D3D12_ROOT_SIGNATURE_DESC desc{};
        desc.NumParameters = 0;
        desc.pParameters = nullptr;
        desc.NumStaticSamplers = 0;
        desc.pStaticSamplers = nullptr;
        desc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

        HRESULT shr = D3D12SerializeRootSignature(&desc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, nullptr);
        HRESULT dhr = d->device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&rootSignature));
        if (!FAILED(shr) && !FAILED(dhr)) return;

        std::cout << "[Soleil] Impossible de creer une root signature" << std::endl;
    }

}