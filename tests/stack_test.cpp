#include "test.hpp"
#include <list>

#ifndef STD_TEST

#include "../containers/stack.hpp"
#include "../containers/vector.hpp"

#endif

void    test_stack(std::ostream & out)
{
    {
        out << "\n ***** default constructor check *****\n\n";
        unsigned int start_time = clock();
        stack<int> s;
        printStack(s, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** constructor with list underlying contatiner check *****\n\n";
        unsigned int start_time = clock();
        stack<int, std::list<int> > s;
        printStack(s, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** constructor from container check *****\n";
        unsigned int start_time = clock();
        int arr[] = {1, 2, 13, -1};
        vector<int> vec(arr, &(arr[4]));
        stack<int, vector<int> > s(vec);
        printStack(s, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** copy constructor check *****\n\n";
        unsigned int start_time = clock();
        stack<int> s1;
        s1.push(1);
        s1.push(2);
        stack<int> s2(s1);
        out << "Stack 1:\n\n";
        printStack(s1, out);
        out << "Stack 2:\n\n";
        printStack(s2, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** operator= check *****\n\n";
        unsigned int start_time = clock();
        stack<int> s1;
        s1.push(1);
        s1.push(2);
        stack<int> s2 = s1;
        out << "Stack 1:\n\n";
        printStack(s1, out);
        out << "Stack 2:\n\n";
        printStack(s2, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** top check *****\n\n";
        unsigned int start_time = clock();
        stack<int> s;
        out << "Push (13) to stack.\n";
        s.push(13);
        out << "Top element: " << s.top() << "\n";
        out << "Change top element to 8:\n";
        s.top() = 8;
        out << "Stack:\n";
        printStack(s, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** const top check *****\n\n";
        unsigned int start_time = clock();
        stack<const int> s;
        out << "Push (13) to stack.\n";
        s.push(13);
        out << "Top element: " << s.top() << "\n";
        out << "Stack:\n";
        printStack(s, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** empty && size check *****\n\n";
        unsigned int start_time = clock();
        stack<int> s;
        out << "Empty: " << s.empty() << "\n";
        printStack(s, out);
        s.push(1);
        out << "Empty: " << s.empty() << "\n";
        printStack(s, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** push check *****\n\n";
        unsigned int start_time = clock();
        stack<int> s;
        s.push(1);
        s.push(2);
        printStack(s, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** pop check *****\n\n";
        unsigned int start_time = clock();
        stack<int> s1;
        s1.push(1);
        s1.push(2);
        stack<int> s2(s1);
        printStack(s1, out);
        out << "after poping one element:\n";
        s2.pop();
        printStack(s2, out);
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** compare == check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        stack<int, vector<int> > s1(vec1);
        stack<int, vector<int> > s2(vec2);
        stack<int, vector<int> > s3(vec3);
        unsigned int start_time = clock();
        out << "Comparing two equal stacks: " << ((s1 == s2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal stacks: " << ((s1 == s3) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** compare != check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        stack<int, vector<int> > s1(vec1);
        stack<int, vector<int> > s2(vec2);
        stack<int, vector<int> > s3(vec3);
        unsigned int start_time = clock();
        out << "Comparing two equal stacks: " << ((s1 != s2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal stacks: " << ((s1 != s3) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** compare < check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        stack<int, vector<int> > s1(vec1);
        stack<int, vector<int> > s2(vec2);
        stack<int, vector<int> > s3(vec3);
        unsigned int start_time = clock();
        out << "Comparing two equal stacks: " << ((s1 < s2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal stacks (1 < 2): " << ((s1 < s3) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** compare <= check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        stack<int, vector<int> > s1(vec1);
        stack<int, vector<int> > s2(vec2);
        stack<int, vector<int> > s3(vec3);
        unsigned int start_time = clock();
        out << "Comparing two equal stacks: " << ((s1 <= s2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal stacks (1 < 2): " << ((s1 <= s3) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** compare > check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        stack<int, vector<int> > s1(vec1);
        stack<int, vector<int> > s2(vec2);
        stack<int, vector<int> > s3(vec3);
        unsigned int start_time = clock();
        out << "Comparing two equal stacks: " << ((s1 > s2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal stacks (1 < 2): " << ((s1 > s3) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
    {
        out << "\n ***** compare >= check *****\n";
        int arr1[] = {1, 4, 6, -1, 10, 666, 111, 51};
        int arr2[] = {1, 4, 6, -1, 10, 666, 112, 51};
        vector<int> vec1(arr1, &(arr1[8]));
        vector<int> vec2(arr1, &(arr1[8]));
        vector<int> vec3(arr2, &(arr2[8]));
        stack<int, vector<int> > s1(vec1);
        stack<int, vector<int> > s2(vec2);
        stack<int, vector<int> > s3(vec3);
        unsigned int start_time = clock();
        out << "Comparing two equal stacks: " << ((s1 >= s2) ? "true" : "false") << std::endl;
        out << "Comparing two not equal stacks (1 < 2): " << ((s1 >= s3) ? "true" : "false") << std::endl;
        out << "Total time : " << clock() - start_time << std::endl;
    }
}