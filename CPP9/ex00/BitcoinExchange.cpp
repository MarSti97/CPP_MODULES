#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy); //make

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& copy); //make

void BitcoinExchange::exchangeRates(char* file)
{
	std::ifstream input(file);
	std::ifstream btc("data.csv");
	if (input == NULL || btc == NULL)
	{
		std::perror("Error: could not open file(s)");
		input.close();
		btc.close();
		return ;
	}
	
}
