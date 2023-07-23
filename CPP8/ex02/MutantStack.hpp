#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public :
        MutantStack() {}
        MutantStack(Container c) : std::stack<T, Container>(c) {}
        ~MutantStack() {}

        MutantStack& operator = (const MutantStack& copy) {
			this->c = copy.c;
			return *this;
		}

        typedef typename Container::iterator iterator;

        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}
};

#endif