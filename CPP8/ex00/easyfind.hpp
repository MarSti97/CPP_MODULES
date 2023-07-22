#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    it = std::find(container.begin(), container.end(), i);
    if (it != container.end())
        return *it;
    throw NotFound();
}

template<typename T>
void    print(T container)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " - ";
    std::cout << std::endl;
}


#endif