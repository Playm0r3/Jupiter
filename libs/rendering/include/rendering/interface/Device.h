//
// Created by Warren on 22/09/2026.
//

#ifndef JUPITER_DEVICE_H
#define JUPITER_DEVICE_H

#include <exception>

#include "rendering/interface/HeapDescriptorType.h"
#include "rendering/interface/CommandListType.h"

namespace jupiter::rendering
{

    class Resource;
    class CpuDescriptorHandle;
    class DirectXDevice;
    class CommandAllocator;

    class Device
    {
    public:

        Device() = default;
        virtual ~Device() = default;

        virtual void createDevice() = 0;
        virtual void destroyDevice() = 0;

        virtual uint32_t getDescriptorHandleIncrementSize(HeapDescriptorType type) = 0;
        virtual void createRenderTargetView(Resource* resource, CpuDescriptorHandle* cdh) = 0;
        virtual void createCommandAllocator(CommandListType type, CommandAllocator* allocator) = 0;

        virtual DirectXDevice* getDHandle() {throw std::exception{"[Soleil] Mauvais appel d'api"};};

    };
}

#endif //JUPITER_DEVICE_H
