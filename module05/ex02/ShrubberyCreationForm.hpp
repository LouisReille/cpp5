/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:54:10 by lreille           #+#    #+#             */
/*   Updated: 2023/05/20 14:59:20 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &t);
		ShrubberyCreationForm& operatpr=(const ShrubberyCreationForm &t);
		void execute(const Bureaucrar &exec);
		~ShrubberyCreationForm();
	private:
		std::string _targwt;
		ShribberyCreationForm();
};
