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
	if (copy.name != "")
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
	if (target.Hit <= 0)
	{
		std::cout << target.name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap ";
	if (this->name != "")
		std::cout << this->name;
	else
		std::cout << "He Who Has No Name";
	std::cout << " attacks " << target.name << ", causing " << this->Attack << " points of damage!" << std::endl;
	target.takeDamage(this->Attack);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->Hit -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hit < 10)
		this->Hit += amount;
	if (this->Hit > 10)
		this->Hit = 10;
}