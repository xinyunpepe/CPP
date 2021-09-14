/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:45:24 by xli               #+#    #+#             */
/*   Updated: 2021/09/13 18:34:40 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap	fragTrap1;
	FragTrap	fragTrap2("Bille");
	FragTrap	fragTrap3(fragTrap2);

	fragTrap1.attack("Carmen");
	fragTrap1 = fragTrap3;
	fragTrap1.attack("Harper");
	fragTrap1.takeDamage(12);
	fragTrap1.beRepaired(100);
	fragTrap1.highFivesGuys();

	return (0);
}
