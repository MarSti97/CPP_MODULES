#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    protected :
        std::string type;
    public :
        WrongAnimal();
        WrongAnimal(std::string newType);
        WrongAnimal(const WrongAnimal& copy);
        virtual ~WrongAnimal();

        WrongAnimal& operator = (const WrongAnimal& copy);

        void    makeSound() const;
		std::string		getType() const;
};

#endif
