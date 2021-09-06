#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <memory>

#ifdef STD_TEST

#include <utility>
#include <vector>
#include <map>
#include <stack>
#include <set>
using namespace std;

#else

// #include "../containers/vector.hpp"
// #include "../containers/map.hpp"
// #include "../containers/stack.hpp"
// #include "../containers/set.hpp"
#include "../containers/utils/utils.hpp"
using namespace ft;

#endif

#define BUF_SIZE_CONST 4096

struct Buffer
{
	int idx;
	char buff[BUF_SIZE_CONST];

    Buffer(void);
    Buffer(const char * str);
    Buffer(Buffer const & src);
    Buffer & operator=(Buffer const & src);
};

std::ostream & operator<<(std::ostream & o, Buffer const & src);

template <class T1, class T2>
std::ostream & operator<<(std::ostream & o, pair<T1, T2> const & src) {
    o << "[" << src.first << ", " << src.second << "]";
    return (o);
}

template <typename T>
std::string to_string(T smth)
{
    std::ostringstream ss;
    ss << smth;
    return (ss.str());
}

void    test_vector(std::ostream & out);
void    test_map(std::ostream & out);
void    test_stack(std::ostream & out);
void    test_set(std::ostream & out);

template < class V, class S>
void  printVector(V const & vec, S & out)
{
    typename V::size_type i = 0;

    out << "Size: " << vec.size() << '\n';
    out << "Capacity: " << vec.capacity() << "\n[";
    if (vec.size() != 0)
    {
        for (; i != vec.size() - 1; ++i)
            out << vec[i] << ", ";
        out << vec[i];
    }
    out << "]\n--------------------------\n";
}

template < class M, class S>
void  printMap(M const & map, S & out)
{
    out << "Size: " << map.size() << '\n';
	
	typename M::const_iterator it;
	for (it = map.begin(); it != map.end(); ++it)
	{
		out << "[";
		out << (*it).first;
		out << ", ";
		out << (*it).second;
		out << "] ";
	}
	out << "\n----------------------------------\n";
}

template < class St, class S>
void	printStack(St & s, S & out)
{
	out << "Size: " << s.size() << '\n';
	while (!s.empty()) {
		out << "[" << s.top() << "] ";
		s.pop();
	}
    out << "\n----------------------------------\n";
}

template < class Set, class S>
void  printSet(Set const & set, S & out)
{
    out << "Size: " << set.size() << '\n';
	
	typename Set::const_iterator it;
	for (it = set.begin(); it != set.end(); ++it)
		out << "[" << *it << "] ";
	out << "\n----------------------------------\n";
}

#endif