#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private :
		std::string			target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string newTarget);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm& operator = (const ShrubberyCreationForm& copy);

		std::string const	targetName() const;
		void		execute(Bureaucrat const& executor) const;
};

#endif