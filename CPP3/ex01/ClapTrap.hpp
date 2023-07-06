#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define MAX_HITS 100

class ClapTrap
{
	protected :
		std::string name;
		int Hit;
		int Energy;
		int Attack;
	
	public :
		ClapTrap();
		ClapTrap(std::string newName);
		ClapTrap(const ClapTrap& copy);
		~ClapTrap();

		ClapTrap& operator = (const ClapTrap& copy);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		std::string	getName();
		int		getAttack();
};

#endif