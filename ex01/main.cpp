#include "iter.hpp"

template < typename T >
void print(T & x)
{
    std::cout << x << std::endl;
}

template < typename T >
void print_str(std::string const & x)
{
    std::cout << x << std::endl;
}

template < typename T >
void print_ptr(T const * x)
{
    std::cout << *x << std::endl;
}

int main()
{
    int int_array[] = {1, 2, 3, 4, 5};
    std::string str_array[] = {"one", "two", "three", "four", "five"};
    char char_array[] = {'a', 'b', 'c', 'd', 'e'};

    int int_len = sizeof(int_array) / sizeof(int_array[0]);
    int str_len = sizeof(str_array) / sizeof(str_array[0]);

    std::cout << "Printing int_array:" << std::endl;
    iter(int_array, int_len, print<int>);

    std::cout << "\nPrinting char_array:" << std::endl;
    iter(char_array, int_len, print<char>);

    std::cout << "\nPrinting str_array:" << std::endl;
    iter(str_array, str_len, print<std::string>);

    std::cout << "\nPrinting str_array with print_str:" << std::endl;
    iter(str_array, str_len, print_str<std::string>);
    return 0;
}
