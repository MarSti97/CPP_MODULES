#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "----- Test Vector -----" << std::endl;
	{
		std::vector<int> vec(5, 7);
		::print(vec);
		int res;
		try
		{
			res = ::easyfind(vec, 44);
			std::cout << "Found: " << res << std::endl;
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
	{
		int arr[] = {7, 21, 42, 77, 73, 0};
		std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
		::print(vec);
		int res;
		try
		{
			res = ::easyfind(vec, 73);
			std::cout << "Found: " << res << std::endl;
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "----- Test List -----" << std::endl;
	{
		std::list<int> lst(5, 7);
		::print(lst);
		int res;
		try
		{
			res = ::easyfind(lst, 44);
			std::cout << "Found: " << res << std::endl;
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
	{
		int arr[] = {7, 21, 42, 77, 73, 0};
		std::list<int> lst(arr, arr + sizeof(arr) / sizeof(arr[0]));
		::print(lst);
		int res;
		try
		{
			res = ::easyfind(lst, 73);
			std::cout << "Found: " << res << std::endl;
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
		std::cout << std::endl;
	std::cout << "----- Test Deque -----" << std::endl;
	{
		std::deque<int> deq(5, 7);
		::print(deq);
		int res;
		try
		{
			res = ::easyfind(deq, 44);
			std::cout << "Found: " << res << std::endl;
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
	{
		int arr[] = {7, 21, 42, 77, 73, 0};
		std::deque<int> deq(arr, arr + sizeof(arr) / sizeof(arr[0]));
		::print(deq);
		int res;
		try
		{
			res = ::easyfind(deq, 73);
			std::cout << "Found: " << res << std::endl;
		}
		catch(std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
}