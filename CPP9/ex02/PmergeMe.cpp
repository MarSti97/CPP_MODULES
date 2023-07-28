#include "PmergeMe.hpp"

void	fillList(std::list<int>& list, char** av)
{
	int i = 0;

	while (av[++i])
	{
		std::string str(av[i]);
		if (str.find_first_not_of("0123456789") != std::string::npos)
			throw InvalidInput();
		list.push_back(atoi(av[i]));
	}
}

void	fillVector(std::vector<int>& vec, std::list<int>& list)
{
	std::list<int>::iterator it;
	for (it = list.begin(); it != list.end(); ++it)
		vec.push_back(*it);
}

double sortList(std::list<int>& list)
{
    const size_t n = list.size();
    if (n <= 1) {
        return 0; //fix
    }
    // Step 1: Group elements into pairs and sort them pairwise
	std::list<std::pair<int, int> > pairs, result;
	std::list<int>::iterator it = list.begin();
	while (it != list.end())
	{
		int a = *it++;
		if (it == list.end())
		{
			// int odd = a; // FIXXXX
			break ;
		}
		int b = *it++;
		// std::cout << "The pairs: a " << a << " and b " << b << std::endl;
		pairs.push_back(std::make_pair(std::max(a, b), std::min(a, b)));
	}
    // Step 2: Recursively sort the pairs by their highest value
	printList(pairs);
    result = mergesortList(pairs);
	printList(result);
	createmainchain(); // make
	insertpend(); // make
    // Step 3: Insert the pend elements into the main chain
	return 0;
}

std::list<std::pair<int, int> > mergesortList(std::list<std::pair<int, int> > list)
{
	if (list.size() <= 1)
		return list;
	std::list<std::pair<int, int> > left, right;
	size_t half = list.size() / 2;
	std::list<std::pair<int, int> >::iterator it;
	for (it = list.begin(); it != list.end(); ++it)
	{
		if (half-- > 0)
			left.push_back(*it);
		else
			right.push_back(*it);
	}
	left = mergesortList(left);
	right = mergesortList(right);
	return merge(left, right);
}

std::list<std::pair<int, int> > merge(std::list<std::pair<int, int> > left, std::list<std::pair<int, int> > right)
{
	std::list<std::pair<int, int> > res;
	while (!left.empty() && !right.empty())
	{
		if (left.front().first <= right.front().first)
		{
			res.push_back(left.front());
			left.pop_front();
		}
		else
		{
			res.push_back(right.front());
			right.pop_front();
		}
	}
	res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
	return res;
}

void printList(std::list<std::pair<int, int> > list)
{
	std::list<std::pair<int, int> >::iterator it;
	for (it = list.begin(); it != list.end(); ++it)
		std::cout << it->first << " ";
	std::cout << std::endl;
}

InvalidInput::InvalidInput() {}

const char* InvalidInput::what() const throw() {
	return ("Error: invalid input");
}