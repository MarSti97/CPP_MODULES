#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
	CatBrain = new Brain();
}

Cat::Cat(const Cat& copy)
{
	CatBrain = new Brain(*(copy.CatBrain));
	this->type = copy.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete CatBrain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& copy)
{
	if (this != &copy){
		delete CatBrain;
		CatBrain = new Brain(*(copy.CatBrain));
		this->type = copy.type;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "\"Meow Meow!\"" << std::endl;
}

void	Cat::haveIdea(std::string newIdea) const
{
	this->CatBrain->addIdea(newIdea);
}

void	Cat::thinking() const
{
	this->CatBrain->showIdeas();
}
