#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Zombie default created." << std::endl;
    return ;
}

Zombie::Zombie(std::string new_name)
{
    name = new_name;
    std::cout << name << " : Zombie created." << std::endl;
}

Zombie::~Zombie(void)
{
    if (name == "")
        std::cout << "Zombie destroyed" << std::endl;
    else
        std::cout << name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
    if (name == "")
        std::cout << "Zombie" << " : BraiiiiiiinnnzzzZ..." << std::endl;
    else
        std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}