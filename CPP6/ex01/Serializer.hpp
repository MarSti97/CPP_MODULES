#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdint>
#include "data.hpp"

class Serializer
{
    public :
        Serializer();
        Serializer(const Serializer& copy);
        ~Serializer();

        Serializer& operator = (const Serializer& copy);

        uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);
};

#endif