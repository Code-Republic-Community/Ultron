#include "List.h"

template<typename T>
void List<T>::clear() {
  delete head;
  delete tail;
  head = nullptr;
  tail = nullptr;
}