#include <iostream>
#include <initializer_list>
#include <vector>
#include "BST.h"
int main()
{
    BST<int> a = {50,30,35,23};
    BST<int> b = {36,4,5,6,2,1};
    BST<int> c = a + b;

    //a.levelorder();
    //a.inorder();
    //std::cout << a.get_height();
    //std::cout << std::endl;
    std::cout << c;
    //std::cout << a << std::endl;}
}
