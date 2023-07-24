#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>

// struct Datum {
// 	int year;
// 	int month;
// 	int day;
// };

class BitcoinExchange
{
	private :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		BitcoinExchange& operator = (const BitcoinExchange& copy);
	public :
		static void exchangeRates(char* file);
		static void makeData(std::map<std::string, double>& data, std::ifstream& btc);
		static void getInfo(std::string buffer, std::string& date, double& price);
		static void makeCompare(std::map<std::string, double>& data, std::ifstream& input);

	class EmptyFile : public std::exception
	{
		public :
			EmptyFile();
			virtual const char* what() const throw();
	};
};

// Datum 	createdatum(std::string date);
// bool	comparedatum(Datum a, Datum b);
// Datum	findclosest(std::map<Datum, double> data, Datum find);

#endif