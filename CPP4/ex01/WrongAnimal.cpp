#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string newType) : type(newType)
{
    std::cout << "WrongAnimal " << this->getType() << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	this->type = copy.type;
    std::cout << "WrongAnimal " << this->getType() << " copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& copy)
{
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	if (type != "")
		return this->type;
	return "Random WrongAnimal";
}

void WrongAnimal::makeSound() const
{
	std::cout << this->getType() << " makes a generic Wronganimal sound. \"YEEEEEET\"!" << std::endl;
}
