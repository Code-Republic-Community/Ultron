#include <iostream>
#include <vector>
#include <list>
#include "BS.h"
int main()
{
    int arr[] = {3,4,5,6,7,8,9,11,22,33};
    std::cout << BinarySearch(arr,10,4);
    std::vector<int> t = {6,7,8,33,30,31,55,88,99};
    auto ti = Binary_Search(t.begin(),t.end(),81);
      std::cout << *ti;
 std::list<int> a = {5,6,7,8,10,22};
 auto it = Binary_Search(a.begin(),a.end(),8);
 std::cout << *it;
}

