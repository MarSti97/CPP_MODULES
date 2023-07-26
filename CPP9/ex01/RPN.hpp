#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>
#include <exception>

std::deque<int>	makeDeck(char* input);
void			calculate(std::deque<int>& seq);
double 			operation(double y, double x, std::deque<int>::iterator& front, std::deque<int>& seq);

class InvalidInput : public std::exception
{
	public :
		InvalidInput();
		virtual const char* what() const throw();
};

class OutOfRangeNumber : public std::exception
{
	public :
		OutOfRangeNumber();
		virtual const char* what() const throw();
};


class SequenceErrorRPN : public std::exception
{
	public :
		SequenceErrorRPN();
		virtual const char* what() const throw();
};

#endif