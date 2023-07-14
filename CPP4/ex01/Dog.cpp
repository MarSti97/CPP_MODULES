#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
	DogBrain = new Brain();
}

Dog::Dog(const Dog& copy)
{
	this->DogBrain = new Brain (*(copy.DogBrain));
	this->type = copy.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete DogBrain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator = (const Dog& copy)
{
	if (this != &copy){
		delete DogBrain;
		DogBrain = new Brain(*(copy.DogBrain));
		this->type = copy.type;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "\"Woof Woof!\"" << std::endl;
}

void	Dog::haveIdea(std::string newIdea) const
{
	this->DogBrain->addIdea(newIdea);
}

void	Dog::thinking() const
{
	this->DogBrain->showIdeas();
}