#include "Harl.hpp"

int main()
{
	Harl newHarl;
	newHarl.complain("DEBUG");
	std::cout << std::endl;
	newHarl.complain("INFO");
	std::cout << std::endl;
	newHarl.complain("WARNING");
	std::cout << std::endl;
	newHarl.complain("ERROR");
	std::cout << std::endl;
	newHarl.complain("SOMETHING");
	std::cout << "Did it work?" << std::endl;
}