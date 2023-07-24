#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {(void)copy;} //make

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& copy) {(void)copy; return *this;} //make

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
	std::map<std::string, double> data;
	try {
		makeData(data, btc);
		makeCompare(data, input);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		input.close();
		btc.close();
		return ;
	}
}

void BitcoinExchange::makeData(std::map<std::string, double>& data, std::ifstream& btc)
{
	std::string buffer;
	std::string date;
	double	price;
	if (!std::getline(btc, buffer))
		throw EmptyFile();
	while (std::getline(btc, buffer))
	{
		getInfo(buffer, date, price);
		data.insert(std::make_pair(date, price));
	}
}

void BitcoinExchange::getInfo(std::string buffer, std::string& date, double& price)
{
	int pos = buffer.find(',');
	date = buffer.substr(0, pos);
	price = strtod((buffer.substr(pos + 1)).c_str(), NULL);
}

void BitcoinExchange::makeCompare(std::map<std::string, double>& data, std::ifstream& input)
{
	std::string buffer;
	if (!std::getline(input, buffer))
		throw EmptyFile();
	while (std::getline(input, buffer))
	{
		try{
			int pos = buffer.find(' ');
			std::string key = buffer.substr(0, pos);
			//use find to find date
			// if the date doesnt exist make a loop and do string compare to find closest date... see if that works
		}
		catch (std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
}


BitcoinExchange::EmptyFile::EmptyFile() {}

const char* BitcoinExchange::EmptyFile::what() const throw() {
	return ("Error: File is empty");
}
