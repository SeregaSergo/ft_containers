#include "test.hpp"

void    test_map(std::ostream & out)
{
    {
        unsigned int start_time = clock();
        out << "\n ***** default constructor check *****\n\n";
        out << "map<int, std::string>:\n";
        map<int, std::string> map;
        printMap(map, out);
        // out << "\nmap <int, Buffer> with new():\n";
        // map<int, Buffer> * ptr_map = new map<int, Buffer>;
        // printVector(*ptr_map, out);
        // delete ptr_map;
        out << "Total time : " << clock() - start_time << std::endl;
    }
}