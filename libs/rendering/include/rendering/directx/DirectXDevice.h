//
// Created by Warren on 22/09/2026.
//

#ifndef JUPITER_DIRECTXDEVICE_H
#define JUPITER_DIRECTXDEVICE_H

#include "../interface/Device.h"

#include <dxgi1_6.h>
#include <wrl.h>

namespace jupiter::rendering
{

    class DirectXDevice : public Device
    {

    public:

        DirectXDevice() = default;
        ~DirectXDevice() override = default;

        void createDevice() override;
        void destroyDevice() override;

        uint32_t getDescriptorHandleIncrementSize(HeapDescriptorType type) override;
        void createRenderTargetView(Resource* resource, CpuDescriptorHandle* cdh) override;
        void createCommandAllocator(CommandListType type, CommandAllocator* allocator) override;

        DirectXDevice* getDHandle() override { return this; }

    private:

        UINT dxgiFactoryFlag = 0;

        Microsoft::WRL::ComPtr<IDXGIFactory6> factory;
        Microsoft::WRL::ComPtr<IDXGIAdapter1> adapter;
        Microsoft::WRL::ComPtr<ID3D12Device> device;

        friend class DirectXCommandQueue;
        friend class DirectXSwapchain;
        friend class DirectXDescriptorHeap;
        friend class DirectXRootSignature;
        friend class DirectXPipelineState;

    };

}

#endif //JUPITER_DIRECTXDEVICE_H
