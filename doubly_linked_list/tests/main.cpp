#include <iostream>
#include <algorithm>

#include "../src/list.h"

int main() {
  //TESTING::constructors
  std::cout << "Testing constructors:" << std::endl;
  List<int> first(1);
  List<int> second = {2, 2, 1, 1, 4, 4, 4, 5, 5, 2, 6};
  List<int> &forth(second);
  List<int> third;
  std::cout << first;
  std::cout << second;
  std::cout << forth;
  std::cout << third;
  std::cout << std::endl;
  //TESTING::comparison
  std::cout << "Testing comparison operators:" << std::endl;
  std::cout << (forth == second) << std::endl;
  std::cout << (first != third) << std::endl;
  std::cout << (forth > first) << std::endl;
  std::cout << (third < first) << std::endl;
  std::cout << (forth >= second) << std::endl;
  std::cout << (second <= forth) << std::endl;
  std::cout << std::endl;
  //TESTING::returnMethods
  std::cout << "Testing value-return methods:" << std::endl;
  std::cout << (first + third);
  std::cout << (second + forth);
  std::cout << second.size() << std::endl;
  std::cout << second.front() << std::endl;
  std::cout << second.back() << std::endl;
  std::cout << third.empty() << std::endl;
  std::cout << std::endl;
  //Testing::actionMethods
  std::cout << "Testing actions:" << std::endl;
  third += first;
  third += forth;
  third.push_back(5);
  first.clear();
  std::cout << first;
  first.push_back(321);
  first.push_front(123);
  first.emplace(0, 1);
  first.resize(3);
  first.insert(1, 321);
  first.unique();
  first.merge(third);
  std::cout << first;
  std::cout << forth;
  first.splice(forth);
  std::cout << first;
  std::cout << forth;
  forth.splice(first, 5); // TODO:ASK
  std::cout << first;
  std::cout << forth;
  std::cout << std::endl;
  //Testing::iterators
  std::cout << "Testing iterators:" << std::endl;
  for (auto pos = first.begin(); pos != first.end(); pos++) {
    std::cout << pos->value << " ";
  }
  List<int>::iterator ptr = first.begin();
  std::cout << ptr->value;
  ptr++;
  std::cout << std::endl << std::endl;
  //Testing:endResults
  std::cout << "Final tests:" << std::endl;
  std::cout << first;
  std::cout << second;
  std::cout << third;
  std::cout << forth;
  std::cout << "All is good." << std::endl;
}
