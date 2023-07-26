#include "PmergeMe.hpp"

void	fillList(std::list<int>& list, char** av)
{
	int i = 0;

	while (av[++i])
	{
		std::string str(av[i]);
		if (str.find_first_not_of("0123456789") != std::string::npos)
			throw InvalidInput();
		list.push_back(atoi(av[i]));
	}
}

void	fillVector(std::vector<int>& vec, std::list<int>& list)
{
	std::list<int>::iterator it;
	for (it = list.begin(); it != list.end(); ++it)
		vec.push_back(*it);
}


InvalidInput::InvalidInput() {}

const char* InvalidInput::what() const throw() {
	return ("Error: invalid input");
}