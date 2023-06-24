#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string newName, Weapon &newWeapon) : weapon(newWeapon), name(newName)
{
    std::cout << "HumanA created: " << name << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA destroyed: " << name << std::endl;
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}