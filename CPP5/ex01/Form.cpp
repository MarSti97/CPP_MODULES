#include "Form.hpp"

Form::Form() : name("undefined"), _signed(false), grade_sign(150), grade_exec(150)
{
    std::cout << "default constructor" << std::endl;
}

Form::Form(std::string newName, int signGrade, int execGrade) : name(newName), _signed(false), grade_sign(signGrade), grade_exec(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << newName << " constructor" << std::endl;
}

Form::Form(const Form& copy) : name(copy.name), _signed(copy._signed), grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{
    std::cout << "copy constructor" << std::endl;
}

Form::~Form()
{
    std::cout << "destructor" << std::endl;
}

Form& Form::operator = (const Form& copy)
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

std::string const	Form::getName() const
{
    return this->name;
}

unsigned int    Form::getSignGrade() const
{
    return this->grade_sign;
}

unsigned int    Form::getExecGrade() const
{
    return this->grade_exec;
}

bool    Form::getSign() const
{
    return this->_signed;
}

void	Form::beSigned(const Bureaucrat& bur)
{
    if (bur.getGrade() <= this->grade_sign)
        this->_signed = true;
    bur.signForm(*this);
}

std::ostream& operator << (std::ostream& out, const Form& form)
{
	out << form.getName() << ", form is " << (form.getSign() ? "" : "not") << " signed, signed grade " << form.getSignGrade() << ", execute grade " << form.getExecGrade() << std::endl;
	return out;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}