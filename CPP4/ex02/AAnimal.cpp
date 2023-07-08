#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string newType) : type(newType)
{
    std::cout << "AAnimal " << this->getType() << " constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	this->type = copy.type;
    std::cout << "AAnimal " << this->getType() << " copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal& AAnimal::operator = (const AAnimal& copy)
{
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

std::string AAnimal::getType() const
{
	if (type != "")
		return this->type;
	return "Random AAnimal";
}

void AAnimal::makeSound() const
{
	std::cout << this->getType() << " makes a generic Aanimal sound. \"YEEEEEET\"!" << std::endl;
}

void	AAnimal::haveIdea(std::string newIdea) const
{
	std::cout << "AAnimal has no brain... how can think about " << newIdea << "." << std::endl;
}

void	AAnimal::thinking() const
{
	std::cout << "AAnimal has no brain... sooooo no ideas either" << std::endl;
}