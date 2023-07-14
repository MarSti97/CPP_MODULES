#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

extern AMateria* dropped[100];

class MateriaSource : public IMateriaSource
{
	private: 
		AMateria* learnt[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		virtual ~MateriaSource();

		MateriaSource& operator = (const MateriaSource& copy);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
		void		showLearnt();
		void		clearLearnt();
};

void	addDropped(AMateria* item);
void	clearDropped();
void	show_dropped();

#endif