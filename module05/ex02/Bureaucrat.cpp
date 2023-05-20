/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:23:40 by lreille           #+#    #+#             */
/*   Updated: 2023/05/18 17:49:13 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _grade(0)
{
}

Bureaucrat::~Bureaucrat()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grade is too High!\nIt sould be between 1 and 150");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's grade is too Low!\nIt should be between 1 and 150");
}

Bureaucrat::Bureaucrat(const Bureaucrat &type):_name(type._name)
{
	_grade= type._grade;
}

const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::inc(void)
{
	if (_grade > 1)
	{
		_grade -= 1;
		std::cout << getName() << "'s rank has increased." << std::endl;
		std::cout << "It is now at: " << _grade << std::endl;
	}
	else if (_grade == 1)
		throw GradeTooHighException();
}

void Bureaucrat::dec(void)
{
	if (_grade < 150)
	{
		_grade += 1;
		std::cout << getName() << "'s rank has lowered." << std::endl;
		std::cout << "It is now at: " << _grade << std::endl;
	}
	else if (_grade == 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form) const
{
	if (form.sign() == false)
	{
		std::cout << *this << " signed " << form << std::endl;
	}
	else 
	{
		if (form.sign() == true)
		{
			std::cout << *this << " couldn't sign " << form << std::endl;
			std::cout << "because it is already signed." << std::endl;
		}

		else if (form.getFormGradeSign() < this->_grade)
		{
			std::cout << *this << " couldn't sign " << form << std::endl;
			std::cout << " because ";
			throw GradeTooLowException();
		}
		else
			std::cout << *this << " signs " << form << std::endl;
	}
	form.beSigned(*this);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &t)
{
	_grade = t._grade;
	return(*this);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &ref)
{
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (out);
}
