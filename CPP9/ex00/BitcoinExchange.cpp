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
			std::string key = parseDate(buffer);
			int pos = buffer.rfind(' ');
			double value = strtod((buffer.substr(pos)).c_str(), NULL);
			if (value < 0 || value > 1000)
				throw ValueOutOfRange();
			std::map<std::string, double>::iterator it = data.find(key);
			if (it != data.end())
				std::cout << key << " => " << value << " = " << (value * it->second) << std::endl;
			else
				findClosest(data, key, value);
			// if the date doesnt exist make a loop and do string compare to find closest date... see if that works
		}
		catch (std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
}

std::string BitcoinExchange::parseDate(std::string buffer)
{
	if (buffer.find_first_not_of("0123456789.-| ") != std::string::npos)
		throw InvalidInput();
	if (!std::isdigit(buffer[0]) || !std::isdigit(buffer[1]) || !std::isdigit(buffer[2]) || !std::isdigit(buffer[3]) || buffer[4] != '-')
		throw InvalidInput();
	int month = atoi((buffer.substr(5, 6)).c_str());
	if (buffer[7] != '-' || month < 1 || month > 12)
		throw InvalidDate();
	int day = atoi((buffer.substr(8, 9)).c_str());
	if (buffer[10] != ' ' || day < 1 || day > 31)
		throw InvalidDate();
	if (buffer[11] != '|' || buffer[12] != ' ')
		throw InvalidInput();
	int pos = buffer.find(' ');
	return (buffer.substr(0, pos));
}

void BitcoinExchange::findClosest(std::map<std::string, double>& data, std::string key, double value)
{
	std::map<std::string, double>::iterator it = data.begin();
	std::map<std::string, double>::iterator best;
	size_t min = it->first.compare(key);
	size_t comp;
	for (++it; it != data.end(); ++it)
	{
		comp = it->first.compare(key);
		if (comp < min) {
			min = comp;
			best = it;
		}
	}
	std::cout << it.first() << " => " << value << " = " << (value * it->second) << std::endl;
}


BitcoinExchange::EmptyFile::EmptyFile() {}

const char* BitcoinExchange::EmptyFile::what() const throw() {
	return ("Error: File is empty");
}

BitcoinExchange::ValueOutOfRange::ValueOutOfRange() {}

const char* BitcoinExchange::ValueOutOfRange::what() const throw() {
	return ("Error: this value is not in the range of 0 to 1000");
}

BitcoinExchange::InvalidInput::InvalidInput() {}

const char* BitcoinExchange::InvalidInput::what() const throw() {
	return ("Error: invalid input or format error");
}

BitcoinExchange::InvalidDate::InvalidDate() {}

const char* BitcoinExchange::InvalidDate::what() const throw() {
	return ("Error: invalid date or format error");
}