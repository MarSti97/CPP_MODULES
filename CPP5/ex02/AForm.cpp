#include "AForm.hpp"

AForm::AForm() : name("undefined"), _signed(false), grade_sign(150), grade_exec(150)
{
    std::cout << "default constructor" << std::endl;
}

AForm::AForm(std::string newName, int signGrade, int execGrade) : name(newName), _signed(false), grade_sign(signGrade), grade_exec(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << newName << " constructor" << std::endl;
}

AForm::AForm(const AForm& copy) : name(copy.name), _signed(copy._signed), grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{
    std::cout << "copy constructor" << std::endl;
}

AForm::~AForm()
{
    std::cout << "destructor" << std::endl;
}

AForm& AForm::operator = (const AForm& copy)
{
    if (this != &copy)
	{
		const_cast<std::string&> (this->name) = copy.name;
        this->_signed = copy._signed;
		const_cast<unsigned int&> (this->grade_sign) = copy.grade_sign;
		const_cast<unsigned int&> (this->grade_exec) = copy.grade_exec;
	}
	std::cout << "copy assignment operator" << std::endl;
	return *this;
}

std::string const	AForm::getName() const
{
    return this->name;
}

unsigned int    AForm::getSignGrade() const
{
    return this->grade_sign;
}

unsigned int    AForm::getExecGrade() const
{
    return this->grade_exec;
}

bool    AForm::getSign() const
{
    return this->_signed;
}

void	AForm::beSigned(const Bureaucrat& bur)
{
	if (this->getSign()){
		std::cout << "This Aform is already signed" << std::endl;
		return ;
	}
    if (bur.getGrade() <= this->grade_sign)
        this->_signed = true;
    bur.signForm(*this);
}

std::ostream& operator << (std::ostream& out, const AForm& form)
{
	out << form.getName() << ", form " << (form.getSign() ? "is" : "is not") << " signed, signed grade " << form.getSignGrade() << ", execute grade " << form.getExecGrade() << std::endl;
	return out;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::NotSignedForm::what() const throw()
{
	return "This form has NOT been signed!";
}

const char* AForm::GradeTooLowToExec::what() const throw()
{
	return "Execution failed, grade too low!";
}