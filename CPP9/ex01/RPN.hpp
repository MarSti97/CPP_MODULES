#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <exception>

void	makeDeck(char* input);
void	calculate(std::stack<double>& seq, int operation);

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