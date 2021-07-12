#include <vector>
#include <list>
#include <iostream>

int main() {
    std::vector<int> vec;
	std::cout << vec.capacity() << std::endl;
	vec.reserve(4444);
	std::cout << "After reserving 4444 bytes: " << vec.capacity() << std::endl;
	vec.reserve(18);
	std::cout << "After reserving 18 bytes: " << vec.capacity() << std::endl;
	return (0);
}
