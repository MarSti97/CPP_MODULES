#include "Zombie.hpp"

int main()
{
    Zombie new_zombie1;
    new_zombie1.announce();
    Zombie* new_zombie2 = newZombie("Brian");
    new_zombie2->announce();
    randomChump("Random");
    // new_zombie2->~Zombie();
    delete new_zombie2;
}