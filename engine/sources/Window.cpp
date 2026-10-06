//
// Created by Warren on 06/10/2026.
//

#include "jupiter/Window.h"

namespace jupiter
{

    Window::Window()
    {

    }

    Window::~Window()
    {

    }

    void Window::createWindow(int width, int height, const char* title)
    {
        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
        windowProperties = SDL_GetWindowProperties(window);
    }

    void* Window::getWindowHandle()
    {
        return SDL_GetPointerProperty(windowProperties, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
    }

    void Window::destroyWindow()
    {
        SDL_Quit();
    }
}
