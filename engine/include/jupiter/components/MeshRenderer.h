//
// Created by Warren on 06/10/2026.
//

#ifndef JUPITER_MESHRENDERER_H
#define JUPITER_MESHRENDERER_H

#include "jupiter/components/Component.h"
#include "Soleil.h"

namespace jupiter::engine
{

    using namespace rendering;

    class MeshRenderer : public Component
    {

    public:

        MeshRenderer();
        ~MeshRenderer() override;


    private:

        Resource* vertex;
        Resource* index;

    };
}

#endif //JUPITER_MESHRENDERER_H
