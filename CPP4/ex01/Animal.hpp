#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    protected :
        std::string type;
    public :
        Animal();
        Animal(std::string newType);
        Animal(const Animal& copy);
        virtual ~Animal();

        Animal& operator = (const Animal& copy);

        virtual void    makeSound() const;
        virtual void    haveIdea(std::string newIdea) const;
        virtual void    thinking() const;
		std::string		getType() const;
};

#endif
