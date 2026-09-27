//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_INTERFACEALLOCATOR_H
#define JUPITER_INTERFACEALLOCATOR_H

#include "Api.h"

#include "interface/Device.h"
#include "interface/Instance.h"

namespace jupiter::rendering
{

    class InterfaceAllocator
    {
    public:

        InterfaceAllocator() = default;
        virtual ~InterfaceAllocator() = default;

        virtual Instance* allocateInstance() = 0;
        virtual void freeInstance(Instance* instance) = 0;

        virtual Device* allocateDevice() = 0;
        virtual void freeDevice(Device* device) = 0;

        static InterfaceAllocator* selectApi(Api api);
    };

}

#endif //JUPITER_INTERFACEALLOCATOR_H
