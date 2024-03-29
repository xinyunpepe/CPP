/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:33:53 by xli               #+#    #+#             */
/*   Updated: 2021/09/23 09:28:53 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form();
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form &copy);
		virtual ~Form();

		Form &operator=(const Form &copy);

		std::string	getName() const;
		bool		getSigned();
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(Bureaucrat &b);

		class GrandTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Exception caught: grade too high");
				}
		};

		class GrandTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Exception caught: grade too low");
				}
		};
};

std::ostream &operator<<(std::ostream &os, const Form &srcs);

#endif
