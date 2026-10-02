//
// Created by Warren on 23/09/2026.
//

#include "rendering/interface/HeapDescriptorType.h"

#include <iostream>

namespace jupiter::rendering::utils
{
    D3D12_DESCRIPTOR_HEAP_TYPE getHeapTypeFromDescriptorType(HeapDescriptorType type)
    {
        switch (type)
        {
        case HeapDescriptorType::WM_HEAP_DESCRIPTOR_TYPE_RTV:
            return D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        default:
            std::cout << "[Soleil] HeapDescriptorType inconnu retour du type RTV" << std::endl;
            return D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        }
    }
}