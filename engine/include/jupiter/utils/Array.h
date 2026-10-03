//
// Created by Warren on 03/10/2026.
//

#ifndef JUPITER_ARRAY_H
#define JUPITER_ARRAY_H

namespace jupiter::engine
{

    template <typename T>
    class Array
    {

    private:

        T elements[];

    public:

        Array(int size);

        void add(T element);
        void remove(T element);

        T operator[](int index) { return elements[index]; }
    };

    template <typename T>
    Array<T>::Array(int size)
    {
        elements = new T[size];
    }

    template <typename T>
    void Array<T>::add(T element)
    {
        
    }

    template <typename T>
    void Array<T>::remove(T element)
    {
    }
}

#endif //JUPITER_ARRAY_H
