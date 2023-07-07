#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& copy)
{
	this->type = copy.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator = (const Dog& copy)
{
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "\"Woof Woof\"!" << std::endl;
}