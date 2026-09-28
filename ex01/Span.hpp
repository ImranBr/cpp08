#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
private:
	unsigned int _capacity;
	std::vector<int> _numbers;

public:
	Span(unsigned int capacity);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);

	template <typename InputIterator>
	void addNumber(InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			addNumber(*first);
			++first;
		}
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#endif