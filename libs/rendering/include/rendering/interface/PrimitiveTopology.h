//
// Created by Warren on 30/09/2026.
//

#ifndef JUPITER_PRIMITIVETOPOLOGY_H
#define JUPITER_PRIMITIVETOPOLOGY_H
#include <d3dcommon.h>

namespace jupiter::rendering
{
    enum PrimitiveTopology
    {
        WM_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
    };

    namespace utils
    {
        D3D_PRIMITIVE_TOPOLOGY getPrimitiveTopology(PrimitiveTopology topology);
    }
}

#endif //JUPITER_PRIMITIVETOPOLOGY_H
