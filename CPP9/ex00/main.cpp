#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac == 2)
	{
		BitcoinExchange::exchangeRates(av[1]);
	}
	else
		std::cerr << "Error: invalid number of arguments" << std::endl;
}