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
        MutantStack() : std::stack<T, Container>() {}
        MutantStack(Container c) : std::stack<T, Container>(c) {}
        ~MutantStack() {}

        MutantStack& operator = (const MutantStack& copy) {
			this->c = copy.c;
			return *this;
		}

        typedef typename Container::iterator reverse_iterator;
        typedef typename Container::const_iterator const_reverse_iterator;
        typedef typename Container::reverse_iterator iterator;
        typedef typename Container::const_reverse_iterator const_iterator;

        iterator				begin() {return this->c.rbegin();}
        iterator				end() {return this->c.rend();}
		const_iterator			begin() const {return this->c.rbegin();}
        const_iterator			end() const {return this->c.rend();}
		reverse_iterator		rbegin() {return this->c.begin();}
        reverse_iterator		rend() {return this->c.end();}
		const_reverse_iterator	rbegin() const {return this->c.begin();}
        const_reverse_iterator	rend() const {return this->c.end();}
};

#endif