//
// Created by Warren on 26/09/2026.
//

#ifndef JUPITER_BLENDSTATE_H
#define JUPITER_BLENDSTATE_H

#include "RenderTargetBlendDescriptor.h"

namespace jupiter::rendering
{

    struct BlendDescriptor
    {
        bool alphaToCoverageEnable = false;
        bool independentBlendEnable = false;
        RenderTarget renderTarget[8]{};
    };

}

#endif //JUPITER_BLENDSTATE_H
