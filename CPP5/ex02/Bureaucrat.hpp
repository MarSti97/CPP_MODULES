#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private :
		std::string const	name;
		unsigned int		grade;
	public :
		Bureaucrat();
		Bureaucrat(std::string newName, int newGrade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();

		Bureaucrat& operator = (const Bureaucrat& copy);

		std::string const	getName() const;
		unsigned int		getGrade() const;
		void				incrementGrade(); 
		void				decrementGrade();
		void				signForm(const Form& form) const;

	class GradeTooLowException : public std::exception
	{
		public :
			GradeTooLowException() {}
			virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public :
			GradeTooHighException() {}
			virtual const char* what() const throw();
	};
};

std::ostream& operator << (std::ostream& out, const Bureaucrat& bur);

#endif