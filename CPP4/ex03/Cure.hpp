#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure(std::string const & type);
		Cure(const Cure& copy);
		~Cure();
		
		Cure& operator = (const Cure& copy);

		// std::string const&	getType() const;
		Cure*				clone() const;
		void				use(ICharacter& target);
};

#endif