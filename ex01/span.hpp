#ifndef SPAN_HPP_
#define SPAN_HPP_
#include <vector>

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


 private:
	Span();
	unsigned int		_max_size;
	std::vector<int>	_data;
};

#endif  // SPAN_HPP_
