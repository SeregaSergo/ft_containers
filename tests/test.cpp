#include <vector>
#include <list>
#include <iostream>

int main() {
    int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
    std::vector<int> vec(&(arr[2]), &(arr[7]));
	std::vector<int>::reverse_iterator beg = vec.rbegin();
	std::vector<int>::reverse_iterator end = vec.rend();
	std::cout << end.base() - beg.base() << std::endl;
	return (0);
}
