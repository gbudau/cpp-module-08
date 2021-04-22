#ifndef EASYFIND_HPP_
#include <algorithm>
#include <iterator>
#include <stdexcept>

template <template <typename ...> class T>
int	easyfind(T<int> const & container, int value) {
	typename T<int>::const_iterator it =
						std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw std::invalid_argument("Value not found");
	}
	return *it;
}

#endif  // EASYFIND_HPP_
