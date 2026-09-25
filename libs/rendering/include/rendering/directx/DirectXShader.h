//
// Created by Warren on 25/09/2026.
//

#ifndef JUPITER_DIRECTXSHADER_H
#define JUPITER_DIRECTXSHADER_H

#include <d3d12.h>
#include <wrl.h>

#include "rendering/interface/Shader.h"

namespace jupiter::rendering
{

    class DirectXShader : public Shader
    {

    public:

        DirectXShader() = default;
        ~DirectXShader() override = default;

        void createShader() override;
        void destroyShader() override;

    private:

        Microsoft::WRL::ComPtr<ID3DBlob> shader;

    };

}

#endif //JUPITER_DIRECTXSHADER_H
