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
        return list;
    }
    // Step 1: Group elements into pairs and sort them pairwise
	std::list<std::pair<int, int> > pairs;
	std::list<int>::iterator it = list.begin();
	while (it != list.end())
	{
		int a = *it++;
		if (it == list.end())
		{
			int odd = a;
			break ;
		}
		int b = *it;
		pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}
    // Step 2: Recursively sort the pairs by their highest value
    result = margesortList();
    // Step 3: Insert the pend elements into the main chain
    std::list<int> mainChain;
    it = list.begin();
    while (it != list.end()) {
        int first = *it++;
        if (it == list.end()) {
            break;
        }
        int second = *it++;

        mainChain.push_back(first);
        mainChain.push_back(second);
        mainChain = mergeInsertionSort(mainChain);

        while (!result.empty() && result.front() < mainChain.front()) {
            mainChain.push_front(result.front());
            result.pop_front();
        }
    }
    // If there are remaining pend elements, insert them at the end
    while (!result.empty()) {
        mainChain.push_back(result.front());
        result.pop_front();
    }
    list = mainChain;
}

// Merge two sorted lists
std::list<int> merge(const std::list<int>& left, const std::list<int>& right) {
    std::list<int> result;
    typename std::list<int>::const_iterator leftIt = left.begin();
    typename std::list<int>::const_iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt < *rightIt) {
            result.push_back(*leftIt);
            ++leftIt;
        } else {
            result.push_back(*rightIt);
            ++rightIt;
        }
    }

    // Append the remaining elements from the left and right lists
    result.insert(result.end(), leftIt, left.end());
    result.insert(result.end(), rightIt, right.end());

    return result;
}

InvalidInput::InvalidInput() {}

const char* InvalidInput::what() const throw() {
	return ("Error: invalid input");
}