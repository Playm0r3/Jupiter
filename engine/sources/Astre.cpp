//
// Created by Warren on 03/10/2026.
//

#include "jupiter/Astre.h"

namespace jupiter::engine
{
    Component* Astre::getComponent(const int& index) const
    {
        if (index < 0 || index >= static_cast<int>(components.size()))
            return nullptr;

        return components[index];
    }
}