#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20)
{
    this->guardMode = 0;
    std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName, 100, 50, 20)
{
    this->guardMode = 0;
    std::cout << "ScavTrap " << getName() << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    this->guardMode = copy.guardMode;
    std::cout << "ScavTrap " << getName() << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& copy)
{
    this->name = copy.name;
	this->Hit = copy.Hit;
	this->Energy = copy.Energy;
	this->Attack = copy.Attack;
    this->guardMode = copy.guardMode;
    std::cout << "ScavTrap " << getName() << " copy assignment operator called" << std::endl;
    return *this;
}

void ScavTrap::guardGate()
{
    this->guardMode = this->guardMode > 0 ? 0 : 1;
    if (this->guardMode == 1)
        std::cout << "ScavTrap " << getName() << " gate keeper mode Activated." << std::endl;
    else
        std::cout << "ScavTrap " << getName() << " gate keeper mode Deactivated." << std::endl;
}

void ScavTrap::guardCheck()
{
    if (this->guardMode == 1)
        std::cout << "ScavTrap " << getName() << " gate keeper mode is active." << std::endl;
    else
        std::cout << "ScavTrap " << getName() << " gate keeper mode is not active." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->Energy == 0)
	{
		std::cout << this->getName() << " is out of energy, cannot attack." << std::endl;
		return ;
	}
	this->Energy--;
	std::cout << "ScavTrap " << this->getName() << " tries to attack " << target << std::endl;
	std::cout << "Energy has decreased to " << this->Energy << std::endl;
}

int ScavTrap::getEnergy(){
	return this->Energy;
}