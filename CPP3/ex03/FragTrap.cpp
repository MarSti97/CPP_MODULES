#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30)
{
    std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string newName) : ClapTrap(newName, 100, 100, 30)
{
    std::cout << "FragTrap " << getName() << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
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
    std::cout << "FragTrap " << getName() << " copy assignment operator called" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (this->Hit != 0)
		std::cout << "Can I get a Hiiiiiigh Fiiiiive?" << std::endl;
	else
		std::cout << "Dead FragTraps can't ask for High Fives..." << std::endl;
}