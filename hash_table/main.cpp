#include "HashTable.hpp"
#include <iostream>

using namespace std;

int main() {
  HashTable<int> b;
  b.insert(1);
  b.insert(2);
  b.insert(3);

  HashTable<int> a;
  a.insert(4);
  a.insert(5);
  a.insert(6);
  a.insert(7);
  a.insert(7);
  a.insert(7);
  a.insert(7);
  std::cout << a << std::endl;
  std::cout << b << std::endl;
}