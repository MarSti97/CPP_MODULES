#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else 
    {
        for (int i = 2; i <= ac; i++)
        {
            int c = -1;
            while (av[i - 1][++c])
            {
                char r = toupper(av[i - 1][c]);
                std::cout << r;           
            }
        }
        std::cout << std::endl;
    }
    return (0);
}