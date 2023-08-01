#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {(void)copy;}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& copy) {(void)copy; return *this;}

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
	{
		try {
			getInfo(buffer, date, price);
			data.insert(std::make_pair(date, price));
		}
		catch (std::exception& e){}
	}
	while (std::getline(btc, buffer))
	{
		getInfo(buffer, date, price);
		data.insert(std::make_pair(date, price));
	}
}

void BitcoinExchange::getInfo(std::string buffer, std::string& date, double& price)
{
	if (buffer.find_first_not_of("0123456789,-. ") != std::string::npos)
		throw DataBaseError();
	int pos = buffer.find(',');
	date = buffer.substr(0, pos);
	price = strtod((buffer.substr(pos + 1)).c_str(), NULL);
}

void BitcoinExchange::makeCompare(std::map<std::string, double>& data, std::ifstream& input)
{
	std::string buffer;
	if (!std::getline(input, buffer))
		throw EmptyFile();
	if (buffer != "date | value"){
		try {
			searchData(data, buffer);
		}
		catch (std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
	while (std::getline(input, buffer))
	{
		try{
			searchData(data, buffer);
		}
		catch (std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
}

void	BitcoinExchange::searchData(std::map<std::string, double>& data, std::string buffer)
{
	std::string key = parseDate(buffer);
	int pos = buffer.rfind(' ');
	double value = strtod((buffer.substr(pos)).c_str(), NULL);
	if (value < 0 || value > 1000)
		throw ValueOutOfRange();
	std::map<std::string, double>::iterator it = data.find(key);
	if (it != data.end())
		std::cout << key << " => " << value << " = " << (value * it->second) << std::endl;
	else
	{
		it = data.lower_bound(key);
		if (it != data.end())
			std::cout << it->first << " => " << value << " = " << (value * it->second) << std::endl;
		else
		{
			--it;
			std::cout << it->first << " => " << value << " = " << (value * it->second) << std::endl;
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

BitcoinExchange::DataBaseError::DataBaseError() {}

const char* BitcoinExchange::DataBaseError::what() const throw() {
	return ("Error: btc database has invalid data");
}