#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>

void	fillList(std::list<int>& list, char** av);
void	fillVector(std::vector<int>& vec, std::list<int>& list);
std::list<std::pair<int, int> > merge(std::list<std::pair<int, int> > left, std::list<std::pair<int, int> > right);
std::list<std::pair<int, int> > mergesortList(std::list<std::pair<int, int> > list);
double sortList(std::list<int>& list);

template<typename T>
void print(T cont){
	typename T::iterator it;
	for (it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

class InvalidInput : public std::exception
{
	public :
		InvalidInput();
		virtual const char* what() const throw();
};

void printList(std::list<std::pair<int, int> > list);

#endif