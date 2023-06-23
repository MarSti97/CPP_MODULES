#include "Zombie.hpp"

int main()
{
	int size = 2;
    Zombie* horde = zombieHorde(size, "Brian");
	for (int i = 0; i < size; i++)
		horde[i].announce();
    delete[] horde;
}