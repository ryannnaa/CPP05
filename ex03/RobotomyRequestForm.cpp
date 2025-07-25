#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("Default")	
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		setSigned(other.getSigned());
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	executeCheck(executor);

	std::srand(std::time(NULL));
	std::string s1 = "succeeded!";
	std::string s2 = "failed!";
	std::string output;

	if (std::rand() % 2 == 0)
		output = s1;
	else
		output = s2;
	std::cout << "Robotomy of " << _target << " has " << output << std::endl;
}
