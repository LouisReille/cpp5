/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:08:35 by lreille           #+#    #+#             */
/*   Updated: 2023/05/17 17:09:18 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string name, const int gradeSign, const int gradeExec);
		Form(const Form &t);
		Form& operator=(const Form &t);
		~Form();
		class GradeTooHighException : public std::exception
		{
			public:
			const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
			const char *what(void) const throw();
		};
		const std::string getFormName() const;
		const int getFormGradeSign() const;
		const int getFormGradeExec() const;
		void beSigned(const Bureaucrat &t);
		bool sign(void) const;

	private:
		const std::string _name;
		bool _s;
		const int _gradeSign;
		const int _gradeExec;
};

std::ostream &operator<<(std::ostream &out, Form const &form);
