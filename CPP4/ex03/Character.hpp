#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"

class Character
{
	private :
		std::string name;
		AMateria inventory[4];
	public:
		Character();
		Character(std::string newName);
		Character(const Character& copy);
		~Character();

		Character& operator = (const Character& copy);

		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, Character& target);
};

#endif