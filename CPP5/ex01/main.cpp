#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat jim; 
	Form f1;

	try
	{
		jim = Bureaucrat("Jim", 25);
		Form f2("F2", 100, 100);
		Form f3("F3", 0, 1);
		f1 = Form("F1", 151, 1);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------ More tests ------" << std::endl;
	f1 = Form("F1", 75, 75);
	f1.beSigned(jim);
	f1.beSigned(jim);
	std::cout << f1 << std::endl;
	return 0;
}