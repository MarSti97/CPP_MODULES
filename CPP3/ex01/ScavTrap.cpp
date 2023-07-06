#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->guardMode = 0;
    this->Hit = 100;
    this->Energy = 50;
    this->Attack = 20;
    std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName)
{
    this->guardMode = 0;
    this->Hit = 100;
    this->Energy = 50;
    this->Attack = 20;
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
    this->guadMode = this->guardMode > 0 ? 0 : 1;
    if (this->guadMode == 1)
        std::cout << "ScavTrap " << getName() << " gate keeper mode Activated." << std::endl;
    else
        std::cout << "ScavTrap " << getName() << " gate keeper mode Deactivated." << std::endl;
}

void ScavTrap::guardCheck()
{
    if (this->guadMode == 1)
        std::cout << "ScavTrap " << getName() << " gate keeper mode is active." << std::endl;
    else
        std::cout << "ScavTrap " << getName() << " gate keeper mode is not active." << std::endl;
}