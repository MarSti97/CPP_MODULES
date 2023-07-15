#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Generic Form", 145, 137), target("*undefined*")
{
	std::cout << "Shrub default constructer" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget) : AForm("Form_" + newTarget, 145, 137), target(newTarget)
{
	std::cout << "Shrub constructer" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm("Form_" + copy.target, 145, 137), target(copy.target)
{
	std::cout << "Shrub copy constructer" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrub destructer" << std::endl;
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
        std::ofstream file(this->targetName() + "_shrubbery");
		if (file == NULL)
        {
            std::perror("Error: could not create a new file");
            file.close();
            return ;
        }
		file << "\n              ,@@@@@@@, " << std::endl;
		file << "      ,,,.   ,@@@@@@/@@,  .oo8888o. " << std::endl;
		file << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o " << std::endl;
		file << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' " << std::endl;
		file << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' " << std::endl;
		file << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' " << std::endl;
		file << "  `&%\\ ` /%&'    |.|        \\ '|8' " << std::endl;
		file << "      |o|        | |         | | " << std::endl;
		file << "      |.|        | |         | | " << std::endl;
		file << "    \\/ ._\\//_/__/  ,\\_//__\\_/.  \\_//__/_ " << std::endl;
		file.close();
	}
}
