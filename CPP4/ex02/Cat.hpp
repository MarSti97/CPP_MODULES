#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private : 
		Brain* CatBrain;
    public :
        Cat();
        Cat(const Cat& copy);
        ~Cat();

        Cat& operator = (const Cat& copy);

		void	makeSound() const;
		void	haveIdea(std::string newIdea) const;
		void	thinking() const;
};

#endif