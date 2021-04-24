#ifndef SPAN_HPP_
#define SPAN_HPP_
#include <vector>
#include <string>
#include <stdexcept>

class Span {
 public:
	explicit		Span(unsigned int n);
					Span(Span const & src);
					~Span();
	Span &			operator=(Span const & rhs);
	void			addNumber(int n);
	void			addRange(int start, int end);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template <typename T>
	void			addNumbers(T start, T end);

 private:
	Span();
	unsigned int		_max_size;
	std::vector<int>	_data;
};

template <typename T>
void	Span::addNumbers(T start, T end) {
	if (start == end) {
	throw std::logic_error(std::string(
			"Iterators have invalid range"));
	}
	while (start != end) {
		addNumber(*start++);
	}
}

#endif  // SPAN_HPP_
