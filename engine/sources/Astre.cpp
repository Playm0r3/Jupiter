//
// Created by Warren on 03/10/2026.
//

#include "jupiter/Astre.h"

namespace jupiter::engine
{
    Astre::~Astre()
    {
        for (int i = 0; i < components.getSize() ; i++)
            delete components[i];
    }

    Component* Astre::getComponent(const int& index)
    {
        if (index < 0 || index >= static_cast<int>(components.getSize()))
            return nullptr;

        return components[index];
    }
}