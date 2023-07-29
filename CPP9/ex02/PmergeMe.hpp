#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>

void	fillList(std::list<int>& list, char** av);
void	fillVector(std::vector<int>& vec, char** av);
// List algorithm
void	sortList(std::list<int>& list);
std::list<std::pair<int, int> >	merge_sortList(std::list<std::pair<int, int> > list);
std::list<std::pair<int, int> >	mergeList(std::list<std::pair<int, int> > left, std::list<std::pair<int, int> > right);
std::list<int>	createList(std::list<std::pair<int, int> > pairs);
std::list<int>::iterator	binarySearchList(std::list<int>& list, int target);
// Vector algorithm
void	sortVector(std::vector<int>& list);
std::vector<std::pair<int, int> >	merge_sortVector(std::vector<std::pair<int, int> > list);
std::vector<std::pair<int, int> >	mergeVector(std::vector<std::pair<int, int> > left, std::vector<std::pair<int, int> > right);
std::vector<int>	createVector(std::vector<std::pair<int, int> > pairs);
std::vector<int>::iterator	binarySearchVector(std::vector<int>& list, int target);

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

class SequenceTooShort : public std::exception
{
	public :
		SequenceTooShort();
		virtual const char* what() const throw();
};

void printList(std::list<std::pair<int, int> > list);

#endif