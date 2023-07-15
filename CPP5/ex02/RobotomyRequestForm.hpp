#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string			target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string newTarget);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm& operator = (const RobotomyRequestForm& copy);

		std::string const	targetName() const;
		void		execute(Bureaucrat const& executor) const;
};

#endif