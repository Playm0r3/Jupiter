//
// Created by Warren on 23/09/2026.
//

#ifndef JUPITER_CPUDESCRIPTORHANDLE_H
#define JUPITER_CPUDESCRIPTORHANDLE_H

#include <exception>

namespace jupiter::rendering
{
    class DirectXCpuDescriptorHandle;
    class DescriptorHeap;

    class CpuDescriptorHandle
    {

    public:

        CpuDescriptorHandle() = default;
        virtual ~CpuDescriptorHandle() = default;

        virtual void createCpuDescriptorHandle(DescriptorHeap* descriptorHeap) = 0;
        virtual void destroyCpuDescriptorHandle() = 0;

        virtual void offset(uint32_t rtvDescriptorSize) = 0;

        virtual DirectXCpuDescriptorHandle* getDHandle() { throw std::exception{"[Soleil] Mauvais appel d'api ! "}; }

    };
}

#endif //JUPITER_CPUDESCRIPTORHANDLE_H
