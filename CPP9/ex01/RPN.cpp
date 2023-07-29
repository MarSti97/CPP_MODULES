#include "RPN.hpp"

void	makeDeck(char* input)
{
	std::stack<double> seq;
	std::string str(input);
	
	if (str.find_first_not_of("0123456789 -+/*") != std::string::npos)
		throw InvalidInput();
	while (true)
	{
		size_t pos = str.find(' ');
		if (str.find(' ') == std::string::npos){
			if (str.size() == 1 && str.find_first_of("-+/*") != std::string::npos)
				calculate(seq, static_cast<int> (str[0]));
			else {
				double res = static_cast<double> (atoi(str.c_str()));
				if (res > -10 && res < 10)
					seq.push(res);
				else
					throw OutOfRangeNumber();
			}
			break ;
		}
		std::string sub = str.substr(0, pos);
		if (sub.size() == 1 && sub.find_first_of("-+/*") != std::string::npos)
				calculate(seq, static_cast<int> (str[0]));
		else {
			double res = static_cast<double> (atoi(sub.c_str()));
			if (res > -10 && res < 10)
				seq.push(res);
			else
				throw OutOfRangeNumber();
		}
		str = str.substr(pos + 1);
	}
	if (seq.size() == 1)
		std::cout << seq.top() << std::endl;
	else
		throw SequenceErrorRPN();
}

void calculate(std::stack<double>& seq, int operation)
{
	if (seq.size() < 2)
		throw SequenceErrorRPN();
	double x = seq.top();
	seq.pop();
	double y = seq.top();
	seq.pop();
	
	switch(operation)
	{
		case 42:
			seq.push(y * x);
			return ;
		case 43:
			seq.push(y + x);
			return ;
		case 45:
			seq.push(y - x);
			return ;
		case 47:
			seq.push(y / x);
			return ;
		default :
			throw InvalidInput();
	}
}

InvalidInput::InvalidInput() {}

const char* InvalidInput::what() const throw() {
	return ("Error: invalid input");
}

OutOfRangeNumber::OutOfRangeNumber(){}

const char* OutOfRangeNumber::what() const throw(){
	return ("Error: values cannot exceed +/-10");
}

SequenceErrorRPN::SequenceErrorRPN() {}

const char* SequenceErrorRPN::what() const throw(){
	return ("Error: Reverse Polish Notation sequence error");
}