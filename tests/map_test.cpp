#include "test.hpp"

void    test_map(std::ostream & out)
{
    {
        unsigned int start_time = clock();
        out << "\n ***** default constructor check *****\n\n";
        out << "map<int, std::string>:\n";
        map<int, std::string> m;
        printMap(m, out);
        out << "\nmap <int, Buffer> with new():\n";
        map<int, Buffer> * ptr_m = new map<int, Buffer>;
        printMap(*ptr_m, out);
        delete ptr_m;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** range constructor check *****\n\n";
        out << "map<int, std::string>:\n";
        map<int, std::string> m;
        printMap(m, out);
        out << "\nmap <int, Buffer> with new():\n";
        map<int, Buffer> * ptr_m = new map<int, Buffer>;
        printMap(*ptr_m, out);
        delete ptr_m;
        out << "Total time : " << clock() - start_time << std::endl;
    }
}