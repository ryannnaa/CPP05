#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: name("Default"), grade(150)
{}

Bureaucrat::Bureaucrat(const std::string& s, int i)
       : name(s)
{		
	if (i < 1)
		throw GradeTooHighException();
	else if (i > 150)
		throw GradeTooLowException();
	grade = i;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name(other.getName()), grade(other.getGrade())
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

const std::string& Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}
