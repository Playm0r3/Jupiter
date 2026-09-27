//
// Created by Warren on 22/09/2026.
//

#include "soleil.h"

#include "../include/rendering/interface/Instance.h"
#include "../include/rendering/interface/SwapchainDescriptor.h"
#include "../include/rendering/interface/HeapDescriptor.h"
#include "../include/rendering/interface/HeapDescriptorType.h"
#include "../include/rendering/interface/InputLayout.h"

#include "../include/rendering/directx/DirectXInstance.h"
#include "../include/rendering/directx/DirectXDevice.h"
#include "../include/rendering/directx/DirectXCommandQueue.h"
#include "../include/rendering/directx/DirectXSwapchain.h"
#include "../include/rendering/directx/DirectXDescriptorHeap.h"
#include "../include/rendering/directx/DirectXCpuDescriptorHandle.h"
#include "../include/rendering/directx/DirectXResource.h"
#include "../include/rendering/directx/DirectXCommandAllocator.h"
#include "../include/rendering/directx/DirectXRootSignature.h"
#include "../include/rendering/directx/DirectXCompiler.h"

#include<SDL3/SDL.h>
#include <iostream>

using namespace jupiter::rendering;

int main()
{
    try
    {

        if (!SDL_Init(SDL_INIT_VIDEO))
            throw std::exception(SDL_GetError());

        SDL_Window* window = SDL_CreateWindow("SandBox", 1080, 720, 0);
        if (!window) throw std::exception(SDL_GetError());
        SDL_PropertiesID props = SDL_GetWindowProperties(window);
        if (!props) throw std::exception(SDL_GetError());
        HWND hwnd = (HWND)SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
        if (!hwnd) throw std::exception("Impossible de récupérer le HWND");
        uint32_t frameCount = 3;

        InterfaceAllocator* allocator = InterfaceAllocator::selectApi(DIRECTX_12);

        Instance* instance = allocator->allocateInstance();
        Device* device = allocator->allocateDevice();

        instance->createInstance();
        device->createDevice();

        std::cout << "Device created" << std::endl;

        jupiter::rendering::CommandQueue* queue = new jupiter::rendering::DirectXCommandQueue();
        queue->createCommandQueue(device);
        std::cout << "CommandQueue created" << std::endl;

        jupiter::rendering::SwapchainDescriptor scDesc = {};
        scDesc.device = device;
        scDesc.commandQueue = queue;
        scDesc.bufferCount = frameCount;
        scDesc.windowHandles = &hwnd;

        jupiter::rendering::Swapchain* swapchain = new jupiter::rendering::DirectXSwapchain();
        swapchain->createSwapchain(&scDesc);
        std::cout << "Swapchain created" << std::endl;
        uint32_t frameIndex = swapchain->getCurrentBackBufferIndex();

        // Création des DescriptorHeap pour les RTV

        jupiter::rendering::HeapDescriptor heapDesc = {};
        heapDesc.numberDescriptor = frameCount;
        heapDesc.type = jupiter::rendering::WM_HEAP_DESCRIPTOR_TYPE_RTV;

        jupiter::rendering::DescriptorHeap* heap = new jupiter::rendering::DirectXDescriptorHeap();
        heap->createDescriptorHeap(device, &heapDesc);
        std::cout << "DescriptorHeap created" << std::endl;

        uint32_t descriptorSize = device->getDescriptorHandleIncrementSize(jupiter::rendering::WM_HEAP_DESCRIPTOR_TYPE_RTV);

        jupiter::rendering::CpuDescriptorHandle* handle = new jupiter::rendering::DirectXCpuDescriptorHandle();
        handle->createCpuDescriptorHandle(heap);
        std::cout << "CpuDescriptorHandle created" << std::endl;

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

        std::cout << "RTVs Descriptor created" << std::endl;

        jupiter::rendering::CommandAllocator* a = new jupiter::rendering::DirectXCommandAllocator();
        device->createCommandAllocator(jupiter::rendering::WM_COMMAND_LIST_TYPE_DIRECT, a);
        std::cout << "CommandAllocator created" << std::endl;

        jupiter::rendering::RootSignature* root = new jupiter::rendering::DirectXRootSignature();
        root->createRootSignature(device);

        jupiter::rendering::Compiler* compiler = new jupiter::rendering::DirectXCompiler();
        compiler->createCompiler();

        jupiter::rendering::Shader* vertex = compiler->compileShader(L"main.hlsl", L"VSMain", L"vs_6_0");
        jupiter::rendering::Shader* pixel = compiler->compileShader(L"main.hlsl", L"PSMain", L"ps_6_0");

        jupiter::rendering::InputLayout* pLayout = new jupiter::rendering::InputLayout();
        pLayout->semanticName = "POSITION";
        pLayout->semanticIndex = 0;
        pLayout->inputFormat = jupiter::rendering::WM_INPUT_FORMAT_FLOAT_3;
        pLayout->inputSlot = 0;
        pLayout->alignedByteOffset = 0;
        pLayout->instanceDataStepRate = 0;

        jupiter::rendering::InputLayout* cLayout = new jupiter::rendering::InputLayout();
        cLayout->semanticName = "COLOR";
        cLayout->semanticIndex = 0;
        cLayout->inputFormat = jupiter::rendering::WM_INPUT_FORMAT_FLOAT_4;
        cLayout->inputSlot = 0;
        cLayout->alignedByteOffset = 12;
        cLayout->instanceDataStepRate = 0;



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

        delete pLayout;
        delete cLayout;

    } catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
