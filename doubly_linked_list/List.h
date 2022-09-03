#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H
#include "iostream"
#include <initializer_list>

template<typename T>
class List{
public:
  /////////operators overloading ///////////////////
  friend std::ostream& operator<<(std::ostream& out, List<T> const &a){
    typename List<T>::node* temp=a.head;
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
  /////////constructors/////////////////////
  explicit List(T value) {
    head = new node(value);
    tail = head;
  }
  List(const List &otherList) {
    if (otherList.head == nullptr){
      head = nullptr;
      tail = nullptr;
    }
    else{
      head = new node(otherList.head->value);
      node* otherNext = otherList.head->next;
      node* temp = head;
      while(otherNext != nullptr){
        temp->next = new node(otherNext->value);
        (temp->next)->prev = temp;
        temp = temp->next;
        otherNext = otherNext->next;
      }
      tail = temp;
    }
  }

  List(std::initializer_list<T> e) {
    head = new node(*e.begin());
    node* temp = head;
    int counter = 0;
    for(auto element: e) {
      if (counter != 0) {
        temp->next = new node(element);
        temp->next->prev = temp;
        temp = temp->next;
        tail = temp;
      }
      counter++;
    }
  }


  ~List() = default;

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
private:
  struct node{
    node* prev;
    node* next;
    T value;
    explicit node(T i) {
      value = i;
      prev = nullptr;
      next = nullptr;
    }
    node(const node &i){
      value = i.value;
      prev = i.prev;
      next = i.prev;
    }
  };
  node* head;
  node* tail;
};


#endif //UNTITLED_LIST_H
