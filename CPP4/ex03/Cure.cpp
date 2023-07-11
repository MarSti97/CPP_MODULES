#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
	std::cout << "Cure type (" << getType() << ") constructor called." << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria(copy.getType())
{
	std::cout << "Cure copy constructor called." << std::endl;
}

Cure::~Cure()
{
	// delete this;
	std::cout << "Cure destructor called." << std::endl;
}

Cure& Cure::operator = (const Cure& copy)
{
	(void)copy;
	return *this;
}

// std::string const& Cure::getType() const
// {
// 	return this->type;
// }

Cure* Cure::clone() const
{
	Cure* clone =  new Cure();
	std::cout << "Cure Clone created" << std::endl;
	return clone;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}