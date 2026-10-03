//
// Created by Warren on 03/10/2026.
//

#ifndef JUPITER_SCENE_H
#define JUPITER_SCENE_H

#include <filesystem>
#include <mutex>

#include "Astre.h"

namespace jupiter::engine
{

    // les 3 derniers éléments sert à encoder la version de l'engine
    constexpr uint8_t scene_hash[10] = {'J', 'P', 'T', 'R', 0x89, 0x1A, 0x0D, 0x01, 0x00, 0x00};

    class Scene
    {
    public:

        Scene();
        virtual ~Scene() = default;

        void saveAs(std::filesystem::path const& path);

        void load();
        void save();

    private:

        std::mutex fileMutex;
        std::filesystem::path path;

        std::vector<Astre*> astres;

        void loadAsync();
        void saveAsync();

    };
}

#endif //JUPITER_SCENE_H
