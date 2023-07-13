#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

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

		std::string const	getName();
		int					getGrade();
		void				incrementGrade(); 
		void				decrementGrade(); 
};

class GradeTooLowException : public std::exception
{
	public :
		virtual const char* what() const throw()
		{
			return "Grade is too low!";
		}
};

class GradeTooHighException : public std::exception
{
	public :
		virtual const char* what() const throw()
		{
			return "Grade is too high!";
		}
};

std::ostream& operator << (std::ostream& out, const Bureaucrat& bur);

#endif