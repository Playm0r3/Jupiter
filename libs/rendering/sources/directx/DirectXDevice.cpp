//
// Created by Warren on 22/09/2026.
//

#include "rendering/directx/DirectXDevice.h"
#include <iostream>

namespace jupiter::rendering
{

    void DirectXDevice::createDevice()
    {
#ifdef DEBUG
        dxgiFactoryFlag |= DXGI_CREATE_FACTORY_DEBUG;
#endif

        CreateDXGIFactory2(dxgiFactoryFlag, IID_PPV_ARGS(&factory));
        factory->EnumAdapterByGpuPreference(0, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&adapter));
        HRESULT hr = D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device));

        if (FAILED(hr))
        {
            std::cout << "[Soleil] Impossible de creer un 'device'" << std::endl;
        }
    }

    void DirectXDevice::destroyDevice()
    {

    }

}
