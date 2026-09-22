//
// Created by Warren on 22/09/2026.
//

#ifndef JUPITER_DEVICE_H
#define JUPITER_DEVICE_H

#include <exception>

namespace jupiter::rendering
{

    class DirectXDevice;

    class Device
    {
    public:

        Device() = default;
        virtual ~Device() = default;

        virtual void createDevice() = 0;
        virtual void destroyDevice() = 0;

        virtual DirectXDevice* getHandle() {throw std::exception{"[Soleil] Mauvais appel d'api"};};

    };
}

#endif //JUPITER_DEVICE_H
