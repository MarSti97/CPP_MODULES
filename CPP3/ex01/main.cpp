#include "ClapTrap.hpp"

int main()
{
    ClapTrap Steve("Steve");
    ClapTrap Carl("Carl");
    ClapTrap noName;

    Steve.attack("Carl");
    Carl.takeDamage(Steve.getAttack());
    noName.attack("Steve");
    Steve.takeDamage(noName.getAttack());
	noName = Steve;
	noName.beRepaired(20);
}