#include <vector>
#include <list>
#include <map>
#include <iostream>

class Test
{
private:
	std::vector<int> * _ptr;
public:
	Test() {
		_ptr = new std::vector<int>(10, 5);
		std::cout << "Default constructor of Test" << std::endl;
	}

	Test(Test const & src) {
		_ptr = new std::vector<int>(src.get_vec().begin(), src.get_vec().end());
		std::cout << "Copy constructor of Test" << std::endl;
	}

	Test & operator=(Test const & src) {
		delete _ptr;
		_ptr = new std::vector<int>(src.get_vec().begin(), src.get_vec().end());
		std::cout << "Assign operator of Test" << std::endl;
		return (*this);
	}

	~Test() {
		delete _ptr;
		std::cout << "Destructor of Test" << std::endl;
	}

	std::vector<int> const & get_vec(void) const {return (*_ptr);}
};

int main() {
    std::map<int, Test> map;
	std::cout << "now create Test:" << std::endl;
	Test	test;
	std::cout << "now insert:" << std::endl;
	map.insert(std::make_pair(1, test));
	std::cout << "now delete:" << std::endl;
	map.erase(1);
	std::cout << "now exit deletion:" << std::endl;
	return (0);
}
