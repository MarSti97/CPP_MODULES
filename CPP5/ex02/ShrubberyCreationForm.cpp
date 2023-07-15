#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Nameless", this->sign_val, this->exec_val), target("*undefined*")
{
	std::cout << "Shrub default constructer" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget) : AForm("Form_" + newTarget, this->sign_val, this->exec_val), target(newTarget)
{
	std::cout << "Shrub constructer" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm("Form_" + copy.target, copy.sign_val, copy.exec_val), target(copy.target)
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

unsigned int	ShrubberyCreationForm::getSignVal() const
{
	return this->sign_val;
}

unsigned int	ShrubberyCreationForm::getExecVal() const
{
	return this->exec_val;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSign())
		throw NotSignedForm();
	else if (this->getExecVal() >= executor.getGrade())
		throw NotGoodEnoughToExec();
	else
	{
        std::ofstream file(this->targetName() + "_shrubbery");
		if (file == NULL)
        {
            std::perror("Error: could not create a new file");
            file.close();
            return (1);
        }
		file << "              ,@@@@@@@, " << std::endl;
		file << "      ,,,.   ,@@@@@@/@@,  .oo8888o. " << std::endl;
		file << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o " << std::endl;
		file << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' " << std::endl;
		file << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' " << std::endl;
		file << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' " << std::endl;
		file << "  `&%\\ ` /%&'    |.|        \\ '|8' " << std::endl;
		file << "      |o|        | |         | | " << std::endl;
		file << "      |.|        | |         | | " << std::endl;
		file << "   \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_ " << std::endl;
		file.close();
	}
}
