//
// Created by Warren on 03/10/2026.
//

#include "jupiter/Scene.h"

#include <fstream>

namespace jupiter::engine
{
    void Scene::saveAs(std::filesystem::path const& p)
    {
        this->path = p;
        save();
    }

    void Scene::save()
    {
        std::thread saveThread{&Scene::saveAsync, this};
    }

    void Scene::loadAsync()
    {
    }

    void Scene::saveAsync()
    {
        fileMutex.lock();

        std::ofstream file = std::ofstream{path, std::ios::out, std::ios::binary};
        file.open(path);

        char* payload = new char[10];
        memcpy(payload, scene_hash, 10);

        file.write(payload, sizeof(scene_hash));

        delete[] payload;

        file.close();
        fileMutex.unlock();
    }


}
