#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria type (" << getType() << ") constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	const_cast<std::string &> (this->_type) = copy._type; // do i need... ?
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called." << std::endl;
}

AMateria& AMateria::operator = (const AMateria& copy)
{
	if (this != &copy)
		const_cast<std::string &> (this->_type) = copy._type; // do i need... ?
	return *this;
}

std::string const& AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "No idea what the implomentation of this is" << std::endl;
}

// bool	AMateria::exist()
// {
// 	if (this->getType().empty())
// 	{
// 		std::cerr << "HERE??" << std::endl;
// 		return true;
// 	}
// 	return false;
// }