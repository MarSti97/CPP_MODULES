#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type)
{
	std::cout << "Ice type (" << getType() << ") constructor called." << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy.getType())
{
	std::cout << "Ice copy constructor called." << std::endl;
}

Ice::~Ice()
{
	// delete this;
	std::cout << "Ice destructor called." << std::endl;
}

Ice& Ice::operator = (const Ice& copy)
{
	(void)copy;
	return *this;
}

// std::string const& Ice::getType() const
// {
// 	return this->type;
// }

Ice* Ice::clone() const
{
	Ice* clone = new Ice(); // need to see if ice has anything that can change or be updated... new?
	std::cout << "Ice Clone created" << std::endl;
	return clone;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}