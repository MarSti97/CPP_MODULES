#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy.getType())
{
	// std::cout << "Ice copy constructor called." << std::endl;
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called." << std::endl;
}

Ice& Ice::operator = (const Ice& copy)
{
	(void)copy;
	return *this;
}

Ice* Ice::clone() const
{
	Ice* clone = new Ice();
	// std::cout << "Ice Clone created" << std::endl;
	return clone;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}