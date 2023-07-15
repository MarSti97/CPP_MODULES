#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		std::string const	name;
		bool				_signed;
		unsigned int const	grade_sign;
		unsigned int const	grade_exec;
	public :
		AForm();
		AForm(std::string newName, int signGrade, int execGrade);
		AForm(const AForm& copy);
		virtual ~AForm();

		AForm& operator = (const AForm& copy);

		std::string const	getName() const;
		unsigned int		getSignGrade() const;
		unsigned int		getExecGrade() const;
		bool				getSign() const;
		void				beSigned(const Bureaucrat& bur);
		virtual void		execute(Bureaucrat const& executor) const = 0;

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

std::ostream& operator << (std::ostream& out, const AForm& form);

#endif