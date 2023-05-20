/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:00:03 by lreille           #+#    #+#             */
/*   Updated: 2023/05/18 18:01:26 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
	private:
		std::string _target;
		PresidentPardonForm();
};
