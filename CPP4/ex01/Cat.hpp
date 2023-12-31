#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private : 
		Brain* CatBrain;
    public :
        Cat();
        Cat(const Cat& copy);
        virtual ~Cat();

        Cat& operator = (const Cat& copy);

		void	makeSound() const;
		void	haveIdea(std::string newIdea) const;
		void	thinking() const;
};

#endif