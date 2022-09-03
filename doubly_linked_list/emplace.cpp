#include "List.h"

template<typename T>
void List<T>::emplace(int index1, int index2){
  node* tmp = head;
  node* value1 = 0;
  node* value2 = 0;
  int counter = 0;
  while((tmp->next) != nullptr){
    if(counter == index1){
      value1 = tmp;
    }
    else if(counter == index2){
      value2 = tmp;
    }
    else if(counter > index2 && counter > index1){
      break;
    }
    counter++;
    tmp = tmp->next;
  }
  int temp = value1->value;
  value1->value = value2->value;
  value2->value = temp;
}