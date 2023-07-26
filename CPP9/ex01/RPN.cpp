#include "RPN.hpp"

std::deque<int>	makeDeck(char* input)
{
	std::deque<int> seq;
	std::string str(input);
	
	if (str.find_first_not_of("0123456789 -+/*") != std::string::npos)
		throw InvalidInput();
	while (true)
	{
		size_t pos = str.find(' ');
		if (str.find(' ') == std::string::npos){
			if (str.size() == 1 && str.find_first_of("-+/*") != std::string::npos)
				seq.push_back(static_cast<int> (str[0]));
			else {
				int res = atoi(str.c_str());
				if (res > -10 && res < 10)
					seq.push_back(res);
				else
					throw OutOfRangeNumber();
			}
			break ;
		}
		std::string sub = str.substr(0, pos);
		if (sub.size() == 1 && sub.find_first_of("-+/*") != std::string::npos)
				seq.push_back(static_cast<int> (sub[0]));
		else {
			int res = atoi(sub.c_str());
			if (res > -10 && res < 10)
				seq.push_back(res);
			else
				throw OutOfRangeNumber();
		}
		str = str.substr(pos + 1);
	}
	return seq;
}

void calculate(std::deque<int>& seq)
{
	double x;
	double y;
	std::deque<int>::iterator front = seq.begin();
	
	if (*front < 10)
		x = static_cast<double> (*front++);
	else 
		throw SequenceErrorRPN();
	seq.pop_front();
	while (front != seq.end())
	{
		if (*front < 10)
			y = static_cast<double> (*front++);
		else 
			throw SequenceErrorRPN();
		seq.pop_front();
		x = operation(y, x, front, seq);
	}
	std::cout << x << std::endl;
}

double operation(double y, double x, std::deque<int>::iterator& front, std::deque<int>& seq)
{
	int op;
	if (*front > 10) {
		op = *front++;
		seq.pop_front();
	}
	else if (seq.back() > 10) {
		op = seq.back();
		seq.pop_back();
	}
	else
		throw SequenceErrorRPN();
	switch(op)
	{
		case 42:
			return (y * x);
		case 43:
			return (y + x);
		case 45:
			return (x - y);
		case 47:
			return (x / y);
		default :
			throw InvalidInput();
	}
	return 0;
}

InvalidInput::InvalidInput() {}

const char* InvalidInput::what() const throw() {
	return ("Error: invalid input");
}

OutOfRangeNumber::OutOfRangeNumber(){}

const char* OutOfRangeNumber::what() const throw(){
	return ("Error: values cannot be double digits");
}

SequenceErrorRPN::SequenceErrorRPN() {}

const char* SequenceErrorRPN::what() const throw(){
	return ("Error: Reverse Polish Notation sequence error");
}