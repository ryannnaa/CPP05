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
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Shrubbery Failed (Not Signed) ]" << std::endl;
	try
	{
		ShrubberyCreationForm f("home1");
		Bureaucrat b("Officer", 1);
		b.execForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Shrubbery Failed (Low Grade) ]" << std::endl;
	try
	{
		ShrubberyCreationForm f("home2");
		Bureaucrat b("Officer", 145);
		b.signForm(f);
		b.execForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Robotomy Success ]" << std::endl;
	try
	{
		RobotomyRequestForm f("home");
		Bureaucrat b("Officer", 1);
		b.signForm(f);
		b.execForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Robotomy Failed (Not Signed) ]" << std::endl;
	try
	{
		RobotomyRequestForm f("home1");
		Bureaucrat b("Officer", 1);
		b.execForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Robotomy Failed (Low Grade) ]" << std::endl;
	try
	{
		RobotomyRequestForm f("home2");
		Bureaucrat b("Officer", 72);
		b.signForm(f);
		b.execForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Presidential Success ]" << std::endl;
	try
	{
		PresidentialPardonForm f("home");
		Bureaucrat b("Officer", 1);
		b.signForm(f);
		b.execForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Presidential Failed (Not Signed) ]" << std::endl;
	try
	{
		PresidentialPardonForm f("home1");
		Bureaucrat b("Officer", 1);
		b.execForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Presidential Failed (Low Grade) ]" << std::endl;
	try
	{
		PresidentialPardonForm f("home2");
		Bureaucrat b("Officer", 72);
		b.signForm(f);
		b.execForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
