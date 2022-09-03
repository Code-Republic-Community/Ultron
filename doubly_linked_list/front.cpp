#include "List.h"

template<typename T>
T List<T>::front() const{
  return head->value;
}