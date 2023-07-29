#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac > 1)
	{
		std::list<int> lst;
		std::vector<int> vec;
		std::vector<int> temp;
		try {
			clock_t start = clock();
			fillList(lst, av);
			sortList(lst);
			clock_t end = clock();
			fillVector(temp, av);
			std::cout << "Before: ";
			::print(temp);
			std::cout << "After: ";
			::print(lst);
			
			std::cout << "Time to process a range of " 
			<< lst.size() << " elements with std::list : " 
			<< static_cast<double>(end - start) / CLOCKS_PER_SEC
			<< " second(s)" << std::endl;
			
			start = clock();
			fillVector(vec, av);
			sortVector(vec);
			end = clock();

			std::cout << "Time to process a range of "
			<< vec.size() << " elements with std::vector : "
			<< static_cast<double>(end - start) / CLOCKS_PER_SEC
			<< " second(s)" << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error: invalid number of arguments" << std::endl;
	return 0;
}

