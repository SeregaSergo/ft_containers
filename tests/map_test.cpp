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
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** range constructor check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
        pair<int, char const *> arrP[4];
        for (int i = 0; i != 4; ++i)
            arrP[i] = make_pair(arrI[i], arrS[i]);
        out << "map<int, char const *>:\n";
        map<int, char const *> m(arrP, &(arrP[4]));
        printMap(m, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** copy constructor check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
        pair<int, char const *> arrP[4];
        for (int i = 0; i != 4; ++i)
            arrP[i] = make_pair(arrI[i], arrS[i]);
        out << "map<int, char const *>:\n";
        map<int, char const *> map1(arrP, &(arrP[4]));
        map<int, char const *> map2(map1);
        printMap(map2, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** operator= check *****\n\n";

        int arrI1[] = {3, -1, 666, 13};
        char const * arrS1[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
        pair<int, char const *> arrP1[4];
        for (int i = 0; i != 4; ++i)
            arrP1[i] = make_pair(arrI1[i], arrS1[i]);
        map<int, char const *> map1(arrP1, &(arrP1[4]));

        int arrI2[] = {7, 18, -1300};
        char const * arrS2[] = {"seven", "+18", "my bank account"};
        pair<int, char const *> arrP2[3];
        for (int i = 0; i != 3; ++i)
            arrP2[i] = make_pair(arrI2[i], arrS2[i]);
        map<int, char const *> map2(arrP2, &(arrP2[3]));

        out << "First map<int, char const *>:\n";
        printMap(map1, out);
        
        out << "Second map<int, char const *>:\n";
        printMap(map2, out);

        out << "First map after operation <map1 = map2>:\n";
        map1 = map2;
        printMap(map1, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** iterators check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
        pair<int, char const *> arrP[4];
        for (int i = 0; i != 4; ++i)
            arrP[i] = make_pair(arrI[i], arrS[i]);
        arrP[2].first = 1;
        out << "map<int, char const *>:\n";
        map<int, char const *> m(arrP, &(arrP[4]));
        printMap(m, out);

        out << "After iterator traverse:\n";
        map<int, char const *>::iterator it;
        for (it = m.begin(); it != m.end(); ++it)
            (*it).second = "lol";
        
        printMap(m, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** const_iterators check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
        pair<int, char const *> arrP[4];
        for (int i = 0; i != 4; ++i)
            arrP[i] = make_pair(arrI[i], arrS[i]);
        arrP[2].first = 1;
        out << "CONST map<int, char const *>:\n";
        const map<int, char const *> m(arrP, &(arrP[4]));
        printMap(m, out);

        out << "Const_terator traverse:\n";
        map<int, char const *>::const_iterator it;
        for (it = m.begin(); it != m.end(); ++it)
            out << *it << ", ";
        
        out << "\nTime : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** reverse_iterators check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
        pair<int, char const *> arrP[4];
        for (int i = 0; i != 4; ++i)
            arrP[i] = make_pair(arrI[i], arrS[i]);
        arrP[2].first = 1;
        out << "map<int, char const *>:\n";
        map<int, char const *> m(arrP, &(arrP[4]));
        printMap(m, out);

        out << "Reverse_iterator traverse:\n";
        map<int, char const *>::reverse_iterator it;
        for (it = m.rbegin(); it != m.rend(); ++it)
        {
            (*it).second = "lol";
            out << "[" << (*it).first << ", " << (*it).second << "], ";
        }
        out << "\n";

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** empty member-function check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
        pair<int, char const *> arrP[4];
        for (int i = 0; i != 4; ++i)
            arrP[i] = make_pair(arrI[i], arrS[i]);
        
        out << "empty map: ";
        map<int, char const *> map1;
        if (map1.empty())
            out << "true\n";
        else
            out << "false\n";
        
        out << "not empty map: ";
        map<int, char const *> map2(arrP, &(arrP[4]));
        if (map2.empty())
            out << "true\n";
        else
            out << "false\n";

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** max_size member-function check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
        pair<int, char const *> arrP[4];
        for (int i = 0; i != 4; ++i)
            arrP[i] = make_pair(arrI[i], arrS[i]);
        map<int, char const *> map(arrP, &(arrP[4]));
        out << "Max size: " << map.max_size();
        out << "\nTime : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** operator[] check *****\n\n";

        int arrI[] = {3, -1, 666, 13};
        char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
        pair<int, char const *> arrP[4];
        for (int i = 0; i != 4; ++i)
            arrP[i] = make_pair(arrI[i], arrS[i]);
        map<int, char const *> map(arrP, &(arrP[4]));

        out << "Accessing to an existing element (-1):\n";
        map[-1] = "PLUS ONE";
        printMap(map, out);

        out << "Accessing to a nonexisten element (-99):\n";
        map[-99] = "Problems";
        printMap(map, out);

        out << "Accessing to an existen element (-99):\n";
        out << "element is " << map[-99] << "\n";
        printMap(map, out);
    
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** Single insertion check *****\n\n";

        map<int, char const *> m;
        pair<map<int, char const *>::iterator, bool> ret;
        map<int, char const *>::iterator  it;

        ret = m.insert(make_pair(-1, "minus one"));
        out << "Element is inserted: " << (ret.second ? "true" : "false") << "\n";
        out << "Element value: " << *(ret.first) << "\n";
        printMap(m, out);

        out << "Double insertion check:\n";
        ret = m.insert(make_pair(-1, "minus one"));
        out << "Element is inserted: " << (ret.second ? "true" : "false") << "\n";
        out << "Element value: " << *ret.first << "\n";
        printMap(m, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** Ordered insertion with hint check *****\n\n";

        map<int, char const *> m;
        map<int, char const *>::iterator  it = m.begin();

        int arrI[] = {-99, -1, 3, 13, 666};
        char const * arrS[] = {"problems", "minus one", "saint num", "Baker's dozen", "number of beast"};

        for (int i = 0; i != 5; ++i)
            it = m.insert(it, make_pair(arrI[i], arrS[i]));

        printMap(m, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** Ordered insertion with hint (LARGE) check *****\n\n";

        map<int, int> m;
        map<int, int>::iterator  it = m.begin();

        for (int i = 0; i != 10000; ++i)
            it = m.insert(it, make_pair(i, i));

        printMap(m, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** Unordered insertion with hint check *****\n\n";

        map<int, char const *> m;

        int arrI[] = {3, -1, -99, 666, 13};
        char const * arrS[] = {"saint num", "minus one", "problems", "number of beast", "Baker's dozen"};

        for (int i = 0; i != 5; ++i)
            m.insert(m.begin(), make_pair(arrI[i], arrS[i]));
    
        printMap(m, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** Unordered insertion with hint (LARGE) check *****\n\n";

        map<int, int> m;

        for (int i = 0; i != 10000; ++i)
            m.insert(m.begin(), make_pair(i, i));
    
        printMap(m, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Range insertions check *****\n\n";

        map<int, int> m;
        vector<pair<int, int> > vec;

        for (int i = 0; i != 10000; ++i)
            vec.push_back(make_pair(i, i));

        unsigned int start_time = clock();

        m.insert(vec.begin(), vec.end());
        printMap(m, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** Deletion by key check *****\n\n";

        int arrI[] = {3, -1, -99, 666, 100, 13, -18, 18, -100, -999};
        char const * arrS[] = {"saint num", "minus one", "problems", "number of beast", "hundred", "Baker's dozen", "-18", "+18", "-100", "-999"};
        pair<int, char const *> arrP[10];
        for (int i = 0; i != 10; ++i)
            arrP[i] = make_pair(arrI[i], arrS[i]);

        out << "map<int, char const *>:\n";
        map<int, char const *> m(arrP, &(arrP[10]));
        printMap(m, out);

        out << "After deletion of -99, 666:\n";
        out << "Deleted: " << (m.erase(-99) ? "true" : "false") << "\n";
        out << "Deleted: " << (m.erase(666) ? "true" : "false") << "\n";
        printMap(m, out);

        out << "After deletion of nonexistent number: \n";
        out << "Deleted: " << (m.erase(1739827) ? "true" : "false") << "\n";
        printMap(m, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Deletion with iterator check *****\n\n";

        map<int, char const *> map;
        map[3] = "saint num";
        map[-1] = "minus one";
        map[-99] = "problems";
        map[666] = "number of beast";
        map[13] = "Baker's dozen";

        out << "map<int, char const *>:\n";
        printMap(map, out);

        unsigned int start_time = clock();

        out << "After deletion of (++begin):\n";
        map.erase(++(map.begin()));
        printMap(map, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Range deletions with iterators check *****\n\n";

        map<int, char const *> map;
        map[3] = "saint num";
        map[-1] = "minus one";
        map[-99] = "problems";
        map[666] = "number of beast";
        map[13] = "Baker's dozen";

        out << "map<int, char const *>:\n";
        printMap(map, out);

        unsigned int start_time = clock();

        out << "After deletion from (++begin) to (--end):\n";
        map.erase(++map.begin(), --map.end());
        printMap(map, out);

        out << "After deletion from (begin) to (end):\n";
        map.erase(map.begin(), map.end());
        printMap(map, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** swap check *****\n\n";

        map<int, char const *> map1;
        map1[3] = "saint num";
        map1[-1] = "minus one";
        map1[666] = "number of beast";
        map1[13] = "Baker's dozen";

        map<int, char const *> map2;
        map2[7] = "seven";
        map2[18] = "+18";
        map2[-1300] = "my bank account";

        out << "First map<int, char const *>:\n";
        printMap(map1, out);
        
        out << "Second map<int, char const *>:\n";
        printMap(map2, out);

        unsigned int start_time = clock();

        out << "map1 after swap:\n";
        map1.swap(map2);
        printMap(map1, out);

        out << "map2 after swap:\n";
        printMap(map2, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Clear check *****\n\n";

        map<int, char const *> map;
        map[3] = "saint num";
        map[-1] = "minus one";
        map[-99] = "problems";
        map[666] = "number of beast";
        map[13] = "Baker's dozen";

        printMap(map, out);
        
        out << "map after clearing:\n";
        unsigned int start_time = clock();
        map.clear();
        printMap(map, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** key_comp check *****\n\n";

        map<int, char const *> m;
        map<int, char const *>::key_compare comp = m.key_comp();
        m[3] = "saint num";
        m[-1] = "minus one";
        m[-99] = "problems";
        m[666] = "number of beast";
        m[13] = "Baker's dozen";

        printMap(m, out);
        unsigned int start_time = clock();

        out << "compare(first elem, last elem) = " << comp((*m.begin()).first, (*(--m.end())).first) << "\n"; 

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** value_comp check *****\n\n";

        map<int, char const *> m;
        map<int, char const *>::value_compare comp = m.value_comp();
        m[3] = "saint num";
        m[-1] = "minus one";
        m[-99] = "problems";
        m[666] = "number of beast";
        m[13] = "Baker's dozen";

        printMap(m, out);
        unsigned int start_time = clock();

        out << "compare(first elem, last elem) = " << comp(*m.begin(), *(--m.end())) << "\n"; 

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** find check *****\n\n";

        map<int, char const *> m;
        m[3] = "saint num";
        m[-1] = "minus one";
        m[-99] = "problems";
        m[666] = "number of beast";
        m[13] = "Baker's dozen";

        printMap(m, out);
        unsigned int start_time = clock();

        out << "Looking for existing element(3) = " << *m.find(3) << "\n";

        map<int, char const *>::iterator it = m.find(1234);
        out << "Looking for nonexisting element(1234) = " << (it == m.end() ? "end" : to_string(*it)) << "\n";

        out << "Looking for existing element and and changing it:\n";
        (*m.find(3)).second = "KEK LOL";
        printMap(m, out);

        out << "Looking for existing element and changing it:\n";
        map<int, char const *>::const_iterator iter = m.find(-1);
        out << *iter << "\n";
        printMap(m, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** count check *****\n\n";

        map<int, char const *> m;
        m[3] = "saint num";
        m[-1] = "minus one";
        m[-99] = "problems";
        m[666] = "number of beast";
        m[13] = "Baker's dozen";

        printMap(m, out);
        unsigned int start_time = clock();

        out << "Looking for existing element(3) = " << m.count(3) << "\n";

        out << "Looking for nonexisting element(1234) = " << m.count(1234) << "\n";

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** lower_bound && upper_bound check *****\n\n";

        map<int, char const *> m;
        map<int, char const *>::iterator it;
        map<int, char const *>::const_iterator const_it;
        m[3] = "saint num";
        m[-1] = "minus one";
        m[-99] = "problems";
        m[666] = "number of beast";
        m[13] = "Baker's dozen";
        m[7] = "seven";
        m[18] = "+18";
        m[-1300] = "my bank account";

        const map<int, char const *> const_m(m);

        printMap(m, out);
        unsigned int start_time = clock();

        out << "Lower_bound of 3 = " << *(m.lower_bound(3)) << "\n";
        out << "Lower_bound of -1300 = " << *(m.lower_bound(-1300)) << "\n";
        out << "Lower_bound of -1200 = " << *(m.lower_bound(-1200)) << "\n";
        out << "Lower_bound of -1600 = " << *(m.lower_bound(-1600)) << "\n\n";
        
        out << "Upper_bound of 3 = " << *(m.upper_bound(3)) << "\n";
        out << "Upper_bound of -1300 = " << *(m.upper_bound(-1300)) << "\n";
        out << "Upper_bound of -1600 = " << *(m.upper_bound(-1600)) << "\n";
        it = m.upper_bound(1000);
        out << "Upper_bound of 1000 = " << (it == m.end() ? "end" : to_string(*it)) << "\n\n";

        out << "Const lower_bound of 3 = " << *(const_m.lower_bound(3)) << "\n";
        out << "Const_lower_bound of -1300 = " << *(const_m.lower_bound(-1300)) << "\n\n";
        
        out << "Const_upper_bound of 3 = " << *(const_m.upper_bound(3)) << "\n";
        const_it = const_m.upper_bound(1000);
        out << "Const_upper_bound of 1000 = " << (const_it == const_m.end() ? "end" : to_string(*it)) << "\n";

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** equal_range check *****\n\n";

        map<int, char const *> m;
        pair< map<int, char const *>::iterator, map<int, char const *>::iterator> ret;
        pair< map<int, char const *>::const_iterator, map<int, char const *>::const_iterator> const_ret;
        m[3] = "saint num";
        m[-1] = "minus one";
        m[666] = "number of beast";
        m[7] = "seven";
        m[18] = "+18";

        const map<int, char const *> const_m(m);

        printMap(m, out);
        unsigned int start_time = clock();

        out << "equal_range of 3:\n";
        ret = m.equal_range(3);
        out << "Lower_bound = " << *(ret.first) << "\n";
        out << "Upper_bound = " << *(ret.second) << "\n\n";

        out << "equal_range of 90:\n";
        ret = m.equal_range(90);
        out << "Lower_bound = " << *(ret.first) << "\n";
        out << "Upper_bound = " << *(ret.second) << "\n\n";

        out << "const equal_range of 3:\n";
        const_ret = const_m.equal_range(3);
        out << "Lower_bound = " << *(const_ret.first) << "\n";
        out << "Upper_bound = " << *(const_ret.second) << "\n";

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** equal_range check *****\n\n";

        map<int, char const *> m;
        pair<const int, char const *> * ptr;
        int size;

        unsigned int start_time = clock();

        ptr = m.get_allocator().allocate(5);
        
        size = sizeof(map<int, char const *>::value_type) * 5;

        out << "The allocated array has a size of " << size << " bytes.\n";

        m.get_allocator().deallocate(ptr, 5);

        out << "Time : " << clock() - start_time << std::endl;
    }
}