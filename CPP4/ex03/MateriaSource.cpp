#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "default MateriaSource constructor called." << std::endl;
}

MateriaSource::MateriaSource(std::name newName) : name(newName)
{
	std::cout << "MateriaSource " << getName() << " constructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy) //fix
{
	this->name = copy.name;
	for (int i = 0; i < 4; i++){
		this->inventory[i] = copy.inventory[i];
	}
	std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called." << std::endl;
}

MateriaSource& MateriaSource::operator = (const MateriaSource& copy) //fix
{
	if (this != &copy){
		this->name = copy.name;
		for (int i = 0; i < 4; i++)
			this->inventory[i] = copy.inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	
}