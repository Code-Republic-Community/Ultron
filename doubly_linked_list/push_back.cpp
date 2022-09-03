#include "List.h"

template<typename T>
void List<T>::push_back(int value)
{
  if(head == nullptr){
    push_front(value);
    return;
  }
  node* n = new node(value);
  tail->next = n;
  n->prev = tail;
  tail = n;
}