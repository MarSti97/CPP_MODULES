#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>

template<typename T>
int easyfind(T container, int i)
{

}

class NotFound : public std::exception
{
    public :
        NotFound() {}
        virtual const char* what() const throw(){
            return ("Int was not found");
        }
}

#endif