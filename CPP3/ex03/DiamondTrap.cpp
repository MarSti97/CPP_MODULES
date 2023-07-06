#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap()
{
	// this->name = ClapTrap::name;
    this->Hit = FragTrap::Hit;
    this->Attack = FragTrap::Attack;
    this->Energy = ScavTrap::getEnergy();
	std::cout << "THIS SHIT: " << ScavTrap::getEnergy() << std::endl;
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string newName) : ClapTrap(newName)
{
	this->name = ClapTrap::name;
    this->Hit = FragTrap::Hit;
    this->Energy = ScavTrap::Energy;
    this->Attack = FragTrap::Attack;
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
	std::cout << "Fix this function!\n" << std::endl;
	std::cout << "Attribute Hit " << this->Hit << std::endl;
	std::cout << "Attribute Energy " << this->Energy << std::endl;
	std::cout << "Attribute Attack " << this->Attack << std::endl;
}