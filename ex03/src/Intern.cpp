#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		;
	}
	return (*this);
}

Intern::~Intern()
{}

AForm *Intern::makeForm(const std::string& name, const std::string& target)
{
	const std::string arr[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	int index = 3;

	for (int i = 0; i < 3; i++)
	{
		if (arr[i] == name)
		{
			index = i;
			break;
		}
	}
	AForm *f = NULL;
	switch(index)
	{
		case 0:
			f = new ShrubberyCreationForm(target);
			break;
		case 1:
			f = new RobotomyRequestForm(target);
			break;
		case 2:
			f = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "I am just an intern, " << name << " is out of my scope." << std::endl;
	}
	return (f);
}
