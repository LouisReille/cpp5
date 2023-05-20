/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:37:21 by lreille           #+#    #+#             */
/*   Updated: 2023/05/09 18:05:58 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("a", 1);
		Bureaucrat b("b", 150);
		Bureaucrat c("c", 50);
		Bureaucrat d("d", 100);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		a.dec();
		b.inc();
		c.inc();
		d.dec();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat e("e", -200);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat f("f", 200);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return 0;
}
