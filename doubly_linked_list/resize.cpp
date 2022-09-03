#include "List.h"

template<typename T>
void List<T>::resize(int index){
  node* tmp = head;
  int counter = 0;
  while(counter != index){
    tmp = tmp->next;
    counter++;
  }
  tmp->next = nullptr;
  begin(tmp);
  head = tmp;
}