#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
{
	this->type = copy.type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& copy)
{
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << this->getType() << " sound : \"MOOOOOOO\"???" << std::endl;
}
