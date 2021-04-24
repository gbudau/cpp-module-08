#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
 public:
	 MutantStack() {}
	 MutantStack(const MutantStack & src) : std::stack<T, Container>(src) {}
	 explicit MutantStack(const std::stack<T, Container> & src) :
												std::stack<T, Container>(src) {}
	 MutantStack &		operator=(const MutantStack &) {
							return *this;
	 					}
	 ~MutantStack() {}
	 typedef typename Container::iterator			iterator;
	 typedef typename Container::reverse_iterator	reverse_iterator;

	 iterator			begin() { return std::stack<T, Container>::c.begin(); }
	 reverse_iterator	rbegin() { return std::stack<T, Container>::c.rbegin(); }
	 iterator			end() { return std::stack<T, Container>::c.end(); }
	 reverse_iterator	rend() { return std::stack<T, Container>::c.rend(); }
};

#endif  // MUTANTSTACK_HPP_
