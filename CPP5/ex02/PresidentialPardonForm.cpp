#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Generic Form", 25, 5), target("*undefined*")
{
	std::cout << "Shrub default constructer" << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget) : AForm("Form_" + newTarget, 25, 5), target(newTarget)
{
	std::cout << "Shrub constructer" << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm("Form_" + copy.target, 25, 5), target(copy.target)
{
	std::cout << "Shrub copy constructer" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Shrub destructer" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& copy)
{
	if (this != &copy)
		this->target = copy.target;
	std::cout << "Shrub copy operator call" << std::endl;
	return *this;
}

std::string const	PresidentialPardonForm::targetName() const
{
	return	this->target;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSign())
		throw AForm::NotSignedForm();
	else if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowToExec();
	else
        std::cout << this->targetName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}