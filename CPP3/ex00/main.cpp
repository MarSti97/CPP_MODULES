#include "ClapTrap.hpp"

int main()
{
    ClapTrap Steve("Steve");
    ClapTrap Carl("Carl");
    ClapTrap noName;

    Steve.attack("Carl");
    Carl.takeDamage(0);
    noName.attack("Steve");
    Steve.takeDamage(0);
    
}