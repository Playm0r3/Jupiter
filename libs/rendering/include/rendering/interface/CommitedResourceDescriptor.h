//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_COMMITEDRESOURCEDESCRIPTOR_H
#define JUPITER_COMMITEDRESOURCEDESCRIPTOR_H

#include <cstdint>

#include "ClearValue.h"
#include "rendering/interface/ResourceState.h"

namespace jupiter::rendering
{

    struct HeapProperties;
    struct ResourceDescriptor;

    struct CommittedResourceDescriptor
    {
        HeapProperties* heapProperties = nullptr;
        ResourceDescriptor* resourceDescriptor = nullptr;
        uint32_t heapFlags = 0;
        ResourceState resourceState = WM_RESOURCE_STATE_COMMON;
        Resource* resource = nullptr;
        ClearValue clearValue;
    };

}

#endif //JUPITER_COMMITEDRESOURCEDESCRIPTOR_H
