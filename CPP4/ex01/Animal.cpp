#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string newType) : type(newType)
{
    std::cout << "Animal " << this->getType() << " constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	this->type = copy.type;
    std::cout << "Animal " << this->getType() << " copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator = (const Animal& copy)
{
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

std::string Animal::getType() const
{
	if (type != "")
		return this->type;
	return "Random Animal";
}

void Animal::makeSound() const
{
	std::cout << this->getType() << " makes a generic animal sound. \"YEEEEEET\"!" << std::endl;
}

void	Animal::haveIdea(std::string newIdea) const
{
	std::cout << "Animal has no brain... how can think about " << newIdea << "." << std::endl;
}

void	Animal::thinking() const
{
	std::cout << "Animal has no brain... sooooo no ideas either" << std::endl;
}