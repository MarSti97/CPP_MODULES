#include "Weapon.hpp"

Weapon::Weapon(std::string weaponName)
{
	type = weaponName;
	std::cout << "Weapon created: " << type << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon destroyed: " << type << std::endl;
}

const std::string& Weapon::getType(void)
{
	return (Weapon::type);
}

void Weapon::setType(std::string newWeapon)
{
	type = newWeapon;
}