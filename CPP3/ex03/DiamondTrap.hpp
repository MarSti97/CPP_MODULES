#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :  public virtual FragTrap, public virtual ScavTrap
{
	private :
		std::string name;
	public :
		DiamondTrap();
		DiamondTrap(std::string newName);
		DiamondTrap(const DiamondTrap& copy);
		~DiamondTrap();

		DiamondTrap& operator = (const DiamondTrap& copy);

		void whoAmI();
};

#endif