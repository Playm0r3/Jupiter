//
// Created by Warren on 25/09/2026.
//

#ifndef JUPITER_SHADER_H
#define JUPITER_SHADER_H

#include <hlsl/dx/linalg.h>
#include <exception>

#include <d3d12.h>
#include <wrl.h>

namespace jupiter::rendering
{

    class DirectXShader;

    class Shader
    {

    public:

        Shader() = default;
        virtual ~Shader() = default;

        virtual DirectXShader* getDHandle() {throw std::exception{"[Soleil] Mauvais appel d'api !"};}

    };

}

#endif //JUPITER_SHADER_H
