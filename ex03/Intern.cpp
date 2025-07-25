#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
		;
	return (*this);
}

Intern::~Intern()
{}

AForm *Intern::makeForm(const std::string& name, const std::string& target)
{
	const std::string arr[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (arr[i] == name)
		{
			int index = i;
			break;
		}
	}
	AForm *f;
	switch(index)
	{
		case 1:
			f = new ShrubberyCreationForm();
			break;
		case 2;
			f = new RobotomyRequestForm();
			break;
		case 3:
			f = new PresidentialPardonForm();
			break;
		default:
			std::cout << "I am just an intern, " << name << " is out of my scope." << std::endl;
	}
	return (f);
}
