//
// Created by Warren on 06/10/2026.
//

#ifndef JUPITER_ARRAY_H
#define JUPITER_ARRAY_H
#include <cstdint>

namespace jupiter::engine::utils
{

    template<typename T>
    class Jrray
    {

    private:

        std::size_t size = 0;
        std::size_t allocated = 0;
        T* list = nullptr;

    public:

        explicit Jrray(std::size_t capacity = 10)
            : allocated(capacity), list(new T[capacity]()) {}

        ~Jrray()
        {
            if (list == nullptr) return;

            delete[] list;
            list = nullptr;
        }

        Jrray(const Jrray&) = delete;
        Jrray& operator=(const Jrray&) = delete;

        void put(T element)
        {
            if (size == allocated)
                resize(allocated == 0 ? 1 : allocated * 2);

            list[size++] = element;
        }

        bool remove(const T& element)
        {
            for (std::size_t i = 0; i < size; i++)
            {
                if (list[i] == element)
                {
                    std::memmove(list + i, list + i + 1, (size - i - 1) * sizeof(T));
                    list[--size] = T{};
                    return true;
                }
            }
            return false;
        }

        // supprime des données si la nouvelle taille est inférieure
        void resize(std::size_t newCapacity)
        {
            T* newList = new T[newCapacity]();
            std::size_t kept = std::min(size, newCapacity);
            if (kept > 0) std::memcpy(newList, list, kept * sizeof(T));

            delete[] list;
            list = newList;
            allocated = newCapacity;
            size = kept;
        }

        [[nodiscard]] std::size_t getSize() const { return size; }

        T operator[](std::size_t index) const
        {
            if (index >= size) throw std::out_of_range("[Jupiter] Index hors borne !");
            return list[index];
        }

        T* begin() { return list; }
        T* end() { return list + size; }
        const T* begin() const { return list; }
        const T* end() const { return list + size; }

    };

}

#endif //JUPITER_ARRAY_H
