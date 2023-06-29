#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    value = fixed.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        value = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}