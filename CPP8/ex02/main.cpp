#include "MutantStack.hpp"

int main()
{
	std::cout << "----- Mutant Stack -----" << std::endl;
    {   
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << std::endl;
	std::cout << "----- Simple list -----" << std::endl;
    {
        std::list<int> mstack;
        mstack.push_front(5);
        mstack.push_front(17);
        std::cout << mstack.front() << std::endl;
        mstack.pop_front();
        std::cout << mstack.size() << std::endl;
        mstack.push_front(3);
        mstack.push_front(5);
        mstack.push_front(737);
        mstack.push_front(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
    }
    std::cout << std::endl;
	std::cout << "----- Other tests -----" << std::endl;
    {
    	MutantStack<int> custom;
		custom.push(1);
		custom.push(2);
		custom.push(3);
		custom.push(4);
		custom.push(5);
		MutantStack<int>::reverse_iterator it = custom.rbegin();
		MutantStack<int>::reverse_iterator fin = custom.rend();
		std::cout << "SIZE : " << custom.size() << std::endl;
		std::cout << "TOP : " << custom.top() << std::endl;
		std::cout << "BEGIN : " << *it << std::endl;
		std::cout << "END : " << *--fin << std::endl;
    }
    return 0;
}
