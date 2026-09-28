#include "easyfind.hpp"

#include <iostream>
#include <list>
#include <vector>

static void testVector()
{
	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(0);

	std::vector<int>::iterator found = easyfind(numbers, 20);
	std::cout << "vector: " << *found << std::endl;

	try
	{
		easyfind(numbers, 42);
	}
	catch (const std::exception &error)
	{
		std::cout << "vector missing: " << error.what() << std::endl;
	}
}

static void testList()
{
	std::list<int> numbers;
	numbers.push_back(4);
	numbers.push_back(8);
	numbers.push_back(12);

	std::list<int>::iterator found = easyfind(numbers, 8);
	std::cout << "list: " << *found << std::endl;
}

int main()
{
	testVector();
	testList();
	return 0;
}