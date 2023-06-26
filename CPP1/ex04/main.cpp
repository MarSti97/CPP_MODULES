#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::ifstream infile(av[1]);
        if (infile == NULL)
        {
            std::perror("Error: file can't be opened");
            infile.close();
            return (1);
        }
        std::string filename(av[1]);
        filename += ".replace";
        std::ofstream outfile(filename);
        if (outfile == NULL)
        {
            std::perror("Error: could not create a new file");
            outfile.close();
            return (1);
        }
        std::string buffer;
        while (std::getline(infile, buffer))
        {
            size_t pos = buffer.find(av[2]);
            while (pos != std::string::npos)
            {
                buffer.erase(pos, strlen(av[2]));
                buffer.insert(pos, av[3]);
                pos = buffer.find(av[2]);
            }
            outfile << buffer << std::endl;
        }
        infile.close();
        outfile.close();
    }
    std::cout << "Wrong number of arguments" << std::endl;
    return (0);
}