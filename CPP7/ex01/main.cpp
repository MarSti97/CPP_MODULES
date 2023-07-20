#include "iter.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::string lst[] = {"who", "what", "where", "when", "why"};

    std::cout << "----- Int Array -----" << std::endl;
    ::iter<int, int(int)>(arr, 5, ::print<int>);
    std::cout << std::endl;
    ::iter(arr, 5, square);
    ::iter<int, int(int)>(arr, 5, ::print<int>);
    std::cout << std::endl;
    std::cout << "----- String Array -----" << std::endl;
    ::iter<std::string, std::string(std::string)>(lst, 5, ::print<std::string>);
    std::cout << std::endl;
    ::iter(lst, 5, question);
    ::iter<std::string, std::string(std::string)>(lst, 5, ::print<std::string>);
    std::cout << std::endl;
    return 0;
}

int square(int nbr)
{
    return (nbr * nbr);
}

std::string question(std::string word)
{
    return (word + "?");
}