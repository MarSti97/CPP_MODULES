#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public :
		FragTrap();
		FragTrap(std::string newName);
		FragTrap(const FragTrap& copy);
		~FragTrap();

		FragTrap& operator = (const FragTrap& copy);

		void	highFivesGuys(void);
};

#endif