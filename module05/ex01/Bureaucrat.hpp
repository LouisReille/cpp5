/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:38:17 by lreille           #+#    #+#             */
/*   Updated: 2023/05/17 17:24:39 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "Form.hpp"

class Form;
class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat &operator=(const Bureaucrat &type);
		~Bureaucrat();
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		const std::string getName(void)const;
		int getGrade(void)const;
		void inc(void);
		void dec(void);
		void signForm(Form &form) const;
	private:
		const std::string _name; 
		int	_grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &ref);
