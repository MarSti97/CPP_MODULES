#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

extern AMateria** dropped;

class MateriaSource : public IMateriaSource
{
	private: 
		AMateria* learnt[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		~MateriaSource();

		MateriaSource& operator = (const MateriaSource& copy);

		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);
		void				showLearnt();
		void				clearLearnt();
};

void	addDropped(AMateria* item);
void	clearDropped();

#endif