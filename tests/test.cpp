// #include <vector>
// #include <list>
// #include <map>
#include <iostream>
#include <array>
#include "../containers/utils/utils.hpp"
#include "../containers/map.hpp"
using namespace ft;
// class Test
// {
// private:
// 	std::vector<int> * _ptr;
// public:
// 	Test() {
// 		_ptr = new std::vector<int>(10, 5);
// 		std::cout << "Default constructor of Test" << std::endl;
// 	}

// 	Test(Test const & src) {
// 		_ptr = new std::vector<int>(src.get_vec().begin(), src.get_vec().end());
// 		std::cout << "Copy constructor of Test" << std::endl;
// 	}

// 	Test & operator=(Test const & src) {
// 		delete _ptr;
// 		_ptr = new std::vector<int>(src.get_vec().begin(), src.get_vec().end());
// 		std::cout << "Assign operator of Test" << std::endl;
// 		return (*this);
// 	}

// 	~Test() {
// 		delete _ptr;
// 		std::cout << "Destructor of Test" << std::endl;
// 	}

// 	std::vector<int> const & get_vec(void) const {return (*_ptr);}
// };

int main() {
    map<int, int> map;
	std::cout << "now create Test:" << std::endl;
	std::cout << "now insert:" << std::endl;
	int arrI[] = {1, -1, 10, 666, 3, 13};
	char const * arrS[] = {"one", "minus one", "ten", "number of beast", "saint num", "Baker's dozen"};
	pair<int, char const *> arrP[6];
	for (int i = 0; i != 6; ++i)
	{
		arrP[i] = make_pair(arrI[i], arrS[i]);
	}
	map.insert(make_pair(1, 2));
	std::cout << "now delete:" << std::endl;
	// map.erase(map.end());
	std::cout << "now exit deletion:" << std::endl;
	return (0);
}

