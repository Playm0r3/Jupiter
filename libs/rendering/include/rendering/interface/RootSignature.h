//
// Created by Warren on 24/09/2026.
//

#ifndef JUPITER_ROOTSIGNATURE_H
#define JUPITER_ROOTSIGNATURE_H

#include <exception>

namespace jupiter::rendering
{

    class Device;
    class DirectXRootSignature;

    class RootSignature
    {
    public:

        RootSignature() = default;
        virtual ~RootSignature() = default;

        virtual void createRootSignature(Device* device) = 0;
        virtual void destroyRootSignature() = 0;

        virtual DirectXRootSignature* getDHandle() {throw std::exception{"[Soleil] Mauvais appel d'api !"};}
    };
}

#endif //JUPITER_ROOTSIGNATURE_H
