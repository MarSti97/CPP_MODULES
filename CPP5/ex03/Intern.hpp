#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private :
        std::string forms[3];
		std::string statments[3];
		typedef AForm* (Intern::*form_ptr)(std::string);
		AForm* makeShrubForm(std::string targ);
		AForm* makeRobotForm(std::string targ);
		AForm* makePresiForm(std::string targ);
    public :
        Intern();
        Intern(const Intern& copy);
        ~Intern();

        Intern& operator = (const Intern& copy);

        AForm*  makeForm(std::string _form, std::string _target);

};

#endif