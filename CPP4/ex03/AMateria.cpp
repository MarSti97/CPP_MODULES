#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria type (" << getType() << ") constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	this->type = copy.type;
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called." << std::endl;
}

AMateria& AMateria::operator = (const AMateria& copy)
{
	if (this != &copy)
		const_cast<std::sting &> (this->type) = copy.type; // do i need... ?
	return *this;
}

std::string const& AMateria::getType() const
{
	return this->type;
}

AMateria* AMateria::clone() const
{
	std::cout << "Pure Virtual Function of the Abstract Class" << std::endl;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "No idea hat the implomentation of this is" << std::endl;
}

bool	AMateria::exist()
{
	if (this->type != "")
		return true;
	return false;
}