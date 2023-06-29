#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstring>

int main(int ac, char **av)
{
    if (ac == 4)
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
        std::ofstream outfile(filename.c_str());
        if (outfile == NULL)
        {
            std::perror("Error: could not create a new file");
            outfile.close();
            return (1);
        }
        std::string buffer;
		std::getline(infile, buffer);
        while (1)
        {
            size_t pos = buffer.find(av[2]);
            while ((std::string)av[2] != "" && pos != std::string::npos)
            {
                buffer.erase(pos, strlen(av[2]));
                buffer.insert(pos, av[3]);
                pos = buffer.find(av[2], pos + strlen(av[3]));
            }
            outfile << buffer;
			if (!std::getline(infile, buffer))
				break ;
			outfile << std::endl;
        }
        infile.close();
        outfile.close();
    }
	else
    	std::cout << "Wrong number of arguments" << std::endl;
    return (0);
}