//
// Created by Warren on 26/09/2026.
//

#include "rendering/directx/DirectXShader.h"

namespace jupiter::rendering
{

    bool DirectXShader::copyShaderByteCode()
    {
        if (shader == nullptr) return false;

        byteCode.resize(shader->GetBufferSize());
        memcpy(byteCode.data(), shader->GetBufferPointer(), shader->GetBufferSize());
        return true;
    }

}