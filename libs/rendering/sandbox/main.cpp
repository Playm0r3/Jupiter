//
// Created by Warren on 22/09/2026.
//

#include "../include/rendering/directx/DirectXInstance.h"
#include "../include/rendering/interface/Instance.h"

#include "../include/rendering/directx/DirectXDevice.h"

#include "../include/rendering/directx/DirectXCommandQueue.h"

int main()
{

    jupiter::rendering::Instance* instance = new jupiter::rendering::DirectXInstance();
    instance->createInstance();

    jupiter::rendering::Device* device = new jupiter::rendering::DirectXDevice();
    device->createDevice();

    jupiter::rendering::CommandQueue* queue = new jupiter::rendering::DirectXCommandQueue();
    queue->createCommandQueue(device);

    return 0;
}