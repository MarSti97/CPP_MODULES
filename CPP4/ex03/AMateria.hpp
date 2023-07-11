#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected :
		const std::string _type;
	public :
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& copy);
		virtual ~AMateria();
		
		AMateria& operator = (const AMateria& copy);

		std::string const &	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
		// virtual bool		exist();
};

#endif