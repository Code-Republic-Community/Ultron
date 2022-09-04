#include "List.h"

template<typename T>
void List<T>::splice(List<T> &second){
  this->merge(second);
  second.head = nullptr;
  second.tail = nullptr;
}

template<typename T>
void List<T>::splice(List<T> &second, int index) {
  if(index > second.size() || index < 0){
    return;
  }
  node* tmp = second.head;
  int counter = 0;
  while(counter != index){
    tmp = tmp->next;
    counter++;
  }

  this->push_back(tmp->value);
  second.remove(index);
}

template<typename T>
void List<T>::splice(List<T> &second, int index1, int index2) {
  if(index2 < index1){
    std::swap(index1, index2);
  }
  if(index1 > second.size() || index1 < 0 || index2 > second.size() || index2 < 0){
    return;
  } else if(second.size() == index2 - index1 + 1){
    this->splice(second);
    return;
  }
  node* tmp = second.head;
  int counter = 0;
  while(counter != index1){
    tmp = tmp->next;
    counter++;
  }
  while(counter != index2){
    this->push_back(tmp->value);
    tmp = tmp->next;
    second.remove(index1);
    counter++;
  }
  this->push_back(tmp->value);
  second.remove(index1);
}