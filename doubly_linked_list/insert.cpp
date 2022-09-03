#include "List.h"

template<typename T>
void List<T>::insert(int index, int value){
  if(this->size() <= index){
    push_back(value);
  }
  else if(index == 0){
    push_front(value);
  }
  else{
    node* temp=head;
    int counter = 0;
    while(counter < index){
      counter++;
      temp=temp->next;
    }
    node* n = new node(value);
    n->next = temp;
    n->prev = temp->prev;
    (temp->prev)->next = n;
    temp->prev = n;
  }
}