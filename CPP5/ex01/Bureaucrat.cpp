#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("undefined"), grade(150)
{
	std::cout << "constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName)
{
	if (newGrade < 1)
		throw GradeTooHighException();
	else if (newGrade > 150)
		throw GradeTooLowException();
	else
	{
		this->grade = newGrade;
		std::cout << newName << " constructor called" << std::endl;
	}
	
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade)
{
	std::cout << "copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& copy)
{
	const_cast<std::string&> (this->name) = copy.name;
	this->grade = copy.grade;
	std::cout << "copy assignment operator" << std::endl;
	return *this;
}

std::string const Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if(this->grade > 1)
		this->grade--;
	else
		throw GradeTooHighException(); 
	std::cout << "Incremented" << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if(this->grade < 150)
		this->grade++;
	else
		throw GradeTooLowException(); 
	std::cout << "Decremented" << std::endl;
}

std::ostream& operator << (std::ostream& out, const Bureaucrat& bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return out;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is terrible... not possible (too low)!";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade exceeds best possible grade (too high)!";
}
