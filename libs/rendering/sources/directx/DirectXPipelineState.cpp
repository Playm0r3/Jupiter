//
// Created by Warren on 26/09/2026.
//

#include <vector>
#include <iostream>

#include "rendering/directx/DirectXPipelineState.h"
#include "rendering/directx/DirectXDevice.h"
#include "rendering/directx/DirectXRootSignature.h"
#include "rendering/directx/DirectXShader.h"

#include "rendering/interface/PipelineStateDescriptor.h"
#include "rendering/interface/InputLayout.h"

namespace jupiter::rendering
{

    void DirectXPipelineState::createPipelineState(Device* device, PipelineStateDescriptor* descriptor)
    {
        DirectXDevice* d = device->getDHandle();

        std::vector<D3D12_INPUT_ELEMENT_DESC> inputElements{descriptor->inputLayoutCount};
        for (int i = 0 ; i < descriptor->inputLayoutCount ; i++)
        {
            inputElements[i].SemanticName = descriptor->inputLayout[i].semanticName;
            inputElements[i].SemanticIndex = descriptor->inputLayout[i].semanticIndex;
            inputElements[i].Format = utils::getFormatFromInputFormat(descriptor->inputLayout[i].inputFormat);
            inputElements[i].InputSlot = descriptor->inputLayout[i].inputSlot;
            inputElements[i].AlignedByteOffset = descriptor->inputLayout[i].alignedByteOffset;
            inputElements[i].InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA; // checker "par instance" fait quoi de différent
            inputElements[i].InstanceDataStepRate = descriptor->inputLayout[i].instanceDataStepRate;
        }

        DirectXShader* vertexShader = descriptor->vertexShader->getDHandle();
        DirectXShader* pixelShader = descriptor->pixelShader->getDHandle();

        D3D12_RASTERIZER_DESC rasterizerDescriptor = getRasterizerDescriptor(descriptor->rasterizer);
        D3D12_BLEND_DESC blendDescriptor = getBlendDescriptor(descriptor->blend);

        D3D12_GRAPHICS_PIPELINE_STATE_DESC desc{};
        desc.InputLayout = {inputElements.data(), static_cast<uint32_t>(inputElements.size())};
        desc.pRootSignature = descriptor->rootSignature->getDHandle()->rootSignature.Get();
        desc.VS.pShaderBytecode = vertexShader->byteCode.data();
        desc.VS.BytecodeLength = vertexShader->byteCode.size();
        desc.PS.pShaderBytecode = pixelShader->byteCode.data();
        desc.PS.BytecodeLength = pixelShader->byteCode.size();
        desc.BlendState = blendDescriptor;
        desc.RasterizerState = rasterizerDescriptor;
        desc.DepthStencilState.DepthEnable = FALSE;
        desc.DepthStencilState.StencilEnable = FALSE;
        desc.SampleMask = 0xffffffff;
        desc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
        desc.NumRenderTargets = descriptor->numRenderTargets;
        desc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
        desc.SampleDesc.Count = 1;

        HRESULT hr = d->device->CreateGraphicsPipelineState(&desc, IID_PPV_ARGS(&pipelineState));
        if (!FAILED(hr)) return;

        std::cout << "[Soleil] Impossible de créer un GraphicsPipelineState" << std::endl;
    }

    void DirectXPipelineState::destroyPipelineState()
    {

    }

    D3D12_RASTERIZER_DESC DirectXPipelineState::getRasterizerDescriptor(RasterizerDescriptor* descriptor)
    {
        D3D12_RASTERIZER_DESC desc{};
        desc.FillMode = utils::getFillModeFromFillMode(descriptor->fillMode);
        desc.CullMode = utils::getCullModeFromCullMode(descriptor->cullMode);
        desc.FrontCounterClockwise = static_cast<int>(descriptor->frontCounterClockwise);
        desc.DepthBias = descriptor->depthBias;
        desc.DepthBiasClamp = descriptor->depthBiasClamp;
        desc.SlopeScaledDepthBias = descriptor->slopeScaleDepthBias;
        desc.DepthClipEnable = static_cast<int>(descriptor->depthClipEnable);
        desc.MultisampleEnable = static_cast<int>(descriptor->multisampleEnable);
        desc.ForcedSampleCount = descriptor->forcedSampleCount;
        desc.ConservativeRaster = static_cast<D3D12_CONSERVATIVE_RASTERIZATION_MODE>(descriptor->conservativeRasterizationMode);

        return desc;
    }

    D3D12_BLEND_DESC DirectXPipelineState::getBlendDescriptor(BlendDescriptor* descriptor)
    {
        D3D12_BLEND_DESC desc{};
        desc.AlphaToCoverageEnable = static_cast<int>(descriptor->alphaToCoverageEnable);
        desc.IndependentBlendEnable = static_cast<int>(descriptor->independentBlendEnable);

        for (int i = 0 ; i < 8 ;i++)
        {
            desc.RenderTarget[i].BlendEnable = static_cast<int>(descriptor->renderTarget[i].blendEnable);
            desc.RenderTarget[i].LogicOpEnable = static_cast<int>(descriptor->renderTarget[i].logicOpEnable);
            desc.RenderTarget[i].SrcBlend = utils::getBlendFromBlend(descriptor->renderTarget[i].srcBlend);
            desc.RenderTarget[i].DestBlend = utils::getBlendFromBlend(descriptor->renderTarget[i].dstBlend);
            desc.RenderTarget[i].BlendOp = utils::getBlendOpFromBlendOperation(descriptor->renderTarget[i].blendOperation);
            desc.RenderTarget[i].SrcBlendAlpha = utils::getBlendFromBlend(descriptor->renderTarget[i].srcBlendAlpha);
            desc.RenderTarget[i].DestBlendAlpha = utils::getBlendFromBlend(descriptor->renderTarget[i].dstBlendAlpha);
            desc.RenderTarget[i].BlendOpAlpha = utils::getBlendOpFromBlendOperation(descriptor->renderTarget[i].blendOperationAlpha);
            desc.RenderTarget[i].LogicOp = utils::getLogicOpFromLogicOperation(descriptor->renderTarget[i].logicOperation);
            desc.RenderTarget[i].RenderTargetWriteMask = descriptor->renderTarget[i].renderTargetWriteMask;
        }

        return desc;
    }

}
