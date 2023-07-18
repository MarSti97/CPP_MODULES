#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	std::cout << "-------- My tests --------" << std::endl;
	{
		Intern me;
		std::cout << std::endl;
		Bureaucrat boss("Clark", 3);
		std::cout << boss << std::endl;
		std::cout << std::endl;
		AForm* shrub = me.makeForm("shrubbery creation", "Trees");
		std::cout << *shrub << std::endl;
		std::cout << std::endl;
		AForm* pardon = me.makeForm("presidential pardon", "Vader");
		std::cout << *pardon << std::endl;
		std::cout << std::endl;
		shrub->beSigned(boss);
		boss.executeForm(*shrub);
		boss.executeForm(*pardon);
		pardon->beSigned(boss);
		boss.executeForm(*pardon);
		delete shrub;
		delete pardon;
	}
	return 0;
}