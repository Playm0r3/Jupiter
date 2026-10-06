//
// Created by Warren on 06/10/2026.
//

#include "jupiter/Astre.h"
#include "jupiter/components/Transform.h"

#include "jmath/vectors/Vector.h"

#include "soleil.h"
#include "jupiter/Window.h"

#include <d3d12.h>
#include<SDL3/SDL.h>
#include <iostream>

using namespace jupiter;
using namespace jupiter::engine;
using namespace jupiter::math;

int main(int argc, char** argv)
{
    std::cout << "Debut du Test" << std::endl;

    Window* window = new Window();
    window->createWindow(1080, 720, "Hello Jupiter");


    Astre* astre = new Astre();

    Transform* transform = astre->createComponent<Transform>();
    transform->position = Vector3{0.0f, 0.0f, 0.0f};
    transform->rotation = Vector3{0.0f, 0.0f, 0.0f};
    transform->scale = Vector3{1.0f, 1.0f, 1.0f};

    astre->addComponent(transform);

    Transform* t = astre->getComponent<Transform>();

    bool isRunning = true;

    while (isRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT) isRunning = false;
        }

        // update

    }

    delete astre;

    std::cout << "Fin du Test" << std::endl;
    return 0;
}