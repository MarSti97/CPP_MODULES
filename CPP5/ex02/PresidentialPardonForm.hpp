#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string			target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string newTarget);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm& operator = (const PresidentialPardonForm& copy);

		std::string const	targetName() const;
		void		execute(Bureaucrat const& executor) const;
};

#endif