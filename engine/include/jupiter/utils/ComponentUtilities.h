//
// Created by Warren on 06/10/2026.
//

#ifndef JUPITER_COMPONENTUTILITIES_H
#define JUPITER_COMPONENTUTILITIES_H
#include <type_traits>

namespace jupiter::engine
{
    class Component;

    namespace utils
    {
        template <typename T> bool isComponent(void* tester)
        {
            if (std::is_base_of_v<Component, T>)
                return true;

            return false;
        }
    }
}



#endif //JUPITER_COMPONENTUTILITIES_H
