#include "AForm.hpp"

AForm::AForm()
	: _name("Default"), _signed(false), _signGrade(150), _execGrade(150)
{}

AForm::AForm(std::string name, int sign, int exec)
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

AForm::AForm(const AForm& other)
	: _name(other.getName()), _signed(other.getSigned()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_signed = other.getSigned();
	}
	return (*this);
}

AForm::~AForm()
{}

const std::string& AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

void AForm::beSigned(const Bureaucrat& other)
{
	if (_signGrade < other.getGrade())
		throw GradeTooLowException();
	_signed = true;
}

void AForm::executeCheck(Bureaucrat const & executor)
{
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	if (this->getSigned() == false)
		throw FormNotSignedException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Aform::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	std::cout << "Name: " << f.getName() << "\nSigned Status: " << std::boolalpha << f.getSigned() << "\nGrade to sign: " << f.getSignGrade() << "\nGrade to exec: " << f.getExecGrade();
	return (out);
}
