#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap Steve("Steve");
    ScavTrap Carl("Carl");
    ScavTrap noName;

	std::cout << std::endl;
    noName.attack(Carl.getName());
    Carl.takeDamage(noName.getAttack());

	std::cout << std::endl;
    noName.attack(Steve.getName());
    Steve.takeDamage(noName.getAttack());
	Carl.guardCheck();
	Carl.guardGate();

	std::cout << std::endl;
	noName = Carl;
	noName.beRepaired(20);

	std::cout << std::endl;
	noName.guardCheck();
	Steve.attack(noName.getName());
	noName.takeDamage(Steve.getAttack());
	std::cout << std::endl;
}