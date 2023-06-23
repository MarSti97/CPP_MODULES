#include "Weapon.hpp"

Weapon::Weapon(void)
{
	std::cout << "Weapon created" << std::endl;
}

Weapon::Weapon(std::string weaponName)
{
	type = weaponName;
	std::cout << type << " created" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon destroyed" << std::endl;
}

std::string Weapon::getType(void)
{
	return (Weapon::type);
}

void Weapon::setType(std::string New)
{
	type = New;
}