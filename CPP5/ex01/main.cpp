#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat patrick;

	try
	{
		Bureaucrat frank("Frank", 5);
		Bureaucrat steve("Steve", 1);
		patrick = Bureaucrat("Patrick", 151);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << patrick << std::endl;
	std::cout << std::endl;
	std::cout << "--------- Increment and Decrement Tests ---------" << std::endl;
	// Bureaucrat craig;
	Bureaucrat burt;
	std::cout << std::endl;
	try
	{
		// craig = Bureaucrat("Craig", 150);
		// craig.decrementGrade();
		// std::cout << craig << std::endl;
		burt = Bureaucrat("Burt", 1);
		burt.decrementGrade();
		std::cout << burt << std::endl;
		burt.incrementGrade();
		std::cout << burt << std::endl;
		burt.incrementGrade();
		std::cout << burt << std::endl;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	// std::cout << craig << std::endl;
	std::cout << burt << std::endl;
	return 0;
}