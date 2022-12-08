#include <iostream>
#include <algorithm>
#include <string>

#include "HashTable.h"

int main() {
  //Testing::constructors
  HashTable<std::string, int> a;
  HashTable<int, std::string> b(20);
  b.insert(2, "fawf");
  b.insert(2, "fasf");
  b.insert(2, "qrwqrqr");
  b.insert(123, "fasfa");
  b.remove(2, "fawf");
  b.remove(2, "qrwqrqr"); // TODO::CannotDeleteLastElementOfIndex
  b.remove(2, "fasf");
  //b.insert(2, "fasfg");
  b.printTable();
}
