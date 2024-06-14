#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        ~Array();

        Array& operator=(const Array& other);

        T& operator[](unsigned int i);
        unsigned int size() const;
};
