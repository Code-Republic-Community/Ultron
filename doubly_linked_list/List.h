#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H
#include <iostream>
#include <initializer_list>

template<typename T>
class List{
public:
  List(const List &otherList) {
    if (otherList.head_ == nullptr){
      head_ = nullptr;
      tail_ = nullptr;
    }
    else{
      head_ = new node(otherList.head_->value);
      node* otherNext = otherList.head_->next;
      node* temp = head_;
      while(otherNext != nullptr){
        temp->next = new node(otherNext->value);
        (temp->next)->prev = temp;
        temp = temp->next;
        otherNext = otherNext->next;
      }
      tail_ = temp;
    }
  }
  List(std::initializer_list<T> init_list) {
    head_ = new node(*init_list.begin());
    node* temp = head_;
    int counter = 0;
    for(auto element: init_list) {
      if (counter != 0) {
        temp->next = new node(element);
        temp->next->prev = temp;
        temp = temp->next;
        tail_ = temp;
      }
      counter++;
    }
  }
  ~List() = default;

public:
  friend std::ostream& operator<<(std::ostream& out, List<T> const &second){
    typename List<T>::node* temp=second.head_;
    while(temp!=nullptr){
      out<<temp->value<<" --> ";
      temp=temp->next;
    }
    std::cout<<"NULL"<<std::endl;
    return out;
  }
  bool operator!=(List<T> second);
  bool operator==(List<T> second);
  bool operator>(List<T> second);
  bool operator>=(List<T> second);
  bool operator<(List<T> second);
  bool operator<=(List<T> second);
  void operator+=(T second);
  List<T> operator+(T value);
  /////////constructors/////////////////////
  explicit List(T value) {
    head_ = new node(value);
    tail_ = head_;
  }

public:
  int size() const; // return count of elements in list
  T front() const; // return first element value
  T back() const; // return last element value
  void push_front(T value); // add element at front
  void push_back(int value); // append element
  void emplace(int index1, int index2); // emplace element values by index
  void remove(int index); //remove element by index
  void resize(int index); // save first index elements
  void insert(int index, int value); // insert element with value in index
  void clear(); // clear all list
  bool empty(); // check if list is empty or not
  void unique(); // remove dublicate values
  void merge(List<T> second); // merge two list
  void splice(List<T> &second); // append all elements from second list and delete from it
  void splice(List<T> &second, int index); // move second[index] element from second list
  void splice(List<T> &second, int index1, int index2); // move ellement from index1 to index2 to main list

private:
  struct node{
    node* prev;
    node* next;
    T value;
    explicit node(T init_value) {
      value = init_value;
      prev = nullptr;
      next = nullptr;
    }
    node(const node &init_node){
      value = init_node.value;
      prev = init_node.prev;
      next = init_node.prev;
    }
  };
  node* head_;
  node* tail_;
};


#endif //UNTITLED_LIST_H