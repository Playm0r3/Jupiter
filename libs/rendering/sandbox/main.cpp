//
// Created by Warren on 22/09/2026.
//

#include "../include/rendering/interface/Instance.h"
#include "../include/rendering/interface/SwapchainDescriptor.h"
#include "../include/rendering/interface/HeapDescriptor.h"
#include "../include/rendering/interface/HeapDescriptorType.h"

#include "../include/rendering/directx/DirectXInstance.h"
#include "../include/rendering/directx/DirectXDevice.h"
#include "../include/rendering/directx/DirectXCommandQueue.h"
#include "../include/rendering/directx/DirectXSwapchain.h"
#include "../include/rendering/directx/DirectXDescriptorHeap.h"
#include "../include/rendering/directx/DirectXCpuDescriptorHandle.h"
#include "../include/rendering/directx/DirectXResource.h"
#include "../include/rendering/directx/DirectXCommandAllocator.h"

#include<SDL3/SDL.h>

int main()
{
    try
    {

        if (!SDL_Init(SDL_INIT_VIDEO))
            throw std::runtime_error(SDL_GetError());

        SDL_Window* window = SDL_CreateWindow("SandBox", 1920, 1080, 0);

        if (!window) throw std::runtime_error(SDL_GetError());

        SDL_PropertiesID props = SDL_GetWindowProperties(window);

        if (!props) throw std::runtime_error(SDL_GetError());

        HWND hwnd = (HWND)SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);

        if (!hwnd) throw std::runtime_error("Impossible de récupérer le HWND");

        uint32_t frameCount = 3;

        jupiter::rendering::Instance* instance = new jupiter::rendering::DirectXInstance();
        instance->createInstance();

        jupiter::rendering::Device* device = new jupiter::rendering::DirectXDevice();
        device->createDevice();

        jupiter::rendering::CommandQueue* queue = new jupiter::rendering::DirectXCommandQueue();
        queue->createCommandQueue(device);

        jupiter::rendering::SwapchainDescriptor scDesc = {};
        scDesc.device = device;
        scDesc.commandQueue = queue;
        scDesc.bufferCount = frameCount;
        scDesc.windowHandles = &hwnd;

        jupiter::rendering::Swapchain* swapchain = new jupiter::rendering::DirectXSwapchain();
        swapchain->createSwapchain(&scDesc);

        uint32_t frameIndex = swapchain->getCurrentBackBufferIndex();

        // Création des DescriptorHeap pour les RTV

        jupiter::rendering::HeapDescriptor heapDesc = {};
        heapDesc.numberDescriptor = frameCount;
        heapDesc.type = jupiter::rendering::WM_HEAP_DESCRIPTOR_TYPE_RTV;

        jupiter::rendering::DescriptorHeap* heap = new jupiter::rendering::DirectXDescriptorHeap();
        heap->createDescriptorHeap(device, &heapDesc);

        uint32_t descriptorSize = device->getDescriptorHandleIncrementSize(jupiter::rendering::WM_HEAP_DESCRIPTOR_TYPE_RTV);

        jupiter::rendering::CpuDescriptorHandle* handle = new jupiter::rendering::DirectXCpuDescriptorHandle();
        handle->createCpuDescriptorHandle(heap);

        jupiter::rendering::Resource* resources[3];
        resources[0] = new jupiter::rendering::DirectXResource();
        resources[1] = new jupiter::rendering::DirectXResource();
        resources[2] = new jupiter::rendering::DirectXResource();

        for (uint32_t i = 0 ; i < frameCount ; i++)
        {
            swapchain->getBuffer(i, resources[i]);
            device->createRenderTargetView(resources[i], handle);
            handle->offset(descriptorSize);
        }

        jupiter::rendering::CommandAllocator* allocator = new jupiter::rendering::DirectXCommandAllocator();
        device->createCommandAllocator(jupiter::rendering::WM_COMMAND_LIST_TYPE_DIRECT, allocator);

        bool running = true;
        while (running)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_EVENT_QUIT) running = false;
                if (event.type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED)
                {
                    // changer la swapchain
                }
            }

            //update
        }

    } catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
