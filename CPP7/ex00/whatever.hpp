#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename S>
void    swap(S& a, S& b)
{
    S temp = a;
    a = b;
    b = temp;
}

template <typename M>
M   min(M a, M b)
{
    return (a >= b ? b : a);
}

template <typename M>
M   max(M a, M b)
{
    return (a <= b ? b : a);
}

#endif