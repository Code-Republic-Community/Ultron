#ifndef LIST_H
#define LIST_H
#pragma once

template<typename T>
class List {
public:
  List();
  explicit List(T value);
  List(const List<T> &other_list);
  List(List<T> &&other_list) noexcept;
  List(const std::initializer_list<T> &init_list);
  ~List();

public:
  template<typename U>
  friend std::ostream &operator<<(std::ostream &out, const List<U> &obj);
  List<T> &operator=(const List<T> &other_list);
  List<T> &operator=(List<T> &&other_list);
  bool operator!=(const List<T> &obj) const;
  bool operator==(const List<T> &obj) const;
  bool operator>(const List<T> &obj) const;
  bool operator>=(const List<T> &obj) const;
  bool operator<(const List<T> &obj) const;
  bool operator<=(const List<T> &obj) const;
  void operator+=(const List<T> &obj);
  List<T> operator+(const List<T> &obj) const;

public:
  [[nodiscard]] int size() const; // return count of elements in list
  T front() const; // return first element value
  T back() const; // return last element value
  void push_front(T value); // add element at front
  void push_back(T value); // append element
  void emplace(int index1, int index2); // replace element values by index
  void resize(int index); // cut or add zeros to change the size of the list
  void insert(int index, T value); // insert element with value in index
  void clear(); // clear all list
  [[nodiscard]] bool empty() const; // check if list is empty or not
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
  }; // declaration of node class ends here

  void remove_by_index(int index); //remove element by index
  node *_head;
  node *_tail;

public:
  class iterator {
    typedef std::bidirectional_iterator_tag iterator_category;
    friend class List;
  public:
    iterator() : new_node(nullptr) {}
    bool operator!=(const iterator &itr) const;
    T &operator*() const {
      return new_node->value;
    }
    node *operator->() const;
    const iterator operator++(int);
    const iterator operator--(int);
  private:
    explicit iterator(node *new_ptr) : new_node(new_ptr) {}
    node *new_node;
  };

public:
  iterator begin() const;
  iterator end() const;

  void remove_if(iterator start, iterator end, bool (*func)(T));
};

#include "list.hpp"

#endif // LIST_H
