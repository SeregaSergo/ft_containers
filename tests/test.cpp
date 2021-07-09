#include <vector>
#include <list>
#include <iostream>
#include "vector.hpp"
int main() {
    std::vector<int> vec(10, 5);
	std::vector<int>::iterator end = vec.end() - 1;
    for (std::vector<int>::iterator i = vec.begin(); i != end; ++i)
	{
		std::cout << ' ' << i->;
		//std::vector<int>::iterator n = i;
		//*n = 10;
	}
	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
		std::cout << ' ' << *i;
	std::cout << std::endl;
	return (0);
}
