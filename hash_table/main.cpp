#include "HashTable.h"
#include <iostream>

int main() {
  HashTable<int> a;
  a.insert(1);
  a.insert(3);
  a.insert(6);
  std::cout << a << std::endl;
  HashTable<std::string> b;
  b.insert("aasf");
  b.insert("asf");
  b.insert("huoh");
  std::cout << b;
  HashTable<std::string> c;
  c.insert("a");
  std::cout << (b>c) << std::endl;

}