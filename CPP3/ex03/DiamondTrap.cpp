#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap("", 100, 50, 30)
{
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string newName) : ClapTrap(newName + "_clap_name", 100, 50, 30)
{
    this->name = newName;
    std::cout << "DiamondTrap " << getName() << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy)
{
    std::cout << "DiamondTrap " << getName() << " copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << getName() << " destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& copy)
{
    this->name = copy.name;
	this->Hit = copy.Hit;
	this->Energy = copy.Energy;
	this->Attack = copy.Attack;
    std::cout << "DiamondTrap " << getName() << " copy assignment operator called" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is " << this->name << " and ClapTrap name is " << this->ClapTrap::name << std::endl;
}

std::string DiamondTrap::getName()
{
	if (this->name != "")
		return this->name;
	else
		return "He Who Has No Name";
}