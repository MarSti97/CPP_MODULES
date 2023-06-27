#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl newHarl;
		std::string input(av[1]);
		newHarl.complain(input);
	}
	else
		std::cout << "Error: invalid number of arguments" << std::endl;
}