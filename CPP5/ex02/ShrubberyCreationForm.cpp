#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Generic Form", 145, 137), target("*undefined*")
{
	std::cout << "Shrub default constructor" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget) : AForm("Form_" + newTarget, 145, 137), target(newTarget)
{
	std::cout << "Shrub constructor" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm("Form_" + copy.target, 145, 137), target(copy.target)
{
	std::cout << "Shrub copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrub destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& copy)
{
	if (this != &copy)
		this->target = copy.target;
	std::cout << "Shrub copy operator call" << std::endl;
	return *this;
}

std::string const	ShrubberyCreationForm::targetName() const
{
	return	this->target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSign())
		throw AForm::NotSignedForm();
	else if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowToExec();
	else
	{
		std::string filename = this->targetName() + "_shrubbery";
        std::ofstream outfile(filename.c_str());
		if (outfile == NULL)
        {
            std::perror("Error: could not create a new file");
            outfile.close();
            return ;
        }
		outfile << "\n              ,@@@@@@@, " << std::endl;
		outfile << "      ,,,.   ,@@@@@@/@@,  .oo8888o. " << std::endl;
		outfile << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o " << std::endl;
		outfile << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' " << std::endl;
		outfile << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' " << std::endl;
		outfile << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' " << std::endl;
		outfile << "  `&%\\ ` /%&'    |.|        \\ '|8' " << std::endl;
		outfile << "      |o|        | |         | | " << std::endl;
		outfile << "      |.|        | |         | | " << std::endl;
		outfile << "    \\/ ._\\//_/__/  ,\\_//__\\_/.  \\_//__/_ " << std::endl;
		outfile.close();
	}
}
