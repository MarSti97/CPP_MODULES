#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Form
{
	private :
		std::string const	name;
		bool				_signed;
		unsigned int const	grade_sign;
		unsigned int const	grade_required;
	public :
		Form();
		Form(std::string newName, int newGrade);
		Form(const Form& copy);
		~Form();

		Form& operator = (const Form& copy);

		std::string const	getName() const;
		int					getGrade() const;

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