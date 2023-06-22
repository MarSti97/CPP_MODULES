#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}

Zombie::Zombie(std::string new_name)
{
    name = new_name;
}

Zombie::~Zombie(void)
{
    if (name == "")
        std::cout << "Zombie" << "destroyed"
    else
        std::cout << name << "destroyed"
}

Zombie::announce(void)
{
    if (name == "")
        std::cout << "Zombie" << " : BraiiiiiiinnnzzzZ..."
    else
        std::cout << name << " : BraiiiiiiinnnzzzZ..."
}