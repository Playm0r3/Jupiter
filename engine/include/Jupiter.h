//
// Created by Warren on 06/10/2026.
//

#ifndef JUPITER_JUPITER_H
#define JUPITER_JUPITER_H

#include "jupiter/window.h"

namespace jupiter
{
    class Jupiter
    {

    public:

        Jupiter();
        ~Jupiter();

    private:

        Window* window = nullptr;

        void initJupiter();
        void destroyJupiter();

        void update();

    };


}

#endif //JUPITER_JUPITER_H
