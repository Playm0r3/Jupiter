//
// Created by Warren on 26/09/2026.
//

#include <iostream>
#include <vector>

#include "rendering/directx/DirectXCompiler.h"
#include "rendering/directx/DirectXShader.h"

namespace jupiter::rendering
{

    void DirectXCompiler::createCompiler()
    {
        HRESULT uhr = DxcCreateInstance(CLSID_DxcUtils, IID_PPV_ARGS(&utils));
        HRESULT chr = DxcCreateInstance(CLSID_DxcCompiler, IID_PPV_ARGS(&compiler));
        if (!FAILED(uhr) && !FAILED(chr)) return;

        std::cerr << "[Soleil] Impossible de créer une instance du compilateur DXCompiler" << std::endl;
    }

    void DirectXCompiler::destroyCompiler()
    {

    }

    Shader* DirectXCompiler::compileShader(const wchar_t* filePath, const wchar_t* entryPoint, const wchar_t* targetProfile)
    {
        Microsoft::WRL::ComPtr<IDxcBlobEncoding> sourceBlob;
        if (utils->LoadFile(filePath, nullptr, &sourceBlob) < 0)
        {
            std::wcerr << "[Soleil] Impossible de charger le fichier " << filePath << std::endl;
            return nullptr;
        }

        DxcBuffer sourceBuffer;
        sourceBuffer.Ptr = sourceBlob->GetBufferPointer();
        sourceBuffer.Size = sourceBlob->GetBufferSize();
        sourceBuffer.Encoding = DXC_CP_ACP;

        LPCWSTR arguments[] = { filePath, L"-E", entryPoint, L"-T", targetProfile, DXC_ARG_OPTIMIZATION_LEVEL3};
        uint32_t argCount = sizeof(arguments) / sizeof(arguments[0]);

        Microsoft::WRL::ComPtr<IDxcResult> result;
        HRESULT rhr = compiler->Compile(&sourceBuffer, arguments, argCount, nullptr, IID_PPV_ARGS(&result));
        if (FAILED(rhr)) return nullptr;

        Microsoft::WRL::ComPtr<IDxcBlobUtf8> errors;
        result->GetOutput(DXC_OUT_ERRORS, IID_PPV_ARGS(&errors), nullptr);
        if (errors && errors->GetStringLength() > 0 || FAILED(result->GetStatus()))
        {
            std::cerr << "[Soleil] Erreur de compilation du shader : " << errors->GetStringPointer() << std::endl;
            return nullptr;
        }

        DirectXShader* shader = new DirectXShader();
        result->GetOutput(DXC_OUT_OBJECT, IID_PPV_ARGS(&shader->shader), nullptr);
        shader->copyShaderByteCode();

        return shader;
    }

}