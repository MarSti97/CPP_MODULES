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

ClapTrap& ClapTrap::operator = (const ClapTrap& copy)
{
	this->name = copy.name;
	this->Hit = copy.Hit;
	this->Energy = copy.Energy;
	this->Attack = copy.Attack;
	std::cout << "copy assignment operator called" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->Energy == 0)
	{
		std::cout << this->getName() << " is out of energy, cannot attack." << std::endl;
		return ;
	}
	this->Energy--;
	std::cout << "ClapTrap " << this->getName() << " tries to attack " << target << std::endl;
	std::cout << "Energy has decreased to " << this->Energy << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hit < 1)
	{
		std::cout << this->getName() << " is already dead!" << std::endl;
		return ;
	}
	this->Hit -= amount;
	std::cout << "ClapTrap " << this->getName() << " took a hit, now has " << this->Hit << " hit points left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hit < MAX_HITS)
		this->Hit += amount;
	if (this->Hit > MAX_HITS)
		this->Hit = MAX_HITS;
	this->Energy--;
	std::cout << "ClayTrap " << this->getName() << " got repaired, now has " << this->Hit << " hit points." << std::endl;
	std::cout << "Energy has decreased to " << this->Energy << std::endl;
}

std::string ClapTrap::getName()
{
	if (this->name != "")
		return this->name;
	else
		return "He Who Has No Name";
}

int	ClapTrap::getAttack()
{
	return this->Attack;
}