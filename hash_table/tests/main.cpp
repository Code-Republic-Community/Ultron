#include <iostream>
#include <algorithm>
#include <string>

#include "../src/hashtable.h"

int main() {
  //Testing::constructors
  HashTable<std::string, int> a;
  std::cout << a;
  a.insert("asd", 1);
  HashTable<std::string, int> l;
  l.insert("dsa", 2);
  HashTable<int, std::string> b(10);
  HashTable<int, std::string> c(b);
  HashTable<std::string, std::string> d = {std::make_pair("fast", "f"), std::make_pair("faff", "fluff")};
  //Testing::methods
  a.insert("2414", 5);
  a.insert("fast", 2);
  b.insert(2, "faff");
  b.insert(3, "placate");
  b.insert(1, "Asaf");
  b.remove(2, "faff");
  c.insert(3, "eureka");
  std::cout << "A:" << std::endl;
  a.print_table();
  std::cout << "B:" << std::endl;
  b.print_table();
  std::cout << "C: " << std::endl;
  c.print_table();
  c.insert(4, "123412");
  std::cout << "Table C has " << c.get_count() << " elements" << std::endl;
  std::cout << "Table A is empty: " << a.empty() << std::endl;
  std::cout << "Table B is empty: " << b.empty() << std::endl;
  c.insert(6, "1241fa");
  c.insert(1, "Asaf");
  c.insert(6, "fatwas");
  c.insert(4, "afar12r");
  c.insert(12, "fas124");
  c.insert(12, "faff");
  c.insert(3, "faf12Assess");
  std::cout << "Table B:" << std::endl;
  b.print_table();
  std::cout << "Table C:" << std::endl;
  c.print_table();
  std::cout << "b == C: " << (b == c) << std::endl;
  b = c;
  std::cout << "b == C: " << (b == c) << std::endl;
  std::cout << "Table B:" << std::endl;
  std::cout << b << std::endl;
  b.find(12);
  b.insert(2, "124");
  b.swap(c);
  std::cout << b;
  std::cout << c;
  a.merge(l);
  a.erase();
  c[4] = "asd";
  std::cout << c[4] << std::endl;
  std:: cout << "Table A: " << a;
  //Testing:operators
  std::cout << "b == C: " << (b == c) << std::endl;
  b = c;
  std::cout << "b == C: " << (b == c) << std::endl;
  std::cout << "b > c: " << (b > c) << std::endl;
  std::cout << "b < c: " << (b < c) << std::endl;
  std::cout << "b <= c or b >= c: " << (b >= c) << " " << (b <= c) << std::endl;
}
