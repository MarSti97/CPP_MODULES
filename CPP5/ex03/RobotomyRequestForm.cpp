#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Generic Form", 72, 45), target("*undefined*")
{
	std::cout << "Shrub default constructor" << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget) : AForm("Form_" + newTarget, 72, 45), target(newTarget)
{
	std::cout << "Shrub constructor" << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm("Form_" + copy.target, 72, 45), target(copy.target)
{
	std::cout << "Shrub copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Shrub destructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& copy)
{
	if (this != &copy)
		this->target = copy.target;
	std::cout << "Shrub copy operator call" << std::endl;
	return *this;
}

std::string const	RobotomyRequestForm::targetName() const
{
	return	this->target;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSign())
		throw AForm::NotSignedForm();
	else if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowToExec();
	else
	{
		std::srand(std::time(0));
		int randomNum = rand() % 2;
		std::cout << "<<<<< " << randomNum << " >>>>>>" << std::endl;
        std::cout << "BzzzZZzzz ZZzzzZ BZZZZ... (that's the sound of a drill)" << std::endl;
		if (randomNum)
			std::cout << this->targetName() << " has been robotomized successfully!" << std::endl;
		else
			std::cout << this->targetName() << " robotomy has failed." << std::endl;
	}
}