#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string newName) : name(newName), weapon(NULL)
{
    std::cout << "HumanB created: " << name << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB destroyed: " << name << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    weapon = &newWeapon;
    std::cout << name << " now has a " << weapon->getType() << std::endl;
}

void HumanB::attack()
{
    if (weapon == NULL)
        std::cout << name << " attacks with their fists" << std::endl;
    else
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}