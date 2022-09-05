#include <iostream>
#include "List.h"

template<typename T>
std::ostream& operator<<(std::ostream& out, List<T> const &second){
  typename List<T>::node* temp=second.head_; // remind asking
  while(temp != nullptr){
    out<<temp->value<<" --> ";
    temp=temp->next;
  }
  std::cout<<"NULL"<<std::endl;
  return out;
}

template<typename T>
void List<T>::operator+=(T value) {
  tail_->next = new node(value);
  tail_->next->prev = tail_;
  tail_ = tail_->next;
}

template<typename T>
List<T> List<T>::operator+(T value) {
  List<T> nlist = *this;
  nlist += value;
  return nlist;
}

template<typename T>
bool List<T>::operator==(List<T> second){
  if(this->size() != second.size()){
    return false;
  }
  List<T>::node *tmp1 = this->head_;
  List<T>::node *tmp2 = second.head_;
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
  return !(*this == second);
}

template<typename T>
bool List<T>::operator>(List<T> second) {
  if (this->size() > second.size()) {
    return true;
  } else if (this->size() < second.size()) {
    return false;
  } else {
    node* tmp = head_;
    node* tmp1 = second.head_;
    while(tmp->next != nullptr){
      if(tmp->value > tmp1->value){
        return true;
      }
      else if(tmp->value < tmp1->value){
        return false;
      }
      tmp = tmp->next;
      tmp1 = tmp1->next;
    }
    return false;
  }
}

template<typename T>
bool List<T>::operator>=(List<T> second) {
  if(*this == second || *this > second){
    return true;
  }
  return false;
}

template<typename T>
bool List<T>::operator<(List<T> second) {
  if(!(*this >= second)){
    return true;
  }
  return false;
}

template<typename T>
bool List<T>::operator<=(List<T> second) {
  if(*this < second || *this == second){
    return true;
  }
  return false;
}

template<typename T>
void List<T>::emplace(int index1, int index2){
  node* tmp = head_;
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

template<typename T>
void List<T>::remove(int index){
  if(index > this->size() || index < 0){
    return;
  }
  node* tmp = head_;
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
    head_ = head_->next;
    head_->prev = nullptr;
    delete tmp;
    tmp = nullptr;
  }
  else {
    tail_ = tmp->prev;
    tail_->next = nullptr;
    delete tmp;
    tmp = nullptr;
  }
}

template<typename T>
void List<T>::unique(){
  node* tmp = head_;
  node* tmp1 = tmp->next;
  while(tmp->next != nullptr){
    while(tmp1->next != nullptr){
      if(tmp->value == tmp1->value){
        tmp1->prev->next = tmp1->next;
        tmp1->next->prev = tmp1->prev;
      }
      tmp1 = tmp1->next;
    }
    if(tmp->value == tail_->value){
      tail_ = tail_->prev;
      tail_->next = nullptr;
    }
    if(tmp->next != nullptr) {
      tmp = tmp->next;
      tmp1 = tmp->next;
    }
  }
}

template<typename T>
T List<T>::front() const{
  return head_->value;
}

template<typename T>
void List<T>::push_back(int value)
{
  if(head_ == nullptr){
    push_front(value);
    return;
  }
  node* new_node = new node(value);
  tail_->next = new_node;
  new_node->prev = tail_;
  tail_ = new_node;
}

template<typename T>
void List<T>::push_front(T value){
  if (head_ == nullptr) {
    head_ = new node(value);
    tail_ = head_;
    return;
  }
  node* new_node = new node(value);
  new_node->next = head_;
  head_->prev = new_node;
  head_ = new_node;
}

template<typename T>
void List<T>::resize(int index){
  node* tmp = head_;
  int counter = 0;
  while(counter != index){
    tmp = tmp->next;
    counter++;
  }
  tmp->next = nullptr;
  begin(tmp);
  head_ = tmp;
}

template<typename T>
void List<T>::splice(List<T> &second){
  this->merge(second);
  second.head_ = nullptr;
  second.tail_ = nullptr;
}

template<typename T>
void List<T>::splice(List<T> &second, int index) {
  if(index > second.size() || index < 0){
    return;
  }
  node* tmp = second.head_;
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
  if (index2 < index1) {
    std::swap(index1, index2);
  }
  if (index1 > second.size() || index1 < 0 || index2 > second.size() || index2 < 0) {
    return;
  } else if (second.size() == index2 - index1 + 1) {
    this->splice(second);
    return;
  }
  node *tmp = second.head_;
  int counter = 0;
  while (counter != index1) {
    tmp = tmp->next;
    counter++;
  }
  while (counter != index2) {
    this->push_back(tmp->value);
    tmp = tmp->next;
    second.remove(index1);
    counter++;
  }
  this->push_back(tmp->value);
  second.remove(index1);
}

template<typename T>
int List<T>::size() const{
  if(head_ == nullptr){
    return 0;
  }
  List<T>::node* temp = head_;
  int counter = 1;
  while(temp->next != nullptr){
    temp = temp->next;
    counter++;
  }
  return counter;
}

template<typename T>
void List<T>::merge(List<T> second) {
  node* tmp = second.head_;
  while(tmp->next != nullptr){
    this->push_back(tmp->value);
    tmp = tmp->next;
  }
  this->push_back(tmp->value);
}

template<typename T>
void List<T>::insert(int index, int value){
  if(this->size() <= index){
    push_back(value);
  }
  else if(index == 0){
    push_front(value);
  }
  else{
    node* temp=head_;
    int counter = 0;
    while(counter < index){
      counter++;
      temp=temp->next;
    }
    node* new_node = new node(value);
    new_node->next = temp;
    new_node->prev = temp->prev;
    (temp->prev)->next = new_node;
    temp->prev = new_node;
  }
}

template<typename T>
bool List<T>::empty(){
  if(head_ == nullptr){
    return true;
  }
  return false;
}

template<typename T>
void List<T>::clear() {
  delete head_;
  delete tail_;
  head_ = nullptr;
  tail_ = nullptr;
}

template<typename T>
T List<T>::back() const{
  return tail_->value;
}