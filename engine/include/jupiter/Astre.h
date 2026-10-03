//
// Created by Warren on 03/10/2026.
//

#ifndef JUPITER_ASTRE_H
#define JUPITER_ASTRE_H

#include <vector>
#include <stdexcept>
#include <iostream>

#include "components/Component.h"

namespace jupiter::engine
{

    class Astre
    {

    private:

        std::vector<Component*> components;
        std::string name;

    public:

        Astre();
        virtual ~Astre();

        virtual void onStart();
        virtual void onEnd();

        virtual void onSpawn();
        virtual void onDestroy();

        virtual void onEnable();
        virtual void onDisable();

        template<typename T> T* addComponent()
        {
            T* component = new T();

            for (Component* & i : components)
                if (i->name == component->name)
                    return nullptr;

            components.push_back(component);
            return component;
        }

        template<typename T> T* addComponent(T* component)
        {
            if (component == nullptr) return nullptr;

            for (Component* & i : components)
                if (i->name == component->name)
                    return nullptr;

            components.push_back(component);
            return static_cast<T*>(component);
        }

        template<typename T> T* getComponent()
        {
            for (Component* c : components)
            {
                T* component = static_cast<T*>(c);
                if (component == nullptr) continue;
                return component;
            }

            return nullptr;
        }

        template<typename T> T* getComponent(int index)
        {
            if (index < 0 || index >= static_cast<int>(components.size()))
                return nullptr;

            return static_cast<T*>(components[index]);
        }

        [[nodiscard]] Component* getComponent(const int& index) const;

    };

}

#endif //JUPITER_ASTRE_H
