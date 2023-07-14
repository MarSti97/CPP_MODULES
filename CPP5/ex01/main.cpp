#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat jim("Jim", 25);
	Form f1;

	try
	{
		Form f2("F2", 100, 100);
		Form f3("F3", 1, 1);
		f1 = Form("F1", 151, 1);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << f1 << std::endl;
	return 0;
}