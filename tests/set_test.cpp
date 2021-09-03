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
    {
        out << "\n ***** const_iterators check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        out << "CONST set<int>:\n";
        const set<int> s(arrI, &(arrI[4]));
        printSet(s, out);

        out << "Const_terator traverse:\n";
        set<int>::const_iterator it;
        unsigned int start_time = clock();
        for (it = s.begin(); it != s.end(); ++it)
            out << "[" << *it << "] ";
        
        out << "\nTime : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** reverse_iterators check *****\n\n";
        int arrI[] = {1, 2, 3, 4};
        out << "set<int>:\n";
        set<int> s(arrI, &(arrI[4]));
        printSet(s, out);

        out << "Reverse_iterator traverse:\n";
        set<int>::reverse_iterator it;
        unsigned int start_time = clock();
        for (it = s.rbegin(); it != s.rend(); ++it)
            out << "[" << *it << "] ";

        out << "\nTime : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** empty member-function check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        unsigned int start_time = clock();
        
        out << "empty set: ";
        set<int> set1;
        if (set1.empty())
            out << "true\n";
        else
            out << "false\n";
        
        out << "not empty set: ";
        set<int> set2(arrI, &(arrI[4]));
        if (set2.empty())
            out << "true\n";
        else
            out << "false\n";

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** max_size member-function check *****\n\n";
        int arrI[] = {3, -1, 666, 13};
        set<int> set(arrI, &(arrI[4]));
        unsigned int start_time = clock();
        out << "Max size: " << set.max_size();
        out << "\nTime : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Single insertion check *****\n\n";

        set<int> s;
        pair<set<int>::iterator, bool> ret;
        set<int>::iterator  it;

        unsigned int start_time = clock();

        ret = s.insert(-1);
        out << "Element is inserted: " << (ret.second ? "true" : "false") << "\n";
        out << "Element value: " << *(ret.first) << "\n";
        printSet(s, out);

        out << "Double insertion check:\n";
        ret = s.insert(-1);
        out << "Element is inserted: " << (ret.second ? "true" : "false") << "\n";
        out << "Element value: " << *ret.first << "\n";
        printSet(s, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Ordered insertion with hint check *****\n\n";

        set<int> s;
        set<int>::iterator  it = s.begin();
        int arrI[] = {-99, -1, 3, 13, 666};
        unsigned int start_time = clock();

        for (int i = 0; i != 5; ++i)
            it = s.insert(it, arrI[i]);

        printSet(s, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Ordered insertion with hint (LARGE) check *****\n\n";

        set<int> s;
        set<int>::iterator  it = s.begin();
        unsigned int start_time = clock();

        for (int i = 0; i != 10000; ++i)
            it = s.insert(it, i);

        printSet(s, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Unordered insertion with hint check *****\n\n";

        set<int> s;

        int arrI[] = {3, -1, -99, 666, 13};

        unsigned int start_time = clock();

        for (int i = 0; i != 5; ++i)
            s.insert(s.begin(), arrI[i]);
    
        printSet(s, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Unordered insertion with hint (LARGE) check *****\n\n";

        set<int> s;

        unsigned int start_time = clock();
        for (int i = 0; i != 10000; ++i)
            s.insert(s.begin(), i);
    
        printSet(s, out);
        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Range insertions check *****\n\n";

        set<int> s;
        vector<int> vec;

        for (int i = 0; i != 10000; ++i)
            vec.push_back(i);

        unsigned int start_time = clock();

        s.insert(vec.begin(), vec.end());
        printSet(s, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Deletion by key check *****\n\n";

        int arrI[] = {3, -1, -99, 666, 100, 13, -18, 18, -100, -999};

        out << "set<int>:\n";
        set<int> s(arrI, &(arrI[10]));
        printSet(s, out);
        unsigned int start_time = clock();

        out << "After deletion of -99, 666:\n";
        out << "Deleted: " << (s.erase(-99) ? "true" : "false") << "\n";
        out << "Deleted: " << (s.erase(666) ? "true" : "false") << "\n";
        printSet(s, out);

        out << "After deletion of nonexistent number: \n";
        out << "Deleted: " << (s.erase(1739827) ? "true" : "false") << "\n";
        printSet(s, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Deletion with iterator *****\n\n";

        int arrI[] = {3, -1, -99, 666, 100, 13, -18, 18, -100, -999};

        out << "set<int>:\n";
        set<int> s(arrI, &(arrI[10]));
        printSet(s, out);

        unsigned int start_time = clock();

        out << "After deletion of (++begin):\n";
        s.erase(++(s.begin()));
        printSet(s, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Range deletions with iterators *****\n\n";

        int arr[] = {3, -1, -99, 666, 100, 13, -18, 18, -100, -999};

        out << "set<int>:\n";
        set<int> s(arr, &(arr[10]));
        printSet(s, out);

        unsigned int start_time = clock();

        out << "After deletion from (++begin) to (--end):\n";
        s.erase(++s.begin(), --s.end());
        printSet(s, out);

        out << "After deletion from (begin) to (end):\n";
        s.erase(s.begin(), s.end());
        printSet(s, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** swap check *****\n\n";

        int arr1[] = {3, -1, 666, 13};
        set<int> set1(arr1, &(arr1[4]));

        int arr2[] = {7, 18, -1300};
        set<int> set2(arr2, &(arr2[3]));

        out << "First set<int>:\n";
        printSet(set1, out);
        
        out << "Second set<int>:\n";
        printSet(set2, out);

        unsigned int start_time = clock();

        out << "set1 after swap:\n";
        set1.swap(set2);
        printSet(set1, out);

        out << "set2 after swap:\n";
        printSet(set2, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** Clear check *****\n\n";

        out << "set<int>:\n";
        int arr[] = {3, -1, -99, 666, 13};
        set<int> s(arr, &(arr[5]));
        printSet(s, out);

        out << "set after clearing:\n";
        unsigned int start_time = clock();
        s.clear();
        printSet(s, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** key_comp check *****\n\n";

        out << "set<int>:\n";
        int arr[] = {3, -1, -99, 666, 13};
        set<int> s(arr, &(arr[5]));
        set<int>::key_compare comp = s.key_comp();
        printSet(s, out);
        unsigned int start_time = clock();

        out << "compare(first elem, last elem) = " << comp(*s.begin(), *(--s.end())) << "\n"; 

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** value_comp check *****\n\n";

        out << "set<int>:\n";
        int arr[] = {3, -1, -99, 666, 13};
        set<int> s(arr, &(arr[5]));
        set<int>::key_compare comp = s.value_comp();
        printSet(s, out);
        unsigned int start_time = clock();

        out << "compare(first elem, last elem) = " << comp(*s.begin(), *(--s.end())) << "\n"; 

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** find check *****\n\n";

        int arr[] = {3, -1, -99, 666, 13};
        set<int> s(arr, &(arr[5]));

        printSet(s, out);
        unsigned int start_time = clock();

        out << "Looking for existing element(3) = " << *s.find(3) << "\n";

        set<int>::iterator it = s.find(1234);
        out << "Looking for nonexisting element(1234) = " << (it == s.end() ? "end" : to_string(*it)) << "\n";

        out << "Looking for existing element and changing it:\n";
        set<int>::const_iterator iter = s.find(-1);
        out << "[" << *iter << "]\n";
        printSet(s, out);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** count check *****\n\n";

        int arr[] = {3, -1, -99, 666, 13};
        set<int> s(arr, &(arr[5]));

        printSet(s, out);
        unsigned int start_time = clock();

        out << "Looking for existing element(3) = " << s.count(3) << "\n";

        out << "Looking for nonexisting element(1234) = " << s.count(1234) << "\n";

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** lower_bound && upper_bound check *****\n\n";

        int arr[] = {3, -1, -99, 666, 13, 7, 18, -1300};

        out << "set<int>:\n";
        set<int> s(arr, &(arr[8]));
        const set<int> const_s(s);
        set<int>::iterator it;
        set<int>::const_iterator const_it;

        printSet(s, out);
        unsigned int start_time = clock();

        out << "Lower_bound of 3 = " << *(s.lower_bound(3)) << "\n";
        out << "Lower_bound of -1300 = " << *(s.lower_bound(-1300)) << "\n";
        out << "Lower_bound of -1200 = " << *(s.lower_bound(-1200)) << "\n";
        out << "Lower_bound of -1600 = " << *(s.lower_bound(-1600)) << "\n\n";
        
        out << "Upper_bound of 3 = " << *(s.upper_bound(3)) << "\n";
        out << "Upper_bound of -1300 = " << *(s.upper_bound(-1300)) << "\n";
        out << "Upper_bound of -1600 = " << *(s.upper_bound(-1600)) << "\n";
        it = s.upper_bound(1000);
        out << "Upper_bound of 1000 = " << (it == s.end() ? "end" : to_string(*it)) << "\n\n";

        out << "Const lower_bound of 3 = " << *(const_s.lower_bound(3)) << "\n";
        out << "Const_lower_bound of -1300 = " << *(const_s.lower_bound(-1300)) << "\n\n";
        
        out << "Const_upper_bound of 3 = " << *(const_s.upper_bound(3)) << "\n";
        const_it = const_s.upper_bound(1000);
        out << "Const_upper_bound of 1000 = " << (const_it == const_s.end() ? "end" : to_string(*it)) << "\n";

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** equal_range check *****\n\n";

        int arr[] = {3, -1, 666, 7, 18};
        out << "set<int>:\n";
        set<int> s(arr, &(arr[5]));
        const set<int> const_s(s);
        pair< set<int>::iterator, set<int>::iterator> ret;
        pair< set<int>::const_iterator, set<int>::const_iterator> const_ret;

        printSet(s, out);
        unsigned int start_time = clock();

        out << "equal_range of 3:\n";
        ret = s.equal_range(3);
        out << "Lower_bound = " << *(ret.first) << "\n";
        out << "Upper_bound = " << *(ret.second) << "\n\n";

        out << "equal_range of 90:\n";
        ret = s.equal_range(90);
        out << "Lower_bound = " << *(ret.first) << "\n";
        out << "Upper_bound = " << *(ret.second) << "\n\n";

        out << "const equal_range of 3:\n";
        const_ret = const_s.equal_range(3);
        out << "Lower_bound = " << *(const_ret.first) << "\n";
        out << "Upper_bound = " << *(const_ret.second) << "\n";

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** get_allocator check *****\n\n";

        set<int> s;
        int * ptr;
        int size;

        unsigned int start_time = clock();

        ptr = s.get_allocator().allocate(5);
        
        size = sizeof(set<int>::value_type) * 5;

        out << "The allocated array has a size of " << size << " bytes.\n";

        s.get_allocator().deallocate(ptr, 5);

        out << "Time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** compare == check *****\n";

        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};

        set<int> s1(arr1, &(arr1[8]));
        set<int> s2(arr1, &(arr1[8]));
        set<int> s3(arr2, &(arr2[8]));

        unsigned int start_time = clock();
        out << "Comparing two equal set: " << ((s1 == s2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal set: " << ((s1 == s3) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** compare != check *****\n";

        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};

        set<int> s1(arr1, &(arr1[8]));
        set<int> s2(arr1, &(arr1[8]));
        set<int> s3(arr2, &(arr2[8]));

        unsigned int start_time = clock();
        out << "Comparing two equal set: " << ((s1 != s2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal set: " << ((s1 != s3) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** compare < check *****\n";

        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};

        set<int> s1(arr1, &(arr1[8]));
        set<int> s2(arr1, &(arr1[8]));
        set<int> s3(arr2, &(arr2[8]));
        set<int> s4(arr2, &(arr2[7]));

        unsigned int start_time = clock();
        out << "Comparing two equal sets: " << ((s1 < s2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal sets (1 < 2): " << ((s1 < s3) ? "true" : "false") << std::endl;
        out << "Comparing two not equal sets (1 > 2): " << ((s4 < s3) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
}