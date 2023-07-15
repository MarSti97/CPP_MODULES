#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string			target;
		static const int	sign_val = 145;
		static const int	exec_val = 137;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string newTarget);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm& operator = (const ShrubberyCreationForm& copy);

		std::string const	targetName() const;
		unsigned int		getSignVal() const;
		unsigned int		getExecVal() const;
		void		execute(Bureaucrat const& executor) const;
};

#endif