#include "List.h"

template<typename T>
bool List<T>::empty(){
  if(head == nullptr){
    return true;
  }
  return false;
}