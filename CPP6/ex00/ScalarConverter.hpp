#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <climits>

class ScalarConverter
{
	private : 
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ~ScalarConverter();
        ScalarConverter& operator = (const ScalarConverter& copy);
    public :
        static void    		convert(std::string literal);
		static std::string	getliteral(const char* type);
		static void			char_print(std::string input);
		static void			int_print(std::string input);
		static void			float_print(std::string input);
		static void			double_print(std::string input);
		static std::string	beautify(std::string str);
};



#endif