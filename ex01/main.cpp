#include "Span.hpp"

#include <iostream>
#include <vector>

static void testExample()
{
	Span span(5);
	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);
	std::cout << "example shortest: " << span.shortestSpan() << std::endl;
	std::cout << "example longest: " << span.longestSpan() << std::endl;
}

static void testRange()
{
	std::vector<int> numbers;
	for (int i = 0; i < 10000; ++i)
		numbers.push_back(i * 3);

	Span span(10000);
	span.addNumber(numbers.begin(), numbers.end());
	std::cout << "range shortest: " << span.shortestSpan() << std::endl;
	std::cout << "range longest: " << span.longestSpan() << std::endl;
}

static void testErrors()
{
	Span empty(0);
	try
	{
		empty.shortestSpan();
	}
	catch (const std::exception &error)
	{
		std::cout << "empty: " << error.what() << std::endl;
	}

	Span full(1);
	full.addNumber(42);
	try
	{
		full.addNumber(43);
	}
	catch (const std::exception &error)
	{
		std::cout << "full: " << error.what() << std::endl;
	}
}

int main()
{
	testExample();
	testRange();
	testErrors();
	return 0;
}