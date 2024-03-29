/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:23:17 by xli               #+#    #+#             */
/*   Updated: 2021/10/05 12:09:12 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		unsigned	_hitpoints;
		unsigned	_energyPoints;
		unsigned	_attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &copy);

		std::string	getName() const;
		void		setName(std::string const name);
		void		attack(std::string const &target);
		void		takeDamage(unsigned amount);
		void		beRepaired(unsigned amount);
};

#endif
