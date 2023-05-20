/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:22:22 by lreille           #+#    #+#             */
/*   Updated: 2023/05/18 17:58:12 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():_gradeExec(0), _gradeSign(0), _s(false)
{
}

Form::~Form()
{
}

Form::Form(const Form &t): _name(t._name), _gradeSign(t._gradeSign),
_gradeExec(t._gradeExec), _s(t._s)
{
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const std::string Form::getFormName() const
{
	return(this->_name);
}

const int Form::getFormGradeSign() const
{
	return(this->_gradeSign);
}

const int Form::getFormGradeExec() const
{
	return(this->_gradeExec);
}

Form::Form(const std::string name, const int gradeSign, const int gradeExec):
_name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	_s = false;
	if (_gradeExec < 1 || _gradeSign < 1)
		throw GradeTooHighException();
	else if (_gradeExec > 150 || _gradeSign > 150)
		throw GradeTooLowException();
}

bool Form::sign(void) const
{
	return (this->_s);
}

void Form::beSigned(const Bureaucrat &t)
{
	if (t.getGrade() > _gradeSign)
		throw GradeTooLowException();
	else
		this->_s = true;
}

Form& Form::operator=(const Form &t)
{
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "[" << ((form.sign()) ? "Signed" : "Unsigned") << "] "
	<< form.getFormName() << " of sign: " << form.getFormGradeSign()
	<< " and of execution: " << form.getFormGradeExec();
//	<< std::endl;
	return (out);
}

