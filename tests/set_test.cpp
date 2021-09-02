#include "test.hpp"

void    test_set(std::ostream & out)
{
    {
        out << "\n ***** default constructor check *****\n\n";
        out << "set<int>:\n";
        unsigned int start_time = clock();
        set<int> s;
        printSet(s, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** range constructor check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        out << "set<int>:\n";
        unsigned int start_time = clock();
        set<int> s(arrI, &(arrI[4]));
        printSet(s, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** copy constructor check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        set<int> set1(arrI, &(arrI[4]));
        out << "First set<int>:\n";
        printSet(set1, out);
        unsigned int start_time = clock();
        set<int> set2(set1);
        out << "Second set<int>:\n";
        printSet(set2, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** operator= check *****\n\n";

        int arrI1[] = {3, -1, 666, 13};
        set<int> set1(arrI1, &(arrI1[4]));

        int arrI2[] = {7, 18, -1300};
        set<int> set2(arrI2, &(arrI2[3]));

        out << "First set<int>:\n";
        printSet(set1, out);
        
        out << "Second set<int>:\n";
        printSet(set2, out);

        out << "First set after operation <set1 = set2>:\n";
        unsigned int start_time = clock();
        set1 = set2;
        printSet(set1, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** iterators check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        out << "set<int>:\n";
        set<int> s(arrI, &(arrI[4]));
        printSet(s, out);
        unsigned int start_time = clock();

        out << "After iterator traverse:\n";
        set<int>::iterator it;
        for (it = s.begin(); it != s.end(); ++it)
            out << "[" << *it << "] ";

        out << "\nTime : " << clock() - start_time << std::endl;
    }
    // {
    //     unsigned int start_time = clock();
    //     out << "\n ***** const_iterators check *****\n\n";
    //     int arrI[] = {3, -1, 666, 13};
    //     char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
    //     pair<int, char const *> arrI[4];
    //     for (int i = 0; i != 4; ++i)
    //         arrI[i] = make_pair(arrI[i], arrS[i]);
    //     arrI[2].first = 1;
    //     out << "CONST set<int>:\n";
    //     const set<int> m(arrI, &(arrI[4]));
    //     printSet(m, out);

    //     out << "Const_terator traverse:\n";
    //     set<int>::const_iterator it;
    //     for (it = m.begin(); it != m.end(); ++it)
    //         out << *it << ", ";
        
    //     out << "\nTime : " << clock() - start_time << std::endl;
    // }
    // {
    //     unsigned int start_time = clock();
    //     out << "\n ***** reverse_iterators check *****\n\n";
    //     int arrI[] = {3, -1, 666, 13};
    //     char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
    //     pair<int, char const *> arrI[4];
    //     for (int i = 0; i != 4; ++i)
    //         arrI[i] = make_pair(arrI[i], arrS[i]);
    //     arrI[2].first = 1;
    //     out << "set<int>:\n";
    //     set<int> m(arrI, &(arrI[4]));
    //     printSet(m, out);

    //     out << "Reverse_iterator traverse:\n";
    //     set<int>::reverse_iterator it;
    //     for (it = m.rbegin(); it != m.rend(); ++it)
    //     {
    //         (*it).second = "lol";
    //         out << "[" << (*it).first << ", " << (*it).second << "], ";
    //     }
    //     out << "\n";

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     unsigned int start_time = clock();
    //     out << "\n ***** empty member-function check *****\n\n";
    //     int arrI[] = {3, -1, 666, 13};
    //     char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
    //     pair<int, char const *> arrI[4];
    //     for (int i = 0; i != 4; ++i)
    //         arrI[i] = make_pair(arrI[i], arrS[i]);
        
    //     out << "empty set: ";
    //     set<int> set1;
    //     if (set1.empty())
    //         out << "true\n";
    //     else
    //         out << "false\n";
        
    //     out << "not empty set: ";
    //     set<int> set2(arrI, &(arrI[4]));
    //     if (set2.empty())
    //         out << "true\n";
    //     else
    //         out << "false\n";

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     unsigned int start_time = clock();
    //     out << "\n ***** max_size member-function check *****\n\n";
    //     int arrI[] = {3, -1, 666, 13};
    //     char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
    //     pair<int, char const *> arrI[4];
    //     for (int i = 0; i != 4; ++i)
    //         arrI[i] = make_pair(arrI[i], arrS[i]);
    //     set<int> set(arrI, &(arrI[4]));
    //     out << "Max size: " << set.max_size();
    //     out << "\nTime : " << clock() - start_time << std::endl;
    // }
    // {
    //     unsigned int start_time = clock();
    //     out << "\n ***** operator[] check *****\n\n";

    //     int arrI[] = {3, -1, 666, 13};
    //     char const * arrS[] = {"saint num", "minus one", "number of beast", "Baker's dozen"};
    //     pair<int, char const *> arrI[4];
    //     for (int i = 0; i != 4; ++i)
    //         arrI[i] = make_pair(arrI[i], arrS[i]);
    //     set<int> set(arrI, &(arrI[4]));

    //     out << "Accessing to an existing element (-1):\n";
    //     set[-1] = "PLUS ONE";
    //     printSet(set, out);

    //     out << "Accessing to a nonexisten element (-99):\n";
    //     set[-99] = "Problems";
    //     printSet(set, out);

    //     out << "Accessing to an existen element (-99):\n";
    //     out << "element is " << set[-99] << "\n";
    //     printSet(set, out);
    
    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     unsigned int start_time = clock();
    //     out << "\n ***** Single insertion check *****\n\n";

    //     set<int> m;
    //     pair<set<int>::iterator, bool> ret;
    //     set<int>::iterator  it;

    //     ret = m.insert(make_pair(-1, "minus one"));
    //     out << "Element is inserted: " << (ret.second ? "true" : "false") << "\n";
    //     out << "Element value: " << *(ret.first) << "\n";
    //     printSet(m, out);

    //     out << "Double insertion check:\n";
    //     ret = m.insert(make_pair(-1, "minus one"));
    //     out << "Element is inserted: " << (ret.second ? "true" : "false") << "\n";
    //     out << "Element value: " << *ret.first << "\n";
    //     printSet(m, out);

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     unsigned int start_time = clock();
    //     out << "\n ***** Ordered insertion with hint check *****\n\n";

    //     set<int> m;
    //     set<int>::iterator  it = m.begin();

    //     int arrI[] = {-99, -1, 3, 13, 666};
    //     char const * arrS[] = {"problems", "minus one", "saint num", "Baker's dozen", "number of beast"};

    //     for (int i = 0; i != 5; ++i)
    //         it = m.insert(it, make_pair(arrI[i], arrS[i]));

    //     printSet(m, out);
    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     unsigned int start_time = clock();
    //     out << "\n ***** Ordered insertion with hint (LARGE) check *****\n\n";

    //     set<int, int> m;
    //     set<int, int>::iterator  it = m.begin();

    //     for (int i = 0; i != 10000; ++i)
    //         it = m.insert(it, make_pair(i, i));

    //     printSet(m, out);
    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     unsigned int start_time = clock();
    //     out << "\n ***** Unordered insertion with hint check *****\n\n";

    //     set<int> m;

    //     int arrI[] = {3, -1, -99, 666, 13};
    //     char const * arrS[] = {"saint num", "minus one", "problems", "number of beast", "Baker's dozen"};

    //     for (int i = 0; i != 5; ++i)
    //         m.insert(m.begin(), make_pair(arrI[i], arrS[i]));
    
    //     printSet(m, out);
    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     unsigned int start_time = clock();
    //     out << "\n ***** Unordered insertion with hint (LARGE) check *****\n\n";

    //     set<int, int> m;

    //     for (int i = 0; i != 10000; ++i)
    //         m.insert(m.begin(), make_pair(i, i));
    
    //     printSet(m, out);
    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** Range insertions check *****\n\n";

    //     set<int, int> m;
    //     vector<pair<int, int> > vec;

    //     for (int i = 0; i != 10000; ++i)
    //         vec.push_back(make_pair(i, i));

    //     unsigned int start_time = clock();

    //     m.insert(vec.begin(), vec.end());
    //     printSet(m, out);

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     unsigned int start_time = clock();
    //     out << "\n ***** Deletion by key check *****\n\n";

    //     int arrI[] = {3, -1, -99, 666, 100, 13, -18, 18, -100, -999};
    //     char const * arrS[] = {"saint num", "minus one", "problems", "number of beast", "hundred", "Baker's dozen", "-18", "+18", "-100", "-999"};
    //     pair<int, char const *> arrI[10];
    //     for (int i = 0; i != 10; ++i)
    //         arrI[i] = make_pair(arrI[i], arrS[i]);

    //     out << "set<int>:\n";
    //     set<int> m(arrI, &(arrI[10]));
    //     printSet(m, out);

    //     out << "After deletion of -99, 666:\n";
    //     out << "Deleted: " << (m.erase(-99) ? "true" : "false") << "\n";
    //     out << "Deleted: " << (m.erase(666) ? "true" : "false") << "\n";
    //     printSet(m, out);

    //     out << "After deletion of nonexistent number: \n";
    //     out << "Deleted: " << (m.erase(1739827) ? "true" : "false") << "\n";
    //     printSet(m, out);

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** Deletion with iterator check *****\n\n";

    //     set<int> set;
    //     set[3] = "saint num";
    //     set[-1] = "minus one";
    //     set[-99] = "problems";
    //     set[666] = "number of beast";
    //     set[13] = "Baker's dozen";

    //     out << "set<int>:\n";
    //     printSet(set, out);

    //     unsigned int start_time = clock();

    //     out << "After deletion of (++begin):\n";
    //     set.erase(++(set.begin()));
    //     printSet(set, out);

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** Range deletions with iterators check *****\n\n";

    //     set<int> set;
    //     set[3] = "saint num";
    //     set[-1] = "minus one";
    //     set[-99] = "problems";
    //     set[666] = "number of beast";
    //     set[13] = "Baker's dozen";

    //     out << "set<int>:\n";
    //     printSet(set, out);

    //     unsigned int start_time = clock();

    //     out << "After deletion from (++begin) to (--end):\n";
    //     set.erase(++set.begin(), --set.end());
    //     printSet(set, out);

    //     out << "After deletion from (begin) to (end):\n";
    //     set.erase(set.begin(), set.end());
    //     printSet(set, out);

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** swap check *****\n\n";

    //     set<int> set1;
    //     set1[3] = "saint num";
    //     set1[-1] = "minus one";
    //     set1[666] = "number of beast";
    //     set1[13] = "Baker's dozen";

    //     set<int> set2;
    //     set2[7] = "seven";
    //     set2[18] = "+18";
    //     set2[-1300] = "my bank account";

    //     out << "First set<int>:\n";
    //     printSet(set1, out);
        
    //     out << "Second set<int>:\n";
    //     printSet(set2, out);

    //     unsigned int start_time = clock();

    //     out << "set1 after swap:\n";
    //     set1.swap(set2);
    //     printSet(set1, out);

    //     out << "set2 after swap:\n";
    //     printSet(set2, out);

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** Clear check *****\n\n";

    //     set<int> set;
    //     set[3] = "saint num";
    //     set[-1] = "minus one";
    //     set[-99] = "problems";
    //     set[666] = "number of beast";
    //     set[13] = "Baker's dozen";

    //     printSet(set, out);
        
    //     out << "set after clearing:\n";
    //     unsigned int start_time = clock();
    //     set.clear();
    //     printSet(set, out);

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** key_comp check *****\n\n";

    //     set<int> m;
    //     set<int>::key_compare comp = m.key_comp();
    //     m[3] = "saint num";
    //     m[-1] = "minus one";
    //     m[-99] = "problems";
    //     m[666] = "number of beast";
    //     m[13] = "Baker's dozen";

    //     printSet(m, out);
    //     unsigned int start_time = clock();

    //     out << "compare(first elem, last elem) = " << comp((*m.begin()).first, (*(--m.end())).first) << "\n"; 

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** value_comp check *****\n\n";

    //     set<int> m;
    //     set<int>::value_compare comp = m.value_comp();
    //     m[3] = "saint num";
    //     m[-1] = "minus one";
    //     m[-99] = "problems";
    //     m[666] = "number of beast";
    //     m[13] = "Baker's dozen";

    //     printSet(m, out);
    //     unsigned int start_time = clock();

    //     out << "compare(first elem, last elem) = " << comp(*m.begin(), *(--m.end())) << "\n"; 

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** find check *****\n\n";

    //     set<int> m;
    //     m[3] = "saint num";
    //     m[-1] = "minus one";
    //     m[-99] = "problems";
    //     m[666] = "number of beast";
    //     m[13] = "Baker's dozen";

    //     printSet(m, out);
    //     unsigned int start_time = clock();

    //     out << "Looking for existing element(3) = " << *m.find(3) << "\n";

    //     set<int>::iterator it = m.find(1234);
    //     out << "Looking for nonexisting element(1234) = " << (it == m.end() ? "end" : to_string(*it)) << "\n";

    //     out << "Looking for existing element and and changing it:\n";
    //     (*m.find(3)).second = "KEK LOL";
    //     printSet(m, out);

    //     out << "Looking for existing element and changing it:\n";
    //     set<int>::const_iterator iter = m.find(-1);
    //     out << *iter << "\n";
    //     printSet(m, out);

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** count check *****\n\n";

    //     set<int> m;
    //     m[3] = "saint num";
    //     m[-1] = "minus one";
    //     m[-99] = "problems";
    //     m[666] = "number of beast";
    //     m[13] = "Baker's dozen";

    //     printSet(m, out);
    //     unsigned int start_time = clock();

    //     out << "Looking for existing element(3) = " << m.count(3) << "\n";

    //     out << "Looking for nonexisting element(1234) = " << m.count(1234) << "\n";

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** lower_bound && upper_bound check *****\n\n";

    //     set<int> m;
    //     set<int>::iterator it;
    //     set<int>::const_iterator const_it;
    //     m[3] = "saint num";
    //     m[-1] = "minus one";
    //     m[-99] = "problems";
    //     m[666] = "number of beast";
    //     m[13] = "Baker's dozen";
    //     m[7] = "seven";
    //     m[18] = "+18";
    //     m[-1300] = "my bank account";

    //     const set<int> const_m(m);

    //     printSet(m, out);
    //     unsigned int start_time = clock();

    //     out << "Lower_bound of 3 = " << *(m.lower_bound(3)) << "\n";
    //     out << "Lower_bound of -1300 = " << *(m.lower_bound(-1300)) << "\n";
    //     out << "Lower_bound of -1200 = " << *(m.lower_bound(-1200)) << "\n";
    //     out << "Lower_bound of -1600 = " << *(m.lower_bound(-1600)) << "\n\n";
        
    //     out << "Upper_bound of 3 = " << *(m.upper_bound(3)) << "\n";
    //     out << "Upper_bound of -1300 = " << *(m.upper_bound(-1300)) << "\n";
    //     out << "Upper_bound of -1600 = " << *(m.upper_bound(-1600)) << "\n";
    //     it = m.upper_bound(1000);
    //     out << "Upper_bound of 1000 = " << (it == m.end() ? "end" : to_string(*it)) << "\n\n";

    //     out << "Const lower_bound of 3 = " << *(const_m.lower_bound(3)) << "\n";
    //     out << "Const_lower_bound of -1300 = " << *(const_m.lower_bound(-1300)) << "\n\n";
        
    //     out << "Const_upper_bound of 3 = " << *(const_m.upper_bound(3)) << "\n";
    //     const_it = const_m.upper_bound(1000);
    //     out << "Const_upper_bound of 1000 = " << (const_it == const_m.end() ? "end" : to_string(*it)) << "\n";

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** equal_range check *****\n\n";

    //     set<int> m;
    //     pair< set<int>::iterator, set<int>::iterator> ret;
    //     pair< set<int>::const_iterator, set<int>::const_iterator> const_ret;
    //     m[3] = "saint num";
    //     m[-1] = "minus one";
    //     m[666] = "number of beast";
    //     m[7] = "seven";
    //     m[18] = "+18";

    //     const set<int> const_m(m);

    //     printSet(m, out);
    //     unsigned int start_time = clock();

    //     out << "equal_range of 3:\n";
    //     ret = m.equal_range(3);
    //     out << "Lower_bound = " << *(ret.first) << "\n";
    //     out << "Upper_bound = " << *(ret.second) << "\n\n";

    //     out << "equal_range of 90:\n";
    //     ret = m.equal_range(90);
    //     out << "Lower_bound = " << *(ret.first) << "\n";
    //     out << "Upper_bound = " << *(ret.second) << "\n\n";

    //     out << "const equal_range of 3:\n";
    //     const_ret = const_m.equal_range(3);
    //     out << "Lower_bound = " << *(const_ret.first) << "\n";
    //     out << "Upper_bound = " << *(const_ret.second) << "\n";

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** equal_range check *****\n\n";

    //     set<int> m;
    //     pair<const int, char const *> * ptr;
    //     int size;

    //     unsigned int start_time = clock();

    //     ptr = m.get_allocator().allocate(5);
        
    //     size = sizeof(set<int>::value_type) * 5;

    //     out << "The allocated array has a size of " << size << " bytes.\n";

    //     m.get_allocator().deallocate(ptr, 5);

    //     out << "Time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** compare == check *****\n";
    //     int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
    //     pair<int, int> arrI1[8];
    //     for (int i = 0; i != 8; ++i)
    //         arrI1[i] = make_pair(arr1[i], arr1[i]);

    //     int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
    //     pair<int, int> arrI2[8];
    //     for (int i = 0; i != 8; ++i)
    //         arrI2[i] = make_pair(arr2[i], arr2[i]);

    //     set<int, int> m1(arrI1, &(arrI1[8]));
    //     set<int, int> m2(arrI1, &(arrI1[8]));
    //     set<int, int> m3(arrI2, &(arrI2[8]));
    //     unsigned int start_time = clock();
    //     out << "Comparing two equal set: " << ((m1 == m2) ? "true" : "false") << std::endl;
    //     out << "Comparing two not equal set: " << ((m1 == m3) ? "true" : "false") << std::endl;
    //     out << "Total time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** compare != check *****\n";
    //     int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
    //     pair<int, int> arrI1[8];
    //     for (int i = 0; i != 8; ++i)
    //         arrI1[i] = make_pair(arr1[i], arr1[i]);

    //     int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
    //     pair<int, int> arrI2[8];
    //     for (int i = 0; i != 8; ++i)
    //         arrI2[i] = make_pair(arr2[i], arr2[i]);

    //     set<int, int> m1(arrI1, &(arrI1[8]));
    //     set<int, int> m2(arrI1, &(arrI1[8]));
    //     set<int, int> m3(arrI2, &(arrI2[8]));
    //     unsigned int start_time = clock();
    //     out << "Comparing two equal set: " << ((m1 != m2) ? "true" : "false") << std::endl;
    //     out << "Comparing two not equal set: " << ((m1 != m3) ? "true" : "false") << std::endl;
    //     out << "Total time : " << clock() - start_time << std::endl;
    // }
    // {
    //     out << "\n ***** compare < check *****\n";
    //     int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
    //     pair<int, int> arrI1[8];
    //     for (int i = 0; i != 8; ++i)
    //         arrI1[i] = make_pair(arr1[i], arr1[i]);

    //     int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
    //     pair<int, int> arrI2[8];
    //     for (int i = 0; i != 8; ++i)
    //         arrI2[i] = make_pair(arr2[i], arr2[i]);

    //     set<int, int> m1(arrI1, &(arrI1[8]));
    //     set<int, int> m2(arrI1, &(arrI1[8]));
    //     set<int, int> m3(arrI2, &(arrI2[8]));
    //     set<int, int> m4(arrI2, &(arrI2[7]));
    //     unsigned int start_time = clock();
    //     out << "Comparing two equal sets: " << ((m1 < m2) ? "true" : "false") << std::endl;
    //     out << "Comparing two not equal sets (1 < 2): " << ((m1 < m3) ? "true" : "false") << std::endl;
    //     out << "Comparing two not equal sets (1 > 2): " << ((m4 < m3) ? "true" : "false") << std::endl;
    //     out << "Total time : " << clock() - start_time << std::endl;
    // }
}