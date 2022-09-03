#include "List.h"

template<typename T>
T List<T>::back() const{
  return tail->value;
}