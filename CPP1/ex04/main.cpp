#include <iostream>
#include <string>
#include <cstdio>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        FILE* infile = std::fopen(av[1], "r");
        if (infile == NULL)
        {
            std::perror("Error: file can't be opened");
            std::fclose(infile);
            return (1);
        }
        std::string filename = av[1] + ".replace"
        FILE* outfile = std::fopen(filename, "w");
        if (outfile == NULL)
        {
            std::perror("Error: could not create a new file");
            std::fclose(outfile);
            return (1);
        }
        std::string buffer;
        while (true)
        {
            getline(file, buffer);
            char *ptr = buffer.find(av[2])
            while (ptr != std::string::npos)
            {
                buffer.
                buffer.search();

            }
        }
        
    }
}