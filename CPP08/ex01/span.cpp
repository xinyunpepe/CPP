/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:30:45 by xli               #+#    #+#             */
/*   Updated: 2021/09/30 15:39:35 by xli              ###   ########lyon.fr   */
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

span	&span::operator=(const span &copy)
{
	if (this == &copy)
		return (*this);
	_size = copy._size;
	_min = copy._min;
	_max = copy._max;
	return (*this);
}

void	span::addNumber(int num) //???
{
	if (_nums.size() == _size) //containers size = max size
		throw (SpanIsFull());
	std::multiset<int>::iterator it = _nums.lower_bound(num), it2;
	if (it != _nums.end())
		_min = std::min(_min, *it - num);
	if (it != _nums.begin())
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

template <typename it>
void	span::addNumber(it begin, it end)
{
	if (std::distance(begin, end) + _nums.size() > _size)
		throw (SpanIsFull());
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
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