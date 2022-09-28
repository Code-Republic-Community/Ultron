#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <initializer_list>

template<typename T>
class List {
public:
  List();
  explicit List(T value);
  List(const List<T> &other_list);
  List(std::initializer_list<T> init_list);
  ~List();

public:
  template<typename U>
  friend std::ostream &operator<<(std::ostream &out, const List<U> &obj);
  List<T> &operator=(List<T> obj);
  bool operator!=(List<T> &obj);
  bool operator==(List<T> &obj);
  bool operator>(List<T> &obj);
  bool operator>=(List<T> &obj);
  bool operator<(List<T> &obj);
  bool operator<=(List<T> &obj);
  void operator+=(List<T> obj);
  List<T> operator+(List<T> obj);

public:
  int size() const; // return count of elements in list
  T front() const; // return first element value
  T back() const; // return last element value
  void push_front(T value); // add element at front
  void push_back(int value); // append element
  void emplace(int index1, int index2); // emplace element values by index
  void resize(int index); // save first index elements
  void insert(int index, T value); // insert element with value in index
  void clear(); // clear all list
  bool empty() const; // check if list is empty or not
  void unique(); // remove duplicate values
  void merge(const List<T> &obj); // merge two list
  void splice(List<T> &obj); // append all elements from second list and delete from it
  void splice(List<T> &obj, int index); // move second[index] element from second list
  void splice(List<T> &obj, int index1, int index2); // move element from index1 to index2 to main list
private:
  struct node {
    node *prev;
    node *next;
    T value;
    explicit node(T init_value);
    node(const node &init_node);
  };
  void remove_by_index(int index); //remove element by index
  node *_head;
  node *_tail;

  class iterator : public std::input_iterator_tag {
    friend class List;
  public:
    iterator() : new_node(nullptr) {}
    bool operator!=(const iterator &itr) const;
    T &operator*() const {
      return new_node->value;
    }
    node *operator->() const;
    iterator operator++(int);
    iterator operator--(int);

  private:
    explicit iterator(node *new_ptr) : new_node(new_ptr) {}
    node *new_node;
  };

public:
  iterator begin() const;
  iterator end() const;
  void remove_if(iterator start, iterator end, bool (*func)(T));
};

#endif