#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac > 1)
	{
		std::list<int> cont1;
		std::vector<int> cont2;
		try {
			fillList(cont1, av);
			fillVector(cont2, cont1);
			::print(cont1);
			double timeList = sortList(cont1);
			// ::print(cont1);
			// double timeVector = sortVector(cont2);
			std::cout << "Time to process a range of " << cont1.size() << " elements with std::list : " << timeList << std::endl;
			// std::cout << "Time to process a range of " << cont2.size() << "elements with std::vector : " << timeVector << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error: invalid number of arguments" << std::endl;
	return 0;
}