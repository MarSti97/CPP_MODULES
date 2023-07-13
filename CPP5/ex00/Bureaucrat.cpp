#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("undefined"), grade(150)
{
	std::cout << "constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName)
{

	std::cout << newName << " constructor called" << std::endl;
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

}

std::string const Bureaucrat::getName()
{
	return this->name;
}

int Bureaucrat::getGrade()
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{

}

void Bureaucrat::decrementGrade()
{

}

std::ostream& operator << (std::ostream& out, const Bureaucrat& bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return out;
}
