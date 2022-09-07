#include "List.hpp"

bool is_odd(int value) {
  if(value%2 == 1){
    return true;
  }
  return false;
}

int main(){
  List a(1);
  a.push_front(2);
  a.push_back(3);
  a.push_back(6);
  a.push_front(11);
  a.insert(16, 27);
  List b = {2, 31, 32, 33, 122};
  std::cout << a << std::endl;
  b.remove_if(b.begin(), b.end(), &is_odd);
  std::cout << b << std::endl;
}