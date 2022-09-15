#include "HashTable.hpp"
#include <iostream>

using namespace std;

int main() {
  HashTable<int> a;
  a.insert(123);
  a.insert(123);
  a.insert(124124);
  a.insert(12515125);
  cout << a.contains(1234);
}