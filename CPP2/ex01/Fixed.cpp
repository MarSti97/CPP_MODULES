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

Fixed::Fixed(const int nbr)
{
    value = (nbr << _bits);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float flt)
{
	// Uncomment this to see the bit representation!
	// float number = flt;
    // std::bitset<sizeof(float) * 8> bits(*reinterpret_cast<unsigned int*>(&number));
    // std::cout << "Bit representation of float" << number << ": " << bits << std::endl;
    value = (int)roundf(flt * (1 << _bits));
    std::cout << "Float constructor called" << std::endl;
	// std::bitset<sizeof(int) * 8> bit(value);
    // std::cout << "Bit representation of conversion" << value << ": " << bit << std::endl;
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

int Fixed::toInt(void) const
{
    return ((int)roundf((float)value / (1 << _bits)));
}

float Fixed::toFloat(void) const
{
    return ((float)value / (1 << _bits));
}

std::ostream& operator << (std::ostream& out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}