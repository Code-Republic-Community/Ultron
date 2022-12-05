#include <iostream>
#include <algorithm>
#include "List.h"

int main() {
  //TESTING::constructors
  std::cout << "Testing constructors:" << std::endl;
  List<int> first(1);
  List<int> second = {2, 2, 1, 1, 4, 4, 4, 5, 5, 2, 6};
  List<int>& forth(second);
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
  std::cout << second.size() << std::endl;
  std::cout << second.front() << std::endl;
  std::cout << second.back() << std::endl;
  std::cout << third.empty() << std::endl;
  std::cout << std::endl;
  //Testing::actions
  std::cout << "Testing actions:" << std::endl;
  third += first;
  //TODO::actionMethods
}
