#include <iostream>
#include <type_traits>
#include "utils.hpp"
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
        out << "*** default constructor check ***\n";
        vector<int> vecstd;
        printVector< vector<int>, Logger >(vecstd, out);
    }
    {
        out << "*** fill constructor check ***\n";
        vector<int> vecstd(40, 5);
        printVector< vector<int>, Logger >(vecstd, out);
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
