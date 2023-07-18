#include "Intern.hpp"

Intern::Intern()
{
    forms[0] = "shrubbery creation";
    forms[1] = "robotomy request";
    forms[2] = "presidential pardon";
    std::cout << "Intern constructor" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    forms[0] = copy.forms[0];
    forms[1] = copy.forms[1];
    forms[2] = copy.forms[2];
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

AForm*  Intern::makeForm(std::string _form, std::string _target)
{
    int i = -1;

    while (++i < 3){
        if (this->forms[i] == _form)
            break ;
    }
    switch(i)
    {
        case 0:
            std::cout << "Intern creates a Shrubbery Creation Form." << std::endl;
            return (new ShrubberyCreationForm(_target));
        case 1:
            std::cout << "Intern creates a Robotomy Request Form." << std::endl;
            return (new RobotomyRequestForm(_target));
        case 2:
            std::cout << "Intern creates a Presidential Pardon Form." << std::endl;
            return (new PresidentialPardonForm(_target));
        case 3:
            std::cerr << "Error: " << _form << " does not exist." << std::endl;
    }
    return NULL;
}
