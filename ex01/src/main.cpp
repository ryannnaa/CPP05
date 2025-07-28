#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main ()
{
	std::cout << "[ Form with sign grade 0 ]" << std::endl;
	try
	{
		Form f("WrongGrade", 0, 1);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n[ Form with sign grade 151 ]" << std::endl;
	try
	{
		Form f("WrongGrade", 151, 1);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n[ Form with exec grade 0 ]" << std::endl;
	try
	{
		Form f("WrongGrade", 1, 0);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n[ Form with exec grade 151 ]" << std::endl;
	try
	{
		Form f("WrongGrade", 1, 151);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	try
	{	
		Bureaucrat b("Someone", 1);
		Form f("Test", 2, 1);
		std::cout << "\n[ Bureaucrat Someone ]\n" << b << std::endl;
		std::cout << "\n[ Form Test ]\n" << f << std::endl;
		b.signForm(f);
		std::cout << "\n[ Form Test ]\n" << f << std::endl;
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
		Bureaucrat b("Someone else", 2);
		Form f("Other test", 1, 1);
		std::cout << "\n[ Bureaucrat Someone else ]\n" << b << std::endl;
		std::cout << "\n[ Form Other test ]\n" << f << std::endl;
		b.signForm(f);
		std::cout << "\n[ Form Other test ]\n" << f << std::endl;
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
