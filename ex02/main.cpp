#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include "mutantstack.hpp"

void	test_subject_mutantstack() {
	std::cout << "##### Tests from subject #####\n";
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Stack size = " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "\nPrint and pop MutantStack copy\n";
	while (!s.empty()) {
		std::cout << s.top() << "\n";
		s.pop();
	}
}

void	test_subject_list() {
	std::cout << "\n##### Tests from subject with std::list #####\n";
	std::list<int>	l;

	l.push_back(5);
	l.push_back(17);

	std::cout << l.back() << "\n";

	l.pop_back();

	std::cout << "List size = " << l.size() << "\n";
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);

	std::list<int>::iterator it = l.begin();
	std::list<int>::iterator ite = l.end();

	++it;
	--it;

	while (it != ite) {
		std::cout << *it << "\n";
		++it;
	}
}

void	test_reverse_iterator() {
	MutantStack<int>	mstack;

	std::cout << "\n##### Test MutantStack reverse iterators #####\n";
	mstack.push(19);
	mstack.push(21);
	mstack.push(42);
	mstack.push(0);
	std::cout <<
			"Value at the top of the MutantStack = " << mstack.top() << "\n";
	mstack.pop();

	MutantStack<int>::reverse_iterator it_r = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite_r = mstack.rend();

	std::cout << "\nReverse print\n";
	while(it_r != ite_r) {
		std::cout << *it_r << std::endl;
		++it_r;
	}
}

void	test_assign_operator() {
	MutantStack<int>	mstack;

	std::cout <<
				"\n##### Test copy constructor and assignment operator #####\n";
	mstack.push(19);
	mstack.push(21);
	mstack.push(42);

	MutantStack<int>	mstack_copy(mstack);

	mstack_copy.push(1337);

	MutantStack<int>	mstack_assign = mstack_copy;

	MutantStack<int>::iterator it = mstack_assign.begin();
	MutantStack<int>::iterator ite = mstack_assign.end();

	while (it != ite) {
		std::cout << *it << "\n";
		it++;
	}
}

void	test_with_other_underlying_container() {
	MutantStack<int, std::vector<int> > mstack_v;

	std::cout <<
	"\n##### Test MutantStack with std:vector as underlying container #####\n";
	mstack_v.push(42);
	std::cout << mstack_v.top() << "\n";
	mstack_v.pop();
	std::cout << "\n";
	mstack_v.push(21);
	mstack_v.push(19);

	MutantStack<int, std::vector<int> >::iterator it = mstack_v.begin();
	MutantStack<int, std::vector<int> >::iterator ite = mstack_v.end();

	while (it != ite) {
		std::cout << *it << "\n";
		it++;
	}
}

int main() {
	test_subject_mutantstack();
	test_subject_list();
	test_reverse_iterator();
	test_assign_operator();
	test_with_other_underlying_container();
}
