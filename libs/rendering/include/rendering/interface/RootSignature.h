//
// Created by Warren on 24/09/2026.
//

#ifndef JUPITER_ROOTSIGNATURE_H
#define JUPITER_ROOTSIGNATURE_H

namespace jupiter::rendering
{

    class Device;

    class RootSignature
    {
    public:

        RootSignature() = default;
        virtual ~RootSignature() = default;

        virtual void createRootSignature(Device* device) = 0;
        virtual void destroyRootSignature() = 0;
    };
}

#endif //JUPITER_ROOTSIGNATURE_H
