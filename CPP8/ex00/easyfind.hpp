#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>

class NotFound : public std::exception
{
    public :
        NotFound() {}
        virtual const char* what() const throw(){
            return ("Int was not found");
        }
};

template<typename T>
int easyfind(T container, int i)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        if (*it == i)
            return (*it);
    throw NotFound();
}


#endif