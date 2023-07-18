#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>

class ScalarConverter
{
    private :
        std::string input;
    public :
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ~ScalarConverter();

        ScalarConverter& operator = (const ScalarConverter& copy);

        void    convert(std::string literal);
}

#endif