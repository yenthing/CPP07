#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 100
int main(int, char**)
{
    std::cout << "----Testing Empty array----\n";
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;
    try
    {
        empty[1] = 42;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\n----Testing Empty Int Array----\n";
    Array<int> *emptyInt = new Array<int>();
    std::cout << "EmptyInt size: " << emptyInt->size() << std::endl;
    Array<int> *emptyInt2 = new Array<int>(*emptyInt);
    *emptyInt = *emptyInt2;

    delete emptyInt;
    delete emptyInt2;

    std::cout << "\n----Testing Array of 3 elements----\n";
    Array<int> three(3);
    std::cout << "Three size: " << three.size() << std::endl;
    for (unsigned int i = 0; i < three.size(); i++)
    {
        three[i] = i;
        std::cout << "Three[" << i << "] = " << three[i] << std::endl;
    }
    try
    {
        three[3] = 42;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n----Testing From Subject----\n";
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    delete [] mirror;
    return 0;
}
