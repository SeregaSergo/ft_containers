// #include <vector>
// #include <list>
// #include <map>
#include <iostream>
#include <array>
#include <stack>
#include <vector>
#include "../containers/utils/utils.hpp"
#include "../containers/map.hpp"
// using namespace ft;

template <class T, class C>
void	printStack(std::stack<T, C > & s)
{
	std::cout << "Stack:" << std::endl;
	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
}

int main() {
	std::vector<int> vec(5, 13);
	std::stack<int, std::vector<int> > s1(vec);
	s1.push(1);
	printStack(s1);
	return (0);
}

