//
// Created by Warren on 03/10/2026.
//

#ifndef JUPITER_COMPONENTS_H
#define JUPITER_COMPONENTS_H

#include <string>

namespace jupiter::engine
{

    class Astre;

    class Component
    {

    public:

        std::string name{""};
        Astre* astre = nullptr;

        Component() = default;
        virtual ~Component() = 0;

    };
}

#endif //JUPITER_COMPONENTS_H
