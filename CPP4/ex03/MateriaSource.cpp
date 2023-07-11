#include "MateriaSource.hpp"

AMateria** dropped = NULL;

MateriaSource::MateriaSource()
{	
	for (int i = 0; i < 4; i++)
		this->learnt[i] = NULL;
	std::cout << "default MateriaSource constructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	int i = 0;
	this->clearLearnt();
	while(i < 4 && copy.learnt[i])
	{
		this->learnt[i] = copy.learnt[i]->clone();
		i++;
	}
	std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource::~MateriaSource()
{
	this->clearLearnt();
	std::cout << "MateriaSource destructor called." << std::endl;
}

MateriaSource& MateriaSource::operator = (const MateriaSource& copy)
{
	if (this != &copy){
		this->clearLearnt();
		int i = 0;
		while(i < 4 && copy.learnt[i])
		{
			this->learnt[i] = copy.learnt[i]->clone();
			i++;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* data)
{
	int i = 0;
	while (i < 4 && this->learnt[i])
			i++;
	this->learnt[i] = data->clone();
	delete data;
	std::cout << this->learnt[i]->getType() << " added to learnt MateriaSource." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (i < 4 && this->learnt[i])
	{
		if (this->learnt[i]->getType() == type)
		{
			return this->learnt[i]->clone();
			std::cout << "Materia created : " << this->learnt[i]->getType() << std::endl;
		}
		i++;
	}
	return 0;
}

void MateriaSource::showLearnt()
{
	int i = 0;
	std::cout << "Current learnt Materia" << std::endl;
	while (i < 4 && this->learnt[i])
	{
		std::cout << (i + 1) << ". " << this->learnt[i]->getType() << std::endl;
		i++;
	}
	if (i == 0)
		std::cout << "No Materia has been learnt." << std::endl;
}

void MateriaSource::clearLearnt()
{
	int i = 0;
	while(i < 4 && this->learnt[i])
		delete this->learnt[i++];
	std::cout << "Learnt cleared" << std::endl;
}

void	addDropped(AMateria* item)
{
	int i = 0;

	if (dropped == NULL){
		dropped[0] = item;
		dropped[1] = NULL;
	}
	else {
		while (dropped[i])
			i++;
		dropped[i] = item;
		dropped[i + 1] = NULL;
	}
}

void	clearDropped()
{
	int i = 0;
	while (dropped[i]){
		// delete dropped[i++];
		std::cout << dropped[i++]->getType() << " THIS" << std::endl;
	}
}
