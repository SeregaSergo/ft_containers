#include <iostream>
#include <type_traits>
#include "test.hpp"
#include <fstream>
#include "Logger.hpp"

#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];

    Buffer(void) : idx(0) {}

    Buffer(const char * str) {
        int i = 0;
        for (; str[i] != '\0'; ++i)
            buff[i] = str[i];
        buff[i] = '\0';
        idx = i;
    }

    Buffer(Buffer const & src) : idx(src.idx) {
        int i = 0;
        for (; i != idx; ++i)
            buff[i] = src.buff[i];
        buff[i] = '\0';
    }
};

std::ostream & operator<<(std::ostream & o, Buffer const & src) {
    if (src.idx > 0)
        o << src.buff;
    return (o);
}

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
    // std::ostream& out = std::cout;
    {
        out << "\n ***** default constructor check *****\n\n";
        out << "vector <int>:\n";
        vector<int> vec;
        printVector(vec, out);
        out << "\nvector <Buffer> with new():\n";
        vector<Buffer> * ptr_vec_buf = new vector<Buffer>;
        printVector(*ptr_vec_buf, out);
        delete ptr_vec_buf;
    }
    {
        out << "\n ***** fill constructor check *****\n\n";
        out << "zero size:\n";
        vector<int> vec1(0);
        printVector(vec1, out);
        out << "some size, no value:\n";
        vector<int> vec2(5);
        printVector(vec2, out);
        out << "some size and value:\n";
        vector<int> vec3(10, 5);
        printVector(vec3, out);
        out << "some size and value vector<Buffer>:\n";
        vector<Buffer> vec_buf(10, Buffer("hello world!"));
        printVector(vec_buf, out);
    }
    {
        out << "\n ***** copy constructor check *****\n\n";
        out << "vector <int>:\n";
        out << "original:\n";
        vector<int> vec1(10, 5);
        printVector(vec1, out);
        out << "coppied:\n";
        vector<int> vec2(vec1);
        printVector(vec2, out);

        out << "\nvector <Buffer>:\n";
        out << "original:\n";
        vector<Buffer> vec1_buf(10, Buffer("hello world!"));
        printVector(vec1_buf, out);
        out << "coppied:\n";
        vector<Buffer> vec2_buf(vec1_buf);
        printVector(vec2_buf, out);
    }
    {
        out << "\n ***** range constructor check *****\n\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        out << "original array:\n[1, 4, 6, -1, 10, 666, 111, 51]\n";
        out << "coppied:\n";
        vector<int> vec(&(arr[2]), &(arr[5]));
        printVector(vec, out);
    }
    {
        out << "\n ***** assigning operator check *****\n\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        out << "original:\n";
        vector<int> vec1(&(arr[2]), &(arr[7]));
        printVector(vec1, out);
        out << "assigned:\n";
        vector<int> vec2;
        vec2 = vec1;
        printVector(vec2, out);
    }
    {
        out << "\n *** iterator check ***\n";
        vector<int> vec(10, 5);
        for (vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
            out << *i  << ", ";
        out << '\n';

        vector<Buffer> vec1_buf(10, Buffer("hello world!"));
        for (vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
            out << *i  << ", ";
        out << '\n';
    }
    // vector<int> vec;
	// vec.push_back(3);
    // printVector< vector<int>, Logger >(vec, out);
	// vec.push_back(1);
    // printVector< vector<int>, Logger >(vec, out);
	// vec.push_back(6);
    // printVector< vector<int>, Logger >(vec, out);
	return 0;
}
