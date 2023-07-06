#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->guardMode = 0;
    this->Hit = 100;
    this->Energy = 50;
    this->Attack = 20;
    std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string newName) : ClapTrap(newName)
{
    this->guardMode = 0;
    this->Hit = 100;
    this->Energy = 50;
    this->Attack = 20;
    std::cout << "FragTrap " << getName() << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    this->guardMode = copy.guardMode;
    std::cout << "FragTrap " << getName() << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " destructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& copy)
{
    this->name = copy.name;
	this->Hit = copy.Hit;
	this->Energy = copy.Energy;
	this->Attack = copy.Attack;
    this->guardMode = copy.guardMode;
    std::cout << "FragTrap " << getName() << " copy assignment operator called" << std::endl;
    return *this;
}

void FragTrap::