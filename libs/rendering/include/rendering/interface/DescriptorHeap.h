//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_HEAPRENDERTARGETVIEW_H
#define JUPITER_HEAPRENDERTARGETVIEW_H

#include <exception>

namespace jupiter::rendering
{

    struct HeapDescriptor;

    class Device;
    class DirectXDescriptorHeap;

    class DescriptorHeap
    {
    public:

        DescriptorHeap() = default;
        virtual ~DescriptorHeap() = default;

        virtual void createDescriptorHeap(Device* device, HeapDescriptor* descriptor) = 0;
        virtual void destroyDescriptorHeap() = 0;

        virtual DirectXDescriptorHeap* getDHandle() { throw std::exception{"[Soleil] Mauvais appel d'api ! "}; }
    };
}

#endif //JUPITER_HEAPRENDERTARGETVIEW_H
