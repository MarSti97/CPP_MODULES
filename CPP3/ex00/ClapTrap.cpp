#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	Hit = 10;
	Energy = 10;
	Attack = 0;
	std::cout << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string newName) : name(newName)
{
	Hit = 10;
	Energy = 10;
	Attack = 0;
	std::cout << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	this->name = copy.name;
	Hit = copy.Hit;
	Energy = copy.Energy;
	Attack = copy.Attack;
	std::cout << "copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->Energy == 0)
	{
		if (this->name != "")
			std::cout << this->name << " is out of energy, cannot attack." << std::endl;
		else
			std::cout << "He Who Has No Name is out of energy, cannot attack." << std::endl;
		return ;
	}
	std::cout << "ClapTrap ";
	if (this->name != "")
		std::cout << this->name << " tries to attack " << target << std::endl;
	else 
		std::cout << "He Who Has No Name tries to attack " << target << std::endl;
	this->Energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hit < 1)
	{
		if (this->name != "")
			std::cout << this->name << " is already dead!" << std::endl;
		else 
			std::cout << "He Who Has No Name is already dead!" << std::endl;
		return ;
	}
	this->Hit -= amount;
	std::cout << "ClapTrap ";
	if (this->name != "")
		std::cout << this->name << " took a hit, now has " << this->Hit << " hit points left." << std::endl;
	else
		std::cout << "He Who Had No Name took a hit, now has " << this->Hit << " hit points left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hit < 10)
		this->Hit += amount;
	if (this->Hit > 10)
		this->Hit = 10;
	this->Energy--;
	std::cout << "ClayTrap ";
	if (this->name != "")
		std::cout << this->name << " got repaired, it now has " << this->Hit << " hit points." << std::endl;
	else
		std::cout << "He Who Has No Name got repaired, it now has " << this->Hit << " hit points." << std::endl;
}