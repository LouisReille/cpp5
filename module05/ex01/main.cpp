/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:37:21 by lreille           #+#    #+#             */
/*   Updated: 2023/05/18 17:56:52 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl;
	Bureaucrat a("a", 100);
	Bureaucrat b("b", 100);
	Form formA("form A", 100, 1);
	Form formB("form B", 20, 100);
	try
	{
		a.signForm(formA);
		b.signForm(formA);
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		a.signForm(formA);
		a.signForm(formB);
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
