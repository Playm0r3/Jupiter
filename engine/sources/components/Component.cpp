//
// Created by Warren on 06/10/2026.
//

#include "jupiter/components/Component.h"

namespace jupiter::engine
{
    Component::~Component()
    {
        name = "";
        astre = nullptr;
    }
}