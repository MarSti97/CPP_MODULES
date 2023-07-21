#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

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

template <typename T>
class Array
{
    private :
        T*              arr;
        unsigned int    _size;
    public :
        Array() : _size(0) {arr = new T[_size];}
        Array(unsigned int n) : _size(n) {arr = new T[_size];}
        Array(const Array& copy) : _size(copy._size) 
        {
            arr = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                arr[i] = copy.arr[i];
        }
        ~Array() {delete[] arr;}

        Array& operator = (const Array& copy)
        {
            if (this != *copy){
                delete[] arr;
                this->_size = copy._size;
                this->arr = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    this->arr[i] = copy.arr[i];
            }
        }

        T& operator [] (int i) const
        {
            if (i < 0 || (unsigned int)i >= this->_size)
                throw OutOfRange();
            return this->arr[i];
        }

        unsigned int    size() {return this->_size;}
        void            print() {
            ::iter<T, T(T)> (arr, _size, ::print<T>);
            std::cout << std::endl;
        }

        class OutOfRange : public std::exception
        {
            public :
                OutOfRange() {}
                virtual const char* what() const throw() {
                    return ("Index is out of range!");
                }
        };
};


#endif