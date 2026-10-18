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

        D3D12_ROOT_PARAMETER params[1];
        params[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS;
        params[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
        params[0].Constants.Num32BitValues = 16;
        params[0].Constants.RegisterSpace = 0;
        params[0].Constants.ShaderRegister = 0;

        D3D12_ROOT_SIGNATURE_DESC desc{};
        desc.NumParameters = 1;
        desc.pParameters = params;
        desc.NumStaticSamplers = 0;
        desc.pStaticSamplers = nullptr;
        desc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

        Microsoft::WRL::ComPtr<ID3DBlob> error;

        HRESULT shr = D3D12SerializeRootSignature(&desc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error);

        if (FAILED(shr) || !signature)
        {
            std::cout << "[Soleil] Echec de la serialisation de la root signature";
            if (error)
                std::cout << " : " << static_cast<const char*>(error->GetBufferPointer());
            std::cout << std::endl;
            return;   // on ne touche pas à signature
        }

        HRESULT dhr = d->device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&rootSignature));
        if (!FAILED(shr) && !FAILED(dhr)) return;

        std::cout << "[Soleil] Impossible de creer une root signature" << std::endl;
    }

    void DirectXRootSignature::destroyRootSignature()
    {

    }

}