#include "Intern.hpp"

Intern::Intern()
{
    forms[0] = "shrubbery creation";
    forms[1] = "robotomy request";
    forms[2] = "presidential pardon";
	statments[0] = "Intern creates a Shrubbery Creation Form.";
	statments[1] = "Intern creates a Robotomy Request Form.";
	statments[2] = "Intern creates a Presidential Pardon Form.";
    std::cout << "Intern constructor" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    forms[0] = copy.forms[0];
    forms[1] = copy.forms[1];
    forms[2] = copy.forms[2];
	statments[0] = copy.forms[0];
	statments[1] = copy.forms[1];
	statments[2] = copy.forms[2];
    std::cout << "Intern copy constructor" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor" << std::endl;
}

Intern& Intern::operator = (const Intern& copy)
{
    (void)copy;
    return *this;
}

AForm* Intern::makeShrubForm(std::string targ)
{
	return (new ShrubberyCreationForm(targ));
}

AForm* Intern::makeRobotForm(std::string targ)
{
	return (new RobotomyRequestForm(targ));
}

AForm* Intern::makePresiForm(std::string targ)
{
	return (new PresidentialPardonForm(targ));
}

AForm*  Intern::makeForm(std::string _form, std::string _target)
{
	form_ptr arr[3];
    int i = -1;
	
	arr[0] = &Intern::makeShrubForm;
	arr[1] = &Intern::makeRobotForm;
	arr[2] = &Intern::makePresiForm;

    while (++i < 3){
        if (this->forms[i] == _form)
            break ;
    }
	if (i < 3)
	{
		std::cout << this->statments[i] << std::endl;
		return ((*arr[i])(_target));
	}
	std::cerr << "Error: " << _form << " does not exist." << std::endl;
    return NULL;
}
