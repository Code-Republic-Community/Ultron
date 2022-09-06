#include "List.hpp"

int main(){
  List a(1);
  a.push_front(2);
  a.push_back(3);
  a.push_back(6);
  a.push_front(11);
  a.insert(16, 27);
  List b = {31, 32};
  b = a;
  /*std::cout << b << std::endl;
  std::cout << a << std::endl;*/
  //std::cout << a + b << std::endl;
 // std::cout << a << std::endl;
}