//
// Created by Warren on 22/09/2026.
//

#ifndef JUPITER_DIRECTXDEVICE_H
#define JUPITER_DIRECTXDEVICE_H

#include "../interface/Device.h"

#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>

namespace jupiter::rendering
{

    class DirectXDevice : public Device
    {

    public:

        DirectXDevice() = default;
        ~DirectXDevice() = default;;

        void createDevice() override;
        void destroyDevice() override;

        DirectXDevice* getHandle() override { return this; }

    private:

        UINT dxgiFactoryFlag = 0;

        Microsoft::WRL::ComPtr<IDXGIFactory6> factory;
        Microsoft::WRL::ComPtr<IDXGIAdapter1> adapter;
        Microsoft::WRL::ComPtr<ID3D12Device> device;

        friend class DirectXCommandQueue;

    };

}

#endif //JUPITER_DIRECTXDEVICE_H
