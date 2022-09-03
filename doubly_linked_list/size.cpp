#include "List.h"

template<typename T>
int List<T>::size() const{
  if(head == nullptr){
    return 0;
  }
  List<T>::node* temp = head;
  int counter = 1;
  while(temp->next != nullptr){
    temp = temp->next;
    counter++;
  }
  return counter;
}