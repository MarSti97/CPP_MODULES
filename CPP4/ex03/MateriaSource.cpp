#include "MateriaSource.hpp"

AMateria* dropped[100];

MateriaSource::MateriaSource()
{	
	for (int i = 0; i < 4; i++)
		this->learnt[i] = NULL;
	// std::cout << "default MateriaSource constructor called." << std::endl;
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
	// std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource::~MateriaSource()
{
	this->clearLearnt();
	// std::cout << "MateriaSource destructor called." << std::endl;
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
	if (i == 4){
		delete data;
		std::cout << "Learning slots are full" << std::endl;
		return ;
	}
	this->learnt[i] = data->clone();
	delete data;
	std::cout << this->learnt[i]->getType() << " added to learnt MateriaSource." << std::endl;
	this->showLearnt();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (i < 4 && this->learnt[i])
	{
		if (this->learnt[i]->getType() == type)
		{
			std::cout << "Creating Materia...  " << this->learnt[i]->getType() << std::endl;
			return this->learnt[i]->clone();
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
	for (int i = 0; i < 4; i++)
	{
		if (this->learnt[i] != NULL)
		{
			delete this->learnt[i];
			this->learnt[i] = NULL;
		}
	}
	// std::cout << "Learnt cleared" << std::endl;
}

void	addDropped(AMateria* item)
{
	int i = 0;
	if (!dropped[0]){
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
		delete dropped[i++];
	}
}