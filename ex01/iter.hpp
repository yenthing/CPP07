#pragma once

#include <iostream>

template < typename T, typename Y >
void iter(T *array, size_t len, void (*f)(Y))
{
    if (!array || !f)
        return ;
    for (size_t i = 0; i < len; i++)
        f(array[i]);
}


