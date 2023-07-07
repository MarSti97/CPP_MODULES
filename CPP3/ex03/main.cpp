#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap Random;
	std::cout << std::endl;
    DiamondTrap Mario("Mario");
    DiamondTrap Luigi("Luigi");
	std::cout << std::endl;
	Mario.whoAmI();
	Luigi.whoAmI();
	std::cout << std::endl;
	Luigi.attack(Mario.getName());
	Mario.takeDamage(Luigi.getAttack());
	std::cout << std::endl;
	Mario.highFivesGuys();
	Luigi.guardGate();
	std::cout << std::endl;

}