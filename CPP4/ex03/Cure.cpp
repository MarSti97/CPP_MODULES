#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria(copy.getType())
{
	// std::cout << "Cure copy constructor called." << std::endl;
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called." << std::endl;
}

Cure& Cure::operator = (const Cure& copy)
{
	(void)copy;
	return *this;
}

Cure* Cure::clone() const
{
	Cure* clone =  new Cure();
	// std::cout << "Cure Clone created" << std::endl;
	return clone;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}