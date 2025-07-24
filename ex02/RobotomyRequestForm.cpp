#include "RobotomyRequestForm.hpp"
#include <stdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("Default")	
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target);
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		_sign = other.getSigned();
	}
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	executeCheck();

	std::srand(std::time(NULL));
	std::string s1 = "Success!";
	std::string s2 = "Failed!";
	std::string output;

	if (std::rand() % 2 == 0)
		output = s1;
	else
		output = s2;
	std::cout << "Robotomy of " << _target << " has " << output << std::endl;
}
