#include "List.cpp"


int main(){
  List a(1);
  a.push_front(2);
  a.push_back(3);
  a.push_back(6);
  a.push_front(11);
  a.insert(16, 27);
  a.emplace(0, 1);
  List b = {3, 3, 3, 3, 3, 3, 2, 3};
  b.unique();
  std::cout << b << std::endl;
}