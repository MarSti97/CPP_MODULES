#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private :
		Weapon &weapon;
		std::string name;
	public :
		void attack();
		HumanA();
		HumanA(std::string newName, Weapon &newWeapon);
		~HumanA();
};

#endif