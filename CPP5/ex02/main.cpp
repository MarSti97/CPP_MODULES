#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat jim; 
	AForm* home =  new ShrubberyCreationForm("home");

	try
	{
		jim = Bureaucrat("Jim", 25);
		home->execute(jim);
		// f1.beSigned(jim);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << home << std::endl;
	jim.executeForm(*home);
	home->beSigned(jim);
	jim.executeForm(*home);
	delete home;
	return 0;
}