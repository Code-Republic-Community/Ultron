#include "HashTable.hpp"
#include <iostream>

using namespace std;

int main() {
  HashTable<int> b({1, 23, 421, 2, 4,  5, 5, 5, 5, 37, 5});
  HashTable<int> a({1, 2, 4, 5, 6, 7, 8, 9, 20});
  a.merge(b);
  std::cout << a << std::endl;
}