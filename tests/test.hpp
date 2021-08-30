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
using namespace std;

#else

#include "../containers/vector.hpp"
#include "../containers/map.hpp"
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

template < class V, class S>
void  printMap(V const & map, S & out)
{
    out << "Size: " << map.size() << '\n';
	
	typename V::const_iterator it;
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

#endif