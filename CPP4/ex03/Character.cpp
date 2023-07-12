#include "Character.hpp"
#include "MateriaSource.hpp"

Character::Character() : name("<default>")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	// std::cout << "default Character constructor called." << std::endl;
}

Character::Character(std::string newName) : name(newName)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	// std::cout << "Character " << getName() << " constructor called." << std::endl;
}

Character::Character(const Character& copy) : name(copy.getName())
{
	this->clearInventory();
	int i = 0;
	while(i < 4 && copy.inventory[i])
	{
		this->inventory[i] = copy.inventory[i]->clone();
		i++;
	}
	// std::cout << "Character copy constructor called." << std::endl;
}

Character::~Character()
{
	this->clearInventory();
	// std::cout << "Character destructor called." << std::endl;
}

Character& Character::operator = (const Character& copy)
{
	if (this != &copy){
		// this->~Character();
		this->clearInventory();
		// this = new Character(copy.getName());
		const_cast<std::string &> (this->name) = copy.name;
		for (int i = 0; i < 4; i++)
		{
			if (copy.inventory[i])
				this->inventory[i] = copy.inventory[i]->clone();
			else 
				this->inventory[i] = NULL;
		}
		// this = update;
	}
	return *this;
}

std::string const& Character::getName() const
{
		return this->name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while(i < 4 && this->inventory[i])
		i++;
	if (i == 4){
		// addDropped(m);
		// std::cout << "Inventory full" << std::endl;
		return ;
	}
	this->inventory[i] = m;
	std::cout << this->getName() << " Equiped " << m->getType() << " in index " << i << std::endl;
}

void Character::unequip(int idx)
{
	if ((!this->inventory[idx]) || (idx > 3 || idx < 0)){
		// std::cout << "There is nothing to drop at this index" << std::endl;
		return ;
	}
	std::cout << "Dropped " << this->inventory[idx]->getType() << std::endl;
	addDropped(this->inventory[idx]);
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if ((!this->inventory[idx]) || (idx > 3 || idx < 0)){
		std::cout << "There is nothing to use at this index" << std::endl;
		return ;
	}
	this->inventory[idx]->use(target);
}

void Character::clearInventory()
{
	int i = 0;
	while(i < 4)
	{
		if (this->inventory[i]){
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		i++;
	}
	// std::cout << "Inventory cleared" << std::endl;
}
