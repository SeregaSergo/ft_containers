#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include "Logger.hpp"

#ifdef STD_TEST_MY

#include <vector>
using namespace std;

#else

#include "../vector.hpp"
using namespace ft;

#endif

template < class V, class S>
void  printVector(V const & vec, S & out)
{
    typename V::size_type i = 0;

    out << "Size: " << vec.size() << '\n';
    out << "Max size: " << vec.max_size() << '\n';
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
void  printVectorSTD(V const & vec, S & out)
{
    typename V::size_type i = 0;

    out << "Size: " << vec.size() << std::endl;
    out << "Max size: " << vec.max_size() << std::endl;
    out << "Capacity: " << vec.capacity() << std::endl;
    out << '[';
    if (vec.size() != 0)
    {
        for (; i != vec.size() - 1; ++i)
            out << vec[i] << ", ";
        out << vec[i];
    }
    out << "]\n--------------------------" << std::endl;
}

#endif