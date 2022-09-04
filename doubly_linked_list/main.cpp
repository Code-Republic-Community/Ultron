#include "List.cpp"


int main(){
  List a(1);
  a.push_front(2);
  a.push_back(3);
  a.push_back(6);
  a.push_front(11);
  a.insert(16, 27);
  a.emplace(0, 1);
  List b = {31, 32, 33, 34, 35, 36};
  std::cout << b << std::endl;
  std::cout << a << std::endl;
  a.splice(b, 1, 5);
  std::cout << b << std::endl;
  std::cout << a << std::endl;
}