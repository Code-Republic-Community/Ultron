#include "List.h"

template<typename T>
void List<T>::merge(List<T> second) {
  node* tmp = second.head;
  while(tmp->next != nullptr){
    this->push_back(tmp->value);
    tmp = tmp->next;
  }
  this->push_back(tmp->value);
}