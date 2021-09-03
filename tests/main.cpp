#include <iostream>
#include <type_traits>
#include "test.hpp"
#include <fstream>


Buffer::Buffer(void) : idx(0) {}

Buffer::Buffer(const char * str) {
    int i = 0;
    for (; str[i] != '\0'; ++i)
        buff[i] = str[i];
    buff[i] = '\0';
    idx = i;
}

Buffer::Buffer(Buffer const & src) : idx(src.idx) {
    int i = 0;
    for (; i != idx; ++i)
        buff[i] = src.buff[i];
    buff[i] = '\0';
}

Buffer & Buffer::operator=(Buffer const & src) {
    idx = src.idx;
    for (int i = 0; i != idx; ++i)
        buff[i] = src.buff[i];
    buff[idx] = '\0';
    return (*this);
}

std::ostream & operator<<(std::ostream & o, Buffer const & src) {
    if (src.idx > 0)
        o << src.buff;
    return (o);
}

void    printWelcome(std::ofstream & outf)
{
    #ifdef STD_TEST

        outf.open("./results/output_std.txt");
        outf << "\n ***** STD Library *****\n" << std::endl;

    #else

        outf.open("./results/output_my.txt");
        outf << "\n ***** My own library *****\n" << std::endl;

    #endif
}

void    test_vector(std::ostream & out);

int main()
{
    unsigned int start_time;
    #ifndef DEBUG_TERM
        std::ofstream out;
        printWelcome(out);
    #else
        std::ostream & out = std::cout;
    #endif

    out << " *******        *******\n";
    out << " ******* VECTOR *******\n";
    out << " *******        *******\n";

    start_time =  clock();
    test_vector(out);
    out << "Total time : " << clock() - start_time << std::endl;

    out << "\n\n";
    out << " *******         *******\n";
    out << " *******   MAP   *******\n";
    out << " *******         *******\n";

    start_time =  clock();
    test_map(out);
    out << "Total time : " << clock() - start_time << std::endl;

    out << "\n\n";
    out << " *******         *******\n";
    out << " *******  STACK  *******\n";
    out << " *******         *******\n";

    start_time =  clock();
    test_stack(out);
    out << "Total time : " << clock() - start_time << std::endl;

    out << "\n\n";
    out << " *******         *******\n";
    out << " *******   SET   *******\n";
    out << " *******         *******\n";

    start_time =  clock();
    test_set(out);
    out << "Total time : " << clock() - start_time << std::endl;

	return 0;
}
