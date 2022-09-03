#include "List.h"

//TODO (change second while to pointers)
template<typename T>
void List<T>::emplace(int index1, int index2){
  node* tmp = head;
  int value1 = 0;
  int value2 = 0;
  int counter = 0;
  while((tmp->next) != nullptr){
    if(counter == index1){
      value1 = tmp->value;
    }
    else if(counter == index2){
      value2 = tmp->value;
    }
    else if(counter > index2 && counter > index1){
      break;
    }
    counter++;
    tmp = tmp->next;
  }
  tmp = head;
  counter = 0;
  while((tmp->next) != nullptr){
    if(counter == index1){
      tmp->value = value2;
    }
    else if(counter == index2){
      tmp->value = value1;
    }
    else if(counter > index2 && counter > index1){
      break;
    }
    counter++;
    tmp = tmp->next;
  }
}