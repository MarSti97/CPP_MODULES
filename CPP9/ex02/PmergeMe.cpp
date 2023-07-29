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

void	fillVector(std::vector<int>& vec, char** av)
{
	int i = 0;

	while (av[++i])
	{
		std::string str(av[i]);
		if (str.find_first_not_of("0123456789") != std::string::npos)
			throw InvalidInput();
		vec.push_back(atoi(av[i]));
	}
}

// ********** ALGORITHM FOR LIST **********
void	sortList(std::list<int>& list)
{
	bool odd_flag = false;
	int odd;
    if (list.size() <= 1) {
        throw SequenceTooShort();
    }
    // Step 1: Group elements into pairs and sort them pairwise
	std::list<std::pair<int, int> > pairs;
	std::list<int>::iterator it = list.begin();
	while (it != list.end())
	{
		int a = *it++;
		if (it == list.end())
		{
			odd = a;
			odd_flag = true;
			break ;
		}
		int b = *it++;
		pairs.push_back(std::make_pair(std::max(a, b), std::min(a, b)));
	}
    // Step 2: Recursively sort the pairs by their highest value
    pairs = merge_sortList(pairs);
	list = createList(pairs);
    // Step 3: Insert the pend elements into the main chain
	list.push_front(pairs.front().second);
	pairs.pop_front();
	if (odd_flag)
		list.insert(binarySearchList(list, odd), odd);
	while (!pairs.empty())
	{
		int target = pairs.front().second;
		list.insert(binarySearchList(list, target), target);
		pairs.pop_front();
	}
}

std::list<std::pair<int, int> > merge_sortList(std::list<std::pair<int, int> > list)
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
	left = merge_sortList(left);
	right = merge_sortList(right);
	return mergeList(left, right);
}

std::list<std::pair<int, int> > mergeList(std::list<std::pair<int, int> > left, std::list<std::pair<int, int> > right)
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

std::list<int> createList(std::list<std::pair<int, int> > pairs)
{
	std::list<int> list;
	std::list<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it)
		list.push_back(it->first);
	return list;
}

std::list<int>::iterator binarySearchList(std::list<int>& list, int target)
{
	std::list<int>::iterator left = list.begin();
	std::list<int>::iterator right = list.end();
	while (left != right) {
		std::list<int>::iterator mid = left;
		std::advance(mid, std::distance(left, right) / 2);

		if (*mid == target)
			return mid;
		else if (*mid < target) {
			++mid; // Move to the right half
			left = mid;
		}
		else
			right = mid; // Move to the left half
	}
    return left; // Position to insert the new element
}

// ********** ALGORITHM FOR VECTOR **********

void	sortVector(std::vector<int>& vec)
{
	bool odd_flag = false;
	int odd;
    if (vec.size() <= 1) {
        throw SequenceTooShort();
    }
	std::vector<std::pair<int, int> > pairs;
	std::vector<int>::iterator it = vec.begin();
	while (it != vec.end())
	{
		int a = *it++;
		if (it == vec.end())
		{
			odd = a;
			odd_flag = true;
			break ;
		}
		int b = *it++;
		pairs.push_back(std::make_pair(std::max(a, b), std::min(a, b)));
	}
    pairs = merge_sortVector(pairs);
	vec = createVector(pairs);
	vec.insert(vec.begin(), pairs.front().second);
	// vec.push_front(pairs.front().second);
	pairs.erase(pairs.begin());
	if (odd_flag)
		vec.insert(binarySearchVector(vec, odd), odd);
	while (!pairs.empty())
	{
		int target = pairs.front().second;
		vec.insert(binarySearchVector(vec, target), target);
		pairs.erase(pairs.begin());
	}
}

std::vector<std::pair<int, int> > merge_sortVector(std::vector<std::pair<int, int> > list)
{
	if (list.size() <= 1)
		return list;
	std::vector<std::pair<int, int> > left, right;
	size_t half = list.size() / 2;
	std::vector<std::pair<int, int> >::iterator it;
	for (it = list.begin(); it != list.end(); ++it)
	{
		if (half-- > 0)
			left.push_back(*it);
		else
			right.push_back(*it);
	}
	left = merge_sortVector(left);
	right = merge_sortVector(right);
	return mergeVector(left, right);
}

std::vector<std::pair<int, int> > mergeVector(std::vector<std::pair<int, int> > left, std::vector<std::pair<int, int> > right)
{
	std::vector<std::pair<int, int> > res;
	while (!left.empty() && !right.empty())
	{
		if (left.front().first <= right.front().first)
		{
			res.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			res.push_back(right.front());
			right.erase(right.begin());
		}
	}
	res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
	return res;
}

std::vector<int> createVector(std::vector<std::pair<int, int> > pairs)
{
	std::vector<int> list;
	std::vector<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it)
		list.push_back(it->first);
	return list;
}

std::vector<int>::iterator binarySearchVector(std::vector<int>& list, int target)
{
	std::vector<int>::iterator left = list.begin();
	std::vector<int>::iterator right = list.end();
	while (left != right) {
		std::vector<int>::iterator mid = left;
		std::advance(mid, std::distance(left, right) / 2);

		if (*mid == target)
			return mid;
		else if (*mid < target) {
			++mid;
			left = mid;
		}
		else
			right = mid;
	}
    return left;
}

// void printList(std::list<std::pair<int, int> > list)
// {
// 	std::list<std::pair<int, int> >::iterator it;
// 	for (it = list.begin(); it != list.end(); ++it)
// 		std::cout << it->first << " ";
// 	std::cout << std::endl;
// }

InvalidInput::InvalidInput() {}

const char* InvalidInput::what() const throw() {
	return ("Error: invalid input");
}

SequenceTooShort::SequenceTooShort() {}

const char* SequenceTooShort::what() const throw() {
	return ("Error: sequence contains one or less integers therefore cannot be sorted");
}