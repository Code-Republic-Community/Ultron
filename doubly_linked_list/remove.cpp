#include "List.h"

//TODO (CHECK INDEX AND LIST SIZE)
template<typename T>
void List<T>::remove(int index){
  if(index > this->size() || index < 0){
    return;
  }
  node* tmp = head;
  int counter = 0;
  while(counter != index){
    tmp = tmp->next;
    counter++;
  }
  if(tmp->prev != nullptr && tmp->next != nullptr) {
    (tmp->prev)->next = tmp->next;
    (tmp->next)->prev = tmp->prev;
    delete tmp;
    tmp = nullptr;
  }
  else if(tmp->next != nullptr && tmp->prev == nullptr){
    head = head->next;
    head->prev = nullptr;
    delete tmp;
    tmp = nullptr;
  }
  else {
    tail = tmp->prev;
    tail->next = nullptr;
    delete tmp;
    tmp = nullptr;
  }
}