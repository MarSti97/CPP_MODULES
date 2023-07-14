#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		std::string const	name;
		bool				_signed;
		unsigned int const	grade_sign;
		unsigned int const	grade_exec;
	public :
		Form();
		Form(std::string newName, int signGrade, int execGrade);
		Form(const Form& copy);
		~Form();

		Form& operator = (const Form& copy);

		std::string const	getName() const;
		unsigned int		getSignGrade() const;
		unsigned int		getExecGrade() const;
		bool				getSign() const;
		void				beSigned(const Bureaucrat& bur);

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

std::ostream& operator << (std::ostream& out, const Form& form);

#endif