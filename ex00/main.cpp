#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include "easyfind.hpp"

int	main() {
	std::vector<int> v = { 7, 5, 16, 8, 0};

	try {
		int i = easyfind(v, 9);
		std::cout << i << "\n";
	}
	catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
}
