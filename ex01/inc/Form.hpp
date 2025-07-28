#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	public:
		Form();
		Form(std::string name, int sign, int exec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string& getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat& other);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};	
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
