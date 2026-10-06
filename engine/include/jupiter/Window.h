//
// Created by Warren on 06/10/2026.
//

#ifndef JUPITER_WINDOW_H
#define JUPITER_WINDOW_H

#include <SDL3/SDL.h>

namespace jupiter
{

    class Window
    {

    public:

        Window();
        ~Window();

        void createWindow(int width, int height, const char* title);
        void destroyWindow();

        void* getWindowHandle();

    private:

        SDL_Window* window = nullptr;
        SDL_PropertiesID windowProperties{};

    };

}

#endif //JUPITER_WINDOW_H
