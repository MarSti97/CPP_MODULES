#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename P>
P    print(P do_it)
{
    std::cout << do_it << " ";
    return (do_it);
}

template <typename I, typename F>
void    iter(I* arr, int len, F func)
{
    for (int i = 0; i < len; i++)
        arr[i] = func(arr[i]);
}


int         square(int nbr);
std::string question(std::string word);

#endif