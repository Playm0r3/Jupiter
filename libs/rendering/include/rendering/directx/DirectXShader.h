//
// Created by Warren on 25/09/2026.
//

#ifndef JUPITER_DIRECTXSHADER_H
#define JUPITER_DIRECTXSHADER_H

#include <d3d12.h>
#include <wrl.h>
#include <vector>

#include "rendering/interface/Shader.h"

namespace jupiter::rendering
{

    class DirectXShader : public Shader
    {

    public:

        DirectXShader() = default;
        ~DirectXShader() override = default;

        DirectXShader* getDHandle() override { return this; }

    private:

        Microsoft::WRL::ComPtr<ID3DBlob> shader;
        std::vector<uint8_t> byteCode;

        bool copyShaderByteCode();

        friend class DirectXCompiler;
        friend class DirectXPipelineState;

    };

}

#endif //JUPITER_DIRECTXSHADER_H
