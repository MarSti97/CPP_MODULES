#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
    protected :
        std::string type;
    public :
        AAnimal();
        AAnimal(std::string newType);
        AAnimal(const AAnimal& copy);
        virtual ~AAnimal();

        AAnimal& operator = (const AAnimal& copy);

        virtual void    makeSound() const = 0;
        virtual void    haveIdea(std::string newIdea) const;
        virtual void    thinking() const;
		std::string		getType() const;
};

#endif
