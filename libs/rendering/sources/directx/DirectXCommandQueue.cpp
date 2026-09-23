//
// Created by Warren on 22/09/2026.
//

#include "rendering/directx/DirectXCommandQueue.h"
#include "rendering/directx/DirectXDevice.h"

#include <iostream>

namespace jupiter::rendering
{
    void DirectXCommandQueue::createCommandQueue(Device* device)
    {
        D3D12_COMMAND_QUEUE_DESC desc = {};
        desc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
        desc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
        desc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
        desc.NodeMask = 0;

        HRESULT hr = device->getDHandle()->device->CreateCommandQueue(&desc, IID_PPV_ARGS(&commandQueue));

        if (FAILED(hr))
        {
            std::cout << "[Soleil] Impossible de creer une command queue" << std::endl;
        }
    }

    void DirectXCommandQueue::destroyCommandQueue()
    {

    }
}