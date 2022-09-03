#include "List.h"

template<typename T>
void List<T>::unique(){
  node* tmp = head;
  node* tmp1 = tmp->next;
  while(tmp->next != nullptr){
    while(tmp1->next != nullptr){
      if(tmp->value == tmp1->value){
        tmp1->prev->next = tmp1->next;
        tmp1->next->prev = tmp1->prev;
      }
      tmp1 = tmp1->next;
    }
    if(tmp->value == tail->value){
      tail = tail->prev;
      tail->next = nullptr;
    }
    if(tmp->next != nullptr) {
      tmp = tmp->next;
      tmp1 = tmp->next;
    }
  }
}