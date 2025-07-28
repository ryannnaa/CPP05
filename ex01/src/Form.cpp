#include "Form.hpp"

Form::Form()
	: _name("Default"), _signed(false), _signGrade(150), _execGrade(150)
{}

Form::Form(std::string name, int sign, int exec)
	: _name(name), _signed(false), _signGrade(sign), _execGrade(exec)
{
	if (sign < 1)
		throw GradeTooHighException();
	else if (sign > 150)
		throw GradeTooLowException();

	if (exec < 1)
		throw GradeTooHighException();
	else if (exec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other.getName()), _signed(other.getSigned()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_signed = other.getSigned();
	}
	return (*this);
}

Form::~Form()
{}

const std::string& Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

void Form::beSigned(const Bureaucrat& other)
{
	if (_signGrade < other.getGrade())
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	std::cout << "Name: " << f.getName() << "\nSigned Status: " << std::boolalpha << f.getSigned() << "\nGrade to sign: " << f.getSignGrade() << "\nGrade to exec: " << f.getExecGrade();
	return (out);
}
