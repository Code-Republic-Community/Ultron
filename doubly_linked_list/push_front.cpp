#include "List.h"

template<typename T>
void List<T>::push_front(T value){
  if (head == nullptr) {
    head = new node(value);
    tail = head;
    return;
  }
  node* n = new node(value);
  n->next = head;
  head->prev = n;
  head=n;
}