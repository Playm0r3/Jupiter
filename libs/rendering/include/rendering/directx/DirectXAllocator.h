//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_DIRECTXALLOCATOR_H
#define JUPITER_DIRECTXALLOCATOR_H


#include "rendering/InterfaceAllocator.h"

#include "DirectXInstance.h"
#include "DirectXDevice.h"

namespace jupiter::rendering
{

    class DirectXAllocator : public InterfaceAllocator
    {

    public:

        DirectXAllocator() = default;
        ~DirectXAllocator() override = default;

        Instance* allocateInstance() override { return new DirectXInstance(); }
        void freeInstance(Instance* instance) override { instance->destroyInstance(); }

        Device* allocateDevice() override { return new DirectXDevice(); }
        void freeDevice(Device* device) override {device->destroyDevice(); }

    };

}

#endif //JUPITER_DIRECTXALLOCATOR_H
