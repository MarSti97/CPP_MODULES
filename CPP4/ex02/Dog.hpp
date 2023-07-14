#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private : 
		Brain* DogBrain;
    public :
        Dog();
        Dog(const Dog& copy);
        virtual ~Dog();

        Dog& operator = (const Dog& copy);

		void	makeSound() const;
		void	haveIdea(std::string newIdea) const;
		void	thinking() const;
};

#endif