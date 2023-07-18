#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private :
        std::string forms[3];
    public :
        Intern();
        Intern(const Intern& copy);
        ~Intern();

        Intern& operator = (const Intern& copy);

        AForm*  makeForm(std::string _form, std::string _target);

};

#endif