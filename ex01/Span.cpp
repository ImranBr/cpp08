#include "Span.hpp"

#include <algorithm>
#include <limits>

Span::Span(unsigned int capacity) : _capacity(capacity), _numbers()
{
	_numbers.reserve(capacity);
}

Span::Span(const Span &other) : _capacity(other._capacity), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_capacity = other._capacity;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _capacity)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("not enough numbers to find a span");

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (std::vector<int>::const_iterator it = sorted.begin() + 1;
		it != sorted.end(); ++it)
	{
		long long difference = static_cast<long long>(*it) - *(it - 1);
		unsigned int distance = static_cast<unsigned int>(difference);
		if (distance < shortest)
			shortest = distance;
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("not enough numbers to find a span");

	std::vector<int>::const_iterator minimum = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maximum = std::max_element(_numbers.begin(), _numbers.end());
	long long difference = static_cast<long long>(*maximum) - *minimum;
	return static_cast<unsigned int>(difference);
}