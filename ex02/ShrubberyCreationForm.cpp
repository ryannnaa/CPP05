#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("Default")	
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target);
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		_sign = other.getSigned();
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	executeCheck();
	std::ofstream outFile(_target);
	if (!outFile)
	{
		std::cerr << "Error: Failed to open file" << std::endl;
		return ;
	}
	outFile << "       Tree 1              Tree 2\n";
	outFile << "\n";
	outFile << "        /\\\n";
	outFile << "       /**\\\n";
	outFile << "      /****\\              /\\\n";
	outFile << "     /******\\            /**\\\n";
	outFile << "    /********\\          /****\\\n";
	outFile << "       ||||                ||\n";
	outFile << "       ||||                ||\n";
	outFile << "       ||||                ||\n";
	outFile.close();	
}
