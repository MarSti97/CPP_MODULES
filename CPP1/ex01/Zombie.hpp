#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private :
        std::string name;
    public :
        void announce(void);
        Zombie(void);
        ~Zombie(void);
		void giveName(std::string newName);
};

Zombie*	zombieHorde(int N, std::string name);

#endif