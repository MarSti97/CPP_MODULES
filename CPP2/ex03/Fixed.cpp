#include "Fixed.hpp"

/* ******************* Constructors and Destructors ******************* */

Fixed::Fixed(){
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed){
    std::cout << "Copy constructor called" << std::endl;
    value = fixed.getRawBits();
}

Fixed::Fixed(const int nbr){
    value = (nbr << _bits);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float flt){
	// Uncomment this to see the bit representation!
	// float number = flt;
    // std::bitset<sizeof(float) * 8> bits(*reinterpret_cast<unsigned int*>(&number));
    // std::cout << "Bit representation of float" << number << ": " << bits << std::endl;
    value = (int)roundf(flt * (1 << _bits));
    std::cout << "Float constructor called" << std::endl;
	// std::bitset<sizeof(int) * 8> bit(value);
    // std::cout << "Bit representation of conversion" << value << ": " << bit << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

/* ******************* Operator assignments ******************* */

bool Fixed::operator > (const Fixed &fixed) const{
	if (this->value > fixed.value)
		return (true);
	return (false);
}

bool Fixed::operator >= (const Fixed &fixed){
	if (this->value >= fixed.value)
		return (true);
	return (false);
}

bool Fixed::operator <= (const Fixed &fixed){
	if (this->value <= fixed.value)
		return (true);
	return (false);
}

bool Fixed::operator < (const Fixed &fixed) const{
	if (this->value < fixed.value)
		return (true);
	return (false);
}

bool Fixed::operator == (const Fixed &fixed){
	if (this->value == fixed.value)
		return (true);
	return (false);
}

bool Fixed::operator != (const Fixed &fixed){
	if (this->value != fixed.value)
		return (true);
	return (false);
}

Fixed& Fixed::operator = (const Fixed &fixed){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        value = fixed.getRawBits();
    return *this;
}

Fixed Fixed::operator + (const Fixed &fixed) const{
	// return Fixed(this->value + fixed.value);
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator - (const Fixed &fixed) const{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator * (const Fixed &fixed) const{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator / (const Fixed &fixed) const{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator ++ (){
    this->value++;
    return *this;
}

Fixed Fixed::operator ++ (int){
    Fixed saved(*this);
    this->value++;
    return saved;
}

Fixed Fixed::operator -- (){
    this->value--;
    return *this;
}

Fixed Fixed::operator -- (int){
    Fixed saved(*this);
    this->value--;
    return saved;
}

std::ostream& operator << (std::ostream& out, const Fixed &fixed){
    out << fixed.toFloat();
    return out;
}

/* ******************* Member functions ******************* */

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return(value);
}

void Fixed::setRawBits(int const raw){
    this->value = raw;
}

int Fixed::toInt(void) const{
    return ((int)roundf((float)value / (1 << _bits)));
}

float Fixed::toFloat(void) const{
    return ((float)value / (1 << _bits));
}

Fixed& Fixed::min(Fixed &one, Fixed &other){
    return (one < other ? one : other);
}

const Fixed& Fixed::min(const Fixed &one, const Fixed &other){
    return ((one < other) ? one : other);
}

Fixed& Fixed::max(Fixed &one, Fixed &other){
    return (one > other ? one : other);
}

const Fixed& Fixed::max(const Fixed &one, const Fixed &other){
    return ((one > other) ? one : other);
}