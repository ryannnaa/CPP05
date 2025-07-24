#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(150)
{}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other.getName()), _grade(other.getGrade())
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm& f)
{
	try
	{
		f.beSigned(this);
		std::cout << getName() << " signed " << f.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
	 	std::cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}	
}

void Bureaucrat::execForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << getName() << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
	}
	catch (const AForm::FormNotSignedException& e)
	{
		std::cout << getName() << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
	}
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
