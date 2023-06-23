#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private :
		std::string type;
	public :
		std::string &getType(void) const;
		void setType(std::string New);
		Weapon();
		Weapon(std::string typeName);
		~Weapon();
};

#endif