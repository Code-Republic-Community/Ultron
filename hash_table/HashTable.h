#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>

template<typename T>
class HashTable {
public:
  HashTable();
  HashTable(const HashTable<T> &other_list); // TODO
  HashTable(std::initializer_list<T> init_list); // TODO
  ~HashTable(); // TODO

  template<typename U>
  friend std::ostream &operator<<(std::ostream &out, const HashTable<U> &obj);
  HashTable<T> &operator=(HashTable<T> obj);
  bool operator!=(HashTable<T> &obj);
  bool operator==(HashTable<T> &obj);
  bool operator>(HashTable<T> &obj);
  bool operator>=(HashTable<T> &obj);
  bool operator<(HashTable<T> &obj);
  bool operator<=(HashTable<T> &obj);
  
  int HashFunctionHorner(const std::string &s, int table_size, int key);
  void resize();
  void insert(std::string &s);
  void insert(T value);
  bool empty() const;
  int size();
  bool contain(T value) const;
private:
  struct node {
    T value;
    node* next;
    node();
    explicit node(T init_value);
  };
  int _count = 0;
  std::vector<node*> array;
};

#endif
