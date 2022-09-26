#include "List.h"

bool is_odd(int value) {
  if(value%2 == 1){
    return true;
  }
  return false;
}

int main(){
  List<int> a(1);
  a.push_front(2);
  a.push_back(3);
  a.push_back(6);
  a.push_front(11);
  a.insert(4, 74);
  List<int> b = {2, 2, 1, 1, 4, 4, 4, 5, 5, 2};
  std::cout << b << std::endl;
  std::cout << a << std::endl;
}
