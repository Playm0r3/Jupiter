//
// Created by Warren on 04/10/2026.
//

#ifndef JUPITER_TRANSFORM_H
#define JUPITER_TRANSFORM_H

#include "Component.h"
#include "jmath/vectors/Vector.h"

namespace jupiter::engine
{
    class Transform : public Component
    {

    public:

        Transform();
        ~Transform() override;

        math::Vector3 position{};
        math::Vector3 rotation{};
        math::Vector3 scale{1.0, 1.0, 1.0};

    private:

        math::Vector3 forward{1.0, 0.0, 0.0};
        math::Vector3 right{0.0, 1.0, 0.0};
        math::Vector3 up{0.0, 0.0, 1.0};

    };
}

#endif //JUPITER_TRANSFORM_H
