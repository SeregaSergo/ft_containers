#include "test.hpp"

void    myFunc(int & i) {
    i *= 2;
}

void    test_vector(std::ostream & out)
{
    {
        unsigned int start_time = clock();
        out << "\n ***** default constructor check *****\n\n";
        out << "vector <int>:\n";
        vector<int> vec;
        printVector(vec, out);
        out << "\nvector <Buffer> with new():\n";
        vector<Buffer> * ptr_vec_buf = new vector<Buffer>;
        printVector(*ptr_vec_buf, out);
        delete ptr_vec_buf;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
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
        vector<Buffer> vec_buf(10, Buffer("yo world!"));
        printVector(vec_buf, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
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
        vector<Buffer> vec1_buf(10, Buffer("yo world!"));
        printVector(vec1_buf, out);
        out << "coppied:\n";
        vector<Buffer> vec2_buf(vec1_buf);
        printVector(vec2_buf, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** range constructor check *****\n\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        out << "original array:\n[1, 4, 6, -1, 10, 666, 111, 51]\n";
        out << "coppied:\n";
        vector<int> vec(&(arr[2]), &(arr[5]));
        printVector(vec, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** assigning operator check *****\n\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        out << "original:\n";
        vector<int> vec1(&(arr[2]), &(arr[7]));
        printVector(vec1, out);
        out << "assigned by empty:\n";
        vector<int> vec2;
        vec2 = vec1;
        printVector(vec2, out);
        out << "assigned by full:\n";
        vector<int> vec3(10, 5);
        vec3 = vec1;
        printVector(vec3, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** const_iterator check *****\n";
        out << "vector<int>:\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        out << "original array:\n[1, 4, 6, -1, 10, 666, 111, 51]\n";
        vector<int> vec(arr, &(arr[8]));
        vector<int>::const_iterator beg = vec.begin();
        vector<int>::const_iterator end = vec.end();
        out << "Begin(*): " << *beg << std::endl;
        out << "End - 1(*): " << *(end - 1) << std::endl;
        for (; beg != end; ++beg)
            out << *beg  << ", ";
        out << '\n';

        out << "\n ***** iterator check *****\n";
        out << "vector<Buffer>:\n";
        vector<Buffer> vec1_buf(6, Buffer("yo world!"));
        int n = 0;
        for (vector<Buffer>::iterator i = vec1_buf.begin(); i != vec1_buf.end(); ++i) {
            if (n % 2 == 0)
                *i = Buffer("bye world");
            out << i->buff << ", ";
            ++n;
        }
        out << '\n';
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** const_reverse_iterator check *****\n";
        out << "vector<int>:\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        out << "original array:\n[1, 4, 6, -1, 10, 666, 111, 51]\n";
        vector<int> vec(arr, &(arr[8]));
        vector<int>::const_reverse_iterator beg = vec.rbegin();
        vector<int>::const_reverse_iterator end = vec.rend();
        out << "Begin(*): " << *beg << std::endl;
        out << "End - 1(*): " << *(end - 1) << std::endl;
        for (; beg != end; ++beg)
            out << *beg  << ", ";
        out << '\n';

        out << "\n ***** reverse_iterator check *****\n";
        out << "vector<Buffer>:\n";
        vector<Buffer> vec1_buf(6, Buffer("yo world!"));
        int n = 0;
        for (vector<Buffer>::reverse_iterator i = vec1_buf.rbegin(); i != vec1_buf.rend(); ++i) {
            if (n % 2 == 0)
                *i = Buffer("bye world");
            out << i->buff << ", ";
            ++n;
        }
        out << '\n';
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** max_size check *****\n";
        vector<int> vec;
        
        out << "Max size: " << vec.max_size() << std::endl;
        printVector(vec, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** resize check *****\n";
        out << "up side resize\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        vector<int> vec1(arr, &(arr[8]));
        printVector(vec1, out);
        vec1.resize(30);
        printVector(vec1, out);

        out << "increase resize more then max_size\n";
        vector<int> vec2(arr, &(arr[8]));
        printVector(vec2, out);
        try {
            vec2.resize(vec2.max_size() + 1);
        }
        catch (std::length_error & ex) {
            out << "Exeption caught: " << ex.what() << std::endl;
        }
        printVector(vec2, out);

        out << "reduce resize:\n";
        vector<int> vec3(arr, &(arr[8]));
        printVector(vec3, out);
        vec3.resize(4);
        printVector(vec3, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** empty check *****\n";
        vector<int> vec1(3, 99);
        vector<int> vec2;
        
        out << "Not empty vector :\n";
        out << "empty: " << ((vec1.empty()) ? "true" : "false") << std::endl;
        printVector(vec1, out);
        
        out << "Empty vector :\n";
        out << "empty: " << ((vec2.empty()) ? "true" : "false") << std::endl;
        printVector(vec2, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** reserve check *****\n";
        vector<int> vec;
        printVector(vec, out);
        out << "After reserving 115 units:\n";
        vec.reserve(115);
        printVector(vec, out);
        out << "After reserving 40 units:\n";
        vec.reserve(40);
        printVector(vec, out);
        out << "After reserving (max_size + 1) units:\n";
        try {
            vec.reserve(vec.max_size() + 1);
        }
        catch (std::length_error & ex) {
            out << "Exeption caught: " << ex.what() << std::endl;
        }
        printVector(vec, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** assign check *****\n";
        out << "\nwith iterators:\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        vector<int> vec1(3, 99);
        printVector(vec1, out);
        vec1.assign(&arr[0], &arr[8]);
        printVector(vec1, out);

        out << "\nwith value:\n";
        vector<int> vec2(3, 99);
        printVector(vec2, out);
        vec2.assign(3, 11);
        printVector(vec2, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** push_back check *****\n";
        vector<int> vec1;
        printVector(vec1, out);
        for (int i = 0; i != 3; ++i)
            vec1.push_back(7);
        out << "After pushing 3 elements:\n";
        printVector(vec1, out);
        for (int i = 0; i != 3; ++i)
            vec1.push_back(9);
        out << "After pushing 3 more elements:\n";
        printVector(vec1, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** pop_back check *****\n";
        vector<int> vec1(6, 7);
        printVector(vec1, out);
        for (int i = 0; i != 3; ++i)
            vec1.pop_back();
        out << "After popping 3 elements:\n";
        printVector(vec1, out);
        for (int i = 0; i != 2; ++i)
            vec1.pop_back();
        out << "After popping 2 more elements:\n";
        printVector(vec1, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** insert check *****\n";
        vector<int> vec1(5, 7);
        printVector(vec1, out);
        out << "After inserting single element:\n";
        vec1.insert(vec1.begin() + 3, 99);
        printVector(vec1, out);
        out << "After inserting some elements:\n";
        vec1.insert(vec1.begin() + 3, 3, 11);
        printVector(vec1, out);
        out << "After inserting some range of elements:\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        vec1.insert(vec1.begin() + 2, arr, arr + 4);
        printVector(vec1, out);
        out << "After inserting itself some range of elements:\n";
        vec1.insert(vec1.end(), vec1.begin(), vec1.end());
        printVector(vec1, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** erase check *****\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        vector<int> vec(arr, &(arr[8]));
        printVector(vec, out);
        out << "After erasing first element two times:\n";
        vec.erase(vec.erase(vec.begin()));
        printVector(vec, out);
        out << "After erasing two elements:\n";
        vec.erase(vec.begin() + 2, vec.begin() + 4);
        printVector(vec, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** swap check *****\n";
        vector<int> vec1(3, 333);
        vector<int> vec2(5, 555);
        printVector(vec1, out);
        printVector(vec2, out);
        out << "After swapping:\n";
        vec1.swap(vec2);
        printVector(vec1, out);
        printVector(vec2, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** clear check *****\n";
        vector<int> vec1(3, 333);
        printVector(vec1, out);
        out << "After clearing:\n";
        vec1.clear();
        printVector(vec1, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** operator [] check *****\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        vector<int> vec(arr, &(arr[8]));
        printVector(vec, out);
        out << "Getting third element (index 2): " << vec[2] << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** at() check *****\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        vector<int> const vec(arr, &(arr[8]));
        printVector(vec, out);
        out << "Getting third element (index 2): " << vec.at(2) << std::endl;
        out << "Getting tenth element (index 9): ";
        try {
            out << vec.at(9) << std::endl;
        }
        catch (std::out_of_range & ex) {
            out << ex.what() << std::endl;
        }
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** front() check *****\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        vector<int> vec(arr, &(arr[8]));
        printVector(vec, out);
        out << "Getting front element: " << vec.front() << std::endl;
        const int i = vec.front();
        out << "Getting const front element: " << i << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** back() check *****\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 111, 51};
        vector<int> vec(arr, &(arr[8]));
        printVector(vec, out);
        out << "Getting back element: " << vec.back() << std::endl;
        const int i = vec.back();
        out << "Getting const back element: " << i << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** compare == check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        out << "Comparing two equal vectors: " << ((vec1 == vec2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal vectors: " << ((vec1 == vec3) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** compare != check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        out << "Comparing two equal vectors: " << ((vec1 != vec2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal vectors: " << ((vec1 != vec3) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** compare < check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        vector<int> vec4(arr2, &(arr2[7]));
        out << "Comparing two equal vectors: " << ((vec1 < vec2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal vectors (1 < 2): " << ((vec1 < vec3) ? "true" : "false") << std::endl;
        out << "Comparing two not equal vectors (1 > 2): " << ((vec3 < vec4) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** compare <= check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        vector<int> vec4(arr2, &(arr2[7]));
        out << "Comparing two equal vectors: " << ((vec1 <= vec2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal vectors (1 < 2): " << ((vec1 <= vec3) ? "true" : "false") << std::endl;
        out << "Comparing two not equal vectors (1 > 2): " << ((vec3 <= vec4) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** compare > check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        vector<int> vec4(arr2, &(arr2[7]));
        out << "Comparing two equal vectors: " << ((vec1 > vec2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal vectors (1 < 2): " << ((vec1 > vec3) ? "true" : "false") << std::endl;
        out << "Comparing two not equal vectors (1 > 2): " << ((vec3 > vec4) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** compare >= check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        vector<int> vec4(arr2, &(arr2[7]));
        out << "Comparing two equal vectors: " << ((vec1 >= vec2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal vectors (1 < 2): " << ((vec1 >= vec3) ? "true" : "false") << std::endl;
        out << "Comparing two not equal vectors (1 > 2): " << ((vec3 >= vec4) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** get_allocator check *****\n";
        vector<int> myvector;
        int * p;
        unsigned int i;

        p = myvector.get_allocator().allocate(5);
        for (i=0; i<5; i++)
            myvector.get_allocator().construct(&p[i],i);

        out << "The allocated array contains:";
        for (i=0; i<5; i++)
            out << ' ' << p[i];
        out << '\n';

        for (i=0; i<5; i++)
            myvector.get_allocator().destroy(&p[i]);
        myvector.get_allocator().deallocate(p,5);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** using std::algorithms sort *****\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec(arr, &(arr[8]));
        printVector(vec, out);
        std::sort(vec.begin(), vec.end());
        out << "After sorting: " << std::endl;
        printVector(vec, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        unsigned int start_time = clock();
        out << "\n ***** using std::algorithms for_each *****\n";
        int arr[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec(arr, &(arr[8]));
        printVector(vec, out);
        std::for_each(vec.begin(), vec.end(), myFunc);
        out << "After for_each: " << std::endl;
        printVector(vec, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
}