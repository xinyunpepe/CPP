/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:45:24 by xli               #+#    #+#             */
/*   Updated: 2021/10/05 08:40:22 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	clapTrap1;
	ClapTrap	clapTrap2("Bob");
	ClapTrap	clapTrap3(clapTrap2);

	clapTrap1.attack("Mike");
	clapTrap1 = clapTrap3;
	clapTrap1.attack("Tom");
	clapTrap1.takeDamage(12);
	clapTrap1.beRepaired(100);

	return (0);
}
