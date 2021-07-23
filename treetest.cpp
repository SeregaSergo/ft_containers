#include "Red_black_tree.hpp"

int main()
{
    ft::Red_black_tree<int> tree;

    tree.insert(0);
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);
    tree.insert(80);
    tree.insert(90);
    tree.insert(100);
    tree.insert(110);
    tree.insert(120);
    tree.insert(130);
    tree.insert(140);
    tree.insert(150);
    tree.insert(160);
    tree.insert(170);
    tree.insert(180);
    tree.insert(190);
    tree.insert(200);
    tree.insert(210);
    tree.insert(220);
    tree.insert(230);
    tree.print(std::cout);
    std::cout << "Erase 70:" << std::endl;
    tree.erase(70);
    tree.print(std::cout);
    ft::Red_black_tree<int>::node_pointer ptr;
    ptr = tree.find(-110);
    if (ptr)
        std::cout << ptr->val << std::endl;
    else
        std::cout << "There is no such element" << std::endl;
    return (0);
}