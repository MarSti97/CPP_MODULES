#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap Carl("Carl");
    FragTrap Anatoli("Anatoli");

	std::cout << std::endl;
	for (int i = 0; i < 5; i++){
    	Carl.attack(Anatoli.getName());
    	Anatoli.takeDamage(Carl.getAttack());
	}
	std::cout << std::endl;
	Anatoli.highFivesGuys();
	Anatoli.beRepaired(1);
	Anatoli.highFivesGuys();

	std::cout << std::endl;
	FragTrap BetterTolii = Anatoli;
	BetterTolii.attack(Anatoli.getName());
	Anatoli.takeDamage(BetterTolii.getAttack());
}