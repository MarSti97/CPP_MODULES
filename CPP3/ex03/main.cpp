#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap Mario("Mario");
    DiamondTrap Luigi("Luigi");
	std::cout << std::endl;
	Mario.whoAmI();
	Luigi.whoAmI();
	std::cout << std::endl;
	Luigi.attack("Mario");
	Mario.takeDamage(Luigi.getAttack());
	std::cout << std::endl;
	Mario.highFivesGuys();
	Luigi.guardGate();
	std::cout << std::endl;


    // FragTrap Anatoli("Anatoli");

	// for (int i = 0; i < 5; i++){
    // 	Carl.attack(Anatoli.getName());
    // 	Anatoli.takeDamage(Carl.getAttack());
	// }
	// std::cout << std::endl;
	// Anatoli.highFivesGuys();
	// Anatoli.beRepaired(1);
	// Anatoli.highFivesGuys();

	// std::cout << std::endl;
	// FragTrap BetterTolii = Anatoli;
	// BetterTolii.attack(Anatoli.getName());
	// Anatoli.takeDamage(BetterTolii.getAttack());
}