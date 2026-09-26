//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_DIRECTXCOMPILER_H
#define JUPITER_DIRECTXCOMPILER_H

#include <d3d12.h>
#include <dxcapi.h>
#include <wrl.h>

#include "rendering/interface/Compiler.h"

namespace jupiter::rendering
{
    class DirectXCompiler : public Compiler
    {

    public:

        DirectXCompiler() = default;
        ~DirectXCompiler() override = default;

        void createCompiler() override;
        void destroyCompiler() override;

        Shader* compileShader(const wchar_t* filePath, const wchar_t* entryPoint, const wchar_t* targetProfile) override;

    private:

        Microsoft::WRL::ComPtr<IDxcUtils> utils;
        Microsoft::WRL::ComPtr<IDxcCompiler3> compiler;


    };
}

#endif //JUPITER_DIRECTXCOMPILER_H
