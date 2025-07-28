#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	public:
		AForm();
		AForm(std::string name, int sign, int exec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void setSigned(bool b);

		void beSigned(const Bureaucrat& other);
		void executeCheck(Bureaucrat const & executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;

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

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm *f);

#endif
