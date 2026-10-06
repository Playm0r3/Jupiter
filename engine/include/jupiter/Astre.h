//
// Created by Warren on 03/10/2026.
//

#ifndef JUPITER_ASTRE_H
#define JUPITER_ASTRE_H

#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>

#include "components/Component.h"
#include "utils/ComponentUtilities.h"
#include "utils/Array.h"

namespace jupiter::engine
{

    using namespace utils;

    class Astre
    {

    private:

        std::string name;
        Jrray<Component*> components{};

    public:

        Astre() {};
        virtual ~Astre();

        virtual void onStart() {};
        virtual void onEnd() {};

        virtual void onSpawn() {};
        virtual void onDestroy() {};

        virtual void onEnable() {};
        virtual void onDisable() {};

        template<typename T> T* createComponent()
        {
            static_assert(std::is_base_of_v<Component, T>, "[Jupiter] Doit etre enfant de Component !");

            for (int i = 0 ; i < components.getSize(); i++)
               if (dynamic_cast<T*>(components[i]) != nullptr)
                   return nullptr;

            T* component = new T();
            components.put(component);
            return component;
        }

        template<typename T> void addComponent(T* component)
        {
            if (component == nullptr) return;

            for (int i = 0 ; i < components.getSize(); i++)
                if (components[i]->name == component->name)
                    return;

            components.put(component);
        }

        template<typename T> T* getComponent()
        {
            for (int i = 0 ; i < components.getSize(); i++)
            {
                if (T* component = dynamic_cast<T*>(components[i]))
                    return component;
            }

            return nullptr;
        }

        template<typename T> T* getComponent(int index)
        {
            if (index < 0 || index >= static_cast<int>(components.getSize()))
                return nullptr;

            T* component = dynamic_cast<T*>(components[index]);
            return component;
        }

        [[nodiscard]] Component* getComponent(const int& index);

    };

}

#endif //JUPITER_ASTRE_H
