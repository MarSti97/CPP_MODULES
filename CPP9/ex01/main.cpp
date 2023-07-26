#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac == 2)
	{
		try {
			std::deque<int> seq = makeDeck(av[1]);
			calculate(seq);
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error: invaid number of arguements: RPN needs to be one continuous string" << std::endl;
	return 0;
}