//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_COMPILER_H
#define JUPITER_COMPILER_H

namespace jupiter::rendering
{

    class Shader;

    class Compiler
    {

    public:

        Compiler() = default;
        virtual ~Compiler() = default;

        virtual void createCompiler() = 0;
        virtual void destroyCompiler() = 0;

        virtual Shader* compileShader(const wchar_t* filePath, const wchar_t* entryPoint, const wchar_t* targetProfile) = 0;

    };

}

#endif //JUPITER_COMPILER_H
