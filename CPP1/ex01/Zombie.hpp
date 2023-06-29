#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private :
        std::string name;
    public :
        Zombie(void);
        ~Zombie(void);

        void	announce(void);
		void	giveName(std::string newName);
};

Zombie*	zombieHorde(int N, std::string name);

#endif