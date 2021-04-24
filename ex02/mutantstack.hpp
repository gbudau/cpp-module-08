#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_
#include <stack>
#include <deque>

template <typename T>
class MutantStack: public std::stack<T> {
 public:
	 MutantStack() {}
	 MutantStack(const MutantStack & src) : std::stack<T>(src) {}
	 MutantStack &		operator=(const MutantStack &) {
							return *this;
	 					}
	 ~MutantStack() {}
	 typedef typename std::deque<T>::iterator			iterator;
	 typedef typename std::deque<T>::reverse_iterator	reverse_iterator;

	 iterator			begin() { return std::stack<T>::c.begin(); }
	 reverse_iterator	rbegin() { return std::stack<T>::c.rbegin(); }
	 iterator			end() { return std::stack<T>::c.end(); }
	 reverse_iterator	rend() { return std::stack<T>::c.rend(); }
};

#endif  // MUTANTSTACK_HPP_
