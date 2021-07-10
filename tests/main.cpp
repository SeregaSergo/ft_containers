#include <iostream>
#include <type_traits>
#include "test.hpp"
#include <fstream>
#include "Logger.hpp"

void    printWelcome(Logger & outf)
{
    #ifdef STD_TEST_MY

        std::cout << "\n ***** STD Library *****\n" << std::endl;
        std::string filename = "./tests/output_std.txt";

    #else

        std::cout << "\n ***** My own library *****\n" << std::endl;
        std::string filename = "./tests/output_my.txt";

    #endif

    outf.open(filename);
}

int main()
{
    Logger out;
    printWelcome(out);
    {
        out << "\n *** default constructor check ***\n";
        vector<int> vec;
        printVector< vector<int>, Logger >(vec, out);
    }
    {
        out << "\n *** fill constructor check ***\n";
        vector<int> vec(10, 5);
        printVector< vector<int>, Logger >(vec, out);
    }
    {
        out << "\n *** copy constructor check ***\n";
        vector<int> vec1(10, 5);
        printVector< vector<int>, Logger >(vec1, out);
        vector<int> vec2(vec1);
        printVector< vector<int>, Logger >(vec2, out);
    }
    {
        out << "\n *** iterator check ***\n";
        vector<int> vec(10, 5);
        for (vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
            out << *i  << ", ";
        out << '\n';
    }
    vector<int> vec;
	vec.push_back(3);
    printVector< vector<int>, Logger >(vec, out);
	vec.push_back(1);
    printVector< vector<int>, Logger >(vec, out);
	vec.push_back(6);
    printVector< vector<int>, Logger >(vec, out);
	return 0;
}
