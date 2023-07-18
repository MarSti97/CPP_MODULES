#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() // make and run more tests at school, will probably need the random number gen.
{
	Bureaucrat jim;
	Bureaucrat sheldon("Sheldon", 1);
	AForm* home =  new ShrubberyCreationForm("home");
	AForm* cat =  new RobotomyRequestForm("My Cat");
	AForm* lenin =  new PresidentialPardonForm("Lenin");

	try
	{
		jim = Bureaucrat("Jim", 25);
		home->execute(jim);
		// f1.beSigned(jim);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << *home << std::endl;
	jim.executeForm(*home);
	home->beSigned(jim);
	cat->beSigned(jim);
	lenin->beSigned(jim);
	jim.executeForm(*home);
	jim.executeForm(*cat);
	sheldon.executeForm(*lenin);
	delete home;
	return 0;
}