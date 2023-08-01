#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
	private :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		BitcoinExchange& operator = (const BitcoinExchange& copy);
	public :
		static void			exchangeRates(char* file);
		static void			makeData(std::map<std::string, double>& data, std::ifstream& btc);
		static void			getInfo(std::string buffer, std::string& date, double& price);
		static void			makeCompare(std::map<std::string, double>& data, std::ifstream& input);
		static std::string	parseDate(std::string key);
		static void			findClosest(std::map<std::string, double>& data, std::string key, double value);
		static void			searchData(std::map<std::string, double>& data, std::string buffer);

	class EmptyFile : public std::exception
	{
		public :
			EmptyFile();
			virtual const char* what() const throw();
	};

	class ValueOutOfRange : public std::exception
	{
		public :
			ValueOutOfRange();
			virtual const char* what() const throw();
	};

	class InvalidInput : public std::exception
	{
		public :
			InvalidInput();
			virtual const char* what() const throw();
	};

	class InvalidDate : public std::exception
	{
		public :
			InvalidDate();
			virtual const char* what() const throw();
	};

	class DataBaseError : public std::exception
	{
		public :
			DataBaseError();
			virtual const char* what() const throw();
	};
};

#endif