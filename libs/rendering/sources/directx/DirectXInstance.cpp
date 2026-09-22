//
// Created by Warren on 22/09/2026.
//

#include <rendering/directx/DirectXInstance.h>
#include <iostream>

namespace jupiter::rendering
{
    void DirectXInstance::createInstance()
    {
#ifdef _DEBUG
        if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
        {
            debugController->EnableDebugLayer();
            std::cout << "[Soleil] Couche de debuggage active !" << std::endl;
        }
#endif
    }

    void DirectXInstance::destroyInstance()
    {

    }
}

