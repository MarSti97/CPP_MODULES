#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::cout << "----- Test Vector -----" << std::endl;
	std::vector<int> vec(5, 7);
	int res;
	try
	{
		res = ::easyfind(vec, 44);
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	// std::cout << "Found: " << res << std::endl;
}