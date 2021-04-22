#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "easyfind.hpp"

template <typename T>
void	print_value(
		T const & container, typename T::const_iterator const & i) {
	if (i != container.end()) {
		std::cout << "Value found: " << *i << "\n";
	} else {
		std::cout << "Value not found\n";
	}
}

template <typename T>
void	test_easyfind(T & container) {
	for (int i = 0; i < 10; i++) {
		container.push_back(i);
	}
	print_value(container, easyfind(container, 5));
	print_value(container, easyfind(container, 42));
}

int	main() {
	std::vector<int> v;
	test_easyfind(v);

	std::list<int> l;
	test_easyfind(l);
}
