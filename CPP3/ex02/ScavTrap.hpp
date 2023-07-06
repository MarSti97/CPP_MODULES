#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private :
		int guardMode;
	public :
		ScavTrap();
		ScavTrap(std::string newName);
		ScavTrap(const ScavTrap& copy);
		~ScavTrap();

		ScavTrap& operator = (const ScavTrap& copy);

		void	attack(const std::string& target);
		void	guardGate();
		void	guardCheck();
};

#endif