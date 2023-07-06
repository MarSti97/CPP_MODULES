#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap Steve("Steve");
    ScavTrap Carl("Carl");
    ClapTrap noName;

    Steve.attack("Carl");
    Carl.takeDamage(Steve.getAttack());
    noName.attack("Steve");
    Steve.takeDamage(noName.getAttack());
	noName = Steve;
	noName.beRepaired(20);
}