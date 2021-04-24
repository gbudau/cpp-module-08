#include <algorithm>
#include <stdexcept>
#include <limits>
#include <string>
#include "span.hpp"


Span::Span(unsigned int n) : _max_size(n) {
}

Span::Span(Span const & src) : _max_size(src._max_size),
								_data(src._data) {
}

Span::~Span() {
}

Span &	Span::operator=(Span const & rhs) {
	if (this != &rhs) {
		_max_size = rhs._max_size;
		_data = rhs._data;
	}
	return *this;
}

void	Span::addNumber(int n) {
	if (_data.size() == std::numeric_limits<unsigned int>::max() ||
			_data.size() + 1 > _max_size) {
		throw std::length_error(
						std::string("Span is full, cannot add more elements"));
	}
	_data.push_back(n);
}

void	Span::addRange(int start, int end) {
	if (start > end) {
		throw std::logic_error(std::string(
				"Starting range is greater than ending range"));
	}
	if (static_cast<unsigned int>(end - start) > _max_size - _data.size()) {
		throw std::logic_error(std::string(
				"Adding values in range will surpass the Span maximum size"));
	}
	for (int i = start; i < end; i++) {
		_data.push_back(i);
	}
}

unsigned int	Span::shortestSpan() const {
	if (_data.size() < 2) {
		throw std::logic_error(std::string(
		"There weren't enough elements in the Span to complete the operation"));
	}
	std::vector<int>	temp = _data;
	std::sort(temp.begin(), temp.end());
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 0; i < temp.size() - 1; i++) {
		if (static_cast<unsigned int>(temp[i + 1] - temp[i]) < shortest) {
			shortest = static_cast<unsigned int>(temp[i + 1] - temp[i]);
		}
	}
	return shortest;
}

unsigned int	Span::longestSpan() const {
	if (_data.size() < 2) {
		throw std::logic_error(std::string(
		"There weren't enough elements in the Span to complete the operation"));
	}
	std::vector<int>	temp = _data;
	std::sort(temp.begin(), temp.end());
	return static_cast<unsigned int>(temp.back() - temp.front());
}
