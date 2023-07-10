#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(std::string newName);
		MateriaSource(const MateriaSource& copy);
		~MateriaSource();

		MateriaSource& operator = (const MateriaSource& copy);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif