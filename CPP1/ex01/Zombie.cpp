#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Zombie created." << std::endl;
    return ;
}


Zombie::~Zombie(void)
{
        std::cout << name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
        std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::giveName(std::string newName)
{
	name = newName;
}