#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <sstream>

class ScalarConverter
{
    public :
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ~ScalarConverter();

        ScalarConverter& operator = (const ScalarConverter& copy);

        void    convert(std::string literal);
};

std::string	getliteral(const char* type);
void		char_print(std::string input);
void		int_print(std::string input);
void		float_print(std::string input);
void		double_print(std::string input);
std::string	beautify(std::string str);


#endif