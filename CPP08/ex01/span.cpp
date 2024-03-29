/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:30:45 by xli               #+#    #+#             */
/*   Updated: 2021/10/18 14:02:19 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

span::span(unsigned size)
{
	_size = size;
	_min = 2147483647;
	_max = 0;
}

span::~span() {}

void	span::addNumber(int num)
{
	if (_nums.size() == _size)
		throw (SpanIsFull());
	//in case of largest num, it = _nums.end();
	//in case of smallest num, it = _nums.begin();
	std::multiset<int>::iterator it = _nums.lower_bound(num);
	std::multiset<int>::iterator it2;
	if (it != _nums.end()) //compare with right number
		_min = std::min(_min, *it - num);
	if (it != _nums.begin()) //compare with left number
	{
		it--;
		_min = std::min(_min, num - *it);
	}
	_nums.insert(num);
	it = _nums.end();
	it--;
	it2 = _nums.begin();
	_max = std::max(_max, *it - *it2);
}

int	span::shortestSpan() const
{
	if (_nums.empty() || _nums.size() <= 1)
		throw (NoSpanToFind());
	return (_min);
}

int	span::longestSpan() const
{
	if (_nums.empty() || _nums.size() <= 1)
		throw (NoSpanToFind());
	return (_max);
}

void	span::display() const
{
	std::multiset<int>::iterator it = _nums.begin();

	while(it != _nums.end())
	{
		std::cout << *it;
		it++;
	}
	std::cout << std::endl;
}

const char *span::SpanIsFull::what() const throw()
{
	return ("Exception caught: Span is full");
}

const char *span::NoSpanToFind::what() const throw()
{
	return ("Exception caught: No span to find");
}
