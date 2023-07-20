#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template <typename C>
class Array
{
    private :
        C arr[];
    public :
        Array() : arr() {}
        Array(unsigned int n) : arr[n]() {}
        Array(const Array& copy);
        ~Array();

        Array& operator = (const Array& copy);

        unsigned int size();
}