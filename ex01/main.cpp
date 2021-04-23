#include <iostream>
#include <limits>
#include <list>
#include "span.hpp"

void	test_from_subject() {
	std::cout << "##### Test from the subject #####\n";
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_add_element_to_full_span() {
	std::cout << "\n##### Test adding elements to Span of size 0 #####\n";
	Span sp = Span(0);
	try {
		sp.addNumber(42);
	}
	catch (const std::exception & e) {
		std::cout << "An exception ocurred: " << e.what() << "\n";
	}
}

void	test_shortest_span_n_elements(unsigned int n) {
	Span sp = Span(n);

	std::cout <<
		"\n##### Test shortestSpan with Span of size "<< n << " ####\n";
	try {
		for (unsigned int i = 0; i < n; i++) {
			sp.addNumber(i);
		}
		std::cout << "shortestSpan() = " << sp.shortestSpan() << "\n";
	}
	catch (const std::exception & e) {
		std::cout << "An exception ocurred: " << e.what() << "\n";
	}
}

void	test_longest_span_n_elements(unsigned int n) {
	Span sp = Span(n);

	std::cout <<
		"\n##### Test longestSpan with Span of size " << n << " ####\n";
	try {
		for (unsigned int i = 0; i < n; i++) {
			sp.addNumber(i);
		}
		std::cout << "longestSpan() = " << sp.longestSpan() << "\n";
	}
	catch (const std::exception & e) {
		std::cout << "An exception ocurred: " << e.what() << "\n";
	}
}

void	test_addRange(unsigned int max_size, int start_range, int end_range) {
	Span sp = Span(max_size);

	try {
		std::cout << "\n##### Test addRange() #####\n";
		std::cout << "Add " <<
		static_cast<unsigned int>(
		std::max(start_range, end_range) - std::min(start_range, end_range)) <<
				" values into Span of size " << max_size << "\n";
		sp.addRange(start_range, end_range);
		std::cout << "shortestSpan() = " << sp.shortestSpan() << "\n";
		std::cout << "longestSpan() = " << sp.longestSpan() << "\n";
	}
	catch (const std::exception & e) {
		std::cout << "An exception ocurred: " << e.what() << "\n";
	}
}

void	test_three_values(int a, int b, int c) {
	Span sp = Span(3);

	std::cout << "\n##### Test Span with three values #####\n";
	std::cout << a << ", " << b << ", " << c << "\n";
	sp.addNumber(a);
	sp.addNumber(b);
	sp.addNumber(c);
	std::cout << "shortestSpan() = " << sp.shortestSpan() << "\n";
	std::cout << "longestSpan() = " << sp.longestSpan() << "\n";
}

void	test_five_values(int a, int b, int c, int d, int e) {
	Span sp = Span(5);

	std::cout << "\n##### Test Span with five values #####\n";
	std::cout << a << ", " << b << ", " << c << ", " << d << ", " << e << "\n";
	sp.addNumber(a);
	sp.addNumber(b);
	sp.addNumber(c);
	sp.addNumber(d);
	sp.addNumber(e);
	std::cout << "shortestSpan() = " << sp.shortestSpan() << "\n";
	std::cout << "longestSpan() = " << sp.longestSpan() << "\n";
}

void	test_add_combined() {
	Span sp = Span(std::numeric_limits<unsigned int>::max());

	std::cout << "\n##### Test addNumber() and addRange() #####\n";
	std::cout << "Add " << std::numeric_limits<int>::min() << "\n";
	sp.addNumber(std::numeric_limits<int>::min());
	std::cout << "Add " << std::numeric_limits<int>::max() << "\n";
	sp.addNumber(std::numeric_limits<int>::max());
	std::cout << "Add values in range (-42,42)\n";
	sp.addRange(-42, 42);
	std::cout << "Add " << 0 << "\n";
	sp.addNumber(0);
	std::cout << "shortestSpan() = " << sp.shortestSpan() << "\n";
	std::cout << "longestSpan() = " << sp.longestSpan() << "\n";
}

void	test_addNumber_limit() {
	const int	span_size = 5;
	Span		sp = Span(span_size);

	try {
		std::cout << "\n##### Test limit with Span size " << span_size << "\n";
		for (int i = 0; i < span_size; i++) {
			sp.addNumber(i);
			std::cout << i;
			if (i < span_size - 1) {
				std::cout << ", ";
			}
		}
		std::cout << "\nAdd 42\n";
		sp.addNumber(42);
	}
	catch (const std::exception & e) {
		std::cout << "An exception ocurred: " << e.what() << "\n";
	}
}

void	test_addNumbers_iterators() {
	const int		max_size = 20000;
	std::list<int>	l;
	Span			sp(max_size);

	std::cout << "\n##### Test addNumbers() #####\n";
	std::cout << "Creating a list with " << max_size << " elements\n";
	for (int i = 0; i < max_size; i++) {
		l.push_back(i);
	}
	std::cout << "Add " << max_size << " elements to a Span of size " <<
		max_size << "\n";
	sp.addNumbers(l.begin(), l.end());
	std::cout << "shortestSpan() = " << sp.shortestSpan() << "\n";
	std::cout << "longestSpan() = " << sp.longestSpan() << "\n";
}

void	test_addNumbers_iterators_limit() {
	const int		max_size = 20000;
	std::list<int>	l;
	Span			sp(max_size);

	std::cout << "\n##### Test addNumbers() limit #####\n";
	std::cout << "Creating a list with " << max_size << " elements\n";
	for (int i = 0; i < max_size; i++) {
		l.push_back(i);
	}
	std::cout << "Add " << max_size << " elements to a Span of size " <<
		max_size << "\n";
	sp.addNumbers(l.begin(), l.end());
	std::cout << "shortestSpan() = " << sp.shortestSpan() << "\n";
	std::cout << "longestSpan() = " << sp.longestSpan() << "\n";
	try {
		std::cout << "Add one more element to Span\n";
		sp.addNumber(42);
	}
	catch (const std::exception & e) {
		std::cout << e.what() << "\n";
	}
}

int main() {
	test_from_subject();
	test_add_element_to_full_span();

	test_shortest_span_n_elements(0);
	test_shortest_span_n_elements(1);
	test_shortest_span_n_elements(2);
	test_shortest_span_n_elements(3);
	test_shortest_span_n_elements(4);

	test_longest_span_n_elements(0);
	test_longest_span_n_elements(1);
	test_longest_span_n_elements(2);
	test_longest_span_n_elements(3);
	test_longest_span_n_elements(4);

	test_addRange(15000, 0, 15000);
	test_addRange(15000, 0, 15001);
	test_addRange(
		10, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
	test_addRange(std::numeric_limits<unsigned int>::max(), -100, 100);
	test_three_values(21, 0, 42);
	test_five_values(21, 19, 0, 42, 1337);
	test_add_combined();
	test_addNumber_limit();
	test_addNumbers_iterators();
	test_addNumbers_iterators_limit();
}
