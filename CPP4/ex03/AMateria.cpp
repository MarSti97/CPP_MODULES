#include "AMateria.hpp"

AMateria::AMateria() : _type("<default>")
{
	// std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "AMateria type (" << getType() << ") constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& copy) : _type(copy.getType())
{
	// const_cast<std::string &> (this->_type) = copy._type; // do i need... ?
	// std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called." << std::endl;
}

AMateria& AMateria::operator = (const AMateria& copy)
{
	if (this != &copy)
		const_cast<std::string &> (this->_type) = copy._type;
	return *this;
}

std::string const& AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "Can't be used here" << std::endl;
}