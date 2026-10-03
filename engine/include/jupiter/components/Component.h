//
// Created by Warren on 03/10/2026.
//

#ifndef JUPITER_COMPONENTS_H
#define JUPITER_COMPONENTS_H

#include <string>

#include "descriptors/ComponentDescriptor.h"

namespace jupiter::engine
{

    class Astre;

    class Component
    {

    public:

        std::string name;
        Astre* astre;

        Component();
        virtual ~Component() = default;

        virtual void createComponent(ComponentDescriptor* descriptor) = 0;
        virtual void destroyComponent() = 0;

    };
}

#endif //JUPITER_COMPONENTS_H
