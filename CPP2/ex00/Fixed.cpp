#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    bits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(cosnt Fixed& fixed)
{
    value = fixed.value;
    bit = fixed.bit;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}