#include "Bureaucrat.hpp"
#include <iostream>

int main ()
{
	std::cout << "[ Testing grade of 151 ]" << std::endl;
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
	std::cout << std::endl;

	std::cout << "[ Testing grade of 0 ]" << std::endl;
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
	std::cout << std::endl;

	std::cout << "[ Testing grade of 1 ]" << std::endl;
	try
	{	
		Bureaucrat b2("Someone", 1);
		std::cout << b2 << std::endl << "( Testing increment )" << std::endl;
		b2.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "[ Increment && Decrement ]" << std::endl;
		Bureaucrat b2("Someone", 10);
		std::cout << b2 << std::endl;

		std::cout << "( Testing increment )" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			b2.incrementGrade();
			std::cout << b2 << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << "( Testing decrement )" << std::endl;	
		for (int i = 0; i < 5; i++)
		{
			b2.decrementGrade();
			std::cout << b2 << std::endl;
		}
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
