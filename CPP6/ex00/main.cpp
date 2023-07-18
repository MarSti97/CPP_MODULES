// #include "ScalarConverter.hpp"
#include <iostream>
#include <string>

std::string getliteral(char* type);

int main(int ac, char** av)
{
    if (ac == 2)
    {
        std::cout << av[1] << std::endl;
        std::string literal = getliteral(av[1]);
        std::cout << literal << std::endl;
        std::cout << std::endl;
        double dub = 0.0;
        float flo = 0.0;
        std::cout << dub << std::endl;
        std::cout << flo << std::endl;
    }
    return 0;
}

std::string getliteral(char* type)
{
    int fd_flag = 0;
    int neg = 0;
    int i = 0;
    std::string temp = (std::string)type;

    //imploment nan and inf
    if (temp.size() == 1 && temp.find_first_not_of("0123456789") != std::string::npos)
        return ("char");
    while (type[i])
    {
        if (type[i] == '-')
            neg++;
        else if (type[i] == '.')
            fd_flag++;
        else if (!std::isdigit(type[i]))
            break ;
        i++;
    }
    if (type[i] == 'f' && !type[i + 1] && fd_flag == 1 && neg < 2)
        return ("float");
    if (!type[i] && fd_flag == 1 && neg < 2)
        return ("double");
    if (!type[i] && !fd_flag && neg < 2)
        return ("int");
    return ("Error");
}