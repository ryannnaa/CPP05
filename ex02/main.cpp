#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main ()
{
	std::cout << "[ Shrubbery Success ]" << std::endl;
	try
	{
		ShrubberyCreationForm f("home");
		Bureaucrat b("Officer", 1);
		b.signForm(f);
		b.execForm(f);
	}
	catch (const AForm::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const AForm::FormNotSignedException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
