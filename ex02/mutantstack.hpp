#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
 public:
	MutantStack() {}
	MutantStack(const MutantStack & src) : std::stack<T, Container>(src) {}
	MutantStack &		operator=(const MutantStack & src) {
		if (this != &src) {
			std::stack<T, Container>::c = src.std::stack<T, Container>::c;
		}
		return *this;
	}
	~MutantStack() {}

	typedef typename Container::iterator				iterator;
	typedef typename Container::const_iterator			const_iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;
	typedef typename Container::const_reverse_iterator	const_reverse_iterator;

	iterator			begin() {
		return std::stack<T, Container>::c.begin();
	}

	iterator			end() {
	    return std::stack<T, Container>::c.end();
	}

	const_iterator		begin() const {
		return std::stack<T, Container>::c.begin();
	}

	const_iterator		end() const {
		return std::stack<T, Container>::c.end();
	}

	reverse_iterator	rbegin() {
		return std::stack<T, Container>::c.rbegin();
	}

	reverse_iterator	rend() {
		return std::stack<T, Container>::c.rend();
	}

	const_reverse_iterator	rbegin() const {
		return std::stack<T, Container>::c.rbegin();
	}

	const_reverse_iterator	rend() const {
		return std::stack<T, Container>::c.rend();
	}
};

#endif  // MUTANTSTACK_HPP_
