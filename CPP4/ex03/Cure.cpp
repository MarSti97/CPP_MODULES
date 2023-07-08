#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
	std::cout << "Cure type (" << getType() << ") constructor called." << std::endl;
}

Cure::Cure(const Cure& copy)
{
	this->type = copy.type; // not sure if this kind of copy is enough yet... new?
	std::cout << "Cure copy constructor called." << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called." << std::endl;
}

Cure& Cure::operator = (const Cure& copy)
{
	if (this != &copy)
		const_cast<std::sting &> (this->type) = copy.type;
	return *this;
}

// std::string const& Cure::getType() const
// {
// 	return this->type;
// }

Cure* Cure::clone() const
{
	Cure clone = Cure(); // need to see if Cure has anything that can change or be updated... new?
	std::cout << "Cure Clone created" << std::endl;
	return clone;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target << "’s wounds *" << std::endl;
}