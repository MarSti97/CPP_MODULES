#include "Character.hpp"

Character::Character()
{
	std::cout << "default Character constructor called." << std::endl;
}

Character::Character(std::name newName) : name(newName)
{
	std::cout << "Character " << getName() << " constructor called." << std::endl;
}

Character::Character(const Character& copy)
{
	this->name = copy.name;
	for (int i = 0; i < 4; i++){
		this->inventory[i] = copy.inventory[i];
	}
	std::cout << "Character copy constructor called." << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called." << std::endl;
}

Character& Character::operator = (const Character& copy)
{
	if (this != &copy){
		this->name = copy.name;
		for (int i = 0; i < 4; i++)
			this->inventory[i] = copy.inventory[i];
	}
}

std::string const& Character::getName() const
{
	if (this->name != "")
		return (this->name);
	return ("No Name");
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while(this->inventory[i].exist())
		i++;
	this->inventory[i] = m;
	std::cout << "Equiped " << getType() << " in index " << i << std::endl;
}

void Character::unequip(int idx)
{
	this->inventory[idx] = AMateria();
	// probably will need a function or place to store all the dropped things
	std::cout << "Unequiped " << getType() << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	this->inventory[idx].use(target);
}