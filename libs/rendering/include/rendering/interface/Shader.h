//
// Created by Warren on 25/09/2026.
//

#ifndef JUPITER_SHADER_H
#define JUPITER_SHADER_H

namespace jupiter::rendering
{

    class Shader
    {

    public:

        Shader() = default;
        virtual ~Shader() = default;

        virtual void createShader() = 0;
        virtual void destroyShader() = 0;

    };

}

#endif //JUPITER_SHADER_H
