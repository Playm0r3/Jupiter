//
// Created by Warren on 30/09/2026.
//

#include "rendering/interface/PrimitiveTopology.h"

namespace jupiter::rendering::utils
{

    D3D_PRIMITIVE_TOPOLOGY getPrimitiveTopology(PrimitiveTopology topology)
    {
        switch (topology)
        {
        case PrimitiveTopology::WM_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST:
            return D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        default:
            return D3D_PRIMITIVE_TOPOLOGY_UNDEFINED;
        }
    }

}