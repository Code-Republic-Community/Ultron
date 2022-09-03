#include <iostream>
#include "List.h"
#include "size.cpp"
#include "push_front.cpp"
#include "push_back.cpp"
#include "insert.cpp"
#include "clear.cpp"
#include "empty.cpp"
#include "resize.cpp"
#include "front.cpp"
#include "back.cpp"
#include "emplace.cpp"
#include "remove.cpp"

template<typename T>
std::ostream& operator<<(std::ostream& out, List<T> const &a){
  typename List<T>::node* temp=a.head;
  while(temp!=nullptr){
    out<<temp->value<<" --> ";
    temp=temp->next;
  }
  std::cout<<"NULL"<<std::endl;
  return out;
}

template<typename T>
bool List<T>::operator==(List<T> second){
  if(this->size() != second.size()){
    return false;
  }
  List<T>::node *tmp1 = this->head;
  List<T>::node *tmp2 = second.head;
  while (tmp1->next != nullptr){
    if(tmp1->value != tmp2->value){
      return false;
    }
    tmp1 = tmp1->next;
    tmp2 = tmp2->next;
  }
  return true;

}

template<typename T>
bool List<T>::operator!=(List<T> second){
  return !(this == second);
}



