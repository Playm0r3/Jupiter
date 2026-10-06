//
// Created by Warren on 06/10/2026.
//

#include "Jupiter.h"

namespace jupiter
{
    inline void Jupiter::initJupiter()
    {
        window = new Window();
        window->createWindow(1080, 720, "Jupiter");
    }

    inline void Jupiter::destroyJupiter()
    {
        window->destroyWindow();
    }

    inline void Jupiter::update()
    {
    }
}