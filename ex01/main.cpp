#include "Bureaucrat.hpp"
#include <iostream>

int main ()
{
	try
	{
		Bureaucrat b("John", 151);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{	
		Bureaucrat b1("Helen", 0);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{	
		Bureaucrat b2("Someone", 1);
		std::cout << b2 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
