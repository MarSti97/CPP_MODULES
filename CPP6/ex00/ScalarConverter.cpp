#include "ScalarConverter.hpp" 

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& copy)
{
	(void)copy;
	return *this;
}

void    ScalarConverter::convert(std::string literal)
{
	std::string type = getliteral(literal.c_str());
	
	if (type == "Error")
		std::cerr << "Error: invalid input" << std::endl;
	else if (type == "char")
		char_print(literal);
	else if (type == "int")
		int_print(literal);
	else if (type == "float")
		float_print(literal);
	else if (type == "double")
		double_print(literal);
}

std::string ScalarConverter::getliteral(const char* type)
{
    int flag = 0;
    int neg = 0;
    int i = 0;
    std::string temp = (std::string)type;

	if (temp == "-inf" || temp == "+inf" || temp == "inf" || temp == "nan")
		return ("double");
	if (temp == "-inff" || temp == "+inff" || temp == "inff" || temp == "nanf")
		return ("float");
	if (type[i] == '+')
		i++;
    if (temp.size() == 1 && temp.find_first_not_of("0123456789") != std::string::npos)
        return ("char");
    while (type[i])
    {
        if (type[i] == '-')
            neg++;
        else if (type[i] == '.')
            flag++;
        else if (!std::isdigit(type[i]))
            break ;
        i++;
    }
    if (type[i] == 'f' && !type[i + 1] && flag == 1 && neg < 2)
        return ("float");
    if (!type[i] && flag == 1 && neg < 2)
        return ("double");
    if (!type[i] && !flag && neg < 2)
        return ("int");
    return ("Error");
}

void	ScalarConverter::char_print(std::string input)
{
	char c = input[0];

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int> (c) << std::endl;
	std::cout << "float: " << static_cast<float> (c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double> (c) << ".0" << std::endl;
}

void	ScalarConverter::int_print(std::string input)
{
	int res = atoi(input.c_str());
	char c = static_cast<char>(res);
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << res << std::endl;
	std::cout << "float: " << static_cast<float> (res) << beautify(input) << "f" << std::endl;
	std::cout << "double: " << static_cast<double> (res) << beautify(input) << std::endl;
}

void	ScalarConverter::float_print(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "inff" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << (input.substr(0, input.size() - 1)) << std::endl;
	}
	else
	{
		float res = atof(input.c_str());
		char c = static_cast<char>(res);
		if (std::isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int> (res) << std::endl;
		std::cout << "float: " << res << beautify(input) << "f" << std::endl;
		std::cout << "double: " << static_cast<double> (res) << beautify(input) << std::endl;
	}
}

void	ScalarConverter::double_print(std::string input)
{
	if (input == "-inf" || input == "+inf" || input == "inf" || input == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
	}
	else
	{
		double res;
		std::istringstream(input) >> res;
		char c = static_cast<char>(res);
		if (std::isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int> (res) << std::endl;
		std::cout << "float: " << static_cast<float> (res) << beautify(input) << "f" << std::endl;
		std::cout << "double: " << res << beautify(input) << std::endl;
	}
}

std::string ScalarConverter::beautify(std::string input)
{
	float val = atof(input.c_str());
	std::stringstream sub;
	sub << val;
	std::string check = sub.str();
	if (check.find_first_of("e") != std::string::npos)
		return ("");
	size_t pos = input.find('.');
	if (pos == std::string::npos)
		return (".0");
	std::string temp = input.substr(pos);
	if (temp.find_first_of("123456789") == std::string::npos)
		return (".0");
	return ("");
}
